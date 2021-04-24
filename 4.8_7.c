#include<stdio.h>
#include<float.h>

int main() {
    double res1 = 1.0;
    float res2 = 1.0;
    int i = 3;
    for (i = 3; i <= 12; i *= 2){
        printf("%.*f %.*f\n", i, res1 / 3.0, i, res2 / 3.0);
    }
    printf("%.16f %.16f\n", res1 / 3.0, res2 / 3.0);
    printf("%d %d", FLT_DIG, DBL_DIG);
    return 0;
}