#include "LaufzeitAnalysator.h"

LaufzeitAnalysator::LaufzeitAnalysator() {
	k_P = 0;
	k_T = 0;
	k_V = 0;

	c_L = 0;
	k_L = 0;
	t_PD0 = 0;
	t_PD_actual = 0;

	laufzeitAnalyseFlag = false;
}
blaaaaaaa

LaufzeitAnalysator::~LaufzeitAnalysator() {}


double LaufzeitAnalysator::berechneGatterLaufzeit() {
	t_PD_actual = (t_PD0 + k_L * c_L) * k_T * k_V * k_P;
	return t_PD_actual;
}

void LaufzeitAnalysator::dfs(SchaltwerkElement* s) {
	

}

void LaufzeitAnalysator::dfs_visit(SchaltwerkElement* k, SchaltwerkElement* s) {


}
