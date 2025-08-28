#include <stdio.h>
#include "C:\Users\Lenovo\Documents\GitHub\C-Summer-School\include\IsZero.hpp"
#include <math.h>

#define EPS 1e-10

bool IsZero(double n)
{
    return fabs(n) < EPS;
}

