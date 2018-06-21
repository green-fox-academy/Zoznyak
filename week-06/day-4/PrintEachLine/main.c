#include <stdio.h>
#include <stdlib.h>

void write_file();
void read_file();

int main()
{
    write_file();
    printf("My-text.txt has been created!\n");
    read_file();
    return 0;
}

void write_file()
{
    char *animals[] = {"cat", "dog", "tiger", "bird", "fish"};
    int length = sizeof(animals)/sizeof(char *);
    FILE *fp;
    fp = fopen("my-text.txt", "w");
    int i;
    for (i = 0; i < length; i++)
    {
        //fprintf(fp, "%s\n", animals[i]);
        fputs(animals[i], fp);
        /*if (i != length)
        {
            fprintf(fp, "\n");
        }*/
    }
    fclose(fp);
}

void read_file()
{
    char textLine[50];
    FILE *fp;
    fp = fopen("my-text.txt", "r");
    while (!feof(fp))
    {
        fgets(textLine, 80, fp);
        printf("%s", textLine);
    }
    fclose(fp);
}
