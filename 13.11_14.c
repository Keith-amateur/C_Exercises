#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
void dealwithnoise(int row, int col, int num_arr[row][col]);

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
			// char_arr[i][j] = char_table[num_arr[i][j]];
		}
		putchar('\n');
	}
	dealwithnoise(row, col, num_ar)rif (abs(num_arr[row-1][0] - num_arr[row-2][0]) > 1 && abs(num_arr[row-1][0] - num_arr[row-1][1]) > 1) {
		num_arr[row-1][0] = (num_arr[row-2][0] + num_arr[row-1][1]) / 2;
	}if (abs(num_arr[row-1][0] - num_arr[row-2][0]) > 1 && abs(num_arr[row-1][0] - num_arr[row-1][1]) > 1) {
		num_arr[row-1][0] = (num_arr[row-2][0] + num_arr[row-1][1]) / 2;
	};
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			char_arr[i][j] = char_table[num_arr[i][j]];
		}
	}

	for (i = 0; i < row; i++) {
		char_arr[i][col] = '\0';
		puts(char_arr[i]);
	}


	fclose(fp);



	return 0;
}

void dealwithnoise(int row, int col, int num_arr[row][col]) {
	int i, j;
	for (i = 1; i < row - 1; i++) {
		for (j = 1; j < col - 1; j++) {
			if (abs(num_arr[i][j] - num_arr[i-1][j]) > 1 &&
				abs(num_arr[i][j] - num_arr[i+1][j]) > 1 &&
				abs(num_arr[i][j] - num_arr[i][j-1]) > 1 &&
				abs(num_arr[i][j] - num_arr[i][j+1]) > 1) {
				num_arr[i][j] = (num_arr[i-1][j] + num_arr[i+1][j] + 
								 num_arr[i][j-1] + num_arr[i][j+1]) / 4;

			}
		}
	}

	// 四个顶点
	if (abs(num_arr[0][0] - num_arr[0][1]) > 1 &&
		abs(num_arr[0][0] - num_arr[1][0]) > 1) {
		num_arr[0][0] = (num_arr[0][1] + num_arr[1][0]) / 2;
	}
	if (abs(num_arr[row-1][0] - num_arr[row-2][0]) > 1 &&
	    abs(num_arr[row-1][0] - num_arr[row-1][1]) > 1) {
		num_arr[row-1][0] = (num_arr[row-2][0] + num_arr[row-1][1]) / 2;
	}
	if (abs(num_arr[0][col-1] - num_arr[0][col-2]) > 1 &&
	 	abs(num_arr[0][col-1] - num_arr[1][col-1]) > 1) {
		num_arr[0][col-1] = (num_arr[0][col-2] + num_arr[1][col-1]) / 2;
	}
	if (abs(num_arr[row-1][col-1] - num_arr[row-1][col-2]) > 1 &&
	    abs(num_arr[row-1][col-1] - num_arr[row-2][col-2]) > 1) {
		num_arr[row-1][col-1] = (num_arr[row-1][col-2] + num_arr[row-2][col-1]) / 2;
	}
	num_arr[0][2] = 0;




}