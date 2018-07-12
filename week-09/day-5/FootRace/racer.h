#ifndef RACER_H_INCLUDED
#define RACER_H_INCLUDED

enum country{
    HUN,
    GER,
    ENG
};

typedef struct{
    char name[30];
    enum country;
    int result;
}racer;

#endif // RACER_H_INCLUDED
