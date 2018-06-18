#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a = 0;
    double b = 0;
    double c = 0;
    double volume;
    double surface;

    printf("Enter the size of the first side: \n");
    scanf("%lf", &a);
    printf("Enter the size of the second side: \n");
    scanf("%lf", &b);
    printf("Enter the size of the third side: \n");
    scanf("%lf", &c);
    volume = a * b * c;
    surface = 2 * ((a * b) + (a * c) + (b * c));
    printf("Volume: %.2lf\n", volume);
    printf("Surface: %.2lf\n", surface);
    return 0;
}
