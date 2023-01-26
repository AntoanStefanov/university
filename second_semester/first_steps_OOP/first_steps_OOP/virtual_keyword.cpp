
// CPP program to illustrate
// concept of Virtual Functions

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
	basePointer->print();

	// Non-virtual function, binded at compile time
	basePointer->show();

	return 0;
}