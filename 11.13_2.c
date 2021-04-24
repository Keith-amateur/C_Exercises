#include<stdio.h>
#define SIZE 80
char st[SIZE];

char *get_all(int n);

int main() {
    char *container;
    container = get_all(SIZE);
    puts(container);
    return 0;
}

char *get_all(int n) {
    extern char st[SIZE];
    fgets(st, n, stdin);
    int i = 0;
    while (st[i] != '\n' && st[i] != ' ' && st[i] != '\t' && st[i] != '\0') {
        i++;
    }
    if (st[i] == '\0') {
        while (getchar() != '\n') {
            continue;
        }
    } else {
        st[i] = '\0';
    }

    return st;
}