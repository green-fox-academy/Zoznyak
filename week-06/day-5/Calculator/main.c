#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void token_input(char line[], int *num1, int *num2, char *oper);
void choose_operation(char oper, int num1, int num2, int *result);
int addition(int num1, int num2);
int subtraction(int num1, int num2);
int multiplication(int num1, int num2);
int division(int num1, int num2);
void set_cursor_pos(int x, int y);
void clear_screen();
void read_file();
void help();

COORD coord = {0,0};

int main()
{
    char line[30] = "dsfs";
    int num1 = NULL;
    int num2 = NULL;
    int result = 0;
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
            printf(" = %d\n", result);
            coord.Y++;
            num1 = NULL;
        }
    }
    return 0;
}
void token_input(char line[], int *num1, int *num2, char *oper)
{
    int i;
    char *p;
    for (p = strtok(line, " "); p != NULL; p = strtok(NULL, " "))
    {
        if ((atoi(p) > 0) && (*num1 == NULL))
        {
            *num1 = atoi(p);
        }
        if (atoi(p) == 0)
        {
            *oper = *p;
        }
        if ((atoi(p) > 0) && (*num1 != NULL))
        {
            *num2 = atoi(p);
        }
    }
}
void choose_operation(char oper, int num1, int num2, int *result)
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

int addition(int num1, int num2)
{
    int result = num1 + num2;
    return result;
}

int subtraction(int num1, int num2)
{
    int result = num1 - num2;
    return result;
}

int multiplication(int num1, int num2)
{
    int result = num1 * num2;
    return result;
}

int division(int num1, int num2)
{
    if (num2 != 0)
    {
        int result = num1 / num2;
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
