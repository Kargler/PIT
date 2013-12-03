#ifndef GATTERTYP_H
#define GATTERTYP_H
  
#include <string>

using namespace std;

class Gattertyp {
public:
	Gattertyp();
	virtual ~Gattertyp();

	string getName(){
		return name;
	}
	double getGrundLaufzeit(){
		return grundLaufzeit;
	}
	short  getLastFaktor(){
		return lastFaktor;
	}
	short  getLastkapazität(){
		return lastKapazitaet;
	}
	short  getEingaenge(){
		return eingaenge;
	}
	virtual bool getIsFlipflop(){
		return false;
	};

	void   setName(string n){
		name = n;
	}
	void   setGrundlaufzeit(double gl){
		grundLaufzeit = gl;
	};
	void   setLastfaktor(short lf){
		lastFaktor = lf;
	}
	void   setLastkapazitaet(short lk){
		lastKapazitaet = lk;
	}
	void   setEingaenge(short ei){
		eingaenge = ei;
	}
protected:
	string name;
	double grundLaufzeit;
	short  lastFaktor;
	short  lastKapazitaet;
	short  eingaenge;

};

#endif;