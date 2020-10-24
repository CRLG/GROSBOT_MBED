/**
 * Generated 24_10_2020 at 18_14
 */

#include "sm_deployerpavillon.h"
#include "CGlobale.h"

SM_DeployerPavillon::SM_DeployerPavillon()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_DeployerPavillon::getName()
{
	return "SM_DeployerPavillon";
}

const char* SM_DeployerPavillon::stateToName(unsigned short state)
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
void SM_DeployerPavillon::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(20,185);/*20*/
		}

			gotoStateAfter(STATE_2,2000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(20,185);/*20*/
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
