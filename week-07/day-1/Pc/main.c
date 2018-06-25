#include <stdio.h>
#include <stdlib.h>
#include "pc.h"
#include "notebook.h"

int main()
{
    struct Computer pc1;
    Notebook notebook1;

    pc1.cpu_speed_GHz = 4.33;
    pc1.ram_size = 8;
    pc1.bits = 32;
    notebook1.cpu_size_GHz = 5;
    notebook1.ram_size = 16;
    notebook1.bits = 64;
    printf("PC1 has %.2f GHZ processor with %i GB RAM and %i system.\n", pc1.cpu_speed_GHz, pc1.ram_size, pc1.bits);
    printf("Notebook1 has %.2f GHZ processor with %i GB RAM and %i system.\n", notebook1.cpu_size_GHz, notebook1.ram_size, notebook1.bits);
    return 0;
}
