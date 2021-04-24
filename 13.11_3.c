#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SLEN 21
#define FILELEN 101

int main() {
	char st[SLEN];
	puts("Please enter the file path");
	scanf("%s", st);
	FILE *fp;
	if ((fp = fopen(st, "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", st);
		exit(EXIT_FAILURE);
	}
	char filecontent[FILELEN];
	char ch;
	int i = 0;
	while ((ch = getc(fp)) != EOF) {
		filecontent[i++] = ch;
	}
	filecontent[i] = '\0';
	fclose(fp);
	for (i = 0; i < strlen(filecontent); i++) {
		filecontent[i] = toupper(filecontent[i]);
	}

	if ((fp = fopen(st, "w")) == NULL) {
		fprintf(stderr, "Can't open %s\n", st);
		exit(EXIT_FAILURE);
	}

	fwrite(filecontent, sizeof(char), strlen(filecontent), fp);
	fclose(fp);
	puts("Done!");


	return 0;
}