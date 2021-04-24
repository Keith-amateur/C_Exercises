#include<stdio.h>
#include<string.h>

#define SIZE 80

char *string_in(char *st1, char *st2);

int main() {
    char s1[SIZE];
    char s2[SIZE];
    while (fgets(s1, SIZE, stdin) && fgets(s2, SIZE, stdin)) {
        char *st;
        st = string_in(s1, s2);
        printf("%c", *st);
    }
    return 0;
}

char *string_in(char *st1, char *st2) {
    int i = 0;
    int lenOfst2 = 0;
    int j = 0;
    // 取得st2的长度
    while (st2[j]) {
        lenOfst2++;
        j++;
    }
    while (st1[i]) {
        if (!strncmp(&st1[i], st2, lenOfst2 - 1)) {         // lenOfst2 - 1 是为了去掉换行符
            return &st1[i];
        }
        i++;
    }
    return NULL;
}