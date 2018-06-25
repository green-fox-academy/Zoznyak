#include <stdio.h>
#include <stdlib.h>
#include "sandwich.h"

int main()
{
    Sandwich ham;
    strcpy(ham.name, "Ham sandwich");
    ham.price = 4;
    Sandwich cheese;
    strcpy(cheese.name, "Cheese sandwich");
    cheese.price = 5;

    printf("The price of your order is: %.2f$\n", price_of_order(2, ham));
    return 0;
}


