//Die SignalListeErzeuger Klasse erzeugt ein array aus Signalen.
//Erstellt am 5.11.2013 von Christian K.
//Zuletzt bearbeitet am 18.11.2013

#ifndef SIGNALLISTEERZEUGER_H
#define SIGNALLISTEERZEUGER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Signal.h"

using namespace std;

class SignalListeErzeuger {
private:
	vector<Signal> signale;		//Array aus allen Signalen
	short anzahlSignale;		//Gibt an, wie viele Signale es gibt
	string datei;				//Dateiname und Pfad
	long frequenz;				//Frequenz, mit der die Schaltung betrieben werden soll (ausgelesen aus der Datei "clk")
	bool signalListeFlag;		//true, wenn signalListe erfolgreich erzeugt wurde

public:
	//Konstruktor & Destruktor
	SignalListeErzeuger();
	~SignalListeErzeuger() {}

	
	//Menueschnittstellen
	//Get&Set Funktionen
	string getDatei() { return datei; }
	bool setDatei(string n_DateiPfad);
	bool getSignalListeFlag() const { return signalListeFlag; }
	vector<Signal>* getSignalListe() { return &signale; }			
	bool pfadEingabe();

	void dateiAusgabe() const;										//Gibt die Schaltnetzdatei aus

	bool erzeugeSignalListe();										//Liest die Schaltnetzdatei ein und erzeugt die Signalliste
	void signalListeAusgabe() const;								//Gibt die Signalliste aus
	
};
#endif