#include <iostream>
#include <format>

// https://stackoverflow.com/questions/2282725/c-what-is-for -> :: double colon
using std::string;
using std::string_view;
using std::cout;
using std::endl;
using std::format;

class AbstractEmployee {
	// The reason, why the non-virtual destructor must be public.
	// Becomes inaccessible, in derived class.
	// https://stackoverflow.com/questions/13704835/why-i-got-c4624base-class-destructor-is-inaccessible-when-using-composition-in
public:
	virtual ~AbstractEmployee() = default; // https://rules.sonarsource.com/cpp/RSPEC-1235
	virtual void askForPromotion() = 0; // pure virtual function.
};

// https://cplusplus.com/forum/beginner/235722/ -> : single colon
// https://rules.sonarsource.com/cpp/RSPEC-5965 -> "private" keyword.
class Employee : private AbstractEmployee {
private:
	string name;
	string company; // https://rules.sonarsource.com/cpp/RSPEC-3656, no protected members.
	int age;

public:
	Employee(string const& employeeName, string const& employeeCompany, int employeeAge) :
		name(employeeName),
		company(employeeCompany),
		age(employeeAge)

	{
		// Do not assign data members in constructor: https://rules.sonarsource.com/cpp/RSPEC-3230
		// name = employeeName;
		// company = employeeCompany;
		// age = employeeAge;
	}

	void introduce() {
		cout << format("Name - {}. Company - {}. Age - {}", name, company, age) << endl;
	}

	void askForPromotion() override {
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

	// https://rules.sonarsource.com/cpp/RSPEC-6009 -> string_view
	void setName(string_view const& employeeName) {
		name = employeeName;
	}

	string getName() const {
		return name;
	}

	void setCompany(string_view const& employeeCompany) {
		company = employeeCompany;
	}

	string getCompany() const {
		return company;
	}

	void setAge(int employeeAge) {
		if (employeeAge < 18) {
			return;
		}

		age = employeeAge;
	}

	int getAge() const {
		return age;
	}

};

class Developer : public Employee {
private:
	// encapsulation
	string programmingLanguage;

public:
	// https://rules.sonarsource.com/cpp/RSPEC-1238 -> const&
	Developer(string const& devName, string const& devCompany, int devAge, string const& devProgrammingLanguage) :
		Employee(devName, devCompany, devAge),
		programmingLanguage(devProgrammingLanguage) {}

	// https://rules.sonarsource.com/cpp/RSPEC-5817 - const
	void fixBug() const {
		cout << format("{} from {} company is fixing a bug.\n", getName(), getCompany());
	}

	// same method is implemented in base class.
	// https://rules.sonarsource.com/cpp/RSPEC-3471
	void work() override {
		cout << format("{} is coding with {}.\n", getName(), programmingLanguage);
	}

	// getter
	string getProgrammingLanguage() const {
		return programmingLanguage;
	}
};

class Teacher : public Employee {
private:
	string subject;

public:
	Teacher(string const& employeeName, string const& employeeCompany, int employeeAge, string_view const& teacherSubject) :
		Employee(employeeName, employeeCompany, employeeAge),
		subject(teacherSubject) {}

	void prepareLesson() {
		cout << format("Lesson for {} prepared. By {}, working in {}.\n", subject, getName(), getCompany());
	}

	// same method is implemented in base class.
	void work() override {
		cout << format("{} is teaching a lesson for {}.\n", getName(), subject);
	}
};

int main() {
	int i = 3;
	// https://rules.sonarsource.com/cpp/RSPEC-5350 -> const&
	int const& ref = i;
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

	// https://rules.sonarsource.com/cpp/RSPEC-5827 -> auto
	auto dev1 = Developer("Tony", "Fruteli", 22, "JS");
	auto teacher1 = Teacher("Rony", "Amazon", 32, "Software development");

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