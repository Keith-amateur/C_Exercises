#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
	int row = 0;
	int col = 0;
	char ch;
	puts("loop starts");
	while ((ch = getc(fp)) != EOF) {
		if (isdigit(ch)) {
			col++;
		} else if (ch == '\n') {
			row++;
		}
	}
	col /= row;
	puts("loop ends");
	printf("%d %d\n", row, col);

	int num_arr[row][col];
	char char_arr[row][col + 1];
	char char_table[10] = {' ', '.', '\'', ':', '~', '*', '=', ' ', '%', '#'};
	int i, j;
	rewind(fp);			// 文件光标回到开头
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			fscanf(fp, "%d", &num_arr[i][j]);
			printf("%c ", char_table[num_arr[i][j]]);
			char_arr[i][j] = char_table[num_arr[i][j]];
		}
		putchar('\n');
	}
	for (i = 0; i < row; i++) {
		char_arr[i][col] = '\0';
		puts(char_arr[i]);
	}


	fclose(fp);
	return 0;
}