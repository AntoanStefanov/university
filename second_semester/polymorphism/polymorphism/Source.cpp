#include <iostream>
#include <format>

// https://stackoverflow.com/questions/2282725/c-what-is-for -> :: double colon
using std::string;
using std::cout;
using std::endl;
using std::format;

class AbstractEmployee {
	virtual void askForPromotion() = 0; // pure virtual function.
};

// https://cplusplus.com/forum/beginner/235722/ -> : single colon
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

	virtual void work() {
		// only with pointer:
		// this is a virtual function and when invoked,
		// it checks for implementation down through the inheritance chain.
		// most derived version of this method is going to be called.
		// If there is no other implementation, execute this one.
		cout << format("{} is performing tasks.\n", name);
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

class Developer : public Employee {
private:
	// encapsulation
	string programmingLanguage;

public:
	Developer(string devName, string devCompany, int devAge, string devProgrammingLanguage) :
		Employee(devName, devCompany, devAge)
	{
		programmingLanguage = devProgrammingLanguage;
	}

	void fixBug() {
		cout << format("{} from {} company is fixing a bug.\n", getName(), company);
	}

	// same method is implemented in base class.
	void work() {
		cout << format("{} is coding with {}.\n", getName(), programmingLanguage);
	}

	// getter
	string getProgrammingLanguage() {
		return programmingLanguage;
	}


};

class Teacher : public Employee {
private:
	string subject;

public:
	Teacher(string employeeName, string employeeCompany, int employeeAge, string teacherSubject) :
		Employee(employeeName, employeeCompany, employeeAge)
	{
		subject = teacherSubject;
	}

	void prepareLesson() {
		cout << format("Lesson for {} prepared. By {}, working in {}.\n", subject, getName(), company);
	}

	// same method is implemented in base class.
	void work() {
		cout << format("{} is teaching a lesson for {}.\n", getName(), subject);
	}
};

int main() {
	int i = 3;
	int& ref = i;
	cout << ref;
	// in programming, polymorphism describes the ability of an object/method,
	// to have many forms.

	// https://stackoverflow.com/questions/2391679/why-do-we-need-virtual-functions-in-c
	// https://stackoverflow.com/questions/22146094/why-should-i-use-a-pointer-rather-than-the-object-itself
	// https://www.geeksforgeeks.org/pointers-vs-references-cpp/
	// https://stackoverflow.com/questions/21215409/does-c-pass-objects-by-value-or-reference
	// https://stackoverflow.com/questions/10269355/c-reasons-for-passing-objects-by-value
	// most common use of polymorphism is when,
	// a "parent class" type pointer, points to a child class object.

	Developer dev1 = Developer("Tony", "Fruteli", 22, "JS");
	Teacher teacher1 = Teacher("Rony", "Amazon", 32, "Software development");

	// Assigning a dev1 reference to a pointer with type Employee.
	Employee* employeePointer1 = &dev1;

	// Assigning a teacher1 reference to a pointer with type Employee.
	Employee* employeePointer2 = &teacher1;

	// "->" accessing members using a pointer.
	// if method is not virtual, the parent class method is called.
	// if method is virtual, the child class method is called.
	employeePointer1->work();
	employeePointer2->work();
}