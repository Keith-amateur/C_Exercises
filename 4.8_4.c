#include<stdio.h>

int main() {
    float height;
    printf("Please enter your height(cm):\n");
    scanf("%f", &height);
    printf("You are %.2f meter tall", height / 100);
    return 0;
}