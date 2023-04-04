#ifndef SEMICONDUCTOR_H
#define SEMICONDUCTOR_H

#include <iostream>
using std::string;

// Abstract class / Interface
class Semiconductor {
public:
	virtual ~Semiconductor();
	virtual void showInfo() = 0; // pure virtual fn. ... = 0
};

#endif
