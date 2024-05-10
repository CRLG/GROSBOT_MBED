/**
 * Generated 09_05_2024 at 14_55
 */

#include "sm_prendreplantespreszonedepart.h"
#include "CGlobale.h"

SM_PrendrePlantesPresZoneDepart::SM_PrendrePlantesPresZoneDepart()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_PrendrePlantesPresZoneDepart::getName()
{
	return "SM_PrendrePlantesPresZoneDepart";
}

const char* SM_PrendrePlantesPresZoneDepart::stateToName(unsigned short state)
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
		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_PrendrePlantesPresZoneDepart::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
			Application.m_asservissement.setPosition_XYTeta(0,0,0);/**/
		}

			gotoStateAfter(STATE_2,50);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_sym(60,0);/**/
		}

			gotoStateIfConvergence(STATE_3,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_3 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(13,140);/*GROSSE_TAPETTE_LEVE*/
		}

			gotoStateAfter(STATE_4,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_4 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_sym(89,-45);/**/
		}

			gotoStateIfConvergence(STATE_5,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_5 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(13,220);/*GROSSE_TAPETTE_BAISSE*/
		}

			gotoStateAfter(STATE_6,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_6 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_sym(44,5);/**/
		}

			gotoStateIfConvergence(STATE_7,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_7 :
		if (onEntry()) {
			
			Application.m_detection_obstacles.inhibeDetection(true);

		}

			gotoStateAfter(STATE_8,100);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_8 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementDistanceAngle(0,3.14);/**/
		}

			gotoStateIfConvergence(STATE_9,3000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_9 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(13,140);/*GROSSE_TAPETTE_LEVE*/
		}

			gotoStateAfter(STATE_10,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_10 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_sym(12,5);/**/
		}

			gotoStateIfConvergence(STATE_11,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_11 :
		if (onEntry()) {
			
			Application.m_detection_obstacles.inhibeDetection(false);

		}

			gotoStateAfter(STATE_12,100);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_12 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(55,-39,3.14);/**/
		}

			gotoStateIfConvergence(STATE_13,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_13 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(13,220);/*GROSSE_TAPETTE_BAISSE*/
		}

			gotoStateAfter(FIN_MISSION,500);
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
