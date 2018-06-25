#include "house.h"

void worth_it(t_house house)
{
    if (house.price / house.area < 400){
        printf("It worths %.2lf Euro.\n", house.price);
    }
    else{
        printf("It does not worth %.2lf Euro.\n", house.price);
    }
}
