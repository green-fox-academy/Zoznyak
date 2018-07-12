#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "racer.h"

char* get_fastest(racer *racers, int length);

int main()
{
    srand(time(NULL));
    racer racers[4];
    int length = sizeof(racers)/sizeof(racers[0]);
    int numbers[] = {0,0,0,0};
    racer zoli, andras, johny, samu;
    zoli.country = ENG;
    strcpy(zoli.name,"Zoltan");
    zoli.result = random_result(numbers);
    andras.country = FRA;
    strcpy(andras.name,"Andras");
    andras.result = random_result(numbers);
    johny.country = ENG;
    strcpy(johny.name, "Johny");
    johny.result = random_result(numbers);
    samu.country = GER;
    strcpy(samu.name, "Samu");
    samu.result = random_result(numbers);

    fill_up_racers(racers, zoli);
    fill_up_racers(racers, andras);
    fill_up_racers(racers, johny);
    fill_up_racers(racers, samu);

    printf("The fastest driver is: %s\n", get_fastest(racers, length));

    printf("%d.: %s\n", racers[0].result, racers[0].name);
    printf("%d.: %s\n", racers[1].result, racers[1].name);
    printf("%d.: %s\n", racers[2].result, racers[2].name);
    printf("%d.: %s\n", racers[3].result, racers[3].name);
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

void fill_up_racers(racer *racers,racer competitor)
{
    strcpy(racers[competitor.result-1].name, competitor.name);
    racers[competitor.result-1].country = competitor.country;
    racers[competitor.result-1].result = competitor.result;
}

char* get_fastest(racer *racers, int length)
{
    int i;
    char *fastest = (char*)malloc(20*sizeof(char));
    for(i = 0; i < length; i++){
        if(racers[i].result == 1){
            strcpy(fastest, racers[i].name);
        }
    }
    return fastest;
}




