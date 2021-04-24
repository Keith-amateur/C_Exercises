#include<stdio.h>

int main() {
    int n;
    int lim;
    printf("Please enter an integer.\n");
    scanf("%d", &n);
    lim = n + 10;
    while (n <= lim) {
        printf("%d\t", n);
        n++;
    }
    return 0;
}