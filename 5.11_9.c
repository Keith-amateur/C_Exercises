#include<stdio.h>
void Temperatures(double temper);
int main() {
    double temper;
    printf("Please enter temper in F\n");
    while (scanf("%lf", &temper) == 1) {
        Temperatures(temper);
        printf("Please enter temper in F\n");
    }
    printf("Done!");
    return 0;
}
void Temperatures(double temper) {
    double t_C = 0.0;
    double t_K = 0.0;
    t_C = 5.0 / (temper - 32.0);
    t_K = t_C + 273.16;
    printf("temperature in F C K: %.3f %.3f %.3f\n", temper, t_C, t_K);
}
