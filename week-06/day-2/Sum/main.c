#include <stdio.h>
#include <stdlib.h>

int Sum(int number);

int main()
{
    int number;
    printf("Enter a number:\n");
    scanf("%i", &number);
    printf("Sum until %i reached: %i\n", number, Sum(number));
    return 0;
}

int Sum(int number)
{
    int i;
    int sum = 0;
    for (i = 0; i <= number; i++)
    {
        sum+=i;
    }
    return sum;
}
