#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int main(int argc, char *argv[])
{
    printf("Program name %s\n", argv[0]);

   if( argc == 2 ) {
        printf("The argument supplied is %s\n", argv[1]);
   }
   else if( argc > 2 ) {
        printf("Too many arguments supplied.\n");
   }
   else {
        read_file();
        printf("One argument expected.\n");

   }
    return 0;
}
