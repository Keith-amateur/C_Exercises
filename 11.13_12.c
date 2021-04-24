#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define SIZE 81

char *s_gets(char *st, int n);
int countWords(char *st);

int main() {
    char st[SIZE];
    int store_num[5] = {0};
    int i = 0;
    int j;
    while (s_gets(st, SIZE)) {
        store_num[0] = countWords(strcat(st, " "));
        while (st[i] != '\0') {
            if (isupper(st[i]))
                store_num[1]++;
            if (islower(st[i]))
                store_num[2]++;
            if (ispunct(st[i]))
                store_num[3]++;
            if (isdigit(st[i]))
                store_num[4]++;
            i++;
        }
        printf("单词数:%d\t大写字母数:%d\t小写字母数:%d\t标点符号数:%d\t数字字符数:%d\t",
           store_num[0], store_num[1], store_num[2], store_num[3], store_num[4]);
        for (j = 0; j < 5; j++) {
            store_num[j] = 0;
        }
        i = 0;
        putchar('\n');
    }
    return 0;
}
int countWords(char *st) {
    int count = 0;
    int i = 0;
    int inword = 0;
    int flag = 0;
    while (st[i] != '\0') {
        if (toupper(st[i]) >= 65 && toupper(st[i]) <= 90) {
            inword = 1;
            flag = 1;
        } else {
            inword = 0;
        }
        if (flag && !inword) {
            count++;
            flag = 0;
        }
        i++;
    }
    return count;
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