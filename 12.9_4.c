#include<stdio.h>
#include<stdlib.h>
static int func_count = 0;
void func(void);

int main(int argc, char **argv) {
    int n;
    n = atoi(argv[1]);
    if (argc < 2 || n < 1) {
        puts("Please enter a correct command argument");
        exit(0);
    }
    int i;
    for (i = 0; i < n; i++) {
        func();
    }
    printf("The func has been used %d time", func_count);
    return 0;
}

void func(void) {
    func_count++;
}