#include<stdio.h>
// 输入ASCII码值(如, 66), 然后打印输入的字符
int main() {
    int ch;
    printf("请输入一个ASCII码值:\n");
    scanf("%d", &ch);
    printf("%c", ch);
    return 0;
}