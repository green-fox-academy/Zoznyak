#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

float Area(float radius);

int main()
{
    float radius;
    printf("Enter the radius:\n");
    scanf("%f", &radius);
    printf("The area of the circle is: %f\n",Area(radius));
    return 0;
}

float Area(float radius)
{
    float area = radius * radius * PI;
    return area;
}
