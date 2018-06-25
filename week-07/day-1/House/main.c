#include <stdio.h>
#include <stdlib.h>
#include "house.h"

void worth_it(t_house house);

int main()
{
    t_house house1, house2;
    strcpy(house1.address, "1027. Bp., Keletei Karoly 5.");
    house1.area = 150;
    house1.rooms = 3;
    house1.price = 65000;
    strcpy(house1.address, "1033. Bp., Bogdani ut 8.");
    house2.area = 120;
    house2.rooms = 3;
    house2.price = 47000;

    worth_it(house2);
}
void worth_it(t_house house)
{
    if (house.price / house.area < 400){
        printf("It worths %.2lf Euro.\n", house.price);
    }
    else{
        printf("It does not worth %.2lf Euro.\n", house.price);
    }
}
