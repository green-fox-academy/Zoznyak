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
int token_line(char text[], t_log **logs);
int validate_line(char text[], t_log *logs);
void offset_text(int number);

#endif // PRINTER_H_INCLUDED
