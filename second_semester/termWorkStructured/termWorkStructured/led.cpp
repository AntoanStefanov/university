#include "semiconductor.h"
#include "diode.h"
#include "led.h"

#include <iostream>
using std::string;
using std::cout;
using std::endl;

LED::LED() : Diode() {
	setElectricalPower(12);
	setBrightness(1.125);
}

LED::LED(string const& chemicalElement, double forwardVolts, int electricalPower, double brightness) : Diode(chemicalElement, forwardVolts) {
	setElectricalPower(electricalPower);
	setBrightness(brightness);
}

LED::LED(LED const& LED) : Diode(LED) {
	setElectricalPower(LED.getElectricalPower());
	setBrightness(LED.getBrightness());
}

LED::~LED() {
	cout << "LED Destructor." << endl;
}

void LED::setElectricalPower(int electricalPowerLED) {
	electricalPower = electricalPowerLED;
}

void LED::setBrightness(double brightnessLED) {
	brightness = brightnessLED;
}

int LED::getElectricalPower() const {
	return electricalPower;
}

double LED::getBrightness() const {
	return brightness;
}

void LED::showInfo() {
	cout << "LED -> Chemical Element: " << getChemicalElement() << ". Forward Volts: " << getForwardVolts() << "V. Electrical Power: " << getElectricalPower() << "W.Brightness: " << getBrightness() << "lm.\n";
}