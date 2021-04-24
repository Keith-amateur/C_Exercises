#include <stdio.h>
#include "16.18_1.h"
#define CALC_AVG(X, Y) 1 / (((1/(X)) + (1/(Y))) / 2)

int main() {
    double x = 1;
    double y = 1;
    double res;
    res = CALC_AVG(x + 1, y);
    printf("The reconciliciing average is %f\n", res);
    BYE;
    return 0;
}