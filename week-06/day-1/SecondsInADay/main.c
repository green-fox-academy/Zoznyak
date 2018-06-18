#include <stdio.h>
#include <stdlib.h>

int main()
{
    int currentHours = 23;
    int currentMinutes = 59;
    int currentSeconds = 40;
    int aDayInSecond = 86400;
    int remainingSeconds;

    remainingSeconds = aDayInSecond - (currentHours * 60 * 60) - (currentMinutes * 60) - currentSeconds;
    printf("Remaining secods from the day: %i\n", remainingSeconds);
    return 0;
}
