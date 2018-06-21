#include <stdio.h>
#include <stdlib.h>

void token_text(char line[], char *pword, char *ppath, int *number);

int main()
{
    char line[100];
    int number;
    char path[30];
    char word[30];
    int *pnumber = &number;
    char *ppath = &path;
    char *pword = &word;
    printf("Enter a filename, a word and a number:\n");
    token_text(gets(line), pword, ppath, pnumber);

    return 0;
}
void token_text(char line[], char *pword, char *ppath, int *pnumber)
{
    int i;
    char *p;
    for (p = strtok(line, " "); p != NULL; p = strtok(NULL, " "))
    {
        if (atoi(p) > 0 )
        {
            pnumber = atoi(p);
            printf("Number: %d\n", pnumber);
        }
        if (strchr(p, '.') != NULL)
        {
            strcpy(ppath, p);
            printf("Path: %s\n", ppath);
        }
        else if (atoi(p) == 0)
        {
            strcpy(pword, p);
            printf("Word: %s\n", pword);
        }
    }
}

