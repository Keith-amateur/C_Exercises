#include<stdio.h>
void larger_of(double * x, double * y);
int main() {
    double origin_m, origin_n;
    double m, n;
    printf("Please enter two numbers: ");
    while (scanf("%lf %lf", &m, &n) != 2) {
        printf("Please enter the number such as 3, 1.2: ");
        scanf("%*s");
    }
    origin_m = m;
    origin_n = n;
    larger_of(&m, &n);
    printf("The entered numbers are %.2f and %.2f. Now they become %.2f and %.2f", origin_m, origin_n, m, n);
    return 0;
}

void larger_of(double * m, double * n) {
    if (*m > *n) {
        *n = *m;
    } else {
        *m = *n;
    }
}