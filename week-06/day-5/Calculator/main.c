#include <stdio.h>
#include <stdlib.h>

void token_input(char line[], int *num1, int *num2, char *oper);
void choose_operation(char oper);

int main()
{
    char line[30];
    int num1 = NULL;
    int num2 = NULL;
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
    choose_operation(oper);
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
void choose_operation(char oper)
{
    switch(oper)
    {
    case '+':
        printf("Addition!!!!!");
        break;
    case '-':
        printf("Substitution");
        break;
    case '*':
        printf("Multiplication");
        break;
    }
}
