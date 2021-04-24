#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 40

struct names {
    char first[NUM];
    char last[NUM];
};

void showarray(struct names * arr, int n);
int mycomp(const void *p1, const void *p2);

int main() {
    struct names arr[4] = {{"Keith", "Flick"}, {"Anne", "Smith"}, {"Allen", "Jaeger"}, {"John", "Sue"}};
    puts("The origin array:");
    showarray(arr, 4);
    qsort(arr, 4, sizeof(struct names), mycomp);
    puts("\nThe sorted array:");
    showarray(arr, 4);
    return 0;
}

int mycomp(const void *p1, const void *p2) {
    const struct names *ps1 = (struct names *)p1;
    const struct names *ps2 = (struct names *)p2;
    int res = strcmp(ps1->last, ps2->last);
    if (res == 0) {
        return strcmp(ps2->first, ps2->first);
    } else {
        return res;
    }
}

void showarray(struct names *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%s %s\n", arr[i].first, arr[i].last);
    }
}
