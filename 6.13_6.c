#include<stdio.h>

int main() {
	int start_num, end_num;
	printf("Please enter the start number and end number:");
	scanf("%d %d", &start_num, &end_num);
	int i;
	for (i = start_num; i <= end_num; i++) {
		printf("%6d %6d %6d\n", i, i * i, i * i * i);

	}
	return 0;
}
