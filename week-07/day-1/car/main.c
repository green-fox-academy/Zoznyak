#include <stdio.h>
#include <stdlib.h>
#include "car.h"

int main()
{
    car car1;
    car car2;
    car1.type = TESLA;
    car1.gas = 0;
    car1.km = 400;
    car2.type = VOLVO;
    car2.gas = 46.23;
    car2.km = 750;
    stat(car1);
    stat(car2);
    return 0;
}
