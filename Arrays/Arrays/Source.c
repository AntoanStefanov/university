#include <stdio.h>
#include <stdlib.h>


void freeArray(int** arr, int rows) {
	for (int i = 0; i < rows; ++i) {
		free(arr[i]);
	}
	free(arr);
}

int main() {
	int rows = 0;
	int cols = 0;

	printf("How many rows? ");
	scanf_s("%d", &rows);

	printf("How many columns? ");
	scanf_s("%d", &cols);

	if (!rows || !cols) {
		return -1;
	}

	int** arr = malloc(sizeof(int*) * rows);
	for (int i = 0; i < rows; i++) {
		arr[i] = malloc(sizeof(int) * cols);
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("Element: %d\n", arr[i][j]);
		}
	}

	freeArray(arr, rows);

	return 0;
}