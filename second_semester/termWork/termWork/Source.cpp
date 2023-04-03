#include <iostream>
#include <format>

using std::string;
using std::cout;
using std::endl;
using std::format;

// Abstract class / Interface
class Semiconductor {
public:
	virtual ~Semiconductor();
	virtual void showInfo() = 0; // pure virtual fn. ... = 0
};

class Diode : public Semiconductor {
public:
	Diode();
	Diode(string const&, double);
	Diode(Diode const&);
	~Diode() override; // same as "virtual void ~Diode()"

	void setChemicalElement(string const&);
	string getChemicalElement() const;

	void setForwardVolts(double);
	double getForwardVolts() const;

	void showInfo() override; // same as "virtual void showInfo()"

private:
	string chemicalElement; // silicon, germanium, etc...
	double forwardVolts; // 0.3V, 0.7V -> so that current can rise.
};

class LED : public Diode {
public:
	LED();
	LED(string const&, double, int, double);
	LED(LED const&);
	~LED() override;

	void setElectricalPower(int);
	int getElectricalPower() const;

	void setBrightness(double);
	double getBrightness() const;

	void showInfo() override;

private:
	int electricalPower; // 12W, 15W, 20W ... etc
	double brightness; // Lumens -> 12W -> 1,125lm(lumens)
};

// Two types of LEDs are available, a lamp type (leaded) and a chip type (surface mount). https://www.google.com/search?q=type+of+LED+diode+&sxsrf=APwXEdeZA52lnvnN9m_X9HDUnSXj-QGimg%3A1680378742879&ei=dosoZJuXNYq_xc8PnNKOuAg&ved=0ahUKEwibqrrQuon-AhWKX_EDHRypA4cQ4dUDCA8&uact=5&oq=type+of+LED+diode+&gs_lcp=Cgxnd3Mtd2l6LXNlcnAQAzIGCAAQBxAeMggIABAIEAcQHjoKCAAQRxDWBBCwAzoKCAAQigUQsAMQQzoFCAAQgAQ6BggAEBYQHjoICAAQFhAeEA86BwgAEIAEEBM6CAgAEBYQHhATOgoIABAWEB4QDxATOgkIABCABBANEBM6CggAEAgQHhANEBM6CAgAEAcQHhAPOgcIABCABBANOgoIABAIEAcQHhAPOgYIABAIEB5KBAhBGABQlUtYutQBYJTVAWgFcAF4AIABcYgBsQ6SAQQ3LjExmAEAoAEByAEKwAEB&sclient=gws-wiz-serp
class LampTypeLED : public LED {
public:
	LampTypeLED();
	LampTypeLED(string const&, double, int, double, int, char const*);
	LampTypeLED(LampTypeLED const&);
	~LampTypeLED() override;

	void setLifespan(int);
	int getLifespan() const;

	void setEnergyClass(char const*);
	char const* getEnergyClass() const;

private:
	int lifespan; // lifespan in years. ex. 1 year, 3 years etc...
	char const* energyClass; // "A", "B", "C", ...,  "F"

};

class Transistor : public Semiconductor {
public:
	Transistor();
	Transistor(string const&, int);
	Transistor(Transistor const&);
	~Transistor();

	void setType(const string&);
	string getType() const;

	void setFunctionality(const string&);
	string getFunctionality() const;

private:
	string type; // bipolar transistors (bipolar junction transistors: BJTs), field-effect transistors (FETs), and insulated-gate bipolar transistors (IGBTs)
	string functionality; // "amplify", "control", and "generate" electrical signals.
};

class Thyristor : public Semiconductor {
public:
	Thyristor();
	Thyristor(string const&, int);
	Thyristor(Thyristor const&);
	~Thyristor();

	void setMode(const string&);
	string getMode() const;

	void setImax(double);
	double getImax() const;

private:
	string mode; // "ON" or "OFF", check if input is valid.
	double Imax; // The usual current rating of SCRs is from about 30 A to 100 A. /not sure/.
};

int main() {
	Semiconductor* defaultDiodePointer;
	Semiconductor* diodePointer;
	Semiconductor* diodeCPYPointer;

	Semiconductor* defaultLEDPointer;
	Semiconductor* LEDPointer;
	Semiconductor* LEDdiodeCPYPointer;

	Diode defaultDiode;
	Diode diode = Diode("Germanium", 0.3);
	Diode diodeCPY = Diode(diode);

	LED defaultLED;
	LED LEDdiode = LED("Germanium", 0.3, 12, 1.125);
	LED LEDdiodeCPY = LED(LEDdiode);

	defaultDiodePointer = &defaultDiode;
	diodePointer = &diode;
	diodeCPYPointer = &diodeCPY;

	defaultLEDPointer = &defaultLED;
	LEDPointer = &LEDdiode;
	LEDdiodeCPYPointer = &LEDdiodeCPY;

	// Diode showInfo called. At runtime. Virtual fn.
	defaultDiodePointer->showInfo();
	diodePointer->showInfo();
	diodeCPYPointer->showInfo();

	// LED showInfo called. At runtime. Virtual fn.
	defaultLEDPointer->showInfo();
	LEDPointer->showInfo();
	LEDdiodeCPYPointer->showInfo();
}

Semiconductor::~Semiconductor() {
	cout << "Semiconductor Destructor" << endl;
}

void Semiconductor::showInfo() {
	cout << "Semiconductor -> showInfo." << endl;
}

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
	cout << format("Diode -> Chemical Element: {}. Forward Volts: {}V.\n", getChemicalElement(), getForwardVolts());
}

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
	cout << format("LED -> Chemical Element: {}. Forward Volts: {}V. Electrical Power: {}W. Brightness: {}lm.\n", getChemicalElement(), getForwardVolts(), getElectricalPower(), getBrightness());
}

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


