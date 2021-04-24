#include<stdio.h>
double min(double x, double y);
int main() {
    printf("Please enter two number:\n");
    double a, b;
    while (scanf("%lf %lf", &a, &b) != 2) {
        printf("Please enter the number, such as 3, 1.2\n");
        scanf("%*s");
    }
    printf("The entered numbers are %.2f and %.2f, the smaller one is %.2f.\n", a, b, min(a, b));
}

double min(double x, double y) {
    return x < y ? x : y;
}