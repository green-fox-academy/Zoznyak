#ifndef TODO_H_INCLUDED
#define TODO_H_INCLUDED

typedef enum {false, true}bool;

typedef struct{
    char name[100];
    int priority; //1-5
    bool done;
}t_todo;

t_todo todos[20];

void add_new_todo(char name[], char priority[], char state[]);
void add_todos(t_todo task);
void add_todo_to_file(t_todo task);
void read_todos();
void token_todos(char line[], int i);
void sort_todos(int length);
void list_todos();
char checked(bool done);
void remove_task(char index[]);
void write_todo_to_file();
int valid_values(int i);

#endif // TODO_H_INCLUDED
