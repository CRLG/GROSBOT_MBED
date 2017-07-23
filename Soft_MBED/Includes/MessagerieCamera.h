// FICHIER GENERE PAR L'OUTIL MESS2C_robot V1.0
// Date de génération : Mon May 12 23:18:17 2014
// PLATEFORME CIBLE : MINIBOT_CAMERA
/*************************************************************************************/
/*! \file MessagerieCamera.h
    \brief Contient les definition de chaque trame

*/
/*************************************************************************************/
/*! \addtogroup MESSAGERIE_Camera		- Ce module contient les definition des trames sous forme de classes heritees de la classe CTrameCAN
		- Chaque signal de la trame a sa donnee membre dans la classe
		- La classse contient egalement des informations generales comme l'ID, DLC pour
		   que l'applicatif y ai acces si besoin
@{  */ 

#ifndef _MESSAGERIE_Camera_H_
#define _MESSAGERIE_Camera_H_


#include "CTrameCamera.h"


// Enumérés, defines, ...
#define ID_CAM_RESULT_TRACKING 0x20
#define ID_CAM_MODE_TRACKING_COLOR 0x10

#define DLC_CAM_RESULT_TRACKING 5
#define DLC_CAM_MODE_TRACKING_COLOR 6

#define BRUTE2PHYS_Etat_Tracking(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etat_Tracking(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Pos_Y(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Pos_Y(val) (unsigned short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Pos_X(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Pos_X(val) (unsigned short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Couleur_R(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Couleur_R(val) (unsigned short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Couleur_G(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Couleur_G(val) (unsigned short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Couleur_B(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Couleur_B(val) (unsigned short)( (val - (0.000000)) / (1.000000) ) 


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameCamera_CAM_RESULT_TRACKING : public CTrameCamera {
public :
	//! Les signaux de la messagerie
	unsigned char Etat_Tracking;
	unsigned short Pos_Y;
	unsigned short Pos_X;

	CTrameCamera_CAM_RESULT_TRACKING();
	void Decode(tStructTrameBruteCamera* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameCamera_CAM_MODE_TRACKING_COLOR : public CTrameCamera {
public :
	//! Les signaux de la messagerie
	unsigned short Couleur_R;
	unsigned short Couleur_G;
	unsigned short Couleur_B;

	CTrameCamera_CAM_MODE_TRACKING_COLOR();
	tStructTrameBruteCamera* Encode(void);
};




#endif
/*! @} */


