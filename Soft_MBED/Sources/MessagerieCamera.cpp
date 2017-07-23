// FICHIER GENERE PAR L'OUTIL MESS2C_robot V1.0
// Date de génération : Mon May 12 23:18:17 2014
// PLATEFORME CIBLE : MINIBOT_CAMERA
/*! \file MessagerieCamera.cpp
	\brief Fichier qui contient toutes les classes messageries heritees de la classe CTrameCAN
*/

#include "mbed.h"
#include "RessourcesHardware.h"
#include "CTrameCamera.h"
#include "MessagerieCamera.h"


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameCamera_CAM_RESULT_TRACKING::CTrameCamera_CAM_RESULT_TRACKING()
{
  m_trame_brute.ID = ID_CAM_RESULT_TRACKING;
  m_trame_brute.DLC = DLC_CAM_RESULT_TRACKING;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame CAM_RESULT_TRACKING

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameCamera_CAM_RESULT_TRACKING::Decode(tStructTrameBruteCamera *trameRecue)
{
  long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   Etat_Tracking = ( ( ((unsigned char)(trameRecue->Data[4])) & 0xFF) );

   Pos_Y = ( ( ((unsigned short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[2])) & 0xFF) << 8 );

   Pos_X = ( ( ((unsigned short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[0])) & 0xFF) << 8 );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameCamera_CAM_MODE_TRACKING_COLOR::CTrameCamera_CAM_MODE_TRACKING_COLOR()
{
  m_trame_brute.ID = ID_CAM_MODE_TRACKING_COLOR;
  m_trame_brute.DLC = DLC_CAM_MODE_TRACKING_COLOR;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame CAM_MODE_TRACKING_COLOR

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
tStructTrameBruteCamera* CTrameCamera_CAM_MODE_TRACKING_COLOR::Encode(void)
{
  unsigned char i=0;

  for (i=0; i<DLC_CAM_MODE_TRACKING_COLOR; i++) {
    m_trame_brute.Data[i] = 0;
  }

  	// Encode chacun des signaux de la trame
    m_trame_brute.Data[5] |= (unsigned char)( ( (Couleur_R) & 0xFF) );
    m_trame_brute.Data[4] |= (unsigned char)( ( (Couleur_R >> 8) & 0xFF) );

    m_trame_brute.Data[3] |= (unsigned char)( ( (Couleur_G) & 0xFF) );
    m_trame_brute.Data[2] |= (unsigned char)( ( (Couleur_G >> 8) & 0xFF) );

    m_trame_brute.Data[1] |= (unsigned char)( ( (Couleur_B) & 0xFF) );
    m_trame_brute.Data[0] |= (unsigned char)( ( (Couleur_B >> 8) & 0xFF) );

	return(&m_trame_brute);
}




/*! @} */

