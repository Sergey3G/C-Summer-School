#include <stdio.h>
#include <math.h>


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
    scanf ("%lg %lg %lg", &a, &b, &c);

    double x1 = 0, x2 = 0;
    enum NRoots nRoots = SolveSquare (a, b, c, &x1, &x2);

    PrintRoots(nRoots, x1, x2);

    return 0;
}

enum NRoots SolveSquare (double a, double b, double c, double* x1, double* x2)
{
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
        else if (D == 0)
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
    }
}

bool IsZero (double n)
{
    const double eps = 1e-7;

    if (n < eps && n > -eps)
    {
        return true;
    }
    else
    {
        return false;
    }
}
