#include<stdio.h>

int main() {
    int days;
    printf("How many days: \n");
    scanf("%d", &days);
    int n = 0;
    int sum = 0;
    while (n++ < days) {
        sum = sum + n * n;
    }
    printf("%d", sum);
    return 0;
}