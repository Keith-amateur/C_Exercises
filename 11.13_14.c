#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("wrong number of arguments\n");
        exit(0);
    }
    double base = atof(argv[1]);
    int power = atoi(argv[2]);
    int i;
    double res = 1;
    for (i = 0; i < power; i++) {
        res *= base;
    }
    printf("%.2f", res);

    return 0;
}