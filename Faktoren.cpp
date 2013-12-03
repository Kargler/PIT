#include "Faktoren.h"
#include "itiv_win_drv.h"
#include <iostream>
using namespace std;

//Konstruktor der Klasse, setzt alle Atribute auf 0
Faktoren::Faktoren(void)
{
	setSpannung(0);
	setTemperatur(0);
	setProzess(0);
	spannungFaktor = 0;
	temperaturFaktor = 0;
	prozessFaktor = 0;
	debugFlag = false;
	faktorenFlag = false;

}

// Destruktor der Klasse
Faktoren::~Faktoren(void)
{
}

//Methode gibt den Spannungs-,Temperatur- und Prozessfaktor aus
void Faktoren::ausgabeFaktoren()
{
	cout << spannungFaktor << endl;
	cout << temperaturFaktor << endl;
	cout << prozessFaktor << endl;
}

//Get Methode der Faktoren (Spannungsfaktor, Temperaturfaktor und Prozessfaktor)
void Faktoren::getFaktoren(double& spgFaktor, double& tmpFaktor, double& przFaktor)
{
spgFaktor = spannungFaktor;
tmpFaktor = temperaturFaktor;
przFaktor = prozessFaktor;

}

//Methode überprüft, ob der eingegebene Wert der Spannung innerhalb des erlaubten Intervalls (erster bis letzer Wert des Arrays) liegt
// Ist dies der Fall, wird berechneFaktor() aufgerufen, ansonsten wird eine Fehlermeldung ausgegeben
bool Faktoren::berechneSpannungFaktor(double spannung) {
	int anzahlSpannungswerte = 7;
	arrspannung[0][0] = 1.08;
	arrspannung[0][1] = 1.121557;
	arrspannung[1][0] = 1.12;
	arrspannung[1][1] = 1.075332;
	arrspannung[2][0] = 1.16;
	arrspannung[2][1] = 1.035161;
	arrspannung[3][0] = 1.20;
	arrspannung[3][1] = 1.000000;
	arrspannung[4][0] = 1.24;
	arrspannung[4][1] = 0.940065;
	arrspannung[5][0] = 1.28;
	arrspannung[5][1] = 0.940065;
	arrspannung[6][0] = 1.32;
	arrspannung[6][1] = 0.914482;
	if( spannung >= arrspannung[0][0] && spannung <= arrspannung[6][0] ) {										
	spannungFaktor = berechneFaktor( spannung, arrspannung ,anzahlSpannungswerte);
	return true;
	} else {
	cout << "Ein Fehler ist aufgetreten, der eingegebene Wert liegt ausserhalb des gueltigen Bereichs" << endl;
	return false;
	}
	
	
}



//Methode überprüft, ob der eingegebene Wert der Temperatur innerhalb des erlaubten Intervalls (erster bis letzer Wert des Arrays) liegt
// Ist dies der Fall, wird berechneFaktor() aufgerufen, ansonsten wird eine Fehlermeldung ausgegeben
bool Faktoren::berechneTemperaturfaktor(double temperatur) {
	int anzahlTemperaturwerte = 15;
	arrtemperatur[0][0] = -25;
	arrtemperatur[0][1] = 0.897498;
	arrtemperatur[1][0] = -15;
	arrtemperatur[1][1] = 0.917532;
	arrtemperatur[2][0] = 0;
	arrtemperatur[2][1] = 0.948338;
	arrtemperatur[3][0] = 15;
	arrtemperatur[3][1] = 0.979213;
	arrtemperatur[4][0] = 25;
	arrtemperatur[4][1] = 1.000000;
	arrtemperatur[5][0] = 35;
	arrtemperatur[5][1] = 1.020305;
	arrtemperatur[6][0] = 45;
	arrtemperatur[6][1] = 1.040540;
	arrtemperatur[7][0] = 55;
	arrtemperatur[7][1] = 1.061831;
	arrtemperatur[8][0] = 65;
	arrtemperatur[8][1] = 1.082983;
	arrtemperatur[9][0] = 75;
	arrtemperatur[9][1] = 1.103817;
	arrtemperatur[10][0] = 85;
	arrtemperatur[10][1] = 1.124124;
	arrtemperatur[11][0] = 95;
	arrtemperatur[11][1] = 1.144245;
	arrtemperatur[12][0] = 105;
	arrtemperatur[12][1] = 1.164563;
	arrtemperatur[13][0] = 115;
	arrtemperatur[13][1] = 1.184370;
	arrtemperatur[14][0] = 125;
	arrtemperatur[14][1] = 1.204966;	
	if( temperatur >= arrtemperatur[0][0] && temperatur <= arrtemperatur[14][0] ) {			
	temperaturFaktor = berechneFaktor( temperatur, arrtemperatur, anzahlTemperaturwerte);
	return true;
	} else {
	cout << "Ein Fehler ist aufgetreten, der eingegebene Wert liegt ausserhalb des gueltigen Bereichs" << endl;
	return false;
	}
	
	
}

//Methode um manuell Werte der Spannung, Temperatur und des Prozesses einzugeben
void Faktoren::debugmodus() {
	
	Faktoren debugFaktor;
	
	cout << "Geben Sie eine Spannung ein:" << endl;
	cin >> spannung;
	cout << "Geben Sie eine Temperatur ein:" << endl;
	cin >>  temperatur;
	cout << "Geben Sie ein Prozess ein:" << endl;
	cin >> prozess;

	debugFaktor.berechneSpannungFaktor(spannung);
	debugFaktor.berechneTemperaturfaktor(temperatur);
	debugFaktor.berechneProzessFaktor(prozess);
	debugFaktor.ausgabeFaktoren();

}

//Methode um Werte der Spannung, Temperatur und des Prozesses über das ITIV-Device zu erhalten
void Faktoren::itivdevice() {
ItivDev_Config* DevPtr;
DevPtr= ItivDev_GetConfigByName("Global\\ITIV_WindowsDevice");
DevPtr -> BaseAddress;

do {
*((int*)(DevPtr->BaseAddress + CTRL_REG)) = 0x00000000;

while (*((int*)(DevPtr->BaseAddress + STAT_REG)) != 0x01000000) {}
	*((int*)(DevPtr->BaseAddress + CTRL_REG)) = 0x00000101;
while (*((int*)(DevPtr->BaseAddress + STAT_REG)) != 0x00010000) {}

} while (*((int*)(DevPtr->BaseAddress + STAT_REG)) == 0x00000001); 
 
spannung = *((double*)(DevPtr->BaseAddress + DATA_REG));
	
	
do {
*((int*)(DevPtr->BaseAddress + CTRL_REG)) = 0x00000000;

while (*((int*)(DevPtr->BaseAddress + STAT_REG)) != 0x01000000) {}
	*((int*)(DevPtr->BaseAddress + CTRL_REG)) = 0x00000102;
while (*((int*)(DevPtr->BaseAddress + STAT_REG)) != 0x00010000) {}

} while (*((int*)(DevPtr->BaseAddress + STAT_REG)) == 0x00000001); 
 
temperatur = *((int32_t*)(DevPtr->BaseAddress + DATA_REG));
	
do {
*((int*)(DevPtr->BaseAddress + CTRL_REG)) = 0x00000000;

while (*((int*)(DevPtr->BaseAddress + STAT_REG)) != 0x01000000) {}
	*((int*)(DevPtr->BaseAddress + CTRL_REG)) = 0x00000103;
while (*((int*)(DevPtr->BaseAddress + STAT_REG)) != 0x00010000) {}

} while (*((int*)(DevPtr->BaseAddress + STAT_REG)) == 0x00000001); 
 
prozess = *((uint32_t*)(DevPtr->BaseAddress + DATA_REG)) + 1 ;
	




*((int*)(DevPtr->BaseAddress + CTRL_REG)) = 0x001B0000;
ItivDev_ReleaseDevice(DevPtr);

}



//Methode überprüft, ob der eingegebene Wert des Prozesses innerhalb des erlaubten Intervalls (erster bis letzer Wert des Arrays) liegt
// Ist dies der Fall, wird berechneFaktor() aufgerufen, ansonsten wird eine Fehlermeldung ausgegeben
bool Faktoren::berechneProzessFaktor(short prozess) {
	int anzahlProzesswerte = 3;
	
	//double arrprozess [3][2];
	arrprozess[0][0] = 1;
	arrprozess[0][1] = 1.174235;
	arrprozess[1][0] = 2;
	arrprozess[1][1] = 1.000000;
	arrprozess[2][0] = 3;
	arrprozess[2][1] = 0.876148;
	if( prozess >= arrprozess[0][0] && prozess <= arrprozess[2][0] ) {
	prozessFaktor = berechneFaktor(prozess, arrprozess, anzahlProzesswerte);
	return true;
	} else {
	cout << "Ein Fehler ist aufgetreten, der eingegebene Wert liegt ausserhalb des gueltigen Bereichs" << endl;
	return false;
	}
	
	
}


//Methode vergleicht den eingegebenen Wert  mit den Werten des Arrays ,
//ist dieser Wert gleich einem Wert im Array wird der ensprechende Faktor ausgegeben
//ansonsten wird die Methode interpolation() aufgerufen

double Faktoren::berechneFaktor(double wert,double arr[][2], int laenge) {
	int test = 0;
	double X1;
	double X2;
	double Y1;
	double Y2;
	double ergebniswert ;
	
	
	for (int i = 0; i < laenge; i ++) {
		if (wert == arr[i][0] ) {
			test = 1;
			ergebniswert = arr[i][1];

			return ergebniswert;
		}
		}

	if ( test !=1 ) {
		for ( int j = 0; j < laenge; j++ ) {
			if ( wert < arr[j][0] && wert > arr[j-1][0]) {
				X1 = arr[j-1][0];
				Y1 = arr[j-1][1];
				X2 = arr[j][0];
				Y2 = arr[j][1];
				
			}
		}
		ergebniswert = interpolation( wert,X1,X2,Y1,Y2 ); 
		return ergebniswert;
	}
	

}

// Methode berechnet aufgrund 2er gegebener Werte einen Wert auf der Geraden durch diese beiden Punkte
double Faktoren::interpolation(double wert, double x1, double x2, double y1, double y2) {
	double ergebnisInt;
	ergebnisInt = y1+((y2-y1)/(x2-x1))*(wert-x1);
	return ergebnisInt;
}



	