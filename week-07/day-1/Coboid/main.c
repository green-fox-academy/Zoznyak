#include <stdio.h>
#include <stdlib.h>
#include "rectangle.h"

// Write a function called "GetSurface" that takes a RectangularCuboid
// and returns it's surface
// Write a function called "GetVolume" that takes a RectangularCuboid
// and returns it's volume


int main()
{
    double a, b, c;
    printf("Enter the first side of the rectangle: \n");
    scanf("%lf", &a);
    printf("Enter the second side of the rectangle: \n");
    scanf("%lf", &b);
    printf("Enter the third side of the rectangle: \n");
    scanf("%lf", &c);

    printf("The surface of the rectangle is: %.2lf\n", GetSurface(a, b, c));
    return 0;
}


