#include <stdio.h>
#include <stdlib.h>

int sum_all(int numbers[], int length);

int main()
{
    int ai[] = {3, 4, 5, 6, 7};
    int length = sizeof(ai)/sizeof(ai[0]);
    printf("Sum of all elements: %i\n", sum_all(ai, length));
    return 0;
}

int sum_all(int numbers[], int length)
{
    int i;
    int sum = 0;
    for (i = 0; i < length; i++)
    {
        sum += numbers[i];
    }
    return sum;
}
