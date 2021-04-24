#include<stdio.h>
int isPrime(int n);
int main() {
    int num;
    printf("Enter a positve integer:\n");
    scanf("%d", &num);
    int i;
    for (i = 2; i <= num; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    if (i == 2) {
        printf("The number inputed is 1");
    }
    return 0;
}
int isPrime(int n) {
    int isprime = 1;
    int i;
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            isprime = 0;
        }
    }
    return isprime;
}