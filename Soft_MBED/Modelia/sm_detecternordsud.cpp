/**
 * Generated 01_11_2020 at 00_26
 */

#include "sm_detecternordsud.h"
#include "CGlobale.h"

SM_DetecterNordSud::SM_DetecterNordSud()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_DetecterNordSud::getName()
{
	return "SM_DetecterNordSud";
}

const char* SM_DetecterNordSud::stateToName(unsigned short state)
{
	switch(state)
	{
		case STATE_1 :		return "STATE_1";
		case STATE_2 :		return "STATE_2";
		case STATE_3 :		return "STATE_3";
		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_DetecterNordSud::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(70,20,1.57);/**/
		}

			gotoStateIfConvergence(STATE_2,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			
            Application.m_modelia.m_datas_interface.m_tx_value_03=1;

		}

			gotoStateAfter(STATE_3,1500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_3 :
		if (onEntry()) {
			
            Application.m_modelia.m_datas_interface.m_tx_value_03=0;

		}

			gotoStateAfter(FIN_MISSION,500);
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
