#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "racer.h"

int main()
{
    srand(time(NULL));
    racer racers[4];
    int numbers[] = {0,0,0,0};
    racer zoli, andras, johny, samu;
    zoli.country = HUN;
    *(zoli.name) = "Zoltan";
    zoli.result = random_result(numbers);
    andras.country = FRA;
    *(andras.name) = "Andras";
    andras.result = random_result(numbers);
    johny.country = ENG;
    *(johny.name) = "Johny";
    johny.result = random_result(numbers);
    samu.country = GER;
    *(samu.name) = "Samu";
    samu.result = random_result(numbers);

    printf("%d\n", zoli.result);
    printf("%d\n", andras.result);
    printf("%d\n", johny.result);
    printf("%d\n", samu.result);
    return 0;
}

void random_result(int *numbers)
{
    int random;
    int i;
    int contains;
    do{
        contains = 0;
        random = (rand() % 4) + 1;
        for (i = 0; i < 4; i++){
            if(random == numbers[i]){
                contains = 1;
            }
        }
    }while(contains == 1);
    for (i = 0; i < 4; i++){
            if(numbers[i] == 0){
            numbers[i] = random;
            break;
        }
    }
}




