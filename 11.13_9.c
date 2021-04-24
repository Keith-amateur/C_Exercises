#include<stdio.h>
#include<string.h>

#define SIZE 80

char *reverse_str(char *str, int n);
char *s_gets(char *str, int n);

int main() {
    char str[SIZE];
    char *ret_str;
    puts("Please enter a string:");
    while (s_gets(str, SIZE) && str[0] != '\0') {
        ret_str = reverse_str(str, strlen(str));
        puts(ret_str);
    }
    return 0;
}

char *reverse_str(char *str, int n) {
    int i;
    char temp;
    for (i = 0; i < n / 2; i++) {
        temp = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = temp;
    }
    return str;
}

char *s_gets(char *str, int n) {
    char *st;
    int i = 0;
    st = fgets(str, n, stdin);
    if (st) {
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
    return st;
}