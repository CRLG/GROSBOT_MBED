/*! \file CLaBotBox.h
	\brief Classe qui contient la gestion des roues motrices gauche et droite
*/

#ifndef _LABOTBOX_H_
#define _LABOTBOX_H_

#include "MessagerieLaBotBox.h"

//! Enumere les differents etats de la machine d'etat de l'automate.
//! Cet enumere contient toutes les valeurs prises par la machine d'etat de reconstitution des donnees
typedef enum {
  cETAT_INIT = 0,

  // --------------
  cETAT_ERREUR,
  cETAT_PILE_PLEINE,
  // --------------
  cETAT_ID_MSB,
  cETAT_ID_LSB,
  cETAT_DLC,
  cETAT_DATA_0,
  cETAT_DATA_1,
  cETAT_DATA_2,
  cETAT_DATA_3,
  cETAT_DATA_4,
  cETAT_DATA_5,
  cETAT_DATA_6,
  cETAT_DATA_7,
  cETAT_CHECKSUM

} tETATS_RECONST;



//! Codes d'erreurs retournes par le module Reconstitution.
//! La liste des codes d'erreurs partages entre le module Reconstitution (producteur d'un message d'erreur ) et les autres modules consommateurs
typedef enum {
  cERREUR_ENTETE_INCONNU = 0,
  cERREUR_CHECKSUM,
  cERREUR_DLC_INCORRECT
}eERREUR_RECONSTITUTION;






class CLaBotBox{

public :
	CLaBotBox();
	~CLaBotBox();


	// __________________________________________ TRAMES EN RECEPTION	
	//! Reconstitution d'une trame a partir d'informations entrantes
	void Reconstitution(unsigned char data);
	//! Recherche et lance le decodage de la trame arrivee
	void DecodeTrame(tStructTrameLaBotBox *trameRecue);
	//! Initialisation des donnees liees a la reconstitution de la trame
	void Init_Reconstitution(void);
	// Test du checksum
	unsigned char isChecksumTrameCouranteOK(unsigned char CS_attendu);



	// __________________________________________ TRAMES EN EMISSION	
	//! Serialise une trame
	void SerialiseTrame(tStructTrameLaBotBox *trameBrute);

	//! Checksum de trame brut
	unsigned char getCheckSumTrame(tStructTrameLaBotBox *trameBrute);


	// __________________________________________ INSTANCE DE CHAQUE TRAME
	//! Trame
    CTrameLaBotBox_ELECTROBOT_CDE_MOTEURS       m_ELECTROBOT_CDE_MOTEURS;
    CTrameLaBotBox_COMMANDE_MVT_XY              m_COMMANDE_MVT_XY;
    CTrameLaBotBox_ASSERV_RESET                 m_ASSERV_RESET;
    CTrameLaBotBox_AUTOAPPRENTISSAGE_ASSERV     m_AUTOAPPRENTISSAGE_ASSERV;
    CTrameLaBotBox_COMMANDE_REINIT_XY_TETA      m_COMMANDE_REINIT_XY_TETA;
    CTrameLaBotBox_COMMANDE_VITESSE_MVT         m_COMMANDE_VITESSE_MVT;
    CTrameLaBotBox_COMMANDE_REGUL_VITESSE       m_COMMANDE_REGUL_VITESSE;
    CTrameLaBotBox_COMMANDE_DISTANCE_ANGLE      m_COMMANDE_DISTANCE_ANGLE;
    CTrameLaBotBox_COMMANDE_MVT_XY_TETA         m_COMMANDE_MVT_XY_TETA;
    CTrameLaBotBox_ELECTROBOT_CDE_SERVOS        m_ELECTROBOT_CDE_SERVOS;
    CTrameLaBotBox_COMMANDE_MVT_MANUEL          m_COMMANDE_MVT_MANUEL;
    CTrameLaBotBox_ETAT_PID_ASSERVISSEMENT      m_ETAT_PID_ASSERVISSEMENT;
    CTrameLaBotBox_ETAT_ASSERVISSEMENT          m_ETAT_ASSERVISSEMENT;
    CTrameLaBotBox_POSITION_CODEURS             m_POSITION_CODEURS;
    CTrameLaBotBox_POSITION_ABSOLUE_XY_TETA     m_POSITION_ABSOLUE_XY_TETA;
    CTrameLaBotBox_ELECTROBOT_ETAT_CODEURS_1_2  m_ELECTROBOT_ETAT_CODEURS_1_2;
    CTrameLaBotBox_ELECTROBOT_ETAT_TELEMETRES   m_ELECTROBOT_ETAT_TELEMETRES;
    CTrameLaBotBox_ELECTROBOT_ETAT_CODEURS_3_4  m_ELECTROBOT_ETAT_CODEURS_3_4;
    CTrameLaBotBox_ELECTROBOT_ETAT_CAPTEURS_2   m_ELECTROBOT_ETAT_CAPTEURS_2;
    CTrameLaBotBox_ELECTROBOT_ETAT_CAPTEURS_1   m_ELECTROBOT_ETAT_CAPTEURS_1;

private : 
	//! Etat de la machine d'etat de reconstitution
	unsigned char m_etatReconst;
	//! Trame en cours de reconstruction
	tStructTrameLaBotBox m_trameCourante;

};


#endif

