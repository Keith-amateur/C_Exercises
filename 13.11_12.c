#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
	if (argc == 1) {
		fprintf(stderr, "not enough arguments\n");
		exit(EXIT_FAILURE);
	}
	FILE *fp;
	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	int num_arr[20][30];
	char char_arr[20][31];
	char char_table[10] = {' ', '.', '\'', ':', '~', '*', '=', ' ', '%', '#'};
	int i, j;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 30; j++) {
			fscanf(fp, "%d", &num_arr[i][j]);
			printf("%c ", char_table[num_arr[i][j]]);
			char_arr[i][j] = char_table[num_arr[i][j]];
		}
		putchar('\n');
	}
	for (i = 0; i < 20; i++) {
		char_arr[i][30] = '\0';
		puts(char_arr[i]);
	}


	fclose(fp);
	return 0;
}