#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "todo.h"

void clear_screen();
void reload();
void reset_array(t_todo todos[], int length);

int main(int argc, char *argv[])
{
    int length = sizeof(todos)/sizeof(todos[0]);
    reset_array(todos,length);
    read_todos();
    sort_todos(20);
    if (argc == 1){
        clear_screen();
        read_help();
    }
    if( argc == 2 ) {
        if (strcmp(argv[1], "-h") == 0){
            clear_screen();
            read_help();
        }
        if (strcmp(argv[1], "-l") == 0){
            clear_screen();
            list_todos();
        }
        else{
            printf("Not valid arguments!\n");
        }
    }
    if( argc == 3 ) {
        if (strcmp(argv[1], "-r") == 0){
            remove_task(argv[2]);
            reload();
        }
        if (strcmp(argv[1], "-c") == 0){
            check_task(argv[2]);
            reload();
        }
   }
   if( argc == 5 ) {
        if (strcmp(argv[1], "-a") == 0){
            add_new_todo(argv[2], argv[3], argv[4]);
            sort_todos(20);
            write_todo_to_file();
            clear_screen();
            list_todos();
            //reload();
        }
        if (strcmp(argv[1], "-r") == 0){
            printf("%s", "First argument is -r");
        }
        if (strcmp(argv[1], "-c") == 0){
            printf("%s", "First argument is -c");
        }
   }
   else if( argc > 5 ) {
        printf("Too many arguments supplied.\n");
   }
   else {
        //read_file();
   }
    return 0;
}

void clear_screen()
{
    system("@cls||clear");
}

void reload()
{
    sort_todos(20);
    write_todo_to_file();
    clear_screen();
    list_todos();
}

void reset_array(t_todo todos[], int length)
{
    int i;
    for (i = 0; i < length; i++){
        todos[i].priority = 0;
    }
}
