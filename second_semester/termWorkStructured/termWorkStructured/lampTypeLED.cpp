#include "semiconductor.h"
#include "diode.h"
#include "led.h"
#include "lampTypeLED.h"

#include <iostream>
using std::string;
using std::cout;
using std::endl;

LampTypeLED::LampTypeLED() : LED::LED() {
	setLifespan(5);
	setEnergyClass("A");
}

LampTypeLED::LampTypeLED(string const& chemicalElement, double forwardVolts, int electricalPower, double brightness, int lifespan, char const* energyClass) : LED::LED(chemicalElement, forwardVolts, electricalPower, brightness) {
	setLifespan(lifespan);
	setEnergyClass(energyClass);
}

LampTypeLED::LampTypeLED(LampTypeLED const& lampTypeLED) : LED::LED(lampTypeLED) {
	setLifespan(lampTypeLED.getLifespan());
	setEnergyClass(lampTypeLED.getEnergyClass());
}

LampTypeLED::~LampTypeLED() {
	cout << "LampTypeLED Destructor" << endl;
}

void LampTypeLED::setLifespan(int lifespanLampTypeLED) {
	lifespan = lifespanLampTypeLED;
}

int LampTypeLED::getLifespan() const {
	return lifespan;
}

void LampTypeLED::setEnergyClass(char const* energyClassLampTypeLED) {
	energyClass = energyClassLampTypeLED;
}

char const* LampTypeLED::getEnergyClass() const {
	return energyClass;
}

void LampTypeLED::showInfo() {
	cout << "LampTypeLED -> Chemical Element: " << getChemicalElement() << ". Forward Volts: " << getForwardVolts() << "V.Electrical Power: " << getElectricalPower() << "W.Brightness: " << getBrightness() << "lm.Lifespan: " << getLifespan() << " years. Energy class: " << "'" << getEnergyClass() << "'" << ".\n";
}