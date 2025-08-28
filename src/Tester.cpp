#include <stdio.h>
#include "C:\Users\Lenovo\Documents\GitHub\C-Summer-School\include\Tester.hpp"
#include "C:\Users\Lenovo\Documents\GitHub\C-Summer-School\include\NRoots.hpp"
#include "C:\Users\Lenovo\Documents\GitHub\C-Summer-School\include\IsZero.hpp"

void TestManySolveSquare(void)
{
    int n_tests = 0;
    struct TestSquareSolver* file_tests = InputTestsFromFile("test_data.txt",
                                                        &n_tests);
    if (file_tests != NULL)
    {
        for (int i = 0; i < n_tests; i++) {
            printf("Test %d from file: ", i + 1);
            TestOneSolveSquare(&file_tests[i]);
        }
        free(file_tests);
    }
}

void TestOneSolveSquare(const struct TestSquareSolver* test_struct)
{
    double x1 = NAN, x2 = NAN;
    enum NRoots n_roots = SolveSquare(test_struct->a, test_struct->b, test_struct->c, &x1, &x2);
    bool success = false;
    if (test_struct->n_roots == n_roots)
    {
        switch (n_roots)
        {
            case ZERO_ROOTS:
            case INFINITE_ROOTS:
                success = true;
                break;
            case ONE_ROOT:
                success = IsZero(test_struct->x1 - x1);
                break;
            case TWO_ROOTS:
                success = (IsZero(test_struct->x1 - x1) && IsZero(test_struct->x2 - x2)) ||
                          (IsZero(test_struct->x1 - x2) && IsZero(test_struct->x2 - x1));
                break;
            default: printf("Error: cannot read fucking count of roots!");
        }
    }
    if (success)
    {
        printf(GREEN "Test is successful!" NORMAL "\n");
    }
    else
    {
        printf(RED "Test is failed!" NORMAL "\n");
        printf("Expected: n_roots = %d, x1 = %lg, x2 = %lg\n",
                test_struct->n_roots, test_struct->x1, test_struct->x2);
        printf("Got: n_roots = %d, x1 = %lg, x2 = %lg\n", n_roots, x1, x2);
    }
}

struct TestSquareSolver* InputTestsFromFile(const char* filename, int* n_tests)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: cannot open file '%s'!\n", filename);
        return NULL;
    }
    if (fscanf(file, "%d", n_tests) != 1)
    {
        printf("Error: cannot read number of tests!\n");
        fclose(file);
        return NULL;
    }
    struct TestSquareSolver* tests = (struct TestSquareSolver*)calloc(*n_tests, sizeof(struct TestSquareSolver));
    if (tests == NULL)
    {
        printf("Error: memory allocation failed!\n");
        fclose(file);
        return NULL;
    }
    for (int i = 0; i < *n_tests; i++)
    {
        int tmp_roots = 0;
        if (fscanf(file, "%lf %lf %lf %lf %lf %d",
                   &tests[i].a, &tests[i].b, &tests[i].c,
                   &tests[i].x1, &tests[i].x2, &tmp_roots) != 6)
        {
            printf("Error: cannot read test %d from file!\n", i + 1);
            free(tests);
            fclose(file);
            return NULL;
        }
        tests[i].n_roots = (enum NRoots)tmp_roots;
    }
    fclose(file);
    return tests;
}
