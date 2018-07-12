#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int read_file();
int count_vowels(char textline[], int length);

int main()
{
    printf("Number of vowels: %d\n", read_file());
    return 0;
}

int read_file()
{
    char textLine[100];
    FILE *fp;
    int vowels = 0;
    fp = fopen("text.txt", "r");
    while (fgets(textLine, 80, fp) != NULL){
            vowels += count_vowels(textLine, strlen(textLine));
    }
    return vowels;
    fclose(fp);
}

int count_vowels(char textline[], int length)
{
    int i;
    int j;
    int counter = 0;
    char vowels [] = {'a', 'e', 'i', 'o', 'u'};
    for (i = 0; i < length; i++){
        for(j = 0; j < 5; j++){
            if(textline[i] == vowels[j]){
                 counter++;
            }
        }
    }
    return counter;
}



