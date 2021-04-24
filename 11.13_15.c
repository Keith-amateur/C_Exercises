#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define SIZE 20

char *s_gets(char *st, int n);
int atoi(char *st);

int main() {
    char str[SIZE];
    if (s_gets(str, SIZE)) {
        printf("%d\n", atoi(str));
    }
    return 0;
}
int atoi(char *st) {
    int num = 0;
    int i = 0;
    while (st[i] != '\0') {
        if (!isdigit(st[i]))
            return 0;
        int j;
        int digit = 1;
        int show = strlen(&st[i]) - 1;
        for (j = 0; j < show; j++) {
            digit *= 10;
        }
        num += digit * (st[i] - '0');
        i++;
    }
    return num;
}
char *s_gets(char *st, int n) {
    char *ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        while (st[i] != '\n' && st[i] != '\0') {
            i++;
        }
        if (st[i] == '\n') {
            st[i] = '\0';
        } else {
            while (getchar() != '\n') {
                continue;
            }
        }
    }
    return ret_val;
}