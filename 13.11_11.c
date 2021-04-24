#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define MAXLEN 256
int main(int argc, char **argv) {
	if (argc == 1) {
		fprintf(stderr, "Not enough arguments\n");
		exit(EXIT_FAILURE);
	}
	FILE *fp;
	if ((fp = fopen(argv[2], "r")) == NULL) {
		fprintf(stderr, "Can't open the file %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	char line[MAXLEN];
	while (!feof(fp)) {
		memset(line, 0, MAXLEN);
		fgets(line, MAXLEN, fp);
		if (strstr(line, argv[1])) {
			fputs(line, stdout);
		}
	}
	fclose(fp);



	return 0;
}