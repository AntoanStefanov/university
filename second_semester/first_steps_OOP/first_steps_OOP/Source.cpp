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

// https://youtu.be/wN0x9eZLix4?t=3068 -> what is interface/abstractEmployee/ purpose.

// Interface behavior using abstract class (Java, C# interface simulation)
// https://www.w3schools.com/java/java_interface.asp
class AbstractEmployee { // it could be name iEmployee for interfaceEmployee)
	// https://stackoverflow.com/questions/2652198/difference-between-a-virtual-function-and-a-pure-virtual-function
	// whoever class inherits this interface, should implement the methods defined,
	// as virtual ....... = 0; . Otherwise they itself become abstract classes.
	virtual void askForPromotion() = 0; // pure virtual function |
	// Showing that Employee class has a askForPromotion method, metaphorically,
	// it shows that the phone has a camera button.
	// others can use this method, without knowing of that functionality implemenation:
	// Abstraction.

	// https://www.geeksforgeeks.org/virtual-function-cpp/ this is just for virtual function, with NO '= 0' at the end.
};


// class Employee { body }
class Employee : AbstractEmployee {
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

	// mandatory overwrite/implementation, otherwise this class becomes an abstract class too.
	// Check AbstractEmployee abstract class. askForPromotion method is a pure virtual function.
	void askForPromotion() {
		// imagine complex implemenation.
		if (age < 30) {
			cout << format("You do NOT get a promotion, {}\n", name);
			return;
		}
		cout << format("You get a promotion, {}\n", name);
	}

	// Setters/Getters
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
	// 
	// --- Hiding complex implementation behind an action/interface that makes those things look simple.
	// Button click for phone call is the action/interface that hides a complex implementation.
	// You don't need to know about the complex implemention in order to use the phone interface.
	// Hiding the complexity and creating a simple interface for user-usage is called 'Abstraction'.
	// In C++, we can simulate the behavior of interface by using abstract class. (In Java and C# have concept of interface).
	// 
	// 3. Inheritance
	// 4. Polymorphism

	// Class objectName = Constructor(args...);
	Employee employee1 = Employee("Antoan", "Company", 30); // calling the class constructor. Constructing the object itself.
	employee1.introduce();
	employee1.askForPromotion();


	Employee employee2 = Employee("Samantha", "Company", 19);
	employee2.introduce();
	employee2.askForPromotion();

	employee1.setName("Tony");
	cout << format("{}\n", employee1.getName());

	employee1.setCompany("Fruteli");
	cout << format("{}\n", employee1.getCompany());

	employee1.setAge(11);
	cout << format("{}\n", employee1.getAge());
}