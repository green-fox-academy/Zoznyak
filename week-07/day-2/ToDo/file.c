#include <stdio.h>
#include "file.h"
#include "todo.h"

void read_file()
{
    char textLine[50];
    FILE *fp;
    fp = fopen("help.txt", "r");
    while (fgets(textLine, 80, fp) != NULL)
    {
        printf("%s", textLine);
    }
    fclose(fp);
}

void write_file(char text[], int priority)
{
    char line[50];
    FILE *fp;
    fp = fopen("todos.txt", "a");
    if(fp==NULL) {
        perror("Error opening file.");
    }
    else {
        sprintf(line,"%d",priority);
        strcat(line," ");
        strcat(line,text);
        fprintf(fp, "%s\n", line);
        fclose(fp);
    }
}
