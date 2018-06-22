#include <stdio.h>
#include <stdlib.h>

void token_text(char line[], char *pword, char *ppath, int *number);
void write_file(char *pword, char *ppath, int number);

int main()
{
    char line[100];
    int number = 0;
    char path[30];
    char word[30];
    char *ppath = &path;
    char *pword = &word;
    printf("Enter a filename, a word and a number:\n");
    token_text(gets(line), pword, ppath, &number);
    write_file(pword, ppath, number);
    return 0;
}
void token_text(char line[], char *pword, char *ppath, int *number)
{
    int i;
    char *p;
    for (p = strtok(line, " "); p != NULL; p = strtok(NULL, " "))
    {
        if (atoi(p) > 0 )
        {
            *number = atoi(p);
        }
        if (strchr(p, '.') != NULL)
        {
            strcpy(ppath, p);
        }
        else if (atoi(p) == 0)
        {
            strcpy(pword, p);
        }
    }
}

void write_file(char *pword, char *ppath, int number)
{
    FILE *fp;
    int i;
    fp = fopen(ppath, "w");
    for (i = 0; i < number; i++)
    {
        fputs(pword, fp);
        fputs("\n",fp);
    }
    fclose(fp);
}

