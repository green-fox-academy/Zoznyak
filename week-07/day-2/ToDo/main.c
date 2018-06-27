#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "todo.h"

void clear_screen();

int main(int argc, char *argv[])
{
    read_todos();
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
   if( argc == 5 ) {
        if (strcmp(argv[1], "-a") == 0){
            add_new_todo(argv[2], argv[3], argv[4]);
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
