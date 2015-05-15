/*! \file CMatch.h
	\brief Classe qui contient toute l'application
*/

#ifndef _MATCH_H_
#define _MATCH_H_

#include "CMoteurs.h"
#include "CServoMoteurSD20.h"
#include "CServoMoteurAX.h"
//! cet enumere contient les numeros d'attribution des servos pour 2014
/*
typedef enum {
	SERVO_ANCRAGE_FILET=13,
	SERVO_CROCHET_AR,
	SERVO_RETOURNE_FEU,
	SERVO_NERF,
	SERVO_KMAR
} eATTRIBUTION_SERVOS;
*/
	
// -----------------------------
//! Classe de gestion des options d'exécution passees en ligne de commande
class CMatch {
public :
	float m_duree;
	unsigned char m_couleur_equipe;
	unsigned char m_dde_test_actionneurs;
    unsigned char m_choix_strategie;
    float m_old_cde_mot[NBRE_MAX_MOTEURS+1]; // +1 par facilité de lecture du code car l'index utilisé MOTEUR_1, ... commence à 1 et pas à "0"
    float m_old_cde_servo[NBRE_SERVOS_SD20+1]; // +1 (même explication)
	int m_obstacleDetecte;   

	CMatch();
	~CMatch();

	//! Initialise les structures
	void Initialise(void);
	
	//! Execute un pas de calcul
	void step(void);

	//! Debug sur la RS232
	void debug(void);


private : 
  float m_DdeMvtManuel_old;
  float m_DdeMvtDistanceAngle_old;
  float m_DdeMvtXY_old;
  float m_DdeMvtXYTeta_old;
  float m_DdeRecalagePosition_old;
  float m_ResetCodeurAscenseur_old;
  float m_ResetCodeurBarillet_old;

};


#endif

