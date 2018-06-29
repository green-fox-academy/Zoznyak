#ifndef TOKEN_H_INCLUDED
#define TOKEN_H_INCLUDED

typedef struct{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int temperature;
}t_log;

t_log all_log[100];

int token_line(char text[], t_log *logs);
int check_year(int year);
int check_month(int month);
int check_day(int day);
int check_hour(int hour);
int check_second(int second);
int check_temperature(char temp[]);
void add_valid_log(t_log logs, int *index);
void creat_log_array();

#endif // TOKEN_H_INCLUDED
