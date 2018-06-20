#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a = (int *)calloc(10, sizeof(int));
    int i;

    for (i = 0; i < 5; i++)
    {
        a[i] = i;
    }
    for (i = 0; i < 10; i++)
    {
        printf("%i\n", a[i]);
    }
    free(a);
    return 0;
}
