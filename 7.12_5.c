#include<stdio.h>

int main() {
    int replace_num = 0;
    char ch;
    while ((ch = getchar()) != '#') {
        switch (ch) {
            case '.':
                ch = '!';
                replace_num++;
                break;
            case '!':
                putchar('!');
                replace_num++;
                break;
            default:
                break;
        }
        putchar(ch);
    }
    printf("\n%d %s", replace_num, (replace_num == 1) ? "time" : "times");
    return 0;
}