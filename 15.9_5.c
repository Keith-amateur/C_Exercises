#include <stdio.h>
#include <limits.h>
#define MAXLEN 33
unsigned int rotate_l(unsigned int x, int y);
char *itobs(int x, char *st);
int main() {
    unsigned int x, new_x;
    int y;
    char bits[MAXLEN];
    while (scanf("%u", &x) == 1) {
        puts("rotating number:");
        scanf("%d", &y);
        printf("%s\n", itobs(x, bits));
        new_x = rotate_l(x, y);
        printf("After rotating: %s\n", itobs(new_x, bits));
    }

    return 0;
}

unsigned int rotate_l(unsigned int x, int y) {
    unsigned int new_x;
    int bit_num = CHAR_BIT * sizeof(x);
    unsigned int mask;
    mask = x;
    mask >>= (bit_num - y);
    new_x = (x << y);
    new_x |= mask;
    return new_x;
}

char *itobs(int x, char *st) {
    int size = CHAR_BIT * sizeof(x);
    int i;
    for (i = size - 1; i >= 0; i--, x >>= 1) {
        st[i] = (01 & x) + '0';
    }
    st[size] = '\0';
    return st;
}