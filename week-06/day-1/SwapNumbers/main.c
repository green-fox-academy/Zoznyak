#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1 = 123;
    int num2 = 526;
    int temp;

    temp = num1;
    num1 = num2;
    num2 = temp;

    printf("%i\n", num1);
    printf("%i", num2);
    return 0;
}
