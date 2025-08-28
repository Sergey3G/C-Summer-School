#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "NRoots.hpp"
#include "Solver.hpp"
#include "Input.hpp"
#include "Printer.hpp"
#include "Tester.hpp" // TODO: __LINE__ __FUNCTION__ __FILE__


int main(const int argc, char* const argv[])
{
    if (argc > 1)
    {
        printf("argc = %d\nargv[1] = %s\n", argc, argv[1]);

        if (strncmp(argv[1], "--solve", 7) == 0)
        {
            double a = NAN, b = NAN, c = NAN;
            InputProcessing(&a, &b, &c);
            double x1 = NAN, x2 = NAN;
            enum NRoots nRoots = SolveSquare(a, b, c, &x1, &x2);
            PrintRoots(nRoots, x1, x2);
        }
        else if (strncmp(argv[1], "--test", 6) == 0)
        {
            TestManySolveSquare();
        }
    }
    return 0;
}




