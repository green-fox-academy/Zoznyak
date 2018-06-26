#ifndef TODO_H_INCLUDED
#define TODO_H_INCLUDED

typedef enum {false, true}bool;

typedef struct{
    char name[100];
    int priority; //1-5
    bool done;
}t_todo;


#endif // TODO_H_INCLUDED
