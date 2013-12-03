#include "SignalListeErzeuger.h"

SignalListeErzeuger::SignalListeErzeuger() {
	anzahlSignale = 0;
	frequenz = 0;
	datei = "c:\\csd.txt";					//standart Dateipfad
	signale.clear();
	signalListeFlag = false;
}


bool SignalListeErzeuger::pfadEingabe() {
	string pfad;
	cout << "Bitte gib einen Dateipfad zur Schaltwerksdatei ein:" << endl;
	cin >> pfad;
	ifstream lesetest(pfad);
	if(lesetest.is_open()) {
		lesetest.close();
		datei = pfad;
		return true;
	} else {
		cout << "Ungueltiger Dateipfad!" << endl;
		system("pause");
		return false;
	}
}

void SignalListeErzeuger::dateiAusgabe() const {
	string zeile;
	int zeilenNummer = 1;
	ifstream auslesen(datei);
	while(auslesen.good()) {
		getline(auslesen, zeile);
		cout << zeilenNummer << "  " << zeile << endl;
		zeilenNummer++;
	}

	auslesen.close();
}

bool SignalListeErzeuger::erzeugeSignalListe() {
	ifstream einlesen(datei);
	if (!einlesen) {
		cerr << "Datei konnte nicht gelesen werden" << endl;
		signalListeFlag = false;
		return false;
	}

	string zeile;
	int pos = 0;
	int signalIndex = 0;
	string signalIndexString = "NULL";

	while(einlesen.good()) {
		getline(einlesen, zeile);
		pos = zeile.find("//");
		if(pos != -1) {
			zeile.erase(pos, (zeile.size() - pos));				//Kommentare, welche mit "//" beginnen werden hier gelöscht
		}
		pos = 0;
		if((zeile.find("INPUT") != -1)||(zeile.find("OUTPUT") != -1)||(zeile.find("SIGNALS") != -1)) {
			anzahlSignale += count(zeile.begin(), zeile.end(), 's');
		}
		if(zeile.find("CLOCK") != -1) {
			if(zeile.find("MHz") != -1) {
				frequenz = stol(zeile.substr(10, zeile.size()-10)) * 1000000;	//String vor der Frequenzangabe wird rausgestrichen
			} else if(zeile.find("kHz") != -1) {
				frequenz = stol(zeile.substr(10, zeile.size()-10)) * 1000;
			} else {
				frequenz = stol(zeile.substr(10, zeile.size()-10));
			}
			break;
		}
	}
	signale.resize(anzahlSignale);
	cout << "Frequenz: " << frequenz << endl;
	einlesen.seekg(0, ios::beg);
	
	while(einlesen.good()) {
		getline(einlesen, zeile);
		pos = zeile.find("//");
		if(pos != -1) {
			zeile.erase(pos, (zeile.size() - pos));				//Kommentare, welche mit "//" beginnen werden hier gelöscht
		}
		pos = 0;

		if(zeile.find("INPUT") != -1) {
			do {
				pos = zeile.find("s", pos+1);
				if(pos != -1) {
					signalIndexString = zeile.substr(pos+1, 3);
					signalIndex = stoi(signalIndexString);
					signale[signalIndex - 1].setSignalTyp(Signal::eingang);
					signale[signalIndex - 1].setQuelle("keine Quelle");
				}
			} while(pos != -1);
		} else if(zeile.find("OUTPUT") != -1) {
			do {
				pos = zeile.find("s", pos+1);
				if(pos != -1) {
					signalIndexString = zeile.substr(pos+1, 3);
					signalIndex = stoi(signalIndexString);
					signale[signalIndex - 1].setSignalTyp(Signal::ausgang);
				}
			} while(pos != -1);
		} else if(zeile.find("SIGNALS") != -1) {
			do {
				pos = zeile.find("s", pos+1);
				if(pos != -1) {
					signalIndexString = zeile.substr(pos+1, 3);
					signalIndex = stoi(signalIndexString);
					signale[signalIndex - 1].setSignalTyp(Signal::intern);
				}
			} while(pos != -1);
		}
		
		
		if(zeile.find("BEGIN") != -1) {
			string gatterName = "NULL";
			string gatterTyp = "NULL";
			int pos2 = 0;
			string eingang1 = "NULL";
			string eingang2 = "NULL";
			string ausgang = "NULL";
			signalIndex = 0;
			while(zeile.find("END") == -1) {
				pos = 0;
				getline(einlesen, zeile);
				if(zeile.find("END") != -1) { break; }
				gatterName = zeile.substr(0, 4);
				pos = zeile.find("(");
				gatterTyp = zeile.substr(5, pos - 5);
				pos2 = zeile.find(",", pos+1);
				eingang1 = zeile.substr(pos+1, (pos2 - pos) - 1);
				if(gatterTyp.find("1") != -1) {
					ausgang = zeile.substr(pos2+1, 4);						//Sonderfall: Inverter (nur ein eingang)
				} else if(gatterTyp.find("2") != -1) {
					pos = zeile.find(",", pos2+1);							//Normalfall: 2 Eingänge
					eingang2 = zeile.substr(pos2+1, (pos - pos2) - 1);
					ausgang = zeile.substr(pos+1, 4);
					signalIndex = stoi(eingang2.substr(1, 3));
					signale[signalIndex - 1].zielHinzufuegen(gatterName, signale[signalIndex - 1].getAnzahlZiele() +1);
					signale[signalIndex - 1].setAnzahlZiele(signale[signalIndex - 1].getAnzahlZiele() + 1);
				} else {
					pos = zeile.find(",", pos2+1);							//Sonderfall: D-Flipflop (eingang2 = clk)
					eingang2 = "CLOCK";
					ausgang = zeile.substr(pos+1, 4);
				}
				signalIndex = stoi(eingang1.substr(1, 3));
				signale[signalIndex - 1].zielHinzufuegen(gatterName, signale[signalIndex - 1].getAnzahlZiele() +1);
				signale[signalIndex - 1].setAnzahlZiele(signale[signalIndex - 1].getAnzahlZiele() + 1);
				
				signalIndex = stoi(ausgang.substr(1, 3));
				if(signale[signalIndex - 1].getQuelle() == "NULL") {
					signale[signalIndex - 1].setQuelle(gatterName);
					signale[signalIndex - 1].setQuellenTyp(gatterTyp);
				} else {
					cout << "Es wird gerade versucht einem Signal eine 2. Quelle zuzuordnen." << endl
						 << "Dies wuerde einen Kurzschluss erzeugen. Signalliste kann nicht erzeugt werden." << endl;
					einlesen.close();
					signalListeFlag = false;
					return false;
				}
			}
		}
	}
	einlesen.close();
	signalListeFlag = true;
	return true;
}

void SignalListeErzeuger::signalListeAusgabe() const {
	string signalTypen[4] = {"Eingangssignal", "Internes Signal", "Ausgangssignal", "Unbekanntes Signal"};
	
	cout << "Signale:" << endl
		 << "--------" << endl;
	
	for(int i=0; i<anzahlSignale; i++) {
		if(i<9) {
			cout << "Signalname : s00" << i+1 << endl;
		} else {
			cout << "Signalname : s0" << i+1 << endl;
		}
		cout << "Signaltyp : " << signalTypen[signale[i].getSignalTyp()] << endl
			 << "Signalquelle : " << signale[i].getQuelle() << endl;
		if(signale[i].getQuelle() != "keine Quelle") {
			cout << "Signalquellentyp : " << signale[i].getQuellenTyp() << endl;
		}
		cout << "-->Das Signal hat " << signale[i].getAnzahlZiele() << " Ziele" << endl;
		cout << "Ziel-Gatter : ";
		for(int j=0; j<signale[i].getAnzahlZiele(); j++) {
			cout << signale[i].getZiel(j);
		}
		cout << endl
			 << endl;
	}
}