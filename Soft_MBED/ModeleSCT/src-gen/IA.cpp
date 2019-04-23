
#include "IA.h"
#include <string.h>

/*! \file Implementation of the state machine 'IA'
*/


IA::IA():
	timer(null),
	stateConfVectorPosition(0),
	iface(),
	ifaceInternalSCI(),
	ifaceAsser(),
	ifaceServo(),
	ifaceAx(),
	ifaceMoteur(),
	ifaceChariot(),
	ifaceCapteur(),
	ifaceIhm()
{
	for (sc_ushort i = 0; i < maxHistoryStates; ++i)
		historyVector[i] = IA_last_state;
		
}

IA::~IA()
{
}

const int32_t IA::DefaultSCI::SERVO_VENTOUSE = 13;
const int32_t IA::DefaultSCI::SERVO_CENTREUR_G = 14;
const int32_t IA::DefaultSCI::SERVO_CENTREUR_D = 15;
const int32_t IA::DefaultSCI::SERVO_PINCE_D = 16;
const int32_t IA::DefaultSCI::SERVO_PINCE_G = 17;
const int32_t IA::DefaultSCI::SERVO_BALLE = 18;
const int32_t IA::DefaultSCI::SERVO_RECOLTEURS = 19;
const int32_t IA::DefaultSCI::SERVO_VOLET = 20;
const int32_t IA::DefaultSCI::AX_ROTATION = 1;
const int32_t IA::DefaultSCI::AX_COULEUR = 2;
const int32_t IA::DefaultSCI::AX_LEVIER = 4;
const int32_t IA::DefaultSCI::KMAR_SORTI = 180;
const int32_t IA::DefaultSCI::KMAR_RENTRE = 0;
const int32_t IA::DefaultSCI::KMAR_PRENDRE = 255;
const int32_t IA::DefaultSCI::VENTOUSE_G = 0;
const int32_t IA::DefaultSCI::VENTOUSE_D = 255;
const int32_t IA::DefaultSCI::KMAR_DROIT = 0;
const int32_t IA::DefaultSCI::MOTEUR_ROUE_GAUCHE = 1;
const int32_t IA::DefaultSCI::MOTEUR_ROUE_DROITE = 2;
const int32_t IA::DefaultSCI::MOTEUR_FUNNY = 3;
const int32_t IA::DefaultSCI::MOTEUR_MOELDAR = 5;
const int32_t IA::DefaultSCI::CODEUR_NON_DEFINI = 0;
const int32_t IA::DefaultSCI::CODEUR_CHARIOT = 1;
const int32_t IA::DefaultSCI::CODEUR_ROUE_DROITE = 2;
const int32_t IA::DefaultSCI::CODEUR_ROUE_GAUCHE = 3;
const int32_t IA::DefaultSCI::VIOLET = 0;
const int32_t IA::DefaultSCI::JAUNE = 1;
const float IA::DefaultSCI::PI = 3.14;


void IA::init()
{
	for (sc_ushort i = 0; i < maxOrthogonalStates; ++i)
		stateConfVector[i] = IA_last_state;
	
	for (sc_ushort i = 0; i < maxHistoryStates; ++i)
		historyVector[i] = IA_last_state;
	
	stateConfVectorPosition = 0;

	clearInEvents();
	clearOutEvents();
	
	/* Default init sequence for statechart IA */
	iface.IN_x_pos = 0.0;
	iface.IN_y_pos = 0.0;
	iface.IN_teta_pos = 0.0;
	iface.IN_vitesse = 0.0;
	iface.IN_sens_deplacement = 0.0;
	iface.IN_Couleur = 0;
	iface.IN_Obstacle = 0;
	iface.IN_Depression = false;
	iface.Couleur = 1;
	iface.countTimeMvt = 0;
	iface.tempsMatch = 0;
	iface.countTempo = 0;
	iface.countTempo2 = 0;
	iface.countTime = 0;
	iface.x_pos_mem = 0;
	iface.y_pos_mem = 0;
	iface.teta_pos_mem = 0;
	iface.nb_Modules = 1;
	ifaceInternalSCI.invMouv = 1;
	ifaceInternalSCI.Te = 0.02;
	ifaceInternalSCI.inhibeObstacle = false;
	ifaceInternalSCI.evitementEnCours = false;
	ifaceInternalSCI.evitementTempo = 0;
	ifaceInternalSCI.sequence1 = false;
	ifaceInternalSCI.sequence2 = false;
	ifaceInternalSCI.pos_fusee = -800;
	ifaceInternalSCI.nb_tentatives = 0;
	ifaceInternalSCI.etape = 0;
	ifaceAx.BRAS_OUVERT = 55;
	ifaceChariot.isReady = false;
	ifaceChariot.isConv = false;
}

void IA::enter()
{
	/* Default enter sequence for statechart IA */
	/* 'default' enter sequence for region main region */
	/* Default react sequence for initial entry  */
	/* 'default' enter sequence for state ATTENTE_TIRETTE */
	/* 'default' enter sequence for region null */
	/* Default react sequence for initial entry  */
	/* 'default' enter sequence for state ATTENTE_TIRETTE */
	/* 'default' enter sequence for region INIT */
	/* Default react sequence for initial entry  */
	/* 'default' enter sequence for state INIT */
	/* Entry action for state 'INIT'. */
	timer->setTimer(this, (sc_eventid)(&timeEvents[0]), 1 * 1000, false);
	Application.m_asservissement.CommandeManuelle(0, 0);
	Application.m_power_switch.setOutput(POMPE_ARG, false);
	Application.m_leds.setPattern(PATTERN_K2000, 50);
	stateConfVector[0] = main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_INIT;
	stateConfVectorPosition = 0;
	/* 'default' enter sequence for region CHOIX_COULEUR */
	/* Default react sequence for initial entry  */
	/* 'default' enter sequence for state CHOIX_COULEUR_VIOLET */
	/* Entry action for state 'CHOIX_COULEUR_VIOLET'. */
	iface.Couleur = IA::DefaultSCI::VIOLET;
	Application.m_leds.setPattern(PATTERN_K2000, 50);
	stateConfVector[1] = main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_VIOLET;
	stateConfVectorPosition = 1;
}

void IA::exit()
{
	/* Default exit sequence for statechart IA */
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of IA.main_region) at position 0... */
	switch(stateConfVector[ 0 ])
	{
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_INIT :
		{
			/* Default exit sequence for state INIT */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'INIT'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[0]));
			break;
		}
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_HAUTS :
		{
			/* Default exit sequence for state TOBOGGANS_HAUTS */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'TOBOGGANS_HAUTS'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[1]));
			break;
		}
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_APPRENTISSAGE_ASCENSEUR :
		{
			/* Default exit sequence for state APPRENTISSAGE_ASCENSEUR */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'APPRENTISSAGE_ASCENSEUR'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[2]));
			break;
		}
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_BAS :
		{
			/* Default exit sequence for state TOBOGGANS_BAS */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'TOBOGGANS_BAS'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[3]));
			break;
		}
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_01 :
		{
			/* Default exit sequence for state KMAR_RANGE_01 */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'KMAR_RANGE_01'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[4]));
			break;
		}
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_02 :
		{
			/* Default exit sequence for state KMAR_RANGE_02 */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_01 :
		{
			/* Default exit sequence for state KMAR_SORTI_01 */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'KMAR_SORTI_01'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[5]));
			break;
		}
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_02 :
		{
			/* Default exit sequence for state KMAR_SORTI_02 */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'KMAR_SORTI_02'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[6]));
			break;
		}
		case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT :
		{
			/* Default exit sequence for state ARRET_ROBOT */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'ARRET_ROBOT'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[8]));
			/* Exit action for state 'DETECTION_OBSTACLE'. */
			Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
			/* Exit action for state 'MATCH_EN_COURS'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[7]));
			break;
		}
		case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_SORTIE_EVITEMENT :
		{
			/* Default exit sequence for state SORTIE_EVITEMENT */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'DETECTION_OBSTACLE'. */
			Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
			/* Exit action for state 'MATCH_EN_COURS'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[7]));
			break;
		}
		case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_ :
		{
			/* Default exit sequence for final state. */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'DETECTION_OBSTACLE'. */
			Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
			/* Exit action for state 'MATCH_EN_COURS'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[7]));
			break;
		}
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS :
		{
			/* Default exit sequence for state DEPASSE_ZONE_CHAOS */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'DEPASSE_ZONE_CHAOS'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[9]));
			/* Exit action for state 'MATCH_EN_COURS'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[7]));
			break;
		}
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS :
		{
			/* Default exit sequence for state FACE_ZONE_CHAOS */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'FACE_ZONE_CHAOS'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[10]));
			/* Exit action for state 'MATCH_EN_COURS'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[7]));
			break;
		}
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART :
		{
			/* Default exit sequence for state STOCKAGE_DANS_ZONE_DEPART */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'STOCKAGE_DANS_ZONE_DEPART'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[11]));
			/* Exit action for state 'MATCH_EN_COURS'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[7]));
			break;
		}
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR :
		{
			/* Default exit sequence for state PLACEMENT_DEVANT_DISTRIBUTEUR */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'PLACEMENT_DEVANT_DISTRIBUTEUR'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[12]));
			/* Exit action for state 'MATCH_EN_COURS'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[7]));
			break;
		}
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES :
		{
			/* Default exit sequence for state VENTOUSAGE_ATOMES */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'VENTOUSAGE_ATOMES'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[13]));
			/* Exit action for state 'MATCH_EN_COURS'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[7]));
			break;
		}
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES :
		{
			/* Default exit sequence for state RECUPERATION_ATOMES */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'RECUPERATION_ATOMES'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[14]));
			/* Exit action for state 'MATCH_EN_COURS'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[7]));
			break;
		}
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES :
		{
			/* Default exit sequence for state DEVENTOUSAGE_ATOMES */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'MATCH_EN_COURS'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[7]));
			break;
		}
		case main_region_MATCH_EN_COURS__region0_SUPERVISOR :
		{
			/* Default exit sequence for state SUPERVISOR */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'MATCH_EN_COURS'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[7]));
			break;
		}
		case main_region_FIN_MATCH :
		{
			/* Default exit sequence for state FIN_MATCH */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		default: break;
	}
	/* Handle exit of all possible states (of IA.main_region) at position 1... */
	switch(stateConfVector[ 1 ])
	{
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_VIOLET :
		{
			/* Default exit sequence for state CHOIX_COULEUR_VIOLET */
			stateConfVector[1] = IA_last_state;
			stateConfVectorPosition = 1;
			break;
		}
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_JAUNE :
		{
			/* Default exit sequence for state CHOIX_COULEUR_JAUNE */
			stateConfVector[1] = IA_last_state;
			stateConfVectorPosition = 1;
			break;
		}
		default: break;
	}
}

sc_boolean IA::isActive() const
{
	return stateConfVector[0] != IA_last_state||stateConfVector[1] != IA_last_state;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean IA::isFinal() const
{
   return false;}

void IA::runCycle()
{
	
	clearOutEvents();
	for (stateConfVectorPosition = 0;
		stateConfVectorPosition < maxOrthogonalStates;
		stateConfVectorPosition++)
		{
			
		switch (stateConfVector[stateConfVectorPosition])
		{
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_INIT :
		{
			react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_INIT();
			break;
		}
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_HAUTS :
		{
			react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_HAUTS();
			break;
		}
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_APPRENTISSAGE_ASCENSEUR :
		{
			react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_APPRENTISSAGE_ASCENSEUR();
			break;
		}
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_BAS :
		{
			react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_BAS();
			break;
		}
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_01 :
		{
			react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_01();
			break;
		}
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_02 :
		{
			react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_02();
			break;
		}
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_01 :
		{
			react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_01();
			break;
		}
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_02 :
		{
			react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_02();
			break;
		}
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_VIOLET :
		{
			react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_VIOLET();
			break;
		}
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_JAUNE :
		{
			react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_JAUNE();
			break;
		}
		case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT :
		{
			react_main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT();
			break;
		}
		case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_SORTIE_EVITEMENT :
		{
			react_main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_SORTIE_EVITEMENT();
			break;
		}
		case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_ :
		{
			react_main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_();
			break;
		}
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS :
		{
			react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS();
			break;
		}
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS :
		{
			react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS();
			break;
		}
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART :
		{
			react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART();
			break;
		}
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR :
		{
			react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR();
			break;
		}
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES :
		{
			react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES();
			break;
		}
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES :
		{
			react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES();
			break;
		}
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES :
		{
			react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES();
			break;
		}
		case main_region_MATCH_EN_COURS__region0_SUPERVISOR :
		{
			react_main_region_MATCH_EN_COURS__region0_SUPERVISOR();
			break;
		}
		case main_region_FIN_MATCH :
		{
			react_main_region_FIN_MATCH();
			break;
		}
		default:
			break;
		}
	}
	clearInEvents();
}

void IA::clearInEvents()
{
	iface.EV_Tirette_raised = false;
	iface.EV_Obstacle_raised = false;
	iface.EV_ConvergenceMvt_raised = false;
	iface.EV_ConvergenceMvt_Rapide_raised = false;
	iface.EV_ConvergenceChariot_raised = false;
	timeEvents[0] = false; 
	timeEvents[1] = false; 
	timeEvents[2] = false; 
	timeEvents[3] = false; 
	timeEvents[4] = false; 
	timeEvents[5] = false; 
	timeEvents[6] = false; 
	timeEvents[7] = false; 
	timeEvents[8] = false; 
	timeEvents[9] = false; 
	timeEvents[10] = false; 
	timeEvents[11] = false; 
	timeEvents[12] = false; 
	timeEvents[13] = false; 
	timeEvents[14] = false; 
}

void IA::clearOutEvents()
{
}


void IA::setTimer(TimerInterface* timerInterface)
{
	this->timer = timerInterface;
}

TimerInterface* IA::getTimer()
{
	return timer;
}

void IA::raiseTimeEvent(sc_eventid evid)
{
	if ((evid >= (sc_eventid)timeEvents) && (evid < (sc_eventid)(&timeEvents[timeEventsCount])))
	{
		*(sc_boolean*)evid = true;
	}				
}

sc_boolean IA::isStateActive(IAStates state) const
{
	switch (state)
	{
		case main_region_ATTENTE_TIRETTE : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_ATTENTE_TIRETTE] >= main_region_ATTENTE_TIRETTE
				&& stateConfVector[SCVI_MAIN_REGION_ATTENTE_TIRETTE] <= main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_JAUNE);
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE] >= main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE
				&& stateConfVector[SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE] <= main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_JAUNE);
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_INIT : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE_INIT_INIT] == main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_INIT
			);
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_HAUTS : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE_INIT_TOBOGGANS_HAUTS] == main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_HAUTS
			);
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_APPRENTISSAGE_ASCENSEUR : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE_INIT_APPRENTISSAGE_ASCENSEUR] == main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_APPRENTISSAGE_ASCENSEUR
			);
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_BAS : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE_INIT_TOBOGGANS_BAS] == main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_BAS
			);
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_01 : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_01] == main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_01
			);
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_02 : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_02] == main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_02
			);
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_01 : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_01] == main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_01
			);
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_02 : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_02] == main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_02
			);
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_VIOLET : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_VIOLET] == main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_VIOLET
			);
		case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_JAUNE : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_JAUNE] == main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_JAUNE
			);
		case main_region_MATCH_EN_COURS : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MATCH_EN_COURS] >= main_region_MATCH_EN_COURS
				&& stateConfVector[SCVI_MAIN_REGION_MATCH_EN_COURS] <= main_region_MATCH_EN_COURS__region0_SUPERVISOR);
		case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_DETECTION_OBSTACLE] >= main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE
				&& stateConfVector[SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_DETECTION_OBSTACLE] <= main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_);
		case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_DETECTION_OBSTACLE_R1_ARRET_ROBOT] == main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT
			);
		case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_SORTIE_EVITEMENT : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_DETECTION_OBSTACLE_R1_SORTIE_EVITEMENT] == main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_SORTIE_EVITEMENT
			);
		case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_ : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_DETECTION_OBSTACLE_R1__FINAL_] == main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_
			);
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_NETTOYAGE] >= main_region_MATCH_EN_COURS__region0_NETTOYAGE
				&& stateConfVector[SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_NETTOYAGE] <= main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES);
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_NETTOYAGE_R1_DEPASSE_ZONE_CHAOS] == main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS
			);
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_NETTOYAGE_R1_FACE_ZONE_CHAOS] == main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS
			);
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_NETTOYAGE_R1_STOCKAGE_DANS_ZONE_DEPART] == main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART
			);
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_NETTOYAGE_R1_PLACEMENT_DEVANT_DISTRIBUTEUR] == main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR
			);
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_NETTOYAGE_R1_VENTOUSAGE_ATOMES] == main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES
			);
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_NETTOYAGE_R1_RECUPERATION_ATOMES] == main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES
			);
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_NETTOYAGE_R1_DEVENTOUSAGE_ATOMES] == main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES
			);
		case main_region_MATCH_EN_COURS__region0_SUPERVISOR : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_SUPERVISOR] == main_region_MATCH_EN_COURS__region0_SUPERVISOR
			);
		case main_region_FIN_MATCH : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_FIN_MATCH] == main_region_FIN_MATCH
			);
		default: return false;
	}
}

IA::DefaultSCI* IA::getDefaultSCI()
{
	return &iface;
}
/* Functions for event EV_Tirette in interface DefaultSCI */
void IA::DefaultSCI::raise_eV_Tirette()
{
	EV_Tirette_raised = true;
}
void IA::raise_eV_Tirette()
{
	iface.raise_eV_Tirette();
}
/* Functions for event EV_Obstacle in interface DefaultSCI */
void IA::DefaultSCI::raise_eV_Obstacle()
{
	EV_Obstacle_raised = true;
}
void IA::raise_eV_Obstacle()
{
	iface.raise_eV_Obstacle();
}
/* Functions for event EV_ConvergenceMvt in interface DefaultSCI */
void IA::DefaultSCI::raise_eV_ConvergenceMvt()
{
	EV_ConvergenceMvt_raised = true;
}
void IA::raise_eV_ConvergenceMvt()
{
	iface.raise_eV_ConvergenceMvt();
}
/* Functions for event EV_ConvergenceMvt_Rapide in interface DefaultSCI */
void IA::DefaultSCI::raise_eV_ConvergenceMvt_Rapide()
{
	EV_ConvergenceMvt_Rapide_raised = true;
}
void IA::raise_eV_ConvergenceMvt_Rapide()
{
	iface.raise_eV_ConvergenceMvt_Rapide();
}
/* Functions for event EV_ConvergenceChariot in interface DefaultSCI */
void IA::DefaultSCI::raise_eV_ConvergenceChariot()
{
	EV_ConvergenceChariot_raised = true;
}
void IA::raise_eV_ConvergenceChariot()
{
	iface.raise_eV_ConvergenceChariot();
}
double IA::DefaultSCI::get_iN_x_pos() const
{
	return IN_x_pos;
}

double IA::get_iN_x_pos() const
{
	return iface.IN_x_pos;
}

void IA::DefaultSCI::set_iN_x_pos(double value)
{
	IN_x_pos = value;
}

void IA::set_iN_x_pos(double value)
{
	iface.IN_x_pos = value;
}

double IA::DefaultSCI::get_iN_y_pos() const
{
	return IN_y_pos;
}

double IA::get_iN_y_pos() const
{
	return iface.IN_y_pos;
}

void IA::DefaultSCI::set_iN_y_pos(double value)
{
	IN_y_pos = value;
}

void IA::set_iN_y_pos(double value)
{
	iface.IN_y_pos = value;
}

double IA::DefaultSCI::get_iN_teta_pos() const
{
	return IN_teta_pos;
}

double IA::get_iN_teta_pos() const
{
	return iface.IN_teta_pos;
}

void IA::DefaultSCI::set_iN_teta_pos(double value)
{
	IN_teta_pos = value;
}

void IA::set_iN_teta_pos(double value)
{
	iface.IN_teta_pos = value;
}

double IA::DefaultSCI::get_iN_vitesse() const
{
	return IN_vitesse;
}

double IA::get_iN_vitesse() const
{
	return iface.IN_vitesse;
}

void IA::DefaultSCI::set_iN_vitesse(double value)
{
	IN_vitesse = value;
}

void IA::set_iN_vitesse(double value)
{
	iface.IN_vitesse = value;
}

double IA::DefaultSCI::get_iN_sens_deplacement() const
{
	return IN_sens_deplacement;
}

double IA::get_iN_sens_deplacement() const
{
	return iface.IN_sens_deplacement;
}

void IA::DefaultSCI::set_iN_sens_deplacement(double value)
{
	IN_sens_deplacement = value;
}

void IA::set_iN_sens_deplacement(double value)
{
	iface.IN_sens_deplacement = value;
}

int32_t IA::DefaultSCI::get_iN_Couleur() const
{
	return IN_Couleur;
}

int32_t IA::get_iN_Couleur() const
{
	return iface.IN_Couleur;
}

void IA::DefaultSCI::set_iN_Couleur(int32_t value)
{
	IN_Couleur = value;
}

void IA::set_iN_Couleur(int32_t value)
{
	iface.IN_Couleur = value;
}

int32_t IA::DefaultSCI::get_iN_Obstacle() const
{
	return IN_Obstacle;
}

int32_t IA::get_iN_Obstacle() const
{
	return iface.IN_Obstacle;
}

void IA::DefaultSCI::set_iN_Obstacle(int32_t value)
{
	IN_Obstacle = value;
}

void IA::set_iN_Obstacle(int32_t value)
{
	iface.IN_Obstacle = value;
}

sc_boolean IA::DefaultSCI::get_iN_Depression() const
{
	return IN_Depression;
}

sc_boolean IA::get_iN_Depression() const
{
	return iface.IN_Depression;
}

void IA::DefaultSCI::set_iN_Depression(sc_boolean value)
{
	IN_Depression = value;
}

void IA::set_iN_Depression(sc_boolean value)
{
	iface.IN_Depression = value;
}

int32_t IA::DefaultSCI::get_couleur() const
{
	return Couleur;
}

int32_t IA::get_couleur() const
{
	return iface.Couleur;
}

void IA::DefaultSCI::set_couleur(int32_t value)
{
	Couleur = value;
}

void IA::set_couleur(int32_t value)
{
	iface.Couleur = value;
}

double IA::DefaultSCI::get_countTimeMvt() const
{
	return countTimeMvt;
}

double IA::get_countTimeMvt() const
{
	return iface.countTimeMvt;
}

void IA::DefaultSCI::set_countTimeMvt(double value)
{
	countTimeMvt = value;
}

void IA::set_countTimeMvt(double value)
{
	iface.countTimeMvt = value;
}

double IA::DefaultSCI::get_tempsMatch() const
{
	return tempsMatch;
}

double IA::get_tempsMatch() const
{
	return iface.tempsMatch;
}

void IA::DefaultSCI::set_tempsMatch(double value)
{
	tempsMatch = value;
}

void IA::set_tempsMatch(double value)
{
	iface.tempsMatch = value;
}

int32_t IA::DefaultSCI::get_countTempo() const
{
	return countTempo;
}

int32_t IA::get_countTempo() const
{
	return iface.countTempo;
}

void IA::DefaultSCI::set_countTempo(int32_t value)
{
	countTempo = value;
}

void IA::set_countTempo(int32_t value)
{
	iface.countTempo = value;
}

int32_t IA::DefaultSCI::get_countTempo2() const
{
	return countTempo2;
}

int32_t IA::get_countTempo2() const
{
	return iface.countTempo2;
}

void IA::DefaultSCI::set_countTempo2(int32_t value)
{
	countTempo2 = value;
}

void IA::set_countTempo2(int32_t value)
{
	iface.countTempo2 = value;
}

double IA::DefaultSCI::get_countTime() const
{
	return countTime;
}

double IA::get_countTime() const
{
	return iface.countTime;
}

void IA::DefaultSCI::set_countTime(double value)
{
	countTime = value;
}

void IA::set_countTime(double value)
{
	iface.countTime = value;
}

double IA::DefaultSCI::get_x_pos_mem() const
{
	return x_pos_mem;
}

double IA::get_x_pos_mem() const
{
	return iface.x_pos_mem;
}

void IA::DefaultSCI::set_x_pos_mem(double value)
{
	x_pos_mem = value;
}

void IA::set_x_pos_mem(double value)
{
	iface.x_pos_mem = value;
}

double IA::DefaultSCI::get_y_pos_mem() const
{
	return y_pos_mem;
}

double IA::get_y_pos_mem() const
{
	return iface.y_pos_mem;
}

void IA::DefaultSCI::set_y_pos_mem(double value)
{
	y_pos_mem = value;
}

void IA::set_y_pos_mem(double value)
{
	iface.y_pos_mem = value;
}

double IA::DefaultSCI::get_teta_pos_mem() const
{
	return teta_pos_mem;
}

double IA::get_teta_pos_mem() const
{
	return iface.teta_pos_mem;
}

void IA::DefaultSCI::set_teta_pos_mem(double value)
{
	teta_pos_mem = value;
}

void IA::set_teta_pos_mem(double value)
{
	iface.teta_pos_mem = value;
}

int32_t IA::DefaultSCI::get_nb_Modules() const
{
	return nb_Modules;
}

int32_t IA::get_nb_Modules() const
{
	return iface.nb_Modules;
}

void IA::DefaultSCI::set_nb_Modules(int32_t value)
{
	nb_Modules = value;
}

void IA::set_nb_Modules(int32_t value)
{
	iface.nb_Modules = value;
}

const int32_t IA::DefaultSCI::get_sERVO_VENTOUSE() const
{
	return SERVO_VENTOUSE;
}

const int32_t IA::get_sERVO_VENTOUSE() const
{
	return IA::DefaultSCI::SERVO_VENTOUSE;
}

const int32_t IA::DefaultSCI::get_sERVO_CENTREUR_G() const
{
	return SERVO_CENTREUR_G;
}

const int32_t IA::get_sERVO_CENTREUR_G() const
{
	return IA::DefaultSCI::SERVO_CENTREUR_G;
}

const int32_t IA::DefaultSCI::get_sERVO_CENTREUR_D() const
{
	return SERVO_CENTREUR_D;
}

const int32_t IA::get_sERVO_CENTREUR_D() const
{
	return IA::DefaultSCI::SERVO_CENTREUR_D;
}

const int32_t IA::DefaultSCI::get_sERVO_PINCE_D() const
{
	return SERVO_PINCE_D;
}

const int32_t IA::get_sERVO_PINCE_D() const
{
	return IA::DefaultSCI::SERVO_PINCE_D;
}

const int32_t IA::DefaultSCI::get_sERVO_PINCE_G() const
{
	return SERVO_PINCE_G;
}

const int32_t IA::get_sERVO_PINCE_G() const
{
	return IA::DefaultSCI::SERVO_PINCE_G;
}

const int32_t IA::DefaultSCI::get_sERVO_BALLE() const
{
	return SERVO_BALLE;
}

const int32_t IA::get_sERVO_BALLE() const
{
	return IA::DefaultSCI::SERVO_BALLE;
}

const int32_t IA::DefaultSCI::get_sERVO_RECOLTEURS() const
{
	return SERVO_RECOLTEURS;
}

const int32_t IA::get_sERVO_RECOLTEURS() const
{
	return IA::DefaultSCI::SERVO_RECOLTEURS;
}

const int32_t IA::DefaultSCI::get_sERVO_VOLET() const
{
	return SERVO_VOLET;
}

const int32_t IA::get_sERVO_VOLET() const
{
	return IA::DefaultSCI::SERVO_VOLET;
}

const int32_t IA::DefaultSCI::get_aX_ROTATION() const
{
	return AX_ROTATION;
}

const int32_t IA::get_aX_ROTATION() const
{
	return IA::DefaultSCI::AX_ROTATION;
}

const int32_t IA::DefaultSCI::get_aX_COULEUR() const
{
	return AX_COULEUR;
}

const int32_t IA::get_aX_COULEUR() const
{
	return IA::DefaultSCI::AX_COULEUR;
}

const int32_t IA::DefaultSCI::get_aX_LEVIER() const
{
	return AX_LEVIER;
}

const int32_t IA::get_aX_LEVIER() const
{
	return IA::DefaultSCI::AX_LEVIER;
}

const int32_t IA::DefaultSCI::get_kMAR_SORTI() const
{
	return KMAR_SORTI;
}

const int32_t IA::get_kMAR_SORTI() const
{
	return IA::DefaultSCI::KMAR_SORTI;
}

const int32_t IA::DefaultSCI::get_kMAR_RENTRE() const
{
	return KMAR_RENTRE;
}

const int32_t IA::get_kMAR_RENTRE() const
{
	return IA::DefaultSCI::KMAR_RENTRE;
}

const int32_t IA::DefaultSCI::get_kMAR_PRENDRE() const
{
	return KMAR_PRENDRE;
}

const int32_t IA::get_kMAR_PRENDRE() const
{
	return IA::DefaultSCI::KMAR_PRENDRE;
}

const int32_t IA::DefaultSCI::get_vENTOUSE_G() const
{
	return VENTOUSE_G;
}

const int32_t IA::get_vENTOUSE_G() const
{
	return IA::DefaultSCI::VENTOUSE_G;
}

const int32_t IA::DefaultSCI::get_vENTOUSE_D() const
{
	return VENTOUSE_D;
}

const int32_t IA::get_vENTOUSE_D() const
{
	return IA::DefaultSCI::VENTOUSE_D;
}

const int32_t IA::DefaultSCI::get_kMAR_DROIT() const
{
	return KMAR_DROIT;
}

const int32_t IA::get_kMAR_DROIT() const
{
	return IA::DefaultSCI::KMAR_DROIT;
}

const int32_t IA::DefaultSCI::get_mOTEUR_ROUE_GAUCHE() const
{
	return MOTEUR_ROUE_GAUCHE;
}

const int32_t IA::get_mOTEUR_ROUE_GAUCHE() const
{
	return IA::DefaultSCI::MOTEUR_ROUE_GAUCHE;
}

const int32_t IA::DefaultSCI::get_mOTEUR_ROUE_DROITE() const
{
	return MOTEUR_ROUE_DROITE;
}

const int32_t IA::get_mOTEUR_ROUE_DROITE() const
{
	return IA::DefaultSCI::MOTEUR_ROUE_DROITE;
}

const int32_t IA::DefaultSCI::get_mOTEUR_FUNNY() const
{
	return MOTEUR_FUNNY;
}

const int32_t IA::get_mOTEUR_FUNNY() const
{
	return IA::DefaultSCI::MOTEUR_FUNNY;
}

const int32_t IA::DefaultSCI::get_mOTEUR_MOELDAR() const
{
	return MOTEUR_MOELDAR;
}

const int32_t IA::get_mOTEUR_MOELDAR() const
{
	return IA::DefaultSCI::MOTEUR_MOELDAR;
}

const int32_t IA::DefaultSCI::get_cODEUR_NON_DEFINI() const
{
	return CODEUR_NON_DEFINI;
}

const int32_t IA::get_cODEUR_NON_DEFINI() const
{
	return IA::DefaultSCI::CODEUR_NON_DEFINI;
}

const int32_t IA::DefaultSCI::get_cODEUR_CHARIOT() const
{
	return CODEUR_CHARIOT;
}

const int32_t IA::get_cODEUR_CHARIOT() const
{
	return IA::DefaultSCI::CODEUR_CHARIOT;
}

const int32_t IA::DefaultSCI::get_cODEUR_ROUE_DROITE() const
{
	return CODEUR_ROUE_DROITE;
}

const int32_t IA::get_cODEUR_ROUE_DROITE() const
{
	return IA::DefaultSCI::CODEUR_ROUE_DROITE;
}

const int32_t IA::DefaultSCI::get_cODEUR_ROUE_GAUCHE() const
{
	return CODEUR_ROUE_GAUCHE;
}

const int32_t IA::get_cODEUR_ROUE_GAUCHE() const
{
	return IA::DefaultSCI::CODEUR_ROUE_GAUCHE;
}

const int32_t IA::DefaultSCI::get_vIOLET() const
{
	return VIOLET;
}

const int32_t IA::get_vIOLET() const
{
	return IA::DefaultSCI::VIOLET;
}

const int32_t IA::DefaultSCI::get_jAUNE() const
{
	return JAUNE;
}

const int32_t IA::get_jAUNE() const
{
	return IA::DefaultSCI::JAUNE;
}

const float IA::DefaultSCI::get_pI() const
{
	return PI;
}

const float IA::get_pI() const
{
	return IA::DefaultSCI::PI;
}

int32_t IA::InternalSCI::get_invMouv() const
{
	return invMouv;
}

void IA::InternalSCI::set_invMouv(int32_t value)
{
	invMouv = value;
}

double IA::InternalSCI::get_te() const
{
	return Te;
}

void IA::InternalSCI::set_te(double value)
{
	Te = value;
}

sc_boolean IA::InternalSCI::get_inhibeObstacle() const
{
	return inhibeObstacle;
}

void IA::InternalSCI::set_inhibeObstacle(sc_boolean value)
{
	inhibeObstacle = value;
}

sc_boolean IA::InternalSCI::get_evitementEnCours() const
{
	return evitementEnCours;
}

void IA::InternalSCI::set_evitementEnCours(sc_boolean value)
{
	evitementEnCours = value;
}

double IA::InternalSCI::get_evitementTempo() const
{
	return evitementTempo;
}

void IA::InternalSCI::set_evitementTempo(double value)
{
	evitementTempo = value;
}

sc_boolean IA::InternalSCI::get_sequence1() const
{
	return sequence1;
}

void IA::InternalSCI::set_sequence1(sc_boolean value)
{
	sequence1 = value;
}

sc_boolean IA::InternalSCI::get_sequence2() const
{
	return sequence2;
}

void IA::InternalSCI::set_sequence2(sc_boolean value)
{
	sequence2 = value;
}

int32_t IA::InternalSCI::get_pos_fusee() const
{
	return pos_fusee;
}

void IA::InternalSCI::set_pos_fusee(int32_t value)
{
	pos_fusee = value;
}

int32_t IA::InternalSCI::get_nb_tentatives() const
{
	return nb_tentatives;
}

void IA::InternalSCI::set_nb_tentatives(int32_t value)
{
	nb_tentatives = value;
}

int32_t IA::InternalSCI::get_etape() const
{
	return etape;
}

void IA::InternalSCI::set_etape(int32_t value)
{
	etape = value;
}

IA::SCI_Asser* IA::getSCI_Asser()
{
	return &ifaceAsser;
}
IA::SCI_Servo* IA::getSCI_Servo()
{
	return &ifaceServo;
}
IA::SCI_Ax* IA::getSCI_Ax()
{
	return &ifaceAx;
}
int32_t IA::SCI_Ax::get_bRAS_OUVERT() const
{
	return BRAS_OUVERT;
}

void IA::SCI_Ax::set_bRAS_OUVERT(int32_t value)
{
	BRAS_OUVERT = value;
}

IA::SCI_Moteur* IA::getSCI_Moteur()
{
	return &ifaceMoteur;
}
IA::SCI_Chariot* IA::getSCI_Chariot()
{
	return &ifaceChariot;
}
sc_boolean IA::SCI_Chariot::get_isReady() const
{
	return isReady;
}

void IA::SCI_Chariot::set_isReady(sc_boolean value)
{
	isReady = value;
}

sc_boolean IA::SCI_Chariot::get_isConv() const
{
	return isConv;
}

void IA::SCI_Chariot::set_isConv(sc_boolean value)
{
	isConv = value;
}

IA::SCI_Capteur* IA::getSCI_Capteur()
{
	return &ifaceCapteur;
}
IA::SCI_Ihm* IA::getSCI_Ihm()
{
	return &ifaceIhm;
}

// implementations of all internal functions

/* shallow enterSequence with history in child r1 */
void IA::shenseq_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1()
{
	/* shallow enterSequence with history in child r1 */
	/* Handle shallow history entry of r1 */
	switch(historyVector[ 0 ])
	{
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS :
		{
			/* 'default' enter sequence for state DEPASSE_ZONE_CHAOS */
			/* Entry action for state 'DEPASSE_ZONE_CHAOS'. */
			timer->setTimer(this, (sc_eventid)(&timeEvents[9]), 3 * 1000, false);
			SCI_Asser_OCB::XYTeta(114, 0, 0);
			stateConfVector[0] = main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS;
			stateConfVectorPosition = 0;
			historyVector[0] = stateConfVector[0];
			break;
		}
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS :
		{
			/* 'default' enter sequence for state FACE_ZONE_CHAOS */
			/* Entry action for state 'FACE_ZONE_CHAOS'. */
			timer->setTimer(this, (sc_eventid)(&timeEvents[10]), 3 * 1000, false);
			SCI_Asser_OCB::XYTeta(114, -57, 0);
			stateConfVector[0] = main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS;
			stateConfVectorPosition = 0;
			historyVector[0] = stateConfVector[0];
			break;
		}
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART :
		{
			/* 'default' enter sequence for state STOCKAGE_DANS_ZONE_DEPART */
			/* Entry action for state 'STOCKAGE_DANS_ZONE_DEPART'. */
			timer->setTimer(this, (sc_eventid)(&timeEvents[11]), 3 * 1000, false);
			SCI_Asser_OCB::XYTeta(30, -57, 0);
			stateConfVector[0] = main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART;
			stateConfVectorPosition = 0;
			historyVector[0] = stateConfVector[0];
			break;
		}
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR :
		{
			/* 'default' enter sequence for state PLACEMENT_DEVANT_DISTRIBUTEUR */
			/* Entry action for state 'PLACEMENT_DEVANT_DISTRIBUTEUR'. */
			timer->setTimer(this, (sc_eventid)(&timeEvents[12]), 4 * 1000, false);
			SCI_Asser_OCB::XYTeta(82, -80, IA::DefaultSCI::PI / 2);
			stateConfVector[0] = main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR;
			stateConfVectorPosition = 0;
			historyVector[0] = stateConfVector[0];
			break;
		}
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES :
		{
			/* 'default' enter sequence for state VENTOUSAGE_ATOMES */
			/* Entry action for state 'VENTOUSAGE_ATOMES'. */
			timer->setTimer(this, (sc_eventid)(&timeEvents[13]), 2 * 1000, false);
			Application.m_power_switch.setOutput(POMPE_ARD, true);
			Application.m_power_switch.setOutput(POMPE_ARG, true);
			Application.m_servos_sd20.CommandePosition(SERVO_BRAS_ARG, 140);
			Application.m_servos_ax.setPosition(SERVO_VENTOUSE_ARG_VERT, 572);
			Application.m_servos_sd20.CommandePosition(SERVO_BRAS_ARD, 160);
			Application.m_servos_ax.setPosition(SERVO_VENTOUSE_ARD_VERT, 450);
			stateConfVector[0] = main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES;
			stateConfVectorPosition = 0;
			historyVector[0] = stateConfVector[0];
			break;
		}
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES :
		{
			/* 'default' enter sequence for state RECUPERATION_ATOMES */
			/* Entry action for state 'RECUPERATION_ATOMES'. */
			timer->setTimer(this, (sc_eventid)(&timeEvents[14]), 1 * 1000, false);
			Application.m_servos_sd20.CommandePosition(SERVO_BRAS_ARG, 50);
			Application.m_servos_ax.setPosition(SERVO_VENTOUSE_ARG_VERT, 170);
			Application.m_servos_sd20.CommandePosition(SERVO_BRAS_ARD, 255);
			Application.m_servos_ax.setPosition(SERVO_VENTOUSE_ARD_VERT, 850);
			stateConfVector[0] = main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES;
			stateConfVectorPosition = 0;
			historyVector[0] = stateConfVector[0];
			break;
		}
		case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES :
		{
			/* 'default' enter sequence for state DEVENTOUSAGE_ATOMES */
			/* Entry action for state 'DEVENTOUSAGE_ATOMES'. */
			Application.m_power_switch.setOutput(POMPE_ARD, false);
			Application.m_power_switch.setOutput(EV_ARD, false);
			Application.m_power_switch.setOutput(POMPE_ARG, false);
			Application.m_power_switch.setOutput(EV_ARG, false);
			stateConfVector[0] = main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES;
			stateConfVectorPosition = 0;
			historyVector[0] = stateConfVector[0];
			break;
		}
		default: break;
	}
}

/* The reactions of state INIT. */
void IA::react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_INIT()
{
	/* The reactions of state INIT. */
	if (iface.EV_Tirette_raised)
	{ 
		/* Default exit sequence for state ATTENTE_TIRETTE */
		/* Default exit sequence for region null */
		/* Handle exit of all possible states (of IA.main_region.ATTENTE_TIRETTE._region0) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_INIT :
			{
				/* Default exit sequence for state INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[0]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_HAUTS :
			{
				/* Default exit sequence for state TOBOGGANS_HAUTS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'TOBOGGANS_HAUTS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[1]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_APPRENTISSAGE_ASCENSEUR :
			{
				/* Default exit sequence for state APPRENTISSAGE_ASCENSEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'APPRENTISSAGE_ASCENSEUR'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[2]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_BAS :
			{
				/* Default exit sequence for state TOBOGGANS_BAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'TOBOGGANS_BAS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[3]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_01 :
			{
				/* Default exit sequence for state KMAR_RANGE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_RANGE_01'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[4]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_02 :
			{
				/* Default exit sequence for state KMAR_RANGE_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_01 :
			{
				/* Default exit sequence for state KMAR_SORTI_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_SORTI_01'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[5]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_02 :
			{
				/* Default exit sequence for state KMAR_SORTI_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_SORTI_02'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[6]));
				break;
			}
			default: break;
		}
		/* Handle exit of all possible states (of IA.main_region.ATTENTE_TIRETTE._region0) at position 1... */
		switch(stateConfVector[ 1 ])
		{
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_VIOLET :
			{
				/* Default exit sequence for state CHOIX_COULEUR_VIOLET */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_JAUNE :
			{
				/* Default exit sequence for state CHOIX_COULEUR_JAUNE */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state MATCH_EN_COURS */
		/* Entry action for state 'MATCH_EN_COURS'. */
		timer->setTimer(this, (sc_eventid)(&timeEvents[7]), (DUREE_MATCH) * 1000, false);
		Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
		Application.m_asservissement.setPosition_XYTeta(0, 0, 0);
		Application.m_asservissement.Ind_perfo = 0.3;
		/* 'default' enter sequence for region null */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state SUPERVISOR */
		/* Entry action for state 'SUPERVISOR'. */
		ifaceInternalSCI.etape = 0;
		stateConfVector[0] = main_region_MATCH_EN_COURS__region0_SUPERVISOR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.tempsMatch = 0;
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = -1;
		if (timeEvents[0])
		{ 
			/* Default exit sequence for state INIT */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'INIT'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[0]));
			/* 'default' enter sequence for state TOBOGGANS_HAUTS */
			/* Entry action for state 'TOBOGGANS_HAUTS'. */
			timer->setTimer(this, (sc_eventid)(&timeEvents[1]), 200, false);
			Application.m_servos_sd20.CommandePosition(SERVO_PLATEAU_G, 140);
			Application.m_servos_ax.setPosition(SERVO_VENTOUSE_ARG_VERT, 512);
			Application.m_servos_sd20.CommandePosition(SERVO_PLATEAU_D, 110);
			Application.m_servos_ax.setPosition(SERVO_VENTOUSE_ARD_VERT, 512);
			stateConfVector[0] = main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_HAUTS;
			stateConfVectorPosition = 0;
		} 
	}
}

/* The reactions of state TOBOGGANS_HAUTS. */
void IA::react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_HAUTS()
{
	/* The reactions of state TOBOGGANS_HAUTS. */
	if (iface.EV_Tirette_raised)
	{ 
		/* Default exit sequence for state ATTENTE_TIRETTE */
		/* Default exit sequence for region null */
		/* Handle exit of all possible states (of IA.main_region.ATTENTE_TIRETTE._region0) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_INIT :
			{
				/* Default exit sequence for state INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[0]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_HAUTS :
			{
				/* Default exit sequence for state TOBOGGANS_HAUTS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'TOBOGGANS_HAUTS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[1]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_APPRENTISSAGE_ASCENSEUR :
			{
				/* Default exit sequence for state APPRENTISSAGE_ASCENSEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'APPRENTISSAGE_ASCENSEUR'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[2]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_BAS :
			{
				/* Default exit sequence for state TOBOGGANS_BAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'TOBOGGANS_BAS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[3]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_01 :
			{
				/* Default exit sequence for state KMAR_RANGE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_RANGE_01'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[4]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_02 :
			{
				/* Default exit sequence for state KMAR_RANGE_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_01 :
			{
				/* Default exit sequence for state KMAR_SORTI_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_SORTI_01'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[5]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_02 :
			{
				/* Default exit sequence for state KMAR_SORTI_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_SORTI_02'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[6]));
				break;
			}
			default: break;
		}
		/* Handle exit of all possible states (of IA.main_region.ATTENTE_TIRETTE._region0) at position 1... */
		switch(stateConfVector[ 1 ])
		{
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_VIOLET :
			{
				/* Default exit sequence for state CHOIX_COULEUR_VIOLET */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_JAUNE :
			{
				/* Default exit sequence for state CHOIX_COULEUR_JAUNE */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state MATCH_EN_COURS */
		/* Entry action for state 'MATCH_EN_COURS'. */
		timer->setTimer(this, (sc_eventid)(&timeEvents[7]), (DUREE_MATCH) * 1000, false);
		Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
		Application.m_asservissement.setPosition_XYTeta(0, 0, 0);
		Application.m_asservissement.Ind_perfo = 0.3;
		/* 'default' enter sequence for region null */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state SUPERVISOR */
		/* Entry action for state 'SUPERVISOR'. */
		ifaceInternalSCI.etape = 0;
		stateConfVector[0] = main_region_MATCH_EN_COURS__region0_SUPERVISOR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.tempsMatch = 0;
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = -1;
		if (timeEvents[1])
		{ 
			/* Default exit sequence for state TOBOGGANS_HAUTS */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'TOBOGGANS_HAUTS'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[1]));
			/* 'default' enter sequence for state KMAR_SORTI_01 */
			/* Entry action for state 'KMAR_SORTI_01'. */
			timer->setTimer(this, (sc_eventid)(&timeEvents[5]), 200, false);
			Application.m_servos_ax.setPosition(SERVO_VENTOUSE_AV_HORIZ, 512);
			stateConfVector[0] = main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_01;
			stateConfVectorPosition = 0;
		} 
	}
}

/* The reactions of state APPRENTISSAGE_ASCENSEUR. */
void IA::react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_APPRENTISSAGE_ASCENSEUR()
{
	/* The reactions of state APPRENTISSAGE_ASCENSEUR. */
	if (iface.EV_Tirette_raised)
	{ 
		/* Default exit sequence for state ATTENTE_TIRETTE */
		/* Default exit sequence for region null */
		/* Handle exit of all possible states (of IA.main_region.ATTENTE_TIRETTE._region0) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_INIT :
			{
				/* Default exit sequence for state INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[0]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_HAUTS :
			{
				/* Default exit sequence for state TOBOGGANS_HAUTS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'TOBOGGANS_HAUTS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[1]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_APPRENTISSAGE_ASCENSEUR :
			{
				/* Default exit sequence for state APPRENTISSAGE_ASCENSEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'APPRENTISSAGE_ASCENSEUR'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[2]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_BAS :
			{
				/* Default exit sequence for state TOBOGGANS_BAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'TOBOGGANS_BAS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[3]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_01 :
			{
				/* Default exit sequence for state KMAR_RANGE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_RANGE_01'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[4]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_02 :
			{
				/* Default exit sequence for state KMAR_RANGE_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_01 :
			{
				/* Default exit sequence for state KMAR_SORTI_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_SORTI_01'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[5]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_02 :
			{
				/* Default exit sequence for state KMAR_SORTI_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_SORTI_02'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[6]));
				break;
			}
			default: break;
		}
		/* Handle exit of all possible states (of IA.main_region.ATTENTE_TIRETTE._region0) at position 1... */
		switch(stateConfVector[ 1 ])
		{
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_VIOLET :
			{
				/* Default exit sequence for state CHOIX_COULEUR_VIOLET */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_JAUNE :
			{
				/* Default exit sequence for state CHOIX_COULEUR_JAUNE */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state MATCH_EN_COURS */
		/* Entry action for state 'MATCH_EN_COURS'. */
		timer->setTimer(this, (sc_eventid)(&timeEvents[7]), (DUREE_MATCH) * 1000, false);
		Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
		Application.m_asservissement.setPosition_XYTeta(0, 0, 0);
		Application.m_asservissement.Ind_perfo = 0.3;
		/* 'default' enter sequence for region null */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state SUPERVISOR */
		/* Entry action for state 'SUPERVISOR'. */
		ifaceInternalSCI.etape = 0;
		stateConfVector[0] = main_region_MATCH_EN_COURS__region0_SUPERVISOR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.tempsMatch = 0;
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = -1;
		if (timeEvents[2])
		{ 
			/* Default exit sequence for state APPRENTISSAGE_ASCENSEUR */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'APPRENTISSAGE_ASCENSEUR'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[2]));
			/* 'default' enter sequence for state TOBOGGANS_BAS */
			/* Entry action for state 'TOBOGGANS_BAS'. */
			timer->setTimer(this, (sc_eventid)(&timeEvents[3]), 200, false);
			Application.m_servos_sd20.CommandePosition(SERVO_PLATEAU_G, 65);
			Application.m_servos_ax.setPosition(SERVO_VENTOUSE_ARG_VERT, 170);
			Application.m_servos_sd20.CommandePosition(SERVO_PLATEAU_D, 210);
			Application.m_servos_ax.setPosition(SERVO_VENTOUSE_ARD_VERT, 850);
			stateConfVector[0] = main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_BAS;
			stateConfVectorPosition = 0;
		} 
	}
}

/* The reactions of state TOBOGGANS_BAS. */
void IA::react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_BAS()
{
	/* The reactions of state TOBOGGANS_BAS. */
	if (iface.EV_Tirette_raised)
	{ 
		/* Default exit sequence for state ATTENTE_TIRETTE */
		/* Default exit sequence for region null */
		/* Handle exit of all possible states (of IA.main_region.ATTENTE_TIRETTE._region0) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_INIT :
			{
				/* Default exit sequence for state INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[0]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_HAUTS :
			{
				/* Default exit sequence for state TOBOGGANS_HAUTS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'TOBOGGANS_HAUTS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[1]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_APPRENTISSAGE_ASCENSEUR :
			{
				/* Default exit sequence for state APPRENTISSAGE_ASCENSEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'APPRENTISSAGE_ASCENSEUR'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[2]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_BAS :
			{
				/* Default exit sequence for state TOBOGGANS_BAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'TOBOGGANS_BAS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[3]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_01 :
			{
				/* Default exit sequence for state KMAR_RANGE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_RANGE_01'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[4]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_02 :
			{
				/* Default exit sequence for state KMAR_RANGE_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_01 :
			{
				/* Default exit sequence for state KMAR_SORTI_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_SORTI_01'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[5]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_02 :
			{
				/* Default exit sequence for state KMAR_SORTI_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_SORTI_02'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[6]));
				break;
			}
			default: break;
		}
		/* Handle exit of all possible states (of IA.main_region.ATTENTE_TIRETTE._region0) at position 1... */
		switch(stateConfVector[ 1 ])
		{
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_VIOLET :
			{
				/* Default exit sequence for state CHOIX_COULEUR_VIOLET */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_JAUNE :
			{
				/* Default exit sequence for state CHOIX_COULEUR_JAUNE */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state MATCH_EN_COURS */
		/* Entry action for state 'MATCH_EN_COURS'. */
		timer->setTimer(this, (sc_eventid)(&timeEvents[7]), (DUREE_MATCH) * 1000, false);
		Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
		Application.m_asservissement.setPosition_XYTeta(0, 0, 0);
		Application.m_asservissement.Ind_perfo = 0.3;
		/* 'default' enter sequence for region null */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state SUPERVISOR */
		/* Entry action for state 'SUPERVISOR'. */
		ifaceInternalSCI.etape = 0;
		stateConfVector[0] = main_region_MATCH_EN_COURS__region0_SUPERVISOR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.tempsMatch = 0;
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = -1;
		if (timeEvents[3])
		{ 
			/* Default exit sequence for state TOBOGGANS_BAS */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'TOBOGGANS_BAS'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[3]));
			/* 'default' enter sequence for state KMAR_RANGE_01 */
			/* Entry action for state 'KMAR_RANGE_01'. */
			timer->setTimer(this, (sc_eventid)(&timeEvents[4]), 200, false);
			Application.m_servos_ax.setPosition(SERVO_VENTOUSE_AV_VERT, 200);
			stateConfVector[0] = main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_01;
			stateConfVectorPosition = 0;
		} 
	}
}

/* The reactions of state KMAR_RANGE_01. */
void IA::react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_01()
{
	/* The reactions of state KMAR_RANGE_01. */
	if (iface.EV_Tirette_raised)
	{ 
		/* Default exit sequence for state ATTENTE_TIRETTE */
		/* Default exit sequence for region null */
		/* Handle exit of all possible states (of IA.main_region.ATTENTE_TIRETTE._region0) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_INIT :
			{
				/* Default exit sequence for state INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[0]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_HAUTS :
			{
				/* Default exit sequence for state TOBOGGANS_HAUTS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'TOBOGGANS_HAUTS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[1]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_APPRENTISSAGE_ASCENSEUR :
			{
				/* Default exit sequence for state APPRENTISSAGE_ASCENSEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'APPRENTISSAGE_ASCENSEUR'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[2]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_BAS :
			{
				/* Default exit sequence for state TOBOGGANS_BAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'TOBOGGANS_BAS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[3]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_01 :
			{
				/* Default exit sequence for state KMAR_RANGE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_RANGE_01'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[4]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_02 :
			{
				/* Default exit sequence for state KMAR_RANGE_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_01 :
			{
				/* Default exit sequence for state KMAR_SORTI_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_SORTI_01'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[5]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_02 :
			{
				/* Default exit sequence for state KMAR_SORTI_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_SORTI_02'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[6]));
				break;
			}
			default: break;
		}
		/* Handle exit of all possible states (of IA.main_region.ATTENTE_TIRETTE._region0) at position 1... */
		switch(stateConfVector[ 1 ])
		{
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_VIOLET :
			{
				/* Default exit sequence for state CHOIX_COULEUR_VIOLET */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_JAUNE :
			{
				/* Default exit sequence for state CHOIX_COULEUR_JAUNE */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state MATCH_EN_COURS */
		/* Entry action for state 'MATCH_EN_COURS'. */
		timer->setTimer(this, (sc_eventid)(&timeEvents[7]), (DUREE_MATCH) * 1000, false);
		Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
		Application.m_asservissement.setPosition_XYTeta(0, 0, 0);
		Application.m_asservissement.Ind_perfo = 0.3;
		/* 'default' enter sequence for region null */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state SUPERVISOR */
		/* Entry action for state 'SUPERVISOR'. */
		ifaceInternalSCI.etape = 0;
		stateConfVector[0] = main_region_MATCH_EN_COURS__region0_SUPERVISOR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.tempsMatch = 0;
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = -1;
		if (timeEvents[4])
		{ 
			/* Default exit sequence for state KMAR_RANGE_01 */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'KMAR_RANGE_01'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[4]));
			/* 'default' enter sequence for state KMAR_RANGE_02 */
			/* Entry action for state 'KMAR_RANGE_02'. */
			Application.m_servos_ax.setPosition(SERVO_VENTOUSE_AV_HORIZ, 200);
			stateConfVector[0] = main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_02;
			stateConfVectorPosition = 0;
		} 
	}
}

/* The reactions of state KMAR_RANGE_02. */
void IA::react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_02()
{
	/* The reactions of state KMAR_RANGE_02. */
	if (iface.EV_Tirette_raised)
	{ 
		/* Default exit sequence for state ATTENTE_TIRETTE */
		/* Default exit sequence for region null */
		/* Handle exit of all possible states (of IA.main_region.ATTENTE_TIRETTE._region0) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_INIT :
			{
				/* Default exit sequence for state INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[0]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_HAUTS :
			{
				/* Default exit sequence for state TOBOGGANS_HAUTS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'TOBOGGANS_HAUTS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[1]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_APPRENTISSAGE_ASCENSEUR :
			{
				/* Default exit sequence for state APPRENTISSAGE_ASCENSEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'APPRENTISSAGE_ASCENSEUR'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[2]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_BAS :
			{
				/* Default exit sequence for state TOBOGGANS_BAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'TOBOGGANS_BAS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[3]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_01 :
			{
				/* Default exit sequence for state KMAR_RANGE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_RANGE_01'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[4]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_02 :
			{
				/* Default exit sequence for state KMAR_RANGE_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_01 :
			{
				/* Default exit sequence for state KMAR_SORTI_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_SORTI_01'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[5]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_02 :
			{
				/* Default exit sequence for state KMAR_SORTI_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_SORTI_02'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[6]));
				break;
			}
			default: break;
		}
		/* Handle exit of all possible states (of IA.main_region.ATTENTE_TIRETTE._region0) at position 1... */
		switch(stateConfVector[ 1 ])
		{
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_VIOLET :
			{
				/* Default exit sequence for state CHOIX_COULEUR_VIOLET */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_JAUNE :
			{
				/* Default exit sequence for state CHOIX_COULEUR_JAUNE */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state MATCH_EN_COURS */
		/* Entry action for state 'MATCH_EN_COURS'. */
		timer->setTimer(this, (sc_eventid)(&timeEvents[7]), (DUREE_MATCH) * 1000, false);
		Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
		Application.m_asservissement.setPosition_XYTeta(0, 0, 0);
		Application.m_asservissement.Ind_perfo = 0.3;
		/* 'default' enter sequence for region null */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state SUPERVISOR */
		/* Entry action for state 'SUPERVISOR'. */
		ifaceInternalSCI.etape = 0;
		stateConfVector[0] = main_region_MATCH_EN_COURS__region0_SUPERVISOR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.tempsMatch = 0;
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = -1;
	}
}

/* The reactions of state KMAR_SORTI_01. */
void IA::react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_01()
{
	/* The reactions of state KMAR_SORTI_01. */
	if (iface.EV_Tirette_raised)
	{ 
		/* Default exit sequence for state ATTENTE_TIRETTE */
		/* Default exit sequence for region null */
		/* Handle exit of all possible states (of IA.main_region.ATTENTE_TIRETTE._region0) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_INIT :
			{
				/* Default exit sequence for state INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[0]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_HAUTS :
			{
				/* Default exit sequence for state TOBOGGANS_HAUTS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'TOBOGGANS_HAUTS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[1]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_APPRENTISSAGE_ASCENSEUR :
			{
				/* Default exit sequence for state APPRENTISSAGE_ASCENSEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'APPRENTISSAGE_ASCENSEUR'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[2]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_BAS :
			{
				/* Default exit sequence for state TOBOGGANS_BAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'TOBOGGANS_BAS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[3]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_01 :
			{
				/* Default exit sequence for state KMAR_RANGE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_RANGE_01'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[4]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_02 :
			{
				/* Default exit sequence for state KMAR_RANGE_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_01 :
			{
				/* Default exit sequence for state KMAR_SORTI_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_SORTI_01'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[5]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_02 :
			{
				/* Default exit sequence for state KMAR_SORTI_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_SORTI_02'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[6]));
				break;
			}
			default: break;
		}
		/* Handle exit of all possible states (of IA.main_region.ATTENTE_TIRETTE._region0) at position 1... */
		switch(stateConfVector[ 1 ])
		{
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_VIOLET :
			{
				/* Default exit sequence for state CHOIX_COULEUR_VIOLET */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_JAUNE :
			{
				/* Default exit sequence for state CHOIX_COULEUR_JAUNE */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state MATCH_EN_COURS */
		/* Entry action for state 'MATCH_EN_COURS'. */
		timer->setTimer(this, (sc_eventid)(&timeEvents[7]), (DUREE_MATCH) * 1000, false);
		Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
		Application.m_asservissement.setPosition_XYTeta(0, 0, 0);
		Application.m_asservissement.Ind_perfo = 0.3;
		/* 'default' enter sequence for region null */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state SUPERVISOR */
		/* Entry action for state 'SUPERVISOR'. */
		ifaceInternalSCI.etape = 0;
		stateConfVector[0] = main_region_MATCH_EN_COURS__region0_SUPERVISOR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.tempsMatch = 0;
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = -1;
		if (timeEvents[5])
		{ 
			/* Default exit sequence for state KMAR_SORTI_01 */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'KMAR_SORTI_01'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[5]));
			/* 'default' enter sequence for state KMAR_SORTI_02 */
			/* Entry action for state 'KMAR_SORTI_02'. */
			timer->setTimer(this, (sc_eventid)(&timeEvents[6]), 200, false);
			Application.m_servos_ax.setPosition(SERVO_VENTOUSE_AV_VERT, 512);
			stateConfVector[0] = main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_02;
			stateConfVectorPosition = 0;
		} 
	}
}

/* The reactions of state KMAR_SORTI_02. */
void IA::react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_02()
{
	/* The reactions of state KMAR_SORTI_02. */
	if (iface.EV_Tirette_raised)
	{ 
		/* Default exit sequence for state ATTENTE_TIRETTE */
		/* Default exit sequence for region null */
		/* Handle exit of all possible states (of IA.main_region.ATTENTE_TIRETTE._region0) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_INIT :
			{
				/* Default exit sequence for state INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[0]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_HAUTS :
			{
				/* Default exit sequence for state TOBOGGANS_HAUTS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'TOBOGGANS_HAUTS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[1]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_APPRENTISSAGE_ASCENSEUR :
			{
				/* Default exit sequence for state APPRENTISSAGE_ASCENSEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'APPRENTISSAGE_ASCENSEUR'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[2]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_BAS :
			{
				/* Default exit sequence for state TOBOGGANS_BAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'TOBOGGANS_BAS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[3]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_01 :
			{
				/* Default exit sequence for state KMAR_RANGE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_RANGE_01'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[4]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_02 :
			{
				/* Default exit sequence for state KMAR_RANGE_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_01 :
			{
				/* Default exit sequence for state KMAR_SORTI_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_SORTI_01'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[5]));
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_02 :
			{
				/* Default exit sequence for state KMAR_SORTI_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'KMAR_SORTI_02'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[6]));
				break;
			}
			default: break;
		}
		/* Handle exit of all possible states (of IA.main_region.ATTENTE_TIRETTE._region0) at position 1... */
		switch(stateConfVector[ 1 ])
		{
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_VIOLET :
			{
				/* Default exit sequence for state CHOIX_COULEUR_VIOLET */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			case main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_JAUNE :
			{
				/* Default exit sequence for state CHOIX_COULEUR_JAUNE */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state MATCH_EN_COURS */
		/* Entry action for state 'MATCH_EN_COURS'. */
		timer->setTimer(this, (sc_eventid)(&timeEvents[7]), (DUREE_MATCH) * 1000, false);
		Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
		Application.m_asservissement.setPosition_XYTeta(0, 0, 0);
		Application.m_asservissement.Ind_perfo = 0.3;
		/* 'default' enter sequence for region null */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state SUPERVISOR */
		/* Entry action for state 'SUPERVISOR'. */
		ifaceInternalSCI.etape = 0;
		stateConfVector[0] = main_region_MATCH_EN_COURS__region0_SUPERVISOR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.tempsMatch = 0;
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = -1;
		if (timeEvents[6])
		{ 
			/* Default exit sequence for state KMAR_SORTI_02 */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'KMAR_SORTI_02'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[6]));
			/* 'default' enter sequence for state APPRENTISSAGE_ASCENSEUR */
			/* Entry action for state 'APPRENTISSAGE_ASCENSEUR'. */
			timer->setTimer(this, (sc_eventid)(&timeEvents[2]), 7 * 1000, false);
			Application.m_asservissement_chariot.Recal_Chariot();
			stateConfVector[0] = main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_APPRENTISSAGE_ASCENSEUR;
			stateConfVectorPosition = 0;
		} 
	}
}

/* The reactions of state CHOIX_COULEUR_VIOLET. */
void IA::react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_VIOLET()
{
	/* The reactions of state CHOIX_COULEUR_VIOLET. */
	if (iface.IN_Couleur == 1)
	{ 
		/* Default exit sequence for state CHOIX_COULEUR_VIOLET */
		stateConfVector[1] = IA_last_state;
		stateConfVectorPosition = 1;
		/* 'default' enter sequence for state CHOIX_COULEUR_JAUNE */
		/* Entry action for state 'CHOIX_COULEUR_JAUNE'. */
		iface.Couleur = IA::DefaultSCI::JAUNE;
		Application.m_leds.setPattern(PATTERN_CHENILLE, 50);
		stateConfVector[1] = main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_JAUNE;
		stateConfVectorPosition = 1;
	} 
}

/* The reactions of state CHOIX_COULEUR_JAUNE. */
void IA::react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_JAUNE()
{
	/* The reactions of state CHOIX_COULEUR_JAUNE. */
	if (iface.IN_Couleur == 0)
	{ 
		/* Default exit sequence for state CHOIX_COULEUR_JAUNE */
		stateConfVector[1] = IA_last_state;
		stateConfVectorPosition = 1;
		/* 'default' enter sequence for state CHOIX_COULEUR_VIOLET */
		/* Entry action for state 'CHOIX_COULEUR_VIOLET'. */
		iface.Couleur = IA::DefaultSCI::VIOLET;
		Application.m_leds.setPattern(PATTERN_K2000, 50);
		stateConfVector[1] = main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_VIOLET;
		stateConfVectorPosition = 1;
	} 
}

/* The reactions of state ARRET_ROBOT. */
void IA::react_main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT()
{
	/* The reactions of state ARRET_ROBOT. */
	if (timeEvents[7])
	{ 
		/* Default exit sequence for state MATCH_EN_COURS */
		/* Default exit sequence for region null */
		/* Handle exit of all possible states (of IA.main_region.MATCH_EN_COURS._region0) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'ARRET_ROBOT'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[8]));
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS :
			{
				/* Default exit sequence for state DEPASSE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DEPASSE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[9]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS :
			{
				/* Default exit sequence for state FACE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FACE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[10]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART :
			{
				/* Default exit sequence for state STOCKAGE_DANS_ZONE_DEPART */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'STOCKAGE_DANS_ZONE_DEPART'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[11]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR :
			{
				/* Default exit sequence for state PLACEMENT_DEVANT_DISTRIBUTEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'PLACEMENT_DEVANT_DISTRIBUTEUR'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[12]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES :
			{
				/* Default exit sequence for state VENTOUSAGE_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'VENTOUSAGE_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[13]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES :
			{
				/* Default exit sequence for state RECUPERATION_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'RECUPERATION_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[14]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES :
			{
				/* Default exit sequence for state DEVENTOUSAGE_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case main_region_MATCH_EN_COURS__region0_SUPERVISOR :
			{
				/* Default exit sequence for state SUPERVISOR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* Exit action for state 'MATCH_EN_COURS'. */
		timer->unsetTimer(this, (sc_eventid)(&timeEvents[7]));
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		Application.m_leds.setPattern(PATTERN_CLIGNO_1234, 400);
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = 9999;
		stateConfVector[0] = main_region_FIN_MATCH;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.tempsMatch = iface.tempsMatch + ifaceInternalSCI.Te;
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = ((int32_t) iface.tempsMatch);
		if ((iface.IN_Obstacle == 0) && (ifaceInternalSCI.evitementEnCours == false))
		{ 
			/* Default exit sequence for state DETECTION_OBSTACLE */
			/* Default exit sequence for region r1 */
			/* Handle exit of all possible states (of IA.main_region.MATCH_EN_COURS._region0.DETECTION_OBSTACLE.r1) at position 0... */
			switch(stateConfVector[ 0 ])
			{
				case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT :
				{
					/* Default exit sequence for state ARRET_ROBOT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'ARRET_ROBOT'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[8]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_SORTIE_EVITEMENT :
				{
					/* Default exit sequence for state SORTIE_EVITEMENT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_ :
				{
					/* Default exit sequence for final state. */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				default: break;
			}
			/* Exit action for state 'DETECTION_OBSTACLE'. */
			Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
			react_main_region_MATCH_EN_COURS__region0__choice_0();
		}  else
		{
			if (timeEvents[8])
			{ 
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'ARRET_ROBOT'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[8]));
				/* 'default' enter sequence for state SORTIE_EVITEMENT */
				/* Entry action for state 'SORTIE_EVITEMENT'. */
				ifaceInternalSCI.evitementEnCours = false;
				stateConfVector[0] = main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_SORTIE_EVITEMENT;
				stateConfVectorPosition = 0;
			} 
		}
	}
}

/* The reactions of state SORTIE_EVITEMENT. */
void IA::react_main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_SORTIE_EVITEMENT()
{
	/* The reactions of state SORTIE_EVITEMENT. */
	if (timeEvents[7])
	{ 
		/* Default exit sequence for state MATCH_EN_COURS */
		/* Default exit sequence for region null */
		/* Handle exit of all possible states (of IA.main_region.MATCH_EN_COURS._region0) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'ARRET_ROBOT'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[8]));
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS :
			{
				/* Default exit sequence for state DEPASSE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DEPASSE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[9]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS :
			{
				/* Default exit sequence for state FACE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FACE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[10]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART :
			{
				/* Default exit sequence for state STOCKAGE_DANS_ZONE_DEPART */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'STOCKAGE_DANS_ZONE_DEPART'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[11]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR :
			{
				/* Default exit sequence for state PLACEMENT_DEVANT_DISTRIBUTEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'PLACEMENT_DEVANT_DISTRIBUTEUR'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[12]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES :
			{
				/* Default exit sequence for state VENTOUSAGE_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'VENTOUSAGE_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[13]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES :
			{
				/* Default exit sequence for state RECUPERATION_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'RECUPERATION_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[14]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES :
			{
				/* Default exit sequence for state DEVENTOUSAGE_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case main_region_MATCH_EN_COURS__region0_SUPERVISOR :
			{
				/* Default exit sequence for state SUPERVISOR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* Exit action for state 'MATCH_EN_COURS'. */
		timer->unsetTimer(this, (sc_eventid)(&timeEvents[7]));
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		Application.m_leds.setPattern(PATTERN_CLIGNO_1234, 400);
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = 9999;
		stateConfVector[0] = main_region_FIN_MATCH;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.tempsMatch = iface.tempsMatch + ifaceInternalSCI.Te;
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = ((int32_t) iface.tempsMatch);
		if ((iface.IN_Obstacle == 0) && (ifaceInternalSCI.evitementEnCours == false))
		{ 
			/* Default exit sequence for state DETECTION_OBSTACLE */
			/* Default exit sequence for region r1 */
			/* Handle exit of all possible states (of IA.main_region.MATCH_EN_COURS._region0.DETECTION_OBSTACLE.r1) at position 0... */
			switch(stateConfVector[ 0 ])
			{
				case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT :
				{
					/* Default exit sequence for state ARRET_ROBOT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'ARRET_ROBOT'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[8]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_SORTIE_EVITEMENT :
				{
					/* Default exit sequence for state SORTIE_EVITEMENT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_ :
				{
					/* Default exit sequence for final state. */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				default: break;
			}
			/* Exit action for state 'DETECTION_OBSTACLE'. */
			Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
			react_main_region_MATCH_EN_COURS__region0__choice_0();
		}  else
		{
			/* Default exit sequence for state SORTIE_EVITEMENT */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Default enter sequence for state null */
			stateConfVector[0] = main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_;
			stateConfVectorPosition = 0;
		}
	}
}

/* The reactions of state null. */
void IA::react_main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_()
{
	/* The reactions of state null. */
	if (timeEvents[7])
	{ 
		/* Default exit sequence for state MATCH_EN_COURS */
		/* Default exit sequence for region null */
		/* Handle exit of all possible states (of IA.main_region.MATCH_EN_COURS._region0) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'ARRET_ROBOT'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[8]));
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS :
			{
				/* Default exit sequence for state DEPASSE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DEPASSE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[9]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS :
			{
				/* Default exit sequence for state FACE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FACE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[10]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART :
			{
				/* Default exit sequence for state STOCKAGE_DANS_ZONE_DEPART */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'STOCKAGE_DANS_ZONE_DEPART'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[11]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR :
			{
				/* Default exit sequence for state PLACEMENT_DEVANT_DISTRIBUTEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'PLACEMENT_DEVANT_DISTRIBUTEUR'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[12]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES :
			{
				/* Default exit sequence for state VENTOUSAGE_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'VENTOUSAGE_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[13]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES :
			{
				/* Default exit sequence for state RECUPERATION_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'RECUPERATION_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[14]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES :
			{
				/* Default exit sequence for state DEVENTOUSAGE_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case main_region_MATCH_EN_COURS__region0_SUPERVISOR :
			{
				/* Default exit sequence for state SUPERVISOR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* Exit action for state 'MATCH_EN_COURS'. */
		timer->unsetTimer(this, (sc_eventid)(&timeEvents[7]));
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		Application.m_leds.setPattern(PATTERN_CLIGNO_1234, 400);
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = 9999;
		stateConfVector[0] = main_region_FIN_MATCH;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.tempsMatch = iface.tempsMatch + ifaceInternalSCI.Te;
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = ((int32_t) iface.tempsMatch);
		if ((iface.IN_Obstacle == 0) && (ifaceInternalSCI.evitementEnCours == false))
		{ 
			/* Default exit sequence for state DETECTION_OBSTACLE */
			/* Default exit sequence for region r1 */
			/* Handle exit of all possible states (of IA.main_region.MATCH_EN_COURS._region0.DETECTION_OBSTACLE.r1) at position 0... */
			switch(stateConfVector[ 0 ])
			{
				case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT :
				{
					/* Default exit sequence for state ARRET_ROBOT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'ARRET_ROBOT'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[8]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_SORTIE_EVITEMENT :
				{
					/* Default exit sequence for state SORTIE_EVITEMENT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_ :
				{
					/* Default exit sequence for final state. */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				default: break;
			}
			/* Exit action for state 'DETECTION_OBSTACLE'. */
			Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
			react_main_region_MATCH_EN_COURS__region0__choice_0();
		} 
	}
}

/* The reactions of state DEPASSE_ZONE_CHAOS. */
void IA::react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS()
{
	/* The reactions of state DEPASSE_ZONE_CHAOS. */
	if (timeEvents[7])
	{ 
		/* Default exit sequence for state MATCH_EN_COURS */
		/* Default exit sequence for region null */
		/* Handle exit of all possible states (of IA.main_region.MATCH_EN_COURS._region0) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'ARRET_ROBOT'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[8]));
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS :
			{
				/* Default exit sequence for state DEPASSE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DEPASSE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[9]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS :
			{
				/* Default exit sequence for state FACE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FACE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[10]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART :
			{
				/* Default exit sequence for state STOCKAGE_DANS_ZONE_DEPART */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'STOCKAGE_DANS_ZONE_DEPART'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[11]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR :
			{
				/* Default exit sequence for state PLACEMENT_DEVANT_DISTRIBUTEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'PLACEMENT_DEVANT_DISTRIBUTEUR'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[12]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES :
			{
				/* Default exit sequence for state VENTOUSAGE_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'VENTOUSAGE_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[13]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES :
			{
				/* Default exit sequence for state RECUPERATION_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'RECUPERATION_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[14]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES :
			{
				/* Default exit sequence for state DEVENTOUSAGE_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case main_region_MATCH_EN_COURS__region0_SUPERVISOR :
			{
				/* Default exit sequence for state SUPERVISOR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* Exit action for state 'MATCH_EN_COURS'. */
		timer->unsetTimer(this, (sc_eventid)(&timeEvents[7]));
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		Application.m_leds.setPattern(PATTERN_CLIGNO_1234, 400);
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = 9999;
		stateConfVector[0] = main_region_FIN_MATCH;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.tempsMatch = iface.tempsMatch + ifaceInternalSCI.Te;
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = ((int32_t) iface.tempsMatch);
		if ((iface.IN_Obstacle == 1) && (ifaceInternalSCI.inhibeObstacle == false))
		{ 
			/* Default exit sequence for state NETTOYAGE */
			/* Default exit sequence for region r1 */
			/* Handle exit of all possible states (of IA.main_region.MATCH_EN_COURS._region0.NETTOYAGE.r1) at position 0... */
			switch(stateConfVector[ 0 ])
			{
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS :
				{
					/* Default exit sequence for state DEPASSE_ZONE_CHAOS */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'DEPASSE_ZONE_CHAOS'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[9]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS :
				{
					/* Default exit sequence for state FACE_ZONE_CHAOS */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FACE_ZONE_CHAOS'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[10]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART :
				{
					/* Default exit sequence for state STOCKAGE_DANS_ZONE_DEPART */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'STOCKAGE_DANS_ZONE_DEPART'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[11]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR :
				{
					/* Default exit sequence for state PLACEMENT_DEVANT_DISTRIBUTEUR */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'PLACEMENT_DEVANT_DISTRIBUTEUR'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[12]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES :
				{
					/* Default exit sequence for state VENTOUSAGE_ATOMES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'VENTOUSAGE_ATOMES'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[13]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES :
				{
					/* Default exit sequence for state RECUPERATION_ATOMES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'RECUPERATION_ATOMES'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[14]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES :
				{
					/* Default exit sequence for state DEVENTOUSAGE_ATOMES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				default: break;
			}
			/* 'default' enter sequence for state DETECTION_OBSTACLE */
			/* Entry action for state 'DETECTION_OBSTACLE'. */
			ifaceInternalSCI.evitementEnCours = true;
			Application.m_leds.setPattern(PATTERN_K2000, 1000);
			/* 'default' enter sequence for region r1 */
			/* Default react sequence for initial entry  */
			/* 'default' enter sequence for state ARRET_ROBOT */
			/* Entry action for state 'ARRET_ROBOT'. */
			timer->setTimer(this, (sc_eventid)(&timeEvents[8]), (1) * 1000, false);
			Application.m_asservissement.CommandeManuelle(0, 0);
			stateConfVector[0] = main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT;
			stateConfVectorPosition = 0;
		}  else
		{
			if (iface.EV_ConvergenceMvt_Rapide_raised || timeEvents[9])
			{ 
				/* Default exit sequence for state DEPASSE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DEPASSE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[9]));
				/* 'default' enter sequence for state FACE_ZONE_CHAOS */
				/* Entry action for state 'FACE_ZONE_CHAOS'. */
				timer->setTimer(this, (sc_eventid)(&timeEvents[10]), 3 * 1000, false);
				SCI_Asser_OCB::XYTeta(114, -57, 0);
				stateConfVector[0] = main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS;
				stateConfVectorPosition = 0;
				historyVector[0] = stateConfVector[0];
			} 
		}
	}
}

/* The reactions of state FACE_ZONE_CHAOS. */
void IA::react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS()
{
	/* The reactions of state FACE_ZONE_CHAOS. */
	if (timeEvents[7])
	{ 
		/* Default exit sequence for state MATCH_EN_COURS */
		/* Default exit sequence for region null */
		/* Handle exit of all possible states (of IA.main_region.MATCH_EN_COURS._region0) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'ARRET_ROBOT'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[8]));
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS :
			{
				/* Default exit sequence for state DEPASSE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DEPASSE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[9]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS :
			{
				/* Default exit sequence for state FACE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FACE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[10]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART :
			{
				/* Default exit sequence for state STOCKAGE_DANS_ZONE_DEPART */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'STOCKAGE_DANS_ZONE_DEPART'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[11]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR :
			{
				/* Default exit sequence for state PLACEMENT_DEVANT_DISTRIBUTEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'PLACEMENT_DEVANT_DISTRIBUTEUR'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[12]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES :
			{
				/* Default exit sequence for state VENTOUSAGE_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'VENTOUSAGE_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[13]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES :
			{
				/* Default exit sequence for state RECUPERATION_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'RECUPERATION_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[14]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES :
			{
				/* Default exit sequence for state DEVENTOUSAGE_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case main_region_MATCH_EN_COURS__region0_SUPERVISOR :
			{
				/* Default exit sequence for state SUPERVISOR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* Exit action for state 'MATCH_EN_COURS'. */
		timer->unsetTimer(this, (sc_eventid)(&timeEvents[7]));
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		Application.m_leds.setPattern(PATTERN_CLIGNO_1234, 400);
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = 9999;
		stateConfVector[0] = main_region_FIN_MATCH;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.tempsMatch = iface.tempsMatch + ifaceInternalSCI.Te;
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = ((int32_t) iface.tempsMatch);
		if ((iface.IN_Obstacle == 1) && (ifaceInternalSCI.inhibeObstacle == false))
		{ 
			/* Default exit sequence for state NETTOYAGE */
			/* Default exit sequence for region r1 */
			/* Handle exit of all possible states (of IA.main_region.MATCH_EN_COURS._region0.NETTOYAGE.r1) at position 0... */
			switch(stateConfVector[ 0 ])
			{
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS :
				{
					/* Default exit sequence for state DEPASSE_ZONE_CHAOS */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'DEPASSE_ZONE_CHAOS'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[9]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS :
				{
					/* Default exit sequence for state FACE_ZONE_CHAOS */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FACE_ZONE_CHAOS'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[10]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART :
				{
					/* Default exit sequence for state STOCKAGE_DANS_ZONE_DEPART */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'STOCKAGE_DANS_ZONE_DEPART'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[11]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR :
				{
					/* Default exit sequence for state PLACEMENT_DEVANT_DISTRIBUTEUR */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'PLACEMENT_DEVANT_DISTRIBUTEUR'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[12]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES :
				{
					/* Default exit sequence for state VENTOUSAGE_ATOMES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'VENTOUSAGE_ATOMES'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[13]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES :
				{
					/* Default exit sequence for state RECUPERATION_ATOMES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'RECUPERATION_ATOMES'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[14]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES :
				{
					/* Default exit sequence for state DEVENTOUSAGE_ATOMES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				default: break;
			}
			/* 'default' enter sequence for state DETECTION_OBSTACLE */
			/* Entry action for state 'DETECTION_OBSTACLE'. */
			ifaceInternalSCI.evitementEnCours = true;
			Application.m_leds.setPattern(PATTERN_K2000, 1000);
			/* 'default' enter sequence for region r1 */
			/* Default react sequence for initial entry  */
			/* 'default' enter sequence for state ARRET_ROBOT */
			/* Entry action for state 'ARRET_ROBOT'. */
			timer->setTimer(this, (sc_eventid)(&timeEvents[8]), (1) * 1000, false);
			Application.m_asservissement.CommandeManuelle(0, 0);
			stateConfVector[0] = main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT;
			stateConfVectorPosition = 0;
		}  else
		{
			if (iface.EV_ConvergenceMvt_raised || timeEvents[10])
			{ 
				/* Default exit sequence for state FACE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FACE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[10]));
				/* 'default' enter sequence for state STOCKAGE_DANS_ZONE_DEPART */
				/* Entry action for state 'STOCKAGE_DANS_ZONE_DEPART'. */
				timer->setTimer(this, (sc_eventid)(&timeEvents[11]), 3 * 1000, false);
				SCI_Asser_OCB::XYTeta(30, -57, 0);
				stateConfVector[0] = main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART;
				stateConfVectorPosition = 0;
				historyVector[0] = stateConfVector[0];
			} 
		}
	}
}

/* The reactions of state STOCKAGE_DANS_ZONE_DEPART. */
void IA::react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART()
{
	/* The reactions of state STOCKAGE_DANS_ZONE_DEPART. */
	if (timeEvents[7])
	{ 
		/* Default exit sequence for state MATCH_EN_COURS */
		/* Default exit sequence for region null */
		/* Handle exit of all possible states (of IA.main_region.MATCH_EN_COURS._region0) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'ARRET_ROBOT'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[8]));
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS :
			{
				/* Default exit sequence for state DEPASSE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DEPASSE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[9]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS :
			{
				/* Default exit sequence for state FACE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FACE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[10]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART :
			{
				/* Default exit sequence for state STOCKAGE_DANS_ZONE_DEPART */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'STOCKAGE_DANS_ZONE_DEPART'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[11]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR :
			{
				/* Default exit sequence for state PLACEMENT_DEVANT_DISTRIBUTEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'PLACEMENT_DEVANT_DISTRIBUTEUR'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[12]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES :
			{
				/* Default exit sequence for state VENTOUSAGE_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'VENTOUSAGE_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[13]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES :
			{
				/* Default exit sequence for state RECUPERATION_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'RECUPERATION_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[14]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES :
			{
				/* Default exit sequence for state DEVENTOUSAGE_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case main_region_MATCH_EN_COURS__region0_SUPERVISOR :
			{
				/* Default exit sequence for state SUPERVISOR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* Exit action for state 'MATCH_EN_COURS'. */
		timer->unsetTimer(this, (sc_eventid)(&timeEvents[7]));
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		Application.m_leds.setPattern(PATTERN_CLIGNO_1234, 400);
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = 9999;
		stateConfVector[0] = main_region_FIN_MATCH;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.tempsMatch = iface.tempsMatch + ifaceInternalSCI.Te;
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = ((int32_t) iface.tempsMatch);
		if ((iface.IN_Obstacle == 1) && (ifaceInternalSCI.inhibeObstacle == false))
		{ 
			/* Default exit sequence for state NETTOYAGE */
			/* Default exit sequence for region r1 */
			/* Handle exit of all possible states (of IA.main_region.MATCH_EN_COURS._region0.NETTOYAGE.r1) at position 0... */
			switch(stateConfVector[ 0 ])
			{
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS :
				{
					/* Default exit sequence for state DEPASSE_ZONE_CHAOS */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'DEPASSE_ZONE_CHAOS'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[9]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS :
				{
					/* Default exit sequence for state FACE_ZONE_CHAOS */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FACE_ZONE_CHAOS'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[10]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART :
				{
					/* Default exit sequence for state STOCKAGE_DANS_ZONE_DEPART */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'STOCKAGE_DANS_ZONE_DEPART'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[11]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR :
				{
					/* Default exit sequence for state PLACEMENT_DEVANT_DISTRIBUTEUR */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'PLACEMENT_DEVANT_DISTRIBUTEUR'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[12]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES :
				{
					/* Default exit sequence for state VENTOUSAGE_ATOMES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'VENTOUSAGE_ATOMES'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[13]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES :
				{
					/* Default exit sequence for state RECUPERATION_ATOMES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'RECUPERATION_ATOMES'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[14]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES :
				{
					/* Default exit sequence for state DEVENTOUSAGE_ATOMES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				default: break;
			}
			/* 'default' enter sequence for state DETECTION_OBSTACLE */
			/* Entry action for state 'DETECTION_OBSTACLE'. */
			ifaceInternalSCI.evitementEnCours = true;
			Application.m_leds.setPattern(PATTERN_K2000, 1000);
			/* 'default' enter sequence for region r1 */
			/* Default react sequence for initial entry  */
			/* 'default' enter sequence for state ARRET_ROBOT */
			/* Entry action for state 'ARRET_ROBOT'. */
			timer->setTimer(this, (sc_eventid)(&timeEvents[8]), (1) * 1000, false);
			Application.m_asservissement.CommandeManuelle(0, 0);
			stateConfVector[0] = main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT;
			stateConfVectorPosition = 0;
		}  else
		{
			if (iface.EV_ConvergenceMvt_raised || timeEvents[11])
			{ 
				/* Default exit sequence for state STOCKAGE_DANS_ZONE_DEPART */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'STOCKAGE_DANS_ZONE_DEPART'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[11]));
				/* 'default' enter sequence for state PLACEMENT_DEVANT_DISTRIBUTEUR */
				/* Entry action for state 'PLACEMENT_DEVANT_DISTRIBUTEUR'. */
				timer->setTimer(this, (sc_eventid)(&timeEvents[12]), 4 * 1000, false);
				SCI_Asser_OCB::XYTeta(82, -80, IA::DefaultSCI::PI / 2);
				stateConfVector[0] = main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR;
				stateConfVectorPosition = 0;
				historyVector[0] = stateConfVector[0];
			} 
		}
	}
}

/* The reactions of state PLACEMENT_DEVANT_DISTRIBUTEUR. */
void IA::react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR()
{
	/* The reactions of state PLACEMENT_DEVANT_DISTRIBUTEUR. */
	if (timeEvents[7])
	{ 
		/* Default exit sequence for state MATCH_EN_COURS */
		/* Default exit sequence for region null */
		/* Handle exit of all possible states (of IA.main_region.MATCH_EN_COURS._region0) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'ARRET_ROBOT'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[8]));
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS :
			{
				/* Default exit sequence for state DEPASSE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DEPASSE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[9]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS :
			{
				/* Default exit sequence for state FACE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FACE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[10]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART :
			{
				/* Default exit sequence for state STOCKAGE_DANS_ZONE_DEPART */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'STOCKAGE_DANS_ZONE_DEPART'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[11]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR :
			{
				/* Default exit sequence for state PLACEMENT_DEVANT_DISTRIBUTEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'PLACEMENT_DEVANT_DISTRIBUTEUR'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[12]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES :
			{
				/* Default exit sequence for state VENTOUSAGE_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'VENTOUSAGE_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[13]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES :
			{
				/* Default exit sequence for state RECUPERATION_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'RECUPERATION_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[14]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES :
			{
				/* Default exit sequence for state DEVENTOUSAGE_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case main_region_MATCH_EN_COURS__region0_SUPERVISOR :
			{
				/* Default exit sequence for state SUPERVISOR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* Exit action for state 'MATCH_EN_COURS'. */
		timer->unsetTimer(this, (sc_eventid)(&timeEvents[7]));
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		Application.m_leds.setPattern(PATTERN_CLIGNO_1234, 400);
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = 9999;
		stateConfVector[0] = main_region_FIN_MATCH;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.tempsMatch = iface.tempsMatch + ifaceInternalSCI.Te;
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = ((int32_t) iface.tempsMatch);
		if ((iface.IN_Obstacle == 1) && (ifaceInternalSCI.inhibeObstacle == false))
		{ 
			/* Default exit sequence for state NETTOYAGE */
			/* Default exit sequence for region r1 */
			/* Handle exit of all possible states (of IA.main_region.MATCH_EN_COURS._region0.NETTOYAGE.r1) at position 0... */
			switch(stateConfVector[ 0 ])
			{
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS :
				{
					/* Default exit sequence for state DEPASSE_ZONE_CHAOS */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'DEPASSE_ZONE_CHAOS'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[9]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS :
				{
					/* Default exit sequence for state FACE_ZONE_CHAOS */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FACE_ZONE_CHAOS'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[10]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART :
				{
					/* Default exit sequence for state STOCKAGE_DANS_ZONE_DEPART */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'STOCKAGE_DANS_ZONE_DEPART'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[11]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR :
				{
					/* Default exit sequence for state PLACEMENT_DEVANT_DISTRIBUTEUR */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'PLACEMENT_DEVANT_DISTRIBUTEUR'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[12]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES :
				{
					/* Default exit sequence for state VENTOUSAGE_ATOMES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'VENTOUSAGE_ATOMES'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[13]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES :
				{
					/* Default exit sequence for state RECUPERATION_ATOMES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'RECUPERATION_ATOMES'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[14]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES :
				{
					/* Default exit sequence for state DEVENTOUSAGE_ATOMES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				default: break;
			}
			/* 'default' enter sequence for state DETECTION_OBSTACLE */
			/* Entry action for state 'DETECTION_OBSTACLE'. */
			ifaceInternalSCI.evitementEnCours = true;
			Application.m_leds.setPattern(PATTERN_K2000, 1000);
			/* 'default' enter sequence for region r1 */
			/* Default react sequence for initial entry  */
			/* 'default' enter sequence for state ARRET_ROBOT */
			/* Entry action for state 'ARRET_ROBOT'. */
			timer->setTimer(this, (sc_eventid)(&timeEvents[8]), (1) * 1000, false);
			Application.m_asservissement.CommandeManuelle(0, 0);
			stateConfVector[0] = main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT;
			stateConfVectorPosition = 0;
		}  else
		{
			if (iface.EV_ConvergenceMvt_raised || timeEvents[12])
			{ 
				/* Default exit sequence for state PLACEMENT_DEVANT_DISTRIBUTEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'PLACEMENT_DEVANT_DISTRIBUTEUR'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[12]));
				/* 'default' enter sequence for state VENTOUSAGE_ATOMES */
				/* Entry action for state 'VENTOUSAGE_ATOMES'. */
				timer->setTimer(this, (sc_eventid)(&timeEvents[13]), 2 * 1000, false);
				Application.m_power_switch.setOutput(POMPE_ARD, true);
				Application.m_power_switch.setOutput(POMPE_ARG, true);
				Application.m_servos_sd20.CommandePosition(SERVO_BRAS_ARG, 140);
				Application.m_servos_ax.setPosition(SERVO_VENTOUSE_ARG_VERT, 572);
				Application.m_servos_sd20.CommandePosition(SERVO_BRAS_ARD, 160);
				Application.m_servos_ax.setPosition(SERVO_VENTOUSE_ARD_VERT, 450);
				stateConfVector[0] = main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES;
				stateConfVectorPosition = 0;
				historyVector[0] = stateConfVector[0];
			} 
		}
	}
}

/* The reactions of state VENTOUSAGE_ATOMES. */
void IA::react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES()
{
	/* The reactions of state VENTOUSAGE_ATOMES. */
	if (timeEvents[7])
	{ 
		/* Default exit sequence for state MATCH_EN_COURS */
		/* Default exit sequence for region null */
		/* Handle exit of all possible states (of IA.main_region.MATCH_EN_COURS._region0) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'ARRET_ROBOT'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[8]));
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS :
			{
				/* Default exit sequence for state DEPASSE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DEPASSE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[9]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS :
			{
				/* Default exit sequence for state FACE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FACE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[10]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART :
			{
				/* Default exit sequence for state STOCKAGE_DANS_ZONE_DEPART */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'STOCKAGE_DANS_ZONE_DEPART'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[11]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR :
			{
				/* Default exit sequence for state PLACEMENT_DEVANT_DISTRIBUTEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'PLACEMENT_DEVANT_DISTRIBUTEUR'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[12]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES :
			{
				/* Default exit sequence for state VENTOUSAGE_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'VENTOUSAGE_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[13]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES :
			{
				/* Default exit sequence for state RECUPERATION_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'RECUPERATION_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[14]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES :
			{
				/* Default exit sequence for state DEVENTOUSAGE_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case main_region_MATCH_EN_COURS__region0_SUPERVISOR :
			{
				/* Default exit sequence for state SUPERVISOR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* Exit action for state 'MATCH_EN_COURS'. */
		timer->unsetTimer(this, (sc_eventid)(&timeEvents[7]));
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		Application.m_leds.setPattern(PATTERN_CLIGNO_1234, 400);
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = 9999;
		stateConfVector[0] = main_region_FIN_MATCH;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.tempsMatch = iface.tempsMatch + ifaceInternalSCI.Te;
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = ((int32_t) iface.tempsMatch);
		if ((iface.IN_Obstacle == 1) && (ifaceInternalSCI.inhibeObstacle == false))
		{ 
			/* Default exit sequence for state NETTOYAGE */
			/* Default exit sequence for region r1 */
			/* Handle exit of all possible states (of IA.main_region.MATCH_EN_COURS._region0.NETTOYAGE.r1) at position 0... */
			switch(stateConfVector[ 0 ])
			{
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS :
				{
					/* Default exit sequence for state DEPASSE_ZONE_CHAOS */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'DEPASSE_ZONE_CHAOS'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[9]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS :
				{
					/* Default exit sequence for state FACE_ZONE_CHAOS */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FACE_ZONE_CHAOS'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[10]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART :
				{
					/* Default exit sequence for state STOCKAGE_DANS_ZONE_DEPART */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'STOCKAGE_DANS_ZONE_DEPART'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[11]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR :
				{
					/* Default exit sequence for state PLACEMENT_DEVANT_DISTRIBUTEUR */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'PLACEMENT_DEVANT_DISTRIBUTEUR'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[12]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES :
				{
					/* Default exit sequence for state VENTOUSAGE_ATOMES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'VENTOUSAGE_ATOMES'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[13]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES :
				{
					/* Default exit sequence for state RECUPERATION_ATOMES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'RECUPERATION_ATOMES'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[14]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES :
				{
					/* Default exit sequence for state DEVENTOUSAGE_ATOMES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				default: break;
			}
			/* 'default' enter sequence for state DETECTION_OBSTACLE */
			/* Entry action for state 'DETECTION_OBSTACLE'. */
			ifaceInternalSCI.evitementEnCours = true;
			Application.m_leds.setPattern(PATTERN_K2000, 1000);
			/* 'default' enter sequence for region r1 */
			/* Default react sequence for initial entry  */
			/* 'default' enter sequence for state ARRET_ROBOT */
			/* Entry action for state 'ARRET_ROBOT'. */
			timer->setTimer(this, (sc_eventid)(&timeEvents[8]), (1) * 1000, false);
			Application.m_asservissement.CommandeManuelle(0, 0);
			stateConfVector[0] = main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT;
			stateConfVectorPosition = 0;
		}  else
		{
			if (timeEvents[13])
			{ 
				/* Default exit sequence for state VENTOUSAGE_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'VENTOUSAGE_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[13]));
				/* 'default' enter sequence for state RECUPERATION_ATOMES */
				/* Entry action for state 'RECUPERATION_ATOMES'. */
				timer->setTimer(this, (sc_eventid)(&timeEvents[14]), 1 * 1000, false);
				Application.m_servos_sd20.CommandePosition(SERVO_BRAS_ARG, 50);
				Application.m_servos_ax.setPosition(SERVO_VENTOUSE_ARG_VERT, 170);
				Application.m_servos_sd20.CommandePosition(SERVO_BRAS_ARD, 255);
				Application.m_servos_ax.setPosition(SERVO_VENTOUSE_ARD_VERT, 850);
				stateConfVector[0] = main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES;
				stateConfVectorPosition = 0;
				historyVector[0] = stateConfVector[0];
			} 
		}
	}
}

/* The reactions of state RECUPERATION_ATOMES. */
void IA::react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES()
{
	/* The reactions of state RECUPERATION_ATOMES. */
	if (timeEvents[7])
	{ 
		/* Default exit sequence for state MATCH_EN_COURS */
		/* Default exit sequence for region null */
		/* Handle exit of all possible states (of IA.main_region.MATCH_EN_COURS._region0) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'ARRET_ROBOT'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[8]));
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS :
			{
				/* Default exit sequence for state DEPASSE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DEPASSE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[9]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS :
			{
				/* Default exit sequence for state FACE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FACE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[10]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART :
			{
				/* Default exit sequence for state STOCKAGE_DANS_ZONE_DEPART */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'STOCKAGE_DANS_ZONE_DEPART'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[11]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR :
			{
				/* Default exit sequence for state PLACEMENT_DEVANT_DISTRIBUTEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'PLACEMENT_DEVANT_DISTRIBUTEUR'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[12]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES :
			{
				/* Default exit sequence for state VENTOUSAGE_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'VENTOUSAGE_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[13]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES :
			{
				/* Default exit sequence for state RECUPERATION_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'RECUPERATION_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[14]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES :
			{
				/* Default exit sequence for state DEVENTOUSAGE_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case main_region_MATCH_EN_COURS__region0_SUPERVISOR :
			{
				/* Default exit sequence for state SUPERVISOR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* Exit action for state 'MATCH_EN_COURS'. */
		timer->unsetTimer(this, (sc_eventid)(&timeEvents[7]));
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		Application.m_leds.setPattern(PATTERN_CLIGNO_1234, 400);
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = 9999;
		stateConfVector[0] = main_region_FIN_MATCH;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.tempsMatch = iface.tempsMatch + ifaceInternalSCI.Te;
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = ((int32_t) iface.tempsMatch);
		if ((iface.IN_Obstacle == 1) && (ifaceInternalSCI.inhibeObstacle == false))
		{ 
			/* Default exit sequence for state NETTOYAGE */
			/* Default exit sequence for region r1 */
			/* Handle exit of all possible states (of IA.main_region.MATCH_EN_COURS._region0.NETTOYAGE.r1) at position 0... */
			switch(stateConfVector[ 0 ])
			{
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS :
				{
					/* Default exit sequence for state DEPASSE_ZONE_CHAOS */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'DEPASSE_ZONE_CHAOS'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[9]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS :
				{
					/* Default exit sequence for state FACE_ZONE_CHAOS */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FACE_ZONE_CHAOS'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[10]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART :
				{
					/* Default exit sequence for state STOCKAGE_DANS_ZONE_DEPART */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'STOCKAGE_DANS_ZONE_DEPART'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[11]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR :
				{
					/* Default exit sequence for state PLACEMENT_DEVANT_DISTRIBUTEUR */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'PLACEMENT_DEVANT_DISTRIBUTEUR'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[12]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES :
				{
					/* Default exit sequence for state VENTOUSAGE_ATOMES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'VENTOUSAGE_ATOMES'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[13]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES :
				{
					/* Default exit sequence for state RECUPERATION_ATOMES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'RECUPERATION_ATOMES'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[14]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES :
				{
					/* Default exit sequence for state DEVENTOUSAGE_ATOMES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				default: break;
			}
			/* 'default' enter sequence for state DETECTION_OBSTACLE */
			/* Entry action for state 'DETECTION_OBSTACLE'. */
			ifaceInternalSCI.evitementEnCours = true;
			Application.m_leds.setPattern(PATTERN_K2000, 1000);
			/* 'default' enter sequence for region r1 */
			/* Default react sequence for initial entry  */
			/* 'default' enter sequence for state ARRET_ROBOT */
			/* Entry action for state 'ARRET_ROBOT'. */
			timer->setTimer(this, (sc_eventid)(&timeEvents[8]), (1) * 1000, false);
			Application.m_asservissement.CommandeManuelle(0, 0);
			stateConfVector[0] = main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT;
			stateConfVectorPosition = 0;
		}  else
		{
			if (timeEvents[14])
			{ 
				/* Default exit sequence for state RECUPERATION_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'RECUPERATION_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[14]));
				/* 'default' enter sequence for state DEVENTOUSAGE_ATOMES */
				/* Entry action for state 'DEVENTOUSAGE_ATOMES'. */
				Application.m_power_switch.setOutput(POMPE_ARD, false);
				Application.m_power_switch.setOutput(EV_ARD, false);
				Application.m_power_switch.setOutput(POMPE_ARG, false);
				Application.m_power_switch.setOutput(EV_ARG, false);
				stateConfVector[0] = main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES;
				stateConfVectorPosition = 0;
				historyVector[0] = stateConfVector[0];
			} 
		}
	}
}

/* The reactions of state DEVENTOUSAGE_ATOMES. */
void IA::react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES()
{
	/* The reactions of state DEVENTOUSAGE_ATOMES. */
	if (timeEvents[7])
	{ 
		/* Default exit sequence for state MATCH_EN_COURS */
		/* Default exit sequence for region null */
		/* Handle exit of all possible states (of IA.main_region.MATCH_EN_COURS._region0) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'ARRET_ROBOT'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[8]));
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS :
			{
				/* Default exit sequence for state DEPASSE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DEPASSE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[9]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS :
			{
				/* Default exit sequence for state FACE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FACE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[10]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART :
			{
				/* Default exit sequence for state STOCKAGE_DANS_ZONE_DEPART */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'STOCKAGE_DANS_ZONE_DEPART'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[11]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR :
			{
				/* Default exit sequence for state PLACEMENT_DEVANT_DISTRIBUTEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'PLACEMENT_DEVANT_DISTRIBUTEUR'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[12]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES :
			{
				/* Default exit sequence for state VENTOUSAGE_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'VENTOUSAGE_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[13]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES :
			{
				/* Default exit sequence for state RECUPERATION_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'RECUPERATION_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[14]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES :
			{
				/* Default exit sequence for state DEVENTOUSAGE_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case main_region_MATCH_EN_COURS__region0_SUPERVISOR :
			{
				/* Default exit sequence for state SUPERVISOR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* Exit action for state 'MATCH_EN_COURS'. */
		timer->unsetTimer(this, (sc_eventid)(&timeEvents[7]));
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		Application.m_leds.setPattern(PATTERN_CLIGNO_1234, 400);
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = 9999;
		stateConfVector[0] = main_region_FIN_MATCH;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.tempsMatch = iface.tempsMatch + ifaceInternalSCI.Te;
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = ((int32_t) iface.tempsMatch);
		if ((iface.IN_Obstacle == 1) && (ifaceInternalSCI.inhibeObstacle == false))
		{ 
			/* Default exit sequence for state NETTOYAGE */
			/* Default exit sequence for region r1 */
			/* Handle exit of all possible states (of IA.main_region.MATCH_EN_COURS._region0.NETTOYAGE.r1) at position 0... */
			switch(stateConfVector[ 0 ])
			{
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS :
				{
					/* Default exit sequence for state DEPASSE_ZONE_CHAOS */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'DEPASSE_ZONE_CHAOS'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[9]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS :
				{
					/* Default exit sequence for state FACE_ZONE_CHAOS */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FACE_ZONE_CHAOS'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[10]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART :
				{
					/* Default exit sequence for state STOCKAGE_DANS_ZONE_DEPART */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'STOCKAGE_DANS_ZONE_DEPART'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[11]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR :
				{
					/* Default exit sequence for state PLACEMENT_DEVANT_DISTRIBUTEUR */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'PLACEMENT_DEVANT_DISTRIBUTEUR'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[12]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES :
				{
					/* Default exit sequence for state VENTOUSAGE_ATOMES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'VENTOUSAGE_ATOMES'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[13]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES :
				{
					/* Default exit sequence for state RECUPERATION_ATOMES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'RECUPERATION_ATOMES'. */
					timer->unsetTimer(this, (sc_eventid)(&timeEvents[14]));
					break;
				}
				case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES :
				{
					/* Default exit sequence for state DEVENTOUSAGE_ATOMES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				default: break;
			}
			/* 'default' enter sequence for state DETECTION_OBSTACLE */
			/* Entry action for state 'DETECTION_OBSTACLE'. */
			ifaceInternalSCI.evitementEnCours = true;
			Application.m_leds.setPattern(PATTERN_K2000, 1000);
			/* 'default' enter sequence for region r1 */
			/* Default react sequence for initial entry  */
			/* 'default' enter sequence for state ARRET_ROBOT */
			/* Entry action for state 'ARRET_ROBOT'. */
			timer->setTimer(this, (sc_eventid)(&timeEvents[8]), (1) * 1000, false);
			Application.m_asservissement.CommandeManuelle(0, 0);
			stateConfVector[0] = main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT;
			stateConfVectorPosition = 0;
		} 
	}
}

/* The reactions of state SUPERVISOR. */
void IA::react_main_region_MATCH_EN_COURS__region0_SUPERVISOR()
{
	/* The reactions of state SUPERVISOR. */
	if (timeEvents[7])
	{ 
		/* Default exit sequence for state MATCH_EN_COURS */
		/* Default exit sequence for region null */
		/* Handle exit of all possible states (of IA.main_region.MATCH_EN_COURS._region0) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'ARRET_ROBOT'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[8]));
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DETECTION_OBSTACLE'. */
				Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 1000);
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS :
			{
				/* Default exit sequence for state DEPASSE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'DEPASSE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[9]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS :
			{
				/* Default exit sequence for state FACE_ZONE_CHAOS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FACE_ZONE_CHAOS'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[10]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART :
			{
				/* Default exit sequence for state STOCKAGE_DANS_ZONE_DEPART */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'STOCKAGE_DANS_ZONE_DEPART'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[11]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR :
			{
				/* Default exit sequence for state PLACEMENT_DEVANT_DISTRIBUTEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'PLACEMENT_DEVANT_DISTRIBUTEUR'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[12]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES :
			{
				/* Default exit sequence for state VENTOUSAGE_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'VENTOUSAGE_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[13]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES :
			{
				/* Default exit sequence for state RECUPERATION_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'RECUPERATION_ATOMES'. */
				timer->unsetTimer(this, (sc_eventid)(&timeEvents[14]));
				break;
			}
			case main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES :
			{
				/* Default exit sequence for state DEVENTOUSAGE_ATOMES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case main_region_MATCH_EN_COURS__region0_SUPERVISOR :
			{
				/* Default exit sequence for state SUPERVISOR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* Exit action for state 'MATCH_EN_COURS'. */
		timer->unsetTimer(this, (sc_eventid)(&timeEvents[7]));
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		Application.m_leds.setPattern(PATTERN_CLIGNO_1234, 400);
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = 9999;
		stateConfVector[0] = main_region_FIN_MATCH;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.tempsMatch = iface.tempsMatch + ifaceInternalSCI.Te;
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp = ((int32_t) iface.tempsMatch);
		/* Default exit sequence for state SUPERVISOR */
		stateConfVector[0] = IA_last_state;
		stateConfVectorPosition = 0;
		/* 'Entry_init' enter sequence for state NETTOYAGE */
		/* 'Entry_init' enter sequence for region r1 */
		/* Default react sequence for initial entry Entry_init */
		/* 'default' enter sequence for state DEPASSE_ZONE_CHAOS */
		/* Entry action for state 'DEPASSE_ZONE_CHAOS'. */
		timer->setTimer(this, (sc_eventid)(&timeEvents[9]), 3 * 1000, false);
		SCI_Asser_OCB::XYTeta(114, 0, 0);
		stateConfVector[0] = main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS;
		stateConfVectorPosition = 0;
		historyVector[0] = stateConfVector[0];
	}
}

/* The reactions of state FIN_MATCH. */
void IA::react_main_region_FIN_MATCH()
{
	/* The reactions of state FIN_MATCH. */
	Application.m_asservissement.CommandeManuelle(0, 0);
}

/* The reactions of state null. */
void IA::react_main_region_MATCH_EN_COURS__region0__choice_0()
{
	/* The reactions of state null. */
	/* 'Entry_history' enter sequence for state NETTOYAGE */
	/* 'Entry_history' enter sequence for region r1 */
	/* Default react sequence for initial entry Entry_history */
	/* Default react sequence for shallow history entry  */
	/* Enter the region with shallow history */
	if (historyVector[0] != IA_last_state)
	{
		shenseq_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1();
	} 
}



