#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 81

char *s_gets(char *str, int n);
void ToUpper(char *str);
void ToLower(char *str);

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("Please enter an argument (-p, -u, -l)\n");
		exit(0);
	}
	char str[SIZE];
	puts("Enter");
	while (s_gets(str, SIZE)) {
		if (!strcmp(argv[1], "-p")) {
			puts(str);
		} else if (!strcmp(argv[1], "-u")) {
			ToUpper(str);
			puts(str);
		} else if (!strcmp(argv[1], "-l")) {
			ToLower(str);
			puts(str);
		}
		puts("Enter the next string");
	}
	return 0;
}

void ToUpper(char *str) {
	while (*str) {
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char *str) {
	while (*str) {
		*str = tolower(*str);
		str++;
	}
}

char *s_gets(char *str, int n) {
	char *ret_val;
	int i = 0;
	ret_val = fgets(str, n, stdin);
	if (ret_val) {
		while (str[i] != '\0' && str[i] != '\n') {
			i++;
		}
		if (str[i] == '\n') {
			str[i] = '\0';
		} else {
			while (getchar() != '\n') {
				continue;
			}
		}
	}
	return ret_val;
}

