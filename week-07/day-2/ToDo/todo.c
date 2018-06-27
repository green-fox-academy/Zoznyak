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
    write_todo(task);
}

void write_todo(t_todo task)
{
    char line[50];
    FILE *fp;
    fp = fopen("todos.txt", "a");
    if(fp == NULL) {
        perror("Error opening file.");
    }
    else {
        sprintf(line,"%d""|""%d""|",task.priority,task.done);
        strcat(line," ");
        strcat(line,task.name);
        fprintf(fp, "%s\n", line);
        fclose(fp);
    }
}

void token_todos(char line[], int i)
{
    char *p;
    int counter = 0;
    for (p = strtok(line, "|"); p != NULL; p = strtok(NULL, "|"))
    {
        counter++;
        if ((atoi(p) > 0) && (counter == 1))
        {
            todos[i].priority = atoi(p);
        }

        if ((atoi(p) == 1) && (counter == 2))
        {
            todos[i].done = true;

        }
    }
}

void read_todos()
{
    char textLine[50];
    int i = 0;
    FILE *fp;
    fp = fopen("todos.txt", "r");
    while (fgets(textLine, 80, fp) != NULL){
        token_todos(textLine, i);
        i++;
    }
    fclose(fp);
}

void list_todos()
{
    int i;
    int j;
    for (i = 3; i > 0; i--){
        for (j = 0; j < 10; j++){
            if (todos[j].priority == i){
               printf("%d\n",todos[j].priority);
            }
        }
    }
}

