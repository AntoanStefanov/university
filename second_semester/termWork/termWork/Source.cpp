#include <iostream>
#include <format>

using std::string;
using std::cout;
using std::endl;
using std::format;

class Semiconductor {
public:
	Semiconductor();
	Semiconductor(string const&, int);
	Semiconductor(Semiconductor const&);
	~Semiconductor();
	void showInfo();

	void setModel(const string&);
	string getModel() const;

	void setYear(int);
	int getYear() const;

private:
	string model;
	int year;
};

class Diode : public Semiconductor {
public:
	Diode();
};

int main() {
	Semiconductor sem1("RR2", 2023);
	Semiconductor semCopy(sem1);
	sem1.showInfo();
	semCopy.showInfo();
}

Semiconductor::Semiconductor() {
	model = "UNDEFINED";
	year = 0000;
}

Semiconductor::Semiconductor(const string& semiconductorModel, int semiconductorYear) {
	model = semiconductorModel;
	year = semiconductorYear;
}

Semiconductor::Semiconductor(Semiconductor const& semiconductorObject) {
	model = semiconductorObject.model;
	year = semiconductorObject.year;
};

Semiconductor::~Semiconductor() {
	cout << "Semiconductor Destructor" << endl;
}

void Semiconductor::showInfo() {
	cout << format("Semiconductor: {}-{}", model, year) << endl;
}

void Semiconductor::setModel(const string& semiconductorModel) {
	model = semiconductorModel;
}

string Semiconductor::getModel() const {
	return model;
}

void Semiconductor::setYear(const int semiconductorYear) {
	year = semiconductorYear;
}

int Semiconductor::getYear() const {
	return year;
}