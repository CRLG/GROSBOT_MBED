/*! \file CAnaconbot.h
	\brief Classe qui contient la gestion des roues motrices gauche et droite
*/

#ifndef _ANACONBOT_H_
#define _ANACONBOT_H_

#include "MessagerieAnaconbot.h"

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






class CAnaconbot{

public :
	CAnaconbot();
	~CAnaconbot();


	// __________________________________________ TRAMES EN RECEPTION	
	//! Reconstitution d'une trame a partir d'informations entrantes
	void Reconstitution(unsigned char data);
	//! Recherche et lance le decodage de la trame arrivee
	void DecodeTrame(tStructTrameBrute *trameRecue);
	//! Initialisation des donnees liees a la reconstitution de la trame
	void Init_Reconstitution(void);
	// Test du checksum
	unsigned char isChecksumTrameCouranteOK(unsigned char CS_attendu);



	// __________________________________________ TRAMES EN EMISSION	
	//! Serialise une trame
	void SerialiseTrame(tStructTrameBrute *trameBrute);

	//! Checksum de trame brut
	unsigned char getCheckSumTrame(tStructTrameBrute *trameBrute);


	// __________________________________________ INSTANCE DE CHAQUE TRAME
	//! Trame
	CTrame_COMMANDE_VITESSE_MVT m_COMMANDE_VITESSE_MVT;
	CTrame_ASSERV_DIAG_WR_COMPTEUR_MAX m_ASSERV_DIAG_WR_COMPTEUR_MAX;
	CTrame_ASSERV_DIAG_WR_SEUIL_CONV_ANGLE m_ASSERV_DIAG_WR_SEUIL_CONV_ANGLE;
	CTrame_ASSERV_DIAG_WR_SEUIL_CONV_DIST m_ASSERV_DIAG_WR_SEUIL_CONV_DIST;
	CTrame_ASSERV_DIAG_WR_KI_ANGLE m_ASSERV_DIAG_WR_KI_ANGLE;
	CTrame_ASSERV_DIAG_WR_KP_ANGLE m_ASSERV_DIAG_WR_KP_ANGLE;
	CTrame_ASSERV_DIAG_WR_KI_DISTANCE m_ASSERV_DIAG_WR_KI_DISTANCE;
	CTrame_ASSERV_DIAG_WR_KP_DISTANCE m_ASSERV_DIAG_WR_KP_DISTANCE;
	CTrame_ASSERV_DIAG_WR_CDE_MIN m_ASSERV_DIAG_WR_CDE_MIN;
	CTrame_ASSERV_DIAG_WR_CDE_MAX m_ASSERV_DIAG_WR_CDE_MAX;
	CTrame_ASSERV_DIAG_READ_PARAM_REP m_ASSERV_DIAG_READ_PARAM_REP;
	CTrame_ASSERV_DIAG_READ_PARAM_REQ m_ASSERV_DIAG_READ_PARAM_REQ;
	CTrame_COMMANDE_SERVOS_MOTEURS m_COMMANDE_SERVOS_MOTEURS;
	CTrame_COMMANDE_MVT_MANUEL m_COMMANDE_MVT_MANUEL;
	CTrame_COMMANDE_DISTANCE_ANGLE m_COMMANDE_DISTANCE_ANGLE;
	CTrame_COMMANDE_MVT_XY m_COMMANDE_MVT_XY;
	CTrame_ETAT_PID_ANGLE m_ETAT_PID_ANGLE;
	CTrame_ETAT_PID_DISTANCE m_ETAT_PID_DISTANCE;
	CTrame_ETAT_ASSERVISSEMENT m_ETAT_ASSERVISSEMENT;
	CTrame_POSITION_CODEURS m_POSITION_CODEURS;
	CTrame_POSITION_ABSOLUE_TETA m_POSITION_ABSOLUE_TETA;
	CTrame_POSITION_ABSOLUE_XY m_POSITION_ABSOLUE_XY;
	CTrame_ETAT_CAPTEURS_SPECIAUX m_ETAT_CAPTEURS_SPECIAUX;
	CTrame_ETAT_CAPTEURS_TOR m_ETAT_CAPTEURS_TOR;
	CTrame_ETAT_CAPTEURS_ANA m_ETAT_CAPTEURS_ANA;

private : 
	//! Etat de la machine d'etat de reconstitution
	unsigned char m_etatReconst;
	//! Trame en cours de reconstruction
	tStructTrameBrute m_trameCourante;

};


#endif

