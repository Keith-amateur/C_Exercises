#include <stdio.h>
#include <string.h>
#include "17.12_5_stack.h"

char *s_gets(char *st, int n);
int main() {
    Stack stack;
    InitializeStack(&stack);
    char str[MAXSTACK + 1];
    puts("Enter a string");
    while (s_gets(str, MAXSTACK + 1) != NULL && str[0] != '\0') {
        int i;
        for (i = 0; i < strlen(str); i++) {
            push(str[i], &stack);
        }
        char ch;
        // pop(&ch, &stack);
        // printf("%c\n", *ch);
        while (!StackIsEmpty(&stack)) {
            pop(&ch, &stack);
            printf("%c", ch);
        }
        puts("\nEnter the next string (empty line to quit)");
    }
    EmptyTheStack(&stack);

    return 0;
}

char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find) {
            *find = '\0';
        } else {
            while (getchar() != '\n') {
                continue;
            }
        }
    }
    return ret_val;
}