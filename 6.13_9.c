#include<stdio.h>
double calc(double a, double b);
int main() {
	double a, b;
	printf("Please enter two double numbers:");
	while (scanf("%lf %lf",&a, &b) == 2) {
		printf("%f", calc(a, b));
		printf("Please enter two double numbers(q to quit):\n");
	}
	
	return 0;
}
double calc(double a, double b) {
	double res;
	res = (a - b) / (a * b);
	return res;
	
}
