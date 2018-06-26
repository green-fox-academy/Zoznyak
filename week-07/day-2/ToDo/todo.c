#include <stdio.h>
#include "file.h"
#include "todo.h"

void add_new_todo(char name[], char priority[])
{
    t_todo new_todo;
    strcpy(new_todo.name, name);
    new_todo.priority = atoi(priority);
    new_todo.done = false;
    add_todos(new_todo);
}

void add_todos(t_todo task)
{
    int i;
    for (i = 0; i < 10; i++){
        if (strlen(todos[i].name) == 0){
            strcpy(todos[i].name, task.name);
            todos[i].priority = task.priority;
            todos[i].done = task.done;
            printf("%s", todos[i].name);
            break;
        }
    }
    write_file(task.name, task.priority, task.done);
}

