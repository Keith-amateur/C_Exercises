#include<stdio.h>
#define H_TO_I 0.3937
int main() {
    float heights;
    printf("Plese enter a height in centimeters:");
    scanf("%f", &heights);
    float Inchs;
    int HinF;
    float HinI;
    while (heights > 0) {
        Inchs = heights * H_TO_I;
        HinF = Inchs / 12;
        HinI = Inchs - HinF * 12;
        printf("%.1f cm = %d feet, %.1f inches\n", heights, HinF, HinI);
        printf("Plese enter a height in centimeters:");
        scanf("%f", &heights);
    }
    printf("Bye");
    return 0;
}