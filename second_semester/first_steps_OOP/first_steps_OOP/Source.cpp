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

// encapsulate/hide the properties within this class, using private(now, we cannot access there properties outside the class):
private:
	// Encapsulated properties /private/hidden in the class/.
	string name;
	string company;
	int age;
	// How we access/interact with these properties, then?
	// We access them through public methods. Getter/Setter methods.

	// The idea of encapsulation is to make props/methods private, then
	// whoever wants to access these properties outside of the class, will
	// have to go through the exposed methods that have access to the properties.

public:
	// public properties
	// ....

	// public methods

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

	// What we can do with these methods(getters/setters)?
	// We can set special rules to interact with the encapsulated properties. One for the age.
	void setName(string employeeName) {
		name = employeeName;
	}

	string getName() {
		return name;
	}

	void setCompany(string employeeCompany) {
		company = employeeCompany;
	}

	string getCompany() {
		return company;
	}

	void setAge(int employeeAge) {
		// let's set an age rule for interacting with the encapsulated "age" property.

		// Check. Validation rule.
		if (employeeAge < 18) {
			// Not applying the changes if age < 18.
			return;
		}

		age = employeeAge;
	}

	int getAge() {
		return age;
	}

};

int main() {
	// 4 most important concepts of OOP.
	// 1. Encapsulation
	// 2. Abstraction
	// 3. Inheritance
	// 4. Polymorphism

	// Class objectName = Constructor(args...);
	Employee employee1 = Employee("Antoan", "Company", 22); // calling the class constructor. Constructing the object itself.
	employee1.introduce();

	Employee employee2 = Employee("Samantha", "Company", 19);
	employee2.introduce();

	employee1.setName("Tony");
	cout << format("{}\n", employee1.getName());

	employee1.setCompany("Fruteli");
	cout << format("{}\n", employee1.getCompany());

	employee1.setAge(11);
	cout << format("{}\n", employee1.getAge());
}