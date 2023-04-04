#ifndef DIODE_H
#define DIODE_H


class Diode :
	public Semiconductor
{
	Diode();
	Diode(std::string const&, double);
	Diode(Diode const&);
	~Diode() override; // same as "virtual void ~Diode()"

	void setChemicalElement(std::string const&);
	std::string getChemicalElement() const;

	void setForwardVolts(double);
	double getForwardVolts() const;

	void showInfo() override; // same as "virtual void showInfo()"

private:
	std::string chemicalElement; // silicon, germanium, etc...
	double forwardVolts; // 0.3V, 0.7V -> so that current can rise.
};

#endif