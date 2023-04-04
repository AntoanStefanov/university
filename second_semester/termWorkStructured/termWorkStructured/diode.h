#ifndef DIODE_H
#define DIODE_H

#include <iostream>
using std::string;

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

#endif
