#ifndef SOLVER_H
#define SOLVER_H

#include <stdio.h>
#include "NRoots.hpp"
#include "IsZero.hpp"

enum NRoots SolveSquare(double a, double b, double c, double* x1, double* x2);
enum NRoots SolveLinear(double b, double c, double* x1);

#endif


