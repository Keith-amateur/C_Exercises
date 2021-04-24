#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define	SLEN 81

void append(FILE *fp, FILE *dest);

int main(int argc, char **argv) {
	FILE *fa, *fs;
	if (argc == 1) {
		fprintf(stderr, "not enough argument");
		exit(EXIT_FAILURE);
	}
	if ((fa = fopen(argv[1], "a+")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0) {
		fputs("Can't create buffer.\n", stderr);
		exit(EXIT_FAILURE);
	}
	int i;
	// 第三个字符串才是sourcdfile
	for (i = 2; i < argc; i++) {
		if (strcmp(argv[1], argv[i]) == 0) {
			fputs("Can't append file to itself\n", stderr);
		} else if ((fs = fopen(argv[i], "r")) == NULL) {
			fprintf(stderr, "Can't open %s\n", argv[i]);
		} else {
			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0) {
				fputs("Can't create input buffer\n", stderr);
				continue;
			}
			append(fs, fa);
			if (ferror(fs) != 0) {
				fprintf(stderr, "Error in reading file %s\n", argv[i]);
			}
			if (ferror(fa) != 0) {
				fprintf(stderr, "Error in writing file %s\n", argv[i]);
			}
			fclose(fs);
			printf("File %s appended \n", argv[i]);
		}
	}
	printf("Done appending. %d files appended \n", argc - 2);
	rewind(fa);
	printf("%s contents: \n", argv[1]);
	char ch;
	while ((ch = getc(fa)) != EOF) {
		putc(ch, stdout);
	}
	puts("Done displying.");
	fclose(fa);

	return 0;
}

void append(FILE *fs, FILE *fa) {
	size_t bytes;
	static char temp[BUFSIZE];
	while ((bytes = fread(temp, sizeof(char), BUFSIZE, fs)) > 0) {
		fwrite(temp, sizeof(char), BUFSIZE, fa);
	}
}