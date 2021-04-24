#include<stdio.h>
void chline(char ch, int i, int j);
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

void chline(char ch, int i, int j) {
    int a, b;
    for (b = 0; b < j; b++) {
        for (a = 0; a < i; a++) {
            putchar(ch);
        }
        putchar('\n');
    }
}