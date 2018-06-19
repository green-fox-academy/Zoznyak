#include <stdio.h>
#include <stdlib.h>

void Greet(char string[]);

int main()
{
    char a1[] = "Greenfox";
    Greet(a1);
    return 0;
}

void Greet(char string[])
{
    printf("Greetings dear %s!", string);
}

