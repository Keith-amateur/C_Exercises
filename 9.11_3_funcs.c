#include<stdio.h>
#include"9.11_3.h"
void chline(char ch, int i, int j) {
    int a, b;
    for (b = 0; b < j; b++) {
        for (a = 0; a < i; a++) {
            putchar(ch);
        }
        putchar('\n');
    }
}