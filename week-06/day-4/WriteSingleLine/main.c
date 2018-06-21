#include <stdio.h>
#include <stdlib.h>

void write_name(char name[]);

int main()
{
    char name[20];
    printf("Enter your name:\n");
    scanf("%s", &name);
    write_name(name);
    printf("Your name has been copied into my-file.txt!\n");
    return 0;
}

void write_name(char name[])
{
    FILE *fp;
    fp = fopen("my-file.txt", "w");
    fputs(name, fp);
    fclose(fp);
}
