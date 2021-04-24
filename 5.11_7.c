#include<stdio.h>
double cube(double n);
int main() {
    double n;
    printf("Please enter a float number\n");
    scanf("%lf", &n);
    printf("%f", cube(n));
    return 0;
}

double cube(double n) {
    double res;
    res = n * n * n;
    return res;
}