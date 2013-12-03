#include "Bibliothek.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Gattertyp.h"
#include "Flipflop.h"
#include <sstream>

Bibliothek::Bibliothek()
{
	datei = "C:\\bib.txt";
	bibFlag = false;
}


Bibliothek::~Bibliothek()
{
	for (vector<Gattertyp*>::iterator it = bibElemente.begin(); it != bibElemente.end(); it++){
		delete *it;
	}
}

string Bibliothek::getPfad()
{ return datei;
}

Gattertyp* Bibliothek::getBibElement(string typ){
	for (vector<Gattertyp*>::iterator it = bibElemente.begin(); it != bibElemente.end(); it++){
		if( typ.compare((*it)-> getName()) == 0){
			return *it;
		}
	}
	cout<< "Es konnte kein BibElement gefunden werden." << endl;
	return NULL;
}

bool Bibliothek::pfadEinlesen(string pfad){
	fstream file;
	file.open(pfad.c_str(),fstream::in);
	if (!file){
		openError();
		return false;
	}
	else {
		datei = pfad;
		file.close(); 
		return true;
	}
}

void Bibliothek::openError(){
	cout<< "Fehler beim Oeffnen der Datei!" << endl;
}
void Bibliothek::readError(){
	cout<< "Fehler beim Lesen der Datei!" <<endl;
}


void Bibliothek::dateiAusgabe(){
	fstream file;
	file.open(datei.c_str(), fstream::in);
	if(!file){
		openError();
	}
	else {
		int i = 1;
		string line;
		while(!file.eof()){
			getline(file, line);
			cout<< i << "  " << line <<endl;
			i++;
		}
		file.close();
	}
}

void Bibliothek::dateiAuswerten(){
	fstream in;
	in.open(datei.c_str(), fstream::in);
	if(in){
		string zeile;
		do{
			getline(in, zeile);
		}
		while (zeile.find("[[Bausteine]]") == zeile.npos);
			getline(in,zeile);

			while(zeile != "#endfile"){

				while(zeile.find("[") == zeile.npos && zeile != "#endfile"){
					getline(in, zeile);
				}

				if (zeile.find("dff") == zeile.npos){

					Gattertyp* tmp = new Gattertyp();
					tmp->setName(zeile.substr(1,zeile.length() - 2));

					getline(in, zeile);
					tmp->setEingaenge(zeile[3]-48);

					getline(in, zeile);
					stringstream stream;
					stream << zeile.substr(5,sizeof(zeile));
					double grundLaufzeit;
					stream >> grundLaufzeit;
					tmp->setGrundlaufzeit(grundLaufzeit);
					stream.clear();

					getline(in, zeile);
					stream << zeile.substr(3,sizeof(zeile));
					short lastFaktor;
					stream >> lastFaktor;
					tmp->setLastfaktor(lastFaktor);
					stream.clear();

					getline(in, zeile);
					stream << zeile.substr(3,sizeof(zeile));
					short lastKapazitaet;
					stream >> lastKapazitaet;
					tmp->setLastkapazitaet(lastKapazitaet);
					stream.clear();

					bibElemente.push_back(tmp);

				}
				else {
					Flipflop* tmp = new Flipflop();
					tmp->setName(zeile.substr(1,zeile.length()-2));
					tmp->setEingaenge(2);
                    getline(in, zeile);

					getline(in, zeile);
					stringstream stream;
					stream << zeile.substr(7,sizeof(zeile));
					short setupTime;
					stream >> setupTime;
					tmp->setSetupTime(setupTime);
					stream.clear();

					getline(in, zeile);
					stream << zeile.substr(6,sizeof(zeile));
					short holdTime;
					stream >> holdTime;
					tmp->setHoldTime(holdTime);
					stream.clear();

					getline(in, zeile);
					stream << zeile.substr(3,sizeof(zeile));
					short lastKapazitaetD;
					stream >> lastKapazitaetD;
					tmp->setLastkapazitaet(lastKapazitaetD);
					stream.clear();

					getline(in,zeile);

					getline(in,zeile);
					stream << zeile.substr(5,sizeof(zeile));
					double grundLaufzeit;
					stream >> grundLaufzeit;
					tmp->setGrundlaufzeit(grundLaufzeit);
					stream.clear();

					getline(in,zeile);
					stream << zeile.substr(3,sizeof(zeile));
					short lastFaktor;
					stream >> lastFaktor;
					tmp->setLastfaktor(lastFaktor);
					stream.clear();

					getline(in,zeile);
					stream << zeile.substr(3,sizeof(zeile));
					short tlastKapazitaet;
					stream >> tlastKapazitaet;
					tmp->setLastKapazitaetClock(tlastKapazitaet);
					stream.clear();

					bibElemente.push_back(tmp);

				}

			}
			}


			}

			

			



