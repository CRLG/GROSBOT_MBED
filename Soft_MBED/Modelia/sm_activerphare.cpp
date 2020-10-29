/**
 * Generated 27_10_2020 at 22_21
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
void SM_ActiverPhare::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(10,43,1.57);/**/
		}

			gotoStateIfConvergence(STATE_2,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(14,30);/*servo rentre*/
			Application.m_moteurs.CommandeVitesse(1,7);/**/
			Application.m_moteurs.CommandeVitesse(2,7);/**/
		}

			gotoStateAfter(STATE_3,2000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_3 :
		if (onEntry()) {
			Application.m_moteurs.CommandeVitesse(1,0);/*stop*/
			Application.m_moteurs.CommandeVitesse(2,0);/*stop*/
		}

			gotoStateAfter(STATE_4,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_4 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(14,125);/*enclenchement*/
		}

			gotoStateAfter(STATE_5,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_5 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(14,30);/*servo rentre*/
		}

			gotoStateAfter(STATE_6,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_6 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementDistanceAngle(-15,0);/*retrait*/
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
