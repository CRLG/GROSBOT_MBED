/*! \file CGlobale.h
	\brief Classe qui contient toute l'application
*/
#ifndef _GLOBALE_H_
#define _GLOBALE_H_

#include "CMatch.h"
#include "CAsservissement.h"
#include "CRoues.h"
#include "CAnaconbot.h"
#include "CCapteurs.h"
#include "CEEPROM.h"
#include "CServoMoteur.h"
#include "CMoteurs.h"
#include "CEcranTactile.h"
#include "CCamera.h"
#include "CAsservissementSulfateuse.h"

typedef enum {
	MODE_AUTONOME = 0,
	MODE_PILOTE_ANACONBOT,
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

	//! Le match à jouer
	CMatch m_match;
	//! La gestion des roues gauches et droites
	CRoues m_roues;
 	//! La gestion d'Anaconbot
	CAnaconbot m_Anaconbot;
	//! La gestion des capteurs
	CCapteurs m_capteurs;
	//! Le gestionnaire d'EEPROM
	CEEPROM m_eeprom;	
	//! L'asservissement de vitesse/position du robot
	// ATTENTION : l'instance de la classe asservisement doit être mise après l'instance de eeprom car CAsservissement utilise CEEPROM dans son constructeur
	CAsservissement m_asservissement;

	//! La gestion de l'ecran tactile
	CEcranTactile m_ecran_tactile;

	//! La gestion de la caméra
	CCamera m_camera;

	//! Gestion des servos moteurs
	CServoMoteur m_Servos;
 	//! Gestion des moteurs
	CMoteurs m_moteurs;

 	//! Gestion de l'asservissement de la sulfateuse
	CAsservissementSulfateuse m_asservissement_sulfateuse;

 
	CGlobale();
	~CGlobale();

	//! Point d'entree pour lancer l'application
	void Run(void);


	//!  Le programme d'IRQ qui gere le timer
	void IRQ_Tick_ModeAutonome(void);
	//!  Le programme d'IRQ qui gere le timer
	void IRQ_Tick_ModePiloteAnaconbot(void);
	//!  Le programme d'IRQ qui gere le timer
	void IRQ_Tick_ModePiloteTerminal(void);


private : 
	//! Le tick du sequenceur de tache
	unsigned int Tick;
	
	
	//! Gestion du mode autonome
	void ModeAutonome(void);
	//! Reception RS232 en IRQ
	void ReceiveRS232_Ecran(void);
	//! Verifie et traite la reception de trames de l'écran
	void CheckReceptionTrameEcran(void);
	//! Envoie les trames vers l'écran
	void SendTramesEcran(void);
	//! Reception RS232 en IRQ
	void ReceiveRS232_Camera(void);
	//! Verifie et traite la reception de trames de la camera
	void CheckReceptionTrameCamera(void);
	//! Envoie les trames vers la caméra
	void SendTramesCamera(void);

	//! Sequenceur de taches en mode autonome
	void SequenceurModeAutonome(void);
	//! Sequenceur de taches en mode pilote par Anaconbot
	void SequenceurModePiloteAnaconbot(void);
	//! Sequenceur de taches en mode pilote par teminal RS232
	void SequenceurModePiloteTerminal(void);
	
	
	
	//! Gestion du mode piloté via Anaconbot
	void ModePiloteAnaconbot(void);
	//! Reception RS232 en IRQ
	void ReceiveRS232_ModePiloteAnaconbot(void);
	//! Verifie et traite la reception de trames d'Anaconbot
	void CheckReceptionTrame(void);
	//! Envoie les trames vers ANACONBOT
	void SendTramesAnaconbot(void);

	//! Gestion du mode piloté par terminal
	void ModePiloteTerminal(void);
 	//! Reception RS232 en IRQ
	void ReceiveRS232_ModePiloteTerminal(void);

};


extern CGlobale Application;


#endif 


