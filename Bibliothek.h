
#ifndef BIBLIOTHEK_H
#define BIBLIOTHEK_H
  
#include <string>
#include <vector>
#include "Gattertyp.h"
#include "Flipflop.h"
  
using namespace std; 
class Bibliothek
{
private:
	string datei;
	vector<Gattertyp*> bibElemente;
	void openError();
	void readError();

	bool bibFlag;

public:
	Bibliothek(void);
	virtual~Bibliothek(void);
	
	bool getBibFlag() const { return bibFlag; }

	string getPfad(); 
	Gattertyp* getBibElement(string typ);
	void dateiAusgabe();
	void dateiAuswerten();
	bool pfadEinlesen(string pfad);
};

#endif