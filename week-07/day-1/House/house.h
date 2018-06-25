#ifndef HOUSE_H_INCLUDED
#define HOUSE_H_INCLUDED
#define MARKETPRICE 400

typedef struct{
    char address[100];
    float price;
    int rooms;
    float area;
}t_house;

void worth_it(t_house house);

#endif // HOUSE_H_INCLUDED
