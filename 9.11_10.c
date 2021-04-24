#include<stdio.h>
void to_base_n(unsigned long num, int n);
int main() {
    unsigned long num;
    int n;
    printf("Please enter two numbers. The first one is base, the second one is exponent.(q to quit)\n");
    while (scanf("%lu %d", &num, &n) == 2) {
        to_base_n(num, n);
        printf("\n");
        printf("Please enter two numbers. The first one is base, the second one is exponent.(q to quit)\n");
    }
    return 0;
}

void to_base_n(unsigned long num, int n) {
    if (num >= n) {
        to_base_n(num / n, n);
    }
    printf("%d", num % n);
}