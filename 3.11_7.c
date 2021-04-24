#include<stdio.h>
#define INCH_TO_CM 2.54
int main() {
    float height_inch;
    scanf("%f", &height_inch);
    float height_cm;
    height_cm = height_inch * INCH_TO_CM;
    printf("%f", height_cm);
    return 0;
}