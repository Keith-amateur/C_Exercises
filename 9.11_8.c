#include<stdio.h>

double power(double a, int n);

int main() {
    int exponent;
    double base;
    printf("Please enter two numbers. The first one is base, the second one is exponent.\n");
    while (scanf("%lf %d", &base, &exponent) != 2) {
        printf("Please enter the numbers, such as 1.2, 3\n");
        scanf("%*s");
    }
    printf("%f", power(base, exponent));
    return 0;
}

double power(double a, int n) {
    double res = 1;
    int i;
    if (n > 0) {
        for (i = 0; i < n; i++) {
            res *= a;
        }
    } else if (n < 0) {
        for (i = 0; i < -n; i++) {
            res *= 1 / a;
        }
    } else {
        if (a == 0) {
            printf("0^0: undefined\n");
        }
    }

    return res;
}