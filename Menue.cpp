#include "Menue.h"

Menue::Menue() {
	//meineFaktoren.itivdevice();
}
Menue::~Menue(){}

//Erstellt den Menuekopf
void Menue::menueKopf() const {
	cout << "******************************************" << endl
		 << "*     IT-Projektpraktikum WS2011/2012    *" << endl
		 << "* Laufzeitanalyse synchroner Schaltwerke *" << endl
		 << "******************************************" << endl
		 << endl;
}


//Ruft das Hauptmenue auf. Ist Ausgangspunkt des Programms
void Menue::start() {
	short benutzerEingabe = 0;
	system("cls");
	menueKopf();

	cout << "(1) Aeussere Faktoren" << endl
		 << "Spannung [Volt]: " << meineFaktoren.getSpannung() << endl
		 << "Temperatur [Grad Celsius]: " << meineFaktoren.getTemperatur() << endl
		 << "Prozess (1=slow, 2=typical, 3=fast): " << meineFaktoren.getProzess() << endl
		 << endl;

	cout << "(2) Bilbliothek" << endl
		 << "Pfad zur Bibliotheksdatei: " << meineBibliothek.getPfad() << endl
		 << endl;
	
	cout << "(3) Schaltwerk" << endl
		 << "Pfad zur Schaltwerksdatei: " << meinSignalListeErzeuger.getDatei() << endl
		 << endl;
		 
	cout << "(4) Analyse starten" << endl
		 << endl;

	cout << "(5) Programm beenden" << endl
		 << endl << endl;

	
	while(!((benutzerEingabe == 1)||(benutzerEingabe == 2)||(benutzerEingabe == 3)||(benutzerEingabe == 4)||(benutzerEingabe == 5))) {
		cout << "Waehle einen Menuepunkt und bestaetige mit Enter: ";
		cin >> benutzerEingabe;
		if(!((benutzerEingabe == 1)||(benutzerEingabe == 2)||(benutzerEingabe == 3)||(benutzerEingabe == 4)||(benutzerEingabe == 5))) {
			cout << "Ungueltige benutzerEingabe!" << endl;
		}
	}

	cout << "------------------------------------------------" << endl;

	switch ( benutzerEingabe ) {
	case 1: faktorenMenue(); break;
	case 2: bibliothekMenue(); break;
	case 3: schaltwerkMenue(); break;
	case 4: if(bereitFuerAnalyse() == true) {
				analyse();
			} else {
				cout << "Die Analyse kann ohne die nötigen Inputs nicht erfolgen. Bitte überprüfen Sie alle Eingaben." << endl;
			}
			break;
	case 5: cout << "Programm wird beendet" << endl; break;
	}
}


//Faktorenmenue: Debugmodus, Ausgabe der errechneten Faktoren
void Menue::faktorenMenue() {
	short benutzerEingabe = 0;
	system("cls");
	menueKopf();
	cout << endl;
	cout << "Untermenue Aeussere Faktoren" << endl
		 << "(1) Debugmodus: ";
	
	if(meineFaktoren.getDebugFlag() == true) {
		cout << "aktiv";
	} else {
		cout << "nicht aktiv";
	}
	cout << endl;
	cout << "\tSpannung [Volt]: " << meineFaktoren.getSpannung() << endl
		 << "\tTemperatur [Grad Celsius]: " << meineFaktoren.getTemperatur() << endl
		 << "\tProzess (1=slow, 2=typical, 3=fast): " << meineFaktoren.getProzess() << endl
		 << "(2) Ausgabe errechneter Faktoren" << endl
		 << "(3) Hauptmenue" << endl << endl << endl;

	while(!((benutzerEingabe == 1)||(benutzerEingabe == 2)||(benutzerEingabe == 3))) {
		cout << "Waehle einen Menuepunkt und bestaetige mit Enter: ";
		cin >> benutzerEingabe;
		if(!((benutzerEingabe == 1)||(benutzerEingabe == 2)||(benutzerEingabe == 3))) {
			cout << "Ungueltige benutzerEingabe!" << endl;
		}
	}
	cout << "------------------------------------------------" << endl;

	switch ( benutzerEingabe ) {
	case 1: cout << "Debugging:" << endl
				 << "----------" << endl;
			meineFaktoren.debugmodus();
			system("pause");
			faktorenMenue();
			break;
	case 2: meineFaktoren.ausgabeFaktoren(); break;
	case 3: start(); break;
	}
}


//Bibliotheksmenue: Pfadverwaltung, Ausgabe der Bibliotheksdatei
void Menue::bibliothekMenue() {
	short benutzerEingabe = 0;
	system("cls");
	menueKopf();
	cout << endl;
	cout << "Untermenue Bibliothek" << endl
		 << "(1) Pfad zur Bibliotheksdatei: " << meineBibliothek.getPfad() << endl
		 << "(2) Ausgabe der Bibliotheksdatei" << endl
		 << "(3) Hauptmenue" << endl << endl << endl;
	while(!((benutzerEingabe == 1)||(benutzerEingabe == 2)||(benutzerEingabe == 3))) {
		cout << "Waehle einen Menuepunkt und bestaetige mit Enter: ";
		cin >> benutzerEingabe;
		if(!((benutzerEingabe == 1)||(benutzerEingabe == 2)||(benutzerEingabe == 3))) {
			cout << "Ungueltige benutzerEingabe!" << endl;
		}
	}

	cout << "------------------------------------------------" << endl;

	switch ( benutzerEingabe ) {
	case 1: {
			string eingabe;
			cout << "Gib einen neuen Dateipfad ein!" << endl; 
			do {
				cin >> eingabe;
				if(meineBibliothek.pfadEinlesen(eingabe) == false) {
					cout << "ungueltiger Dateipfad!" << endl;
				}
			} while(meineBibliothek.pfadEinlesen(eingabe) == false); 
			break;
			}
	case 2: cout << "Bibliotheksdatei wird ausgegeben:" << endl;
			meineBibliothek.dateiAusgabe();
			break;
	case 3: start(); break;
	}
}


//Schaltwerkmenue: Pfadverwaltung, Ausgabe Schaltnetzdatei, Ausgabe Signale, Ausgabe Graphenstruktur
void Menue::schaltwerkMenue() {
	short benutzerEingabe = 0;
	system("cls");
	menueKopf();
	cout << endl;
	cout << "Untermenue Schaltwerk" << endl
		 << "(1) Pfad zur Schaltnetzdatei: " << meinSignalListeErzeuger.getDatei() << endl
		 << "(2) Ausgabe der Schaltnetzdatei" << endl
		 << "(3) Ausgabe der Signale" << endl
		 << "(4) Ausgabe der Graphenstruktur" << endl
		 << "(5) Hauptmenue" << endl << endl << endl;
	while(!((benutzerEingabe == 1)||(benutzerEingabe == 2)||(benutzerEingabe == 3)||(benutzerEingabe == 4)||(benutzerEingabe == 5))) {
		cout << "Waehle einen Menuepunkt und bestaetige mit Enter: ";
		cin >> benutzerEingabe;
		if(!((benutzerEingabe == 1)||(benutzerEingabe == 2)||(benutzerEingabe == 3)||(benutzerEingabe == 4)||(benutzerEingabe == 5))) {
			cout << "Ungueltige benutzerEingabe!" << endl;
		}
		cout << "------------------------------------------------" << endl;
	}

	switch ( benutzerEingabe ) {
	case 1: meinSignalListeErzeuger.pfadEingabe();
			schaltwerkMenue();
			break;
	case 2: cout << "Datei wird Ausgegeben:" << endl
				 << "----------------------" << endl;
			meinSignalListeErzeuger.dateiAusgabe();
			cout << endl;
			system("pause");
			schaltwerkMenue();
			break;
	case 3: 
			if(meinSignalListeErzeuger.getSignalListeFlag() == false) {
				meinSignalListeErzeuger.erzeugeSignalListe();
			}
			if(meinSignalListeErzeuger.getSignalListeFlag() == true) {
				meinSignalListeErzeuger.signalListeAusgabe();
			} else {
				cout << "Signalliste konnte nicht erstellt werden" << endl;
			}
			system("pause");
			schaltwerkMenue();
			break;
	case 4: cout << "Die Graphenstruktur sieht wie folgt aus: ..." << endl; break;
	case 5: start(); break;
	}
}

bool Menue::bereitFuerAnalyse() const {
	if(meinSignalListeErzeuger.getSignalListeFlag() == false) {
		cout << "Signalliste wurde noch nicht erzeugt" << endl;
		return false;
	} else if(meineBibliothek.getBibFlag() == false) {
		cout << "Bibliothek wurde noch nicht erzeugt" << endl;
		return false;
	} else if(meineFaktoren.getFaktorenFlag() == false) {
		cout << "Faktoren wurden noch nicht erzeugt" << endl;
		return false;
	} else {
		return true;
	}
}


//Analyse
void Menue::analyse() {

	meinGraphErzeuger.erzeugeGraph();
	//meinLaufzeitAnalysator.laufzeitEinzelgatterBerechnen();
	//meinLaufzeitAnalysator.dfs(meinGraphErzeuger.startElement);
}

