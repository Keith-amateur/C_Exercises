#include<stdio.h>
#define INTEREST1 0.1
#define INTEREST2 0.05
int main() {
	double p_1 = 100;
	double p_2 = 100;
	int year = 0;
	while (p_2 <= p_1) {
		p_1 += 100 * INTEREST1;
		p_2 *= (1 + INTEREST2);
		year++;

	}
	printf("%d\n", year);
	printf("%f %f", p_1, p_2);

	return 0;
}
