#include "Signal.h"

Signal::Signal() {
	signalTyp = unbekannt;
	quelle = "NULL";
	quellenTyp = "NULL";
	anzahlZiele = 0;
	ziele.clear();
}
Signal::~Signal() {}

//Die Get&Set-Funktionen wurden Inline implementiert und tauchen hier nicht mehr auf!


