#include "semiconductor.h"
#include "transistor.h"

#include <iostream>

using std::string;
using std::cout;
using std::endl;

Transistor::Transistor() {
	setType("BJT");
	setFunctionality("amplify");
}

Transistor::Transistor(string const& type, string const& functionality) {
	setType(type);
	setFunctionality(functionality);
}

Transistor::Transistor(Transistor const& transistor) {
	setType(transistor.getType());
	setFunctionality(transistor.getFunctionality());
}

Transistor::~Transistor() {
	cout << "Transistor Destructor." << endl;
}

void Transistor::setType(const string& transistorType) {
	type = transistorType;
}

string Transistor::getType() const {
	return type;
}

void Transistor::setFunctionality(const string& transistorFunctionality) {
	functionality = transistorFunctionality;
}

string Transistor::getFunctionality() const {
	return functionality;
}

void Transistor::showInfo() {
	cout << "Transistor -> Functionality: " << getFunctionality() << ". Type: " << getType() << ".\n";
}