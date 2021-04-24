#include<stdio.h>
int main(){
	printf("Please enter a capital alphabet: ");
	char ch;
	int rows;
	scanf("%c", &ch);
	rows = ch - 'A' + 1;
	int i, j;
	for (i = 0; i < rows; i++) {
		char ch1 = 'A' - 1;
		for (j = 0; j < rows - (i + 1); j++)
			printf(" ");
		for (j = 0; j < i + 1; j++) {
			ch1 += 1;
			printf("%c", ch1);
		}
		for (j = 0; j < i; j++){
			ch1 -= 1;
			printf("%c", ch1);
		}
		printf("\n");
	}

}
