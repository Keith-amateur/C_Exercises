#include<stdio.h>

int main() {
    int num = 0;
    while (getchar() != EOF) {
        num += 1;
    }
    printf("%d", num);
    return 0;
}