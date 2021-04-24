#include<stdio.h>

int main() {
	char alpha_bet[26];
	int i;
	for (i = 0; i < 26; i++) {
		alpha_bet[i] = 'a' + i;
		printf("%c\t", alpha_bet[i]);
	}
	
	return 0;	
}	
