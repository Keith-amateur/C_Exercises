#include<stdio.h>
#include<ctype.h>
#define MAXLEN 20

char *getAword(char *st, int n);

int main() {
    char input_str[80];
    char *word;
    word = getAword(input_str, MAXLEN);
    puts(word);
    return 0;
}

char *getAword(char *st, int n) {
    puts("Please enter something");
    fgets(st, 4*n, stdin);
    int i = 0;
    for (i = 0; i < 4 * n; i++) {
        if (toupper(st[i]) >= 65 && toupper(st[i]) <= 90) {
            st = &st[i];
            break;
        }
    }
    int j = 0;
    while (st[j] != '\0') {
        if (j >= n || (toupper(st[j]) < 65 || toupper(st[j]) > 90)) {
            st[j] = '\0';
        }
        j++;
    }
    return st;
}