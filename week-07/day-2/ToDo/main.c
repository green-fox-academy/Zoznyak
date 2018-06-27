#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "todo.h"

int main(int argc, char *argv[])
{
    read_todos();
    if (argc == 1){
        read_help();
    }
    if( argc == 2 ) {
        if (strcmp(argv[1], "-h") == 0){
            read_help();
        }
    }

    if( argc == 2 ) {
        if (strcmp(argv[1], "-l") == 0){
            list_todos();
        }
    }
   if( argc == 4 ) {
        if (strcmp(argv[1], "-a") == 0){
            add_new_todo(argv[2], argv[3]);
        }
        if (strcmp(argv[1], "-l") == 0){
            printf("%s", "First argument is -l");
        }
        if (strcmp(argv[1], "-r") == 0){
            printf("%s", "First argument is -r");
        }
        if (strcmp(argv[1], "-c") == 0){
            printf("%s", "First argument is -c");
        }
   }
   else if( argc > 4 ) {
        printf("Too many arguments supplied.\n");
   }
   else {
        //read_file();
   }
    return 0;
}
