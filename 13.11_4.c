#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if (argc == 1) {
		fprintf(stderr, "Please enter an argument\n");
	}
	int i;
	for (i = 1; i < argc; i++) {
		printf("%s\n", argv[i]);
	}

	return 0;
}