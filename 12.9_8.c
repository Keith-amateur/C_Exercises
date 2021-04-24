#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int *make_array(int size, int vals);
void show_array(int *arr, int size);

int main() {
	int *pa;
	int size;
	int value;

	printf("Enter the number of elements: ");
	while (scanf("%d", &size) == 1 && size >= 1) {
		printf("Enter the initialization values: ");
		scanf("%d", &value);
		pa = make_array(size, value);
		if (pa) {
			show_array(pa, size);
			free(pa);
		}
		printf("Enter the number of elements (< 1 to quit): ");
	}
	printf("Done.\n");

	return 0;
}

int *make_array(int size, int value) {
	int *p;
	p = (int *)malloc(size * sizeof(int));
	int i;
	for (i = 0; i < size; i++) {
		p[i] = value;
	}	
	return p;
}
void show_array(int *p, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", p[i]);
	}
	putchar('\n');
}