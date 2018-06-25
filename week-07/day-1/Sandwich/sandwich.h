#ifndef SANDWICH_H_INCLUDED
#define SANDWICH_H_INCLUDED

typedef struct{
    char name[30];
    float price;
    float weight;
}Sandwich;

float price_of_order(int number_of_sandwich, Sandwich sandwich);

#endif // SANDWICH_H_INCLUDED
