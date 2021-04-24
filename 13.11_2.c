#include <stdio.h>
#include <stdlib.h>
#define SLEN 21

int main(int argc, char **argv) {
	FILE *orgin_fp;
	FILE *dest_fp;
	int ch;
	if (argc != 3) {
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((orgin_fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(orgin_fp)) != EOF) {
		putc(ch, dest_fp);
	}
	fclose(orgin_fp);
	fclose(dest_fp);





	return 0;
}