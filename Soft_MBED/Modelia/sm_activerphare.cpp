/**
 * Generated 08_04_2020 at 11_37
 */

#include "sm_activerphare.h"
#include "CGlobale.h"

SM_ActiverPhare::SM_ActiverPhare()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_ActiverPhare::getName()
{
	return "SM_ActiverPhare";
}

const char* SM_ActiverPhare::stateToName(unsigned short state)
{
	switch(state)
	{
		case STATE_1 :		return "STATE_1";
		case ACTIVER_PHARE :		return "ACTIVER_PHARE";
		case VERIFIER_PHARE :		return "VERIFIER_PHARE";
		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_ActiverPhare::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(10,45,-1.57);/**/
		}

			gotoStateIfConvergence(ACTIVER_PHARE,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case ACTIVER_PHARE :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(10,53,-1.57);/**/
		}

			gotoStateIfConvergence(VERIFIER_PHARE,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case VERIFIER_PHARE :
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
