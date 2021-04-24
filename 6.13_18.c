#include<stdio.h>
int main() {
	int num_friends = 5;
	int i = 1;
	do {
		printf("%d weeks, number:%d\n", i, num_friends);
		num_friends = (num_friends - i) * 2;
		i++;

	} while (num_friends <= 150);
	return 0;
}

