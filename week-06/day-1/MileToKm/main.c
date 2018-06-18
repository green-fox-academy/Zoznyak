#include <stdio.h>
#include <stdlib.h>

int main()
{
    double distanceInKm;
    double distanceInMile;

    printf("Enter the distance in Km: \n");
    scanf("%lf", &distanceInKm);
    distanceInMile = distanceInKm * 0.621371192;
    printf("The distance in Mile: %lf", distanceInMile);
    return 0;
}
