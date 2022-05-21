/**
 * Generated 21_05_2022 at 00_14
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
			Application.m_asservissement.setPosition_XYTeta(0,0,1.57);/**/
		}

			gotoStateAfter(STATE_2,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(31.5,-88.5,-2.35);/**/
		}

			gotoStateIfConvergence(STATE_3,50000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_3 :
		if (onEntry()) {
			Application.m_kmar.start(2);/*mouvement index 3*/
		}

			gotoStateAfter(STATE_4,2500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_4 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(7,7);/**/
			Application.m_kmar.catchObject();/*prendre un objet avec le bras robotise*/
		}

			gotoStateIfObjetPris(STATE_5,2000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_5 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(20.5,-104.5,-2.35);/**/
		}

			gotoStateIfConvergence(STATE_6,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_6 :
		if (onEntry()) {
			Application.m_kmar.releaseObject();/*relacher un objet par le bras robotise*/
		}

			gotoStateAfter(FIN_MISSION,1000);
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
