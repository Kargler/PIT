//Die Signalklasse speichert und verwaltet die Eigenschaften der einzelnen Signale.
//Erstellt am 5.11.2013 von Christian K.
//Zuletzt bearbeitet am 18.11.2013


#ifndef SIGNAL_H
#define SIGNAL_H

#include <string>
#include <vector>

using namespace std;

class Signal {
private:
	string quelle;											//Gibt an welches Quellenelement vor dem Signal liegt 
	string quellenTyp;										//Bauteiltyp des Quellenelementes
	vector<string> ziele;									//Gibt an, welche Elemente an diesem Signal anliegen
	int anzahlZiele;										//Gibt an wie viele Elemente an diesem Signal anliegen

public:
	Signal();
	~Signal();

	enum signalTypen {eingang, intern, ausgang, unbekannt};	//Gibt an, wo das Signal ist (Eingang der Schaltung, Zwischen den Gattern, Ausgang der Schaltung)	
	signalTypen signalTyp;
	
	//Get&Set Befehle wurden inline implementiert!

	int getAnzahlZiele() const { return anzahlZiele; }
	signalTypen getSignalTyp() const { return signalTyp; }
	string getQuelle() const { return quelle; }											
	string getQuellenTyp() const { return quellenTyp; }											//
	string getZiel(int pos) const { return ziele[pos]; }
	
	void setAnzahlZiele(int nZiele) { anzahlZiele = nZiele; }
	void setSignalTyp(signalTypen sigTyp) { signalTyp = sigTyp; }
	void setQuelle(string gatterName) { quelle = gatterName; }
	void setQuellenTyp(string gatterTyp) { quellenTyp = gatterTyp; }
	void zielHinzufuegen(string gatterName, int pos) { ziele.push_back(gatterName); }

};

#endif