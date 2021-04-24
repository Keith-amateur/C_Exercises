#include<stdio.h>
#include<stdbool.h>
#define SIZE 80
bool is_within(char ch, char *st);

int main() {
    char st[SIZE];
    puts("Please enter the string");
    fgets(st, SIZE, stdin);
    char ch;
    puts("Please enter the char");
    while ((ch = getchar()) != '\n') {
        printf("%d", is_within(ch, st));
    }
    return 0;
}

bool is_within(char ch, char *st) {
    while (*st) {
        if (*st == ch)
            return true;
        st++;
    }
    return false;
}