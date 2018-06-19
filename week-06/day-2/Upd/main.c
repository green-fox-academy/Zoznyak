#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number = 1234;
    int *pnumber = &number;

    *pnumber = 42;
    printf("%i\n", number);
    return 0;
}
