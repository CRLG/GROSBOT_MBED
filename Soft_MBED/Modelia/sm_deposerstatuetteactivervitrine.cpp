/**
 * Generated 28_05_2022 at 00_18
 */

#include "sm_deposerstatuetteactivervitrine.h"
#include "CGlobale.h"

SM_DeposerStatuetteActiverVitrine::SM_DeposerStatuetteActiverVitrine()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_DeposerStatuetteActiverVitrine::getName()
{
	return "SM_DeposerStatuetteActiverVitrine";
}

const char* SM_DeposerStatuetteActiverVitrine::stateToName(unsigned short state)
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
		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_DeposerStatuetteActiverVitrine::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(3,35,1.57);/**/
			
			internals()->evit_inhibe_obstacle=false;

		}

			gotoStateIfConvergence(STATE_2,4000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(1,73,1.57);/**/
		}

			gotoStateIfConvergence(STATE_3,4000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_3 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(8,8);/*on finit en manuel*/
		}

			gotoStateAfter(STATE_4,1500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_4 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(0,0);/**/
		}

			gotoStateAfter(STATE_5,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_5 :
		if (onEntry()) {
			Application.m_kmar.start(4);/*liberer statuette*/
		}

			gotoStateIfConvergenceKmar(STATE_6,4000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_6 :
		if (onEntry()) {
			Application.m_kmar.releaseObject();/*relacher un objet par le bras robotise*/
		}

			gotoStateAfter(STATE_7,1500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_7 :
		if (onEntry()) {
			
			Application.m_messenger_xbee_ntw.m_database.m_CommandeExperience.ExperienceCmd = Message_COMMANDE_EXPERIENCE::EXPERIENCE_CMD_START;

			outputs()->CommandeMouvementXY_TETA_sym(1,64,1.57);/*eloigne de vitrine*/
		}

			gotoStateIfConvergence(STATE_8,4000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_8 :
		if (onEntry()) {
			Application.m_kmar.start(1);/*kmar init*/
			
			internals()->evit_inhibe_obstacle=false;

		}

			gotoStateIfConvergenceKmar(FIN_MISSION,4000);
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
