#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int main() {
    int num;
    printf("How many words do you wish to enter? ");
    scanf("%d", &num);
    char **ptr;
    ptr = (char **)malloc(num * 8);
    printf("Enter %d words now:\n", num);
    int i;
    char p[SIZE];
    for (i = 0; i < num; i++) {
        scanf("%s", &p[20 * i]);
        ptr[i] = &p[20 * i];
    }
    puts("Here are your words:");
    for (i = 0; i < num; i++) {
        puts(ptr[i]);
    }
    free(ptr);
    return 0;
}