#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

static unsigned long int next = 1;
int rand1(void);
void srand1(unsigned int seed);

int main() {
    int *arr = (int *)malloc(10 * sizeof(int));
    memset(arr, (char)0, 10 * sizeof(int));
    int i;
    for (i = 0; i < 1000; i++) {
        arr[rand1() - 1]++;
    }
    for (i = 0; i < 10; i++) {
        printf("%d : %d  ", i + 1, arr[i]);
    }
    free(arr);
    return 0;
}

int rand1(void) {
    next = next * 1103515245 + 12345;
    return (unsigned int)((next / 65536) % 10 + 1);
}

void srand1(unsigned int seed) {
    next = seed;
}