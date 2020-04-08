/**
 * Generated 08_04_2020 at 11_38
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
			Application.m_asservissement.CommandeMouvementXY_TETA(60,2,0.3);/**/
		}

			gotoStateIfConvergence(STATE_2,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(128,23,0);/*TODO profiter d'etre dans le coin pour reconnaitre nord-sud*/
		}

			gotoStateIfConvergence(STATE_3,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_3 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(30,23,0);/**/
		}

			gotoStateIfConvergence(STATE_4,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_4 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(40,23,1.57);/**/
		}

			gotoStateIfConvergence(STATE_5,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_5 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(40,45,0);/**/
		}

			gotoStateIfConvergence(STATE_6,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_6 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(10,45,1.57);/**/
		}

			gotoStateIfConvergence(STATE_7,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_7 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(10,30,1.57);/**/
		}

			gotoStateIfConvergence(STATE_8,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_8 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(10,40,1.57);/*TODO ranger les actionneurs*/
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
