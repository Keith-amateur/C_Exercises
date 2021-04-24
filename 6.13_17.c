#include<stdio.h>

int main() {
	double money = 100;
	int year = 0;
	while (money > 9) {
		money *= 1 + 0.08;
		money -= 10;
		year++;
	}
	printf("%d years later, %f left\n", year, money );
	printf("%d years later, nothing left", ++year);
	return 0;
}
