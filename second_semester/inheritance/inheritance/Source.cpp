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

// In order to access the methods of the super class through Developer objects /ex. dev1.introduce(); /
// we need to change the inheritance from private(default) to public.

class Developer : public Employee {
private:
	// encapsulation
	string programmingLanguage;
public:
	// https://cplusplus.com/forum/beginner/235722/ -> : single colon
	// https://en.cppreference.com/w/cpp/language/constructor
	// https://stackoverflow.com/questions/120876/what-are-the-rules-for-calling-the-base-class-constructor
	// https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/
	Developer(string devName, string devCompany, int devAge, string devProgrammingLanguage) : // <----- : (single colon)
		Employee(devName, devCompany, devAge) // calling the super class constructor.
	{
		programmingLanguage = devProgrammingLanguage;
	}

	void fixBug() {
		// accessing the protected prop, easily. Using getter to access the private prop "name", otherwise -> error.
		cout << format("{} from {} company is fixing a bug.\n", getName(), company);
	}

	// getter
	string getProgrammingLanguage() {
		return programmingLanguage;
	}


};

// Another child class of Employee (C++ supports multiple inheritance)
class Teacher : public Employee {
private:
	string subject;

public:
	// https://cplusplus.com/forum/beginner/235722/#msg1056281 -> : (single colon)
	Teacher(string employeeName, string employeeCompany, int employeeAge, string teacherSubject) : // <-- single colon
		Employee(employeeName, employeeCompany, employeeAge)
	{
		subject = teacherSubject;
	}

	void prepareLesson() {
		cout << format("Lesson for {} prepared. By {}, working in {}.\n", subject, getName(), company);
	}
};


class HistoryTeacher : public Teacher {
private:
	int lessonNumber = 1;

public:
	// https://cplusplus.com/forum/beginner/235722/#msg1056281 -> : (single colon)
	HistoryTeacher(string employeeName, string employeeCompany, int employeeAge, string teacherSubject, int lessonNum) : // <-- single colon
		Teacher(employeeName, employeeCompany, employeeAge, teacherSubject)
	{
		lessonNumber = lessonNum;
	}

	void showLessonNum() {
		cout << format("Lesson number {} is ready, created by {}, working in {}\n", lessonNumber, getName(), company);
	}
};

int main() {
	Employee employee1 = Employee("John", "Company", 30);
	employee1.introduce();
	employee1.askForPromotion();

	Developer dev1 = Developer("Tony", "Fruteli", 22, "JS");
	dev1.fixBug();

	dev1.introduce(); // we have access to the method, bcs the inheritance is public.

	Teacher teacher1 = Teacher("Rony", "Amazon", 32, "Software development");
	teacher1.prepareLesson();
	teacher1.askForPromotion();

	HistoryTeacher hisotryTeacher1 = HistoryTeacher("Jack", "Amazon", 32, "Software development", 1);
	hisotryTeacher1.showLessonNum();

	// https://youtu.be/wN0x9eZLix4?t=3490
	// Employee emp;// -> Error "no default constructor exists for class "Employee" "
	// Developer employee2; // Error "no default constructor exists for class "Developer" "
}