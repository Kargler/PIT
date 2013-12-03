#ifndef FLIPFLOP_H
#define FLIPFLOP_H
#include "Gattertyp.h"

class Flipflop : public Gattertyp
{
private:
	short setupTime;
	short holdTime;
	short lastKapazitaetClock;
	
	
public:	
	Flipflop(void);
	~Flipflop(void);
	virtual bool getIsFlipflop(){
		return true;
	}
	short getSetupTime(){
		return setupTime;
	}
	short getHoldTime(){
		return holdTime;
	}
	short getLastKapazitaetClock(){
		return lastKapazitaetClock;
	}

	void setSetupTime(short st){
		setupTime = st;
	}
	void setHoldTime(short ht){
		holdTime = ht;
	}
	void setLastKapazitaetClock(short lkc){
		lastKapazitaetClock = lkc;
	}
	

};

#endif;