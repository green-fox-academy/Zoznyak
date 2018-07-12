#ifndef RACER_H_INCLUDED
#define RACER_H_INCLUDED

typedef enum{
    HUN,
    GER,
    FRA,
    ENG
}nationality;

typedef struct{
    char name[20];
    nationality country;
    int result;
}racer;

#endif // RACER_H_INCLUDED
