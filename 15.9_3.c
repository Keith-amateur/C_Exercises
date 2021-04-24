#include <stdio.h>
#include <string.h>

int returnOpenNum(int num);

int main() {
    puts("Enter an integer.");
    int num;
    while (scanf("%d", &num) == 1) {
        printf("There are %d bit(s) opened\n", returnOpenNum(num));
        puts("Enter the next num");
    } 
}

int returnOpenNum(int num) {
    int count = 0;
    while (num > 0) {
        if ((num & 01) == 01)
            count++;
        num >>= 1;
    }
    return count;
}