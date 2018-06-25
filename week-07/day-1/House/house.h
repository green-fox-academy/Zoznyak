#ifndef HOUSE_H_INCLUDED
#define HOUSE_H_INCLUDED
#define MARKETPRICE 400

typedef struct{
    char address[100];
    float price;
    int rooms;
    float area;
}t_house;

void worth_it(char* worth_or_not, t_house house);
int counts_good_deals(t_house houses[], int length);

#endif // HOUSE_H_INCLUDED
