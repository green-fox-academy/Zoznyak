#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

struct rectangular_cuboid {
    double a;
    double b;
    double c;
};
double GetSurface(double a, double b, double c);
double GetVolume(double a, double b, double c);

#endif // RECTANGLE_H_INCLUDED
