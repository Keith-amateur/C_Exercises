#include<stdio.h>
char get_first(void);       //读取非缓存区中的第一个非空白字符
int main() {
    char ch;
    while ((ch = get_first()) != EOF) {
        putchar(ch);
        printf("\n%d\n", ch);
        printf("------------\n");
    }
    return 0;   
}

char get_first(void) {
    int ch;
    while (1) {
        if ((ch = getchar()) > ' ')
            break;
    }
    while (getchar() != '\n') {
        continue;
    }
    return ch;
}