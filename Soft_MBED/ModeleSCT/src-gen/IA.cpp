
#include "IA.h"
#include <string.h>

/*! \file Implementation of the state machine 'IA'
*/

IA::IA()
{
	
	
	for (int i = 0; i < maxHistoryStates; ++i)
		historyVector[i] = IA_last_state;
	
	stateConfVectorPosition = 0;
	
}

IA::~IA()
{
}

const sc_integer IA::DefaultSCI::SERVO_VENTOUSE = 13;
const sc_integer IA::DefaultSCI::SERVO_CENTREUR_G = 14;
const sc_integer IA::DefaultSCI::SERVO_CENTREUR_D = 15;
const sc_integer IA::DefaultSCI::SERVO_PINCE_D = 16;
const sc_integer IA::DefaultSCI::SERVO_PINCE_G = 17;
const sc_integer IA::DefaultSCI::SERVO_BALLE = 18;
const sc_integer IA::DefaultSCI::SERVO_RECOLTEURS = 19;
const sc_integer IA::DefaultSCI::SERVO_VOLET = 20;
const sc_integer IA::DefaultSCI::AX_ROTATION = 1;
const sc_integer IA::DefaultSCI::AX_COULEUR = 2;
const sc_integer IA::DefaultSCI::AX_LEVIER = 4;
const sc_integer IA::DefaultSCI::KMAR_SORTI = 180;
const sc_integer IA::DefaultSCI::KMAR_RENTRE = 0;
const sc_integer IA::DefaultSCI::KMAR_PRENDRE = 255;
const sc_integer IA::DefaultSCI::VENTOUSE_G = 0;
const sc_integer IA::DefaultSCI::VENTOUSE_D = 255;
const sc_integer IA::DefaultSCI::KMAR_DROIT = 0;
const sc_integer IA::DefaultSCI::MOTEUR_ROUE_GAUCHE = 1;
const sc_integer IA::DefaultSCI::MOTEUR_ROUE_DROITE = 2;
const sc_integer IA::DefaultSCI::MOTEUR_FUNNY = 3;
const sc_integer IA::DefaultSCI::MOTEUR_MOELDAR = 5;
const sc_integer IA::DefaultSCI::CODEUR_NON_DEFINI = 0;
const sc_integer IA::DefaultSCI::CODEUR_CHARIOT = 1;
const sc_integer IA::DefaultSCI::CODEUR_ROUE_DROITE = 2;
const sc_integer IA::DefaultSCI::CODEUR_ROUE_GAUCHE = 3;


void IA::init()
{
	for (int i = 0; i < maxOrthogonalStates; ++i)
		stateConfVector[i] = IA_last_state;
	
	for (int i = 0; i < maxHistoryStates; ++i)
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
	iface.countTimeMvt = 0;
	iface.tempsMatch = 0;
	iface.countTempo = 0;
	iface.countTempo2 = 0;
	iface.countTime = 0;
	iface.x_pos_mem = 0;
	iface.y_pos_mem = 0;
	iface.teta_pos_mem = 0;
	iface.nb_Modules = 1;
	iface.JAUNE = 1;
	iface.BLEU = 0;
	ifaceInternalSCI.Couleur = 1;
	ifaceInternalSCI.invMouv = 1;
	ifaceInternalSCI.Te = 0.02;
	ifaceInternalSCI.PI = 3.14;
	ifaceInternalSCI.inhibeObstacle = false;
	ifaceInternalSCI.evitementEnCours = false;
	ifaceInternalSCI.evitementTempo = 0;
	ifaceInternalSCI.sequence1 = false;
	ifaceInternalSCI.sequence2 = false;
	ifaceInternalSCI.pos_fusee = -800;
	ifaceInternalSCI.nb_tentatives = 0;
	ifaceAx.BRAS_OUVERT = 55;
	ifaceChariot.isReady = false;
	ifaceChariot.isConv = false;
}

void IA::enter()
{
	/* Default enter sequence for statechart IA */
	/* 'default' enter sequence for region STRATEGIE */
	/* Default react sequence for initial entry  */
	/* 'default' enter sequence for state TEMPS_INIT */
	/* Entry action for state 'TEMPS_INIT'. */
	iface.countTime = 0;
	stateConfVector[0] = STRATEGIE_TEMPS_INIT;
	stateConfVectorPosition = 0;
}

void IA::exit()
{
	/* Default exit sequence for statechart IA */
	/* Default exit sequence for region STRATEGIE */
	/* Handle exit of all possible states (of IA.STRATEGIE) at position 0... */
	switch(stateConfVector[ 0 ])
	{
		case STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1 :
		{
			/* Default exit sequence for state EQUIPE_1 */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2 :
		{
			/* Default exit sequence for state EQUIPE_2 */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
		{
			/* Default exit sequence for state DEPOSE_MODULE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
		{
			/* Default exit sequence for state LARGAGE_MODULES */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'LARGAGE_MODULES'. */
			ifaceInternalSCI.inhibeObstacle = true;
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
			SCI_Chariot_OCB::setPos(30);
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
		{
			/* Default exit sequence for final state. */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
		{
			/* Default exit sequence for state POSITION_INIT */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
		{
			/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
		{
			/* Default exit sequence for state PRISE_MODULE_01 */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
		{
			/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
			ifaceInternalSCI.sequence1 = false;
			ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
			ifaceInternalSCI.Couleur = iface.BLEU;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
		{
			/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
			ifaceInternalSCI.sequence1 = false;
			ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
			ifaceInternalSCI.Couleur = iface.JAUNE;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
		{
			/* Default exit sequence for state ARRET_ROBOT */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
		{
			/* Default exit sequence for state SORTIE_EVITEMENT */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
		{
			/* Default exit sequence for final state. */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
		{
			/* Default exit sequence for state INIT_MATCH */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'INIT_MATCH'. */
			ifaceInternalSCI.sequence1 = true;
			SCI_Asser_OCB::setSportivite(1);
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
		{
			/* Default exit sequence for state INIT_KMAR */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
		{
			/* Default exit sequence for state FACE_FUSEE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
		{
			/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
		{
			/* Default exit sequence for state ATTENTE_VENTOUSAGE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
		{
			/* Default exit sequence for state RETIRE_MODULE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
		{
			/* Default exit sequence for state DEGAGE_MODULE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
		{
			/* Default exit sequence for state PROCHE_BORDURE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
		{
			/* Default exit sequence for state RALENTI_ROTATION */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
		{
			/* Default exit sequence for state SOULEVE_MODULE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
		{
			/* Default exit sequence for state CHOISI_COULEUR */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
		{
			/* Default exit sequence for state INIT_COULEUR */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
		{
			/* Default exit sequence for state RALENTI_AX_COULEUR */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
		{
			/* Default exit sequence for state TOURNE_POUR_FUSEE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
		{
			/* Default exit sequence for state PROCHE_ZONE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
		{
			/* Default exit sequence for state AU_DESSUS_ZONE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
		{
			/* Default exit sequence for state DEVENTOUSAGE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
		{
			/* Default exit sequence for state ACCELERE_AX_ROTATION */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
		{
			/* Default exit sequence for state ACCELERE_AX_LEVIER */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
		{
			/* Default exit sequence for state INIT_AX_LEVIER */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
		{
			/* Default exit sequence for final state. */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
		{
			/* Default exit sequence for state MAX_HORS_ZONE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'MAX_HORS_ZONE'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
		{
			/* Default exit sequence for state DECALE_MODULES */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
		{
			/* Default exit sequence for state INIT_CHARIOT_COTE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
		{
			/* Default exit sequence for state RECENTRAGE_BRAS */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
		{
			/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
		{
			/* Default exit sequence for state RANGE_BRAS_02 */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
		{
			/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
		{
			/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
		{
			/* Default exit sequence for state CHERCHE_FUSEE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
		{
			/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
		{
			/* Default exit sequence for state VENTOUSAGE_CERTAIN */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
		{
			/* Default exit sequence for state RANGE_BRAS_01 */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
		{
			/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
		{
			/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS :
		{
			/* Default exit sequence for state ARRET_ACTIONNEURS */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_FIN_FUNNY :
		{
			/* Default exit sequence for state FIN_FUNNY */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_FIN_MATCH_FIN_MATCH_REGION__final_ :
		{
			/* Default exit sequence for final state. */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR :
		{
			/* Default exit sequence for state ARRET_MOELDAR */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_TEMPS_INIT :
		{
			/* Default exit sequence for state TEMPS_INIT */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		default: break;
	}
	/* Handle exit of all possible states (of IA.STRATEGIE) at position 1... */
	switch(stateConfVector[ 1 ])
	{
		case STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_U065064 :
		{
			/* Default exit sequence for state U065064 */
			stateConfVector[1] = IA_last_state;
			stateConfVectorPosition = 1;
			break;
		}
		case STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_Copy_1_POSITION_ASCENSEUR_INIT :
		{
			/* Default exit sequence for state Copy_1_POSITION_ASCENSEUR_INIT */
			stateConfVector[1] = IA_last_state;
			stateConfVectorPosition = 1;
			break;
		}
		case STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_Copy_1_INIT :
		{
			/* Default exit sequence for state Copy_1_INIT */
			stateConfVector[1] = IA_last_state;
			stateConfVectorPosition = 1;
			break;
		}
		default: break;
	}
	/* Handle exit of all possible states (of IA.STRATEGIE) at position 2... */
	switch(stateConfVector[ 2 ])
	{
		case STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_INIT :
		{
			/* Default exit sequence for state INIT */
			stateConfVector[2] = IA_last_state;
			stateConfVectorPosition = 2;
			break;
		}
		case STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_01 :
		{
			/* Default exit sequence for state CHENILLARD_01 */
			stateConfVector[2] = IA_last_state;
			stateConfVectorPosition = 2;
			break;
		}
		case STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_02 :
		{
			/* Default exit sequence for state CHENILLARD_02 */
			stateConfVector[2] = IA_last_state;
			stateConfVectorPosition = 2;
			break;
		}
		default: break;
	}
}

sc_boolean IA::isActive()
{
	return stateConfVector[0] != IA_last_state||stateConfVector[1] != IA_last_state||stateConfVector[2] != IA_last_state;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean IA::isFinal()
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
		case STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1 :
		{
			react_STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1();
			break;
		}
		case STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2 :
		{
			react_STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2();
			break;
		}
		case STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_U065064 :
		{
			react_STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_U065064();
			break;
		}
		case STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_Copy_1_POSITION_ASCENSEUR_INIT :
		{
			react_STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_Copy_1_POSITION_ASCENSEUR_INIT();
			break;
		}
		case STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_Copy_1_INIT :
		{
			react_STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_Copy_1_INIT();
			break;
		}
		case STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_INIT :
		{
			react_STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_INIT();
			break;
		}
		case STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_01 :
		{
			react_STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_01();
			break;
		}
		case STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_02 :
		{
			react_STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_02();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
		{
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE();
			break;
		}
		case STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS :
		{
			react_STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS();
			break;
		}
		case STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_FIN_FUNNY :
		{
			react_STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_FIN_FUNNY();
			break;
		}
		case STRATEGIE_FIN_MATCH_FIN_MATCH_REGION__final_ :
		{
			react_STRATEGIE_FIN_MATCH_FIN_MATCH_REGION__final_();
			break;
		}
		case STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR :
		{
			react_STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR();
			break;
		}
		case STRATEGIE_TEMPS_INIT :
		{
			react_STRATEGIE_TEMPS_INIT();
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
}

void IA::clearOutEvents()
{
}


sc_boolean IA::isStateActive(IAStates state)
{
	switch (state)
	{
		case STRATEGIE_ATTENTE_DEBUT_MATCH : 
			return (sc_boolean) (stateConfVector[0] >= STRATEGIE_ATTENTE_DEBUT_MATCH
				&& stateConfVector[0] <= STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_02);
		case STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1 : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1
			);
		case STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2 : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2
			);
		case STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_U065064 : 
			return (sc_boolean) (stateConfVector[1] == STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_U065064
			);
		case STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_Copy_1_POSITION_ASCENSEUR_INIT : 
			return (sc_boolean) (stateConfVector[1] == STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_Copy_1_POSITION_ASCENSEUR_INIT
			);
		case STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_Copy_1_INIT : 
			return (sc_boolean) (stateConfVector[1] == STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_Copy_1_INIT
			);
		case STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_INIT : 
			return (sc_boolean) (stateConfVector[2] == STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_INIT
			);
		case STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_01 : 
			return (sc_boolean) (stateConfVector[2] == STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_01
			);
		case STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_02 : 
			return (sc_boolean) (stateConfVector[2] == STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_02
			);
		case STRATEGIE_MATCH : 
			return (sc_boolean) (stateConfVector[0] >= STRATEGIE_MATCH
				&& stateConfVector[0] <= STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE : 
			return (sc_boolean) (stateConfVector[0] >= STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE
				&& stateConfVector[0] <= STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU
			);
		case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT : 
			return (sc_boolean) (stateConfVector[0] >= STRATEGIE_MATCH_MATCH_REGION_EVITEMENT
				&& stateConfVector[0] <= STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_);
		case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT
			);
		case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT
			);
		case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_
			);
		case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE : 
			return (sc_boolean) (stateConfVector[0] >= STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE
				&& stateConfVector[0] <= STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE
			);
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE
			);
		case STRATEGIE_FIN_MATCH : 
			return (sc_boolean) (stateConfVector[0] >= STRATEGIE_FIN_MATCH
				&& stateConfVector[0] <= STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR);
		case STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS
			);
		case STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_FIN_FUNNY : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_FIN_FUNNY
			);
		case STRATEGIE_FIN_MATCH_FIN_MATCH_REGION__final_ : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_FIN_MATCH_FIN_MATCH_REGION__final_
			);
		case STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR
			);
		case STRATEGIE_TEMPS_INIT : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_TEMPS_INIT
			);
		default: return false;
	}
}

IA::DefaultSCI* IA::getDefaultSCI()
{
	return &iface;
}

void IA::DefaultSCI::raise_eV_Tirette()
{
	EV_Tirette_raised = true;
}

void IA::raise_eV_Tirette()
{
	iface.raise_eV_Tirette();
}

void IA::DefaultSCI::raise_eV_Obstacle()
{
	EV_Obstacle_raised = true;
}

void IA::raise_eV_Obstacle()
{
	iface.raise_eV_Obstacle();
}

void IA::DefaultSCI::raise_eV_ConvergenceMvt()
{
	EV_ConvergenceMvt_raised = true;
}

void IA::raise_eV_ConvergenceMvt()
{
	iface.raise_eV_ConvergenceMvt();
}

void IA::DefaultSCI::raise_eV_ConvergenceMvt_Rapide()
{
	EV_ConvergenceMvt_Rapide_raised = true;
}

void IA::raise_eV_ConvergenceMvt_Rapide()
{
	iface.raise_eV_ConvergenceMvt_Rapide();
}

void IA::DefaultSCI::raise_eV_ConvergenceChariot()
{
	EV_ConvergenceChariot_raised = true;
}

void IA::raise_eV_ConvergenceChariot()
{
	iface.raise_eV_ConvergenceChariot();
}


sc_real IA::DefaultSCI::get_iN_x_pos()
{
	return IN_x_pos;
}

sc_real IA::get_iN_x_pos()
{
	return iface.IN_x_pos;
}

void IA::DefaultSCI::set_iN_x_pos(sc_real value)
{
	IN_x_pos = value;
}

void IA::set_iN_x_pos(sc_real value)
{
	iface.IN_x_pos = value;
}

sc_real IA::DefaultSCI::get_iN_y_pos()
{
	return IN_y_pos;
}

sc_real IA::get_iN_y_pos()
{
	return iface.IN_y_pos;
}

void IA::DefaultSCI::set_iN_y_pos(sc_real value)
{
	IN_y_pos = value;
}

void IA::set_iN_y_pos(sc_real value)
{
	iface.IN_y_pos = value;
}

sc_real IA::DefaultSCI::get_iN_teta_pos()
{
	return IN_teta_pos;
}

sc_real IA::get_iN_teta_pos()
{
	return iface.IN_teta_pos;
}

void IA::DefaultSCI::set_iN_teta_pos(sc_real value)
{
	IN_teta_pos = value;
}

void IA::set_iN_teta_pos(sc_real value)
{
	iface.IN_teta_pos = value;
}

sc_real IA::DefaultSCI::get_iN_vitesse()
{
	return IN_vitesse;
}

sc_real IA::get_iN_vitesse()
{
	return iface.IN_vitesse;
}

void IA::DefaultSCI::set_iN_vitesse(sc_real value)
{
	IN_vitesse = value;
}

void IA::set_iN_vitesse(sc_real value)
{
	iface.IN_vitesse = value;
}

sc_real IA::DefaultSCI::get_iN_sens_deplacement()
{
	return IN_sens_deplacement;
}

sc_real IA::get_iN_sens_deplacement()
{
	return iface.IN_sens_deplacement;
}

void IA::DefaultSCI::set_iN_sens_deplacement(sc_real value)
{
	IN_sens_deplacement = value;
}

void IA::set_iN_sens_deplacement(sc_real value)
{
	iface.IN_sens_deplacement = value;
}

sc_integer IA::DefaultSCI::get_iN_Couleur()
{
	return IN_Couleur;
}

sc_integer IA::get_iN_Couleur()
{
	return iface.IN_Couleur;
}

void IA::DefaultSCI::set_iN_Couleur(sc_integer value)
{
	IN_Couleur = value;
}

void IA::set_iN_Couleur(sc_integer value)
{
	iface.IN_Couleur = value;
}

sc_integer IA::DefaultSCI::get_iN_Obstacle()
{
	return IN_Obstacle;
}

sc_integer IA::get_iN_Obstacle()
{
	return iface.IN_Obstacle;
}

void IA::DefaultSCI::set_iN_Obstacle(sc_integer value)
{
	IN_Obstacle = value;
}

void IA::set_iN_Obstacle(sc_integer value)
{
	iface.IN_Obstacle = value;
}

sc_boolean IA::DefaultSCI::get_iN_Depression()
{
	return IN_Depression;
}

sc_boolean IA::get_iN_Depression()
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

sc_real IA::DefaultSCI::get_countTimeMvt()
{
	return countTimeMvt;
}

sc_real IA::get_countTimeMvt()
{
	return iface.countTimeMvt;
}

void IA::DefaultSCI::set_countTimeMvt(sc_real value)
{
	countTimeMvt = value;
}

void IA::set_countTimeMvt(sc_real value)
{
	iface.countTimeMvt = value;
}

sc_integer IA::DefaultSCI::get_tempsMatch()
{
	return tempsMatch;
}

sc_integer IA::get_tempsMatch()
{
	return iface.tempsMatch;
}

void IA::DefaultSCI::set_tempsMatch(sc_integer value)
{
	tempsMatch = value;
}

void IA::set_tempsMatch(sc_integer value)
{
	iface.tempsMatch = value;
}

sc_integer IA::DefaultSCI::get_countTempo()
{
	return countTempo;
}

sc_integer IA::get_countTempo()
{
	return iface.countTempo;
}

void IA::DefaultSCI::set_countTempo(sc_integer value)
{
	countTempo = value;
}

void IA::set_countTempo(sc_integer value)
{
	iface.countTempo = value;
}

sc_integer IA::DefaultSCI::get_countTempo2()
{
	return countTempo2;
}

sc_integer IA::get_countTempo2()
{
	return iface.countTempo2;
}

void IA::DefaultSCI::set_countTempo2(sc_integer value)
{
	countTempo2 = value;
}

void IA::set_countTempo2(sc_integer value)
{
	iface.countTempo2 = value;
}

sc_real IA::DefaultSCI::get_countTime()
{
	return countTime;
}

sc_real IA::get_countTime()
{
	return iface.countTime;
}

void IA::DefaultSCI::set_countTime(sc_real value)
{
	countTime = value;
}

void IA::set_countTime(sc_real value)
{
	iface.countTime = value;
}

sc_real IA::DefaultSCI::get_x_pos_mem()
{
	return x_pos_mem;
}

sc_real IA::get_x_pos_mem()
{
	return iface.x_pos_mem;
}

void IA::DefaultSCI::set_x_pos_mem(sc_real value)
{
	x_pos_mem = value;
}

void IA::set_x_pos_mem(sc_real value)
{
	iface.x_pos_mem = value;
}

sc_real IA::DefaultSCI::get_y_pos_mem()
{
	return y_pos_mem;
}

sc_real IA::get_y_pos_mem()
{
	return iface.y_pos_mem;
}

void IA::DefaultSCI::set_y_pos_mem(sc_real value)
{
	y_pos_mem = value;
}

void IA::set_y_pos_mem(sc_real value)
{
	iface.y_pos_mem = value;
}

sc_real IA::DefaultSCI::get_teta_pos_mem()
{
	return teta_pos_mem;
}

sc_real IA::get_teta_pos_mem()
{
	return iface.teta_pos_mem;
}

void IA::DefaultSCI::set_teta_pos_mem(sc_real value)
{
	teta_pos_mem = value;
}

void IA::set_teta_pos_mem(sc_real value)
{
	iface.teta_pos_mem = value;
}

sc_integer IA::DefaultSCI::get_nb_Modules()
{
	return nb_Modules;
}

sc_integer IA::get_nb_Modules()
{
	return iface.nb_Modules;
}

void IA::DefaultSCI::set_nb_Modules(sc_integer value)
{
	nb_Modules = value;
}

void IA::set_nb_Modules(sc_integer value)
{
	iface.nb_Modules = value;
}

const sc_integer IA::DefaultSCI::get_sERVO_VENTOUSE()
{
	return SERVO_VENTOUSE;
}

const sc_integer IA::get_sERVO_VENTOUSE()
{
	return IA::DefaultSCI::SERVO_VENTOUSE;
}

const sc_integer IA::DefaultSCI::get_sERVO_CENTREUR_G()
{
	return SERVO_CENTREUR_G;
}

const sc_integer IA::get_sERVO_CENTREUR_G()
{
	return IA::DefaultSCI::SERVO_CENTREUR_G;
}

const sc_integer IA::DefaultSCI::get_sERVO_CENTREUR_D()
{
	return SERVO_CENTREUR_D;
}

const sc_integer IA::get_sERVO_CENTREUR_D()
{
	return IA::DefaultSCI::SERVO_CENTREUR_D;
}

const sc_integer IA::DefaultSCI::get_sERVO_PINCE_D()
{
	return SERVO_PINCE_D;
}

const sc_integer IA::get_sERVO_PINCE_D()
{
	return IA::DefaultSCI::SERVO_PINCE_D;
}

const sc_integer IA::DefaultSCI::get_sERVO_PINCE_G()
{
	return SERVO_PINCE_G;
}

const sc_integer IA::get_sERVO_PINCE_G()
{
	return IA::DefaultSCI::SERVO_PINCE_G;
}

const sc_integer IA::DefaultSCI::get_sERVO_BALLE()
{
	return SERVO_BALLE;
}

const sc_integer IA::get_sERVO_BALLE()
{
	return IA::DefaultSCI::SERVO_BALLE;
}

const sc_integer IA::DefaultSCI::get_sERVO_RECOLTEURS()
{
	return SERVO_RECOLTEURS;
}

const sc_integer IA::get_sERVO_RECOLTEURS()
{
	return IA::DefaultSCI::SERVO_RECOLTEURS;
}

const sc_integer IA::DefaultSCI::get_sERVO_VOLET()
{
	return SERVO_VOLET;
}

const sc_integer IA::get_sERVO_VOLET()
{
	return IA::DefaultSCI::SERVO_VOLET;
}

const sc_integer IA::DefaultSCI::get_aX_ROTATION()
{
	return AX_ROTATION;
}

const sc_integer IA::get_aX_ROTATION()
{
	return IA::DefaultSCI::AX_ROTATION;
}

const sc_integer IA::DefaultSCI::get_aX_COULEUR()
{
	return AX_COULEUR;
}

const sc_integer IA::get_aX_COULEUR()
{
	return IA::DefaultSCI::AX_COULEUR;
}

const sc_integer IA::DefaultSCI::get_aX_LEVIER()
{
	return AX_LEVIER;
}

const sc_integer IA::get_aX_LEVIER()
{
	return IA::DefaultSCI::AX_LEVIER;
}

const sc_integer IA::DefaultSCI::get_kMAR_SORTI()
{
	return KMAR_SORTI;
}

const sc_integer IA::get_kMAR_SORTI()
{
	return IA::DefaultSCI::KMAR_SORTI;
}

const sc_integer IA::DefaultSCI::get_kMAR_RENTRE()
{
	return KMAR_RENTRE;
}

const sc_integer IA::get_kMAR_RENTRE()
{
	return IA::DefaultSCI::KMAR_RENTRE;
}

const sc_integer IA::DefaultSCI::get_kMAR_PRENDRE()
{
	return KMAR_PRENDRE;
}

const sc_integer IA::get_kMAR_PRENDRE()
{
	return IA::DefaultSCI::KMAR_PRENDRE;
}

const sc_integer IA::DefaultSCI::get_vENTOUSE_G()
{
	return VENTOUSE_G;
}

const sc_integer IA::get_vENTOUSE_G()
{
	return IA::DefaultSCI::VENTOUSE_G;
}

const sc_integer IA::DefaultSCI::get_vENTOUSE_D()
{
	return VENTOUSE_D;
}

const sc_integer IA::get_vENTOUSE_D()
{
	return IA::DefaultSCI::VENTOUSE_D;
}

const sc_integer IA::DefaultSCI::get_kMAR_DROIT()
{
	return KMAR_DROIT;
}

const sc_integer IA::get_kMAR_DROIT()
{
	return IA::DefaultSCI::KMAR_DROIT;
}

const sc_integer IA::DefaultSCI::get_mOTEUR_ROUE_GAUCHE()
{
	return MOTEUR_ROUE_GAUCHE;
}

const sc_integer IA::get_mOTEUR_ROUE_GAUCHE()
{
	return IA::DefaultSCI::MOTEUR_ROUE_GAUCHE;
}

const sc_integer IA::DefaultSCI::get_mOTEUR_ROUE_DROITE()
{
	return MOTEUR_ROUE_DROITE;
}

const sc_integer IA::get_mOTEUR_ROUE_DROITE()
{
	return IA::DefaultSCI::MOTEUR_ROUE_DROITE;
}

const sc_integer IA::DefaultSCI::get_mOTEUR_FUNNY()
{
	return MOTEUR_FUNNY;
}

const sc_integer IA::get_mOTEUR_FUNNY()
{
	return IA::DefaultSCI::MOTEUR_FUNNY;
}

const sc_integer IA::DefaultSCI::get_mOTEUR_MOELDAR()
{
	return MOTEUR_MOELDAR;
}

const sc_integer IA::get_mOTEUR_MOELDAR()
{
	return IA::DefaultSCI::MOTEUR_MOELDAR;
}

const sc_integer IA::DefaultSCI::get_cODEUR_NON_DEFINI()
{
	return CODEUR_NON_DEFINI;
}

const sc_integer IA::get_cODEUR_NON_DEFINI()
{
	return IA::DefaultSCI::CODEUR_NON_DEFINI;
}

const sc_integer IA::DefaultSCI::get_cODEUR_CHARIOT()
{
	return CODEUR_CHARIOT;
}

const sc_integer IA::get_cODEUR_CHARIOT()
{
	return IA::DefaultSCI::CODEUR_CHARIOT;
}

const sc_integer IA::DefaultSCI::get_cODEUR_ROUE_DROITE()
{
	return CODEUR_ROUE_DROITE;
}

const sc_integer IA::get_cODEUR_ROUE_DROITE()
{
	return IA::DefaultSCI::CODEUR_ROUE_DROITE;
}

const sc_integer IA::DefaultSCI::get_cODEUR_ROUE_GAUCHE()
{
	return CODEUR_ROUE_GAUCHE;
}

const sc_integer IA::get_cODEUR_ROUE_GAUCHE()
{
	return IA::DefaultSCI::CODEUR_ROUE_GAUCHE;
}

sc_integer IA::DefaultSCI::get_jAUNE()
{
	return JAUNE;
}

sc_integer IA::get_jAUNE()
{
	return iface.JAUNE;
}

sc_integer IA::DefaultSCI::get_bLEU()
{
	return BLEU;
}

sc_integer IA::get_bLEU()
{
	return iface.BLEU;
}


sc_integer IA::InternalSCI::get_couleur()
{
	return Couleur;
}

void IA::InternalSCI::set_couleur(sc_integer value)
{
	Couleur = value;
}

sc_integer IA::InternalSCI::get_invMouv()
{
	return invMouv;
}

void IA::InternalSCI::set_invMouv(sc_integer value)
{
	invMouv = value;
}

sc_real IA::InternalSCI::get_te()
{
	return Te;
}

void IA::InternalSCI::set_te(sc_real value)
{
	Te = value;
}

sc_real IA::InternalSCI::get_pI()
{
	return PI;
}

sc_boolean IA::InternalSCI::get_inhibeObstacle()
{
	return inhibeObstacle;
}

void IA::InternalSCI::set_inhibeObstacle(sc_boolean value)
{
	inhibeObstacle = value;
}

sc_boolean IA::InternalSCI::get_evitementEnCours()
{
	return evitementEnCours;
}

void IA::InternalSCI::set_evitementEnCours(sc_boolean value)
{
	evitementEnCours = value;
}

sc_real IA::InternalSCI::get_evitementTempo()
{
	return evitementTempo;
}

void IA::InternalSCI::set_evitementTempo(sc_real value)
{
	evitementTempo = value;
}

sc_boolean IA::InternalSCI::get_sequence1()
{
	return sequence1;
}

void IA::InternalSCI::set_sequence1(sc_boolean value)
{
	sequence1 = value;
}

sc_boolean IA::InternalSCI::get_sequence2()
{
	return sequence2;
}

void IA::InternalSCI::set_sequence2(sc_boolean value)
{
	sequence2 = value;
}

sc_integer IA::InternalSCI::get_pos_fusee()
{
	return pos_fusee;
}

void IA::InternalSCI::set_pos_fusee(sc_integer value)
{
	pos_fusee = value;
}

sc_integer IA::InternalSCI::get_nb_tentatives()
{
	return nb_tentatives;
}

void IA::InternalSCI::set_nb_tentatives(sc_integer value)
{
	nb_tentatives = value;
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


sc_integer IA::SCI_Ax::get_bRAS_OUVERT()
{
	return BRAS_OUVERT;
}

IA::SCI_Moteur* IA::getSCI_Moteur()
{
	return &ifaceMoteur;
}


IA::SCI_Chariot* IA::getSCI_Chariot()
{
	return &ifaceChariot;
}


sc_boolean IA::SCI_Chariot::get_isReady()
{
	return isReady;
}

void IA::SCI_Chariot::set_isReady(sc_boolean value)
{
	isReady = value;
}

sc_boolean IA::SCI_Chariot::get_isConv()
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

/* shallow enterSequence with history in child HOMOLOGATION_REGION */
void IA::shenseq_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION()
{
	/* shallow enterSequence with history in child HOMOLOGATION_REGION */
	/* Handle shallow history entry of HOMOLOGATION_REGION */
	switch(historyVector[ 0 ])
	{
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
		{
			/* 'default' enter sequence for state DEPOSE_MODULE */
			/* Entry action for state 'DEPOSE_MODULE'. */
			SCI_Asser_OCB::XY(138, -145 * ifaceInternalSCI.invMouv);
			iface.countTimeMvt = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE;
			stateConfVectorPosition = 0;
			historyVector[0] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
		{
			/* 'default' enter sequence for state LARGAGE_MODULES */
			/* Entry action for state 'LARGAGE_MODULES'. */
			SCI_Asser_OCB::XYTeta(105, -170 * ifaceInternalSCI.invMouv, (-ifaceInternalSCI.PI / 2) * ifaceInternalSCI.invMouv);
			iface.countTimeMvt = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES;
			stateConfVectorPosition = 0;
			historyVector[0] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
		{
			/* 'default' enter sequence for state POSITION_INIT */
			/* Entry action for state 'POSITION_INIT'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_ROTATION, 0);
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 750);
			SCI_Chariot_OCB::setPos(-800);
			SCI_Asser_OCB::XY(10, 0);
			iface.countTimeMvt = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT;
			stateConfVectorPosition = 0;
			historyVector[0] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
		{
			/* 'default' enter sequence for state DIRECTION_ZONE_ADVERSE */
			/* Entry action for state 'DIRECTION_ZONE_ADVERSE'. */
			SCI_Asser_OCB::XY(98, -100 * ifaceInternalSCI.invMouv);
			iface.countTimeMvt = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE;
			stateConfVectorPosition = 0;
			historyVector[0] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
		{
			/* 'default' enter sequence for state PRISE_MODULE_01 */
			/* Entry action for state 'PRISE_MODULE_01'. */
			SCI_Asser_OCB::XYTeta(98, -155 * ifaceInternalSCI.invMouv, 0);
			iface.countTimeMvt = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01;
			stateConfVectorPosition = 0;
			historyVector[0] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
		{
			/* 'default' enter sequence for state FIN_DEPLACEMENT_JAUNE */
			/* Entry action for state 'FIN_DEPLACEMENT_JAUNE'. */
			SCI_Asser_OCB::XYTeta(105, -182.5 * ifaceInternalSCI.invMouv, (-ifaceInternalSCI.PI / 2) * ifaceInternalSCI.invMouv);
			iface.countTimeMvt = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE;
			stateConfVectorPosition = 0;
			historyVector[0] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
		{
			/* 'default' enter sequence for state FIN_DEPLACEMENT_BLEU */
			/* Entry action for state 'FIN_DEPLACEMENT_BLEU'. */
			SCI_Asser_OCB::XYTeta(105, -183.5 * ifaceInternalSCI.invMouv, (-ifaceInternalSCI.PI / 2) * ifaceInternalSCI.invMouv);
			iface.countTimeMvt = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU;
			stateConfVectorPosition = 0;
			historyVector[0] = stateConfVector[0];
			break;
		}
		default: break;
	}
}

/* shallow enterSequence with history in child SEQUENCE_MODULES_FUSEE */
void IA::shenseq_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE()
{
	/* shallow enterSequence with history in child SEQUENCE_MODULES_FUSEE */
	/* Handle shallow history entry of SEQUENCE_MODULES_FUSEE */
	switch(historyVector[ 1 ])
	{
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
		{
			/* 'default' enter sequence for state INIT_KMAR */
			/* Entry action for state 'INIT_KMAR'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
		{
			/* 'default' enter sequence for state FACE_FUSEE */
			/* Entry action for state 'FACE_FUSEE'. */
			SCI_Chariot_OCB::setPos(ifaceInternalSCI.pos_fusee);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
		{
			/* 'default' enter sequence for state VENTOUSAGE_INCERTAIN */
			/* Entry action for state 'VENTOUSAGE_INCERTAIN'. */
			SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 100);
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 580);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
		{
			/* 'default' enter sequence for state ATTENTE_VENTOUSAGE */
			/* Entry action for state 'ATTENTE_VENTOUSAGE'. */
			SCI_Ax_OCB::setSpd(IA::DefaultSCI::AX_LEVIER, 100);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
		{
			/* 'default' enter sequence for state RETIRE_MODULE */
			/* Entry action for state 'RETIRE_MODULE'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 435);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
		{
			/* 'default' enter sequence for state DEGAGE_MODULE */
			/* Entry action for state 'DEGAGE_MODULE'. */
			SCI_Chariot_OCB::setPos(ifaceInternalSCI.invMouv * 300 + ifaceInternalSCI.invMouv * 35 * ifaceInternalSCI.nb_tentatives);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
		{
			/* 'default' enter sequence for state PROCHE_BORDURE */
			/* Entry action for state 'PROCHE_BORDURE'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
		{
			/* 'default' enter sequence for state RALENTI_ROTATION */
			/* Entry action for state 'RALENTI_ROTATION'. */
			SCI_Ax_OCB::setSpd(IA::DefaultSCI::AX_ROTATION, 100);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
		{
			/* 'default' enter sequence for state SOULEVE_MODULE */
			/* Entry action for state 'SOULEVE_MODULE'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_ROTATION, 500);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
		{
			/* 'default' enter sequence for state CHOISI_COULEUR */
			/* Entry action for state 'CHOISI_COULEUR'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_COULEUR, 800);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
		{
			/* 'default' enter sequence for state INIT_COULEUR */
			/* Entry action for state 'INIT_COULEUR'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_COULEUR, 510);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
		{
			/* 'default' enter sequence for state RALENTI_AX_COULEUR */
			/* Entry action for state 'RALENTI_AX_COULEUR'. */
			SCI_Ax_OCB::setSpd(IA::DefaultSCI::AX_COULEUR, 100);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
		{
			/* 'default' enter sequence for state TOURNE_POUR_FUSEE */
			/* Entry action for state 'TOURNE_POUR_FUSEE'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_ROTATION, 800);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
		{
			/* 'default' enter sequence for state PROCHE_ZONE */
			/* Entry action for state 'PROCHE_ZONE'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 550);
			SCI_Chariot_OCB::setPos(-150 * ifaceInternalSCI.invMouv + ifaceInternalSCI.invMouv * 45 * ifaceInternalSCI.nb_tentatives);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
		{
			/* 'default' enter sequence for state AU_DESSUS_ZONE */
			/* Entry action for state 'AU_DESSUS_ZONE'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_ROTATION, 200);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
		{
			/* 'default' enter sequence for state DEVENTOUSAGE */
			/* Entry action for state 'DEVENTOUSAGE'. */
			SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
		{
			/* 'default' enter sequence for state ACCELERE_AX_ROTATION */
			/* Entry action for state 'ACCELERE_AX_ROTATION'. */
			SCI_Ax_OCB::setSpd(IA::DefaultSCI::AX_ROTATION, 0);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
		{
			/* 'default' enter sequence for state ACCELERE_AX_LEVIER */
			/* Entry action for state 'ACCELERE_AX_LEVIER'. */
			SCI_Ax_OCB::setSpd(IA::DefaultSCI::AX_LEVIER, 0);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
		{
			/* 'default' enter sequence for state INIT_AX_LEVIER */
			/* Entry action for state 'INIT_AX_LEVIER'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
		{
			/* 'default' enter sequence for state MAX_HORS_ZONE */
			/* Entry action for state 'MAX_HORS_ZONE'. */
			SCI_Chariot_OCB::setPos(-700 * ifaceInternalSCI.invMouv + ifaceInternalSCI.invMouv * 45 * ifaceInternalSCI.nb_tentatives);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
		{
			/* 'default' enter sequence for state DECALE_MODULES */
			/* Entry action for state 'DECALE_MODULES'. */
			SCI_Chariot_OCB::setPos(800 * ifaceInternalSCI.invMouv + ifaceInternalSCI.invMouv * 45 * ifaceInternalSCI.nb_tentatives);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
		{
			/* 'default' enter sequence for state INIT_CHARIOT_COTE */
			/* Entry action for state 'INIT_CHARIOT_COTE'. */
			SCI_Chariot_OCB::setPos(0);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
		{
			/* 'default' enter sequence for state RECENTRAGE_BRAS */
			/* Entry action for state 'RECENTRAGE_BRAS'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_ROTATION, 505);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
		{
			/* 'default' enter sequence for state FIN_INIT_CHARIOT_COTE */
			/* Entry action for state 'FIN_INIT_CHARIOT_COTE'. */
			SCI_Chariot_OCB::setPos(0);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
		{
			/* 'default' enter sequence for state RANGE_BRAS_02 */
			/* Entry action for state 'RANGE_BRAS_02'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 300);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
		{
			/* 'default' enter sequence for state Copy_1_CHOISI_COULEUR */
			/* Entry action for state 'Copy_1_CHOISI_COULEUR'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_COULEUR, 200);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
		{
			/* 'default' enter sequence for state LEVIER_RECULE_AU_MAX */
			/* Entry action for state 'LEVIER_RECULE_AU_MAX'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 435);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
		{
			/* 'default' enter sequence for state CHERCHE_FUSEE */
			/* Entry action for state 'CHERCHE_FUSEE'. */
			SCI_Chariot_OCB::setPos(ifaceInternalSCI.pos_fusee + ifaceInternalSCI.invMouv * 45 * ifaceInternalSCI.nb_tentatives);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
		{
			/* 'default' enter sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
			/* Entry action for state 'Copy_1_LEVIER_RECULE_AU_MAX'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 435);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
		{
			/* 'default' enter sequence for state VENTOUSAGE_CERTAIN */
			/* Entry action for state 'VENTOUSAGE_CERTAIN'. */
			SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 100);
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 580);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
		{
			/* 'default' enter sequence for state RANGE_BRAS_01 */
			/* Entry action for state 'RANGE_BRAS_01'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_ROTATION, 200);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
		{
			/* 'default' enter sequence for state Copy_1_TOURNE_POUR_FUSEE */
			/* Entry action for state 'Copy_1_TOURNE_POUR_FUSEE'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_ROTATION, 200);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
		{
			/* 'default' enter sequence for state Copy_1_AU_DESSUS_ZONE */
			/* Entry action for state 'Copy_1_AU_DESSUS_ZONE'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_ROTATION, 800);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
			break;
		}
		default: break;
	}
}

/* The reactions of state EQUIPE_1. */
void IA::react_STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1()
{
	/* The reactions of state EQUIPE_1. */
	if (iface.EV_Tirette_raised)
	{ 
		/* Default exit sequence for state ATTENTE_DEBUT_MATCH */
		/* Default exit sequence for region CHOIX_EQUIPE */
		/* Handle exit of all possible states (of IA.STRATEGIE.ATTENTE_DEBUT_MATCH.CHOIX_EQUIPE) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1 :
			{
				/* Default exit sequence for state EQUIPE_1 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2 :
			{
				/* Default exit sequence for state EQUIPE_2 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* Default exit sequence for region APPRENTISSAGE_ACTIONNEUR */
		/* Handle exit of all possible states (of IA.STRATEGIE.ATTENTE_DEBUT_MATCH.APPRENTISSAGE_ACTIONNEUR) at position 1... */
		switch(stateConfVector[ 1 ])
		{
			case STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_U065064 :
			{
				/* Default exit sequence for state U065064 */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			case STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_Copy_1_POSITION_ASCENSEUR_INIT :
			{
				/* Default exit sequence for state Copy_1_POSITION_ASCENSEUR_INIT */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			case STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_Copy_1_INIT :
			{
				/* Default exit sequence for state Copy_1_INIT */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			default: break;
		}
		/* Default exit sequence for region CHENILLARD */
		/* Handle exit of all possible states (of IA.STRATEGIE.ATTENTE_DEBUT_MATCH.CHENILLARD) at position 2... */
		switch(stateConfVector[ 2 ])
		{
			case STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_INIT :
			{
				/* Default exit sequence for state INIT */
				stateConfVector[2] = IA_last_state;
				stateConfVectorPosition = 2;
				break;
			}
			case STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_01 :
			{
				/* Default exit sequence for state CHENILLARD_01 */
				stateConfVector[2] = IA_last_state;
				stateConfVectorPosition = 2;
				break;
			}
			case STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_02 :
			{
				/* Default exit sequence for state CHENILLARD_02 */
				stateConfVector[2] = IA_last_state;
				stateConfVectorPosition = 2;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state MATCH */
		/* Entry action for state 'MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		iface.tempsMatch = 0;
		/* 'default' enter sequence for region MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state INIT_MATCH */
		/* Entry action for state 'INIT_MATCH'. */
		iface.tempsMatch = 0;
		SCI_Asser_OCB::setPosition(0, 0, 0);
		SCI_Ihm_OCB::setLed(2, false);
		SCI_Ihm_OCB::setLed(3, false);
		SCI_Ihm_OCB::setLed(4, false);
		stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		if (iface.IN_Couleur == iface.BLEU)
		{ 
			/* Default exit sequence for state EQUIPE_1 */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* 'default' enter sequence for state EQUIPE_2 */
			/* Entry action for state 'EQUIPE_2'. */
			ifaceInternalSCI.Couleur = iface.BLEU;
			SCI_Ihm_OCB::setLed(4, false);
			ifaceInternalSCI.invMouv = -1;
			stateConfVector[0] = STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2;
			stateConfVectorPosition = 0;
		} 
	}
}

/* The reactions of state EQUIPE_2. */
void IA::react_STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2()
{
	/* The reactions of state EQUIPE_2. */
	if (iface.EV_Tirette_raised)
	{ 
		/* Default exit sequence for state ATTENTE_DEBUT_MATCH */
		/* Default exit sequence for region CHOIX_EQUIPE */
		/* Handle exit of all possible states (of IA.STRATEGIE.ATTENTE_DEBUT_MATCH.CHOIX_EQUIPE) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1 :
			{
				/* Default exit sequence for state EQUIPE_1 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2 :
			{
				/* Default exit sequence for state EQUIPE_2 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* Default exit sequence for region APPRENTISSAGE_ACTIONNEUR */
		/* Handle exit of all possible states (of IA.STRATEGIE.ATTENTE_DEBUT_MATCH.APPRENTISSAGE_ACTIONNEUR) at position 1... */
		switch(stateConfVector[ 1 ])
		{
			case STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_U065064 :
			{
				/* Default exit sequence for state U065064 */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			case STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_Copy_1_POSITION_ASCENSEUR_INIT :
			{
				/* Default exit sequence for state Copy_1_POSITION_ASCENSEUR_INIT */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			case STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_Copy_1_INIT :
			{
				/* Default exit sequence for state Copy_1_INIT */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			default: break;
		}
		/* Default exit sequence for region CHENILLARD */
		/* Handle exit of all possible states (of IA.STRATEGIE.ATTENTE_DEBUT_MATCH.CHENILLARD) at position 2... */
		switch(stateConfVector[ 2 ])
		{
			case STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_INIT :
			{
				/* Default exit sequence for state INIT */
				stateConfVector[2] = IA_last_state;
				stateConfVectorPosition = 2;
				break;
			}
			case STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_01 :
			{
				/* Default exit sequence for state CHENILLARD_01 */
				stateConfVector[2] = IA_last_state;
				stateConfVectorPosition = 2;
				break;
			}
			case STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_02 :
			{
				/* Default exit sequence for state CHENILLARD_02 */
				stateConfVector[2] = IA_last_state;
				stateConfVectorPosition = 2;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state MATCH */
		/* Entry action for state 'MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		iface.tempsMatch = 0;
		/* 'default' enter sequence for region MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state INIT_MATCH */
		/* Entry action for state 'INIT_MATCH'. */
		iface.tempsMatch = 0;
		SCI_Asser_OCB::setPosition(0, 0, 0);
		SCI_Ihm_OCB::setLed(2, false);
		SCI_Ihm_OCB::setLed(3, false);
		SCI_Ihm_OCB::setLed(4, false);
		stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		if (iface.IN_Couleur == iface.JAUNE)
		{ 
			/* Default exit sequence for state EQUIPE_2 */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* 'default' enter sequence for state EQUIPE_1 */
			/* Entry action for state 'EQUIPE_1'. */
			ifaceInternalSCI.Couleur = iface.JAUNE;
			SCI_Ihm_OCB::setLed(4, true);
			ifaceInternalSCI.invMouv = 1;
			stateConfVector[0] = STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1;
			stateConfVectorPosition = 0;
		} 
	}
}

/* The reactions of state U065064. */
void IA::react_STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_U065064()
{
	/* The reactions of state U065064. */
	if (iface.countTempo2 > (1 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state U065064 */
		stateConfVector[1] = IA_last_state;
		stateConfVectorPosition = 1;
		/* 'default' enter sequence for state Copy_1_INIT */
		/* Entry action for state 'Copy_1_INIT'. */
		SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_ROTATION, 0);
		SCI_Chariot_OCB::init();
		iface.countTempo2 = 0;
		stateConfVector[1] = STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_Copy_1_INIT;
		stateConfVectorPosition = 1;
	} 
}

/* The reactions of state Copy_1_POSITION_ASCENSEUR_INIT. */
void IA::react_STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_Copy_1_POSITION_ASCENSEUR_INIT()
{
}

/* The reactions of state Copy_1_INIT. */
void IA::react_STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_Copy_1_INIT()
{
	/* The reactions of state Copy_1_INIT. */
	if (iface.EV_ConvergenceChariot_raised || (iface.countTempo2 > (12 / ifaceInternalSCI.Te)))
	{ 
		/* Default exit sequence for state Copy_1_INIT */
		stateConfVector[1] = IA_last_state;
		stateConfVectorPosition = 1;
		/* 'default' enter sequence for state Copy_1_POSITION_ASCENSEUR_INIT */
		/* Entry action for state 'Copy_1_POSITION_ASCENSEUR_INIT'. */
		SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 300);
		stateConfVector[1] = STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_Copy_1_POSITION_ASCENSEUR_INIT;
		stateConfVectorPosition = 1;
	} 
}

/* The reactions of state INIT. */
void IA::react_STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_INIT()
{
	/* The reactions of state INIT. */
	if (iface.countTempo > (1 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state INIT */
		stateConfVector[2] = IA_last_state;
		stateConfVectorPosition = 2;
		/* 'default' enter sequence for state CHENILLARD_01 */
		/* Entry action for state 'CHENILLARD_01'. */
		SCI_Ihm_OCB::setLed(2, true);
		SCI_Ihm_OCB::setLed(3, false);
		iface.countTempo = 0;
		stateConfVector[2] = STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_01;
		stateConfVectorPosition = 2;
	} 
}

/* The reactions of state CHENILLARD_01. */
void IA::react_STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_01()
{
	/* The reactions of state CHENILLARD_01. */
	if (iface.countTempo > (1 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state CHENILLARD_01 */
		stateConfVector[2] = IA_last_state;
		stateConfVectorPosition = 2;
		/* 'default' enter sequence for state CHENILLARD_02 */
		/* Entry action for state 'CHENILLARD_02'. */
		SCI_Ihm_OCB::setLed(2, false);
		SCI_Ihm_OCB::setLed(3, true);
		iface.countTempo = 0;
		stateConfVector[2] = STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_02;
		stateConfVectorPosition = 2;
	} 
}

/* The reactions of state CHENILLARD_02. */
void IA::react_STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_02()
{
	/* The reactions of state CHENILLARD_02. */
	if (iface.countTempo > (1 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state CHENILLARD_02 */
		stateConfVector[2] = IA_last_state;
		stateConfVectorPosition = 2;
		/* 'default' enter sequence for state CHENILLARD_01 */
		/* Entry action for state 'CHENILLARD_01'. */
		SCI_Ihm_OCB::setLed(2, true);
		SCI_Ihm_OCB::setLed(3, false);
		iface.countTempo = 0;
		stateConfVector[2] = STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_01;
		stateConfVectorPosition = 2;
	} 
}

/* The reactions of state DEPOSE_MODULE. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE()
{
	/* The reactions of state DEPOSE_MODULE. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if ((iface.IN_Obstacle == 1) && (ifaceInternalSCI.inhibeObstacle == false))
		{ 
			/* Default exit sequence for state MODULES_LUNAIRES_COTE */
			/* Default exit sequence for region HOMOLOGATION_REGION */
			/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION.MODULES_LUNAIRES_COTE.HOMOLOGATION_REGION) at position 0... */
			switch(stateConfVector[ 0 ])
			{
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
				{
					/* Default exit sequence for state DEPOSE_MODULE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
				{
					/* Default exit sequence for state LARGAGE_MODULES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'LARGAGE_MODULES'. */
					ifaceInternalSCI.inhibeObstacle = true;
					SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
					SCI_Chariot_OCB::setPos(30);
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
				{
					/* Default exit sequence for final state. */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
				{
					/* Default exit sequence for state POSITION_INIT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
				{
					/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
				{
					/* Default exit sequence for state PRISE_MODULE_01 */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
				{
					/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
					ifaceInternalSCI.sequence1 = false;
					ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
					ifaceInternalSCI.Couleur = iface.BLEU;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
				{
					/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
					ifaceInternalSCI.sequence1 = false;
					ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
					ifaceInternalSCI.Couleur = iface.JAUNE;
					break;
				}
				default: break;
			}
			/* 'default' enter sequence for state EVITEMENT */
			/* Entry action for state 'EVITEMENT'. */
			ifaceInternalSCI.evitementTempo = 0;
			ifaceInternalSCI.evitementEnCours = true;
			iface.IN_x_pos = iface.x_pos_mem;
			/* 'default' enter sequence for region EVITEMENT_REGION */
			/* Default react sequence for initial entry  */
			/* 'default' enter sequence for state ARRET_ROBOT */
			/* Entry action for state 'ARRET_ROBOT'. */
			SCI_Asser_OCB::Manuel(0, 0);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT;
			stateConfVectorPosition = 0;
		}  else
		{
			if (!ifaceInternalSCI.sequence1)
			{ 
				/* Default exit sequence for state MODULES_LUNAIRES_COTE */
				/* Default exit sequence for region HOMOLOGATION_REGION */
				/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION.MODULES_LUNAIRES_COTE.HOMOLOGATION_REGION) at position 0... */
				switch(stateConfVector[ 0 ])
				{
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
					{
						/* Default exit sequence for state DEPOSE_MODULE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
					{
						/* Default exit sequence for state LARGAGE_MODULES */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'LARGAGE_MODULES'. */
						ifaceInternalSCI.inhibeObstacle = true;
						SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
						SCI_Chariot_OCB::setPos(30);
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
					{
						/* Default exit sequence for final state. */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
					{
						/* Default exit sequence for state POSITION_INIT */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
					{
						/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
					{
						/* Default exit sequence for state PRISE_MODULE_01 */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
					{
						/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
						ifaceInternalSCI.sequence1 = false;
						ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
						ifaceInternalSCI.Couleur = iface.BLEU;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
					{
						/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
						ifaceInternalSCI.sequence1 = false;
						ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
						ifaceInternalSCI.Couleur = iface.JAUNE;
						break;
					}
					default: break;
				}
				ifaceInternalSCI.sequence2 = true;
				ifaceInternalSCI.pos_fusee = ifaceInternalSCI.pos_fusee * ifaceInternalSCI.invMouv;
				/* 'entry_Init' enter sequence for state MODULES_COTE_JAUNE */
				/* 'entry_Init' enter sequence for region SEQUENCE_MODULES_FUSEE */
				/* Default react sequence for initial entry entry_Init */
				/* 'default' enter sequence for state INIT_KMAR */
				/* Entry action for state 'INIT_KMAR'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR;
				stateConfVectorPosition = 0;
				historyVector[1] = stateConfVector[0];
			}  else
			{
				if (iface.EV_ConvergenceMvt_raised || iface.countTimeMvt > (3 / ifaceInternalSCI.Te))
				{ 
					/* Default exit sequence for state DEPOSE_MODULE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* 'default' enter sequence for state LARGAGE_MODULES */
					/* Entry action for state 'LARGAGE_MODULES'. */
					SCI_Asser_OCB::XYTeta(105, -170 * ifaceInternalSCI.invMouv, (-ifaceInternalSCI.PI / 2) * ifaceInternalSCI.invMouv);
					iface.countTimeMvt = 0;
					stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES;
					stateConfVectorPosition = 0;
					historyVector[0] = stateConfVector[0];
				} 
			}
		}
	}
}

/* The reactions of state LARGAGE_MODULES. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES()
{
	/* The reactions of state LARGAGE_MODULES. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if ((iface.IN_Obstacle == 1) && (ifaceInternalSCI.inhibeObstacle == false))
		{ 
			/* Default exit sequence for state MODULES_LUNAIRES_COTE */
			/* Default exit sequence for region HOMOLOGATION_REGION */
			/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION.MODULES_LUNAIRES_COTE.HOMOLOGATION_REGION) at position 0... */
			switch(stateConfVector[ 0 ])
			{
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
				{
					/* Default exit sequence for state DEPOSE_MODULE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
				{
					/* Default exit sequence for state LARGAGE_MODULES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'LARGAGE_MODULES'. */
					ifaceInternalSCI.inhibeObstacle = true;
					SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
					SCI_Chariot_OCB::setPos(30);
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
				{
					/* Default exit sequence for final state. */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
				{
					/* Default exit sequence for state POSITION_INIT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
				{
					/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
				{
					/* Default exit sequence for state PRISE_MODULE_01 */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
				{
					/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
					ifaceInternalSCI.sequence1 = false;
					ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
					ifaceInternalSCI.Couleur = iface.BLEU;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
				{
					/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
					ifaceInternalSCI.sequence1 = false;
					ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
					ifaceInternalSCI.Couleur = iface.JAUNE;
					break;
				}
				default: break;
			}
			/* 'default' enter sequence for state EVITEMENT */
			/* Entry action for state 'EVITEMENT'. */
			ifaceInternalSCI.evitementTempo = 0;
			ifaceInternalSCI.evitementEnCours = true;
			iface.IN_x_pos = iface.x_pos_mem;
			/* 'default' enter sequence for region EVITEMENT_REGION */
			/* Default react sequence for initial entry  */
			/* 'default' enter sequence for state ARRET_ROBOT */
			/* Entry action for state 'ARRET_ROBOT'. */
			SCI_Asser_OCB::Manuel(0, 0);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT;
			stateConfVectorPosition = 0;
		}  else
		{
			if (!ifaceInternalSCI.sequence1)
			{ 
				/* Default exit sequence for state MODULES_LUNAIRES_COTE */
				/* Default exit sequence for region HOMOLOGATION_REGION */
				/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION.MODULES_LUNAIRES_COTE.HOMOLOGATION_REGION) at position 0... */
				switch(stateConfVector[ 0 ])
				{
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
					{
						/* Default exit sequence for state DEPOSE_MODULE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
					{
						/* Default exit sequence for state LARGAGE_MODULES */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'LARGAGE_MODULES'. */
						ifaceInternalSCI.inhibeObstacle = true;
						SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
						SCI_Chariot_OCB::setPos(30);
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
					{
						/* Default exit sequence for final state. */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
					{
						/* Default exit sequence for state POSITION_INIT */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
					{
						/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
					{
						/* Default exit sequence for state PRISE_MODULE_01 */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
					{
						/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
						ifaceInternalSCI.sequence1 = false;
						ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
						ifaceInternalSCI.Couleur = iface.BLEU;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
					{
						/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
						ifaceInternalSCI.sequence1 = false;
						ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
						ifaceInternalSCI.Couleur = iface.JAUNE;
						break;
					}
					default: break;
				}
				ifaceInternalSCI.sequence2 = true;
				ifaceInternalSCI.pos_fusee = ifaceInternalSCI.pos_fusee * ifaceInternalSCI.invMouv;
				/* 'entry_Init' enter sequence for state MODULES_COTE_JAUNE */
				/* 'entry_Init' enter sequence for region SEQUENCE_MODULES_FUSEE */
				/* Default react sequence for initial entry entry_Init */
				/* 'default' enter sequence for state INIT_KMAR */
				/* Entry action for state 'INIT_KMAR'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR;
				stateConfVectorPosition = 0;
				historyVector[1] = stateConfVector[0];
			}  else
			{
				if (iface.EV_ConvergenceMvt_raised || iface.countTimeMvt > (3 / ifaceInternalSCI.Te))
				{ 
					/* Default exit sequence for state LARGAGE_MODULES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'LARGAGE_MODULES'. */
					ifaceInternalSCI.inhibeObstacle = true;
					SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
					SCI_Chariot_OCB::setPos(30);
					react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__choice_0();
				} 
			}
		}
	}
}

/* The reactions of state null. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_()
{
	/* The reactions of state null. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if ((iface.IN_Obstacle == 1) && (ifaceInternalSCI.inhibeObstacle == false))
		{ 
			/* Default exit sequence for state MODULES_LUNAIRES_COTE */
			/* Default exit sequence for region HOMOLOGATION_REGION */
			/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION.MODULES_LUNAIRES_COTE.HOMOLOGATION_REGION) at position 0... */
			switch(stateConfVector[ 0 ])
			{
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
				{
					/* Default exit sequence for state DEPOSE_MODULE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
				{
					/* Default exit sequence for state LARGAGE_MODULES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'LARGAGE_MODULES'. */
					ifaceInternalSCI.inhibeObstacle = true;
					SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
					SCI_Chariot_OCB::setPos(30);
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
				{
					/* Default exit sequence for final state. */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
				{
					/* Default exit sequence for state POSITION_INIT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
				{
					/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
				{
					/* Default exit sequence for state PRISE_MODULE_01 */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
				{
					/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
					ifaceInternalSCI.sequence1 = false;
					ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
					ifaceInternalSCI.Couleur = iface.BLEU;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
				{
					/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
					ifaceInternalSCI.sequence1 = false;
					ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
					ifaceInternalSCI.Couleur = iface.JAUNE;
					break;
				}
				default: break;
			}
			/* 'default' enter sequence for state EVITEMENT */
			/* Entry action for state 'EVITEMENT'. */
			ifaceInternalSCI.evitementTempo = 0;
			ifaceInternalSCI.evitementEnCours = true;
			iface.IN_x_pos = iface.x_pos_mem;
			/* 'default' enter sequence for region EVITEMENT_REGION */
			/* Default react sequence for initial entry  */
			/* 'default' enter sequence for state ARRET_ROBOT */
			/* Entry action for state 'ARRET_ROBOT'. */
			SCI_Asser_OCB::Manuel(0, 0);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT;
			stateConfVectorPosition = 0;
		}  else
		{
			if (!ifaceInternalSCI.sequence1)
			{ 
				/* Default exit sequence for state MODULES_LUNAIRES_COTE */
				/* Default exit sequence for region HOMOLOGATION_REGION */
				/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION.MODULES_LUNAIRES_COTE.HOMOLOGATION_REGION) at position 0... */
				switch(stateConfVector[ 0 ])
				{
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
					{
						/* Default exit sequence for state DEPOSE_MODULE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
					{
						/* Default exit sequence for state LARGAGE_MODULES */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'LARGAGE_MODULES'. */
						ifaceInternalSCI.inhibeObstacle = true;
						SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
						SCI_Chariot_OCB::setPos(30);
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
					{
						/* Default exit sequence for final state. */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
					{
						/* Default exit sequence for state POSITION_INIT */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
					{
						/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
					{
						/* Default exit sequence for state PRISE_MODULE_01 */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
					{
						/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
						ifaceInternalSCI.sequence1 = false;
						ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
						ifaceInternalSCI.Couleur = iface.BLEU;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
					{
						/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
						ifaceInternalSCI.sequence1 = false;
						ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
						ifaceInternalSCI.Couleur = iface.JAUNE;
						break;
					}
					default: break;
				}
				ifaceInternalSCI.sequence2 = true;
				ifaceInternalSCI.pos_fusee = ifaceInternalSCI.pos_fusee * ifaceInternalSCI.invMouv;
				/* 'entry_Init' enter sequence for state MODULES_COTE_JAUNE */
				/* 'entry_Init' enter sequence for region SEQUENCE_MODULES_FUSEE */
				/* Default react sequence for initial entry entry_Init */
				/* 'default' enter sequence for state INIT_KMAR */
				/* Entry action for state 'INIT_KMAR'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR;
				stateConfVectorPosition = 0;
				historyVector[1] = stateConfVector[0];
			}  else
			{
			}
		}
	}
}

/* The reactions of state POSITION_INIT. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT()
{
	/* The reactions of state POSITION_INIT. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if ((iface.IN_Obstacle == 1) && (ifaceInternalSCI.inhibeObstacle == false))
		{ 
			/* Default exit sequence for state MODULES_LUNAIRES_COTE */
			/* Default exit sequence for region HOMOLOGATION_REGION */
			/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION.MODULES_LUNAIRES_COTE.HOMOLOGATION_REGION) at position 0... */
			switch(stateConfVector[ 0 ])
			{
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
				{
					/* Default exit sequence for state DEPOSE_MODULE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
				{
					/* Default exit sequence for state LARGAGE_MODULES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'LARGAGE_MODULES'. */
					ifaceInternalSCI.inhibeObstacle = true;
					SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
					SCI_Chariot_OCB::setPos(30);
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
				{
					/* Default exit sequence for final state. */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
				{
					/* Default exit sequence for state POSITION_INIT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
				{
					/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
				{
					/* Default exit sequence for state PRISE_MODULE_01 */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
				{
					/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
					ifaceInternalSCI.sequence1 = false;
					ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
					ifaceInternalSCI.Couleur = iface.BLEU;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
				{
					/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
					ifaceInternalSCI.sequence1 = false;
					ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
					ifaceInternalSCI.Couleur = iface.JAUNE;
					break;
				}
				default: break;
			}
			/* 'default' enter sequence for state EVITEMENT */
			/* Entry action for state 'EVITEMENT'. */
			ifaceInternalSCI.evitementTempo = 0;
			ifaceInternalSCI.evitementEnCours = true;
			iface.IN_x_pos = iface.x_pos_mem;
			/* 'default' enter sequence for region EVITEMENT_REGION */
			/* Default react sequence for initial entry  */
			/* 'default' enter sequence for state ARRET_ROBOT */
			/* Entry action for state 'ARRET_ROBOT'. */
			SCI_Asser_OCB::Manuel(0, 0);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT;
			stateConfVectorPosition = 0;
		}  else
		{
			if (!ifaceInternalSCI.sequence1)
			{ 
				/* Default exit sequence for state MODULES_LUNAIRES_COTE */
				/* Default exit sequence for region HOMOLOGATION_REGION */
				/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION.MODULES_LUNAIRES_COTE.HOMOLOGATION_REGION) at position 0... */
				switch(stateConfVector[ 0 ])
				{
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
					{
						/* Default exit sequence for state DEPOSE_MODULE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
					{
						/* Default exit sequence for state LARGAGE_MODULES */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'LARGAGE_MODULES'. */
						ifaceInternalSCI.inhibeObstacle = true;
						SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
						SCI_Chariot_OCB::setPos(30);
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
					{
						/* Default exit sequence for final state. */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
					{
						/* Default exit sequence for state POSITION_INIT */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
					{
						/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
					{
						/* Default exit sequence for state PRISE_MODULE_01 */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
					{
						/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
						ifaceInternalSCI.sequence1 = false;
						ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
						ifaceInternalSCI.Couleur = iface.BLEU;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
					{
						/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
						ifaceInternalSCI.sequence1 = false;
						ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
						ifaceInternalSCI.Couleur = iface.JAUNE;
						break;
					}
					default: break;
				}
				ifaceInternalSCI.sequence2 = true;
				ifaceInternalSCI.pos_fusee = ifaceInternalSCI.pos_fusee * ifaceInternalSCI.invMouv;
				/* 'entry_Init' enter sequence for state MODULES_COTE_JAUNE */
				/* 'entry_Init' enter sequence for region SEQUENCE_MODULES_FUSEE */
				/* Default react sequence for initial entry entry_Init */
				/* 'default' enter sequence for state INIT_KMAR */
				/* Entry action for state 'INIT_KMAR'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR;
				stateConfVectorPosition = 0;
				historyVector[1] = stateConfVector[0];
			}  else
			{
				if (iface.EV_ConvergenceMvt_Rapide_raised || iface.countTimeMvt > (2 / ifaceInternalSCI.Te))
				{ 
					/* Default exit sequence for state POSITION_INIT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* 'default' enter sequence for state DIRECTION_ZONE_ADVERSE */
					/* Entry action for state 'DIRECTION_ZONE_ADVERSE'. */
					SCI_Asser_OCB::XY(98, -100 * ifaceInternalSCI.invMouv);
					iface.countTimeMvt = 0;
					stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE;
					stateConfVectorPosition = 0;
					historyVector[0] = stateConfVector[0];
				} 
			}
		}
	}
}

/* The reactions of state DIRECTION_ZONE_ADVERSE. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE()
{
	/* The reactions of state DIRECTION_ZONE_ADVERSE. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if ((iface.IN_Obstacle == 1) && (ifaceInternalSCI.inhibeObstacle == false))
		{ 
			/* Default exit sequence for state MODULES_LUNAIRES_COTE */
			/* Default exit sequence for region HOMOLOGATION_REGION */
			/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION.MODULES_LUNAIRES_COTE.HOMOLOGATION_REGION) at position 0... */
			switch(stateConfVector[ 0 ])
			{
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
				{
					/* Default exit sequence for state DEPOSE_MODULE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
				{
					/* Default exit sequence for state LARGAGE_MODULES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'LARGAGE_MODULES'. */
					ifaceInternalSCI.inhibeObstacle = true;
					SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
					SCI_Chariot_OCB::setPos(30);
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
				{
					/* Default exit sequence for final state. */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
				{
					/* Default exit sequence for state POSITION_INIT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
				{
					/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
				{
					/* Default exit sequence for state PRISE_MODULE_01 */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
				{
					/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
					ifaceInternalSCI.sequence1 = false;
					ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
					ifaceInternalSCI.Couleur = iface.BLEU;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
				{
					/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
					ifaceInternalSCI.sequence1 = false;
					ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
					ifaceInternalSCI.Couleur = iface.JAUNE;
					break;
				}
				default: break;
			}
			/* 'default' enter sequence for state EVITEMENT */
			/* Entry action for state 'EVITEMENT'. */
			ifaceInternalSCI.evitementTempo = 0;
			ifaceInternalSCI.evitementEnCours = true;
			iface.IN_x_pos = iface.x_pos_mem;
			/* 'default' enter sequence for region EVITEMENT_REGION */
			/* Default react sequence for initial entry  */
			/* 'default' enter sequence for state ARRET_ROBOT */
			/* Entry action for state 'ARRET_ROBOT'. */
			SCI_Asser_OCB::Manuel(0, 0);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT;
			stateConfVectorPosition = 0;
		}  else
		{
			if (!ifaceInternalSCI.sequence1)
			{ 
				/* Default exit sequence for state MODULES_LUNAIRES_COTE */
				/* Default exit sequence for region HOMOLOGATION_REGION */
				/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION.MODULES_LUNAIRES_COTE.HOMOLOGATION_REGION) at position 0... */
				switch(stateConfVector[ 0 ])
				{
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
					{
						/* Default exit sequence for state DEPOSE_MODULE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
					{
						/* Default exit sequence for state LARGAGE_MODULES */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'LARGAGE_MODULES'. */
						ifaceInternalSCI.inhibeObstacle = true;
						SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
						SCI_Chariot_OCB::setPos(30);
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
					{
						/* Default exit sequence for final state. */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
					{
						/* Default exit sequence for state POSITION_INIT */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
					{
						/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
					{
						/* Default exit sequence for state PRISE_MODULE_01 */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
					{
						/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
						ifaceInternalSCI.sequence1 = false;
						ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
						ifaceInternalSCI.Couleur = iface.BLEU;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
					{
						/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
						ifaceInternalSCI.sequence1 = false;
						ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
						ifaceInternalSCI.Couleur = iface.JAUNE;
						break;
					}
					default: break;
				}
				ifaceInternalSCI.sequence2 = true;
				ifaceInternalSCI.pos_fusee = ifaceInternalSCI.pos_fusee * ifaceInternalSCI.invMouv;
				/* 'entry_Init' enter sequence for state MODULES_COTE_JAUNE */
				/* 'entry_Init' enter sequence for region SEQUENCE_MODULES_FUSEE */
				/* Default react sequence for initial entry entry_Init */
				/* 'default' enter sequence for state INIT_KMAR */
				/* Entry action for state 'INIT_KMAR'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR;
				stateConfVectorPosition = 0;
				historyVector[1] = stateConfVector[0];
			}  else
			{
				if (iface.EV_ConvergenceMvt_Rapide_raised || iface.countTimeMvt > (4 / ifaceInternalSCI.Te))
				{ 
					/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* 'default' enter sequence for state PRISE_MODULE_01 */
					/* Entry action for state 'PRISE_MODULE_01'. */
					SCI_Asser_OCB::XYTeta(98, -155 * ifaceInternalSCI.invMouv, 0);
					iface.countTimeMvt = 0;
					stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01;
					stateConfVectorPosition = 0;
					historyVector[0] = stateConfVector[0];
				} 
			}
		}
	}
}

/* The reactions of state PRISE_MODULE_01. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01()
{
	/* The reactions of state PRISE_MODULE_01. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if ((iface.IN_Obstacle == 1) && (ifaceInternalSCI.inhibeObstacle == false))
		{ 
			/* Default exit sequence for state MODULES_LUNAIRES_COTE */
			/* Default exit sequence for region HOMOLOGATION_REGION */
			/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION.MODULES_LUNAIRES_COTE.HOMOLOGATION_REGION) at position 0... */
			switch(stateConfVector[ 0 ])
			{
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
				{
					/* Default exit sequence for state DEPOSE_MODULE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
				{
					/* Default exit sequence for state LARGAGE_MODULES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'LARGAGE_MODULES'. */
					ifaceInternalSCI.inhibeObstacle = true;
					SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
					SCI_Chariot_OCB::setPos(30);
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
				{
					/* Default exit sequence for final state. */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
				{
					/* Default exit sequence for state POSITION_INIT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
				{
					/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
				{
					/* Default exit sequence for state PRISE_MODULE_01 */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
				{
					/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
					ifaceInternalSCI.sequence1 = false;
					ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
					ifaceInternalSCI.Couleur = iface.BLEU;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
				{
					/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
					ifaceInternalSCI.sequence1 = false;
					ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
					ifaceInternalSCI.Couleur = iface.JAUNE;
					break;
				}
				default: break;
			}
			/* 'default' enter sequence for state EVITEMENT */
			/* Entry action for state 'EVITEMENT'. */
			ifaceInternalSCI.evitementTempo = 0;
			ifaceInternalSCI.evitementEnCours = true;
			iface.IN_x_pos = iface.x_pos_mem;
			/* 'default' enter sequence for region EVITEMENT_REGION */
			/* Default react sequence for initial entry  */
			/* 'default' enter sequence for state ARRET_ROBOT */
			/* Entry action for state 'ARRET_ROBOT'. */
			SCI_Asser_OCB::Manuel(0, 0);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT;
			stateConfVectorPosition = 0;
		}  else
		{
			if (!ifaceInternalSCI.sequence1)
			{ 
				/* Default exit sequence for state MODULES_LUNAIRES_COTE */
				/* Default exit sequence for region HOMOLOGATION_REGION */
				/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION.MODULES_LUNAIRES_COTE.HOMOLOGATION_REGION) at position 0... */
				switch(stateConfVector[ 0 ])
				{
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
					{
						/* Default exit sequence for state DEPOSE_MODULE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
					{
						/* Default exit sequence for state LARGAGE_MODULES */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'LARGAGE_MODULES'. */
						ifaceInternalSCI.inhibeObstacle = true;
						SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
						SCI_Chariot_OCB::setPos(30);
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
					{
						/* Default exit sequence for final state. */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
					{
						/* Default exit sequence for state POSITION_INIT */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
					{
						/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
					{
						/* Default exit sequence for state PRISE_MODULE_01 */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
					{
						/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
						ifaceInternalSCI.sequence1 = false;
						ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
						ifaceInternalSCI.Couleur = iface.BLEU;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
					{
						/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
						ifaceInternalSCI.sequence1 = false;
						ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
						ifaceInternalSCI.Couleur = iface.JAUNE;
						break;
					}
					default: break;
				}
				ifaceInternalSCI.sequence2 = true;
				ifaceInternalSCI.pos_fusee = ifaceInternalSCI.pos_fusee * ifaceInternalSCI.invMouv;
				/* 'entry_Init' enter sequence for state MODULES_COTE_JAUNE */
				/* 'entry_Init' enter sequence for region SEQUENCE_MODULES_FUSEE */
				/* Default react sequence for initial entry entry_Init */
				/* 'default' enter sequence for state INIT_KMAR */
				/* Entry action for state 'INIT_KMAR'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR;
				stateConfVectorPosition = 0;
				historyVector[1] = stateConfVector[0];
			}  else
			{
				if (iface.EV_ConvergenceMvt_raised || iface.countTimeMvt > (4 / ifaceInternalSCI.Te))
				{ 
					/* Default exit sequence for state PRISE_MODULE_01 */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* 'default' enter sequence for state DEPOSE_MODULE */
					/* Entry action for state 'DEPOSE_MODULE'. */
					SCI_Asser_OCB::XY(138, -145 * ifaceInternalSCI.invMouv);
					iface.countTimeMvt = 0;
					stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE;
					stateConfVectorPosition = 0;
					historyVector[0] = stateConfVector[0];
				} 
			}
		}
	}
}

/* The reactions of state FIN_DEPLACEMENT_JAUNE. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE()
{
	/* The reactions of state FIN_DEPLACEMENT_JAUNE. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if ((iface.IN_Obstacle == 1) && (ifaceInternalSCI.inhibeObstacle == false))
		{ 
			/* Default exit sequence for state MODULES_LUNAIRES_COTE */
			/* Default exit sequence for region HOMOLOGATION_REGION */
			/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION.MODULES_LUNAIRES_COTE.HOMOLOGATION_REGION) at position 0... */
			switch(stateConfVector[ 0 ])
			{
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
				{
					/* Default exit sequence for state DEPOSE_MODULE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
				{
					/* Default exit sequence for state LARGAGE_MODULES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'LARGAGE_MODULES'. */
					ifaceInternalSCI.inhibeObstacle = true;
					SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
					SCI_Chariot_OCB::setPos(30);
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
				{
					/* Default exit sequence for final state. */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
				{
					/* Default exit sequence for state POSITION_INIT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
				{
					/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
				{
					/* Default exit sequence for state PRISE_MODULE_01 */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
				{
					/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
					ifaceInternalSCI.sequence1 = false;
					ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
					ifaceInternalSCI.Couleur = iface.BLEU;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
				{
					/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
					ifaceInternalSCI.sequence1 = false;
					ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
					ifaceInternalSCI.Couleur = iface.JAUNE;
					break;
				}
				default: break;
			}
			/* 'default' enter sequence for state EVITEMENT */
			/* Entry action for state 'EVITEMENT'. */
			ifaceInternalSCI.evitementTempo = 0;
			ifaceInternalSCI.evitementEnCours = true;
			iface.IN_x_pos = iface.x_pos_mem;
			/* 'default' enter sequence for region EVITEMENT_REGION */
			/* Default react sequence for initial entry  */
			/* 'default' enter sequence for state ARRET_ROBOT */
			/* Entry action for state 'ARRET_ROBOT'. */
			SCI_Asser_OCB::Manuel(0, 0);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT;
			stateConfVectorPosition = 0;
		}  else
		{
			if (!ifaceInternalSCI.sequence1)
			{ 
				/* Default exit sequence for state MODULES_LUNAIRES_COTE */
				/* Default exit sequence for region HOMOLOGATION_REGION */
				/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION.MODULES_LUNAIRES_COTE.HOMOLOGATION_REGION) at position 0... */
				switch(stateConfVector[ 0 ])
				{
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
					{
						/* Default exit sequence for state DEPOSE_MODULE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
					{
						/* Default exit sequence for state LARGAGE_MODULES */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'LARGAGE_MODULES'. */
						ifaceInternalSCI.inhibeObstacle = true;
						SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
						SCI_Chariot_OCB::setPos(30);
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
					{
						/* Default exit sequence for final state. */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
					{
						/* Default exit sequence for state POSITION_INIT */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
					{
						/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
					{
						/* Default exit sequence for state PRISE_MODULE_01 */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
					{
						/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
						ifaceInternalSCI.sequence1 = false;
						ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
						ifaceInternalSCI.Couleur = iface.BLEU;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
					{
						/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
						ifaceInternalSCI.sequence1 = false;
						ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
						ifaceInternalSCI.Couleur = iface.JAUNE;
						break;
					}
					default: break;
				}
				ifaceInternalSCI.sequence2 = true;
				ifaceInternalSCI.pos_fusee = ifaceInternalSCI.pos_fusee * ifaceInternalSCI.invMouv;
				/* 'entry_Init' enter sequence for state MODULES_COTE_JAUNE */
				/* 'entry_Init' enter sequence for region SEQUENCE_MODULES_FUSEE */
				/* Default react sequence for initial entry entry_Init */
				/* 'default' enter sequence for state INIT_KMAR */
				/* Entry action for state 'INIT_KMAR'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR;
				stateConfVectorPosition = 0;
				historyVector[1] = stateConfVector[0];
			}  else
			{
				if (iface.EV_ConvergenceMvt_raised || iface.countTimeMvt > (3 / ifaceInternalSCI.Te))
				{ 
					/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
					ifaceInternalSCI.sequence1 = false;
					ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
					ifaceInternalSCI.Couleur = iface.BLEU;
					/* Default enter sequence for state null */
					stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_;
					stateConfVectorPosition = 0;
				} 
			}
		}
	}
}

/* The reactions of state FIN_DEPLACEMENT_BLEU. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU()
{
	/* The reactions of state FIN_DEPLACEMENT_BLEU. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if ((iface.IN_Obstacle == 1) && (ifaceInternalSCI.inhibeObstacle == false))
		{ 
			/* Default exit sequence for state MODULES_LUNAIRES_COTE */
			/* Default exit sequence for region HOMOLOGATION_REGION */
			/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION.MODULES_LUNAIRES_COTE.HOMOLOGATION_REGION) at position 0... */
			switch(stateConfVector[ 0 ])
			{
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
				{
					/* Default exit sequence for state DEPOSE_MODULE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
				{
					/* Default exit sequence for state LARGAGE_MODULES */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'LARGAGE_MODULES'. */
					ifaceInternalSCI.inhibeObstacle = true;
					SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
					SCI_Chariot_OCB::setPos(30);
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
				{
					/* Default exit sequence for final state. */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
				{
					/* Default exit sequence for state POSITION_INIT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
				{
					/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
				{
					/* Default exit sequence for state PRISE_MODULE_01 */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
				{
					/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
					ifaceInternalSCI.sequence1 = false;
					ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
					ifaceInternalSCI.Couleur = iface.BLEU;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
				{
					/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
					ifaceInternalSCI.sequence1 = false;
					ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
					ifaceInternalSCI.Couleur = iface.JAUNE;
					break;
				}
				default: break;
			}
			/* 'default' enter sequence for state EVITEMENT */
			/* Entry action for state 'EVITEMENT'. */
			ifaceInternalSCI.evitementTempo = 0;
			ifaceInternalSCI.evitementEnCours = true;
			iface.IN_x_pos = iface.x_pos_mem;
			/* 'default' enter sequence for region EVITEMENT_REGION */
			/* Default react sequence for initial entry  */
			/* 'default' enter sequence for state ARRET_ROBOT */
			/* Entry action for state 'ARRET_ROBOT'. */
			SCI_Asser_OCB::Manuel(0, 0);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT;
			stateConfVectorPosition = 0;
		}  else
		{
			if (!ifaceInternalSCI.sequence1)
			{ 
				/* Default exit sequence for state MODULES_LUNAIRES_COTE */
				/* Default exit sequence for region HOMOLOGATION_REGION */
				/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION.MODULES_LUNAIRES_COTE.HOMOLOGATION_REGION) at position 0... */
				switch(stateConfVector[ 0 ])
				{
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
					{
						/* Default exit sequence for state DEPOSE_MODULE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
					{
						/* Default exit sequence for state LARGAGE_MODULES */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'LARGAGE_MODULES'. */
						ifaceInternalSCI.inhibeObstacle = true;
						SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
						SCI_Chariot_OCB::setPos(30);
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
					{
						/* Default exit sequence for final state. */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
					{
						/* Default exit sequence for state POSITION_INIT */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
					{
						/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
					{
						/* Default exit sequence for state PRISE_MODULE_01 */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
					{
						/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
						ifaceInternalSCI.sequence1 = false;
						ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
						ifaceInternalSCI.Couleur = iface.BLEU;
						break;
					}
					case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
					{
						/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
						stateConfVector[0] = IA_last_state;
						stateConfVectorPosition = 0;
						/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
						ifaceInternalSCI.sequence1 = false;
						ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
						ifaceInternalSCI.Couleur = iface.JAUNE;
						break;
					}
					default: break;
				}
				ifaceInternalSCI.sequence2 = true;
				ifaceInternalSCI.pos_fusee = ifaceInternalSCI.pos_fusee * ifaceInternalSCI.invMouv;
				/* 'entry_Init' enter sequence for state MODULES_COTE_JAUNE */
				/* 'entry_Init' enter sequence for region SEQUENCE_MODULES_FUSEE */
				/* Default react sequence for initial entry entry_Init */
				/* 'default' enter sequence for state INIT_KMAR */
				/* Entry action for state 'INIT_KMAR'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR;
				stateConfVectorPosition = 0;
				historyVector[1] = stateConfVector[0];
			}  else
			{
				if (iface.EV_ConvergenceMvt_raised || iface.countTimeMvt > (3 / ifaceInternalSCI.Te))
				{ 
					/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
					ifaceInternalSCI.sequence1 = false;
					ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
					ifaceInternalSCI.Couleur = iface.JAUNE;
					/* Default enter sequence for state null */
					stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_;
					stateConfVectorPosition = 0;
				} 
			}
		}
	}
}

/* The reactions of state ARRET_ROBOT. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT()
{
	/* The reactions of state ARRET_ROBOT. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if ((ifaceInternalSCI.evitementEnCours == false) && (iface.IN_Obstacle == 0))
		{ 
			/* Default exit sequence for state EVITEMENT */
			/* Default exit sequence for region EVITEMENT_REGION */
			/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION.EVITEMENT.EVITEMENT_REGION) at position 0... */
			switch(stateConfVector[ 0 ])
			{
				case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
				{
					/* Default exit sequence for state ARRET_ROBOT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
				{
					/* Default exit sequence for state SORTIE_EVITEMENT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
				{
					/* Default exit sequence for final state. */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				default: break;
			}
			react_STRATEGIE_MATCH_MATCH_REGION__choice_0();
		}  else
		{
			ifaceInternalSCI.evitementTempo = ifaceInternalSCI.evitementTempo + 1;
			if ((ifaceInternalSCI.evitementTempo > (1 / ifaceInternalSCI.Te)))
			{ 
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* 'default' enter sequence for state SORTIE_EVITEMENT */
				/* Entry action for state 'SORTIE_EVITEMENT'. */
				ifaceInternalSCI.evitementEnCours = false;
				stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT;
				stateConfVectorPosition = 0;
			} 
		}
	}
}

/* The reactions of state SORTIE_EVITEMENT. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT()
{
	/* The reactions of state SORTIE_EVITEMENT. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if ((ifaceInternalSCI.evitementEnCours == false) && (iface.IN_Obstacle == 0))
		{ 
			/* Default exit sequence for state EVITEMENT */
			/* Default exit sequence for region EVITEMENT_REGION */
			/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION.EVITEMENT.EVITEMENT_REGION) at position 0... */
			switch(stateConfVector[ 0 ])
			{
				case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
				{
					/* Default exit sequence for state ARRET_ROBOT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
				{
					/* Default exit sequence for state SORTIE_EVITEMENT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
				{
					/* Default exit sequence for final state. */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				default: break;
			}
			react_STRATEGIE_MATCH_MATCH_REGION__choice_0();
		}  else
		{
			ifaceInternalSCI.evitementTempo = ifaceInternalSCI.evitementTempo + 1;
			/* Default exit sequence for state SORTIE_EVITEMENT */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Default enter sequence for state null */
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_;
			stateConfVectorPosition = 0;
		}
	}
}

/* The reactions of state null. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_()
{
	/* The reactions of state null. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if ((ifaceInternalSCI.evitementEnCours == false) && (iface.IN_Obstacle == 0))
		{ 
			/* Default exit sequence for state EVITEMENT */
			/* Default exit sequence for region EVITEMENT_REGION */
			/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION.EVITEMENT.EVITEMENT_REGION) at position 0... */
			switch(stateConfVector[ 0 ])
			{
				case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
				{
					/* Default exit sequence for state ARRET_ROBOT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
				{
					/* Default exit sequence for state SORTIE_EVITEMENT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
				{
					/* Default exit sequence for final state. */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				default: break;
			}
			react_STRATEGIE_MATCH_MATCH_REGION__choice_0();
		}  else
		{
			ifaceInternalSCI.evitementTempo = ifaceInternalSCI.evitementTempo + 1;
		}
	}
}

/* The reactions of state INIT_MATCH. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH()
{
	/* The reactions of state INIT_MATCH. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		/* Default exit sequence for state INIT_MATCH */
		stateConfVector[0] = IA_last_state;
		stateConfVectorPosition = 0;
		/* Exit action for state 'INIT_MATCH'. */
		ifaceInternalSCI.sequence1 = true;
		SCI_Asser_OCB::setSportivite(1);
		/* 'entry_Init' enter sequence for state MODULES_LUNAIRES_COTE */
		/* 'entry_Init' enter sequence for region HOMOLOGATION_REGION */
		/* Default react sequence for initial entry entry_Init */
		/* 'default' enter sequence for state POSITION_INIT */
		/* Entry action for state 'POSITION_INIT'. */
		SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_ROTATION, 0);
		SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 750);
		SCI_Chariot_OCB::setPos(-800);
		SCI_Asser_OCB::XY(10, 0);
		iface.countTimeMvt = 0;
		stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT;
		stateConfVectorPosition = 0;
		historyVector[0] = stateConfVector[0];
	}
}

/* The reactions of state INIT_KMAR. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR()
{
	/* The reactions of state INIT_KMAR. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		/* Default exit sequence for state INIT_KMAR */
		stateConfVector[0] = IA_last_state;
		stateConfVectorPosition = 0;
		/* 'default' enter sequence for state INIT_COULEUR */
		/* Entry action for state 'INIT_COULEUR'. */
		SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_COULEUR, 510);
		stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR;
		stateConfVectorPosition = 0;
		historyVector[1] = stateConfVector[0];
	}
}

/* The reactions of state FACE_FUSEE. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE()
{
	/* The reactions of state FACE_FUSEE. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if (iface.EV_ConvergenceChariot_raised || (iface.countTempo > (3 / ifaceInternalSCI.Te)))
		{ 
			/* Default exit sequence for state FACE_FUSEE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_3();
		} 
	}
}

/* The reactions of state VENTOUSAGE_INCERTAIN. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN()
{
	/* The reactions of state VENTOUSAGE_INCERTAIN. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if (iface.countTempo > (0.75 / ifaceInternalSCI.Te))
		{ 
			/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_2();
		} 
	}
}

/* The reactions of state ATTENTE_VENTOUSAGE. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE()
{
	/* The reactions of state ATTENTE_VENTOUSAGE. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if (iface.countTempo > (1 / ifaceInternalSCI.Te) || iface.IN_Depression)
		{ 
			/* Default exit sequence for state ATTENTE_VENTOUSAGE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* 'default' enter sequence for state RETIRE_MODULE */
			/* Entry action for state 'RETIRE_MODULE'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 435);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state RETIRE_MODULE. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE()
{
	/* The reactions of state RETIRE_MODULE. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if (iface.countTempo > (1.5 / ifaceInternalSCI.Te))
		{ 
			/* Default exit sequence for state RETIRE_MODULE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* 'default' enter sequence for state DEGAGE_MODULE */
			/* Entry action for state 'DEGAGE_MODULE'. */
			SCI_Chariot_OCB::setPos(ifaceInternalSCI.invMouv * 300 + ifaceInternalSCI.invMouv * 35 * ifaceInternalSCI.nb_tentatives);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state DEGAGE_MODULE. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE()
{
	/* The reactions of state DEGAGE_MODULE. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if (iface.EV_ConvergenceChariot_raised || (iface.countTempo > (3 / ifaceInternalSCI.Te)))
		{ 
			/* Default exit sequence for state DEGAGE_MODULE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* 'default' enter sequence for state PROCHE_BORDURE */
			/* Entry action for state 'PROCHE_BORDURE'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state PROCHE_BORDURE. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE()
{
	/* The reactions of state PROCHE_BORDURE. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		/* Default exit sequence for state PROCHE_BORDURE */
		stateConfVector[0] = IA_last_state;
		stateConfVectorPosition = 0;
		/* 'default' enter sequence for state RALENTI_ROTATION */
		/* Entry action for state 'RALENTI_ROTATION'. */
		SCI_Ax_OCB::setSpd(IA::DefaultSCI::AX_ROTATION, 100);
		stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION;
		stateConfVectorPosition = 0;
		historyVector[1] = stateConfVector[0];
	}
}

/* The reactions of state RALENTI_ROTATION. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION()
{
	/* The reactions of state RALENTI_ROTATION. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		/* Default exit sequence for state RALENTI_ROTATION */
		stateConfVector[0] = IA_last_state;
		stateConfVectorPosition = 0;
		/* 'default' enter sequence for state SOULEVE_MODULE */
		/* Entry action for state 'SOULEVE_MODULE'. */
		SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_ROTATION, 500);
		stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE;
		stateConfVectorPosition = 0;
		historyVector[1] = stateConfVector[0];
	}
}

/* The reactions of state SOULEVE_MODULE. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE()
{
	/* The reactions of state SOULEVE_MODULE. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		/* Default exit sequence for state SOULEVE_MODULE */
		stateConfVector[0] = IA_last_state;
		stateConfVectorPosition = 0;
		react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_1();
	}
}

/* The reactions of state CHOISI_COULEUR. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR()
{
	/* The reactions of state CHOISI_COULEUR. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if (iface.countTempo > (2.5 / ifaceInternalSCI.Te))
		{ 
			/* Default exit sequence for state CHOISI_COULEUR */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* 'default' enter sequence for state PROCHE_ZONE */
			/* Entry action for state 'PROCHE_ZONE'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 550);
			SCI_Chariot_OCB::setPos(-150 * ifaceInternalSCI.invMouv + ifaceInternalSCI.invMouv * 45 * ifaceInternalSCI.nb_tentatives);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state INIT_COULEUR. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR()
{
	/* The reactions of state INIT_COULEUR. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		/* Default exit sequence for state INIT_COULEUR */
		stateConfVector[0] = IA_last_state;
		stateConfVectorPosition = 0;
		/* 'default' enter sequence for state RALENTI_AX_COULEUR */
		/* Entry action for state 'RALENTI_AX_COULEUR'. */
		SCI_Ax_OCB::setSpd(IA::DefaultSCI::AX_COULEUR, 100);
		stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR;
		stateConfVectorPosition = 0;
		historyVector[1] = stateConfVector[0];
	}
}

/* The reactions of state RALENTI_AX_COULEUR. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR()
{
	/* The reactions of state RALENTI_AX_COULEUR. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		/* Default exit sequence for state RALENTI_AX_COULEUR */
		stateConfVector[0] = IA_last_state;
		stateConfVectorPosition = 0;
		react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_6();
	}
}

/* The reactions of state TOURNE_POUR_FUSEE. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE()
{
	/* The reactions of state TOURNE_POUR_FUSEE. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if (iface.countTempo > (1 / ifaceInternalSCI.Te))
		{ 
			/* Default exit sequence for state TOURNE_POUR_FUSEE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* 'default' enter sequence for state LEVIER_RECULE_AU_MAX */
			/* Entry action for state 'LEVIER_RECULE_AU_MAX'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 435);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state PROCHE_ZONE. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE()
{
	/* The reactions of state PROCHE_ZONE. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if (iface.EV_ConvergenceChariot_raised || (iface.countTempo > (3 / ifaceInternalSCI.Te)))
		{ 
			/* Default exit sequence for state PROCHE_ZONE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_7();
		} 
	}
}

/* The reactions of state AU_DESSUS_ZONE. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE()
{
	/* The reactions of state AU_DESSUS_ZONE. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if (iface.countTempo > (1 / ifaceInternalSCI.Te))
		{ 
			/* Default exit sequence for state AU_DESSUS_ZONE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* 'default' enter sequence for state DEVENTOUSAGE */
			/* Entry action for state 'DEVENTOUSAGE'. */
			SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state DEVENTOUSAGE. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE()
{
	/* The reactions of state DEVENTOUSAGE. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if (iface.countTempo > (0.5 / ifaceInternalSCI.Te))
		{ 
			/* Default exit sequence for state DEVENTOUSAGE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* 'default' enter sequence for state ACCELERE_AX_ROTATION */
			/* Entry action for state 'ACCELERE_AX_ROTATION'. */
			SCI_Ax_OCB::setSpd(IA::DefaultSCI::AX_ROTATION, 0);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state ACCELERE_AX_ROTATION. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION()
{
	/* The reactions of state ACCELERE_AX_ROTATION. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		/* Default exit sequence for state ACCELERE_AX_ROTATION */
		stateConfVector[0] = IA_last_state;
		stateConfVectorPosition = 0;
		/* 'default' enter sequence for state ACCELERE_AX_LEVIER */
		/* Entry action for state 'ACCELERE_AX_LEVIER'. */
		SCI_Ax_OCB::setSpd(IA::DefaultSCI::AX_LEVIER, 0);
		stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER;
		stateConfVectorPosition = 0;
		historyVector[1] = stateConfVector[0];
	}
}

/* The reactions of state ACCELERE_AX_LEVIER. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER()
{
	/* The reactions of state ACCELERE_AX_LEVIER. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		/* Default exit sequence for state ACCELERE_AX_LEVIER */
		stateConfVector[0] = IA_last_state;
		stateConfVectorPosition = 0;
		/* 'default' enter sequence for state INIT_AX_LEVIER */
		/* Entry action for state 'INIT_AX_LEVIER'. */
		SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
		stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER;
		stateConfVectorPosition = 0;
		historyVector[1] = stateConfVector[0];
	}
}

/* The reactions of state INIT_AX_LEVIER. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER()
{
	/* The reactions of state INIT_AX_LEVIER. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		/* Default exit sequence for state INIT_AX_LEVIER */
		stateConfVector[0] = IA_last_state;
		stateConfVectorPosition = 0;
		react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_0();
	}
}

/* The reactions of state null. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_()
{
	/* The reactions of state null. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
	}
}

/* The reactions of state MAX_HORS_ZONE. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE()
{
	/* The reactions of state MAX_HORS_ZONE. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if (iface.EV_ConvergenceChariot_raised || (iface.countTempo > (2 / ifaceInternalSCI.Te)))
		{ 
			/* Default exit sequence for state MAX_HORS_ZONE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'MAX_HORS_ZONE'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
			/* 'default' enter sequence for state DECALE_MODULES */
			/* Entry action for state 'DECALE_MODULES'. */
			SCI_Chariot_OCB::setPos(800 * ifaceInternalSCI.invMouv + ifaceInternalSCI.invMouv * 45 * ifaceInternalSCI.nb_tentatives);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state DECALE_MODULES. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES()
{
	/* The reactions of state DECALE_MODULES. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if (iface.EV_ConvergenceChariot_raised || (iface.countTempo > (2 / ifaceInternalSCI.Te)))
		{ 
			/* Default exit sequence for state DECALE_MODULES */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* 'default' enter sequence for state INIT_CHARIOT_COTE */
			/* Entry action for state 'INIT_CHARIOT_COTE'. */
			SCI_Chariot_OCB::setPos(0);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state INIT_CHARIOT_COTE. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE()
{
	/* The reactions of state INIT_CHARIOT_COTE. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if (iface.EV_ConvergenceChariot_raised || (iface.countTempo > (2 / ifaceInternalSCI.Te)))
		{ 
			/* Default exit sequence for state INIT_CHARIOT_COTE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* 'default' enter sequence for state RECENTRAGE_BRAS */
			/* Entry action for state 'RECENTRAGE_BRAS'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_ROTATION, 505);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state RECENTRAGE_BRAS. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS()
{
	/* The reactions of state RECENTRAGE_BRAS. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if (iface.countTime > (1 / ifaceInternalSCI.Te))
		{ 
			/* Default exit sequence for state RECENTRAGE_BRAS */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			iface.nb_Modules = iface.nb_Modules + 1;
			/* 'default' enter sequence for state INIT_KMAR */
			/* Entry action for state 'INIT_KMAR'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state FIN_INIT_CHARIOT_COTE. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE()
{
	/* The reactions of state FIN_INIT_CHARIOT_COTE. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if (iface.EV_ConvergenceChariot_raised || (iface.countTempo > (2 / ifaceInternalSCI.Te)))
		{ 
			/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* 'default' enter sequence for state RANGE_BRAS_01 */
			/* Entry action for state 'RANGE_BRAS_01'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_ROTATION, 200);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state RANGE_BRAS_02. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02()
{
	/* The reactions of state RANGE_BRAS_02. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		/* Default exit sequence for state RANGE_BRAS_02 */
		stateConfVector[0] = IA_last_state;
		stateConfVectorPosition = 0;
		/* Default enter sequence for state null */
		stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_;
		stateConfVectorPosition = 0;
	}
}

/* The reactions of state Copy_1_CHOISI_COULEUR. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR()
{
	/* The reactions of state Copy_1_CHOISI_COULEUR. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if (iface.countTempo > (2.5 / ifaceInternalSCI.Te))
		{ 
			/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* 'default' enter sequence for state PROCHE_ZONE */
			/* Entry action for state 'PROCHE_ZONE'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 550);
			SCI_Chariot_OCB::setPos(-150 * ifaceInternalSCI.invMouv + ifaceInternalSCI.invMouv * 45 * ifaceInternalSCI.nb_tentatives);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state LEVIER_RECULE_AU_MAX. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX()
{
	/* The reactions of state LEVIER_RECULE_AU_MAX. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if (iface.countTempo > (0.5 / ifaceInternalSCI.Te))
		{ 
			/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* 'default' enter sequence for state FACE_FUSEE */
			/* Entry action for state 'FACE_FUSEE'. */
			SCI_Chariot_OCB::setPos(ifaceInternalSCI.pos_fusee);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state CHERCHE_FUSEE. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE()
{
	/* The reactions of state CHERCHE_FUSEE. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if (iface.EV_ConvergenceChariot_raised || (iface.countTempo > (1 / ifaceInternalSCI.Te)))
		{ 
			/* Default exit sequence for state CHERCHE_FUSEE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* 'default' enter sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
			/* Entry action for state 'Copy_1_LEVIER_RECULE_AU_MAX'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 435);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state Copy_1_LEVIER_RECULE_AU_MAX. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX()
{
	/* The reactions of state Copy_1_LEVIER_RECULE_AU_MAX. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if (iface.countTempo > (0.75 / ifaceInternalSCI.Te))
		{ 
			/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* 'default' enter sequence for state VENTOUSAGE_INCERTAIN */
			/* Entry action for state 'VENTOUSAGE_INCERTAIN'. */
			SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 100);
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 580);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state VENTOUSAGE_CERTAIN. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN()
{
	/* The reactions of state VENTOUSAGE_CERTAIN. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		/* Default exit sequence for state VENTOUSAGE_CERTAIN */
		stateConfVector[0] = IA_last_state;
		stateConfVectorPosition = 0;
		/* 'default' enter sequence for state ATTENTE_VENTOUSAGE */
		/* Entry action for state 'ATTENTE_VENTOUSAGE'. */
		SCI_Ax_OCB::setSpd(IA::DefaultSCI::AX_LEVIER, 100);
		iface.countTempo = 0;
		stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE;
		stateConfVectorPosition = 0;
		historyVector[1] = stateConfVector[0];
	}
}

/* The reactions of state RANGE_BRAS_01. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01()
{
	/* The reactions of state RANGE_BRAS_01. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if (iface.countTempo > (2 / ifaceInternalSCI.Te))
		{ 
			/* Default exit sequence for state RANGE_BRAS_01 */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* 'default' enter sequence for state RANGE_BRAS_02 */
			/* Entry action for state 'RANGE_BRAS_02'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 300);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state Copy_1_TOURNE_POUR_FUSEE. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE()
{
	/* The reactions of state Copy_1_TOURNE_POUR_FUSEE. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if (iface.countTempo > (1 / ifaceInternalSCI.Te))
		{ 
			/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* 'default' enter sequence for state LEVIER_RECULE_AU_MAX */
			/* Entry action for state 'LEVIER_RECULE_AU_MAX'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 435);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state Copy_1_AU_DESSUS_ZONE. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE()
{
	/* The reactions of state Copy_1_AU_DESSUS_ZONE. */
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of IA.STRATEGIE.MATCH.MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ])
		{
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE :
			{
				/* Default exit sequence for state DEPOSE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES :
			{
				/* Default exit sequence for state LARGAGE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'LARGAGE_MODULES'. */
				ifaceInternalSCI.inhibeObstacle = true;
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 530);
				SCI_Chariot_OCB::setPos(30);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT :
			{
				/* Default exit sequence for state POSITION_INIT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE :
			{
				/* Default exit sequence for state DIRECTION_ZONE_ADVERSE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01 :
			{
				/* Default exit sequence for state PRISE_MODULE_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_JAUNE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_JAUNE'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.BLEU;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU :
			{
				/* Default exit sequence for state FIN_DEPLACEMENT_BLEU */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'FIN_DEPLACEMENT_BLEU'. */
				ifaceInternalSCI.sequence1 = false;
				ifaceInternalSCI.invMouv = -ifaceInternalSCI.invMouv;
				ifaceInternalSCI.Couleur = iface.JAUNE;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT :
			{
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT :
			{
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH :
			{
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'INIT_MATCH'. */
				ifaceInternalSCI.sequence1 = true;
				SCI_Asser_OCB::setSportivite(1);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR :
			{
				/* Default exit sequence for state INIT_KMAR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE :
			{
				/* Default exit sequence for state FACE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_INCERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE :
			{
				/* Default exit sequence for state ATTENTE_VENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE :
			{
				/* Default exit sequence for state RETIRE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE :
			{
				/* Default exit sequence for state DEGAGE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE :
			{
				/* Default exit sequence for state PROCHE_BORDURE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION :
			{
				/* Default exit sequence for state RALENTI_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE :
			{
				/* Default exit sequence for state SOULEVE_MODULE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR :
			{
				/* Default exit sequence for state CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR :
			{
				/* Default exit sequence for state INIT_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR :
			{
				/* Default exit sequence for state RALENTI_AX_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE :
			{
				/* Default exit sequence for state PROCHE_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE :
			{
				/* Default exit sequence for state DEVENTOUSAGE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION :
			{
				/* Default exit sequence for state ACCELERE_AX_ROTATION */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER :
			{
				/* Default exit sequence for state ACCELERE_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER :
			{
				/* Default exit sequence for state INIT_AX_LEVIER */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_ :
			{
				/* Default exit sequence for final state. */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE :
			{
				/* Default exit sequence for state MAX_HORS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				/* Exit action for state 'MAX_HORS_ZONE'. */
				SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 630);
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES :
			{
				/* Default exit sequence for state DECALE_MODULES */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS :
			{
				/* Default exit sequence for state RECENTRAGE_BRAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE :
			{
				/* Default exit sequence for state FIN_INIT_CHARIOT_COTE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02 :
			{
				/* Default exit sequence for state RANGE_BRAS_02 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR :
			{
				/* Default exit sequence for state Copy_1_CHOISI_COULEUR */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE :
			{
				/* Default exit sequence for state CHERCHE_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX :
			{
				/* Default exit sequence for state Copy_1_LEVIER_RECULE_AU_MAX */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN :
			{
				/* Default exit sequence for state VENTOUSAGE_CERTAIN */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01 :
			{
				/* Default exit sequence for state RANGE_BRAS_01 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE :
			{
				/* Default exit sequence for state Copy_1_TOURNE_POUR_FUSEE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE :
			{
				/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* Entry action for state 'FIN_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_MOELDAR */
		/* Entry action for state 'ARRET_MOELDAR'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTimeMvt = iface.countTimeMvt + 1;
		iface.countTime = iface.countTime + 1;
		iface.countTempo = iface.countTempo + 1;
		iface.countTempo2 = iface.countTempo2 + 1;
		iface.tempsMatch = iface.tempsMatch + 1;
		if (iface.countTempo > (1 / ifaceInternalSCI.Te))
		{ 
			/* Default exit sequence for state Copy_1_AU_DESSUS_ZONE */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* 'default' enter sequence for state DEVENTOUSAGE */
			/* Entry action for state 'DEVENTOUSAGE'. */
			SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 0);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state ARRET_ACTIONNEURS. */
void IA::react_STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS()
{
	/* The reactions of state ARRET_ACTIONNEURS. */
	if (iface.countTempo > (10 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state ARRET_ACTIONNEURS */
		stateConfVector[0] = IA_last_state;
		stateConfVectorPosition = 0;
		/* 'default' enter sequence for state FIN_FUNNY */
		/* Entry action for state 'FIN_FUNNY'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_FUNNY, 0);
		iface.countTempo = 0;
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_FIN_FUNNY;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTempo = iface.countTempo + 1;
	}
}

/* The reactions of state FIN_FUNNY. */
void IA::react_STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_FIN_FUNNY()
{
	/* The reactions of state FIN_FUNNY. */
	if (iface.countTempo > (5 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state FIN_FUNNY */
		stateConfVector[0] = IA_last_state;
		stateConfVectorPosition = 0;
		/* Default enter sequence for state null */
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION__final_;
		stateConfVectorPosition = 0;
	}  else
	{
		iface.countTempo = iface.countTempo + 1;
	}
}

/* The reactions of state null. */
void IA::react_STRATEGIE_FIN_MATCH_FIN_MATCH_REGION__final_()
{
	/* The reactions of state null. */
}

/* The reactions of state ARRET_MOELDAR. */
void IA::react_STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR()
{
	/* The reactions of state ARRET_MOELDAR. */
	/* Default exit sequence for state ARRET_MOELDAR */
	stateConfVector[0] = IA_last_state;
	stateConfVectorPosition = 0;
	/* 'default' enter sequence for state ARRET_ACTIONNEURS */
	/* Entry action for state 'ARRET_ACTIONNEURS'. */
	SCI_Asser_OCB::Manuel(0, 0);
	SCI_Ihm_OCB::setLed(3, true);
	SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_FUNNY, 100);
	iface.countTempo = 0;
	stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS;
	stateConfVectorPosition = 0;
}

/* The reactions of state TEMPS_INIT. */
void IA::react_STRATEGIE_TEMPS_INIT()
{
	/* The reactions of state TEMPS_INIT. */
	if (iface.countTime > (0.5 / ifaceInternalSCI.Te))
	{ 
		/* Default exit sequence for state TEMPS_INIT */
		stateConfVector[0] = IA_last_state;
		stateConfVectorPosition = 0;
		/* 'default' enter sequence for state ATTENTE_DEBUT_MATCH */
		/* Entry action for state 'ATTENTE_DEBUT_MATCH'. */
		iface.countTimeMvt = 0;
		iface.countTime = 0;
		iface.countTempo = 0;
		iface.countTempo2 = 0;
		/* 'default' enter sequence for region CHOIX_EQUIPE */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state EQUIPE_1 */
		/* Entry action for state 'EQUIPE_1'. */
		ifaceInternalSCI.Couleur = iface.JAUNE;
		SCI_Ihm_OCB::setLed(4, true);
		ifaceInternalSCI.invMouv = 1;
		stateConfVector[0] = STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1;
		stateConfVectorPosition = 0;
		/* 'default' enter sequence for region APPRENTISSAGE_ACTIONNEUR */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state U065064 */
		/* Entry action for state 'U065064'. */
		SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_COULEUR, 500);
		SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 520);
		iface.countTempo2 = 0;
		stateConfVector[1] = STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_U065064;
		stateConfVectorPosition = 1;
		/* 'default' enter sequence for region CHENILLARD */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state INIT */
		/* Entry action for state 'INIT'. */
		SCI_Ihm_OCB::setLed(2, false);
		SCI_Ihm_OCB::setLed(3, false);
		SCI_Ihm_OCB::setLed(4, false);
		iface.countTempo = 0;
		stateConfVector[2] = STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_INIT;
		stateConfVectorPosition = 2;
	}  else
	{
		iface.countTime = iface.countTime + 1;
	}
}

/* The reactions of state null. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__choice_0()
{
	/* The reactions of state null. */
	if (iface.IN_Couleur == iface.JAUNE)
	{ 
		/* 'default' enter sequence for state FIN_DEPLACEMENT_JAUNE */
		/* Entry action for state 'FIN_DEPLACEMENT_JAUNE'. */
		SCI_Asser_OCB::XYTeta(105, -182.5 * ifaceInternalSCI.invMouv, (-ifaceInternalSCI.PI / 2) * ifaceInternalSCI.invMouv);
		iface.countTimeMvt = 0;
		stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE;
		stateConfVectorPosition = 0;
		historyVector[0] = stateConfVector[0];
	}  else
	{
		if (iface.IN_Couleur == iface.BLEU)
		{ 
			/* 'default' enter sequence for state FIN_DEPLACEMENT_BLEU */
			/* Entry action for state 'FIN_DEPLACEMENT_BLEU'. */
			SCI_Asser_OCB::XYTeta(105, -183.5 * ifaceInternalSCI.invMouv, (-ifaceInternalSCI.PI / 2) * ifaceInternalSCI.invMouv);
			iface.countTimeMvt = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU;
			stateConfVectorPosition = 0;
			historyVector[0] = stateConfVector[0];
		} 
	}
}

/* The reactions of state null. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_0()
{
	/* The reactions of state null. */
	if (iface.nb_Modules < 4)
	{ 
		/* 'default' enter sequence for state MAX_HORS_ZONE */
		/* Entry action for state 'MAX_HORS_ZONE'. */
		SCI_Chariot_OCB::setPos(-700 * ifaceInternalSCI.invMouv + ifaceInternalSCI.invMouv * 45 * ifaceInternalSCI.nb_tentatives);
		iface.countTempo = 0;
		stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE;
		stateConfVectorPosition = 0;
		historyVector[1] = stateConfVector[0];
	}  else
	{
		/* 'default' enter sequence for state FIN_INIT_CHARIOT_COTE */
		/* Entry action for state 'FIN_INIT_CHARIOT_COTE'. */
		SCI_Chariot_OCB::setPos(0);
		iface.countTempo = 0;
		stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE;
		stateConfVectorPosition = 0;
		historyVector[1] = stateConfVector[0];
	}
}

/* The reactions of state null. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_1()
{
	/* The reactions of state null. */
	if (iface.nb_Modules == 2 || iface.nb_Modules == 4)
	{ 
		react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_5();
	}  else
	{
		if (iface.nb_Modules == 1 || iface.nb_Modules == 3)
		{ 
			react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_4();
		} 
	}
}

/* The reactions of state null. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_2()
{
	/* The reactions of state null. */
	if (iface.IN_Depression || ifaceInternalSCI.nb_tentatives > 6)
	{ 
		ifaceInternalSCI.pos_fusee = ifaceInternalSCI.pos_fusee + ifaceInternalSCI.invMouv * 45 * ifaceInternalSCI.nb_tentatives;
		/* 'default' enter sequence for state ATTENTE_VENTOUSAGE */
		/* Entry action for state 'ATTENTE_VENTOUSAGE'. */
		SCI_Ax_OCB::setSpd(IA::DefaultSCI::AX_LEVIER, 100);
		iface.countTempo = 0;
		stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE;
		stateConfVectorPosition = 0;
		historyVector[1] = stateConfVector[0];
	}  else
	{
		if (!iface.IN_Depression)
		{ 
			ifaceInternalSCI.nb_tentatives = ifaceInternalSCI.nb_tentatives + 1;
			/* 'default' enter sequence for state CHERCHE_FUSEE */
			/* Entry action for state 'CHERCHE_FUSEE'. */
			SCI_Chariot_OCB::setPos(ifaceInternalSCI.pos_fusee + ifaceInternalSCI.invMouv * 45 * ifaceInternalSCI.nb_tentatives);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state null. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_3()
{
	/* The reactions of state null. */
	if (ifaceInternalSCI.nb_tentatives == 0)
	{ 
		/* 'default' enter sequence for state VENTOUSAGE_INCERTAIN */
		/* Entry action for state 'VENTOUSAGE_INCERTAIN'. */
		SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 100);
		SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 580);
		iface.countTempo = 0;
		stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN;
		stateConfVectorPosition = 0;
		historyVector[1] = stateConfVector[0];
	}  else
	{
		if (ifaceInternalSCI.nb_tentatives > 0)
		{ 
			/* 'default' enter sequence for state VENTOUSAGE_CERTAIN */
			/* Entry action for state 'VENTOUSAGE_CERTAIN'. */
			SCI_Moteur_OCB::setPWM(IA::DefaultSCI::MOTEUR_MOELDAR, 100);
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_LEVIER, 580);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state null. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_4()
{
	/* The reactions of state null. */
	if (ifaceInternalSCI.Couleur == iface.JAUNE)
	{ 
		/* 'default' enter sequence for state Copy_1_CHOISI_COULEUR */
		/* Entry action for state 'Copy_1_CHOISI_COULEUR'. */
		SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_COULEUR, 200);
		iface.countTempo = 0;
		stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR;
		stateConfVectorPosition = 0;
		historyVector[1] = stateConfVector[0];
	}  else
	{
		if (ifaceInternalSCI.Couleur == iface.BLEU)
		{ 
			/* 'default' enter sequence for state CHOISI_COULEUR */
			/* Entry action for state 'CHOISI_COULEUR'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_COULEUR, 800);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state null. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_5()
{
	/* The reactions of state null. */
	if (ifaceInternalSCI.Couleur == iface.JAUNE)
	{ 
		/* 'default' enter sequence for state CHOISI_COULEUR */
		/* Entry action for state 'CHOISI_COULEUR'. */
		SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_COULEUR, 800);
		iface.countTempo = 0;
		stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR;
		stateConfVectorPosition = 0;
		historyVector[1] = stateConfVector[0];
	}  else
	{
		if (ifaceInternalSCI.Couleur == iface.BLEU)
		{ 
			/* 'default' enter sequence for state Copy_1_CHOISI_COULEUR */
			/* Entry action for state 'Copy_1_CHOISI_COULEUR'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_COULEUR, 200);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state null. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_6()
{
	/* The reactions of state null. */
	if (ifaceInternalSCI.Couleur == iface.JAUNE)
	{ 
		/* 'default' enter sequence for state TOURNE_POUR_FUSEE */
		/* Entry action for state 'TOURNE_POUR_FUSEE'. */
		SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_ROTATION, 800);
		iface.countTempo = 0;
		stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE;
		stateConfVectorPosition = 0;
		historyVector[1] = stateConfVector[0];
	}  else
	{
		if (ifaceInternalSCI.Couleur == iface.BLEU)
		{ 
			/* 'default' enter sequence for state Copy_1_TOURNE_POUR_FUSEE */
			/* Entry action for state 'Copy_1_TOURNE_POUR_FUSEE'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_ROTATION, 200);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state null. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_7()
{
	/* The reactions of state null. */
	if (ifaceInternalSCI.Couleur == iface.JAUNE)
	{ 
		/* 'default' enter sequence for state AU_DESSUS_ZONE */
		/* Entry action for state 'AU_DESSUS_ZONE'. */
		SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_ROTATION, 200);
		iface.countTempo = 0;
		stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE;
		stateConfVectorPosition = 0;
		historyVector[1] = stateConfVector[0];
	}  else
	{
		if (ifaceInternalSCI.Couleur == iface.BLEU)
		{ 
			/* 'default' enter sequence for state Copy_1_AU_DESSUS_ZONE */
			/* Entry action for state 'Copy_1_AU_DESSUS_ZONE'. */
			SCI_Ax_OCB::setPos(IA::DefaultSCI::AX_ROTATION, 800);
			iface.countTempo = 0;
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE;
			stateConfVectorPosition = 0;
			historyVector[1] = stateConfVector[0];
		} 
	}
}

/* The reactions of state null. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION__choice_0()
{
	/* The reactions of state null. */
	if (ifaceInternalSCI.sequence1)
	{ 
		/* 'entry_History' enter sequence for state MODULES_LUNAIRES_COTE */
		/* 'entry_History' enter sequence for region HOMOLOGATION_REGION */
		/* Default react sequence for initial entry entry_History */
		/* Default react sequence for shallow history entry  */
		/* Enter the region with shallow history */
		if (historyVector[0] != IA_last_state)
		{
			shenseq_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION();
		} 
	}  else
	{
		if (ifaceInternalSCI.sequence2)
		{ 
			/* 'entry_History' enter sequence for state MODULES_COTE_JAUNE */
			/* 'entry_History' enter sequence for region SEQUENCE_MODULES_FUSEE */
			/* Default react sequence for initial entry entry_History */
			/* Default react sequence for shallow history entry  */
			/* Enter the region with shallow history */
			if (historyVector[1] != IA_last_state)
			{
				shenseq_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE();
			} 
		} 
	}
}


