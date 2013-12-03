#ifndef SCHALTWERKELEMENT_H
#define SCHALTWERKELEMENT_H

#include "Gattertyp.h"

#include <iostream>
#include <string>

using namespace std;

class SchaltwerkElement
{
private:
	string name;
	Gattertyp* typ;
	double laufzeitEinzelgatter;
	SchaltwerkElement* nachfolgerElemente;
	int anzahlNachfolger;
	bool isEingangsElement;
	bool isAusgangsElement;
	short anzahlEingangssignale;

public:
	SchaltwerkElement(void);
	~SchaltwerkElement(void);
};

#endif