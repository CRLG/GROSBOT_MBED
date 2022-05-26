/**
 * Generated 26_05_2022 at 08_27
 */

#include "sm_recupstatuette.h"
#include "CGlobale.h"

SM_RecupStatuette::SM_RecupStatuette()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_RecupStatuette::getName()
{
	return "SM_RecupStatuette";
}

const char* SM_RecupStatuette::stateToName(unsigned short state)
{
	switch(state)
	{
		case STATE_1 :		return "STATE_1";
		case NODE_0 :		return "NODE_0";
		case JAUNE :		return "JAUNE";
		case BLEU :		return "BLEU";
		case NODE_1 :		return "NODE_1";
		case STATE_6 :		return "STATE_6";
		case STATE_7 :		return "STATE_7";
		case STATE_8 :		return "STATE_8";
		case STATE_9 :		return "STATE_9";
		case STATE_10 :		return "STATE_10";
		case STATE_11 :		return "STATE_11";
		case STATE_12 :		return "STATE_12";
		case STATE_13 :		return "STATE_13";
		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_RecupStatuette::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(32,-55,-2.3);/**/
		}

			gotoStateIfConvergence(NODE_0,5000);
		if (onExit()) {  /*Un seul lien vers un noeud: Ne rien mettre ici  (cf doc Modélia)*/  }
		break;
	// ___________________________
	case NODE_0 :
		if (onEntry()) {
			/*Ne rien mettre ici (cf doc Modélia)*/
		}

            gotoStateIfTrue(BLEU,internals()->couleur_equipe==EQUIPE_BLEU);
            gotoStateIfTrue(JAUNE,internals()->couleur_equipe==EQUIPE_JAUNE);
		if (onExit()) {  /* Mettre ici le code du onExit de létat STATE_1 car un seul lien avant le noeud (cf doc Modélia)*/  }
		break;
	// ___________________________
	case JAUNE :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(22,-77,-2.3);/**/
		}

			gotoStateIfConvergence(NODE_1,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case BLEU :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(10,63,2.3);/**/
		}

			gotoStateIfConvergence(NODE_1,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case NODE_1 :
		if (onEntry()) {
			/*Ne rien mettre ici (cf doc Modélia)*/
			Application.m_kmar.start(3);/*mouvement MOUVEMENT_PRISE_STATUETTE*/
		}
        else {
            gotoStateIfConvergenceKmar(STATE_6,4000);
        }
		if (onExit()) {  /*Ne rien mettre ici  (cf doc Modélia)*/  }
		break;
	// ___________________________
	case STATE_6 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(5,5);/**/
		}

			gotoStateAfter(STATE_7,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_7 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(22,-77,-2.3);/**/
		}

			gotoStateIfConvergence(STATE_8,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_8 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(18,41,2.3);/**/
		}

			gotoStateIfConvergence(STATE_9,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_9 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(1,66,1.57);/**/
		}

			gotoStateIfConvergence(STATE_10,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_10 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(5,5);/**/
		}

			gotoStateAfter(STATE_11,250);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_11 :
		if (onEntry()) {
            Application.m_kmar.start(MOUVEMENT_APPRENTISSAGE_CHARIOT);/*mouvement MOUVEMENT_POSER_STATUETTE_SUR_VITRINE*/
		}

			gotoStateIfConvergenceKmar(STATE_12,1000);
        if (onExit()) {
            Application.m_kmar.releaseObject();  // Relarche l'objet
        }
		break;
	// ___________________________
	case STATE_12 :
		if (onEntry()) {
			Application.m_messenger_xbee_ntw.m_database.m_CommandeExperience.ExperienceCmd = Message_COMMANDE_EXPERIENCE::EXPERIENCE_CMD_START;
		}

            gotoStateAfter(STATE_13,1000);  // Cette tempo permet aussi d'être certain que la pression est dégagée et que l'objet est libéré
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_13 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(1,66,1.57);/**/
		}

            gotoStateIfConvergence(STATE_14,5000);
        if (onExit()) {
            Application.m_kmar.start(MOUVEMENT_INIT);  // Range le bras pour finir
        }
		break;

        // ___________________________
        case STATE_14 :
            if (onEntry()) {
            }

            gotoStateAfter(FIN_MISSION, 40000);
            if (onExit()) {
            }
            break;

    // ___________________________
	case FIN_MISSION :
		m_succes = true;
		m_score = m_max_score;
		stop();
		break;
	}
}
