#include <stdio.h>
#include <stdlib.h>
#define SLEN 21

int main() {
	char filename[SLEN];
	puts("Please enter the filename");
	scanf("%s", filename);
	FILE *fp;
	if ((fp = fopen(filename, "r")) == NULL) {
		fprintf(stderr, "Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	} 
	long index;
	while ((scanf("%ld", &index)) == 1 && index >= 0) {
		fseek(fp, index, SEEK_SET);
		char ch;
		while ((ch = getc(fp)) != '\n') {
			putc(ch, stdout);
		}
		putchar('\n');
	}
	fclose(fp);



	return 0;
}