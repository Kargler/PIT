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
		
		void start();					//schreibt das Hauptmenü in die Konsole und startet die Hauptschleife, in der durch das Hauptmenü navigiert wird.
		void faktorenMenue();			//schreibt das Untermenü Aeussere Faktoren in die Konsole und navigiert durch dieses.
		void bibliothekMenue();			//schreibt das Untermenü Bibliothek in die Konsole und navigiert durch dieses.
		void schaltwerkMenue();			//schreibt das Untermenü Schaltwerk in die Konsole und navigiert durch dieses.
		void analyse();					//ruft die zur Analyse benötigten Methoden auf und gibt das Ergebnis auf dem Bildschirm aus.
		void menueKopf() const;			//Gibt den Kopf der Menüs aus. Dieser bleibt in Hauptmenü und allen Untermenüs gleich.

		bool bereitFuerAnalyse() const;

		//void assign();

};

#endif