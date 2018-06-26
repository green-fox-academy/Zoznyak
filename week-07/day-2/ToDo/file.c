#include <stdio.h>
#include "file.h"
#include "todo.h"

void read_help()
{
    char textLine[50];
    FILE *fp;
    fp = fopen("help.txt", "r");
    while (fgets(textLine, 80, fp) != NULL){
            printf("%s", textLine);
    }
    fclose(fp);
}

