#include <stdio.h>
#include <stdlib.h>

int number_of_lines(char file[]);

int main()
{
    char myfile[20];
    printf("Please enter a filename:\n");
    scanf("%s",&myfile);
    printf("The number of the lines in your file: %i\n", number_of_lines(myfile));
    return 0;
}

int number_of_lines(char file[])
{
    char path[20];
    char line[30];
    int counter = 0;
    strcpy(path,file);
    strcat(path, ".txt");
    FILE *fp;
    fp = fopen(path, "r");
    if (fp == NULL)
    {
        printf("File does not exist!");
        exit(-1);
    }
    while (!feof(fp))
    {
        fgets(line, 30, fp);
        counter += 1;
    }
    fclose(fp);
    return counter;
}
