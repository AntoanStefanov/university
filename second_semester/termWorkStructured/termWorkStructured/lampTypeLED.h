#ifndef LAMP_TYPE_LED_H
#define LAMP_TYPE_LED_H

#include <iostream>
using std::string;

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

#endif
