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
    FILE* file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Error: cannot open file '%s'!\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    unsigned long file_size = ftell(file);
    rewind(file);

    char* buffer = (char*)calloc(file_size + 1, sizeof(char));
    if (buffer == NULL)
    {
        printf("Error: memory allocation failed!");
        fclose(file);
        return NULL;
    }

    size_t read_size = fread(buffer, sizeof(char), file_size, file);
    fclose(file);
    if (read_size != file_size)
    {
        printf("Error: cannot read file content!");
        free(buffer);
        return NULL;
    }

    char* ptr = buffer;
    int n_chars = 0;
    if (sscanf(ptr, "%d%n", n_tests, &n_chars) != 1)
    {
        printf("Error: cannot read number of tests!\n");
        free(buffer);
        return NULL;
    }
    ptr += n_chars;

    struct TestSquareSolver* tests = (struct TestSquareSolver*)calloc(*n_tests, sizeof(struct TestSquareSolver));
    if (tests == NULL)
    {
        printf("Error: memory allocation failed!\n");
        free(buffer);
        return NULL;
    }

    for (int i = 0; i < *n_tests; i++)
    {
        int expected_n_roots = 0;
        if (sscanf(ptr, "%lf %lf %lf %lf %lf %d",
                   &tests[i].a, &tests[i].b, &tests[i].c,
                   &tests[i].x1, &tests[i].x2, &expected_n_roots) != 6)
        {
            printf("Error: cannot read test %d from file!\n", i + 1);
            free(tests);
            free(buffer);
            return NULL;
        }
        tests[i].n_roots = (enum NRoots)expected_n_roots;
    }
    free(buffer);
    return tests;
}
