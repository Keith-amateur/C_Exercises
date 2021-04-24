#include<stdio.h>

int main() {
	char ch = 'A' - 1;
	int i, j;
	for (i = 0; i < 4; i++){
		for (j = 0; j < i + 1; j++) {
			ch = ch + 1;
			printf("%c", ch);
		}
		printf("\n");
	}

}
