#include <stdio.h>
#include <math.h>
#define NUM 101
#define M_PI 3.14159265358979323846


void transform(double *src, double *dst, int num, double (*pf)(double));
double square(double x);
double cube(double x);
void showdst(double *dst, int num);
int main() {
    double src[NUM] = {0.0};
    double dst[NUM] = {0.0};
    int i;
    for (i = 1; i < NUM; i++) {
        src[i] = i * (M_PI / 100);
    }
    transform(src, dst, NUM, sin);
    showdst(dst, NUM);
    printf("\n\n");
    transform(src, dst, NUM, cos);
    showdst(dst, NUM);
    printf("\n\n");
    transform(src, dst, NUM, square);
    showdst(dst, NUM);
    printf("\n\n");
    transform(src, dst, NUM, cube);
    showdst(dst, NUM);
    printf("\n\n");
    return 0;
}

void transform(double *src, double *dst, int num, double (*pf)(double)) {
    int i;
    for (i = 0; i < num; i++) {
        dst[i] = (*pf)(src[i]);
    }
}

double square(double x) {
    return x * x;
}

double cube(double x) {
    return x * x * x;
}

void showdst(double *dst, int num) {
    int i;
    for (i = 0; i < num; i++) {
        if (i % 20 == 0) {
            printf("\n");
        }
        printf("%5.2f ", dst[i]);
    }
}