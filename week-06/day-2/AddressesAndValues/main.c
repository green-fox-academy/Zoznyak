#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number = 2017;
    float Pi = 3.14;
    char letter = 't';
    int *pnumber = &number;
    float *pPi = &Pi;
    char *pletter = &letter;

    printf("Value\t Value with pointer\t Address\t Address with pointer\n");
    printf("%i\t\t %i\t\t%p\t\t%p\n", number, *pnumber, &number, pnumber);
    printf("%.2f\t\t %.2f\t\t%p\t\t%p\n", Pi, *pPi, &Pi, pPi);
    printf("%c\t\t %c\t\t%p\t\t%p\n", letter, *pletter, &letter, pletter);
    return 0;
}
