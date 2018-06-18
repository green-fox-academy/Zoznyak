#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 3;
    int b = 100;
    int c = 44;
    int d = 125;
    int e = 8;
    int f1 = 123;
    int f2 = 345;
    int g1 = 350;
    int g2 = 200;
    int long h = 1357988018575474;
    int divisor;
    int i1 = 10;
    int i2 = 3;
    int j = 1521;
    char k[] = "Apple";

    printf("%i\n", a + 10);
    printf("%i\n", b - 7);
    printf("%i\n", c * 2);
    printf("%i\n", d / 5);
    printf("%i\n", e * e * e);
    printf("%i\n", d / 5);
    printf("%i\n", f1 > f2);
    g2*=2;
    printf("%i\n", g1 < g2);
    printf("%i\n", h % 11);
    printf("%i\n", i1 > i2 * 0.5 && i1 < i2 * i2 * i2);
    printf("%i\n", j % 3 == 0 || j % 5 == 0);
    printf("%s%s%s ", k, k, k, k);
    return 0;
}
