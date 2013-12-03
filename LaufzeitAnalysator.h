#ifndef LAUFZEITANALYSATOR_H
#define LAUFZEITANALYSATOR_H

#include "GraphErzeuger.h"
#include "ListenElement.h"
#include "Faktoren.h"

class LaufzeitAnalysator
{
private:
	double k_T, k_V, k_P;
	double c_L;
	double k_L;
	double t_PD0;
	double t_PD_actual;
	double t_PD_max;

	bool laufzeitAnalyseFlag;

	double berechneGatterLaufzeit();
	
	//Noch zu definieren:
	void checkIfStartpunkt();
	;

public:
	LaufzeitAnalysator();
	~LaufzeitAnalysator();

	void dfs(SchaltwerkElement* s);
	void dfs_visit(SchaltwerkElement* k, SchaltwerkElement* s);

	//Noch zu definieren:
	//get & set Schnitstellen (call by reference/pointer)






};

#endif