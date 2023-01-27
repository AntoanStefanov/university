#include <iostream>
#include <format>

using std::string;
using std::cout;
using std::endl;
using std::format;

// https://www.simplilearn.com/tutorials/cpp-tutorial/virtual-function-in-cpp
// https://www.geeksforgeeks.org/virtual-function-cpp/
// https://stackoverflow.com/questions/2652198/difference-between-a-virtual-function-and-a-pure-virtual-function

class Base {
public:
	virtual void print()
	{
		cout << "print base class\n";
	}

	void show()
	{
		cout << "show base class\n";
	}
};

class Derived : public Base {
public:
	void print()
	{
		cout << "print derived class\n";
	}

	void show()
	{
		cout << "show derived class\n";
	}
};

int main()
{
	Base* basePointer; // define pointer with data type "base" class!
	Derived derivedClass;
	basePointer = &derivedClass; // set pointer with data type "base", but value is derivedClass address/reference.

	// Virtual function, binded at runtime.
	// And because it's virtual fn (in base), it calls the method on the pointer VALUE which is "derivedClass" reference.
	// this calls the derived method.
	basePointer->print();

	// Non-virtual function, binded at compile time
	// Because it is NOT virtual(in base), it calls the method on the pointer DATA TYPE, which is "base".
	// this calls the base method.
	basePointer->show();
}