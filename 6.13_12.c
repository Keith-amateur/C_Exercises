#include<stdio.h>

int main() {
	int times;
	printf("Please enter how many times:");
	scanf("%d", &times);
	while (times > 0) {
		int i;
		double sum1 = 0;
		double sum2 = 0;
		double sum3 = 0;
		for (i = 1; i <= times; i++) {
			sum1 += 1.0 / i;
			if (i % 2 == 0) {
				sum2 += - 1.0 / i;
			} else {
				sum2 += 1.0 / i;
			}
			if (i % 2 == 1) {
				sum3 += 2 * (1.0 / i);
			}
		}
		printf("1 + 1/2 +....+ 1/%d = %f\n", times, sum1);
		printf("1 - 1/2 +.... 1/%d = %f\n", times, sum2);
		printf("1 + 1/3 + 1/5 +....=%f\n", sum3);
		printf("Please enter how many times:");
		scanf("%d", &times);
	}
	printf("Done");
	return 0;
}
