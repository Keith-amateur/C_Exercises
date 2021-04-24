#include<stdio.h>

int main() {
    char ch;
    int cnt = 0;
    while ((ch = getchar()) != EOF) {
        if (ch <= ' ') {
            if (ch == '\n') {
                printf("%5s:%5d\t", "\\n", ch);
                cnt++;
            } else if (ch == '\t') {
                printf("%5s:%5d\t", "\\t", ch);
                cnt++;
            } else if (ch == ' ') {
                printf("%5s:%5d\t", "space", ch);
                cnt++;
            } else {
                printf("%4c%c:%5d\t", '^', ch + 64, ch);
                cnt++;
            }
        } else {
            printf("%5c:%5d\t", ch, ch);
            cnt++;
        }
        if (cnt % 10 == 0) {
            putchar('\n');
        }
    }
    printf("\n\n一共输入了%d个字符", cnt);
    return 0;
}