#include <stdio.h>
#include "C:\Users\Lenovo\Documents\GitHub\C-Summer-School\include\Input.hpp"

int InputProcessing(double* a, double* b, double* c)
{
    int count_of_inputs = 0;
    while (1) {
        printf("Enter coefficients of quadratic equation ax^2 + bx + c = 0: ");
        count_of_inputs = scanf("%lf %lf %lf", a, b, c);
        if (count_of_inputs == 3) {
            ClearBuffer();
            return 1;
        } else if (count_of_inputs == EOF) {
            printf("End of file.\n");
            ClearBuffer();
            return 0;
        } else {
            ClearBuffer();
            printf("Input error. Try again.\n");
        }
    }
}

void ClearBuffer(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
