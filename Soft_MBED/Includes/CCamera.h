/*! \file CCamera.h
	\brief Classe qui contient la gestion des roues motrices gauche et droite
*/

#ifndef _CAMERA_H
#define _CAMERA_H

#include "MessagerieCamera.h"

//! Enumere les differents etats de la machine d'etat de l'automate.
//! Cet enumere contient toutes les valeurs prises par la machine d'etat de reconstitution des donnees
typedef enum {
  cETAT_CAMERA_INIT = 0,
  cETAT_CAMERA_ID_LSB,
  cETAT_CAMERA_ID_MSB_CHANNEL_DLC,
  cETAT_CAMERA_DLC,
  cETAT_CAMERA_DATA_i,
  cETAT_CAMERA_CHECKSUM
} tETATS_RECONST_CAMERA;



//! Codes d'erreurs retournes par le module Reconstitution.
//! La liste des codes d'erreurs partages entre le module Reconstitution (producteur d'un message d'erreur ) et les autres modules consommateurs
typedef enum {
  cERREUR_CAMERA_ENTETE_INCONNU = 0,
  cERREUR_CAMERA_CHECKSUM,
  cERREUR_CAMERA_DLC_INCORRECT
}eERREUR_CAMERA_RECONSTITUTION;






class CCamera{

public :
	CCamera();
	~CCamera();


	// __________________________________________ TRAMES EN RECEPTION	
	//! Reconstitution d'une trame a partir d'informations entrantes
	void Reconstitution(unsigned char data);
	//! Recherche et lance le decodage de la trame arrivee
	void DecodeTrame(tStructTrameBruteCamera *trameRecue);
	//! Initialisation des donnees liees a la reconstitution de la trame
	void Init_Reconstitution(void);

	// __________________________________________ TRAMES EN EMISSION	
	//! Serialise une trame
	void SerialiseTrame(tStructTrameBruteCamera *trameBrute);

	//! Checksum de trame brut
	unsigned char getChecksum(tStructTrameBruteCamera *trameBrute);


	// __________________________________________ INSTANCE DE CHAQUE TRAME
	//! Trames
	//CTrameCamera_CAMERA_ETAT_CAPTEURS_1    m_ETAT_CAPTEURS_1;
	//CTrameCamera_CAMERA_ETAT_CAPTEURS_2    m_ETAT_CAPTEURS_2;
    CTrameCamera_CAM_MODE_TRACKING_COLOR     m_CAM_MODE_TRACKING_COLOR;
    CTrameCamera_CAM_RESULT_TRACKING         m_CAM_RESULT_TRACKING;

private : 
	//! Etat de la machine d'etat de reconstitution
	unsigned char m_etatReconst;
	//! Index du numero de donnee recue
	unsigned char m_numero_data;
	//! Trame en cours de reconstruction
	tStructTrameBruteCamera m_trameCourante;

};


#endif


