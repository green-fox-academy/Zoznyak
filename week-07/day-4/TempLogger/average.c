#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "token.h"
#include "average.h"
#include "STP/printer.h"
#include "STP/rs232/rs232.h"

get_daily_avg()
{
	char date[10];
	int year;
	int month;
	int day;
	do {
	    clear_screen();
        printf("Please enter date (yyyy.mm.dd) you want to see the average temperature of!\n");
        gets(date);
	}while(token_date(&date,&year,&month,&day) != 1);
	printf("AVG: %.2fl",daily_avg(year, month, day));
}

int token_date(char *date, int *year, int *month, int *day)
{
    char *p;
    int counter = 0;
    if(strlen(date) == 10){
        for (p = strtok(date, "."); p != NULL; p = strtok(NULL, ".")){
            if(counter == 0){
                if (check_year(atoi(p)) == 1){
                    *year = atoi(p);
                    counter++;
                }
            }
            else if(counter == 1){
                if (check_month(atoi(p)) == 1){
                    *month = atoi(p);
                    counter++;
                }
            }
            else if(counter == 2){
                if (check_day(atoi(p)) == 1){
                    *day = atoi(p);
                    counter++;
                }
            }
        }
    }
    if(counter == 3){
        return 1;
    }
    else{
        return 0;
    }
}

float daily_avg(int year, int month, int day)
{
    int i = 0;
    int match = 0;
    int sum = 0;
    float avg;
    while ((1 + (int)log10(all_log[i].year)) == 4){
        if(all_log[i].year == year && all_log[i].month == month && all_log[i].day == day){
            sum += all_log[i].temperature;
            match++;
        }
        i++;
    }
    if(match != 0){
        avg = (float)sum / match;
    }
    else{
        avg = 0;
    }
    return avg;
}
