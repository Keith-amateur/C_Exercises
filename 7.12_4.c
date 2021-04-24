#include<stdio.h>

int main() {
    int replace_num = 0;
    char ch;
    while ((ch = getchar()) != '#') {
        if (ch == '.') {
            ch = '!';
            replace_num++;
        } else if (ch == '!') {
            putchar('!');
            replace_num++;
        }
        putchar(ch);
    }
    printf("\n%d %s", replace_num, (replace_num == 1) ? "time" : "times");
    return 0;   
}