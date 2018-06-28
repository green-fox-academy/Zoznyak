#include <stdio.h>
#include <string.h>
#include <math.h>
#include "printer.h"
#include "rs232/rs232.h"

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
	printf(" k      List logged data\n");
	printf(" c      Close port\n");
    printf(" e      Exit from the program\n");
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
}

void print_log()
{
    char textLine[50];
    char temp[50];
    t_log logs;
    FILE *fp;
    fp = fopen("log.txt", "r");
    printf("  Date\t\tTime\t   Temperature\n");
	printf("======================================\n");
    while (fgets(textLine, 50, fp) != NULL){
        strcpy(temp, textLine);
        if (validate_line(temp, &logs) == 1){
            printf("%i.%i.%i", logs.year, logs.month, logs.day);
            offset_text(13 - ((1 + (int)log10(logs.year)) + (1 + (int)log10(logs.month)) + (1 + (int)log10(logs.day))));
            printf("%i:%i:%i", logs.hour, logs.minute, logs.second);
            offset_text(15 - ((1 + (int)log10(logs.hour)) + (1 + (int)log10(logs.minute)) + (1 + (int)log10(logs.second))));
            printf("%i\n", logs.temperature);
        }
    }
    fclose(fp);
    printf("\n");
    printf("Press \"h\" to go back...");
}

int validate_line(char text[], t_log *logs)
{
    if(token_line(text, &logs) == 1){
        return 1;
    }
    else{
        return 0;
    }
}

int token_line(char text[], t_log **logs)
{
    char *p;
    int number = 0;
    int valid_arg;
    //char *pdate;
    for (p = strtok(text, ".: "); p != NULL; p = strtok(NULL, ".: ")){
        if(number == 0){
            valid_arg = 2019;
            (*(*logs)).year = atoi(p);
        }
        else if(number == 1){
            valid_arg = 13;
            (*(*logs)).month = atoi(p);
        }
        else if(number == 2){
            valid_arg = 32;
            (*(*logs)).day = atoi(p);
        }
        else if(number == 3){
            valid_arg = 24;
            (*(*logs)).hour = atoi(p);
        }
        else if(number == 4){
            valid_arg = 60;
            (*(*logs)).minute = atoi(p);
        }
        else if(number == 5){
            valid_arg = 60;
            (*(*logs)).second = atoi(p);
        }
        else if(number == 6 && (atoi(p)) > 0){
            //printf("%i", atoi(p));
            valid_arg = 100;
            (*(*logs)).temperature = atoi(p);
        }
        if (atoi(p) > 0 && atoi(p) < valid_arg){
            number++;
            }

    }
    if (number == 6 || number == 7){
        return 1;
    }
    else {
        return 0;
    }
}

void offset_text(int number)
{
    int i;
    for(i = 0; i < number; i++){
        printf(" ");
    }
}


