#ifndef PRINTER_H_INCLUDED
#define PRINTER_H_INCLUDED

typedef struct{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int temperature;
}t_log;

void print_startup_message();
void clear_screen();
void print_port_list();

void print_log();
//int token_line(char text[], t_log **logs);
//int validate_line(char text[], t_log *logs);
void offset_text(int number);

int token_line(char text[], t_log *logs);
int check_year(int year);
int check_month(int month);
int check_day(int day);
int check_hour(int hour);
int check_second(int second);
int check_temperature(char temp[]);

#endif // PRINTER_H_INCLUDED
