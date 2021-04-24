#include<stdio.h>

int main(){
	double a[8];
	double b[8];
	int i;
	int sum = 0;
	for (i = 0; i < 8; i++) {
		scanf("%lf", &a[i]);
		sum += a[i];
		b[i] = sum;
	}
	int j;
	for (j = 0; j < 8; j++) {
		printf("%.2f ", a[j]);
	}
	printf("\n");
	for (j = 0; j < 8; j++) {
		printf("%.2f ", b[j]);
	
	}




	return 0;
}
