#include "semiconductor.h"
#include "diode.h"
#include "led.h"
#include "lampTypeLED.h"
#include "transistor.h"
#include "thyristor.h"
#include "singlyLinkedList.h"

#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main() {
	// SINGLY LINKED LIST AT THE END.

	Semiconductor* defaultDiodePointer;
	Semiconductor* diodePointer;
	Semiconductor* diodeCPYPointer;

	Semiconductor* defaultLEDPointer;
	Semiconductor* LEDPointer;
	Semiconductor* LEDdiodeCPYPointer;

	Semiconductor* defaultLampTypeLEDPointer;
	Semiconductor* LampTypeLEDPointer;
	Semiconductor* LEDLampTypeCPYPointer;

	Semiconductor* defaultTransistorPointer;
	Semiconductor* transistorPointer;
	Semiconductor* transistorCPYPointer;

	Semiconductor* defaultThyristorPointer;
	Semiconductor* thyristorPointer;
	Semiconductor* thyristorCPYPointer;

	Diode defaultDiode;
	Diode diode = Diode("Germanium", 0.3);
	Diode diodeCPY = Diode(diode);

	LED defaultLED;
	LED LEDdiode = LED("Germanium", 0.3, 12, 1.125);
	LED LEDdiodeCPY = LED(LEDdiode);

	LampTypeLED defaultLampTypeLED;
	LampTypeLED lampTypeLED = LampTypeLED("Germanium", 0.4, 15, 1.500, 3, "B");
	LampTypeLED LEDlampTypeCPY = LampTypeLED(lampTypeLED);

	Transistor defaultTransistor;
	Transistor transistor = Transistor("FET", "control");
	Transistor transistorCPY = Transistor(transistor);

	Thyristor defaultThyristor;
	Thyristor thyristor = Thyristor("ON", 40.5);
	Thyristor thyristorCPY = Thyristor(thyristor);

	defaultDiodePointer = &defaultDiode;
	diodePointer = &diode;
	diodeCPYPointer = &diodeCPY;

	defaultLEDPointer = &defaultLED;
	LEDPointer = &LEDdiode;
	LEDdiodeCPYPointer = &LEDdiodeCPY;

	defaultLampTypeLEDPointer = &defaultLampTypeLED;
	LampTypeLEDPointer = &lampTypeLED;
	LEDLampTypeCPYPointer = &LEDlampTypeCPY;

	defaultTransistorPointer = &defaultTransistor;
	transistorPointer = &transistor;
	transistorCPYPointer = &transistorCPY;

	defaultThyristorPointer = &defaultThyristor;
	thyristorPointer = &thyristor;
	thyristorCPYPointer = &thyristorCPY;

	// Diode showInfo called. At runtime. Virtual fn.
	defaultDiodePointer->showInfo();
	diodePointer->showInfo();
	diodeCPYPointer->showInfo();

	// LED showInfo called. At runtime. Virtual fn.
	defaultLEDPointer->showInfo();
	LEDPointer->showInfo();
	LEDdiodeCPYPointer->showInfo();

	// LampTypeLED showInfo called. At runtime. Virtual fn.
	defaultLampTypeLEDPointer->showInfo();
	LampTypeLEDPointer->showInfo();
	LEDLampTypeCPYPointer->showInfo();

	// Transistor showInfo called. At runtime. Virtual fn.
	defaultTransistorPointer->showInfo();
	transistorPointer->showInfo();
	transistorCPYPointer->showInfo();

	// Thyristor showInfo called. At runtime. Virtual fn.
	defaultThyristorPointer->showInfo();
	thyristorPointer->showInfo();
	thyristorCPYPointer->showInfo();

	// static array
	Transistor arr[3];

	for (int i = 0; i < 3; i++) {
		arr[i].showInfo();
	}

	// dynamic array
	Diode* arrPointer;
	arrPointer = new Diode[3];

	for (int i = 0; i < 3; i++) {
		(arrPointer + i)->showInfo();
	}

	delete[] arrPointer;

	// Singly Linked List.

	SinglyLinkedList list;

	list.append(defaultDiodePointer);
	list.append(defaultLEDPointer);
	list.append(defaultLampTypeLEDPointer);
	list.append(defaultTransistorPointer);
	list.append(defaultThyristorPointer);
	list.print();
	list.deleteList();

	return 0;
}