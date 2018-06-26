#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "todo.h"

t_todo todos[10];

int main(int argc, char *argv[])
{
    //printf("Program name %s\n", argv[0]);
    if (argc == 1){
        read_file();
    }
    if( argc == 2 ) {
        if (strcmp(argv[1], "-h") == 0){
            read_file();
        }
    }
    if( argc == 2 ) {
        if (strcmp(argv[1], "-l") == 0){
            printf("-l mukodik");
            printf("%s",todos[0].name);
        }
    }
   if( argc == 4 ) {
        if (strcmp(argv[1], "-a") == 0){
            add_new_todo(argv[2], argv[3]);
            //write_file(argv[2]);
            //printf("%s", "First argument is -a");
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
