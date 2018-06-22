#include <stdio.h>
#include <stdlib.h>

void token_input(char line[], int *num1, int *num2, char *oper);
void choose_operation(char oper, int num1, int num2, int *result);
int addition(int num1, int num2);
int subtraction(int num1, int num2);

int main()
{
    char line[30];
    int num1 = NULL;
    int num2 = NULL;
    int result = 0;
    char oper = 'a';
    puts("\t   CLI Calculator");
    puts("====================================");
    puts("usage: [number] [operation] [number]");
    puts("Commands:\n");
    puts(" +\t summation");
    puts(" -\t subtraction");
    puts(" *\t multiplication");
    puts(" /\t division");
    puts(" %\t division with reminder");
    puts(" ^\t squaring");
    puts(" log\t logarithm");
    puts(" binto\t binary to hex or dec");
    puts(" hexto\t hexadecimal to bin or dec");
    puts(" decto\t decimal to bin or hey");
    puts("====================================");
    puts(" exit\t exiting from the program");
    puts(" clear\t clear the screen");
    puts(" help\t print usage");
    puts("====================================");
    puts("Hit enter to start!");
    puts("====================================");
    getchar();
    token_input(gets(line), &num1, &num2, &oper);
    choose_operation(oper, num1, num2, &result);
    puts("");
    printf("The result is: %d", result);
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
