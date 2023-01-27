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
};

int main() {
	// in programming, polymorphism describes the ability of an object/method,
	// to have many forms.
	// 
	// most common use of polymorphism is when,
	// a type parent class pointer, points to a child class object.

	Developer dev1 = Developer("Tony", "Fruteli", 22, "JS");
	dev1.fixBug();
	dev1.introduce();

	Teacher teacher1 = Teacher("Rony", "Amazon", 32, "Software development");
	teacher1.prepareLesson();
	teacher1.askForPromotion();

}