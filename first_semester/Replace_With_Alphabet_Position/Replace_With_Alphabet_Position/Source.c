#include <stdlib.h>

// returned string has to be dynamically allocated and will be freed by the caller
char* alphabet_position(const char* text) {
	for (int i = 0; i < 5; i++) {
		char ch = text[i];
	}
	char* numbers = "1 2 3";

	return numbers;
}

int main() {
	const char* input = "The sunset sets at twelve o' clock.";
	char* ptr = alphabet_position(input);
	free(ptr);
	return 0;
}
