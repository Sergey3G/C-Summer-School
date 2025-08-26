#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "IsZero.hpp"
#include "NRoots.hpp"
#include "Solver.hpp"
#include "Input.hpp"
#include "Printer.hpp"
#include "Tester.hpp"
#define EPS 1e-10


int main(void)
{
    double a = NAN, b = NAN, c = NAN;
    InputProcessing(&a, &b, &c);
    printf("a = %lg, b = %lg, c = %lg\n", a, b, c);
    double x1 = NAN, x2 = NAN;
    enum NRoots nRoots = SolveSquare(a, b, c, &x1, &x2);
    PrintRoots(nRoots, x1, x2);
    TestManySolveSquare();
    return 0;
}




