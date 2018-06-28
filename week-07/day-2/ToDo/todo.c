#include <stdio.h>
#include "file.h"
#include "todo.h"
#include <windows.h>

void add_new_todo(char name[], char priority[], char state[])
{
    if (atoi(priority) > 0 && atoi(priority) < 4){
        t_todo new_todo;
        strcpy(new_todo.name, name);
        new_todo.priority = atoi(priority);
        if (atoi(state) == 1){
            new_todo.done = true;
            add_todos(new_todo);
        }
        if (atoi(state) == 0){
            new_todo.done = false;
            add_todos(new_todo);
        }
        else if (atoi(state) < 0 || atoi(state) > 1) {
            printf("State must be either 1 or 0");
        }
    }
    else{
        printf("Use priority 1-3!");
    }
}

void add_todos(t_todo task)
{
    int i;
    for (i = 0; i < 20; i++){
        if(valid_values(i) != 1){
            strcpy(todos[i].name, task.name);
            todos[i].priority = task.priority;
            todos[i].done = task.done;
            printf("You have added task: \"%s\", with priority: %i, and state: %i\n", todos[i].name, todos[i].priority, todos[i].done);
            break;
        }
    }
}

void token_todos(char line[], int i)
{
    char *p;
    int counter = 0;
    int length;
    for (p = strtok(line, "|"); p != NULL; p = strtok(NULL, "|"))
    {
        counter++;
        if ((atoi(p) > 0) && (counter == 1)){
            todos[i].priority = atoi(p);
        }
        if ((atoi(p) == 1) && (counter == 2)){
            todos[i].done = true;
        }
        else if (atoi(p) == 0){
            strcpy(todos[i].name, p);
            length = strlen(todos[i].name);
            if(todos[i].name[length-1] == '\n'){
                todos[i].name[length-1] ='\0';
            }
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

void sort_todos(int length)
{
    t_todo temp_todos[20];
    int i;
    int j;
    int number = 0;
    for (i = 3; i > 0; i--){
        for (j = 0; j < 20; j++){
            if(valid_values(j) == 1){
                if (todos[j].priority == i){
                    temp_todos[number] = todos[j];
                    number++;
                }
            }
        }
    }
    for (i = 0; i < 20; i++){
        todos[i] = temp_todos[i];
    }
}

void list_todos()
{
    printf("\n");
    printf("\t\tCommand Line Todo application\n");
    printf("\t\t=============================\n");
    printf("\n");
    printf("#   Status\t\tTask\t\t\tPriority\n");
    printf("\n");
    int i;
    int y_coord = 6;
    for (i = 0; i < 20; i++){
        if(valid_values(i) == 1){
            printf("%d",i + 1);
            set_cursor_pos(2, y_coord);
            printf(" - [%c]\t %s",checked(todos[i].done),todos[i].name);
            set_cursor_pos(51, y_coord);
            printf("%d\n",todos[i].priority);
            y_coord++;
        }
    }
    printf("\n");
}

char checked(bool done)
{
    if (done == true){
        return 'X';
    }
    else{
        return ' ';
    }
}

void remove_task(char index[])
{
    int i;
    int number = 0;
    t_todo temp_todos[20];
    todos[atoi(index)-1].priority = 0;
    for (i = 0; i < 20; i++){
        if(valid_values(i) == 1){      //==1!!!!!
            temp_todos[number] = todos[i];
            number++;
        }
    }
    for (i = 0; i < 20; i++){
        todos[i] = temp_todos[i];
    }
}

void write_todo_to_file()
{
    int i;
    char line[50];
    FILE *fp;
    fp = fopen("todos.txt", "w");
    if(fp == NULL) {
        perror("Error opening file.");
    }
    else {
        for (i = 0; i < 20; i++){
            if(valid_values(i) == 1){
                sprintf(line,"%d""|""%d""|",todos[i].priority,todos[i].done);
                strcat(line,todos[i].name);
                fprintf(fp, "%s\n", line);
            }
        }
    fclose(fp);
    }
}

int valid_values(int i)
{
    if((todos[i].priority == 1 || todos[i].priority == 2 || todos[i].priority == 3) && (todos[i].done == false || todos[i].done == true)){
        return 1;
    }
    else 0;
}

void check_task(char index[])
{
    todos[atoi(index)-1].done = true;
}

void set_cursor_pos(int x, int y)
{
    COORD coord = {0,0};
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

