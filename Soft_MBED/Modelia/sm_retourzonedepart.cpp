/**
 * Generated 28_05_2022 at 01_21
 */

#include "sm_retourzonedepart.h"
#include "CGlobale.h"

SM_RetourZoneDepart::SM_RetourZoneDepart()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_RetourZoneDepart::getName()
{
	return "SM_RetourZoneDepart";
}

const char* SM_RetourZoneDepart::stateToName(unsigned short state)
{
	switch(state)
	{
		case STATE_1 :		return "STATE_1";
		case STATE_2 :		return "STATE_2";
		case STATE_3 :		return "STATE_3";
		case STATE_4 :		return "STATE_4";
		case STATE_5 :		return "STATE_5";
		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_RetourZoneDepart::step()
{
	switch (m_state)
	{


    case STATE_1 :
		if (onEntry()) {
            outputs()->CommandeMouvementXY_sym(0,0);/**/
		}

            gotoStateIfConvergence(FIN_MISSION,20000);
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
