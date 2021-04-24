#include<stdio.h>
int main() {
	int int_arr[8];
	int i, j;
	printf("Please enter 8 integers:\n");
	for (i = 0; i < 8; i++) {
		scanf("%d", &int_arr[i]);
	}
	for (j = 7; j >= 0; j--) {
		printf("%d ", int_arr[j]);

	}
	return 0;
}
