#include<stdio.h>
int fibonacci(int n);
int main() {
    int n;
    printf("Please enter the a number which indicates the nth term in Fibonacci.\n");
    while (scanf("%d", &n) == 1) {
        printf("%d", fibonacci(n));
        printf("\n");
        printf("Please enter the a number which indicates the nth term in Fibonacci.(q to quit)\n");
    }

    return 0;
}

int fibonacci(int n) {
    if (n <= 2) {
        return 1;
    } else {
        int i;
        int temp;
        int f_1 = 1, f_2 = 1;
        for (i = 0; i < n - 2; i++) {
            temp = f_2;
            f_2 = f_1 + f_2;
            f_1 = temp;
        }
        return f_2;
    }

}