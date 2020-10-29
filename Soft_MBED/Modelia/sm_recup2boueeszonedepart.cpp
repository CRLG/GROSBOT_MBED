/**
 * Generated 27_10_2020 at 19_25
 */

#include "sm_recup2boueeszonedepart.h"
#include "CGlobale.h"

SM_Recup2BoueesZoneDepart::SM_Recup2BoueesZoneDepart()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_Recup2BoueesZoneDepart::getName()
{
	return "SM_Recup2BoueesZoneDepart";
}

const char* SM_Recup2BoueesZoneDepart::stateToName(unsigned short state)
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
		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_Recup2BoueesZoneDepart::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(65,-4,3.14);/**/
		}

			gotoStateIfConvergence(STATE_2,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(85,-4,3.14);/**/
		}

			gotoStateIfConvergence(STATE_3,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_3 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(19,220);/*baisser arceau*/
		}

			gotoStateAfter(STATE_4,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_4 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(80,-5,-1.57);/**/
		}

			gotoStateIfConvergence(STATE_5,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_5 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(19,25);/*lever arceau*/
		}

			gotoStateAfter(STATE_6,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_6 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(80,16,-1.57);/**/
		}

			gotoStateIfConvergence(STATE_7,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_7 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(19,220);/*baisser arceau*/
		}

			gotoStateAfter(STATE_8,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_8 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(63,16,-1.57);/**/
		}

			gotoStateIfConvergence(STATE_9,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_9 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(19,25);/*lever arceau*/
		}

			gotoStateAfter(STATE_10,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_10 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(63,46,-1.57);/**/
		}

			gotoStateIfConvergence(STATE_11,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_11 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(19,220);/*baisser arceau*/
		}

			gotoStateAfter(STATE_12,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_12 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(48,36,-2.54);/**/
		}

			gotoStateIfConvergence(STATE_13,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_13 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(12,13,-2.54);/**/
		}

			gotoStateIfConvergence(STATE_14,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_14 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(10,28,1.57);/**/
		}

			gotoStateIfConvergence(STATE_15,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_15 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(19,25);/*lever arceau*/
		}

			gotoStateAfter(STATE_16,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_16 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(10,43,1.57);/**/
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
