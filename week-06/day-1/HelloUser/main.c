#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age;
    char name[100];
    printf("Enter your name: \n");
    scanf("%s", &name);
    printf("Enter your age: \n");
    scanf("%i", &age);
    printf("Hello %i years old %s!\n", age, name);
    return 0;
}
