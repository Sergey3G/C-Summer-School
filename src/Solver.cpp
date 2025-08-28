#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "C:\Users\Lenovo\Documents\GitHub\C-Summer-School\include\Solver.hpp"

enum NRoots SolveSquare (double a, double b, double c, double* x1, double* x2)
{
    MY_ASSERT(!(isnan(a)), "Error! Coefficient a is not a number!");
    MY_ASSERT(!(isnan(b)), "Error! Coefficient c is not a number!");
    MY_ASSERT(!(isnan(c)), "Error! Coefficient a is not a number!");
    MY_ASSERT(x1 != nullptr, "Error! Coefficient a is not a number!");
    MY_ASSERT(x2 != nullptr, "Error! Coefficient a is not a number!");
    double D = (b * b) - (4 * a * c);
    if (IsZero(a))
    {
        return SolveLinear(b, c, x1);
    }
    else
    {
        if (D > 0)
        {
            *x1 = (-b + sqrt(D)) / (2 * a);
            *x2 = (-b - sqrt(D)) / (2 * a);
            return TWO_ROOTS;
        }
        else if (IsZero(D))
        {
            *x1 = (-b) / (2 * a);
            return ONE_ROOT;
        }
        else
        {
            return ZERO_ROOTS;
        }
    }
}

enum NRoots SolveLinear (double b, double c, double* x1)
{
    if (IsZero(b))
    {
        if (IsZero(c))
        {
            return INFINITE_ROOTS;
        }
        else
        {
            return ZERO_ROOTS;
        }
    }
    else
    {
        *x1 = -(c / b);
        return ONE_ROOT;
    }
}
