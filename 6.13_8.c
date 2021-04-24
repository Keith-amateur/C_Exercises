#include<stdio.h>
int main() {
	double a, b;
	printf("Please enter two double numbers(q to quit): ");
	while (scanf("%lf %lf", &a, &b) == 2) {
		printf("%f\n", (a - b)/ (a * b));
		printf("Please enter two double numbers(q to quit): ");
	}
	
	return 0;
}
