/**
 * Generated 10_11_2020 at 00_35
 */

#include "sm_recupboueesdistributeur.h"
#include "CGlobale.h"

SM_RecupBoueesDistributeur::SM_RecupBoueesDistributeur()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_RecupBoueesDistributeur::getName()
{
	return "SM_RecupBoueesDistributeur";
}

const char* SM_RecupBoueesDistributeur::stateToName(unsigned short state)
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
		case STATE_18 :		return "STATE_18";
		case STATE_19 :		return "STATE_19";
		case STATE_20 :		return "STATE_20";
		case STATE_21 :		return "STATE_21";
		case STATE_22 :		return "STATE_22";
		case STATE_23 :		return "STATE_23";
		case STATE_24 :		return "STATE_24";
		case STATE_25 :		return "STATE_25";
		case STATE_26 :		return "STATE_26";
		case STATE_27 :		return "STATE_27";
		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_RecupBoueesDistributeur::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
			Application.m_asservissement_chariot.setConsigne(600);/*rack haut*/
		}

			gotoStateIfConvergenceRack(STATE_2,2000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(70,45,1.57);/*face au distributeur*/
		}

			gotoStateIfConvergence(STATE_3,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_3 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(13,220);/*ouverture pince 1*/
		}

			gotoStateAfter(STATE_4,300);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_4 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(14,215);/*ouverture pince 2*/
		}

			gotoStateAfter(STATE_5,300);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_5 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(15,50);/*ouverture pince 3*/
		}

			gotoStateAfter(STATE_6,300);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_6 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(16,230);/*ouverture pince 4*/
		}

			gotoStateAfter(STATE_7,300);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_7 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(17,230);/*ouverture pince 5*/
		}

			gotoStateAfter(STATE_8,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_8 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(8,7);/**/
		}

			gotoStateAfter(STATE_9,2000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_9 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(0,0);/**/
		}

			gotoStateAfter(STATE_10,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_10 :
		if (onEntry()) {
			Application.m_asservissement_chariot.setConsigne(-100);/*rack bas*/
		}

			gotoStateIfConvergenceRack(STATE_11,3000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_11 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(13,25);/*fermeture toutes pinces (pince 1)*/
		}

			gotoStateAfter(STATE_12,300);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_12 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(14,25);/*fermeture toutes pinces (pince 2)*/
		}

			gotoStateAfter(STATE_13,300);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_13 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(15,240);/*fermeture toutes pinces (pince 3)*/
		}

			gotoStateAfter(STATE_14,300);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_14 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(16,50);/*fermeture toutes pinces (pince 4)*/
		}

			gotoStateAfter(STATE_15,300);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_15 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(17,60);/*fermeture toutes pinces (pince 5)*/
		}

			gotoStateAfter(STATE_16,1500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_16 :
		if (onEntry()) {
			Application.m_asservissement_chariot.setConsigne(600);/*rack haut*/
		}

			gotoStateIfConvergenceRack(STATE_17,2000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_17 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementDistanceAngle(-15,1.57);/*eloignement bordure*/
		}

			gotoStateIfConvergence(STATE_18,2000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_18 :
		if (onEntry()) {
			Application.m_asservissement_chariot.setConsigne(200);/*rack milieu*/
		}

			gotoStateIfConvergenceRack(STATE_19,2000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_19 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(13,40,-1.57);/**/
		}

			gotoStateIfConvergence(STATE_20,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_20 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(13,36,-1.57);/**/
		}

			gotoStateIfConvergence(STATE_21,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_21 :
		if (onEntry()) {
			Application.m_asservissement_chariot.setConsigne(0);/*rack moyen*/
		}

			gotoStateIfConvergenceRack(STATE_22,2000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_22 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(13,90);/*ouverture toutes pinces (pince 1)*/
		}

			gotoStateAfter(STATE_23,300);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_23 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(14,90);/*ouverture toutes pinces (pince 2)*/
		}

			gotoStateAfter(STATE_24,300);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_24 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(16,110);/*ouverture toutes pinces (pince 4)*/
		}

			gotoStateAfter(STATE_25,300);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_25 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(17,110);/*ouverture toutes pinces (pince 5)*/
		}

			gotoStateAfter(STATE_26,1500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_26 :
		if (onEntry()) {
			Application.m_asservissement_chariot.setConsigne(600);/*rack haut pour liberer gobelets*/
		}

			gotoStateIfConvergenceRack(STATE_27,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_27 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementDistanceAngle(-10,1.57);/*reculer en dehors zone depose*/
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
