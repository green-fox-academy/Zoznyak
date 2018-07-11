#include "main.h"
#include <string.h>
#include "fonts.h"
#include "stm32746g_discovery_ts.h"
#include "stm32746g_discovery_lcd.h"

/** @addtogroup STM32F7xx_HAL_Examples
  * @{
  */

/** @addtogroup Templates
  * @{
  */ 
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef uart_handle;
RNG_HandleTypeDef random;
TS_StateTypeDef ts_state;
TIM_HandleTypeDef tim2_handle;

uint32_t posX, posY;
char command[2] = {};

/* Private function prototypes -----------------------------------------------*/
void draw_reactangle();
void draw_start_button();
void draw_restart();
void print_avg_time(int sum);

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

/* Private functions ---------------------------------------------------------*/


int main(void)
{
  /* Configure the MPU attributes as Write Through */
  MPU_Config();

  /* Enable the CPU Cache */
  CPU_CACHE_Enable();
  HAL_Init();

  /* Configure the System clock to have a frequency of 216 MHz */
  SystemClock_Config();

  /* Add your application code here
     */
  BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
  BSP_LCD_Init();

  __HAL_RCC_USART1_CLK_ENABLE();
  uart_handle.Instance = USART1;
  uart_handle.Init.BaudRate   = 115200;
  uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
  uart_handle.Init.StopBits   = UART_STOPBITS_1;
  uart_handle.Init.Parity     = UART_PARITY_NONE;
  uart_handle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
  uart_handle.Init.Mode       = UART_MODE_TX_RX;
  BSP_COM_Init(COM1, &uart_handle);

  __HAL_RCC_RNG_CLK_ENABLE();
  random.Instance = RNG;
  HAL_RNG_Init(&random);

  BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
  BSP_LCD_SelectLayer(1);
  BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
  BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
  BSP_LCD_SetTextColor(LCD_COLOR_RED);
  BSP_LCD_Clear(LCD_COLOR_WHITE);
  BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());

  __HAL_RCC_TIM2_CLK_ENABLE();
  tim2_handle.Instance = TIM2;
  tim2_handle.Init.Period = 60000;
  tim2_handle.Init.Prescaler = 10800;
  tim2_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
  HAL_TIM_Base_Init(&tim2_handle);

//  HAL_NVIC_SetPriority(TIM2_IRQn, 0, 1);
//  HAL_NVIC_EnableIRQ(TIM2_IRQn);
//  HAL_TIM_Base_Start_IT(&tim2_handle);

  HAL_NVIC_SetPriority(USART1_IRQn, 0, 1);
  HAL_NVIC_EnableIRQ(USART1_IRQn);

  int game = 0;
  int go = 0;
  int restart = 1;
  uint32_t start;
  uint32_t stop;
  uint32_t result;
  uint32_t sum = 0;

  HAL_UART_Receive_IT(&uart_handle, command, 2);

  draw_start_button();
  while (go == 0)
  {
	  BSP_TS_GetState(&ts_state);
	  if (ts_state.touchDetected) {
		  int x,y;
		  x = ts_state.touchX[0];
  		  y = ts_state.touchY[0];
  		  if(x > 150 && x < 330 && y > 100 && y < 172){
  			  go = 1;
  			  BSP_LCD_Clear(LCD_COLOR_WHITE);
  		  }
	  }
  }
  while (restart ==1)
  {
	  BSP_LCD_SetTextColor(LCD_COLOR_RED);
	  restart = 0;
	  while (game != 5) {
			uint32_t timer = (HAL_RNG_GetRandomNumber(&random) % 11000) / 3;
			int match = 0;
			HAL_Delay(timer);
			draw_reactangle();
			start = HAL_GetTick();
			while (match == 0) {
				BSP_TS_GetState(&ts_state);
				if (ts_state.touchDetected) {
					int x, y;
					x = ts_state.touchX[0];
					y = ts_state.touchY[0];
					if (x > posX && x < posX + 50 && y > posY
							&& y < posY + 50) {
						stop = HAL_GetTick();
						result = stop - start;
						printf("%d\r\n", result);
						match = 1;
						BSP_LCD_Clear(LCD_COLOR_WHITE);
						game++;
					}
				}
			}
			sum += result;
		}
		print_avg_time(sum);
		HAL_Delay(500);
		draw_restart();
		while (restart == 0){
			BSP_TS_GetState(&ts_state);
			if (ts_state.touchDetected) {
				int x, y;
				x = ts_state.touchX[0];
				y = ts_state.touchY[0];
				if (x < 180 && y > 222) {
					restart = 1;
					game = 0;
					sum = 0;
					BSP_LCD_Clear(LCD_COLOR_WHITE);
				}
			}
		}
	}
}

void draw_reactangle()
{
	do {
		posX = (HAL_RNG_GetRandomNumber(&random) % 11000) / 20;
	} while (posX > 430);
	do {
		posY = (HAL_RNG_GetRandomNumber(&random) % 11000) / 40;
	} while (posY > 222);
	BSP_LCD_SetTextColor(LCD_COLOR_RED);
	BSP_LCD_FillRect(posX, posY, 50, 50);
}

void draw_start_button() {
	BSP_LCD_SetBackColor(LCD_COLOR_RED);
	BSP_LCD_FillRect(150, 100, 180, 72);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_DisplayStringAt(0, 125, "START", CENTER_MODE);
}

void draw_restart() {
	BSP_LCD_SetBackColor(LCD_COLOR_RED);
	BSP_LCD_SetTextColor(LCD_COLOR_RED);
	BSP_LCD_FillRect(0, 222, 180, 50);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_DisplayStringAt(25, 240, "RESTART", LEFT_MODE);
}

void print_avg_time(int sum) {
	char *text[20];
	uint32_t avg;
	avg = sum / 5;
	sprintf(text, "%d ms", avg);
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_DisplayStringAt(0, 115, "Average reaction time:", CENTER_MODE);
	BSP_LCD_DisplayStringAt(0, 135, text, CENTER_MODE);
}

void USART1_IRQHandler(void)
{
	HAL_UART_IRQHandler(&uart_handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (!strcmp(command,"aa")){
		BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
		BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
		BSP_LCD_DisplayStringAt(0, 115, "LASSU VAGY!", CENTER_MODE);
	}
	else if (!strcmp(command,"cc")){
		draw_reactangle();
	}
	HAL_UART_Receive_IT(&uart_handle, command, 2);
}


PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
  HAL_UART_Transmit(&uart_handle, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}


static void SystemClock_Config(void)
{
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
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /* activate the OverDrive to reach the 216 Mhz Frequency */
  if(HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;  
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
}


/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  /* User may add here some code to deal with this error */
  while(1)
  {

  }
}


/**
  * @brief  Configure the MPU attributes as Write Through for SRAM1/2.
  * @note   The Base Address is 0x20010000 since this memory interface is the AXI.
  *         The Region Size is 256KB, it is related to SRAM1 and SRAM2  memory size.
  * @param  None
  * @retval None
  */
static void MPU_Config(void)
{
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
static void CPU_CACHE_Enable(void)
{
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
