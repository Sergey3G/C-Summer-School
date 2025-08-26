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


int main(void) // TODO: argc argv "--test"
{
    double a = NAN, b = NAN, c = NAN;
    InputProcessing(&a, &b, &c);
    double x1 = NAN, x2 = NAN;
    enum NRoots nRoots = SolveSquare(a, b, c, &x1, &x2);
    PrintRoots(nRoots, x1, x2);
    TestManySolveSquare();
    return 0;
}




