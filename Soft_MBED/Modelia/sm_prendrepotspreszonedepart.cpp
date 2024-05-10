/**
 * Generated 10_05_2024 at 10_58
 */

#include "sm_prendrepotspreszonedepart.h"
#include "CGlobale.h"

SM_PrendrePotsPresZoneDepart::SM_PrendrePotsPresZoneDepart()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_PrendrePotsPresZoneDepart::getName()
{
	return "SM_PrendrePotsPresZoneDepart";
}

const char* SM_PrendrePotsPresZoneDepart::stateToName(unsigned short state)
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
		case STATE_10 :		return "STATE_10";
		case STATE_11 :		return "STATE_11";
		case STATE_12 :		return "STATE_12";
		case STATE_13 :		return "STATE_13";
		case STATE_14 :		return "STATE_14";
		case STATE_15 :		return "STATE_15";
		case STATE_16 :		return "STATE_16";
		case STATE_17 :		return "STATE_17";
		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_PrendrePotsPresZoneDepart::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(18,1);/*INCLINE_PLANTE BAISSE*/
		}

			gotoStateAfter(STATE_2,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(19,255);/*PINCE_OUVERTE*/
		}

			gotoStateAfter(STATE_3,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_3 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(89,-104,2.01);/**/
		}

			gotoStateIfConvergence(STATE_4,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_4 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(19,80);/*PINCE_FERMEE*/
		}

			gotoStateAfter(STATE_5,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_5 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(18,180);/*INCLINE_PLANTE_LEVE*/
		}

			gotoStateAfter(STATE_6,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_6 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(45,-33,0);/**/
		}

			gotoStateIfConvergence(STATE_7,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_7 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(17,-33,0);/**/
		}

			gotoStateIfConvergence(STATE_8,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_8 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(15,200);/*LEVER_TIGE_POUR_POTS*/
		}

			gotoStateAfter(STATE_9,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_9 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(-3,-3);/**/
		}

			gotoStateAfter(STATE_10,4000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_10 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(0,0);/**/
		}

			gotoStateAfter(STATE_11,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_11 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(64,-33,0);/**/
		}

			gotoStateIfConvergence(STATE_12,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_12 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(64,-145,0);/**/
		}

			gotoStateIfConvergence(STATE_13,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_13 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(5,-145,0);/**/
		}

			gotoStateIfConvergence(STATE_14,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_14 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(15,1);/*POTS_POUSSES*/
		}

			gotoStateAfter(STATE_15,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_15 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(19,255);/*PINCE_OUVERTE*/
		}

			gotoStateAfter(STATE_16,2000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_16 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(60,-145,0);/**/
		}

			gotoStateIfConvergence(STATE_17,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_17 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(19,80);/*PINCE_FERMEE*/
		}

			gotoStateAfter(FIN_MISSION,1000);
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
