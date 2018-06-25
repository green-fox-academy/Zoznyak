#include <stdio.h>
#include <stdlib.h>
#include "house.h"


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
