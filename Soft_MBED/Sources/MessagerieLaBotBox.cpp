// FICHIER GENERE PAR L'OUTIL MESS2C_robot V1.0
// Date de génération : Tue May 05 22:19:15 2015
// PLATEFORME CIBLE : MINIBOT
/*! \file MessagerieLaBotBox.cpp
	\brief Fichier qui contient toutes les classes messageries heritees de la classe CTrameCAN
*/

#include "mbed.h"
#include "RessourcesHardware.h"
#include "MessagerieLaBotBox.h"


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ELECTROBOT_CDE_SERVOS_SD20::CTrameLaBotBox_ELECTROBOT_CDE_SERVOS_SD20()
{
  m_trame_brute.ID = ID_ELECTROBOT_CDE_SERVOS_SD20;
  m_trame_brute.DLC = DLC_ELECTROBOT_CDE_SERVOS_SD20;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_CDE_SERVOS_SD20

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_ELECTROBOT_CDE_SERVOS_SD20::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   valeur_commande_sd20 = ( ( ((unsigned short)(trameRecue->Data[4])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[3])) & 0xFF) << 8 );

   commande_sd20 = ( ( ((unsigned short)(trameRecue->Data[2])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[1])) & 0xFF) << 8 );

   num_servo_sd20 = ( ( ((unsigned char)(trameRecue->Data[0])) & 0xFF) );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_CDE_SERVOS_SD20

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameLaBotBox* CTrameLaBotBox_ELECTROBOT_CDE_SERVOS_SD20::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ELECTROBOT_CDE_SERVOS_SD20; i++) {
    m_trame_brute.Data[i] = 0;
  }

  	// Encode chacun des signaux de la trame
    m_trame_brute.Data[4] |= (unsigned char)( ( (valeur_commande_sd20) & 0xFF) );
    m_trame_brute.Data[3] |= (unsigned char)( ( (valeur_commande_sd20 >> 8) & 0xFF) );

    m_trame_brute.Data[2] |= (unsigned char)( ( (commande_sd20) & 0xFF) );
    m_trame_brute.Data[1] |= (unsigned char)( ( (commande_sd20 >> 8) & 0xFF) );

    m_trame_brute.Data[0] |= (unsigned char)( ( (num_servo_sd20) & 0xFF) );

	return(&m_trame_brute);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ELECTROBOT_CDE_SERVOS_AX::CTrameLaBotBox_ELECTROBOT_CDE_SERVOS_AX()
{
  m_trame_brute.ID = ID_ELECTROBOT_CDE_SERVOS_AX;
  m_trame_brute.DLC = DLC_ELECTROBOT_CDE_SERVOS_AX;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_CDE_SERVOS_AX

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_ELECTROBOT_CDE_SERVOS_AX::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   valeur_commande_ax = ( ( ((unsigned short)(trameRecue->Data[4])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[3])) & 0xFF) << 8 );

   commande_ax = ( ( ((unsigned short)(trameRecue->Data[2])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[1])) & 0xFF) << 8 );

   num_servo_ax = ( ( ((unsigned char)(trameRecue->Data[0])) & 0xFF) );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ELECTROBOT_CDE_MOTEURS::CTrameLaBotBox_ELECTROBOT_CDE_MOTEURS()
{
  m_trame_brute.ID = ID_ELECTROBOT_CDE_MOTEURS;
  m_trame_brute.DLC = DLC_ELECTROBOT_CDE_MOTEURS;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_CDE_MOTEURS

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_ELECTROBOT_CDE_MOTEURS::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   cde_moteur_6 = ( ( ((char)(trameRecue->Data[5])) & 0xFF) );

   cde_moteur_5 = ( ( ((char)(trameRecue->Data[4])) & 0xFF) );

   cde_moteur_4 = ( ( ((char)(trameRecue->Data[3])) & 0xFF) );

   cde_moteur_3 = ( ( ((char)(trameRecue->Data[2])) & 0xFF) );

   cde_moteur_2 = ( ( ((char)(trameRecue->Data[1])) & 0xFF) );

   cde_moteur_1 = ( ( ((char)(trameRecue->Data[0])) & 0xFF) );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_COMMANDE_MVT_XY::CTrameLaBotBox_COMMANDE_MVT_XY()
{
  m_trame_brute.ID = ID_COMMANDE_MVT_XY;
  m_trame_brute.DLC = DLC_COMMANDE_MVT_XY;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame COMMANDE_MVT_XY

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_COMMANDE_MVT_XY::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   Y_consigne = ( ( ((short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[2])) & 0xFF) << 8 );

   X_consigne = ( ( ((short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[0])) & 0xFF) << 8 );

   Type_mouvement = ( ( ((unsigned char)(trameRecue->Data[4])) & 0xFF) );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ASSERV_RESET::CTrameLaBotBox_ASSERV_RESET()
{
  m_trame_brute.ID = ID_ASSERV_RESET;
  m_trame_brute.DLC = DLC_ASSERV_RESET;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ASSERV_RESET

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_ASSERV_RESET::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   SECURITE_RESET = ( ( ((unsigned char)(trameRecue->Data[0])) & 0xFF) );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_AUTOAPPRENTISSAGE_ASSERV::CTrameLaBotBox_AUTOAPPRENTISSAGE_ASSERV()
{
  m_trame_brute.ID = ID_AUTOAPPRENTISSAGE_ASSERV;
  m_trame_brute.DLC = DLC_AUTOAPPRENTISSAGE_ASSERV;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame AUTOAPPRENTISSAGE_ASSERV

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_AUTOAPPRENTISSAGE_ASSERV::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   Type_autoapprentissage = ( ( ((unsigned char)(trameRecue->Data[0])) & 0xFF) );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_COMMANDE_REINIT_XY_TETA::CTrameLaBotBox_COMMANDE_REINIT_XY_TETA()
{
  m_trame_brute.ID = ID_COMMANDE_REINIT_XY_TETA;
  m_trame_brute.DLC = DLC_COMMANDE_REINIT_XY_TETA;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame COMMANDE_REINIT_XY_TETA

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_COMMANDE_REINIT_XY_TETA::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   reinit_teta_pos = ( ( ((short)(trameRecue->Data[5])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[4])) & 0xFF) << 8 );

   reinit_y_pos = ( ( ((short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[2])) & 0xFF) << 8 );

   reinit_x_pos = ( ( ((short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[0])) & 0xFF) << 8 );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_COMMANDE_VITESSE_MVT::CTrameLaBotBox_COMMANDE_VITESSE_MVT()
{
  m_trame_brute.ID = ID_COMMANDE_VITESSE_MVT;
  m_trame_brute.DLC = DLC_COMMANDE_VITESSE_MVT;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame COMMANDE_VITESSE_MVT

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_COMMANDE_VITESSE_MVT::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   indice_sportivite_decel = ( ( ((unsigned char)(trameRecue->Data[5])) & 0xFF) );

   indice_sportivite_accel = ( ( ((unsigned char)(trameRecue->Data[4])) & 0xFF) );

   vitesse_rotation_max = ( ( ((unsigned short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[2])) & 0xFF) << 8 );

   vitesse_avance_max = ( ( ((unsigned short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[0])) & 0xFF) << 8 );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_COMMANDE_REGUL_VITESSE::CTrameLaBotBox_COMMANDE_REGUL_VITESSE()
{
  m_trame_brute.ID = ID_COMMANDE_REGUL_VITESSE;
  m_trame_brute.DLC = DLC_COMMANDE_REGUL_VITESSE;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame COMMANDE_REGUL_VITESSE

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_COMMANDE_REGUL_VITESSE::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   consigne_vitesse_roue_D = ( ( ((short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[2])) & 0xFF) << 8 );

   consigne_vitesse_roue_G = ( ( ((short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[0])) & 0xFF) << 8 );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_COMMANDE_DISTANCE_ANGLE::CTrameLaBotBox_COMMANDE_DISTANCE_ANGLE()
{
  m_trame_brute.ID = ID_COMMANDE_DISTANCE_ANGLE;
  m_trame_brute.DLC = DLC_COMMANDE_DISTANCE_ANGLE;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame COMMANDE_DISTANCE_ANGLE

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_COMMANDE_DISTANCE_ANGLE::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   angle_consigne = ( ( ((short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[2])) & 0xFF) << 8 );

   distance_consigne = ( ( ((short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[0])) & 0xFF) << 8 );

   priorite_mouvement = ( ( ((unsigned char)(trameRecue->Data[4])) & 0xFF) );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_COMMANDE_MVT_XY_TETA::CTrameLaBotBox_COMMANDE_MVT_XY_TETA()
{
  m_trame_brute.ID = ID_COMMANDE_MVT_XY_TETA;
  m_trame_brute.DLC = DLC_COMMANDE_MVT_XY_TETA;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame COMMANDE_MVT_XY_TETA

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_COMMANDE_MVT_XY_TETA::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   angle_consigne = ( ( ((short)(trameRecue->Data[5])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[4])) & 0xFF) << 8 );

   Y_consigne = ( ( ((short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[2])) & 0xFF) << 8 );

   X_consigne = ( ( ((short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[0])) & 0xFF) << 8 );

   Type_mouvement = ( ( ((unsigned char)(trameRecue->Data[6])) & 0xFF) );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ASSERV_DIAG_WRITE_PARAM::CTrameLaBotBox_ASSERV_DIAG_WRITE_PARAM()
{
  m_trame_brute.ID = ID_ASSERV_DIAG_WRITE_PARAM;
  m_trame_brute.DLC = DLC_ASSERV_DIAG_WRITE_PARAM;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ASSERV_DIAG_WRITE_PARAM

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_ASSERV_DIAG_WRITE_PARAM::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   ASSERV_DIAG_WRITE_VALUE = ( ( ((short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[2])) & 0xFF) << 8 );

   ASSERV_DIAG_WRITE_PARAM = ( ( ((unsigned short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[0])) & 0xFF) << 8 );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ELECTROBOT_CDE_SERVOS::CTrameLaBotBox_ELECTROBOT_CDE_SERVOS()
{
  m_trame_brute.ID = ID_ELECTROBOT_CDE_SERVOS;
  m_trame_brute.DLC = DLC_ELECTROBOT_CDE_SERVOS;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_CDE_SERVOS

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_ELECTROBOT_CDE_SERVOS::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   PositionServoMoteur2 = ( ( ((unsigned short)(trameRecue->Data[7])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[6])) & 0xFF) << 8 );

   VitesseServoMoteur2 = ( ( ((unsigned char)(trameRecue->Data[5])) & 0xFF) );

   NumeroServoMoteur2 = ( ( ((unsigned char)(trameRecue->Data[4])) & 0xFF) );

   PositionServoMoteur1 = ( ( ((unsigned short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[2])) & 0xFF) << 8 );

   VitesseServoMoteur1 = ( ( ((unsigned char)(trameRecue->Data[1])) & 0xFF) );

   NumeroServoMoteur1 = ( ( ((unsigned char)(trameRecue->Data[0])) & 0xFF) );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_COMMANDE_MVT_MANUEL::CTrameLaBotBox_COMMANDE_MVT_MANUEL()
{
  m_trame_brute.ID = ID_COMMANDE_MVT_MANUEL;
  m_trame_brute.DLC = DLC_COMMANDE_MVT_MANUEL;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame COMMANDE_MVT_MANUEL

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_COMMANDE_MVT_MANUEL::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   PuissanceMotD = ( ( ((short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[2])) & 0xFF) << 8 );

   PuissanceMotG = ( ( ((short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[0])) & 0xFF) << 8 );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ETAT_PID_ASSERVISSEMENT::CTrameLaBotBox_ETAT_PID_ASSERVISSEMENT()
{
  m_trame_brute.ID = ID_ETAT_PID_ASSERVISSEMENT;
  m_trame_brute.DLC = DLC_ETAT_PID_ASSERVISSEMENT;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ETAT_PID_ASSERVISSEMENT

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameLaBotBox* CTrameLaBotBox_ETAT_PID_ASSERVISSEMENT::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ETAT_PID_ASSERVISSEMENT; i++) {
    m_trame_brute.Data[i] = 0;
  }

  	// Encode chacun des signaux de la trame
    m_trame_brute.Data[7] |= (unsigned char)( ( (consigne_vitesse_rotation_filt) & 0xFF) );
    m_trame_brute.Data[6] |= (unsigned char)( ( (consigne_vitesse_rotation_filt >> 8) & 0xFF) );

    m_trame_brute.Data[5] |= (unsigned char)( ( (vitesse_rotation_robot_filt) & 0xFF) );
    m_trame_brute.Data[4] |= (unsigned char)( ( (vitesse_rotation_robot_filt >> 8) & 0xFF) );

    m_trame_brute.Data[3] |= (unsigned char)( ( (consigne_vitesse_avance_filt) & 0xFF) );
    m_trame_brute.Data[2] |= (unsigned char)( ( (consigne_vitesse_avance_filt >> 8) & 0xFF) );

    m_trame_brute.Data[1] |= (unsigned char)( ( (vitesse_avance_robot_filt) & 0xFF) );
    m_trame_brute.Data[0] |= (unsigned char)( ( (vitesse_avance_robot_filt >> 8) & 0xFF) );

	return(&m_trame_brute);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ETAT_ASSERVISSEMENT::CTrameLaBotBox_ETAT_ASSERVISSEMENT()
{
  m_trame_brute.ID = ID_ETAT_ASSERVISSEMENT;
  m_trame_brute.DLC = DLC_ETAT_ASSERVISSEMENT;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ETAT_ASSERVISSEMENT

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameLaBotBox* CTrameLaBotBox_ETAT_ASSERVISSEMENT::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ETAT_ASSERVISSEMENT; i++) {
    m_trame_brute.Data[i] = 0;
  }

  	// Encode chacun des signaux de la trame
    m_trame_brute.Data[7] |= (unsigned char)( ( (compteur_diag_blocage) & 0xFF) );
    m_trame_brute.Data[6] |= (unsigned char)( ( (compteur_diag_blocage >> 8) & 0xFF) );

    m_trame_brute.Data[5] |= (unsigned char)( ( (ModeAsservissement) & 0xFF) );

    m_trame_brute.Data[3] |= (unsigned char)( ( (cde_moteur_D) & 0xFF) );
    m_trame_brute.Data[2] |= (unsigned char)( ( (cde_moteur_D >> 8) & 0xFF) );

    m_trame_brute.Data[1] |= (unsigned char)( ( (cde_moteur_G) & 0xFF) );
    m_trame_brute.Data[0] |= (unsigned char)( ( (cde_moteur_G >> 8) & 0xFF) );

    m_trame_brute.Data[4] |= (unsigned char)( ( (Convergence) & 0xFF) );

	return(&m_trame_brute);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_POSITION_CODEURS::CTrameLaBotBox_POSITION_CODEURS()
{
  m_trame_brute.ID = ID_POSITION_CODEURS;
  m_trame_brute.DLC = DLC_POSITION_CODEURS;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame POSITION_CODEURS

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameLaBotBox* CTrameLaBotBox_POSITION_CODEURS::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_POSITION_CODEURS; i++) {
    m_trame_brute.Data[i] = 0;
  }

  	// Encode chacun des signaux de la trame
    m_trame_brute.Data[1] |= (unsigned char)( ( (PosCodeurG) & 0xFF) );
    m_trame_brute.Data[0] |= (unsigned char)( ( (PosCodeurG >> 8) & 0xFF) );

    m_trame_brute.Data[3] |= (unsigned char)( ( (PosCodeurD) & 0xFF) );
    m_trame_brute.Data[2] |= (unsigned char)( ( (PosCodeurD >> 8) & 0xFF) );

	return(&m_trame_brute);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_POSITION_ABSOLUE_XY_TETA::CTrameLaBotBox_POSITION_ABSOLUE_XY_TETA()
{
  m_trame_brute.ID = ID_POSITION_ABSOLUE_XY_TETA;
  m_trame_brute.DLC = DLC_POSITION_ABSOLUE_XY_TETA;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame POSITION_ABSOLUE_XY_TETA

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameLaBotBox* CTrameLaBotBox_POSITION_ABSOLUE_XY_TETA::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_POSITION_ABSOLUE_XY_TETA; i++) {
    m_trame_brute.Data[i] = 0;
  }

  	// Encode chacun des signaux de la trame
    m_trame_brute.Data[5] |= (unsigned char)( ( (teta_pos) & 0xFF) );
    m_trame_brute.Data[4] |= (unsigned char)( ( (teta_pos >> 8) & 0xFF) );

    m_trame_brute.Data[3] |= (unsigned char)( ( (y_pos) & 0xFF) );
    m_trame_brute.Data[2] |= (unsigned char)( ( (y_pos >> 8) & 0xFF) );

    m_trame_brute.Data[1] |= (unsigned char)( ( (x_pos) & 0xFF) );
    m_trame_brute.Data[0] |= (unsigned char)( ( (x_pos >> 8) & 0xFF) );

	return(&m_trame_brute);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ELECTROBOT_ETAT_CODEURS_1_2::CTrameLaBotBox_ELECTROBOT_ETAT_CODEURS_1_2()
{
  m_trame_brute.ID = ID_ELECTROBOT_ETAT_CODEURS_1_2;
  m_trame_brute.DLC = DLC_ELECTROBOT_ETAT_CODEURS_1_2;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_ETAT_CODEURS_1_2

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameLaBotBox* CTrameLaBotBox_ELECTROBOT_ETAT_CODEURS_1_2::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ELECTROBOT_ETAT_CODEURS_1_2; i++) {
    m_trame_brute.Data[i] = 0;
  }

  	// Encode chacun des signaux de la trame
    m_trame_brute.Data[7] |= (unsigned char)( ( (Codeur_2) & 0xFF) );
    m_trame_brute.Data[6] |= (unsigned char)( ( (Codeur_2 >> 8) & 0xFF) );
    m_trame_brute.Data[5] |= (unsigned char)( ( (Codeur_2 >> 16) & 0xFF) );
    m_trame_brute.Data[4] |= (unsigned char)( ( (Codeur_2 >> 24) & 0xFF) );

    m_trame_brute.Data[3] |= (unsigned char)( ( (Codeur_1) & 0xFF) );
    m_trame_brute.Data[2] |= (unsigned char)( ( (Codeur_1 >> 8) & 0xFF) );
    m_trame_brute.Data[1] |= (unsigned char)( ( (Codeur_1 >> 16) & 0xFF) );
    m_trame_brute.Data[0] |= (unsigned char)( ( (Codeur_1 >> 24) & 0xFF) );

	return(&m_trame_brute);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ELECTROBOT_ETAT_TELEMETRES::CTrameLaBotBox_ELECTROBOT_ETAT_TELEMETRES()
{
  m_trame_brute.ID = ID_ELECTROBOT_ETAT_TELEMETRES;
  m_trame_brute.DLC = DLC_ELECTROBOT_ETAT_TELEMETRES;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_ETAT_TELEMETRES

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameLaBotBox* CTrameLaBotBox_ELECTROBOT_ETAT_TELEMETRES::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ELECTROBOT_ETAT_TELEMETRES; i++) {
    m_trame_brute.Data[i] = 0;
  }

  	// Encode chacun des signaux de la trame
    m_trame_brute.Data[3] |= (unsigned char)( ( (Telemetre4) & 0xFF) );

    m_trame_brute.Data[2] |= (unsigned char)( ( (Telemetre3) & 0xFF) );

    m_trame_brute.Data[1] |= (unsigned char)( ( (Telemetre2) & 0xFF) );

    m_trame_brute.Data[0] |= (unsigned char)( ( (Telemetre1) & 0xFF) );

	return(&m_trame_brute);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ELECTROBOT_ETAT_CODEURS_3_4::CTrameLaBotBox_ELECTROBOT_ETAT_CODEURS_3_4()
{
  m_trame_brute.ID = ID_ELECTROBOT_ETAT_CODEURS_3_4;
  m_trame_brute.DLC = DLC_ELECTROBOT_ETAT_CODEURS_3_4;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_ETAT_CODEURS_3_4

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameLaBotBox* CTrameLaBotBox_ELECTROBOT_ETAT_CODEURS_3_4::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ELECTROBOT_ETAT_CODEURS_3_4; i++) {
    m_trame_brute.Data[i] = 0;
  }

  	// Encode chacun des signaux de la trame
    m_trame_brute.Data[7] |= (unsigned char)( ( (Codeur_4) & 0xFF) );
    m_trame_brute.Data[6] |= (unsigned char)( ( (Codeur_4 >> 8) & 0xFF) );
    m_trame_brute.Data[5] |= (unsigned char)( ( (Codeur_4 >> 16) & 0xFF) );
    m_trame_brute.Data[4] |= (unsigned char)( ( (Codeur_4 >> 24) & 0xFF) );

    m_trame_brute.Data[3] |= (unsigned char)( ( (Codeur_3) & 0xFF) );
    m_trame_brute.Data[2] |= (unsigned char)( ( (Codeur_3 >> 8) & 0xFF) );
    m_trame_brute.Data[1] |= (unsigned char)( ( (Codeur_3 >> 16) & 0xFF) );
    m_trame_brute.Data[0] |= (unsigned char)( ( (Codeur_3 >> 24) & 0xFF) );

	return(&m_trame_brute);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ELECTROBOT_ETAT_CAPTEURS_2::CTrameLaBotBox_ELECTROBOT_ETAT_CAPTEURS_2()
{
  m_trame_brute.ID = ID_ELECTROBOT_ETAT_CAPTEURS_2;
  m_trame_brute.DLC = DLC_ELECTROBOT_ETAT_CAPTEURS_2;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_ETAT_CAPTEURS_2

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameLaBotBox* CTrameLaBotBox_ELECTROBOT_ETAT_CAPTEURS_2::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ELECTROBOT_ETAT_CAPTEURS_2; i++) {
    m_trame_brute.Data[i] = 0;
  }

  	// Encode chacun des signaux de la trame
    m_trame_brute.Data[7] |= (unsigned char)( ( (Etor_PGED1_dsPIC2) & 0x1) << 7 );

    m_trame_brute.Data[7] |= (unsigned char)( ( (Etor_PGED1_dsPIC1) & 0x1) << 6 );

    m_trame_brute.Data[7] |= (unsigned char)( ( (Etor_PGEC1_dsPIC2) & 0x1) << 5 );

    m_trame_brute.Data[7] |= (unsigned char)( ( (Etor_PGEC1_dsPIC1) & 0x1) << 4 );

    m_trame_brute.Data[7] |= (unsigned char)( ( (Etor_Codeur4_B) & 0x1) << 3 );

    m_trame_brute.Data[7] |= (unsigned char)( ( (Etor_Codeur4_A) & 0x1) << 2 );

    m_trame_brute.Data[7] |= (unsigned char)( ( (Etor_Codeur3_B) & 0x1) << 1 );

    m_trame_brute.Data[7] |= (unsigned char)( ( (Etor_Codeur3_A) & 0x1) );

    m_trame_brute.Data[6] |= (unsigned char)( ( (Etor_CAN_TX) & 0x1) << 7 );

    m_trame_brute.Data[6] |= (unsigned char)( ( (Etor_CAN_RX) & 0x1) << 6 );

    m_trame_brute.Data[6] |= (unsigned char)( ( (Etor6) & 0x1) << 5 );

    m_trame_brute.Data[6] |= (unsigned char)( ( (Etor5) & 0x1) << 4 );

    m_trame_brute.Data[6] |= (unsigned char)( ( (Etor4) & 0x1) << 3 );

    m_trame_brute.Data[6] |= (unsigned char)( ( (Etor3) & 0x1) << 2 );

    m_trame_brute.Data[6] |= (unsigned char)( ( (Etor2) & 0x1) << 1 );

    m_trame_brute.Data[6] |= (unsigned char)( ( (Etor1) & 0x1) );

    m_trame_brute.Data[5] |= (unsigned char)( ( (Vbat) & 0xFF) );

    m_trame_brute.Data[4] |= (unsigned char)( ( (Eana13) & 0xFF) );

    m_trame_brute.Data[3] |= (unsigned char)( ( (Eana12) & 0xFF) );

    m_trame_brute.Data[2] |= (unsigned char)( ( (Eana11) & 0xFF) );

    m_trame_brute.Data[1] |= (unsigned char)( ( (Eana10) & 0xFF) );

    m_trame_brute.Data[0] |= (unsigned char)( ( (Eana9) & 0xFF) );

	return(&m_trame_brute);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ELECTROBOT_ETAT_CAPTEURS_1::CTrameLaBotBox_ELECTROBOT_ETAT_CAPTEURS_1()
{
  m_trame_brute.ID = ID_ELECTROBOT_ETAT_CAPTEURS_1;
  m_trame_brute.DLC = DLC_ELECTROBOT_ETAT_CAPTEURS_1;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_ETAT_CAPTEURS_1

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameLaBotBox* CTrameLaBotBox_ELECTROBOT_ETAT_CAPTEURS_1::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ELECTROBOT_ETAT_CAPTEURS_1; i++) {
    m_trame_brute.Data[i] = 0;
  }

  	// Encode chacun des signaux de la trame
    m_trame_brute.Data[7] |= (unsigned char)( ( (Eana8) & 0xFF) );

    m_trame_brute.Data[6] |= (unsigned char)( ( (Eana7) & 0xFF) );

    m_trame_brute.Data[5] |= (unsigned char)( ( (Eana6) & 0xFF) );

    m_trame_brute.Data[4] |= (unsigned char)( ( (Eana5) & 0xFF) );

    m_trame_brute.Data[3] |= (unsigned char)( ( (Eana4) & 0xFF) );

    m_trame_brute.Data[2] |= (unsigned char)( ( (Eana3) & 0xFF) );

    m_trame_brute.Data[1] |= (unsigned char)( ( (Eana2) & 0xFF) );

    m_trame_brute.Data[0] |= (unsigned char)( ( (Eana1) & 0xFF) );

	return(&m_trame_brute);
}



//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ECRAN_ETAT_ECRAN::CTrameLaBotBox_ECRAN_ETAT_ECRAN()
{
  m_trame_brute.ID = ID_ETAT_ECRAN;
  m_trame_brute.DLC = DLC_ETAT_ECRAN;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ECRAN_ETAT_ECRAN

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_ECRAN_ETAT_ECRAN::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   Valeur = ( ( ((short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[2])) & 0xFF) << 8 );

   CodeCommande = ( ( ((unsigned short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[0])) & 0xFF) << 8 );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ECRAN_ETAT_MATCH::CTrameLaBotBox_ECRAN_ETAT_MATCH()
{
  m_trame_brute.ID = ID_ETAT_MATCH;
  m_trame_brute.DLC = DLC_ETAT_MATCH;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ECRAN_ETAT_MATCH

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameLaBotBox* CTrameLaBotBox_ECRAN_ETAT_MATCH::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ETAT_MATCH; i++) {
    m_trame_brute.Data[i] = 0;
  }

  	// Encode chacun des signaux de la trame
    m_trame_brute.Data[2] |= (unsigned char)( ( (ObstacleDetecte) & 0x3) << 6 );

    m_trame_brute.Data[2] |= (unsigned char)( ( (DiagBlocage) & 0x1) << 5 );

    m_trame_brute.Data[2] |= (unsigned char)( ( (ConvergenceAsserv) & 0x1) << 4 );

    m_trame_brute.Data[2] |= (unsigned char)( ( (ModeFonctionnement) & 0xF) );

    m_trame_brute.Data[1] |= (unsigned char)( ( (CouleurEquipe) & 0xFF) );

    m_trame_brute.Data[0] |= (unsigned char)( ( (TempsMatch) & 0xFF) );

	return(&m_trame_brute);
}

//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ETAT_RACK::CTrameLaBotBox_ETAT_RACK()
{
  m_trame_brute.ID = ID_ETAT_RACK;
  m_trame_brute.DLC = DLC_ETAT_RACK;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ETAT_RACK

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameLaBotBox* CTrameLaBotBox_ETAT_RACK::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ETAT_RACK; i++) {
    m_trame_brute.Data[i] = 0;
  }

  	// Encode chacun des signaux de la trame
    m_trame_brute.Data[7] |= (unsigned char)( ( (rack_reserve) & 0xFF) );
    m_trame_brute.Data[6] |= (unsigned char)( ( (rack_reserve >> 8) & 0xFF) );

    m_trame_brute.Data[5] |= (unsigned char)( ( (rack_modeAsservissement) & 0xFF) );

    m_trame_brute.Data[3] |= (unsigned char)( ( (rack_cde_moteur) & 0xFF) );
    m_trame_brute.Data[2] |= (unsigned char)( ( (rack_cde_moteur >> 8) & 0xFF) );

    m_trame_brute.Data[1] |= (unsigned char)( ( (rack_consigne_moteur) & 0xFF) );
    m_trame_brute.Data[0] |= (unsigned char)( ( (rack_consigne_moteur >> 8) & 0xFF) );

    m_trame_brute.Data[4] |= (unsigned char)( ( (rack_convergence) & 0xFF) );

	return(&m_trame_brute);
}

//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ELECTROBOT_COLOR_SENSOR::CTrameLaBotBox_ELECTROBOT_COLOR_SENSOR()
{
  m_trame_brute.ID = ID_ELECTROBOT_COLOR_SENSOR;
  m_trame_brute.DLC = DLC_ELECTROBOT_COLOR_SENSOR;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_COLOR_SENSOR

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameLaBotBox* CTrameLaBotBox_ELECTROBOT_COLOR_SENSOR::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ELECTROBOT_COLOR_SENSOR; i++) {
    m_trame_brute.Data[i] = 0;
  }

	m_trame_brute.Data[1] |= (unsigned char)( ( (R) & 0xFF) );
	m_trame_brute.Data[0] |= (unsigned char)( ( (R >> 8) & 0xFF) );

	m_trame_brute.Data[3] |= (unsigned char)( ( (G) & 0xFF) );
	m_trame_brute.Data[2] |= (unsigned char)( ( (G >> 8) & 0xFF) );

	m_trame_brute.Data[5] |= (unsigned char)( ( (B) & 0xFF) );
	m_trame_brute.Data[4] |= (unsigned char)( ( (B >> 8) & 0xFF) );



	return(&m_trame_brute);
}

//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_CONFIG_PERIODE_TRAME::CTrameLaBotBox_CONFIG_PERIODE_TRAME()
{
  m_trame_brute.ID = ID_CONFIG_PERIODE_TRAME;
  m_trame_brute.DLC = DLC_CONFIG_PERIODE_TRAME;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame CONFIG_PERIODE_TRAME

        - Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_CONFIG_PERIODE_TRAME::Decode(tStructTrameLaBotBox *trameRecue)
{
   // Decode les signaux de la trame
   Periode = ( ( ((short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[2])) & 0xFF) << 8 );

   ID = ( ( ((unsigned short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[0])) & 0xFF) << 8 );


  m_new_trame = true;
  m_nombre_recue++;
}


/*! @} */

