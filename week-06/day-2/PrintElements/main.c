#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numbers[] = {4, 5 , 6, 7};
    int i;
    for (i = 0; i < (int)sizeof(numbers)/sizeof(int); i++)
    {
        printf("%d\n", numbers[i]);
    }
    return 0;
}
