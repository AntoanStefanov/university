#ifndef LED_H
#define LED_H

#include <iostream>
using std::string;

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

#endif
