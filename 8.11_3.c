#include<stdio.h>
#include<ctype.h>

int main() {
    char ch;
    int cnt_lower = 0;
    int cnt_upper = 0;
    while ((ch = getchar()) != EOF) {
        if (islower(ch)) {
            cnt_lower++;
        } else if (isupper(ch)) {
            cnt_upper++;
        }
    }
    printf("大写: %d\t小写: %d", cnt_upper, cnt_lower);
    return 0;
}