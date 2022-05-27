/**
 * Generated 28_05_2022 at 00_17
 */

#include "sm_recupstatuette.h"
#include "CGlobale.h"

SM_RecupStatuette::SM_RecupStatuette()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_RecupStatuette::getName()
{
	return "SM_RecupStatuette";
}

const char* SM_RecupStatuette::stateToName(unsigned short state)
{
	switch(state)
	{
		case STATE_1 :		return "STATE_1";
		case STATE_2 :		return "STATE_2";
		case STATE_3 :		return "STATE_3";
		case STATE_4 :		return "STATE_4";
		case STATE_5 :		return "STATE_5";
		case STATE_6 :		return "STATE_6";
		case STATE_7 :		return "STATE_7";
		case STATE_8 :		return "STATE_8";
		case STATE_9 :		return "STATE_9";
		case STATE_10 :		return "STATE_10";
		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_RecupStatuette::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(25,-62,-2.3);/*face a abris*/
		}

			gotoStateIfConvergence(STATE_2,4000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			Application.m_kmar.start(3);/*prise statuette*/
		}

			gotoStateIfConvergenceKmar(STATE_3,4000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_3 :
		if (onEntry()) {
			Application.m_kmar.catchObject();/*prendre un objet avec le bras robotise*/
		}

			gotoStateAfter(STATE_4,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_4 :
		if (onEntry()) {
			Application.m_asservissement_chariot.setConsigne(550);/**/
		}

			gotoStateIfConvergenceRack(STATE_5,4000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_5 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(12,-75,-2.3);/*tres proche abris*/
		}

			gotoStateIfConvergence(STATE_6,4000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_6 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(8,8);/*on finit en manuel*/
		}

			gotoStateAfter(STATE_7,1500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_7 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(0,0);/**/
		}

			gotoStateAfter(STATE_8,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_8 :
		if (onEntry()) {
			Application.m_asservissement_chariot.setConsigne(0);/**/
		}

			gotoStateIfTrue(STATE_9,Application.m_kmar.isObjectCatched(),4000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_9 :
		if (onEntry()) {
			Application.m_kmar.start(8);/*lever statuette*/
		}

			gotoStateIfConvergenceKmar(STATE_10,4000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_10 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(29,-56,-2.3);/*eloigne de abris*/
		}

			gotoStateIfConvergence(FIN_MISSION,4000);
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
