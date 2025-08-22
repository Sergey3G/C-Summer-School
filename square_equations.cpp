#include <stdio.h>
#include <math.h>
#include <assert.h>
#define EPS 1e-7


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

int main(void)
{
    printf ("# Enter a, b, c: ");

    double a = NAN, b = NAN, c = NAN; // TODO: NAN
    scanf ("%lg %lg %lg", &a, &b, &c); // TODO: input processing

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
        case ONE_ROOT: printf ("One root: %f\n", x1);
                break;
        case TWO_ROOTS: printf ("Two roots: %f, %f\n", x1, x2);
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

/* void InputProcessing (double* a, double* b, double* c)
{

} */
