#include<stdio.h>
#include<ctype.h>
int alpha_num(char ch);

int main() {
    char ch;
    printf("Please enter somer characters: ");
    while ((ch = getchar()) != '\n')
    {
        printf("%d ", alpha_num(ch));
    }
    return 0;
}
int alpha_num(char ch) {
    if (isalpha(ch)) {
        return toupper(ch) - 'A' + 1;
    } else {
        return -1;
    }
}