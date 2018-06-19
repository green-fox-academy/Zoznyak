#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (i == j)
            {
                printf("%i", 1);
            }
            else
            {
                printf("%i", 0);
            }
        }
        printf("\n");
    }
    return 0;
}
