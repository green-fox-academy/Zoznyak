#include "sandwich.h"

float price_of_order(int number_of_sandwich, Sandwich sandwich)
{
    float price = number_of_sandwich * sandwich.price;
    return price;
}
