#include<stdio.h>
int main() {
    char ch;
    int cnt = 0;
    while ((ch = getchar()) != '#') {
        if (ch == 'e' && getchar() == 'i') {
            cnt++;
        }
    }
    printf("%d \'ei\'", cnt);
    return 0;
}