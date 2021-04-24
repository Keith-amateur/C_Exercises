#include <stdio.h>
#include <string.h>
#define MAXLEN 33

int bstoi(char *bits);
int main() {
    char bits[MAXLEN];
    puts("Please enter an integer in binomial");
    scanf("%s", bits);
    int num;
    num = bstoi(bits);
    printf("%d\n", num);
    return 0;
}

int bstoi(char *bits) {
    int num = 0;
    int bitvals = 1;
    int size = strlen(bits);
    int i;
    for (i = size - 1; i >= 0; i--, bitvals <<= 1) {
        if (bits[i] == '1') {
            num |= bitvals;
        }
    }
    return num;
}