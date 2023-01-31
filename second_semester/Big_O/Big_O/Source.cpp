#include <iostream> // for std::cout, std::cin
#include <vector> // for std::vector
#include <format> // for std::format
#include <numeric> // for std::midpoint

using std::string;
using std::cout;
using std::endl;
using std::format;
using std::vector;
using std::midpoint;

// Time complexity describes how the CPU operations are changing,
// with the input size(n) increase.
// More CPU operations, more time needed for the ALGO to execute.

// Same idea is for space complexity,
// it describes how the needed memory space is changing,
// based on the input size(n).

// Big O:
// It gives an estimate of how long it takes your code to run on different sets of inputs.
// It it a measure for our algorithm efficiency as the input size increases.

// Big O:
// Analyses the worst-case scenario.

// f(n) = 7log(n)^3 + 15n^2 + 2n^3 + 8
// O(f(n)) = O(n^3) -> big O of n cubed. -> Cubic time, because,
// n^3 is the most dominant term.

// c - constant, n - input size.
// We ignore constants and mathematical operations,
// infinity(n) + 7(c) is again infinity.
// O(n+c) = O(n)
// O(c*n) = O(n)


// The time to finish(CPU_operations) is(are) fully independent of the input size(n),
// O(1), constant time.
// The loop does not depend on the input size(n).
void constantTime(int n) {
	cout << n;
	int i = 0;
	while (i < 11) {
		i++;
	}

}

// The algorithm runs in linear time with respect to the input size(n),
// because we do a constant amount of work, n-times.
// with input size increase, the CPU operations increase too.
// Here: f(n) = n, so
// O(f(n)) = O(n)
void linearTimeOne(int n) {
	int i = 0;
	while (i < n) {
		i++;
	}
}

// Increment by 3, the loop will finish 3 times faster.
// n=9: i=3, i=6, i=9
// Here: f(n) = n/3, we ignore constants(l.28), so:
// O(f(n)) = O(n)
void linearTimeTwo(int n) {
	int i = 0;
	while (i < n) {
		i = i + 3;
	}
}

// n work, done n times. n^2., if n=10, operations done are 100.
// Here, f(n) = n^2, so:
// O(f(n)) = O(n^2)
void quadraticTime(int n) {
	int executedLineCounter = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << format("{} {}", i, j) << endl;
			executedLineCounter++;
		}
	}
	cout << executedLineCounter << endl;

}

// Instead of j=0, now it's j=i.
// (n) + (n-1) + (n-2) + (n-3) + ... + 3 + 2 + 1 =>
// O(n(n+1)/2) = O(n^2/2 + n/2) =>
// O(n^2) | n^2 is the most dominant term, so it's big O of n^2.
void quadraticTimeTricky(int n) {
	int executedLineCounter = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			cout << format("{} {}", i, j) << endl;
			executedLineCounter++;
		}
	}
	cout << executedLineCounter << endl;
}

// Check indentation explanation below. in summarize:
// Multiply loops on DIFFERENT levels and add those that are on same level. 
// 
// Here, f(n) = n * (3n + 2n) = 5n^2, most dominant term is n^2, so
// O(n^2)
void anotherQuadraticTime(int n) {
	int i = 0;
	while (i < n) {
		int j = 0;
		while (j < 3 * n) {
			j++;
		}
		int k = 0;
		while (k < 2 * n) {
			k++;
		}
		i++;
	}
}

// Check indentation explanation below. in summarize:
// Multiply loops on DIFFERENT levels and add those that are on same level. 
// 3n * (40 + n^3/2) = 120n + 3n^4/2 , n^4 is the most dominant term, so
// O(f(n)) = O(n4)
void anotherQuadraticTimeTwo(int n) {
	int i = 0;
	while (i < 3 * n) {
		int j = 10;
		while (j < 50) {
			j++;
		}
		int k = 0;
		while (k < n * n * n) {
			k = k + 2;
		}
		i++;
	}
}

// Binary search, discarding one half of it.
// Works for sorted arrays, tho.
// f(n) = log2(n) | log2 -> log of base 2
// O(log(n)) | n - is the size of the vector/arr.
// 
// n = 10 (size of arr/vector)
// low = 0, high = 9, currentNum = 5, step 1
// low = 5, high = 9, currentNum = 8, step 2
// low = 8, high = 9, currentNum = 9, step 3
// low = 9, break loop.
// log2(10) => 3.32 ~ 3.
size_t logarithmicTime(const vector<int>& vector, int num) {
	size_t low = 0;
	size_t high = vector.size() - 1;

	while (low < high) {
		size_t mid = midpoint(low, high);
		int currentNum = vector[mid];

		if (currentNum == num) return mid;

		if (currentNum < num) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}

int main() {
	constantTime(100000);
	quadraticTime(10);
	quadraticTimeTricky(5);
	quadraticTimeTricky(10);
	quadraticTimeTricky(15);

	vector<int> vector = { 1,2,3,4,5,6,7,8,9,10 };
	logarithmicTime(vector, 11);

	anotherQuadraticTime(3);
}

// https://youtu.be/RBSGKlAvoiM?list=PLxfRCInfTk3Wk-IKiCWLIkBtVKrDv-2QG&t=858

// check indentation, if indented u multiply, if on same indentation level u add.
// while n  (n*)
//	while 3*n (3n+)
//	while 2*n (2n)
// n * (3n+2n) = 5n2, O(n2)


// same goes with for loop
// for n (n*)
//	for 2*n (+2n)
// n*2n = 2n2, O(n2)