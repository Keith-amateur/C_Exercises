#include <stdio.h>

int isopened(int num, int pos);
char *itobs(int num, char *st);

int main() {
    int num;
    int pos;
    char bits[33];
    while (scanf("%d", &num) == 1) {
        printf("%s\n", itobs(num, bits));
        scanf("%d", &pos);
        printf(isopened(num, pos) ? "true\n" : "false\n");

    }
    return 0;
}

char *itobs(int num, char *st) {
    int i;
    int size = sizeof(num) * 8;
    for (i = size - 1; i >= 0; i--, num >>= 1) {
        st[i] = (01 & num) + '0';
    }
    st[size] = '\0';
    return st;
}

int isopened(int num, int pos) {
    int res;
    res = (num >> (pos - 1)) & (01);
    return res;
}