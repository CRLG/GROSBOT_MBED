/**
 * Generated 27_05_2022 at 03_32
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
		case STATE_11 :		return "STATE_11";
		case STATE_12 :		return "STATE_12";
		case STATE_13 :		return "STATE_13";
		case STATE_14 :		return "STATE_14";
		case STATE_15 :		return "STATE_15";
		case STATE_16 :		return "STATE_16";
		case STATE_17 :		return "STATE_17";
		case STATE_18 :		return "STATE_18";
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

			gotoStateIfConvergence(STATE_11,4000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_11 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(1,35,1.57);/**/
			
			internals()->evit_inhibe_obstacle=false;

		}

			gotoStateIfConvergence(STATE_12,4000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_12 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(1,73,1.57);/**/
		}

			gotoStateIfConvergence(STATE_13,4000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_13 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(8,8);/*on finit en manuel*/
		}

			gotoStateAfter(STATE_14,1500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_14 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(0,0);/**/
		}

			gotoStateAfter(STATE_15,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_15 :
		if (onEntry()) {
			Application.m_kmar.start(4);/*liberer statuette*/
		}

			gotoStateIfConvergenceKmar(STATE_16,4000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_16 :
		if (onEntry()) {
			Application.m_kmar.releaseObject();/*relacher un objet par le bras robotise*/
		}

			gotoStateAfter(STATE_17,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_17 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(1,64,1.57);/*eloigne de vitrine*/
		}

			gotoStateIfConvergence(STATE_18,4000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_18 :
		if (onEntry()) {
			Application.m_kmar.start(1);/*kmar init*/
			
			internals()->evit_inhibe_obstacle=false;

		}

			gotoStateIfConvergenceKmar(FIN_MISSION,4000);
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
