#include "rectangle.h"

double GetSurface(double a, double b, double c)
{
    double surface = 2 * (a * b + a * c + b * c);
    return surface;
}

double GetVolume(double a, double b, double c)
{
    double volume = a * b * c;
    return volume;
}
