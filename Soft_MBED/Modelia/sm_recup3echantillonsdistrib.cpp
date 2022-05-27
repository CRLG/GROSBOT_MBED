/**
 * Generated 28_05_2022 at 00_17
 */

#include "sm_recup3echantillonsdistrib.h"
#include "CGlobale.h"

SM_Recup3EchantillonsDistrib::SM_Recup3EchantillonsDistrib()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_Recup3EchantillonsDistrib::getName()
{
	return "SM_Recup3EchantillonsDistrib";
}

const char* SM_Recup3EchantillonsDistrib::stateToName(unsigned short state)
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
		case STATE_9 :		return "STATE_9";
		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_Recup3EchantillonsDistrib::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(10,-38,0);/*face distri*/
		}

			gotoStateIfConvergence(STATE_2,3000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(13,230);/*elevateur bas*/
		}

			gotoStateAfter(STATE_3,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_3 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(14,5);/*pince ouverte*/
		}

			gotoStateAfter(STATE_4,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_4 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_sym(0,-38);/*proche distri*/
		}

			gotoStateIfConvergence(STATE_5,3000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_5 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(-8,-8);/*on finit en manuel*/
		}

			gotoStateAfter(STATE_6,3000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_6 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(0,0);/*on arrete*/
		}

			gotoStateAfter(STATE_7,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_7 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(14,255);/*pince fermee*/
		}

			gotoStateAfter(STATE_8,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_8 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(13,150);/*elevateur milieu*/
		}

			gotoStateAfter(STATE_9,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_9 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(13,-38,1.57);/*on  ecarte le robot*/
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
