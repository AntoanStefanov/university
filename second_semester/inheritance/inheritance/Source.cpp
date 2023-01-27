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
	string company;
	int age;

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

int main() {
	Employee employee1 = Employee("Antoan", "Company", 30);
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