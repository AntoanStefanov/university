#include <iostream>
#include <format>

using std::string;
using std::cout;
using std::endl;
using std::format;

class AbstractEmployee {
	virtual void askForPromotion() = 0; // pure virtual function.
};

class Employee : AbstractEmployee {

private:
	string name;
	int age;

protected:
	string company;

public:
	Employee(string employeeName, string employeeCompany, int employeeAge) {
		name = employeeName;
		company = employeeCompany;
		age = employeeAge;
	}

	void introduce() {
		cout << format("Name - {}. Company - {}. Age - {}", name, company, age) << endl;
	}

	void askForPromotion() {
		if (age < 30) {
			cout << format("You do NOT get a promotion, {}\n", name);
			return;
		}
		cout << format("You get a promotion, {}\n", name);
	}

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
		if (employeeAge < 18) {
			return;
		}

		age = employeeAge;
	}

	int getAge() {
		return age;
	}

};

// inheritance
// Employee -> parent class /base/superclass/
// Developer -> child class /derived/subclass/

class Developer : Employee {
private:
	// encapsulation
	string programmingLanguage;
public:
	Developer(string devName, string devCompany, int devAge, string devProgrammingLanguage)
		:Employee(devName, devCompany, devAge) // calling the super class constructor.
	{
		programmingLanguage = devProgrammingLanguage;
	}

	void fixBug() {
		// accessing the protected prop, easily. Using getter for the private prop, otherwise -> error.
		cout << format("{} from {} company is fixing a bug.\n", getName(), company);
	}

	// getter
	string getProgrammingLanguage() {
		return programmingLanguage;
	}


};

int main() {
	Employee employee1 = Employee("John", "Company", 30);
	employee1.introduce();
	employee1.askForPromotion();

	Developer employee2 = Developer("Tony", "Fruteli", 22, "JS");
	employee2.fixBug();

	// employee2.introduce(); // | not working?

	// https://youtu.be/wN0x9eZLix4?t=3490
	// Employee emp;// -> Error "no default constructor exists for class "Employee" "
	// Developer employee2; // Error "no default constructor exists for class "Developer" "
}