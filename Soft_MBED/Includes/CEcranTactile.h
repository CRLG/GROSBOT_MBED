/*! \file CEcranTactile.h
	\brief Classe qui contient la gestion des roues motrices gauche et droite
*/

#ifndef _ECRAN_TACTILE_H_
#define _ECRAN_TACTILE_H_

#include "MessagerieEcranTactile.h"


//! Enuméré des codes commandes de l'écran vers le MBED
typedef enum {
    // Générique pour toutes les années
    CMDE_INVALIDE = 0,
    CMDE_CHOIX_EQUIPE,
    CMDE_CHOIX_NUMERO_STRATEGIE,
    CMDE_PILOTAGE_MOTEUR_1,
    CMDE_PILOTAGE_MOTEUR_2,
    CMDE_PILOTAGE_MOTEUR_3,
    CMDE_PILOTAGE_MOTEUR_4,
    CMDE_PILOTAGE_MOTEUR_5,
    CMDE_PILOTAGE_MOTEUR_6,
    CMDE_PILOTAGE_SERVO_20,
    CMDE_PILOTAGE_SERVO_19,
    CMDE_PILOTAGE_SERVO_18,
    CMDE_PILOTAGE_SERVO_17,
    CMDE_PILOTAGE_SERVO_16,
    CMDE_PILOTAGE_SERVO_15,
    CMDE_PILOTAGE_SERVO_14,
    CMDE_PILOTAGE_SERVO_13,
    CMDE_RAZ_CODEURS_ROUES,
    CMDE_RAZ_CODEUR_3,
    CMDE_RAZ_CODEUR_4,
    CMDE_RESET_MODELE_SIMULINK_MATCH,
    CMDE_TEST_ACTIONNEURS,
    CMDE_INIT_ACTIONNEURS,

    // Spécifique année 2014
    CMDE_PILOTAGE_ELECTROVANNE,
    CMDE_PILOTAGE_SERVO_NERF,
    CMDE_PILOTAGE_SERVO_KMAR,
    CMDE_PILOTAGE_SERVO_FEU,
    CMDE_PILOTAGE_SERVO_CROCHET_AR,
    CMDE_PILOTAGE_SERVO_ANCRAGE_FILET,
}tCodeCommandeEcran;



//! Enumere les differents etats de la machine d'etat de l'automate.
//! Cet enumere contient toutes les valeurs prises par la machine d'etat de reconstitution des donnees
typedef enum {
  cETAT_ECRAN_INIT = 0,
  cETAT_ECRAN_ID_LSB,
  cETAT_ECRAN_ID_MSB_CHANNEL_DLC,
  cETAT_ECRAN_DLC,
  cETAT_ECRAN_DATA_i,
  cETAT_ECRAN_CHECKSUM
} tETATS_RECONST_ECRAN;



//! Codes d'erreurs retournes par le module Reconstitution.
//! La liste des codes d'erreurs partages entre le module Reconstitution (producteur d'un message d'erreur ) et les autres modules consommateurs
typedef enum {
  cERREUR_ECRAN_ENTETE_INCONNU = 0,
  cERREUR_ECRAN_CHECKSUM,
  cERREUR_ECRAN_DLC_INCORRECT
}eERREUR_ECRAN_RECONSTITUTION;






class CEcranTactile{

public :
	CEcranTactile();
	~CEcranTactile();


	// __________________________________________ TRAMES EN RECEPTION	
	//! Reconstitution d'une trame a partir d'informations entrantes
	void Reconstitution(unsigned char data);
	//! Recherche et lance le decodage de la trame arrivee
	void DecodeTrame(tStructTrameBruteEcran *trameRecue);
	//! Initialisation des donnees liees a la reconstitution de la trame
	void Init_Reconstitution(void);

	// __________________________________________ TRAMES EN EMISSION	
	//! Serialise une trame
	void SerialiseTrame(tStructTrameBruteEcran *trameBrute);

	//! Checksum de trame brut
	unsigned char getChecksum(tStructTrameBruteEcran *trameBrute);


	// __________________________________________ INSTANCE DE CHAQUE TRAME
	//! Trames
	CTrameEcranTactile_ECRAN_ETAT_CAPTEURS_1    m_ETAT_CAPTEURS_1;
	CTrameEcranTactile_ECRAN_ETAT_CAPTEURS_2    m_ETAT_CAPTEURS_2;
	CTrameEcranTactile_ECRAN_ETAT_MATCH         m_ETAT_MATCH;
	CTrameEcranTactile_ECRAN_ETAT_ECRAN         m_ETAT_ECRAN;
    CTrameEcranTactile_ECRAN_ETAT_TELEMETRE     m_ETAT_TELEMETRE;
    CTrameEcranTactile_ECRAN_ETAT_CODEURS_1_2   m_ETAT_CODEURS_1_2;
    CTrameEcranTactile_ECRAN_ETAT_CODEURS_3_4   m_ETAT_CODEURS_3_4;
    CTrameEcranTactile_ECRAN_POSITION_ROBOT     m_POSITION_ROBOT;

private : 
	//! Etat de la machine d'etat de reconstitution
	unsigned char m_etatReconst;
	//! Index du numero de donnee recue
	unsigned char m_numero_data;
	//! Trame en cours de reconstruction
	tStructTrameBruteEcran m_trameCourante;

};


#endif

