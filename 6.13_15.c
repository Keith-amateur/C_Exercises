#include<stdio.h>
int main() {
	char row[256];
	int i = 0;
	do {
		scanf("%c", &row[i]);

	} while (row[i] != '\n' && ++i);
	for (i--; i >= 0; i--) {
		printf("%c", row[i]);
	}
	printf("\nDone!\n");
	
	return 0;
}
