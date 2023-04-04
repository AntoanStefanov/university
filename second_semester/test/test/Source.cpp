#include <iostream>

#include "Semiconductor.h"
#include "Diode.h"


using namespace std;

int main() {
	Semiconductor* defaultDiodePointer;

	Diode diode;

	defaultDiodePointer = &diode;

	cout << defaultDiodePointer;
}