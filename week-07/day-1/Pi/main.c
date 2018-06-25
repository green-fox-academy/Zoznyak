#include <stdio.h>
#include <stdlib.h>
#include "circle.h"

int main()
{
    float radius;
    printf("Enter the radius:\n");
    scanf("%f", &radius);
    printf("The area of the circle is: %f\n",Area(radius));
    return 0;
}


