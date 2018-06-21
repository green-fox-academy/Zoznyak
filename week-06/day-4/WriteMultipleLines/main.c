#include <stdio.h>
#include <stdlib.h>

int main()
{
    char line[100];
    int number;
    char path[30];
    char word[30];
    printf("Enter a filename, a word and a number:\n");
    gets(line);
    //printf("%d", strlen(line));
    int i;
    char *p;
    for (p = strtok(line, " "); p != NULL; p = strtok(NULL, " "))
    {
        if (atoi(p) > 0 )
        {
            number = atoi(p);
            printf("Number: %d\n", number);
        }
        if (strchr(p, '.') != NULL)
        {
            strcpy(path, p);
            printf("Path: %s\n", path);
        }
        else if (atoi(p) == 0)
        {
            strcpy(word, p);
            printf("Word: %s\n", word);
        }
    }
/*
    printf("%s\n", first);
    printf("%s\n", second);
    printf("%s\n", third);
*/
    return 0;
}

