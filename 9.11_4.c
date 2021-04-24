#include<stdio.h>
double Harmonic_mean(double a, double b);
int main() {
    double m, n;
    printf("Please enter two numbers: ");
    while (scanf("%lf %lf", &m, &n) != 2) {
        printf("Please enter the number such as 3, 1.2: ");
        scanf("%*s");
    }
    printf("The entered numbers are %.2f and %.2f. Their harmonic mean is %.2f", m, n, Harmonic_mean(m, n));
    return 0;
}

double Harmonic_mean(double a, double b) {
    return (1 / a + 1 / b) / 2;
}