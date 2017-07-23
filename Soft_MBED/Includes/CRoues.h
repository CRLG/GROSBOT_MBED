/*! \file CRoues.h
	\brief Classe qui contient la gestion des roues motrices gauche et droite
*/

#ifndef _ROUES_H_
#define _ROUES_H_

#define FREQ_MOTEUR_ROUES   20000

// -----------------------------
//! Classe de gestion des options d'exécution passees en ligne de commande
class CRoues {
public :
	//! Memorise la commande des moteurs
	float m_cde_roue_G;
	float m_cde_roue_D;

	CRoues();
	~CRoues();

	void AdapteCommandeMoteur_G(float vitesse);
	void AdapteCommandeMoteur_D(float vitesse);
	void AdapteCommandeMoteurs(float vit_G, float vit_D);

	int getCodeurG(void);
	int getCodeurD(void);

	void resetCodeurs(void);

private : 


};


#endif


