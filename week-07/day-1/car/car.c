#include "car.h"

void stat(car item)
{
    if (item.type == TESLA){
        printf("Type: %d, km: %.2f\n", item.type, item.km);
    }
    else{
        printf("Type: %d, km: %.2f, gas: %.2f\n", item.type, item.km, item.gas);
    }
}
