#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 33
int bstoi(char *st);
char *itobs(int num, char *bits);
int main(int argc, char **argv) {
    if (argc <= 1) {
        fprintf(stderr, "Lack of command line argument.\n");
        exit(1);
    }
    char bits[MAXLEN];
    int bits1, bits2;
    bits1 = bstoi(argv[1]);
    bits2 = bstoi(argv[2]);
    printf("~:  %s ", itobs(~bits1, bits));
    printf("%s\n", itobs(~bits2, bits));
    printf("&:  %s\n", itobs(bits1 & bits2, bits));
    printf("|:  %s\n", itobs(bits1 | bits2, bits));
    printf("^:  %s\n", itobs(bits1 ^ bits2, bits));

    return 0;
}

int bstoi(char *st) {
    int num = 0;
    int bitval = 1;
    int size = strlen(st);
    int i;
    for (i = size - 1; i >= 0; i--, bitval <<= 1) {
        if (st[i] == '1') {
            num |= bitval;
        }
    }
    return num;
}

char *itobs(int num, char *bits) {
    int size = sizeof(num) * 8;
    int i;
    for (i = size - 1; i >= 0; i--, num >>= 1) {
        bits[i] = (01 & num) + '0';
    }
    bits[size] = '\0';
    return bits;
}