#include <iostream>
#include <format>

using std::string;
using std::cout;
using std::endl;
using std::format;

class Base
{
public:
	int b;
	void Display()
	{
		cout << "Base: Non-virtual display." << endl;
	};
	virtual void vDisplay()
	{
		cout << "Base: Virtual display." << endl;
	};
};

class Derived : public Base
{
public:
	int d;
	void Display()
	{
		cout << "Derived: Non-virtual display." << endl;
	};
	virtual void vDisplay()
	{
		cout << "Derived: Virtual display." << endl;
	};
};

int main() {
	// https://stackoverflow.com/questions/11067975/overriding-non-virtual-methods
	Base ba;
	Derived de;

	ba.Display();
	ba.vDisplay();
	de.Display();
	de.vDisplay();

	// answer
	Base* b = &ba;
	b->Display();
	b->vDisplay();
	b = &de;
	b->Display();
	b->vDisplay();
}

// So, just to be sure, I can define a method in base class,
// and override it in derived class, irrespective of declaring it as virtual or not.
// The only difference is that if a base pointer points to a derived class object,
// then calling that method will call the base class' method if it is not virtual, and the derived class' method if it is virtual.

// Me: also note that if we delete 'virtual' keyword in line 31 (in derived class),
// the derived method will still be called, bcs it's still virtual in the base class.

// IN OTHER WORDS -> NON-VIRTUAL FUNCTIONS, WHEN INHERITED WILL DO A LOOKUP from derived to base,
// to check a method.
// 
// IF pointer of class base points to a derived class,
// VIRTUAL FUNCTIONS, WHEN INHERITED WILL DO A LOOKDOWN FROM BASE CLASS TO DERIVED.
// THAT's THE REAL NATURE OF POLYMORPHISM