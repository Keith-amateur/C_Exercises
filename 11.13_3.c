#include<stdio.h>
#include<ctype.h>

#define LEN 20
char *getAword(char *st);

int main() {
    char st[LEN];
    char *str;
    str = getAword(st); // scanf("%s", st);
    puts(str);

    return 0;
}

char *getAword(char *st) {
    puts("Please enter something");
    fgets(st, LEN, stdin);
    int i = 0;
    for (i = 0; i < LEN; i++) {
        if (toupper(st[i]) >= 65 && toupper(st[i]) <= 90) {
            st = &(st[i]);
            break;
        }
    }
    int j = 0;
    while (st[j] != '\0') {
        if (toupper(st[j]) < 65 || toupper(st[j]) > 90) {
            st[j] = '\0';
            break;
        }
        j++;
    }
    return st;
}
