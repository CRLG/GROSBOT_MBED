// FICHIER GENERE PAR L'OUTIL MESS2C_robot V1.0
// Date de génération : Thu May 29 18:15:36 2014
// PLATEFORME CIBLE : MINIBOT_ECRAN_TACTILE
/*! \file MessagerieEcranTactile.cpp
	\brief Fichier qui contient toutes les classes messageries heritees de la classe CTrameCAN
*/

#include "mbed.h"
#include "RessourcesHardware.h"
#include "CTrameEcranTactile.h"
#include "MessagerieEcranTactile.h"


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameEcranTactile_ECRAN_POSITION_ROBOT::CTrameEcranTactile_ECRAN_POSITION_ROBOT()
{
  m_trame_brute.ID = ID_ECRAN_POSITION_ROBOT;
  m_trame_brute.DLC = DLC_ECRAN_POSITION_ROBOT;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ECRAN_POSITION_ROBOT

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameBruteEcran* CTrameEcranTactile_ECRAN_POSITION_ROBOT::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ECRAN_POSITION_ROBOT; i++) {
    m_trame_brute.Data[i] = 0;
  }

  	// Encode chacun des signaux de la trame
    m_trame_brute.Data[5] |= (unsigned char)( ( (PositionRobot_Teta) & 0xFF) );
    m_trame_brute.Data[4] |= (unsigned char)( ( (PositionRobot_Teta >> 8) & 0xFF) );

    m_trame_brute.Data[3] |= (unsigned char)( ( (PositionRobot_Y) & 0xFF) );
    m_trame_brute.Data[2] |= (unsigned char)( ( (PositionRobot_Y >> 8) & 0xFF) );

    m_trame_brute.Data[1] |= (unsigned char)( ( (PositionRobot_X) & 0xFF) );
    m_trame_brute.Data[0] |= (unsigned char)( ( (PositionRobot_X >> 8) & 0xFF) );

	return(&m_trame_brute);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameEcranTactile_ECRAN_ETAT_CODEURS_1_2::CTrameEcranTactile_ECRAN_ETAT_CODEURS_1_2()
{
  m_trame_brute.ID = ID_ECRAN_ETAT_CODEURS_1_2;
  m_trame_brute.DLC = DLC_ECRAN_ETAT_CODEURS_1_2;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ECRAN_ETAT_CODEURS_1_2

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameBruteEcran* CTrameEcranTactile_ECRAN_ETAT_CODEURS_1_2::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ECRAN_ETAT_CODEURS_1_2; i++) {
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
CTrameEcranTactile_ECRAN_ETAT_ECRAN::CTrameEcranTactile_ECRAN_ETAT_ECRAN()
{
  m_trame_brute.ID = ID_ECRAN_ETAT_ECRAN;
  m_trame_brute.DLC = DLC_ECRAN_ETAT_ECRAN;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ECRAN_ETAT_ECRAN

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameEcranTactile_ECRAN_ETAT_ECRAN::Decode(tStructTrameBruteEcran *trameRecue)
{
  long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

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
CTrameEcranTactile_ECRAN_ETAT_TELEMETRE::CTrameEcranTactile_ECRAN_ETAT_TELEMETRE()
{
  m_trame_brute.ID = ID_ECRAN_ETAT_TELEMETRE;
  m_trame_brute.DLC = DLC_ECRAN_ETAT_TELEMETRE;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ECRAN_ETAT_TELEMETRE

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameBruteEcran* CTrameEcranTactile_ECRAN_ETAT_TELEMETRE::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ECRAN_ETAT_TELEMETRE; i++) {
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
CTrameEcranTactile_ECRAN_ETAT_MATCH::CTrameEcranTactile_ECRAN_ETAT_MATCH()
{
  m_trame_brute.ID = ID_ECRAN_ETAT_MATCH;
  m_trame_brute.DLC = DLC_ECRAN_ETAT_MATCH;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ECRAN_ETAT_MATCH

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameBruteEcran* CTrameEcranTactile_ECRAN_ETAT_MATCH::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ECRAN_ETAT_MATCH; i++) {
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
CTrameEcranTactile_ECRAN_ETAT_CODEURS_3_4::CTrameEcranTactile_ECRAN_ETAT_CODEURS_3_4()
{
  m_trame_brute.ID = ID_ECRAN_ETAT_CODEURS_3_4;
  m_trame_brute.DLC = DLC_ECRAN_ETAT_CODEURS_3_4;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ECRAN_ETAT_CODEURS_3_4

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameBruteEcran* CTrameEcranTactile_ECRAN_ETAT_CODEURS_3_4::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ECRAN_ETAT_CODEURS_3_4; i++) {
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
CTrameEcranTactile_ECRAN_ETAT_CAPTEURS_2::CTrameEcranTactile_ECRAN_ETAT_CAPTEURS_2()
{
  m_trame_brute.ID = ID_ECRAN_ETAT_CAPTEURS_2;
  m_trame_brute.DLC = DLC_ECRAN_ETAT_CAPTEURS_2;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ECRAN_ETAT_CAPTEURS_2

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameBruteEcran* CTrameEcranTactile_ECRAN_ETAT_CAPTEURS_2::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ECRAN_ETAT_CAPTEURS_2; i++) {
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
CTrameEcranTactile_ECRAN_ETAT_CAPTEURS_1::CTrameEcranTactile_ECRAN_ETAT_CAPTEURS_1()
{
  m_trame_brute.ID = ID_ECRAN_ETAT_CAPTEURS_1;
  m_trame_brute.DLC = DLC_ECRAN_ETAT_CAPTEURS_1;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ECRAN_ETAT_CAPTEURS_1

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameBruteEcran* CTrameEcranTactile_ECRAN_ETAT_CAPTEURS_1::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_ECRAN_ETAT_CAPTEURS_1; i++) {
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




/*! @} */
