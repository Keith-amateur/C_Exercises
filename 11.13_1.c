#include<stdio.h>
#define SIZE 80

char *get_all(int n);
char st[SIZE];

int main() {
    char *container;
    container = get_all(SIZE);
    puts(container);
    return 0;   
}

char *get_all(int n) {
    extern char st[SIZE];
    fgets(st, n, stdin);
    return st;
} 
