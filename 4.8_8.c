#include<stdio.h>
#define GALLON_LITER 3.785
#define MILE_KM 1.609
int main() {
    double mile;
    double oil;
    printf("Please enter miles and oil:\n");
    scanf("%lf %lf", &mile, &oil);
    printf("%f mile/gallon\n", mile / oil);
    printf("%f liter/km", (oil * GALLON_LITER) / (mile * MILE_KM));
    return 0;
}