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
	do {
	    clear_screen();
        printf("Please enter date (yyyy.mm.dd) you want to see the average temperature of!\n");
        printf("\n");
        gets(date);
	}while(valid_date(&date) != 1);
	printf(" ");
}

int valid_date(char *date)
{
    printf("%i", strlen(date));
    char *p;
    int valid = 0;
    if(strlen(date) == 10){
        for (p = strtok(date, "."); p != NULL; p = strtok(NULL, ".")){
            if(atoi(p) > 0 && atoi(p) < 2019){
                valid++;
            }
        }
    }
    if(valid == 3){
        return 1;
    }
    else{
        return 0;
    }
}
