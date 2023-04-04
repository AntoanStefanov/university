#ifndef TRANSISTOR_H
#define TRANSISTOR_H

#include <iostream>
using std::string;

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

#endif
