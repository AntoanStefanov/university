#ifndef THYRISTOR_H
#define THYRISTOR_H

#include <iostream>
using std::string;

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

#endif