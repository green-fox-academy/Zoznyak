#include <stdio.h>
#include <stdlib.h>

int main()
{
    puts("\t   CLI Calculator");
    puts("====================================");
    puts("usage: [number] [operation] [number]");
    puts("Commands:\n");
    puts(" +\t summation");
    puts(" -\t subtraction");
    puts(" *\t multiplication");
    puts(" /\t division");
    puts(" %\t division with reminder");
    puts(" ^\t squaring");
    puts(" log\t logarithm");
    puts(" binto\t binary to hex or dec");
    puts(" hexto\t hexadecimal to bin or dec");
    puts(" decto\t decimal to bin or hey");
    puts("====================================");
    puts(" exit\t exiting from the program");
    puts(" clear\t clear the screen");
    puts(" help\t print usage");
    puts("====================================");
    puts("Hit enter to start!");
    puts("====================================");

    return 0;
}
