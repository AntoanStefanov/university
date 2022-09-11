
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, answerNum;
	int nextNum = 0;
	int previousNum = 1;
	int currentNum = 1;
	printf("Fn for n= ");
	scanf_s("%d", &n);

	if (n < 0) {
		printf("Please input positive num.");
		return 0;
	}

	if (n == 0) {
		answerNum = 0;
	}
	else if (n == 1 || n == 2) {
		answerNum = 1;
	}

	for (int i = 3; i <= n; i++) {
		nextNum = previousNum + currentNum;
		previousNum = currentNum;
		currentNum = nextNum;
	}

	if (nextNum) {
		answerNum = nextNum;
	}

	printf("Fibonacci(n=%d): %d", n, answerNum);
	return 0;
}