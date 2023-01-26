#include <iostream>

using namespace std;

namespace namespace1 {
	// Read main fn comments. house 1 -> here we can have "David". 
	string name = "David";
}

namespace namespace2 {
	// Read main fn comments. house 2 -> here we can have "David".
	string name = "David";

}

// https://stackoverflow.com/questions/16995914/what-is-the-default-namespace -> sayHi fn is in the global namespace.
// 	cout << ::sayHi(); is same as 	cout << sayHi();
string sayHi() {
	return "Hi";
}

// sayHi(); error ! not in main function!

int main() {

	// string name = "David";
	// string name = "David";
	// collision. can't have 2 same variable names with same name. Like 2 brother named "David", and their mom calls them.
	// the house is their namespace. the brother names are the 2 variable, mom is the compiler.
	// "David" refers to the variable name, not its value.
	// https://www.youtube.com/watch?v=etQX4Mme2f4 -> namespaces (brothers example is said here.)
	// cout << name;

	// no collision. even though these variables have the same name(name), they are in different namespaces(houses).
	cout << namespace1::name;
	cout << namespace2::name;
}