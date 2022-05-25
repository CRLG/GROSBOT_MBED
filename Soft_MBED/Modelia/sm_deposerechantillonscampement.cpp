/**
 * Generated 25_05_2022 at 09_24
 */

#include "sm_deposerechantillonscampement.h"
#include "CGlobale.h"

SM_DeposerEchantillonsCampement::SM_DeposerEchantillonsCampement()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_DeposerEchantillonsCampement::getName()
{
	return "SM_DeposerEchantillonsCampement";
}

const char* SM_DeposerEchantillonsCampement::stateToName(unsigned short state)
{
	switch(state)
	{
		case STATE_1 :		return "STATE_1";
		case STATE_2 :		return "STATE_2";
		case STATE_3 :		return "STATE_3";
		case STATE_4 :		return "STATE_4";
		case STATE_5 :		return "STATE_5";
		case STATE_6 :		return "STATE_6";
		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_DeposerEchantillonsCampement::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
			outputs()->setPosition_XYTeta_sym(0,0,1.57);/**/
		}

			gotoStateAfter(STATE_2,50);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(0,20,0);/**/
		}

			gotoStateIfConvergence(STATE_3,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_3 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(97,20,-1.57);/**/
		}

			gotoStateIfConvergence(STATE_4,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_4 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(97,-16,3.14);/**/
		}

			gotoStateIfConvergence(STATE_5,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_5 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(9,-16,3.14);/**/
		}

			gotoStateIfConvergence(STATE_6,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_6 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(50,-16,3.14);/**/
		}

			gotoStateIfConvergence(FIN_MISSION,5000);
		if (onExit()) {  }
		break;

	// ___________________________
	case FIN_MISSION :
		m_succes = true;
		m_score = m_max_score;
		stop();
		break;
	}
}
