#include<stdio.h>
int power(int n, int p);
int main() {
	int a[8];
	int i;
	for (i = 0; i < 8; i++) {
		a[i] = power(2, i);
	}
	i = i - 1;
	do {
		printf("%d ", a[7-i]);
		i--;
	} while (i >= 0);
	return 0;
}

int power(int n, int p) {
	int i;
	int res = 1;
	if (p == 0) {
		return 1;
	}
	for (i = 0; i < p; i++) {
		res *= n;
	}
	return res;
}

