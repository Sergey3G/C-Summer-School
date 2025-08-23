#include <stdio.h>
#include <math.h>
#include <assert.h>
#define EPS 1e-10


enum NRoots
{
    ZERO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INFINITE_ROOTS = -1
};


bool IsZero(double n);
enum NRoots SolveSquare(double a, double b, double c, double* x1, double* x2);
void PrintRoots(enum NRoots roots_count, double x1, double x2);
int InputProcessing(double* a, double* b, double* c);
void ClearBuffer(void);

int main(void)
{

    double a = NAN, b = NAN, c = NAN; // TODO: NAN
    InputProcessing(&a, &b, &c); // TODO: input processing
    printf("a = %lg, b = %lg, c = %lg\n", a, b, c);
    double x1 = 0, x2 = 0;
    enum NRoots nRoots = SolveSquare (a, b, c, &x1, &x2);

    PrintRoots(nRoots, x1, x2);

    return 0;
}

enum NRoots SolveSquare (double a, double b, double c, double* const x1, double* const x2) // TODO: const
{
    assert(!(isnan(a)) && "Error! Coefficient a is not a number!");
    assert(!(isnan(b)) && "Error! Coefficient b is not a number!");
    assert(!(isnan(c)) && "Error! Coefficient c is not a number!"); // TODO: isnan()  NAN != NAN
    double D = (b * b) - (4 * a * c);
    if (IsZero(a))    // TODO: function is_zero(double)
    {
        if (IsZero(b))
        {
            if (IsZero(c))
            {
                return INFINITE_ROOTS; // TODO: enum
            }
        }
        else
        {
            *x1 =  -(c / b);
            return ONE_ROOT;
        }
    }
    else
    {
        if (D > 0)
        {
            *x1 = (-b + sqrt(D)) / (2 * a);
            *x2 = (-b - sqrt(D)) / (2 * a);
            return TWO_ROOTS;
        }
        else if (IsZero(D)) // TODO: compare with zero
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

void PrintRoots (enum NRoots roots_count, double x1, double x2)
{
    switch (roots_count)
    {
        case ZERO_ROOTS: printf ("No roots\n");
                break;
        case ONE_ROOT: printf ("One root: x = %lg\n", x1);
                break;
        case TWO_ROOTS: printf ("Two roots: x1 = %lg, x2 = %lg\n", x1, x2);
                break;
        case INFINITE_ROOTS: printf ("Infinite quantity of roots\n");
                break;
        default: printf("main(): ERROR: Roots Count = %d\n", roots_count);
    }
}

bool IsZero (double n)
{
    if (n < EPS && n > -EPS)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int InputProcessing (double* a, double* b, double* c)
{
    int inputed_count = 0;

    while (true)
    {
        printf("Enter coefficients of quadratic equation ax^2 + bx + c = 0: ");
        inputed_count = scanf("%lg %lg %lg", a, b, c);

        if (inputed_count == 3)
        {
            ClearBuffer();
            return 1;
        }
        else
        {
            printf("Input error. Try again.\n");
            ClearBuffer();
            return 0;
        }
    }
}

void ClearBuffer (void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

/*
int TestSolveSquare (void)
{
    double x1 = 0, x2 = 0;
    int nRoots = SolveSquare(1, -5, 6, &x1, &x2);
    if (!(nRoots == 2 && x1 == 2 && x2 == 3))
    {
        printf("Error: SolveSquare(-1, 5, 6, ...) -> 2, x1 = %lf, x2 = %lf (should be x1 = 2, x2 = 3\n", x1, x2);
    }
}
*/
