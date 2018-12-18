
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


void IA::init()
{
	for (sc_ushort i = 0; i < maxOrthogonalStates; ++i)
		stateConfVector[i] = IA_last_state;
	
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
	iface.ORANGE = 1;
	iface.VERT = 0;
	iface.BLEU = 2;
	iface.JAUNE = 3;
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
	/* 'default' enter sequence for region main region */
	/* Default react sequence for initial entry  */
	/* 'default' enter sequence for state StateA */
	/* Entry action for state 'StateA'. */
	timer->setTimer(this, (sc_eventid)(&timeEvents[0]), 15 * 1000, false);
	Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 400);
	Application.m_asservissement.CommandeMouvementXY_TETA(100, 20, 0);
	Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp++;
	Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.send();
	stateConfVector[0] = main_region_StateA;
	stateConfVectorPosition = 0;
}

void IA::exit()
{
	/* Default exit sequence for statechart IA */
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of IA.main_region) at position 0... */
	switch(stateConfVector[ 0 ])
	{
		case main_region_StateA :
		{
			/* Default exit sequence for state StateA */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'StateA'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[0]));
			break;
		}
		case main_region_StateB :
		{
			/* Default exit sequence for state StateB */
			stateConfVector[0] = IA_last_state;
			stateConfVectorPosition = 0;
			/* Exit action for state 'StateB'. */
			timer->unsetTimer(this, (sc_eventid)(&timeEvents[1]));
			break;
		}
		default: break;
	}
}

sc_boolean IA::isActive() const
{
	return stateConfVector[0] != IA_last_state;
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
		case main_region_StateA :
		{
			react_main_region_StateA();
			break;
		}
		case main_region_StateB :
		{
			react_main_region_StateB();
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
		case main_region_StateA : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_STATEA] == main_region_StateA
			);
		case main_region_StateB : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_STATEB] == main_region_StateB
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

int32_t IA::DefaultSCI::get_tempsMatch() const
{
	return tempsMatch;
}

int32_t IA::get_tempsMatch() const
{
	return iface.tempsMatch;
}

void IA::DefaultSCI::set_tempsMatch(int32_t value)
{
	tempsMatch = value;
}

void IA::set_tempsMatch(int32_t value)
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

int32_t IA::DefaultSCI::get_oRANGE() const
{
	return ORANGE;
}

int32_t IA::get_oRANGE() const
{
	return iface.ORANGE;
}

void IA::DefaultSCI::set_oRANGE(int32_t value)
{
	ORANGE = value;
}

void IA::set_oRANGE(int32_t value)
{
	iface.ORANGE = value;
}

int32_t IA::DefaultSCI::get_vERT() const
{
	return VERT;
}

int32_t IA::get_vERT() const
{
	return iface.VERT;
}

void IA::DefaultSCI::set_vERT(int32_t value)
{
	VERT = value;
}

void IA::set_vERT(int32_t value)
{
	iface.VERT = value;
}

int32_t IA::DefaultSCI::get_bLEU() const
{
	return BLEU;
}

int32_t IA::get_bLEU() const
{
	return iface.BLEU;
}

void IA::DefaultSCI::set_bLEU(int32_t value)
{
	BLEU = value;
}

void IA::set_bLEU(int32_t value)
{
	iface.BLEU = value;
}

int32_t IA::DefaultSCI::get_jAUNE() const
{
	return JAUNE;
}

int32_t IA::get_jAUNE() const
{
	return iface.JAUNE;
}

void IA::DefaultSCI::set_jAUNE(int32_t value)
{
	JAUNE = value;
}

void IA::set_jAUNE(int32_t value)
{
	iface.JAUNE = value;
}

int32_t IA::InternalSCI::get_couleur() const
{
	return Couleur;
}

void IA::InternalSCI::set_couleur(int32_t value)
{
	Couleur = value;
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

double IA::InternalSCI::get_pI() const
{
	return PI;
}

void IA::InternalSCI::set_pI(double value)
{
	PI = value;
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

/* The reactions of state StateA. */
void IA::react_main_region_StateA()
{
	/* The reactions of state StateA. */
	if (timeEvents[0])
	{ 
		/* Default exit sequence for state StateA */
		stateConfVector[0] = IA_last_state;
		stateConfVectorPosition = 0;
		/* Exit action for state 'StateA'. */
		timer->unsetTimer(this, (sc_eventid)(&timeEvents[0]));
		/* 'default' enter sequence for state StateB */
		/* Entry action for state 'StateB'. */
		timer->setTimer(this, (sc_eventid)(&timeEvents[1]), 15 * 1000, false);
		Application.m_leds.setPattern(PATTERN_K2000, 50);
		Application.m_asservissement.CommandeMouvementXY_TETA(0, 0, 0);
		stateConfVector[0] = main_region_StateB;
		stateConfVectorPosition = 0;
	} 
}

/* The reactions of state StateB. */
void IA::react_main_region_StateB()
{
	/* The reactions of state StateB. */
	if (timeEvents[1])
	{ 
		/* Default exit sequence for state StateB */
		stateConfVector[0] = IA_last_state;
		stateConfVectorPosition = 0;
		/* Exit action for state 'StateB'. */
		timer->unsetTimer(this, (sc_eventid)(&timeEvents[1]));
		/* 'default' enter sequence for state StateA */
		/* Entry action for state 'StateA'. */
		timer->setTimer(this, (sc_eventid)(&timeEvents[0]), 15 * 1000, false);
		Application.m_leds.setPattern(PATTERN_CLIGNO_12_34, 400);
		Application.m_asservissement.CommandeMouvementXY_TETA(100, 20, 0);
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.Timestamp++;
		Application.m_messenger_xbee_ntw.m_database.m_TimestampMatch.send();
		stateConfVector[0] = main_region_StateA;
		stateConfVectorPosition = 0;
	} 
}



