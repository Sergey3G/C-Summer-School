#include <stdio.h>
#include "IsZero.hpp"
#include <math.h>

#define EPS 1e-10

bool IsZero(double n)
{
    return fabs(n) < EPS;
}

