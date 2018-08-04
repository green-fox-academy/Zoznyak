#include "main.h"
#include "stm32746g_discovery_lcd.h"
#include <string.h>

UART_HandleTypeDef uart_handle;
GPIO_InitTypeDef gpio_adc_init;
ADC_HandleTypeDef adc_handle;
ADC_ChannelConfTypeDef adc_chconf;

TIM_HandleTypeDef tim2_handle;
TIM_OC_InitTypeDef sConfig;
GPIO_InitTypeDef pwm_pin;

/* Private function prototypes -----------------------------------------------*/

#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
 set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

static void SystemClock_Config(void);
static void Error_Handler(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);

int rescale(uint32_t adc_value, int scale_value);
void write_info(int scale_value);
void set_pulse(int scale_value);
void create_display(int number_of_rect);
void visualization(int scale_value);

/* Private functions ---------------------------------------------------------*/

int main(void) {
	/* Configure the MPU attributes as Write Through */
	MPU_Config();

	/* Enable the CPU Cache */
	CPU_CACHE_Enable();

	/* STM32F7xx HAL library initialization:
	 - Configure the Flash ART accelerator on ITCM interface
	 - Configure the Systick to generate an interrupt each 1 msec
	 - Set NVIC Group Priority to 4
	 - Low Level Initialization
	 */
	HAL_Init();

	/* Configure the System clock to have a frequency of 216 MHz */
	SystemClock_Config();

	/* Add your application code here
	 */
	BSP_LED_Init(LED_GREEN);
	BSP_LCD_Init();

	BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
	BSP_LCD_SelectLayer(1);
	BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
	BSP_LCD_Clear(LCD_COLOR_WHITE);

	__HAL_RCC_USART1_CLK_ENABLE();
	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate   = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits   = UART_STOPBITS_1;
	uart_handle.Init.Parity     = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode       = UART_MODE_TX_RX;
	BSP_COM_Init(COM1, &uart_handle);

	/*PWM*/
	__HAL_RCC_TIM2_CLK_ENABLE();
	tim2_handle.Instance = TIM2;
	tim2_handle.Init.Period = 100;
	tim2_handle.Init.Prescaler = 1;
	tim2_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&tim2_handle);

	__HAL_RCC_GPIOA_CLK_ENABLE();
	pwm_pin.Alternate = GPIO_AF1_TIM2;
	pwm_pin.Mode = GPIO_MODE_AF_PP;
	pwm_pin.Pin = GPIO_PIN_15;
	pwm_pin.Pull = GPIO_NOPULL;
	pwm_pin.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOA, &pwm_pin);

	HAL_TIM_PWM_Init(&tim2_handle);

	sConfig.OCMode = TIM_OCMODE_PWM1;
	sConfig.Pulse = 50;
	HAL_TIM_PWM_ConfigChannel(&tim2_handle, &sConfig, TIM_CHANNEL_1);

	HAL_TIM_Base_Start(&tim2_handle);
	HAL_TIM_PWM_Start(&tim2_handle, TIM_CHANNEL_1);

	/*ADC*/
	__HAL_RCC_GPIOA_CLK_ENABLE();
	gpio_adc_init.Mode = GPIO_MODE_ANALOG;
	gpio_adc_init.Pin = GPIO_PIN_0;
	gpio_adc_init.Speed	= GPIO_SPEED_LOW;
	gpio_adc_init.Pull	= GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &gpio_adc_init);

	__HAL_RCC_ADC3_CLK_ENABLE();
	adc_handle.Instance	= ADC3;
	HAL_ADC_Init(&adc_handle);

	adc_chconf.Channel = ADC_CHANNEL_0;
	adc_chconf.SamplingTime = ADC_SAMPLETIME_56CYCLES;

	HAL_ADC_ConfigChannel(&adc_handle, &adc_chconf);

	uint32_t adc_value = 0;
	int scale_value = 0;

	create_display(20);

	while (1)
	{
		HAL_ADC_Start(&adc_handle);
		adc_value = HAL_ADC_GetValue(&adc_handle);
		set_pulse(rescale(adc_value, scale_value));
		HAL_Delay(50);
	}
}

int rescale(uint32_t adc_value, int scale_value)
{
	scale_value = (100 - 0) / (4095.0 - 0) * (adc_value - 0) + 0;
	write_info(scale_value);
	visualization(scale_value);
	return scale_value;
}

void write_info(int scale_value)
{
	uint8_t text[30];
	BSP_LCD_Clear(LCD_COLOR_WHITE);
	create_display(20);
	sprintf(text, "Actual brightness: %d %%", scale_value);
	BSP_LCD_DisplayStringAt(10, 20, text, LEFT_MODE);
}

void set_pulse(int scale_value)
{
	sConfig.Pulse = scale_value;
	HAL_TIM_PWM_ConfigChannel(&tim2_handle, &sConfig, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&tim2_handle, TIM_CHANNEL_1);
	HAL_Delay(10);
}

void create_display(int number_of_rect)
{
	int i;
	int x = 40;
	for(i = 0; i < number_of_rect; i++) {
		BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
		BSP_LCD_DrawRect(x, 110, 15, 60);
		x += 20;
	}
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
}

void visualization(int scale_value)
{
	int number_of_rect = scale_value / 5;
	int i;
	int x = 40;
	for(i = 0; i < number_of_rect; i++) {
		if (i < 7){
			BSP_LCD_SetTextColor(LCD_COLOR_YELLOW);
		}
		if (i > 6 && i < 13){
			BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
		}
		if (i > 12){
			BSP_LCD_SetTextColor(LCD_COLOR_RED);
		}
		BSP_LCD_FillRect(x, 110, 15, 60);
		x += 20;
	}
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
}


PUTCHAR_PROTOTYPE {
	/* Place your implementation of fputc here */
	/* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
	HAL_UART_Transmit(&uart_handle, (uint8_t *)&ch, 1, 0xFFFF);
	return ch;
}

/**
 * @brief  System Clock Configuration
 *         The system Clock is configured as follow :
 *            System Clock source            = PLL (HSE)
 *            SYSCLK(Hz)                     = 216000000
 *            HCLK(Hz)                       = 216000000
 *            AHB Prescaler                  = 1
 *            APB1 Prescaler                 = 4
 *            APB2 Prescaler                 = 2
 *            HSE Frequency(Hz)              = 25000000
 *            PLL_M                          = 25
 *            PLL_N                          = 432
 *            PLL_P                          = 2
 *            PLL_Q                          = 9
 *            VDD(V)                         = 3.3
 *            Main regulator output voltage  = Scale1 mode
 *            Flash Latency(WS)              = 7
 * @param  None
 * @retval None
 */
static void SystemClock_Config(void) {
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;

	/* Enable HSE Oscillator and activate PLL with HSE as source */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 25;
	RCC_OscInitStruct.PLL.PLLN = 432;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 9;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/* activate the OverDrive to reach the 216 Mhz Frequency */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
	 clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @param  None
 * @retval None
 */
static void Error_Handler(void) {
	/* User may add here some code to deal with this error */
	while (1) {
	}
}

/**
 * @brief  Configure the MPU attributes as Write Through for SRAM1/2.
 * @note   The Base Address is 0x20010000 since this memory interface is the AXI.
 *         The Region Size is 256KB, it is related to SRAM1 and SRAM2  memory size.
 * @param  None
 * @retval None
 */
static void MPU_Config(void) {
	MPU_Region_InitTypeDef MPU_InitStruct;

	/* Disable the MPU */
	HAL_MPU_Disable();

	/* Configure the MPU attributes as WT for SRAM */
	MPU_InitStruct.Enable = MPU_REGION_ENABLE;
	MPU_InitStruct.BaseAddress = 0x20010000;
	MPU_InitStruct.Size = MPU_REGION_SIZE_256KB;
	MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
	MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
	MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
	MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
	MPU_InitStruct.Number = MPU_REGION_NUMBER0;
	MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
	MPU_InitStruct.SubRegionDisable = 0x00;
	MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

	HAL_MPU_ConfigRegion(&MPU_InitStruct);

	/* Enable the MPU */
	HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

/**
 * @brief  CPU L1-Cache enable.
 * @param  None
 * @retval None
 */
static void CPU_CACHE_Enable(void) {
	/* Enable I-Cache */
	SCB_EnableICache();

	/* Enable D-Cache */
	SCB_EnableDCache();
}

#ifdef  USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
	 ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{
	}
}
#endif

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
