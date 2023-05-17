/**
 * Generated 17_05_2023 at 17_32
 */

#include "sm_lancercerises.h"
#include "CGlobale.h"

SM_LancerCerises::SM_LancerCerises()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_LancerCerises::getName()
{
	return "SM_LancerCerises";
}

const char* SM_LancerCerises::stateToName(unsigned short state)
{
	switch(state)
	{
		case STATE_1 :		return "STATE_1";
		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_LancerCerises::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(0,0,0);/**/
		}

			gotoStateAfter(FIN_MISSION, 4000);
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
