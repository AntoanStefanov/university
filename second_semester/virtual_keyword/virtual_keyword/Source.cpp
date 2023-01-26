#include <iostream>
#include <format>

using std::string;
using std::cout;
using std::endl;
using std::format;

// https://www.geeksforgeeks.org/virtual-function-cpp/
// https://stackoverflow.com/questions/2652198/difference-between-a-virtual-function-and-a-pure-virtual-function

#include<iostream>
using namespace std;

class base {
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

class derived : public base {
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
	base* basePointer; // define pointer
	derived derivedClass;
	basePointer = &derivedClass; // set pointer

	// Virtual function, binded at runtime
	basePointer->print(); // this calls the overwritten method

	// Non-virtual function, binded at compile time
	basePointer->show(); // this calls the initial method

	return 0;
}