#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number = 1234;
    int *pnumber = &number;
    printf("The value of the number: %i\n", *pnumber);
    return 0;
}
