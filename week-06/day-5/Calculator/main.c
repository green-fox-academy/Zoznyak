#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void token_input(char line[], int *num1, int *num2, char *oper);
void choose_operation(char oper, int num1, int num2, int *result);
int addition(int num1, int num2);
int subtraction(int num1, int num2);
void set_cursor_pos(int x, int y);
void clear_screen();
void read_file();

COORD coord = {0,0};

int main()
{
    char line[30];
    int num1 = NULL;
    int num2 = NULL;
    int result = 0;
    char oper = 'a';
    int lengthOfLine;

    read_file();
    getchar();
    clear_screen();
    gets(line);
    set_cursor_pos(strlen(line), 0);
    token_input(line, &num1, &num2, &oper);
    choose_operation(oper, num1, num2, &result);
    printf(" = %d", result);

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
        printf("Multiplication");
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

void set_cursor_pos(int x, int y)
    {
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

void clear_screen()
{
    system("@cls||clear");
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
