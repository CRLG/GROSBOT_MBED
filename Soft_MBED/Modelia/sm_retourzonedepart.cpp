/**
 * Generated 25_05_2022 at 09_20
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
		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_RetourZoneDepart::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(55,5,3.14);/**/
		}

			gotoStateIfConvergence(STATE_2,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_sym(19,5);/**/
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
