#include <stdio.h>
#include "file.h"

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

void write_file(char text[])
{
    FILE *fp;
    fp = fopen("todos.txt", "a");
    if(fp==NULL) {
        perror("Error opening file.");
    }
    else {
        fprintf(fp, "%s\n", text);
        fclose(fp);
    }
}
