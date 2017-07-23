/*! \file CAsservissementSulfateuse.h
	\brief Classe qui contient l'asservissement vitesse/position du robot
*/

#ifndef _ASSERVISSEMENT_SULFATEUSE_H_
#define _ASSERVISSEMENT_SULFATEUSE_H_


// -----------------------------
//! Classe de gestion des options d'exécution passees en ligne de commande
class CAsservissementSulfateuse {
public :
 
	//! Constructeur / destructeur
	CAsservissementSulfateuse();
	~CAsservissementSulfateuse();

	//! Réinitilise tous les paramètres et valeurs
	void Init(void);	

private : 

 float max(float Inp1, float Inp2);
 float min(float Inp1, float Inp2);
 float SAT(float Inp_max, float Inp_min, float Inp);

};


#endif


