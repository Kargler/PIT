//Datei: Faktoren.h
//Beschreibung: liest die auesseren Faktoren entweder über eine manuelle Eingabe oder das Itiv-Device ein, berechnet den dazugehörigen Faktor und gibt diesen aus
//Rev:
//Geschrieben:
//Geändert:
//Author: 

#ifndef FAKTOREN_H
#define FAKTOREN_H

class Faktoren
{
private:
	double spannung;
	double temperatur;
	short prozess;
	double spannungFaktor;
	double temperaturFaktor;
	double prozessFaktor;
	double arrspannung [7][2];
	double arrtemperatur [15][2];
	double arrprozess [3][2];
	double ergebniswert;
	
	bool debugFlag;
	bool faktorenFlag;

	bool berechneSpannungFaktor(double spannung);
	bool berechneTemperaturfaktor(double temperatur);
	bool berechneProzessFaktor(short prozess);
	double berechneFaktor( double wert, double arr[][2], int laenge);
	double interpolation( double wert, double x1, double x2, double y1, double y2 );

public:
	void ausgabeFaktoren();
	Faktoren(void);
	~Faktoren(void);
	void debugmodus();
	void itivdevice();

	bool getDebugFlag() const { return debugFlag; }
	bool getFaktorenFlag() const { return faktorenFlag; }

	double getSpannung() { return spannung; }  ;
	double getTemperatur() { return temperatur; };
	short getProzess() { return prozess; };
	void getFaktoren( double& spannungFaktor, double& temperaturFaktor, double& prozessFaktor );
	bool setSpannung( double spannung1 ) { spannung = spannung1; return true; };
	bool setTemperatur(double temperatur1 ) { temperatur = temperatur1; return true; };
	bool setProzess( short prozess1 ) {prozess = prozess1; return true; };

}; 

#endif

