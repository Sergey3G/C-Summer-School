#include <stdio.h>
#include "Printer.hpp"
#include "NRoots.hpp"


void PrintRoots(enum NRoots n_roots, double x1, double x2)
{
    switch (n_roots) {
        case ZERO_ROOTS:
            printf(YELLOW "No roots" NORMAL "\n");
            break;
        case ONE_ROOT:
            printf(YELLOW "One root: x = %lg" NORMAL "\n", x1);
            break;
        case TWO_ROOTS:
            printf(YELLOW "Two roots: x1 = %lg, x2 = %lg" NORMAL "\n", x1, x2);
            break;
        case INFINITE_ROOTS:
            printf(YELLOW "Infinite quantity of roots" NORMAL "\n");
            break;
        default:
            printf(RED "main(): ERROR: Roots Count = %d" NORMAL "\n", n_roots);
    }
}
