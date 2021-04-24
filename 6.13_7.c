#include<stdio.h>
#include<string.h>
int main() {
	char word[40];
	printf("Please enter a word: ");
	scanf("%s", &word);
	int i;
	printf("The word you enter is %s\n", word);
	printf("The reserve word is ");
	for (i = strlen(word); i > 0; i--){
		printf("%c", word[i - 1]);
	}

	return 0;
}
