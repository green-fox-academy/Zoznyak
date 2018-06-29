#ifndef AVERAGE_H_INCLUDED
#define AVERAGE_H_INCLUDED

get_daily_avg();
int valid_date(char date[]);
int token_date(char *date, int *year, int *month, int *day);
float daily_avg(int year, int month, int day);

#endif // AVERAGE_H_INCLUDED
