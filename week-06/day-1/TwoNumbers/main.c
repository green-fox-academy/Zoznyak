#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1 = 22;
    int num2 = 13;
    int resultSubstraction;
    int resultAddition;
    int resultMultiplication;
    int resultDivision;
    int resultModulus;

    resultAddition = num1 + num2;
    resultSubstraction = num1 - num2;
    resultMultiplication = num1 * num2;
    resultDivision = num1 / num2;
    resultModulus = num1 % num2;

    printf("%i + %i = %i\n", num1, num2, resultAddition);
    printf("%i - %i = %i\n", num1, num2, resultSubstraction);
    printf("%i * %i = %i\n", num1, num2, resultMultiplication);
    printf("%i / %i = %i\n", num1, num2, resultDivision);
    printf("%i %% %i = %i\n", num1, num2, resultModulus);
    return 0;
}

