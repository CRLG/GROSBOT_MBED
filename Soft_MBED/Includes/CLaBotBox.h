/*! \file CLaBotBox.h
	\brief Classe qui contient la gestion des roues motrices gauche et droite
*/

#ifndef _LABOTBOX_H_
#define _LABOTBOX_H_

#include "MessagerieLaBotBox.h"

//! Enuméré des codes commandes de l'écran vers le MBED
typedef enum {
    // Générique pour toutes les années
    LBB_CMDE_INVALIDE = 0,
    LBB_CMDE_CHOIX_EQUIPE,
    LBB_CMDE_CHOIX_NUMERO_STRATEGIE,
    LBB_CMDE_RAZ_CODEURS_ROUES,
    LBB_CMDE_RAZ_CODEUR_3,
    LBB_CMDE_RAZ_CODEUR_4,
    LBB_CMDE_RESET_STATEFLOW_MATCH,
    LBB_CMDE_TEST_ACTIONNEURS,
    LBB_CMDE_INIT_ACTIONNEURS
}tCodeCommandeLabotBox;

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

//! La liste des codes possibles dans le champ "commande_ax" de la trame ELECTROBOT_CDE_SERVOS_AX
// (enum commun MBED<->LaBotBox)
typedef enum {
  cSERVO_AX_POSITION = 0,
  cSERVO_AX_VITESSE,
  cSERVO_AX_COUPLE,
  cSERVO_AX_CHANGE_ID,
  cSERVO_AX_LED_STATE,
  cSERVO_AX_BUTEE_MIN,
  cSERVO_AX_BUTEE_MAX,
  cSERVO_AX_POSITION_INIT   
}eCOMMANDES_SERVOS_AX;

typedef enum {
  cSERVO_SD20_POSITION = 0,
  cSERVO_SD20_BUTEE_MIN,
  cSERVO_SD20_BUTEE_MAX,
  cSERVO_SD20_POSITION_INIT
}eCOMMANDES_SERVOS_SD20;


//! La liste des codes possibles dans le champ "commande_ax" de la trame ELECTROBOT_CDE_SERVOS_AX
// (enum commun MBED<->LaBotBox)
typedef enum {
   cASSERV_SEUIL_CONV_DIST = 0,
   cASSERV_SEUIL_CONV_ANGLE,
   cASSERV_DIAG_WR_KI_ANGLE,
   cASSERV_DIAG_WR_KP_ANGLE,
   cASSERV_DIAG_WR_KI_DISTANCE,
   cASSERV_DIAG_WR_KP_DISTANCE,
   cASSERV_DIAG_WR_CDE_MIN,
   cASSERV_DIAG_WR_CDE_MAX,
   cASSERV_DIAG_RACK_CDE_MAX,
   cASSERV_DIAG_RACK_K_POSVIT,
   cASSERV_DIAG_RACK_KP,
   cASSERV_DIAG_RACK_KI,
   cASSERV_DIAG_RACK_CONV
}eASSERV_WRITE_PARAM;


class CLaBotBox{

public :
	CLaBotBox();
	~CLaBotBox();

    void Start();
    void Stop();
    void StopRx();
    void StopTx();
    bool isRxEnabled();
    bool isTxEnabled();
    void Execute();
    void IRQ_ReceiveRS232();


	// __________________________________________ TRAMES EN RECEPTION	
	//! Reconstitution d'une trame a partir d'informations entrantes
	void Reconstitution(unsigned char data);
	//! Recherche et lance le decodage de la trame arrivee
	void DecodeTrame(tStructTrameLaBotBox *trameRecue);
	//! Initialisation des donnees liees a la reconstitution de la trame
	void Init_Reconstitution(void);
	// Test du checksum
	unsigned char isChecksumTrameCouranteOK(unsigned char CS_attendu);


    //! Verifie et traite la reception de trames d'Anaconbot
    void CheckReceptionTrame(void);
    //! Envoie les trames vers LABOTBOX
    void SendTramesLaBotBox(void);

	// __________________________________________ TRAMES EN EMISSION	
	//! Serialise une trame
	void SerialiseTrame(tStructTrameLaBotBox *trameBrute);

	//! Checksum de trame brut
	unsigned char getCheckSumTrame(tStructTrameLaBotBox *trameBrute);

    //! Fixe la période de toutes les trames TX d'un seul coup
    void setAllTransmitPeriod(int period_msec);

#define NOMBRE_MAX_TRAMES_LABOTBOX 30
	// __________________________________________ INSTANCE DE CHAQUE TRAME
	//! Trame
    CTrameLaBotBox_ELECTROBOT_CDE_MOTEURS       m_ELECTROBOT_CDE_MOTEURS;
    CTrameLaBotBox_COMMANDE_MVT_XY              m_COMMANDE_MVT_XY;
    CTrameLaBotBox_ASSERV_RESET                 m_ASSERV_RESET;
    CTrameLaBotBox_ASSERV_DIAG_WRITE_PARAM      m_ASSERV_DIAG_WRITE_PARAM;
    CTrameLaBotBox_AUTOAPPRENTISSAGE_ASSERV     m_AUTOAPPRENTISSAGE_ASSERV;
    CTrameLaBotBox_COMMANDE_REINIT_XY_TETA      m_COMMANDE_REINIT_XY_TETA;
    CTrameLaBotBox_COMMANDE_VITESSE_MVT         m_COMMANDE_VITESSE_MVT;
    CTrameLaBotBox_COMMANDE_REGUL_VITESSE       m_COMMANDE_REGUL_VITESSE;
    CTrameLaBotBox_COMMANDE_DISTANCE_ANGLE      m_COMMANDE_DISTANCE_ANGLE;
    CTrameLaBotBox_COMMANDE_MVT_XY_TETA         m_COMMANDE_MVT_XY_TETA;
    CTrameLaBotBox_ELECTROBOT_CDE_SERVOS        m_ELECTROBOT_CDE_SERVOS;
    CTrameLaBotBox_ELECTROBOT_CDE_SERVOS_AX     m_ELECTROBOT_CDE_SERVOS_AX;
    CTrameLaBotBox_ELECTROBOT_CDE_SERVOS_SD20   m_ELECTROBOT_CDE_SERVOS_SD20;
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
    CTrameLaBotBox_ECRAN_ETAT_ECRAN				m_ETAT_ECRAN;
    CTrameLaBotBox_ECRAN_ETAT_MATCH				m_ETAT_MATCH;
    CTrameLaBotBox_ETAT_RACK          			m_ETAT_RACK;
    CTrameLaBotBox_ELECTROBOT_COLOR_SENSOR		m_COLOR_SENSOR;
    CTrameLaBotBox_CONFIG_PERIODE_TRAME         m_CONFIG_PERIODE_TRAME;

private : 
    //! Autorise la réception de données en IRQ en provenance de Labotbox
    bool m_rx_enabled;
    //! Autorise la transmission de données vers Labotbox
    bool m_tx_enabled;
    //! Etat de la machine d'etat de reconstitution
	unsigned char m_etatReconst;
	//! Trame en cours de reconstruction
	tStructTrameLaBotBox m_trameCourante;

    CTrameLaBotBox* m_liste_trames[NOMBRE_MAX_TRAMES_LABOTBOX];
    unsigned int m_nombre_trames;

    //! Crée la liste des trames
    void initListeTrames();
    //! Renvoie le pointeur sur la trame à partir de son identifiant
    CTrameLaBotBox* getTrameFromID(unsigned int ID);

};


#endif


