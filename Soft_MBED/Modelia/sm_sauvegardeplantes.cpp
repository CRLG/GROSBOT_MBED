/**
 * Generated 10_05_2024 at 08_10
 */

#include "sm_sauvegardeplantes.h"
#include "CGlobale.h"

SM_SauvegardePlantes::SM_SauvegardePlantes()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_SauvegardePlantes::getName()
{
	return "SM_SauvegardePlantes";
}

const char* SM_SauvegardePlantes::stateToName(unsigned short state)
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
		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_SauvegardePlantes::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(87,-131,1.57);/*Pret pour le nettoyage*/
		}

			gotoStateIfConvergence(STATE_2,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(13,140);/*GROSSE TAPETTE LEVE*/
		}

			gotoStateAfter(STATE_3,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_3 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(88,-22,1.57);/*Ligne droite de nettoyage*/
		}

			gotoStateIfConvergence(STATE_4,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_4 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(13,220);/*GROSSE TAPETTE BAISSE*/
		}

			gotoStateAfter(STATE_5,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_5 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(21,2,2.8);/*Direct dans la zone de départ*/
		}

			gotoStateIfConvergence(STATE_6,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_6 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(13,140);/*GROSSE TAPETTE LEVE*/
		}

			gotoStateAfter(STATE_7,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_7 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(18,1);/*INCLINE_PLANTE BAISSE*/
		}

			gotoStateAfter(STATE_8,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_8 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(19,255);/*PINCE OUVERT*/
		}

			gotoStateAfter(STATE_9,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_9 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(154,-24,2.81);/*pret pour pincer plantes milieu*/
		}

			gotoStateIfConvergence(STATE_10,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_10 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(13,220);/*GROSSE TAPETTE BAISSE*/
		}

			gotoStateAfter(STATE_11,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_11 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(19,80);/*PINCE FERME*/
		}

			gotoStateAfter(STATE_12,1500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_12 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(18,180);/*INCLINE_PLANTE_LEVE*/
		}

			gotoStateAfter(STATE_13,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_13 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(63,3,-1.57);/**/
		}

			gotoStateIfConvergence(STATE_14,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_14 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(-3,-3);/*accostage jardinière en douceur*/
		}

			gotoStateAfter(STATE_15,2000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_15 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(0,0);/**/
		}

			gotoStateAfter(STATE_16,50);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_16 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(18,160);/*INCLINE_PLANTE presque BAISSE*/
		}

			gotoStateAfter(STATE_17,750);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_17 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(19,255);/*PINCE OUVERT*/
		}

			gotoStateAfter(STATE_18,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_18 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(19,80);/*PINCE FERME*/
		}

			gotoStateAfter(STATE_19,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_19 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(19,255);/*PINCE OUVERT*/
		}

			gotoStateAfter(STATE_20,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_20 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(62,-23,-1.57);/*écarté de la jardinière*/
		}

			gotoStateIfConvergence(STATE_21,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_21 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(261,-66,-0.37);/*rechargement des batteries*/
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
