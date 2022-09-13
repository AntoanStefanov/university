#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char string[80];

	printf("Enter string: ");
	scanf_s("%s", string, 80);
	string[79] = "\0";
	printf("String: %s\n", string);
	if (!string) {
		return -1;
	}

	char* second = NULL;
	char* first = strtok_s(string, "+", &second);
	int firstNum = atoi(first);

	if (second) {
		int secondNum = atoi(second);
		printf("Sum: %d\n", firstNum + secondNum);
	}

	return 0;

}