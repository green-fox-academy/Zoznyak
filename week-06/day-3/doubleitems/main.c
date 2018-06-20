#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numList[] = {3, 4, 5 ,6, 7};
    int length;
    int i;

    length = sizeof(numList)/sizeof(numList[0]);
    double_items(numList, length);
    for (i = 0; i < length; i++)
    {
        printf("%i\n", numList[i]);
    }
    return 0;
}

void double_items(int numbers[], int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        numbers[i] *= 2;
    }
}
