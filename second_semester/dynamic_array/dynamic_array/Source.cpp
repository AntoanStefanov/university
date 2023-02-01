#include <iostream>
#include <format>
#include <array>

using std::string;
using std::cout;
using std::endl;
using std::format;
using std::array;

// https://youtu.be/RBSGKlAvoiM?list=PLxfRCInfTk3Wk-IKiCWLIkBtVKrDv-2QG&t=1021
// 
// Static Array:
// A static array is a fixed length container containing n elements,
// indexable from the range [0, n-1].

// indexable?
// meaning that each slot/index in the array can be referenced with a number.

// static arrays are given as contiguous chunks of memory.
// 
// meaning that your chunk of memory does NOT look like 
// a piece of cheese with a bunch of holes and gaps.
// it's contiguous, all the addresses are adjacent in your static array.


// complexities
// !action      static arr    | dynamic arr   |      explain
// !access		 O(1)	      |    O(1)		  | !index-based arr[0]
// !search		 O(n)	      |    O(n)		  | !iterate over each element
// !insertion	 N/A	      |    O(n)		  | !reorder indexes after insert
// !appending    N/A	      |    O(1)		  | !arr[length] = element
// !deleting     N/A	      |    O(n)		  | !reorder indexes after delete

// overloaded fn. Same name different paramaters.
void swap(int& x, int& y, const int(&arr)[2]) {
	int z = x;
	x = y;
	y = z;
	cout << arr;
}

void swap(int* x, int* y, const int* arr) {
	int z = *x;
	*x = *y;
	*y = z;
	cout << arr;

}

// if u pass arg, with *arg(dereference), param should be the type of the pointed object
// fn(*CstyleArr), *CstyleArr = &CstyleArr[0], so int.

// if u pass arg, with &a(reference), param should be pointer
// fn(&a), &a = memory address(reference), so int*.

// if u pass arg, a, param could be int a, or int& a
// if param is int a, function creates a copy of the arg.
// if param is int* a, function works with the same passed arg.


// with NO &, the function creates a copy, which, if mutated, does NOT
// effect outer object.
// 
// with & arr, we have the same object as outside the function./reference/,
// just the same as how JS works with the objects.
void swap(int& x, int& y, const array<int, 2>& arr) {
	int z = x;
	x = y;
	y = z;
	cout << arr.size();

}

int main() {
	int a = 45;
	int b = 35;

	int CstyleArr[2];

	array<int, 2> stdArr = { 1, 2 };
	cout << "Before Swap\n";
	cout << "a = " << a << " b = " << b << "\n";

	swap(a, b, CstyleArr);
	swap(&a, &b, CstyleArr); // arr passed to pointer is same as passing &arr[0], the address of first el.

	swap(a, b, stdArr);


	cout << "After Swap with pass by reference\n";
	cout << "a = " << a << " b = " << b << "\n";
}