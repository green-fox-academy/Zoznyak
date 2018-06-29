#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "printer.h"
#include "rs232/rs232.h"
#include "../token.h"
#include "../avarage.h"

void print_startup_message()
{
	clear_screen();
	printf("Temperature Logger Application\n");
	printf("==============================\n");
	printf("Commands:\n");
	printf(" h      Show the command list\n");
	printf(" l      List available ports\n");
	printf(" p      Set port name\n");
	printf(" o      Open port\n");
	printf(" s      Start logging / Stop logging\n");
	printf(" c      Close port\n");
	printf(" k      List after error handling\n");
	printf(" a      Avarage temperature handling by days\n");
    printf(" e      Exit from the program\n");
}

void print_daily_avarage_message()
{
    clear_screen();
	printf("Avarage temperature handling by days\n");
	printf("====================================\n");
	printf("Commands:\n");
	printf(" 1      One day avarage\n");
	printf(" 2      Last days avarage\n");
	printf(" 3      Day to day avarage\n");
}

void clear_screen()
{
	system("cls");
}

void print_port_list()
{
	clear_screen();
	printf("Available serial ports:\n");
	printf("====================\n");
	int port_count = comEnumerate();
	if (port_count <= 0) {
		printf("No serial port found!\n");
	} else {
		for (int i = 0; i < port_count; i++)
			printf("%d. - %s\n", i + 1, comGetPortName(i));
	}
	printf("\n");
    printf("Press \"h\" to go back or \"e\" to exit...");
}

void print_log()
{
    int i = 0;
    printf("  Date\t\tTime\t   Temperature\n");
	printf("======================================\n");
    while ((1 + (int)log10(all_log[i].year)) == 4){
        printf("%i.%i.%i", all_log[i].year, all_log[i].month, all_log[i].day);
        offset_text(13 - ((1 + (int)log10(all_log[i].year)) + (1 + (int)log10(all_log[i].month)) + (1 + (int)log10(all_log[i].day))));
        printf("%i:%i:%i", all_log[i].hour, all_log[i].minute, all_log[i].second);
        offset_text(14 - ((1 + (int)log10(all_log[i].hour)) + (1 + (int)log10(all_log[i].minute)) + (1 + (int)log10(all_log[i].second))));
        printf("%i\n", all_log[i].temperature);
        i++;
    }
    printf("\n");
    printf("Press \"h\" to go back or \"e\" to exit...");
}

void offset_text(int number)
{
    int i;
    for(i = 0; i < number; i++){
        printf(" ");
    }
}



