#ifndef GRAPHERZEUGER_H
#define GRAPHERZEUGER_H

#include "Bibliothek.h"
#include "Signal.h"

#include "ListenElement.h"

using namespace std;

class GraphErzeuger
{
private:
	Bibliothek* bibliothek;
	ListenElement* startElement;
	ListenElement* endElement;
	vector<Signal> signale;
	short anzahlSignale;

public:
	GraphErzeuger(void);
	~GraphErzeuger(void);

	void setAnzahlSignale(short _anzahlSignale) { anzahlSignale = _anzahlSignale; }
	void setSignalListe(vector<Signal>* _signale) { signale = *_signale; }
	void erzeugeGraph();

};

#endif