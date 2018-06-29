#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "token.h"
#include "STP/printer.h"
#include "STP/rs232/rs232.h"
#include "avarage.h"

void creat_log_array()
{
    char textLine[50];
    char temp[50];
    t_log logs;
    int index = 0;
    FILE *fp;
    fp = fopen("log.txt", "r");
    while (fgets(textLine, 50, fp) != NULL){
        strcpy(temp, textLine);
        if (token_line(temp, &logs) == 1){
                add_valid_log(logs, &index);
        }
    }
    fclose(fp);
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
                temperature = atoi(p);
                number++;
            }
        }
        else{
            number++;
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

void add_valid_log(t_log logs, int *index)
{
    all_log[*index].year = logs.year;
    all_log[*index].month = logs.month;
    all_log[*index].day = logs.day;
    all_log[*index].hour = logs.hour;
    all_log[*index].minute = logs.minute;
    all_log[*index].second = logs.second;
    all_log[*index].temperature = logs.temperature;
    (*index) ++;
}
