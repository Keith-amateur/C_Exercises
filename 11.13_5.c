#include<stdio.h>
#define SIZE 80
char *findchr(char *st, char ch);

int main() {
    puts("Please enter sth.");
    char st[SIZE];
    fgets(st, SIZE, stdin);
    char ch;
    while ((ch = getchar()) != '\0') {
        char *strc = findchr(st, ch);
        if (!strc)
            break;
        printf("%c\n", *strc);
    }
    return 0;
}
// 实现strchr()
char *findchr(char *st, char ch) {
    while (*st) {
        if (*st == ch) {
            return st;
        }
        st++;
    }
    return NULL;
}