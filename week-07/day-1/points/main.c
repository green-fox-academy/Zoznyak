#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	float x;
	float y;
}point_t;

float distance(point_t p1, point_t p2);

int main()
{
    point_t p1, p2;
    p1.x = 3;
    p1.y = 2;
    p2.x = 9;
    p2.y = 7;
    printf("The distance is: %.4f\n", distance(p1,p2));
    return 0;
}

float distance(point_t p1, point_t p2)
{
    float dist;
    dist = (float)sqrt(((p1.x - p2.x)*(p1.x - p2.x)) + ((p1.y - p2.y)*(p1.y - p2.y)));
    return dist;
}
