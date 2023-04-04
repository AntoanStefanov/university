#include <iostream>

using std::string;
using std::cout;
using std::endl;

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

	void showInfo() override;

private:
	int lifespan; // lifespan in years. ex. 1 year, 3 years etc...
	char const* energyClass; // "A", "B", "C", ...,  "F"

};

class Transistor : public Semiconductor {
public:
	Transistor();
	Transistor(string const&, string const&);
	Transistor(Transistor const&);
	~Transistor() override;

	void setType(const string&);
	string getType() const;

	void setFunctionality(const string&);
	string getFunctionality() const;

	void showInfo() override;

private:
	string type; // bipolar transistors (bipolar junction transistors: BJTs), field-effect transistors (FETs), and insulated-gate bipolar transistors (IGBTs)
	string functionality; // "amplify", "control", and "generate" electrical signals.
};

class Thyristor : public Semiconductor {
public:
	Thyristor();
	Thyristor(string const&, double);
	Thyristor(Thyristor const&);
	~Thyristor() override;

	void setMode(const string&);
	string getMode() const;

	void setImax(double);
	double getImax() const;

	void showInfo() override;

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

	Semiconductor* defaultLampTypeLEDPointer;
	Semiconductor* LampTypeLEDPointer;
	Semiconductor* LEDLampTypeCPYPointer;

	Semiconductor* defaultTransistorPointer;
	Semiconductor* transistorPointer;
	Semiconductor* transistorCPYPointer;

	Semiconductor* defaultThyristorPointer;
	Semiconductor* thyristorPointer;
	Semiconductor* thyristorCPYPointer;

	Diode defaultDiode;
	Diode diode = Diode("Germanium", 0.3);
	Diode diodeCPY = Diode(diode);

	LED defaultLED;
	LED LEDdiode = LED("Germanium", 0.3, 12, 1.125);
	LED LEDdiodeCPY = LED(LEDdiode);

	LampTypeLED defaultLampTypeLED;
	LampTypeLED lampTypeLED = LampTypeLED("Germanium", 0.4, 15, 1.500, 3, "B");
	LampTypeLED LEDlampTypeCPY = LampTypeLED(lampTypeLED);

	Transistor defaultTransistor;
	Transistor transistor = Transistor("FET", "control");
	Transistor transistorCPY = Transistor(transistor);

	Thyristor defaultThyristor;
	Thyristor thyristor = Thyristor("ON", 40.5);
	Thyristor thyristorCPY = Thyristor(thyristor);

	defaultDiodePointer = &defaultDiode;
	diodePointer = &diode;
	diodeCPYPointer = &diodeCPY;

	defaultLEDPointer = &defaultLED;
	LEDPointer = &LEDdiode;
	LEDdiodeCPYPointer = &LEDdiodeCPY;

	defaultLampTypeLEDPointer = &defaultLampTypeLED;
	LampTypeLEDPointer = &lampTypeLED;
	LEDLampTypeCPYPointer = &LEDlampTypeCPY;

	defaultTransistorPointer = &defaultTransistor;
	transistorPointer = &transistor;
	transistorCPYPointer = &transistorCPY;

	defaultThyristorPointer = &defaultThyristor;
	thyristorPointer = &thyristor;
	thyristorCPYPointer = &thyristorCPY;


	// static array
	Transistor arr[3];

	for (int i = 0; i < 3; i++) {
		arr[i].showInfo();
	}

	// dynamic array
	Diode* arrPointer;
	arrPointer = new Diode[3];

	for (int i = 0; i < 3; i++) {
		(arrPointer + i)->showInfo();
	}

	delete[] arrPointer;


	// Diode showInfo called. At runtime. Virtual fn.
	defaultDiodePointer->showInfo();
	diodePointer->showInfo();
	diodeCPYPointer->showInfo();

	// LED showInfo called. At runtime. Virtual fn.
	defaultLEDPointer->showInfo();
	LEDPointer->showInfo();
	LEDdiodeCPYPointer->showInfo();

	// LampTypeLED showInfo called. At runtime. Virtual fn.
	defaultLampTypeLEDPointer->showInfo();
	LampTypeLEDPointer->showInfo();
	LEDLampTypeCPYPointer->showInfo();

	// Transistor showInfo called. At runtime. Virtual fn.
	defaultTransistorPointer->showInfo();
	transistorPointer->showInfo();
	transistorCPYPointer->showInfo();

	// Thyristor showInfo called. At runtime. Virtual fn.
	defaultThyristorPointer->showInfo();
	thyristorPointer->showInfo();
	thyristorCPYPointer->showInfo();
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
	cout << "Diode -> Chemical Element: " << getChemicalElement() << ". Forward Volts: " << getForwardVolts() << "V.\n";
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
	cout << "LED -> Chemical Element: " << getChemicalElement() << ". Forward Volts: " << getForwardVolts() << "V. Electrical Power: " << getElectricalPower() << "W.Brightness: " << getBrightness() << "lm.\n";
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

void LampTypeLED::showInfo() {
	cout << "LampTypeLED -> Chemical Element: " << getChemicalElement() << ". Forward Volts: " << getForwardVolts() << "V.Electrical Power: " << getElectricalPower() << "W.Brightness: " << getBrightness() << "lm.Lifespan: " << getLifespan() << " years. Energy class: " << "'" << getEnergyClass() << "'" << ".\n";
}


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

// replace "format" with "cout".