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
void TestOneSolveSquare(double a, double b, double c, double expected_x1, double expected_x2, int expected_nRoots);
void TestManySolveSquare();
void PrintRoots(enum NRoots roots_count, double x1, double x2);
int InputProcessing(double* a, double* b, double* c);
void ClearBuffer(void);

int main(void)
{

    double a = NAN, b = NAN, c = NAN; // TODO: NAN
    InputProcessing(&a, &b, &c); // TODO: input processing
    printf("a = %lg, b = %lg, c = %lg\n", a, b, c);
    double x1 = NAN, x2 = NAN; // TODO: NAN
    enum NRoots nRoots = SolveSquare (a, b, c, &x1, &x2);

    PrintRoots(nRoots, x1, x2);

    TestManySolveSquare();

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
            else
            {
                return ZERO_ROOTS;
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
        case ZERO_ROOTS:
            printf ("No roots\n");
            break;
        case ONE_ROOT:
            printf ("One root: x = %lg\n", x1);
            break;
        case TWO_ROOTS:
            printf ("Two roots: x1 = %lg, x2 = %lg\n", x1, x2);
            break;
        case INFINITE_ROOTS:
            printf ("Infinite quantity of roots\n");
            break;
        default:
            printf("main(): ERROR: Roots Count = %d\n", roots_count);
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
        else if (inputed_count == EOF)
        {
            printf("End of file.\n");
            ClearBuffer();
            return 0;
        }
        else
        {
            ClearBuffer();
            printf("Input error. Try again.\n");

        }
    }
}

void ClearBuffer (void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}


void TestManySolveSquare (void)
{
    int i = 0;
    double x1 = NAN, x2 = NAN;
    double testInfo[8][6] = {{1, -5, 6, 3, 2, TWO_ROOTS},
                            {0, -2, 8, 4, NAN, ONE_ROOT},
                            {2, 0, -8, 2, -2, TWO_ROOTS},
                            {3, 6, 0, 0, -2, TWO_ROOTS},
                            {1e-8, 0, 0, 0, NAN, ONE_ROOT},
                            {0, 0, 0, NAN, NAN, INFINITE_ROOTS},
                            {2, -4, 2, 1, NAN, ONE_ROOT},
                            {1, 3, 1, NAN, NAN, ZERO_ROOTS}};
    for (i = 0; i < 7; i++)
    {
        double a = testInfo[i][0];
        double b = testInfo[i][1];
        double c = testInfo[i][2];

        enum NRoots expected_nRoots = (enum NRoots)testInfo[i][5];
        double expected_x1 = testInfo[i][3];
        double expected_x2 = testInfo[i][4];

        TestOneSolveSquare(a, b, c, expected_x1, expected_x2, expected_nRoots);

    }
}

void TestOneSolveSquare (double a, double b, double c, double expected_x1, double expected_x2, int expected_nRoots)
{
    double x1 = NAN, x2 = NAN;

    enum NRoots nRoots = SolveSquare(a, b, c, &x1, &x2);

    if (expected_nRoots == nRoots &&
        (IsZero(expected_x1 - x1) || (isnan(x1) && isnan(expected_x1))) &&
        (IsZero(expected_x2 - x2) || (isnan(x2) && isnan(expected_x2))))
    {
        printf("Test is successful!\n");
    }
    else
    {
        printf("Test is failed!\n");
        printf("Expected roots: x1 = %lg, x2 = %lg\n", expected_x1, expected_x2);
        printf("Got roots: x1 = %lg, x2 = %lg\n", x1, x2);
    }
}

