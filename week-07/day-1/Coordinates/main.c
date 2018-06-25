#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
}coordinate;

int main()
{
    int i;
    coordinate coordinates [5];
    for (i = 0; i < 5; i++){
        coordinates[i].x = rand() % 100;
        coordinates[i].y = rand() % 100;
        printf("%i. X: %i, Y:%i \n", i, coordinates[i].x, coordinates[i].y);
    }
    return 0;
}
