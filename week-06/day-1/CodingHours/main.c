#include <stdio.h>
#include <stdlib.h>

int main()
{
    float workDaysWeekly = 5.00f;
    int weekNumbers = 17;
    float dailyCodingHours = 6.00f;
    int avarageWorkingHoursWeekly = 52;
    int spentHoursWithCoding;
    int percentageOfCoding;

    spentHoursWithCoding = workDaysWeekly * dailyCodingHours * weekNumbers;
    percentageOfCoding = ((dailyCodingHours * workDaysWeekly * weekNumbers)/(avarageWorkingHoursWeekly*weekNumbers))*100;

    printf("Spent hours with coding in a semester: %i\n", spentHoursWithCoding);
    printf("Percentage of the coding hours in the semester: %i\n", percentageOfCoding);
    return 0;
}
