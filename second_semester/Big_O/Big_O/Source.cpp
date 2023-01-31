#include <iostream>
#include <format>

using std::string;
using std::cout;
using std::endl;
using std::format;

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

// We ignore constants, infinity(n) + 7(c) is again infinity.
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

// f(n) = n
// O(f(n)) = O(n)
void linearTimeOne(int n) {
	int i = 0;
	while (i < n) {
		i++;
	}
}


int main() {
	constantTime(100000);
}