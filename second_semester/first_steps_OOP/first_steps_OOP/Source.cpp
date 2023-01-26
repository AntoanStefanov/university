#include <iostream>
#include <format>

// using namespace std; -> bad practice. Instead, include only the things u need or write everytime "std::...."
// https://www.youtube.com/watch?v=etQX4Mme2f4|https://www.geeksforgeeks.org/using-namespace-std-considered-bad-practice/

using std::string;
using std::cout;
using std::endl;
using std::format;

// used JS naming convetions.
// class -> PascalCase (ExampleClass)
// members(properties and methods) -> camelCase (exampleVariable)

// class Employee { body }
class Employee {
	// EVERYTHING INSIDE CLASS IN C++ is PRIVATE BY DEFAULT !!
	// we have 3 access modifiers: public, protected, private. (private by default).
	// 
	// private: NOT ACCESSIBLE OUTSIDE THE CLASS. (by default)
	// protected: NOT ACCESSIBLE OUTSIDE THE CLASS AND ITS DERIVATIVES CLASSES.
	// public: ACCESSIBLE EVERYWHERE.
public:

	// properties
	string name;
	string company;
	int age;

	// methods

	// 1. constructor method does NOT have a return type.
	// 2. constructor has the same name as the class that it belongs to. /class Employee -> constructor Employee/.
	// 3. constructor must be public./at this level in our knowledge./
	Employee(string employeeName, string employeeCompany, int employeeAge) {
		// assign parameters to the properties.
		name = employeeName;
		company = employeeCompany;
		age = employeeAge;
	}

	void introduce() {
		cout << format("Name - {}. Company - {}. Age - {}", name, company, age) << endl;
	}

};

int main() {
	// Class objectName = Constructor(args...);
	Employee employee1 = Employee("Antoan", "Company", 22); // calling the class constructor. Constructing the object itself.
	employee1.introduce();

	Employee employee2 = Employee("Samantha", "Company", 19);
	employee2.introduce();



}