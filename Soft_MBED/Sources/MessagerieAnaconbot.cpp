// FICHIER GENERE PAR L'OUTIL MESS2C_robot V1.0
// Date de génération : Wed Dec 14 22:48:43 2011
// PLATEFORME CIBLE : MINIBOT
/*! \file MessagerieAnaconbot.cpp
	\brief Fichier qui contient toutes les classes messageries heritees de la classe CTrameCAN
*/

#include "mbed.h"
#include "RessourcesHardware.h"
#include "CTrameCAN.h"
#include "MessagerieAnaconbot.h"


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrame_DIAG_ULTRASON_SRF08::CTrame_DIAG_ULTRASON_SRF08()
{
  m_trame_brute.ID = ID_DIAG_ULTRASON_SRF08;
  m_trame_brute.DLC = DLC_DIAG_ULTRASON_SRF08;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame DIAG_ULTRASON_SRF08

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameBrute* CTrame_DIAG_ULTRASON_SRF08::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_DIAG_ULTRASON_SRF08; i++) {
    m_trame_brute.Data[i] = 0;
  }

  	// Encode chacun des signaux de la trame
    m_trame_brute.Data[1] |= (unsigned char)( ( (SRF08_NEW_ADRESSE) & 0xFF) );

    m_trame_brute.Data[0] |= (unsigned char)( ( (SRF08_OLD_ADRESSE) & 0xFF) );

	return(&m_trame_brute);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrame_COMMANDE_VITESSE_MVT::CTrame_COMMANDE_VITESSE_MVT()
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
void CTrame_COMMANDE_VITESSE_MVT::Decode(tStructTrameBrute *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   VitesseConsigneAngle = ( ( ((short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[2])) & 0xFF) << 8 );

   VitesseConsigneDist = ( ( ((short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[0])) & 0xFF) << 8 );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrame_ASSERV_DIAG_WR_COMPTEUR_MAX::CTrame_ASSERV_DIAG_WR_COMPTEUR_MAX()
{
  m_trame_brute.ID = ID_ASSERV_DIAG_WR_COMPTEUR_MAX;
  m_trame_brute.DLC = DLC_ASSERV_DIAG_WR_COMPTEUR_MAX;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ASSERV_DIAG_WR_COMPTEUR_MAX

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrame_ASSERV_DIAG_WR_COMPTEUR_MAX::Decode(tStructTrameBrute *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   COMPTEUR_MAX = ( ( ((unsigned short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[0])) & 0xFF) << 8 );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrame_ASSERV_DIAG_WR_SEUIL_CONV_ANGLE::CTrame_ASSERV_DIAG_WR_SEUIL_CONV_ANGLE()
{
  m_trame_brute.ID = ID_ASSERV_DIAG_WR_SEUIL_CONV_ANGLE;
  m_trame_brute.DLC = DLC_ASSERV_DIAG_WR_SEUIL_CONV_ANGLE;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ASSERV_DIAG_WR_SEUIL_CONV_ANGLE

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrame_ASSERV_DIAG_WR_SEUIL_CONV_ANGLE::Decode(tStructTrameBrute *trameRecue)
{
  long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   lDonnee_temp = ( ( ((long)(trameRecue->Data[0])) & 0xFF) )  |  ( ( ((long)(trameRecue->Data[1])) & 0xFF) << 8 )  |  ( ( ((long)(trameRecue->Data[2])) & 0xFF) << 16 )  |  ( ( ((long)(trameRecue->Data[3])) & 0xFF) << 24 );
   SEUIL_CONV_ANGLE = *( (float *) (&lDonnee_temp) ) ;

  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrame_ASSERV_DIAG_WR_SEUIL_CONV_DIST::CTrame_ASSERV_DIAG_WR_SEUIL_CONV_DIST()
{
  m_trame_brute.ID = ID_ASSERV_DIAG_WR_SEUIL_CONV_DIST;
  m_trame_brute.DLC = DLC_ASSERV_DIAG_WR_SEUIL_CONV_DIST;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ASSERV_DIAG_WR_SEUIL_CONV_DIST

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrame_ASSERV_DIAG_WR_SEUIL_CONV_DIST::Decode(tStructTrameBrute *trameRecue)
{
  long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   lDonnee_temp = ( ( ((long)(trameRecue->Data[0])) & 0xFF) )  |  ( ( ((long)(trameRecue->Data[1])) & 0xFF) << 8 )  |  ( ( ((long)(trameRecue->Data[2])) & 0xFF) << 16 )  |  ( ( ((long)(trameRecue->Data[3])) & 0xFF) << 24 );
   SEUIL_CONV_DIST = *( (float *) (&lDonnee_temp) ) ;

  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrame_ASSERV_DIAG_WR_KI_ANGLE::CTrame_ASSERV_DIAG_WR_KI_ANGLE()
{
  m_trame_brute.ID = ID_ASSERV_DIAG_WR_KI_ANGLE;
  m_trame_brute.DLC = DLC_ASSERV_DIAG_WR_KI_ANGLE;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ASSERV_DIAG_WR_KI_ANGLE

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrame_ASSERV_DIAG_WR_KI_ANGLE::Decode(tStructTrameBrute *trameRecue)
{
  long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   lDonnee_temp = ( ( ((long)(trameRecue->Data[0])) & 0xFF) )  |  ( ( ((long)(trameRecue->Data[1])) & 0xFF) << 8 )  |  ( ( ((long)(trameRecue->Data[2])) & 0xFF) << 16 )  |  ( ( ((long)(trameRecue->Data[3])) & 0xFF) << 24 );
   KI_ANGLE = *( (float *) (&lDonnee_temp) ) ;

  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrame_ASSERV_DIAG_WR_KP_ANGLE::CTrame_ASSERV_DIAG_WR_KP_ANGLE()
{
  m_trame_brute.ID = ID_ASSERV_DIAG_WR_KP_ANGLE;
  m_trame_brute.DLC = DLC_ASSERV_DIAG_WR_KP_ANGLE;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ASSERV_DIAG_WR_KP_ANGLE

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrame_ASSERV_DIAG_WR_KP_ANGLE::Decode(tStructTrameBrute *trameRecue)
{
  long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   lDonnee_temp = ( ( ((long)(trameRecue->Data[0])) & 0xFF) )  |  ( ( ((long)(trameRecue->Data[1])) & 0xFF) << 8 )  |  ( ( ((long)(trameRecue->Data[2])) & 0xFF) << 16 )  |  ( ( ((long)(trameRecue->Data[3])) & 0xFF) << 24 );
   KP_ANGLE = *( (float *) (&lDonnee_temp) ) ;

  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrame_ASSERV_DIAG_WR_KI_DISTANCE::CTrame_ASSERV_DIAG_WR_KI_DISTANCE()
{
  m_trame_brute.ID = ID_ASSERV_DIAG_WR_KI_DISTANCE;
  m_trame_brute.DLC = DLC_ASSERV_DIAG_WR_KI_DISTANCE;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ASSERV_DIAG_WR_KI_DISTANCE

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrame_ASSERV_DIAG_WR_KI_DISTANCE::Decode(tStructTrameBrute *trameRecue)
{
  long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   lDonnee_temp = ( ( ((long)(trameRecue->Data[0])) & 0xFF) )  |  ( ( ((long)(trameRecue->Data[1])) & 0xFF) << 8 )  |  ( ( ((long)(trameRecue->Data[2])) & 0xFF) << 16 )  |  ( ( ((long)(trameRecue->Data[3])) & 0xFF) << 24 );
   KI_DISTANCE = *( (float *) (&lDonnee_temp) ) ;

  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrame_ASSERV_DIAG_WR_KP_DISTANCE::CTrame_ASSERV_DIAG_WR_KP_DISTANCE()
{
  m_trame_brute.ID = ID_ASSERV_DIAG_WR_KP_DISTANCE;
  m_trame_brute.DLC = DLC_ASSERV_DIAG_WR_KP_DISTANCE;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ASSERV_DIAG_WR_KP_DISTANCE

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrame_ASSERV_DIAG_WR_KP_DISTANCE::Decode(tStructTrameBrute *trameRecue)
{
  long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   lDonnee_temp = ( ( ((long)(trameRecue->Data[0])) & 0xFF) )  |  ( ( ((long)(trameRecue->Data[1])) & 0xFF) << 8 )  |  ( ( ((long)(trameRecue->Data[2])) & 0xFF) << 16 )  |  ( ( ((long)(trameRecue->Data[3])) & 0xFF) << 24 );
   KP_DISTANCE = *( (float *) (&lDonnee_temp) ) ;

  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrame_ASSERV_DIAG_WR_CDE_MIN::CTrame_ASSERV_DIAG_WR_CDE_MIN()
{
  m_trame_brute.ID = ID_ASSERV_DIAG_WR_CDE_MIN;
  m_trame_brute.DLC = DLC_ASSERV_DIAG_WR_CDE_MIN;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ASSERV_DIAG_WR_CDE_MIN

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrame_ASSERV_DIAG_WR_CDE_MIN::Decode(tStructTrameBrute *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   CDE_MIN = ( ( ((short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[0])) & 0xFF) << 8 );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrame_ASSERV_DIAG_WR_CDE_MAX::CTrame_ASSERV_DIAG_WR_CDE_MAX()
{
  m_trame_brute.ID = ID_ASSERV_DIAG_WR_CDE_MAX;
  m_trame_brute.DLC = DLC_ASSERV_DIAG_WR_CDE_MAX;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ASSERV_DIAG_WR_CDE_MAX

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrame_ASSERV_DIAG_WR_CDE_MAX::Decode(tStructTrameBrute *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   CDE_MAX = ( ( ((short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[0])) & 0xFF) << 8 );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrame_ASSERV_DIAG_READ_PARAM_REP::CTrame_ASSERV_DIAG_READ_PARAM_REP()
{
  m_trame_brute.ID = ID_ASSERV_DIAG_READ_PARAM_REP;
  m_trame_brute.DLC = DLC_ASSERV_DIAG_READ_PARAM_REP;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ASSERV_DIAG_READ_PARAM_REP

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrame_ASSERV_DIAG_READ_PARAM_REP::Decode(tStructTrameBrute *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   DIAG_READ_VALUE_4 = ( ( ((unsigned char)(trameRecue->Data[5])) & 0xFF) );

   DIAG_READ_VALUE_3 = ( ( ((unsigned char)(trameRecue->Data[4])) & 0xFF) );

   DIAG_READ_VALUE_2 = ( ( ((unsigned char)(trameRecue->Data[3])) & 0xFF) );

   DIAG_READ_VALUE_1 = ( ( ((unsigned char)(trameRecue->Data[2])) & 0xFF) );

   DIAG_READ_PARAM = ( ( ((unsigned short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[0])) & 0xFF) << 8 );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrame_ASSERV_DIAG_READ_PARAM_REQ::CTrame_ASSERV_DIAG_READ_PARAM_REQ()
{
  m_trame_brute.ID = ID_ASSERV_DIAG_READ_PARAM_REQ;
  m_trame_brute.DLC = DLC_ASSERV_DIAG_READ_PARAM_REQ;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ASSERV_DIAG_READ_PARAM_REQ

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrame_ASSERV_DIAG_READ_PARAM_REQ::Decode(tStructTrameBrute *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   DIAG_READ_PARAM = ( ( ((unsigned short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[0])) & 0xFF) << 8 );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrame_COMMANDE_SERVOS_MOTEURS::CTrame_COMMANDE_SERVOS_MOTEURS()
{
  m_trame_brute.ID = ID_COMMANDE_SERVOS_MOTEURS;
  m_trame_brute.DLC = DLC_COMMANDE_SERVOS_MOTEURS;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame COMMANDE_SERVOS_MOTEURS

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrame_COMMANDE_SERVOS_MOTEURS::Decode(tStructTrameBrute *trameRecue)
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
CTrame_COMMANDE_MVT_MANUEL::CTrame_COMMANDE_MVT_MANUEL()
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
void CTrame_COMMANDE_MVT_MANUEL::Decode(tStructTrameBrute *trameRecue)
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
CTrame_COMMANDE_DISTANCE_ANGLE::CTrame_COMMANDE_DISTANCE_ANGLE()
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
void CTrame_COMMANDE_DISTANCE_ANGLE::Decode(tStructTrameBrute *trameRecue)
{
  long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   lDonnee_temp = ( ( ((long)(trameRecue->Data[4])) & 0xFF) )  |  ( ( ((long)(trameRecue->Data[5])) & 0xFF) << 8 )  |  ( ( ((long)(trameRecue->Data[6])) & 0xFF) << 16 )  |  ( ( ((long)(trameRecue->Data[7])) & 0xFF) << 24 );
   angle_consigne = *( (float *) (&lDonnee_temp) ) ;
   lDonnee_temp = ( ( ((long)(trameRecue->Data[0])) & 0xFF) )  |  ( ( ((long)(trameRecue->Data[1])) & 0xFF) << 8 )  |  ( ( ((long)(trameRecue->Data[2])) & 0xFF) << 16 )  |  ( ( ((long)(trameRecue->Data[3])) & 0xFF) << 24 );
   distance_consigne = *( (float *) (&lDonnee_temp) ) ;

  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrame_COMMANDE_MVT_XY::CTrame_COMMANDE_MVT_XY()
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
void CTrame_COMMANDE_MVT_XY::Decode(tStructTrameBrute *trameRecue)
{
  long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   lDonnee_temp = ( ( ((long)(trameRecue->Data[4])) & 0xFF) )  |  ( ( ((long)(trameRecue->Data[5])) & 0xFF) << 8 )  |  ( ( ((long)(trameRecue->Data[6])) & 0xFF) << 16 )  |  ( ( ((long)(trameRecue->Data[7])) & 0xFF) << 24 );
   consigne_Y = *( (float *) (&lDonnee_temp) ) ;
   lDonnee_temp = ( ( ((long)(trameRecue->Data[0])) & 0xFF) )  |  ( ( ((long)(trameRecue->Data[1])) & 0xFF) << 8 )  |  ( ( ((long)(trameRecue->Data[2])) & 0xFF) << 16 )  |  ( ( ((long)(trameRecue->Data[3])) & 0xFF) << 24 );
   consigne_X = *( (float *) (&lDonnee_temp) ) ;

  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrame_ETAT_PID_ANGLE::CTrame_ETAT_PID_ANGLE()
{
  m_trame_brute.ID = ID_ETAT_PID_ANGLE;
  m_trame_brute.DLC = DLC_ETAT_PID_ANGLE;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ETAT_PID_ANGLE

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameBrute* CTrame_ETAT_PID_ANGLE::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ETAT_PID_ANGLE; i++) {
    m_trame_brute.Data[i] = 0;
  }

  	// Encode chacun des signaux de la trame
    m_trame_brute.Data[4] |= (unsigned char)( ( ((*((long *)(&int_terme_angle)))) & 0xFF) );
    m_trame_brute.Data[5] |= (unsigned char)( ( ((*((long *)(&int_terme_angle))) >> 8) & 0xFF) );
    m_trame_brute.Data[6] |= (unsigned char)( ( ((*((long *)(&int_terme_angle))) >> 16) & 0xFF) );
    m_trame_brute.Data[7] |= (unsigned char)( ( ((*((long *)(&int_terme_angle))) >> 24) & 0xFF) );

    m_trame_brute.Data[0] |= (unsigned char)( ( ((*((long *)(&cde_angle)))) & 0xFF) );
    m_trame_brute.Data[1] |= (unsigned char)( ( ((*((long *)(&cde_angle))) >> 8) & 0xFF) );
    m_trame_brute.Data[2] |= (unsigned char)( ( ((*((long *)(&cde_angle))) >> 16) & 0xFF) );
    m_trame_brute.Data[3] |= (unsigned char)( ( ((*((long *)(&cde_angle))) >> 24) & 0xFF) );

	return(&m_trame_brute);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrame_ETAT_PID_DISTANCE::CTrame_ETAT_PID_DISTANCE()
{
  m_trame_brute.ID = ID_ETAT_PID_DISTANCE;
  m_trame_brute.DLC = DLC_ETAT_PID_DISTANCE;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ETAT_PID_DISTANCE

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameBrute* CTrame_ETAT_PID_DISTANCE::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ETAT_PID_DISTANCE; i++) {
    m_trame_brute.Data[i] = 0;
  }

  	// Encode chacun des signaux de la trame
    m_trame_brute.Data[4] |= (unsigned char)( ( ((*((long *)(&int_terme_distance)))) & 0xFF) );
    m_trame_brute.Data[5] |= (unsigned char)( ( ((*((long *)(&int_terme_distance))) >> 8) & 0xFF) );
    m_trame_brute.Data[6] |= (unsigned char)( ( ((*((long *)(&int_terme_distance))) >> 16) & 0xFF) );
    m_trame_brute.Data[7] |= (unsigned char)( ( ((*((long *)(&int_terme_distance))) >> 24) & 0xFF) );

    m_trame_brute.Data[0] |= (unsigned char)( ( ((*((long *)(&cde_distance)))) & 0xFF) );
    m_trame_brute.Data[1] |= (unsigned char)( ( ((*((long *)(&cde_distance))) >> 8) & 0xFF) );
    m_trame_brute.Data[2] |= (unsigned char)( ( ((*((long *)(&cde_distance))) >> 16) & 0xFF) );
    m_trame_brute.Data[3] |= (unsigned char)( ( ((*((long *)(&cde_distance))) >> 24) & 0xFF) );

	return(&m_trame_brute);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrame_ETAT_ASSERVISSEMENT::CTrame_ETAT_ASSERVISSEMENT()
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
tStructTrameBrute* CTrame_ETAT_ASSERVISSEMENT::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ETAT_ASSERVISSEMENT; i++) {
    m_trame_brute.Data[i] = 0;
  }

  	// Encode chacun des signaux de la trame
    m_trame_brute.Data[5] |= (unsigned char)( ( (cde_moteur_D) & 0xFF) );
    m_trame_brute.Data[4] |= (unsigned char)( ( (cde_moteur_D >> 8) & 0xFF) );

    m_trame_brute.Data[3] |= (unsigned char)( ( (cde_moteur_G) & 0xFF) );
    m_trame_brute.Data[2] |= (unsigned char)( ( (cde_moteur_G >> 8) & 0xFF) );

    m_trame_brute.Data[0] |= (unsigned char)( ( (Convergence) & 0xFF) );

	return(&m_trame_brute);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrame_POSITION_CODEURS::CTrame_POSITION_CODEURS()
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
tStructTrameBrute* CTrame_POSITION_CODEURS::Encode(void)
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
CTrame_POSITION_ABSOLUE_TETA::CTrame_POSITION_ABSOLUE_TETA()
{
  m_trame_brute.ID = ID_POSITION_ABSOLUE_TETA;
  m_trame_brute.DLC = DLC_POSITION_ABSOLUE_TETA;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame POSITION_ABSOLUE_TETA

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameBrute* CTrame_POSITION_ABSOLUE_TETA::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_POSITION_ABSOLUE_TETA; i++) {
    m_trame_brute.Data[i] = 0;
  }

  	// Encode chacun des signaux de la trame
    m_trame_brute.Data[0] |= (unsigned char)( ( ((*((long *)(&teta_pos)))) & 0xFF) );
    m_trame_brute.Data[1] |= (unsigned char)( ( ((*((long *)(&teta_pos))) >> 8) & 0xFF) );
    m_trame_brute.Data[2] |= (unsigned char)( ( ((*((long *)(&teta_pos))) >> 16) & 0xFF) );
    m_trame_brute.Data[3] |= (unsigned char)( ( ((*((long *)(&teta_pos))) >> 24) & 0xFF) );

	return(&m_trame_brute);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrame_POSITION_ABSOLUE_XY::CTrame_POSITION_ABSOLUE_XY()
{
  m_trame_brute.ID = ID_POSITION_ABSOLUE_XY;
  m_trame_brute.DLC = DLC_POSITION_ABSOLUE_XY;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame POSITION_ABSOLUE_XY

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameBrute* CTrame_POSITION_ABSOLUE_XY::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_POSITION_ABSOLUE_XY; i++) {
    m_trame_brute.Data[i] = 0;
  }

  	// Encode chacun des signaux de la trame
    m_trame_brute.Data[4] |= (unsigned char)( ( ((*((long *)(&y_pos)))) & 0xFF) );
    m_trame_brute.Data[5] |= (unsigned char)( ( ((*((long *)(&y_pos))) >> 8) & 0xFF) );
    m_trame_brute.Data[6] |= (unsigned char)( ( ((*((long *)(&y_pos))) >> 16) & 0xFF) );
    m_trame_brute.Data[7] |= (unsigned char)( ( ((*((long *)(&y_pos))) >> 24) & 0xFF) );

    m_trame_brute.Data[0] |= (unsigned char)( ( ((*((long *)(&x_pos)))) & 0xFF) );
    m_trame_brute.Data[1] |= (unsigned char)( ( ((*((long *)(&x_pos))) >> 8) & 0xFF) );
    m_trame_brute.Data[2] |= (unsigned char)( ( ((*((long *)(&x_pos))) >> 16) & 0xFF) );
    m_trame_brute.Data[3] |= (unsigned char)( ( ((*((long *)(&x_pos))) >> 24) & 0xFF) );

	return(&m_trame_brute);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrame_ETAT_CAPTEURS_SPECIAUX::CTrame_ETAT_CAPTEURS_SPECIAUX()
{
  m_trame_brute.ID = ID_ETAT_CAPTEURS_SPECIAUX;
  m_trame_brute.DLC = DLC_ETAT_CAPTEURS_SPECIAUX;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ETAT_CAPTEURS_SPECIAUX

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameBrute* CTrame_ETAT_CAPTEURS_SPECIAUX::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ETAT_CAPTEURS_SPECIAUX; i++) {
    m_trame_brute.Data[i] = 0;
  }

  	// Encode chacun des signaux de la trame
    m_trame_brute.Data[7] |= (unsigned char)( ( (ULTRASON_8) & 0xFF) );

    m_trame_brute.Data[6] |= (unsigned char)( ( (ULTRASON_7) & 0xFF) );

    m_trame_brute.Data[5] |= (unsigned char)( ( (ULTRASON_6) & 0xFF) );

    m_trame_brute.Data[4] |= (unsigned char)( ( (ULTRASON_5) & 0xFF) );

    m_trame_brute.Data[3] |= (unsigned char)( ( (ULTRASON_4) & 0xFF) );

    m_trame_brute.Data[2] |= (unsigned char)( ( (ULTRASON_3) & 0xFF) );

    m_trame_brute.Data[1] |= (unsigned char)( ( (ULTRASON_2) & 0xFF) );

    m_trame_brute.Data[0] |= (unsigned char)( ( (ULTRASON_1) & 0xFF) );

	return(&m_trame_brute);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrame_ETAT_CAPTEURS_TOR::CTrame_ETAT_CAPTEURS_TOR()
{
  m_trame_brute.ID = ID_ETAT_CAPTEURS_TOR;
  m_trame_brute.DLC = DLC_ETAT_CAPTEURS_TOR;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ETAT_CAPTEURS_TOR

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameBrute* CTrame_ETAT_CAPTEURS_TOR::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ETAT_CAPTEURS_TOR; i++) {
    m_trame_brute.Data[i] = 0;
  }

  	// Encode chacun des signaux de la trame
    m_trame_brute.Data[1] |= (unsigned char)( ( (IOB7_J30) & 0x1) << 7 );

    m_trame_brute.Data[1] |= (unsigned char)( ( (IOB6_J30) & 0x1) << 6 );

    m_trame_brute.Data[1] |= (unsigned char)( ( (IOB5_J14) & 0x1) << 5 );

    m_trame_brute.Data[1] |= (unsigned char)( ( (IOB4_J14) & 0x1) << 4 );

    m_trame_brute.Data[1] |= (unsigned char)( ( (IOB3_J14) & 0x1) << 3 );

    m_trame_brute.Data[1] |= (unsigned char)( ( (IOB2_J13) & 0x1) << 2 );

    m_trame_brute.Data[1] |= (unsigned char)( ( (IOB1_J13) & 0x1) << 1 );

    m_trame_brute.Data[1] |= (unsigned char)( ( (IOB0_J13) & 0x1) );

    m_trame_brute.Data[0] |= (unsigned char)( ( (IOA7_J12) & 0x1) << 7 );

    m_trame_brute.Data[0] |= (unsigned char)( ( (IOA6_J12) & 0x1) << 6 );

    m_trame_brute.Data[0] |= (unsigned char)( ( (IOA5_J12) & 0x1) << 5 );

    m_trame_brute.Data[0] |= (unsigned char)( ( (IOA4_J6) & 0x1) << 4 );

    m_trame_brute.Data[0] |= (unsigned char)( ( (IOA3_J5) & 0x1) << 3 );

    m_trame_brute.Data[0] |= (unsigned char)( ( (IOA2_J4) & 0x1) << 2 );

    m_trame_brute.Data[0] |= (unsigned char)( ( (IOA1_J3) & 0x1) << 1 );

    m_trame_brute.Data[0] |= (unsigned char)( ( (IOA0_J2) & 0x1) );

	return(&m_trame_brute);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrame_ETAT_CAPTEURS_ANA::CTrame_ETAT_CAPTEURS_ANA()
{
  m_trame_brute.ID = ID_ETAT_CAPTEURS_ANA;
  m_trame_brute.DLC = DLC_ETAT_CAPTEURS_ANA;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ETAT_CAPTEURS_ANA

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameBrute* CTrame_ETAT_CAPTEURS_ANA::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ETAT_CAPTEURS_ANA; i++) {
    m_trame_brute.Data[i] = 0;
  }

  	// Encode chacun des signaux de la trame
    m_trame_brute.Data[7] |= (unsigned char)( ( (Eana7_J29) & 0xFF) );

    m_trame_brute.Data[6] |= (unsigned char)( ( (Eana6_J28) & 0xFF) );

    m_trame_brute.Data[5] |= (unsigned char)( ( (Eana5_J23) & 0xFF) );

    m_trame_brute.Data[4] |= (unsigned char)( ( (Eana4_J27) & 0xFF) );

    m_trame_brute.Data[3] |= (unsigned char)( ( (Eana3_J26) & 0xFF) );

    m_trame_brute.Data[2] |= (unsigned char)( ( (Eana2_J22) & 0xFF) );

    m_trame_brute.Data[1] |= (unsigned char)( ( (Eana1_J21) & 0xFF) );

    m_trame_brute.Data[0] |= (unsigned char)( ( (Eana0_J20) & 0xFF) );

	return(&m_trame_brute);
}




/*! @} */
