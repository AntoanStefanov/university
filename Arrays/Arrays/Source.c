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

	int* MinValuesArr = malloc(sizeof(int)*cols);

	printf("Inserting goes by column.\n");
	for (int j = 0; j < cols; j++) {
		int minValue = INT_MAX;
		for (int i = 0; i < rows; i++) {
			printf("Element[%d][%d]= ", i,j);
			scanf_s("%d", &arr[i][j]);
			if (arr[i][j] < minValue) {
				minValue = arr[i][j];
			}
		}
		MinValuesArr[j] = minValue;
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < cols; i++) {
		printf("Min Value: %d\n", MinValuesArr[i]);
	}

	int maxOfMins = MinValuesArr[0];
	int maxOfMinsColumnNumber = -1;
	for (int i = 1; i < cols; i++) {
		if (MinValuesArr[i] > maxOfMins) {
			maxOfMins = MinValuesArr[i];
			maxOfMinsColumnNumber = i + 1;
		}
	}
	printf("Max Value of Mins: %d, Column Number = %d\n", maxOfMins, maxOfMinsColumnNumber);

	freeArray(arr, rows);

	return 0;
}