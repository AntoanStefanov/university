#include "Semiconductor.h"
#include "Diode.h"
#include <string>
#include <iostream>

using namespace std;

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
	std::cout << "Diode Destructor." << std::endl;
}

void Diode::setChemicalElement(std::string const& diodeChemicalElement) {
	chemicalElement = diodeChemicalElement;
}

std::string Diode::getChemicalElement() const {
	return chemicalElement;
}

void Diode::setForwardVolts(double diodeForwardVolts) {
	forwardVolts = diodeForwardVolts;
}

double Diode::getForwardVolts() const {
	return forwardVolts;
}

void Diode::showInfo() {
	std::cout << "Diode -> Chemical Element: " << getChemicalElement() << ". Forward Volts: " << getForwardVolts() << "V.\n";
}