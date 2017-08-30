/*! \file CGlobale.h
	\brief Classe qui contient toute l'application
*/
#ifndef _GLOBALE_H_
#define _GLOBALE_H_

#include "CMatch.h"
#include "CAsservissement.h"
#include "CRoues.h"
#include "CLaBotBox.h"
#include "CCapteurs.h"
#include "CEEPROM.h"
#include "CServoMoteurSD20.h"
#include "CServoMoteurAX.h"
#include "CMoteurs.h"
#include "CCamera.h"
#include "CAsservissementSulfateuse.h"
#include "CAsservissementChariot.h"

typedef enum {
	MODE_AUTONOME = 0,
	MODE_PILOTE_LABOTBOX,
	MODE_PILOTE_TERMINAL
}tModeFonctionnement;

// Pour le séquenceur de tâche
#define PERIODE_TICK	(10)
#define TEMPO_10msec	(10/PERIODE_TICK) 
#define TEMPO_20msec	(20/PERIODE_TICK) 
#define TEMPO_50msec	(50/PERIODE_TICK) 
#define TEMPO_100msec	(100/PERIODE_TICK) 
#define TEMPO_200msec	(200/PERIODE_TICK) 
#define TEMPO_500msec	(500/PERIODE_TICK) 
#define TEMPO_1sec		(1000/PERIODE_TICK) 
#define TEMPO_2sec		(2000/PERIODE_TICK) 
#define TEMPO_5sec		(5000/PERIODE_TICK) 
#define TEMPO_10sec		(10000/PERIODE_TICK) 
#define TEMPO_15sec		(15000/PERIODE_TICK) 



// -----------------------------
//! Classe de gestion des options d'exécution passees en ligne de commande
class CGlobale {
public :
	//! Le mode de fonctionnement (autonome ou piloté via Anaconbot)
	unsigned int ModeFonctionnement;

	//le temps max de gonflage du ballon
	unsigned int TempsMaxGonflage;

	//! Le match �  jouer
	CMatch m_match;
	//! La gestion des roues gauches et droites
	CRoues m_roues;
 	//! La gestion d'Anaconbot
	CLaBotBox m_LaBotBox;
	//! La gestion des capteurs
	CCapteurs m_capteurs;
	//! Le gestionnaire d'EEPROM
	CEEPROM m_eeprom;	
	//! L'asservissement de vitesse/position du robot
	// ATTENTION : l'instance de la classe asservisement doit être mise après l'instance de eeprom car CAsservissement utilise CEEPROM dans son constructeur
	CAsservissement m_asservissement;

	//! La gestion de la caméra
	CCamera m_camera;

	//! Gestion des servos moteurs controlés par le SD20
	CServoMoteurSD20 m_servos_sd20;
	//! Gestion des servos moteurs AX
	CServoMoteurAX m_servos_ax;
 	//! Gestion des moteurs
	CMoteurs m_moteurs;

 	//! Gestion de l'asservissement de la sulfateuse
	CAsservissementSulfateuse m_asservissement_sulfateuse;
	
	//! Gestion de l'asservissement du chariot
	CAsservissementChariot m_asservissement_chariot;

	//debug
	float m_x_debug, m_y_debug, m_teta_debug;

 
	CGlobale();
	~CGlobale();

	//! Point d'entree pour lancer l'application
	void Run(void);


	//!  Le programme d'IRQ qui gere le timer
	void IRQ_Tick_ModeAutonome(void);
	//!  Le programme d'IRQ qui gere le timer
	void IRQ_Tick_ModePiloteLaBotBox(void);
	//!  Le programme d'IRQ qui gere le timer
	void IRQ_Tick_ModePiloteTerminal(void);


private : 
	//! Le tick du sequenceur de tache
	unsigned int Tick;
	
	
	//! Gestion du mode autonome
	void ModeAutonome(void);
	//! Reception RS232 en IRQ
	void ReceiveRS232_Camera(void);
	//! Verifie et traite la reception de trames de la camera
	void CheckReceptionTrameCamera(void);
	//! Envoie les trames vers la caméra
	void SendTramesCamera(void);

	//! Sequenceur de taches en mode autonome
	void SequenceurModeAutonome(void);
	//! Sequenceur de taches en mode pilote par Anaconbot
	void SequenceurModePiloteLaBotBox(void);
	//! Sequenceur de taches en mode pilote par teminal RS232
	void SequenceurModePiloteTerminal(void);
	
	
	
	//! Gestion du mode piloté via Anaconbot
	void ModePiloteLaBotBox(void);
	//! Reception RS232 en IRQ
    //void ReceiveRS232_ModePiloteLaBotBox(void);
	//! Verifie et traite la reception de trames d'Anaconbot
    //void CheckReceptionTrame(void);
	//! Envoie les trames vers LABOTBOX
    //void SendTramesLaBotBox(void);

	//! Gestion du mode piloté par terminal
	void ModePiloteTerminal(void);
 	//! Reception RS232 en IRQ
	void ReceiveRS232_ModePiloteTerminal(void);

};


extern CGlobale Application;


#endif 



