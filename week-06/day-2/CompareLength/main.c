#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p1[] = {1, 2, 3};
    int p2[] = {4, 5};

    printf("%d", (int)sizeof(p1) < (int)sizeof(p2));
    return 0;
}
