#include<stdio.h>

int main() {
    char ch;
    int cnt = 0;
    while ((ch = getchar()) != '#') {
        if (ch == '\n')
            continue;
        cnt++;
        printf("%c : %d ", ch, ch);
        if (cnt % 8 == 0) {
            printf("\n");
        }
    }
    printf("Done!");
    return 0;
}