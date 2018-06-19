#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 20;
    int b = 17;
    int *pa = &a;
    int *pb = &b;
    int sum;

    sum = *pa + *pb;

    printf("%i\n", sum);
    return 0;
}
