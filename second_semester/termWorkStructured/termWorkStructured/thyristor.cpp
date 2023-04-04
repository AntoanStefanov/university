#include "semiconductor.h"
#include "thyristor.h"

#include <iostream>
using std::string;
using std::cout;
using std::endl;

Thyristor::Thyristor() {
	setMode("OFF");
	setImax(30.5);
}

Thyristor::Thyristor(string const& mode, double Imax) {
	setMode(mode);
	setImax(Imax);
}

Thyristor::Thyristor(Thyristor const& thyristor) {
	setMode(thyristor.getMode());
	setImax(thyristor.getImax());
}

Thyristor::~Thyristor() {
	cout << "Thyristor Destructor." << endl;
}

void Thyristor::setMode(const string& thyristorMode) {
	mode = thyristorMode;
}

string Thyristor::getMode() const {
	return mode;
}

void Thyristor::setImax(double thyristorImax) {
	Imax = thyristorImax;
}

double Thyristor::getImax() const {
	return Imax;
}

void Thyristor::showInfo() {
	cout << "Thyristor -> MODE: " << getMode() << ". Imax: " << getImax() << "A.\n";
}