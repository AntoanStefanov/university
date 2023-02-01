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

// static arrays are given as contiguous chunks of memory,
// meaning that your chunk of memory does NOT look like 
// a piece of cheese with a bunch of holes and gaps.
// it's contiguous, all the addresses are adjacent in your static array.

// https://youtu.be/RBSGKlAvoiM?list=PLxfRCInfTk3Wk-IKiCWLIkBtVKrDv-2QG&t=1259
// Static arr has N/A, because, static arrays are fixed-size containers.
// To append/delete/insert, means shrinking/expanding the arr,
// things which dynamic arrays do.

// !complexities
// !action      static arr    | dynamic arr   |      explain
// !access		 !O(1)	      |    !O(1)	  | !index-based arr[0]
// !search		 !O(n)	      |    !O(n)	  | !iterate over each element
// !insertion	 !N/A	      |    !O(n)	  | !reorder elements after insert(to right) https://youtu.be/RBSGKlAvoiM?list=PLxfRCInfTk3Wk-IKiCWLIkBtVKrDv-2QG&t=1301
// !appending    !N/A	      |    !O(1)	  | !arr[length] = element
// !deleting     !N/A	      |    !O(n)	  | !reorder elements after delete(to left)


// Dynamic arrays can grow and shrink in size AS NEEDED.
// 
// A = [34, 4]
// A.add(-7), A = [34, 4, -7] | grow in size
// A.remove(4), A = [34, -7] |  shrink is size

// How to implement a dynamic array? (std::vector does the same thing)
//	Using a static array. (not the only way, ofc)
// 
// 1. create a static array with initial capacity/non-zero capacity/.
// 
// 2. add elements to the underlying static array,
// keep trackof the number of elements.
// 
// 3. if adding another element will exceed the capacity of our internal static array,
// then create a new static array with twice the capacity,
// and copy the original elements into it, and add the new element.

// Dynamic array, with an initial capacity of 2,
// let's add some elements to it. 
// 
// If added element exceeds the arr size,
// we create new array with twice the size,
// copy the original elements into it,
// and then we add it.

// [empty, empty] | [7, empty] | [7, -9]
// [7, -9, 3, empty] | [7, -9, 3, 12]
// [7, -9, 3, 12, 5, empty, empty, empty]
// [7, -9, 3, 12, 5, -6, empty, empty]



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