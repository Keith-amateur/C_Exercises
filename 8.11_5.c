#include<stdio.h>
char get_first(void);
int main() {
    int guess = 50;
    int low = 1;
    int high = 100;
    char ch;
    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it with a y if my guess is right.\nIf my guess is wrong, ");
    printf("tell me whether the integer is bigger(b) or smaller(s) than my guess.\n");
    printf("Is it %d?\n", guess);
    while ((ch = get_first()) != 'y') {
        switch (ch) {
            case 'b':
                low = guess;
                guess = (high + guess) / 2;
                break;
            case 's':
                high = guess;
                guess = (low + guess) / 2;
                break;
            default:
                printf("Wrong input.\n");
                break;
        }
        printf("Is it %d?\n", guess);
    }
    return 0;
}

char get_first(void) {
    int ch;
    ch = getchar();
    while (getchar() != '\n') {
        continue;
    }
    return ch;
}

