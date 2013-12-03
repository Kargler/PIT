#ifndef MENUE_H
#define MENUE_H

#include <iostream>
#include <string>

#include "Faktoren.h"
#include "SignalListeErzeuger.h"
#include "bibliothek.h"
#include "GraphErzeuger.h"
#include "LaufzeitAnalysator.h"

using namespace std;

class Menue {
	private:
		Faktoren meineFaktoren;
		Bibliothek meineBibliothek;
		SignalListeErzeuger meinSignalListeErzeuger;
		GraphErzeuger meinGraphErzeuger;
		LaufzeitAnalysator meinLaufzeitAnalysator;

	public:
		Menue();
		~Menue();
		
		void start();					//schreibt das Hauptmen� in die Konsole und startet die Hauptschleife, in der durch das Hauptmen� navigiert wird.
		void faktorenMenue();			//schreibt das Untermen� Aeussere Faktoren in die Konsole und navigiert durch dieses.
		void bibliothekMenue();			//schreibt das Untermen� Bibliothek in die Konsole und navigiert durch dieses.
		void schaltwerkMenue();			//schreibt das Untermen� Schaltwerk in die Konsole und navigiert durch dieses.
		void analyse();					//ruft die zur Analyse ben�tigten Methoden auf und gibt das Ergebnis auf dem Bildschirm aus.
		void menueKopf() const;			//Gibt den Kopf der Men�s aus. Dieser bleibt in Hauptmen� und allen Untermen�s gleich.

		bool bereitFuerAnalyse() const;

		//void assign();

};

#endif