/**
 * Generated 17_05_2023 at 17_34
 */

#include "sm_chasseneige.h"
#include "CGlobale.h"

SM_ChasseNeige::SM_ChasseNeige()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_ChasseNeige::getName()
{
	return "SM_ChasseNeige";
}

const char* SM_ChasseNeige::stateToName(unsigned short state)
{
	switch(state)
	{
		case STATE_1 :		return "STATE_1";
		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_ChasseNeige::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
            Application.m_asservissement.CommandeMouvementXY(160,0);/**/
		}

            gotoStateAfter(FIN_MISSION, 20000);
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
