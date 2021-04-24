#include<stdio.h>
#include"9.11_3.h"
int main() {
    char ch;
    printf("Please enter the character you want to display: ");
    while ((ch = getchar()) <= ' ') {
        continue;
    }
    printf("Please enter two integers: ");
    int i, j;
    while (scanf("%d %d", &i, &j) != 2) {
        printf("Please enter the number such as 3, 1.2: ");
        scanf("%*s");
    }
    chline(ch, i, j);
    return 0;
}