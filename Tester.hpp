#ifndef TESTER_H
#define TESTER_H

#include <stdio.h>
#include "NRoots.hpp"
#include <stdlib.h>
#include <math.h>
#include "Solver.hpp"

struct TestSquareSolver
{
    double a;
    double b;
    double c;
    double x1;
    double x2;
    enum NRoots n_roots;
};

void TestOneSolveSquare(const struct TestSquareSolver* test_struct);
void TestManySolveSquare();
struct TestSquareSolver* InputTestsFromFile(const char* filename, int* n_tests);

#endif
