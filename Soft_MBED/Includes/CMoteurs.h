/*! \file CMoteurs.h
	\brief Classe qui contient la gestion du pilotage des moteurs
*/

#ifndef _MOTEURS_H_
#define _MOTEURS_H_

typedef enum {
  MOTEUR_1 = 1,
  MOTEUR_2,
  MOTEUR_3,
  MOTEUR_4,
  MOTEUR_5,
  MOTEUR_6,
  MOTEUR_7,
  LAST_NUMERO_MOTEUR
}T_MOTEUR;

#define NBRE_MAX_MOTEURS    (LAST_NUMERO_MOTEUR-1)


// -----------------------------
//! Classe de gestion des options d'exécution passees en ligne de commande
class CMoteurs {
public :
 	//! Memorise la commande des moteurs
	float m_cde_mot_1;
	float m_cde_mot_2;
    float m_cde_mot_3;
	float m_cde_mot_4;
	float m_cde_mot_5;
	float m_cde_mot_6;
	float m_cde_mot_7;

	CMoteurs();
	~CMoteurs();

	void CommandeVitesse(unsigned char num_mot, float vitesse);

private : 
	void CommandeVitesse_1(float vitesse);
	void CommandeVitesse_2(float vitesse);
	void CommandeVitesse_3(float vitesse);
	void CommandeVitesse_4(float vitesse);
	void CommandeVitesse_5(float vitesse);
	void CommandeVitesse_6(float vitesse);

};


#endif


