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
	Diode(string const&, int);
	Diode(Diode const&);
	~Diode();

	void setChemicalElement(const string&);
	string getChemicalElement() const;

	void setForwardVolts(int);
	double getForwardVolts() const;

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
};

// Two types of LEDs are available, a lamp type (leaded) and a chip type (surface mount). https://www.google.com/search?q=type+of+LED+diode+&sxsrf=APwXEdeZA52lnvnN9m_X9HDUnSXj-QGimg%3A1680378742879&ei=dosoZJuXNYq_xc8PnNKOuAg&ved=0ahUKEwibqrrQuon-AhWKX_EDHRypA4cQ4dUDCA8&uact=5&oq=type+of+LED+diode+&gs_lcp=Cgxnd3Mtd2l6LXNlcnAQAzIGCAAQBxAeMggIABAIEAcQHjoKCAAQRxDWBBCwAzoKCAAQigUQsAMQQzoFCAAQgAQ6BggAEBYQHjoICAAQFhAeEA86BwgAEIAEEBM6CAgAEBYQHhATOgoIABAWEB4QDxATOgkIABCABBANEBM6CggAEAgQHhANEBM6CAgAEAcQHhAPOgcIABCABBANOgoIABAIEAcQHhAPOgYIABAIEB5KBAhBGABQlUtYutQBYJTVAWgFcAF4AIABcYgBsQ6SAQQ3LjExmAEAoAEByAEKwAEB&sclient=gws-wiz-serp
class LampTypeLED : public LED {
public:
	LampTypeLED();
	LampTypeLED(string const&, int);
	LampTypeLED(LampTypeLED const&);
	~LampTypeLED();
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

	void setImax(int);
	double getImax() const;

private:
	string mode; // "ON" or "OFF", check if input is valid.
	double Imax; // The usual current rating of SCRs is from about 30 A to 100 A. /not sure/.
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