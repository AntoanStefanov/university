#include <iostream>

// using namespace std; -> bad practice. Instead do include the things u need or write everytime "std::...."
// https://www.youtube.com/watch?v=etQX4Mme2f4|https://www.geeksforgeeks.org/using-namespace-std-considered-bad-practice/

using std::string;
using std::cout;
using std::endl;

// used JS naming convetions.
// class -> PascalCase (ExampleClass)
// members -> camelCase (exampleVariable)

// class Employee { body }
class Employee {
	// EVERYTHING INSIDE CLASS IN C++ is PRIVATE BY DEFAULT !!
	// we have 3 access modifiers: public, protected, private. (private by default).
	// 
	// private: NOT ACCESSIBLE OUTSIDE THE CLASS.
	// protected: NOT ACCESSIBLE OUTSIDE THE CLASS AND ITS DERIVATIVES CLASSES.
	// public: ACCESSIBLE EVERYWHERE.
	// 
	// Add Members of the class (members are its attributes/properties/ and its behaviour/methods/)
	string name;
	string company;
	int age;
	// above are 3 attributes(properties)
};

int main() {
	// how do we create a variable of type int?
	int x = 3; // data type | variable name = value;
	// above, we created a variable of type int.

	// how do we create an object/instance of this class?
	// same goes for a variable of type Employee /int example above/

	// a variable of type Employee
	Employee employee1; // data type(user-defined type) | variable name
	// above, we successfully have created a variable of type Employee. 
	// (employee1 is an object/instance of class Employee)
	employee1.name
}