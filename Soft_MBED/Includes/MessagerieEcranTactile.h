// FICHIER GENERE PAR L'OUTIL MESS2C_robot V1.0
// Date de génération : Thu May 29 18:15:36 2014
// PLATEFORME CIBLE : MINIBOT_ECRAN_TACTILE
/*************************************************************************************/
/*! \file MessagerieEcranTactile.h
    \brief Contient les definition de chaque trame

*/
/*************************************************************************************/
/*! \addtogroup MESSAGERIE_EcranTactile		- Ce module contient les definition des trames sous forme de classes heritees de la classe CTrameCAN
		- Chaque signal de la trame a sa donnee membre dans la classe
		- La classse contient egalement des informations generales comme l'ID, DLC pour
		   que l'applicatif y ai acces si besoin
@{  */ 

#ifndef _MESSAGERIE_EcranTactile_H_
#define _MESSAGERIE_EcranTactile_H_


#include "CTrameEcranTactile.h"


// Enumérés, defines, ...
#define ID_ECRAN_POSITION_ROBOT 0x50
#define ID_ECRAN_ETAT_CODEURS_1_2 0x30
#define ID_ECRAN_ETAT_ECRAN 0x90
#define ID_ECRAN_ETAT_TELEMETRE 0x60
#define ID_ECRAN_ETAT_MATCH 0x40
#define ID_ECRAN_ETAT_CODEURS_3_4 0x31
#define ID_ECRAN_ETAT_CAPTEURS_2 0x20
#define ID_ECRAN_ETAT_CAPTEURS_1 0x10

#define DLC_ECRAN_POSITION_ROBOT 6
#define DLC_ECRAN_ETAT_CODEURS_1_2 8
#define DLC_ECRAN_ETAT_ECRAN 4
#define DLC_ECRAN_ETAT_TELEMETRE 8
#define DLC_ECRAN_ETAT_MATCH 3
#define DLC_ECRAN_ETAT_CODEURS_3_4 8
#define DLC_ECRAN_ETAT_CAPTEURS_2 8
#define DLC_ECRAN_ETAT_CAPTEURS_1 8

#define BRUTE2PHYS_PositionRobot_Teta(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_PositionRobot_Teta(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_PositionRobot_Y(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_PositionRobot_Y(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_PositionRobot_X(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_PositionRobot_X(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Codeur_2(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Codeur_2(val) (long)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Codeur_1(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Codeur_1(val) (long)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Valeur(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Valeur(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_CodeCommande(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_CodeCommande(val) (unsigned short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Telemetre4(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Telemetre4(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Telemetre3(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Telemetre3(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Telemetre2(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Telemetre2(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Telemetre1(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Telemetre1(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_ObstacleDetecte(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_ObstacleDetecte(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_DiagBlocage(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_DiagBlocage(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_ConvergenceAsserv(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_ConvergenceAsserv(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_ModeFonctionnement(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_ModeFonctionnement(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_CouleurEquipe(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_CouleurEquipe(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_TempsMatch(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_TempsMatch(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Codeur_4(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Codeur_4(val) (long)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Codeur_3(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Codeur_3(val) (long)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor_PGED1_dsPIC2(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor_PGED1_dsPIC2(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor_PGED1_dsPIC1(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor_PGED1_dsPIC1(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor_PGEC1_dsPIC2(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor_PGEC1_dsPIC2(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor_PGEC1_dsPIC1(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor_PGEC1_dsPIC1(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor_Codeur4_B(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor_Codeur4_B(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor_Codeur4_A(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor_Codeur4_A(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor_Codeur3_B(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor_Codeur3_B(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor_Codeur3_A(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor_Codeur3_A(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor_CAN_TX(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor_CAN_TX(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor_CAN_RX(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor_CAN_RX(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor6(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor6(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor5(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor5(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor4(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor4(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor3(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor3(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor2(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor2(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor1(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor1(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Vbat(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Vbat(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana13(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana13(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana12(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana12(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana11(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana11(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana10(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana10(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana9(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana9(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana8(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana8(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana7(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana7(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana6(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana6(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana5(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana5(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana4(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana4(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana3(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana3(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana2(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana2(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana1(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana1(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameEcranTactile_ECRAN_POSITION_ROBOT : public CTrameEcranTactile {
public :
	//! Les signaux de la messagerie
	short PositionRobot_Teta;
	short PositionRobot_Y;
	short PositionRobot_X;

	CTrameEcranTactile_ECRAN_POSITION_ROBOT();
	tStructTrameBruteEcran* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameEcranTactile_ECRAN_ETAT_CODEURS_1_2 : public CTrameEcranTactile {
public :
	//! Les signaux de la messagerie
	long Codeur_2;
	long Codeur_1;

	CTrameEcranTactile_ECRAN_ETAT_CODEURS_1_2();
	tStructTrameBruteEcran* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameEcranTactile_ECRAN_ETAT_TELEMETRE : public CTrameEcranTactile {
public :
	//! Les signaux de la messagerie
	unsigned char Telemetre4;
	unsigned char Telemetre3;
	unsigned char Telemetre2;
	unsigned char Telemetre1;

	CTrameEcranTactile_ECRAN_ETAT_TELEMETRE();
	tStructTrameBruteEcran* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameEcranTactile_ECRAN_ETAT_CODEURS_3_4 : public CTrameEcranTactile {
public :
	//! Les signaux de la messagerie
	long Codeur_4;
	long Codeur_3;

	CTrameEcranTactile_ECRAN_ETAT_CODEURS_3_4();
	tStructTrameBruteEcran* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameEcranTactile_ECRAN_ETAT_CAPTEURS_2 : public CTrameEcranTactile {
public :
	//! Les signaux de la messagerie
	unsigned char Etor_PGED1_dsPIC2;
	unsigned char Etor_PGED1_dsPIC1;
	unsigned char Etor_PGEC1_dsPIC2;
	unsigned char Etor_PGEC1_dsPIC1;
	unsigned char Etor_Codeur4_B;
	unsigned char Etor_Codeur4_A;
	unsigned char Etor_Codeur3_B;
	unsigned char Etor_Codeur3_A;
	unsigned char Etor_CAN_TX;
	unsigned char Etor_CAN_RX;
	unsigned char Etor6;
	unsigned char Etor5;
	unsigned char Etor4;
	unsigned char Etor3;
	unsigned char Etor2;
	unsigned char Etor1;
	unsigned char Vbat;
	unsigned char Eana13;
	unsigned char Eana12;
	unsigned char Eana11;
	unsigned char Eana10;
	unsigned char Eana9;

	CTrameEcranTactile_ECRAN_ETAT_CAPTEURS_2();
	tStructTrameBruteEcran* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameEcranTactile_ECRAN_ETAT_CAPTEURS_1 : public CTrameEcranTactile {
public :
	//! Les signaux de la messagerie
	unsigned char Eana8;
	unsigned char Eana7;
	unsigned char Eana6;
	unsigned char Eana5;
	unsigned char Eana4;
	unsigned char Eana3;
	unsigned char Eana2;
	unsigned char Eana1;

	CTrameEcranTactile_ECRAN_ETAT_CAPTEURS_1();
	tStructTrameBruteEcran* Encode(void);
};


// Enumérés, defines, ...
#define ID_ECRAN_ETAT_ECRAN 0x90
#define ID_ECRAN_ETAT_MATCH 0x40

#define DLC_ECRAN_ETAT_ECRAN 4
#define DLC_ECRAN_ETAT_MATCH 3

#define BRUTE2PHYS_Valeur(val) ( ((float)val * (1.000000)) + (0.000000) )
#define PHYS2BRUTE_Valeur(val) (short)( (val - (0.000000)) / (1.000000) )
#define BRUTE2PHYS_CodeCommande(val) ( ((float)val * (1.000000)) + (0.000000) )
#define PHYS2BRUTE_CodeCommande(val) (unsigned short)( (val - (0.000000)) / (1.000000) )
#define BRUTE2PHYS_ObstacleDetecte(val) ( ((float)val * (1.000000)) + (0.000000) )
#define PHYS2BRUTE_ObstacleDetecte(val) (unsigned char)( (val - (0.000000)) / (1.000000) )
#define BRUTE2PHYS_DiagBlocage(val) ( ((float)val * (1.000000)) + (0.000000) )
#define PHYS2BRUTE_DiagBlocage(val) (unsigned char)( (val - (0.000000)) / (1.000000) )
#define BRUTE2PHYS_ConvergenceAsserv(val) ( ((float)val * (1.000000)) + (0.000000) )
#define PHYS2BRUTE_ConvergenceAsserv(val) (unsigned char)( (val - (0.000000)) / (1.000000) )
#define BRUTE2PHYS_ModeFonctionnement(val) ( ((float)val * (1.000000)) + (0.000000) )
#define PHYS2BRUTE_ModeFonctionnement(val) (unsigned char)( (val - (0.000000)) / (1.000000) )
#define BRUTE2PHYS_CouleurEquipe(val) ( ((float)val * (1.000000)) + (0.000000) )
#define PHYS2BRUTE_CouleurEquipe(val) (unsigned char)( (val - (0.000000)) / (1.000000) )
#define BRUTE2PHYS_TempsMatch(val) ( ((float)val * (1.000000)) + (0.000000) )
#define PHYS2BRUTE_TempsMatch(val) (unsigned char)( (val - (0.000000)) / (1.000000) )

// -----------------------------
//! Classe de base pour les trames CAN
class CTrameEcranTactile_ECRAN_ETAT_ECRAN : public CTrameEcranTactile {
public :
	//! Les signaux de la messagerie
	short Valeur;
	unsigned short CodeCommande;

	CTrameEcranTactile_ECRAN_ETAT_ECRAN();
	void Decode(tStructTrameBruteEcran* trameRecue);
};

// -----------------------------
//! Classe de base pour les trames CAN
class CTrameEcranTactile_ECRAN_ETAT_MATCH : public CTrameEcranTactile {
public :
	//! Les signaux de la messagerie
	unsigned char ObstacleDetecte;
	unsigned char DiagBlocage;
	unsigned char ConvergenceAsserv;
	unsigned char ModeFonctionnement;
	unsigned char CouleurEquipe;
	unsigned char TempsMatch;

	CTrameEcranTactile_ECRAN_ETAT_MATCH();
	tStructTrameBruteEcran* Encode(void);
};




#endif
/*! @} */


