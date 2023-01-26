#include <iostream>

// https://www.youtube.com/watch?v=etQX4Mme2f4 | https://www.geeksforgeeks.org/using-namespace-std-considered-bad-practice/

// using namespace std; // std -> standard namespace(used often)
// why above is bad ? Because the NAMESPACE contains a LOT of members(variables, functions, ...),
// and INCLUDING THEM ALL, so we could easily OVERWRITE some of them BY MISTAKE! And then bugs come along.

// string, cout, endl are members(variables, functions) of std namespace. There are more ofc.
// in order to access these members we should call them like this: std::string or 'using namespace std' which is a bad practice.

// RECOMMENDED WAY TO USE STD. We could also access these members individually:
using std::cout;
using std::endl;
using std::string;

// another way is std::string, std::cout,
// Everytime we need it, but that's a bit annoying, so the recommended way is cool.
// Adding only the ones we need. 'using std::cout', 'using std::endl' 

namespace namespace1 {
	// Read main fn comments. house 1 -> here we can have variable called name. 
	string name = "David";
	int age = 25;
}

namespace namespace2 {
	// Read main fn comments. house 2 -> here we can have variable called name.
	string name = "David";

}

// https://stackoverflow.com/questions/16995914/what-is-the-default-namespace -> sayHi fn is in the global namespace.
// 	cout << ::sayHi(); is same as cout << sayHi();
string sayHi() {
	return "Hi";
}

// sayHi(); error ! not in main function!

// if we use 'using namespace std;', our function will overwrite the one in the namespace. 
// and if we expect the function to behave one way, and it does NOT. Big problem.
//int abs() {
//	return 5;
//}

int main() {

	// string name = "David";
	// string name = "David";
	// collision. can't have 2 same variable names with same name. Like 2 brother named "David", and their mom calls them.
	// the house is their namespace. the brother names are the 2 variable, mom is the compiler.
	// "David" refers to the variable name, not its value.
	// https://www.youtube.com/watch?v=etQX4Mme2f4 -> namespaces (brothers example is said here.)
	// cout << name;

	// no collision. even though these variables have the same name(name), they are in different namespaces(houses).
	cout << namespace1::name << endl;
	cout << namespace2::name << endl;
	cout << namespace1::age << endl;
}