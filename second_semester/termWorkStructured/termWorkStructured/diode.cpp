#include "semiconductor.h"
#include "diode.h"

#include <iostream>

using std::string;
using std::cout;
using std::endl;

Diode::Diode() {
	setChemicalElement("Silicon");
	setForwardVolts(0.7);
}

Diode::Diode(string const& chemicalElement, double forwardVolts) {
	setChemicalElement(chemicalElement);
	setForwardVolts(forwardVolts);
}

Diode::Diode(Diode const& diode) {
	setChemicalElement(diode.getChemicalElement());
	setForwardVolts(diode.getForwardVolts());
}

Diode::~Diode() {
	cout << "Diode Destructor." << endl;
}

void Diode::setChemicalElement(string const& diodeChemicalElement) {
	chemicalElement = diodeChemicalElement;
}

string Diode::getChemicalElement() const {
	return chemicalElement;
}

void Diode::setForwardVolts(double diodeForwardVolts) {
	forwardVolts = diodeForwardVolts;
}

double Diode::getForwardVolts() const {
	return forwardVolts;
}

void Diode::showInfo() {
	cout << "Diode -> Chemical Element: " << getChemicalElement() << ". Forward Volts: " << getForwardVolts() << "V.\n";
}