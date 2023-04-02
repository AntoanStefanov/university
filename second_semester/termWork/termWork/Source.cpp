#include <iostream>
#include <format>

using std::string;
using std::cout;
using std::endl;
using std::format;

// https://www.ibm.com/docs/en/zos/2.4.0?topic=only-abstract-classes-c ? class Semiconductor
// https://stackoverflow.com/questions/8513408/c-abstract-base-class-constructors-destructors-general-correctness
class Semiconductor {
public:
	virtual ~Semiconductor();
	virtual void showInfo() = 0; // pure virtual function, ... = 0
};

class Diode : public Semiconductor {
public:
	Diode();
	Diode(string const&, double);
	Diode(Diode const&);
	virtual ~Diode();

	void setChemicalElement(const string&);
	string getChemicalElement() const;

	void setForwardVolts(double);
	double getForwardVolts() const;

	virtual void showInfo();

private:
	string chemicalElement; // silicon, germanium, etc...
	double forwardVolts; // 0.3V, 0.7V -> so that current can rise.
};

class LED : public Diode {
public:
	LED();
	LED(string const&, int);
	LED(LED const&);
	~LED();

	void setElectricalPower(int);
	int getElectricalPower() const;

	void setBrightness(double);
	double getBrightness() const;

private:
	int electricalPower; // 12W, 15W, 20W ... etc
	double brightness; // Lumens, 12W->1,125lm(lumens)
};

// Two types of LEDs are available, a lamp type (leaded) and a chip type (surface mount). https://www.google.com/search?q=type+of+LED+diode+&sxsrf=APwXEdeZA52lnvnN9m_X9HDUnSXj-QGimg%3A1680378742879&ei=dosoZJuXNYq_xc8PnNKOuAg&ved=0ahUKEwibqrrQuon-AhWKX_EDHRypA4cQ4dUDCA8&uact=5&oq=type+of+LED+diode+&gs_lcp=Cgxnd3Mtd2l6LXNlcnAQAzIGCAAQBxAeMggIABAIEAcQHjoKCAAQRxDWBBCwAzoKCAAQigUQsAMQQzoFCAAQgAQ6BggAEBYQHjoICAAQFhAeEA86BwgAEIAEEBM6CAgAEBYQHhATOgoIABAWEB4QDxATOgkIABCABBANEBM6CggAEAgQHhANEBM6CAgAEAcQHhAPOgcIABCABBANOgoIABAIEAcQHhAPOgYIABAIEB5KBAhBGABQlUtYutQBYJTVAWgFcAF4AIABcYgBsQ6SAQQ3LjExmAEAoAEByAEKwAEB&sclient=gws-wiz-serp
class LampTypeLED : public LED {
public:
	LampTypeLED();
	LampTypeLED(string const&, int);
	LampTypeLED(LampTypeLED const&);
	~LampTypeLED();

	void setLifespan(int);
	int getLifespan() const;

	void setEnergyClass(char);
	char getEnergyClass() const;

private:
	int lifespan; // lifespan in years. ex. 1 year, 3 years etc...
	char energyClass; // "A", "B", "C", ...,  "F"

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
	cout << "main" << endl;
	Diode diode;
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