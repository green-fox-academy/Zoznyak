#ifndef TODO_H_INCLUDED
#define TODO_H_INCLUDED

typedef enum {false, true}bool;

typedef struct{
    char name[100];
    int priority; //1-5
    bool done;
}t_todo;

t_todo todos[10];

void add_new_todo(char name[], char priority[]);
void add_todos(t_todo task);
void write_todo(t_todo task);
void read_todos();
void token_todos(char line[], int i);
void list_todos();
char checked(bool done);

#endif // TODO_H_INCLUDED
