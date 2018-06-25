#include "house.h"

void worth_it(char* worth_or_not, t_house house)
{
    if (house.price / house.area < 400){
        strcpy(worth_or_not, "does worth");
    }
    else{
        strcpy(worth_or_not, "does not worth");
    }
}
