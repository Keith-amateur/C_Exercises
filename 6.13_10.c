#include<stdio.h>
int main() {
	int a, b;
	int sum = 0;
	printf("Please enter two integers: ");
	scanf("%d %d", &a, &b);
	while ( a < b) {
		int i;
		for (i = a; i <= b; i++) {
			sum += i * i;
		}
		printf("The sums of squares from %d to %d is %d\n", a * a, b * b, sum);
		printf("Please enter two integers: ");
		scanf("%d %d", &a, &b);

	}
	printf("Done!");
	
	return 0;
}
