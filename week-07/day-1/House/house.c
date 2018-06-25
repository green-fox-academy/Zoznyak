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

int counts_good_deals(t_house houses[], int length)
{
    int counter = 0;
    int i;
    for (i = 0; i < length; i++){
        if (houses[i].price / houses[i].area < 400 ){
            counter++;
        }
    }
    return counter;
}
