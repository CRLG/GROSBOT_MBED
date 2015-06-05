
#include "IA.h"
#include <string.h>
/*! \file Implementation of the state machine 'IA'
*/

IA::IA() {
	
	
	for (int i = 0; i < maxHistoryStates; ++i)
		historyVector[i] = IA_last_state;
	
	stateConfVectorPosition = 0;
	
}

IA::~IA() {
}

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
	iface.countTimeMvt = 0;
	iface.tempsMatch = 0;
	iface.countTime = 0;
	iface.SERVO_BRAS = 13;
	iface.SERVO_CENTREUR_G = 14;
	iface.SERVO_CENTREUR_D = 15;
	iface.SERVO_PINCE_D = 16;
	iface.SERVO_PINCE_G = 17;
	iface.SERVO_BALLE = 18;
	iface.SERVO_RECOLTEURS = 19;
	iface.SERVO_VOLET = 20;
	iface.MOTEUR_ROUE_GAUCHE = 1;
	iface.MOTEUR_ROUE_DROITE = 2;
	iface.MOTEUR_ASCENSEUR = 3;
	iface.MOTEUR_DISTRIBUTEUR = 4;
	iface.MOTEUR_NON_DEFINI = 5;
	iface.MOTEUR_SOUFFLEUR = 6;
	iface.CODEUR_NON_DEFINI = 0;
	iface.CODEUR_ASCENSEUR = 1;
	iface.CODEUR_ROUE_DROITE = 2;
	iface.CODEUR_ROUE_GAUCHE = 3;
	iface.JAUNE = 0;
	iface.VERT = 1;
	ifaceInternalSCI.Couleur = 1;
	ifaceInternalSCI.invMouv = 1;
	ifaceInternalSCI.Te = 0.02;
	ifaceInternalSCI.PI = 3.14;
	ifaceInternalSCI.inhibeObstacle = false;
	ifaceInternalSCI.evitementEnCours = false;
	ifaceInternalSCI.evitementTempo = 0;

}

void IA::enter()
{
	/* Default enter sequence for statechart IA */
	enact_SequenceImpl();
	/* 'default' enter sequence for region STRATEGIE */
	/* Default react sequence for initial entry  */
	/* 'default' enter sequence for state ATTENTE_DEBUT_MATCH */
	/* 'default' enter sequence for region CHOIX_EQUIPE */
	/* Default react sequence for initial entry  */
	/* 'default' enter sequence for state EQUIPE_1 */
	/* Entry action for state 'EQUIPE_1'. */
	ifaceInternalSCI.Couleur = iface.JAUNE;
	ifaceInternalSCI.invMouv = 1;
	stateConfVector[0] = STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1;
	stateConfVectorPosition = 0;
	/* 'default' enter sequence for region APPRENTISSAGE_ACTIONNEUR */
	/* Default react sequence for initial entry  */
	/* 'default' enter sequence for state INIT */
	/* Entry action for state 'INIT'. */
	SCI_Servo_OCB::setPos(iface.SERVO_BRAS, 1500);
	SCI_Ascenseur_OCB::init();
	stateConfVector[1] = STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_INIT;
	stateConfVectorPosition = 1;
}

void IA::exit()
{
	/* Default exit sequence for statechart IA */
	/* Default exit sequence for region STRATEGIE */
	/* Handle exit of all possible states (of STRATEGIE) at position 0... */
	switch(stateConfVector[ 0 ]) {
		case STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1 : {
			/* Default exit sequence for state EQUIPE_1 */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2 : {
			/* Default exit sequence for state EQUIPE_2 */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_PREMIER_PAS : {
			/* Default exit sequence for state PREMIER_PAS */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_INIT_POS : {
			/* Default exit sequence for state INIT_POS */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT : {
			/* Default exit sequence for state ARRET_ROBOT */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT : {
			/* Default exit sequence for state SORTIE_EVITEMENT */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH : {
			/* Default exit sequence for state INIT_MATCH */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		case STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS : {
			/* Default exit sequence for state ARRET_ACTIONNEURS */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			break;
		}
		default: break;
	}
	/* Handle exit of all possible states (of STRATEGIE) at position 1... */
	switch(stateConfVector[ 1 ]) {
		case STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_INIT : {
			/* Default exit sequence for state INIT */
			stateConfVector[1] = IA_last_state;
			stateConfVectorPosition = 1;
			break;
		}
		default: break;
	}
	exact_SequenceImpl();
}

void IA::runCycle() {
	
	clearOutEvents();
	
	for (stateConfVectorPosition = 0;
		stateConfVectorPosition < maxOrthogonalStates;
		stateConfVectorPosition++) {
			
		switch (stateConfVector[stateConfVectorPosition]) {
		case STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1 : {
			react_STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1();
			break;
		}
		case STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2 : {
			react_STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2();
			break;
		}
		case STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_INIT : {
			react_STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_INIT();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_PREMIER_PAS : {
			react_STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_PREMIER_PAS();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_INIT_POS : {
			react_STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_INIT_POS();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT : {
			react_STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT : {
			react_STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT();
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH : {
			react_STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH();
			break;
		}
		case STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS : {
			react_STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS();
			break;
		}
		default:
			break;
		}
	}
	
	clearInEvents();
}

void IA::clearInEvents() {
	iface.EV_Tirette_raised = false;
	iface.EV_Obstacle_raised = false;
	iface.EV_ConvergenceMvt_raised = false;
	iface.EV_ConvergenceMvt_Rapide_raised = false;
}

void IA::clearOutEvents() {
}


sc_boolean IA::isActive(IAStates state) {
	switch (state) {
		case STRATEGIE_ATTENTE_DEBUT_MATCH : 
			return (sc_boolean) (stateConfVector[0] >= STRATEGIE_ATTENTE_DEBUT_MATCH
				&& stateConfVector[0] <= STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_INIT);
		case STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1 : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1
			);
		case STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2 : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2
			);
		case STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_INIT : 
			return (sc_boolean) (stateConfVector[1] == STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_INIT
			);
		case STRATEGIE_MATCH : 
			return (sc_boolean) (stateConfVector[0] >= STRATEGIE_MATCH
				&& stateConfVector[0] <= STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH);
		case STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION : 
			return (sc_boolean) (stateConfVector[0] >= STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION
				&& stateConfVector[0] <= STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_INIT_POS);
		case STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_PREMIER_PAS : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_PREMIER_PAS
			);
		case STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_INIT_POS : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_INIT_POS
			);
		case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT : 
			return (sc_boolean) (stateConfVector[0] >= STRATEGIE_MATCH_MATCH_REGION_EVITEMENT
				&& stateConfVector[0] <= STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT);
		case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT
			);
		case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT
			);
		case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH
			);
		case STRATEGIE_FIN_MATCH : 
			return (sc_boolean) (stateConfVector[0] >= STRATEGIE_FIN_MATCH
				&& stateConfVector[0] <= STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS);
		case STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS : 
			return (sc_boolean) (stateConfVector[0] == STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS
			);
		default: return false;
	}
}

IA::DefaultSCI* IA::getDefaultSCI() {
	return &iface;
}

void IA::DefaultSCI::raise_eV_Tirette() {
	EV_Tirette_raised = true;
}

void IA::raise_eV_Tirette() {
	iface.raise_eV_Tirette();
}

void IA::DefaultSCI::raise_eV_Obstacle() {
	EV_Obstacle_raised = true;
}

void IA::raise_eV_Obstacle() {
	iface.raise_eV_Obstacle();
}

void IA::DefaultSCI::raise_eV_ConvergenceMvt() {
	EV_ConvergenceMvt_raised = true;
}

void IA::raise_eV_ConvergenceMvt() {
	iface.raise_eV_ConvergenceMvt();
}

void IA::DefaultSCI::raise_eV_ConvergenceMvt_Rapide() {
	EV_ConvergenceMvt_Rapide_raised = true;
}

void IA::raise_eV_ConvergenceMvt_Rapide() {
	iface.raise_eV_ConvergenceMvt_Rapide();
}


sc_real IA::DefaultSCI::get_iN_x_pos() {
	return IN_x_pos;
}

sc_real IA::get_iN_x_pos() {
	return iface.IN_x_pos;
}

void IA::DefaultSCI::set_iN_x_pos(sc_real value) {
	IN_x_pos = value;
}

void IA::set_iN_x_pos(sc_real value) {
	iface.IN_x_pos = value;
}

sc_real IA::DefaultSCI::get_iN_y_pos() {
	return IN_y_pos;
}

sc_real IA::get_iN_y_pos() {
	return iface.IN_y_pos;
}

void IA::DefaultSCI::set_iN_y_pos(sc_real value) {
	IN_y_pos = value;
}

void IA::set_iN_y_pos(sc_real value) {
	iface.IN_y_pos = value;
}

sc_real IA::DefaultSCI::get_iN_teta_pos() {
	return IN_teta_pos;
}

sc_real IA::get_iN_teta_pos() {
	return iface.IN_teta_pos;
}

void IA::DefaultSCI::set_iN_teta_pos(sc_real value) {
	IN_teta_pos = value;
}

void IA::set_iN_teta_pos(sc_real value) {
	iface.IN_teta_pos = value;
}

sc_real IA::DefaultSCI::get_iN_vitesse() {
	return IN_vitesse;
}

sc_real IA::get_iN_vitesse() {
	return iface.IN_vitesse;
}

void IA::DefaultSCI::set_iN_vitesse(sc_real value) {
	IN_vitesse = value;
}

void IA::set_iN_vitesse(sc_real value) {
	iface.IN_vitesse = value;
}

sc_real IA::DefaultSCI::get_iN_sens_deplacement() {
	return IN_sens_deplacement;
}

sc_real IA::get_iN_sens_deplacement() {
	return iface.IN_sens_deplacement;
}

void IA::DefaultSCI::set_iN_sens_deplacement(sc_real value) {
	IN_sens_deplacement = value;
}

void IA::set_iN_sens_deplacement(sc_real value) {
	iface.IN_sens_deplacement = value;
}

sc_integer IA::DefaultSCI::get_iN_Couleur() {
	return IN_Couleur;
}

sc_integer IA::get_iN_Couleur() {
	return iface.IN_Couleur;
}

void IA::DefaultSCI::set_iN_Couleur(sc_integer value) {
	IN_Couleur = value;
}

void IA::set_iN_Couleur(sc_integer value) {
	iface.IN_Couleur = value;
}

sc_integer IA::DefaultSCI::get_iN_Obstacle() {
	return IN_Obstacle;
}

sc_integer IA::get_iN_Obstacle() {
	return iface.IN_Obstacle;
}

void IA::DefaultSCI::set_iN_Obstacle(sc_integer value) {
	IN_Obstacle = value;
}

void IA::set_iN_Obstacle(sc_integer value) {
	iface.IN_Obstacle = value;
}

sc_real IA::DefaultSCI::get_countTimeMvt() {
	return countTimeMvt;
}

sc_real IA::get_countTimeMvt() {
	return iface.countTimeMvt;
}

void IA::DefaultSCI::set_countTimeMvt(sc_real value) {
	countTimeMvt = value;
}

void IA::set_countTimeMvt(sc_real value) {
	iface.countTimeMvt = value;
}

sc_real IA::DefaultSCI::get_tempsMatch() {
	return tempsMatch;
}

sc_real IA::get_tempsMatch() {
	return iface.tempsMatch;
}

void IA::DefaultSCI::set_tempsMatch(sc_real value) {
	tempsMatch = value;
}

void IA::set_tempsMatch(sc_real value) {
	iface.tempsMatch = value;
}

sc_real IA::DefaultSCI::get_countTime() {
	return countTime;
}

sc_real IA::get_countTime() {
	return iface.countTime;
}

void IA::DefaultSCI::set_countTime(sc_real value) {
	countTime = value;
}

void IA::set_countTime(sc_real value) {
	iface.countTime = value;
}

sc_integer IA::DefaultSCI::get_sERVO_BRAS() {
	return SERVO_BRAS;
}

sc_integer IA::get_sERVO_BRAS() {
	return iface.SERVO_BRAS;
}

sc_integer IA::DefaultSCI::get_sERVO_CENTREUR_G() {
	return SERVO_CENTREUR_G;
}

sc_integer IA::get_sERVO_CENTREUR_G() {
	return iface.SERVO_CENTREUR_G;
}

sc_integer IA::DefaultSCI::get_sERVO_CENTREUR_D() {
	return SERVO_CENTREUR_D;
}

sc_integer IA::get_sERVO_CENTREUR_D() {
	return iface.SERVO_CENTREUR_D;
}

sc_integer IA::DefaultSCI::get_sERVO_PINCE_D() {
	return SERVO_PINCE_D;
}

sc_integer IA::get_sERVO_PINCE_D() {
	return iface.SERVO_PINCE_D;
}

sc_integer IA::DefaultSCI::get_sERVO_PINCE_G() {
	return SERVO_PINCE_G;
}

sc_integer IA::get_sERVO_PINCE_G() {
	return iface.SERVO_PINCE_G;
}

sc_integer IA::DefaultSCI::get_sERVO_BALLE() {
	return SERVO_BALLE;
}

sc_integer IA::get_sERVO_BALLE() {
	return iface.SERVO_BALLE;
}

sc_integer IA::DefaultSCI::get_sERVO_RECOLTEURS() {
	return SERVO_RECOLTEURS;
}

sc_integer IA::get_sERVO_RECOLTEURS() {
	return iface.SERVO_RECOLTEURS;
}

sc_integer IA::DefaultSCI::get_sERVO_VOLET() {
	return SERVO_VOLET;
}

sc_integer IA::get_sERVO_VOLET() {
	return iface.SERVO_VOLET;
}

sc_integer IA::DefaultSCI::get_mOTEUR_ROUE_GAUCHE() {
	return MOTEUR_ROUE_GAUCHE;
}

sc_integer IA::get_mOTEUR_ROUE_GAUCHE() {
	return iface.MOTEUR_ROUE_GAUCHE;
}

sc_integer IA::DefaultSCI::get_mOTEUR_ROUE_DROITE() {
	return MOTEUR_ROUE_DROITE;
}

sc_integer IA::get_mOTEUR_ROUE_DROITE() {
	return iface.MOTEUR_ROUE_DROITE;
}

sc_integer IA::DefaultSCI::get_mOTEUR_ASCENSEUR() {
	return MOTEUR_ASCENSEUR;
}

sc_integer IA::get_mOTEUR_ASCENSEUR() {
	return iface.MOTEUR_ASCENSEUR;
}

sc_integer IA::DefaultSCI::get_mOTEUR_DISTRIBUTEUR() {
	return MOTEUR_DISTRIBUTEUR;
}

sc_integer IA::get_mOTEUR_DISTRIBUTEUR() {
	return iface.MOTEUR_DISTRIBUTEUR;
}

sc_integer IA::DefaultSCI::get_mOTEUR_NON_DEFINI() {
	return MOTEUR_NON_DEFINI;
}

sc_integer IA::get_mOTEUR_NON_DEFINI() {
	return iface.MOTEUR_NON_DEFINI;
}

sc_integer IA::DefaultSCI::get_mOTEUR_SOUFFLEUR() {
	return MOTEUR_SOUFFLEUR;
}

sc_integer IA::get_mOTEUR_SOUFFLEUR() {
	return iface.MOTEUR_SOUFFLEUR;
}

sc_integer IA::DefaultSCI::get_cODEUR_NON_DEFINI() {
	return CODEUR_NON_DEFINI;
}

sc_integer IA::get_cODEUR_NON_DEFINI() {
	return iface.CODEUR_NON_DEFINI;
}

sc_integer IA::DefaultSCI::get_cODEUR_ASCENSEUR() {
	return CODEUR_ASCENSEUR;
}

sc_integer IA::get_cODEUR_ASCENSEUR() {
	return iface.CODEUR_ASCENSEUR;
}

sc_integer IA::DefaultSCI::get_cODEUR_ROUE_DROITE() {
	return CODEUR_ROUE_DROITE;
}

sc_integer IA::get_cODEUR_ROUE_DROITE() {
	return iface.CODEUR_ROUE_DROITE;
}

sc_integer IA::DefaultSCI::get_cODEUR_ROUE_GAUCHE() {
	return CODEUR_ROUE_GAUCHE;
}

sc_integer IA::get_cODEUR_ROUE_GAUCHE() {
	return iface.CODEUR_ROUE_GAUCHE;
}

sc_integer IA::DefaultSCI::get_jAUNE() {
	return JAUNE;
}

sc_integer IA::get_jAUNE() {
	return iface.JAUNE;
}

sc_integer IA::DefaultSCI::get_vERT() {
	return VERT;
}

sc_integer IA::get_vERT() {
	return iface.VERT;
}


sc_integer IA::InternalSCI::get_couleur() {
	return Couleur;
}

void IA::InternalSCI::set_couleur(sc_integer value) {
	Couleur = value;
}

sc_integer IA::InternalSCI::get_invMouv() {
	return invMouv;
}

void IA::InternalSCI::set_invMouv(sc_integer value) {
	invMouv = value;
}

sc_real IA::InternalSCI::get_te() {
	return Te;
}

void IA::InternalSCI::set_te(sc_real value) {
	Te = value;
}

sc_real IA::InternalSCI::get_pI() {
	return PI;
}

sc_boolean IA::InternalSCI::get_inhibeObstacle() {
	return inhibeObstacle;
}

void IA::InternalSCI::set_inhibeObstacle(sc_boolean value) {
	inhibeObstacle = value;
}

sc_boolean IA::InternalSCI::get_evitementEnCours() {
	return evitementEnCours;
}

void IA::InternalSCI::set_evitementEnCours(sc_boolean value) {
	evitementEnCours = value;
}

sc_real IA::InternalSCI::get_evitementTempo() {
	return evitementTempo;
}

void IA::InternalSCI::set_evitementTempo(sc_real value) {
	evitementTempo = value;
}

IA::SCI_Asser* IA::getSCI_Asser() {
	return &ifaceAsser;
}


IA::SCI_Servo* IA::getSCI_Servo() {
	return &ifaceServo;
}


IA::SCI_Moteur* IA::getSCI_Moteur() {
	return &ifaceMoteur;
}


IA::SCI_Ascenseur* IA::getSCI_Ascenseur() {
	return &ifaceAscenseur;
}


IA::SCI_Capteur* IA::getSCI_Capteur() {
	return &ifaceCapteur;
}


IA::SCI_Ihm* IA::getSCI_Ihm() {
	return &ifaceIhm;
}



// implementations of all internal functions

sc_boolean IA::check_lr0() {
	return true;
}

void IA::effect_lr0() {
	iface.tempsMatch = iface.tempsMatch + 1;
	iface.countTimeMvt = iface.countTimeMvt + 1;
	iface.countTime = iface.countTime + 1;
}

/* Entry action for statechart 'IA'. */
void IA::enact_SequenceImpl() {
}

/* Exit action for state 'IA'. */
void IA::exact_SequenceImpl() {
}

/* shallow enterSequence with history in child HOMOLOGATION_REGION */
void IA::shenseq_SequenceImpl() {
	/* shallow enterSequence with history in child HOMOLOGATION_REGION */
	/* Handle shallow history entry of HOMOLOGATION_REGION */
	switch(historyVector[ 0 ]) {
		case STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_PREMIER_PAS : {
			/* 'default' enter sequence for state PREMIER_PAS */
			/* Entry action for state 'PREMIER_PAS'. */
			SCI_Asser_OCB::XYTeta(10, 10, ifaceInternalSCI.PI);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_PREMIER_PAS;
			stateConfVectorPosition = 0;
			historyVector[0] = stateConfVector[0];
			break;
		}
		case STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_INIT_POS : {
			/* 'default' enter sequence for state INIT_POS */
			/* Entry action for state 'INIT_POS'. */
			SCI_Asser_OCB::setPosition(0, 0, ifaceInternalSCI.PI);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_INIT_POS;
			stateConfVectorPosition = 0;
			historyVector[0] = stateConfVector[0];
			break;
		}
		default: break;
	}
}

/* The reactions of state EQUIPE_1. */
void IA::react_STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1() {
	/* The reactions of state EQUIPE_1. */
	effect_lr0();
	if (iface.EV_Tirette_raised) { 
		/* Default exit sequence for state ATTENTE_DEBUT_MATCH */
		/* Default exit sequence for region CHOIX_EQUIPE */
		/* Handle exit of all possible states (of CHOIX_EQUIPE) at position 0... */
		switch(stateConfVector[ 0 ]) {
			case STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1 : {
				/* Default exit sequence for state EQUIPE_1 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2 : {
				/* Default exit sequence for state EQUIPE_2 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* Default exit sequence for region APPRENTISSAGE_ACTIONNEUR */
		/* Handle exit of all possible states (of APPRENTISSAGE_ACTIONNEUR) at position 1... */
		switch(stateConfVector[ 1 ]) {
			case STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_INIT : {
				/* Default exit sequence for state INIT */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state MATCH */
		/* 'default' enter sequence for region MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state INIT_MATCH */
		/* Entry action for state 'INIT_MATCH'. */
		iface.tempsMatch = 0;
		stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH;
		stateConfVectorPosition = 0;
	}  else {
		if (iface.IN_Couleur == iface.VERT) { 
			/* Default exit sequence for state EQUIPE_1 */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* 'default' enter sequence for state EQUIPE_2 */
			/* Entry action for state 'EQUIPE_2'. */
			ifaceInternalSCI.Couleur = iface.VERT;
			ifaceInternalSCI.invMouv = - 1;
			stateConfVector[0] = STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2;
			stateConfVectorPosition = 0;
		} 
	}
}

/* The reactions of state EQUIPE_2. */
void IA::react_STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2() {
	/* The reactions of state EQUIPE_2. */
	effect_lr0();
	if (iface.EV_Tirette_raised) { 
		/* Default exit sequence for state ATTENTE_DEBUT_MATCH */
		/* Default exit sequence for region CHOIX_EQUIPE */
		/* Handle exit of all possible states (of CHOIX_EQUIPE) at position 0... */
		switch(stateConfVector[ 0 ]) {
			case STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1 : {
				/* Default exit sequence for state EQUIPE_1 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2 : {
				/* Default exit sequence for state EQUIPE_2 */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* Default exit sequence for region APPRENTISSAGE_ACTIONNEUR */
		/* Handle exit of all possible states (of APPRENTISSAGE_ACTIONNEUR) at position 1... */
		switch(stateConfVector[ 1 ]) {
			case STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_INIT : {
				/* Default exit sequence for state INIT */
				stateConfVector[1] = IA_last_state;
				stateConfVectorPosition = 1;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state MATCH */
		/* 'default' enter sequence for region MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state INIT_MATCH */
		/* Entry action for state 'INIT_MATCH'. */
		iface.tempsMatch = 0;
		stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH;
		stateConfVectorPosition = 0;
	}  else {
		if (iface.IN_Couleur == iface.JAUNE) { 
			/* Default exit sequence for state EQUIPE_2 */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* 'default' enter sequence for state EQUIPE_1 */
			/* Entry action for state 'EQUIPE_1'. */
			ifaceInternalSCI.Couleur = iface.JAUNE;
			ifaceInternalSCI.invMouv = 1;
			stateConfVector[0] = STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1;
			stateConfVectorPosition = 0;
		} 
	}
}

/* The reactions of state INIT. */
void IA::react_STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_INIT() {
}

/* The reactions of state PREMIER_PAS. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_PREMIER_PAS() {
	/* The reactions of state PREMIER_PAS. */
	effect_lr0();
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te)) { 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ]) {
			case STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_PREMIER_PAS : {
				/* Default exit sequence for state PREMIER_PAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_INIT_POS : {
				/* Default exit sequence for state INIT_POS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT : {
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT : {
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH : {
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_ACTIONNEURS */
		/* Entry action for state 'ARRET_ACTIONNEURS'. */
		SCI_Asser_OCB::Manuel(0, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS;
		stateConfVectorPosition = 0;
	}  else {
		if ((iface.IN_Obstacle == 1) && (ifaceInternalSCI.inhibeObstacle == false)) { 
			/* Default exit sequence for state HOMOLOGATION */
			/* Default exit sequence for region HOMOLOGATION_REGION */
			/* Handle exit of all possible states (of HOMOLOGATION_REGION) at position 0... */
			switch(stateConfVector[ 0 ]) {
				case STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_PREMIER_PAS : {
					/* Default exit sequence for state PREMIER_PAS */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_INIT_POS : {
					/* Default exit sequence for state INIT_POS */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				default: break;
			}
			/* 'default' enter sequence for state EVITEMENT */
			/* Entry action for state 'EVITEMENT'. */
			ifaceInternalSCI.evitementTempo = 0;
			ifaceInternalSCI.evitementEnCours = true;
			/* 'default' enter sequence for region EVITEMENT_REGION */
			/* Default react sequence for initial entry  */
			/* 'default' enter sequence for state ARRET_ROBOT */
			/* Entry action for state 'ARRET_ROBOT'. */
			SCI_Asser_OCB::Manuel(0, 0);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT;
			stateConfVectorPosition = 0;
		}  else {
		}
	}
}

/* The reactions of state INIT_POS. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_INIT_POS() {
	/* The reactions of state INIT_POS. */
	effect_lr0();
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te)) { 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ]) {
			case STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_PREMIER_PAS : {
				/* Default exit sequence for state PREMIER_PAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_INIT_POS : {
				/* Default exit sequence for state INIT_POS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT : {
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT : {
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH : {
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_ACTIONNEURS */
		/* Entry action for state 'ARRET_ACTIONNEURS'. */
		SCI_Asser_OCB::Manuel(0, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS;
		stateConfVectorPosition = 0;
	}  else {
		if ((iface.IN_Obstacle == 1) && (ifaceInternalSCI.inhibeObstacle == false)) { 
			/* Default exit sequence for state HOMOLOGATION */
			/* Default exit sequence for region HOMOLOGATION_REGION */
			/* Handle exit of all possible states (of HOMOLOGATION_REGION) at position 0... */
			switch(stateConfVector[ 0 ]) {
				case STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_PREMIER_PAS : {
					/* Default exit sequence for state PREMIER_PAS */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_INIT_POS : {
					/* Default exit sequence for state INIT_POS */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				default: break;
			}
			/* 'default' enter sequence for state EVITEMENT */
			/* Entry action for state 'EVITEMENT'. */
			ifaceInternalSCI.evitementTempo = 0;
			ifaceInternalSCI.evitementEnCours = true;
			/* 'default' enter sequence for region EVITEMENT_REGION */
			/* Default react sequence for initial entry  */
			/* 'default' enter sequence for state ARRET_ROBOT */
			/* Entry action for state 'ARRET_ROBOT'. */
			SCI_Asser_OCB::Manuel(0, 0);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT;
			stateConfVectorPosition = 0;
		}  else {
			/* Default exit sequence for state INIT_POS */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* 'default' enter sequence for state PREMIER_PAS */
			/* Entry action for state 'PREMIER_PAS'. */
			SCI_Asser_OCB::XYTeta(10, 10, ifaceInternalSCI.PI);
			stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_PREMIER_PAS;
			stateConfVectorPosition = 0;
			historyVector[0] = stateConfVector[0];
		}
	}
}

/* The reactions of state ARRET_ROBOT. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT() {
	/* The reactions of state ARRET_ROBOT. */
	effect_lr0();
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te)) { 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ]) {
			case STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_PREMIER_PAS : {
				/* Default exit sequence for state PREMIER_PAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_INIT_POS : {
				/* Default exit sequence for state INIT_POS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT : {
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT : {
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH : {
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_ACTIONNEURS */
		/* Entry action for state 'ARRET_ACTIONNEURS'. */
		SCI_Asser_OCB::Manuel(0, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS;
		stateConfVectorPosition = 0;
	}  else {
		if ((ifaceInternalSCI.evitementEnCours == false) && (iface.IN_Obstacle == 0)) { 
			/* Default exit sequence for state EVITEMENT */
			/* Default exit sequence for region EVITEMENT_REGION */
			/* Handle exit of all possible states (of EVITEMENT_REGION) at position 0... */
			switch(stateConfVector[ 0 ]) {
				case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT : {
					/* Default exit sequence for state ARRET_ROBOT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT : {
					/* Default exit sequence for state SORTIE_EVITEMENT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				default: break;
			}
			/* Default react sequence for shallow history entry  */
			/* Enter the region with shallow history */
			if (historyVector[0] != IA_last_state) {
				shenseq_SequenceImpl();
			} 
		}  else {
			ifaceInternalSCI.evitementTempo = ifaceInternalSCI.evitementTempo + 1;
			if ((ifaceInternalSCI.evitementTempo > (1 / ifaceInternalSCI.Te))) { 
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
void IA::react_STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT() {
	/* The reactions of state SORTIE_EVITEMENT. */
	effect_lr0();
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te)) { 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ]) {
			case STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_PREMIER_PAS : {
				/* Default exit sequence for state PREMIER_PAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_INIT_POS : {
				/* Default exit sequence for state INIT_POS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT : {
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT : {
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH : {
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_ACTIONNEURS */
		/* Entry action for state 'ARRET_ACTIONNEURS'. */
		SCI_Asser_OCB::Manuel(0, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS;
		stateConfVectorPosition = 0;
	}  else {
		if ((ifaceInternalSCI.evitementEnCours == false) && (iface.IN_Obstacle == 0)) { 
			/* Default exit sequence for state EVITEMENT */
			/* Default exit sequence for region EVITEMENT_REGION */
			/* Handle exit of all possible states (of EVITEMENT_REGION) at position 0... */
			switch(stateConfVector[ 0 ]) {
				case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT : {
					/* Default exit sequence for state ARRET_ROBOT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT : {
					/* Default exit sequence for state SORTIE_EVITEMENT */
					stateConfVector[0] = IA_last_state;
					stateConfVectorPosition = 0;
					break;
				}
				default: break;
			}
			/* Default react sequence for shallow history entry  */
			/* Enter the region with shallow history */
			if (historyVector[0] != IA_last_state) {
				shenseq_SequenceImpl();
			} 
		}  else {
			ifaceInternalSCI.evitementTempo = ifaceInternalSCI.evitementTempo + 1;
		}
	}
}

/* The reactions of state INIT_MATCH. */
void IA::react_STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH() {
	/* The reactions of state INIT_MATCH. */
	effect_lr0();
	if (iface.tempsMatch > (90 / ifaceInternalSCI.Te)) { 
		/* Default exit sequence for state MATCH */
		/* Default exit sequence for region MATCH_REGION */
		/* Handle exit of all possible states (of MATCH_REGION) at position 0... */
		switch(stateConfVector[ 0 ]) {
			case STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_PREMIER_PAS : {
				/* Default exit sequence for state PREMIER_PAS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_INIT_POS : {
				/* Default exit sequence for state INIT_POS */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT : {
				/* Default exit sequence for state ARRET_ROBOT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT : {
				/* Default exit sequence for state SORTIE_EVITEMENT */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			case STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH : {
				/* Default exit sequence for state INIT_MATCH */
				stateConfVector[0] = IA_last_state;
				stateConfVectorPosition = 0;
				break;
			}
			default: break;
		}
		/* 'default' enter sequence for state FIN_MATCH */
		/* 'default' enter sequence for region FIN_MATCH_REGION */
		/* Default react sequence for initial entry  */
		/* 'default' enter sequence for state ARRET_ACTIONNEURS */
		/* Entry action for state 'ARRET_ACTIONNEURS'. */
		SCI_Asser_OCB::Manuel(0, 0);
		stateConfVector[0] = STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS;
		stateConfVectorPosition = 0;
	}  else {
		/* Default exit sequence for state INIT_MATCH */
		stateConfVector[0] = IA_last_state;
		stateConfVectorPosition = 0;
		/* 'default' enter sequence for state INIT_POS */
		/* Entry action for state 'INIT_POS'. */
		SCI_Asser_OCB::setPosition(0, 0, ifaceInternalSCI.PI);
		stateConfVector[0] = STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_INIT_POS;
		stateConfVectorPosition = 0;
		historyVector[0] = stateConfVector[0];
	}
}

/* The reactions of state ARRET_ACTIONNEURS. */
void IA::react_STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS() {
	/* The reactions of state ARRET_ACTIONNEURS. */
	effect_lr0();
}


