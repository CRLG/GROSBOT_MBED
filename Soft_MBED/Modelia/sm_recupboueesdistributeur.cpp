/**
 * Generated 08_04_2020 at 11_39
 */

#include "sm_recupboueesdistributeur.h"
#include "CGlobale.h"

SM_RecupBoueesDistributeur::SM_RecupBoueesDistributeur()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_RecupBoueesDistributeur::getName()
{
	return "SM_RecupBoueesDistributeur";
}

const char* SM_RecupBoueesDistributeur::stateToName(unsigned short state)
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
		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_RecupBoueesDistributeur::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(52,5,-1.57);/**/
		}

			gotoStateIfConvergence(STATE_2,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY(80,40);/**/
		}

			gotoStateIfConvergence(STATE_3,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_3 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementDistanceAngle(0,-1.57);/**/
		}

			gotoStateIfConvergence(STATE_4,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_4 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(80,53,-1.57);/**/
		}

			gotoStateIfConvergence(STATE_5,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_5 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(80,45,0);/**/
		}

			gotoStateIfConvergence(STATE_6,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_6 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(10,45,0);/**/
		}

			gotoStateIfConvergence(STATE_7,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_7 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(68,45,1.57);/**/
		}

			gotoStateIfConvergence(STATE_8,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_8 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(68,53,1.57);/**/
		}

			gotoStateIfConvergence(STATE_9,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_9 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(68,45,0);/**/
		}

			gotoStateIfConvergence(STATE_10,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_10 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(10,45,-1.57);/**/
		}

			gotoStateIfConvergence(STATE_11,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_11 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(10,35,-1.57);/**/
		}

			gotoStateIfConvergence(STATE_12,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_12 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(10,45,-1.57);/**/
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
