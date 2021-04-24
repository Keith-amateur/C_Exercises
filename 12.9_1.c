// 重写12.4_global.c程序
#include <stdio.h>

void critic(int *ptr);

int main() {
	printf("How many pounds to a firkin of butter?\n");
	int units = 0;
	scanf("%d", &units);
	while (units != 56) {
		critic(&units);
	}
	printf("You must have looked it up!\n");

	return 0;
}

void critic(int *ptr) {
	printf("No luck my friends. Try again.\n");
	scanf("%d", ptr);
}