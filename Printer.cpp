#include <stdio.h>
#include "Printer.hpp"
#include "NRoots.hpp"

void PrintRoots(enum NRoots n_roots, double x1, double x2)
{
    switch (n_roots) {
        case ZERO_ROOTS:
            printf("No roots\n");
            break;
        case ONE_ROOT:
            printf("One root: x = %lg\n", x1);
            break;
        case TWO_ROOTS:
            printf("Two roots: x1 = %lg, x2 = %lg\n", x1, x2);
            break;
        case INFINITE_ROOTS:
            printf("Infinite quantity of roots\n");
            break;
        default:
            printf("main(): ERROR: Roots Count = %d\n", n_roots);
    }
}
