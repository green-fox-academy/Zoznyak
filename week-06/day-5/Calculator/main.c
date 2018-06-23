#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void token_input(char line[], float *num1, float *num2, char *oper);
void choose_operation(char oper, float num1, float num2, float *result);
float addition(float num1, float num2);
float subtraction(float num1, float num2);
float multiplication(float num1, float num2);
float division(float num1, float num2);
void set_cursor_pos(int x, int y);
void clear_screen();
void read_file();
void help();

COORD coord = {0,0};

int main()
{
    char line[30] = "dsfs";
    float num1 = 0;
    float num2 = 0;
    float result = 0;
    char oper = 'a';

    read_file();
    getchar();
    clear_screen();
    while (1)
    {
        gets(line);
        if (strstr(line, "exit"))
        {
            break;
        }
        if (strstr(line, "clear"))
        {
            clear_screen();
        }
        if (strstr(line, "help"))
        {
            help();
        }
        else if (!(strstr(line, "exit")) && !(strstr(line, "clear")) && !(strstr(line, "help")))
        {
            set_cursor_pos(strlen(line), coord.Y);
            token_input(line, &num1, &num2, &oper);
            choose_operation(oper, num1, num2, &result);
            printf(" = %.3f\n", result);
            coord.Y++;
            num1 = 0;
        }
    }
    return 0;
}
void token_input(char line[], float *num1, float *num2, char *oper)
{
    int i;
    char *p;
    for (p = strtok(line, " "); p != NULL; p = strtok(NULL, " "))
    {
        if ((atof(p) > 0) && (*num1 == 0))
        {
            *num1 = atof(p);
        }
        if (atof(p) == 0)
        {
            *oper = *p;
        }
        if ((atof(p) > 0) && (*num1 != 0))
        {
            *num2 = atof(p);
        }
    }
}
void choose_operation(char oper, float num1, float num2, float *result)
{
    switch(oper)
    {
    case '+':
        *result = addition(num1, num2);
        break;
    case '-':
        *result = subtraction(num1, num2);
        break;
    case '*':
        *result = multiplication(num1, num2);
        break;
    case '/':
        *result = division(num1, num2);
        break;
    }
}

float addition(float num1, float num2)
{
    float result = num1 + num2;
    return result;
}

float subtraction(float num1, float num2)
{
    float result = num1 - num2;
    return result;
}

float multiplication(float num1, float num2)
{
    float result = num1 * num2;
    return result;
}

float division(float num1, float num2)
{
    if (num2 != 0)
    {
        float result = num1 / num2;
        return result;
    }
}

void set_cursor_pos(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void clear_screen()
{
    system("@cls||clear");
    coord.X = 0;
    coord.Y = 0;
    set_cursor_pos(coord.X, coord.Y);
}

void read_file()
{
    char textLine[50];
    FILE *fp;
    fp = fopen("help.txt", "r");
    while (fgets(textLine, 80, fp) != NULL)
    {
        printf("%s", textLine);
    }
    fclose(fp);
}

void help()
{
    clear_screen();
    read_file();
    getchar();
    clear_screen();
}
