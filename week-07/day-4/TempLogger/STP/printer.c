#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
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
	printf(" c      Close port\n");
	printf(" k      List after error handling\n");
	printf(" a      Avarage temperature handling by days\n");
    printf(" e      Exit from the program\n");
}

void print_daily_avarage_message()
{
    clear_screen();
	//printf("Temperature Logger Application\n");
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
    char textLine[50];
    char temp[50];
    t_log logs;
    FILE *fp;
    fp = fopen("log.txt", "r");
    printf("  Date\t\tTime\t   Temperature\n");
	printf("======================================\n");
    while (fgets(textLine, 50, fp) != NULL){
        strcpy(temp, textLine);
        if (token_line(temp, &logs) == 1){
            printf("%i.%i.%i", logs.year, logs.month, logs.day);
            offset_text(13 - ((1 + (int)log10(logs.year)) + (1 + (int)log10(logs.month)) + (1 + (int)log10(logs.day))));
            printf("%i:%i:%i", logs.hour, logs.minute, logs.second);
            offset_text(14 - ((1 + (int)log10(logs.hour)) + (1 + (int)log10(logs.minute)) + (1 + (int)log10(logs.second))));
            printf("%i\n", atoi(logs.temperature));
        }
    }
    fclose(fp);
    printf("\n");
    printf("Press \"h\" to go back or \"e\" to exit...");
}


int token_line(char text[], t_log *logs)
{
    char *p;
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int temperature;
    int number = 0;
    for (p = strtok(text, ".: "); p != NULL; p = strtok(NULL, ".: ")){
        if(number == 0){
            if (check_year(atoi(p)) == 1){
                year = atoi(p);
                number++;
            }
        }
        else if(number == 1){
            if (check_month(atoi(p)) == 1){
                month = atoi(p);
                number++;
            }
        }
        else if(number == 2){
            if (check_day(atoi(p)) == 1){
                day = atoi(p);
                number++;
            }
        }
        else if(number == 3){
            if (check_hour(atoi(p)) == 1){
                hour = atoi(p);
                number++;
            }
        }
        else if(number == 4){
            if (check_minute(atoi(p)) == 1){
                minute = atoi(p);
                number++;
            }
        }
        else if(number == 5){
            if (check_second(atoi(p)) == 1){
                second = atoi(p);
                number++;
            }
        }
        else if(number == 6){
            if (check_temperature(p) == 1){
                temperature = p;
                number++;
            }
        }
    }
    if (number ==7){
        (*logs).year = year;
        (*logs).month = month;
        (*logs).day = day;
        (*logs).hour = hour;
        (*logs).minute = minute;
        (*logs).second = second;
        (*logs).temperature = temperature;
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

int check_temperature(char temperature[])
{
    if((atoi(temperature) > -273 && strlen(temperature) != 1 && (atoi(temperature)) != 0) || (strlen(temperature) == 2 && isdigit(temperature[0]) == 1)){
            return 1;
        }
    else{
        return 0;
    }
}

int check_year(int year)
{
     if (year > 0 && year < 2019){
        return 1;
     }
     else{
        return 0;
     }
}

int check_month(int month)
{
     if (month > 0 && month < 13){
        return 1;
     }
     else{
        return 0;
     }
}

int check_day(int day)
{
     if (day > 0 && day < 32){
        return 1;
     }
     else{
        return 0;
     }
}

int check_hour(int hour)
{
     if (hour >- 0 && hour < 24){
        return 1;
     }
     else{
        return 0;
     }
}

int check_minute(int minute)
{
     if (minute >= 0 && minute < 60){
        return 1;
     }
     else{
        return 0;
     }
}

int check_second(int second)
{
     if (second >= 0 && second < 60){
        return 1;
     }
     else{
        return 0;
     }
}




