/*! \file CCamera.cpp
	\brief Classe qui contient les méthodes pour le dialogue avec Camera
*/
#include "CCamera.h"
#include "RessourcesHardware.h"

//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CCamera::CCamera() 
{
 
}

//___________________________________________________________________________
 /*!
   \brief Destructeur

   \param --
   \return --
*/
CCamera::~CCamera() 
{

}



//___________________________________________________________________________
 /*!
   \brief Applique la puissance au moteur gauche

   \param vitesse la vitesse signee en pourcentage [-100%;+100]
   \return --
*/



//___________________________________________________________________________
 /*!
   \brief Point d'entree du module pour la serialisation de la trame

    - Fonction appelee pour demander la transformation d'une trame en serie d'octet envoyes sur la liaison serie
    - Prend les donnees une par une et les envoie sur la liaison serie
   \param trameBrute la trame a envoyer avec ses octets bruts
   \return --
   */
void CCamera::SerialiseTrame(tStructTrameBruteCamera *trameBrute)
{
  unsigned char i=0;
  unsigned char tmp;

  // _________________
  _rs232_camera_tx.putc(0xFF);
  // _________________
  _rs232_camera_tx.putc(trameBrute->ID);
  // _________________
  tmp = ( (((trameBrute->ID)>>3) & 0xE0) +      		// ID>>3 = ( (ID>>8) << 5 )
			(((trameBrute->Channel)&0x01) << 4) +		// Numéro de channel
			((trameBrute->DLC)&0x0F)
		);
  _rs232_camera_tx.putc(tmp);
  // _________________
  for(i=0; i<trameBrute->DLC; i++) {
     _rs232_camera_tx.putc(trameBrute->Data[i]);
  }
  // _________________
  _rs232_camera_tx.putc(getChecksum(trameBrute));
}



//___________________________________________________________________________
 /*!
   \brief Calcul le checksum de la trame

    - Calcul le checksum de la trame courante et le compare au parametre d'entree de la fonction

   \param trameBrute la trame pour laquelle calculer le checksum
   \return 	le checksum sur 8 bits
   */
unsigned char CCamera::getChecksum(tStructTrameBruteCamera *trameBrute)
{
 unsigned char i=0;
 unsigned char checksum = 0;

 checksum+= ( (((trameBrute->ID)>>3) & 0xE0) +      // ID>>3 = ( (ID>>8) << 5 ) -> MSB de l'ID
			  (((trameBrute->Channel)<<4) & 0x10) +  // Numéro de channel
			  ((trameBrute->DLC)&0x0F)
			);
 checksum+= (unsigned char)(trameBrute->ID);	// LSB de l'ID
 for(i=0;i<trameBrute->DLC;i++) {
	checksum+= trameBrute->Data[i];
 }
 return(checksum);
}




//___________________________________________________________________________
 /*!
   \brief Point d'entree du module.

    - Fonction appelee lorsqu'une donnee arrive sur la liaison serie
    -   Implemente la machine d'etat de reconstitution d'une trame, de detection d'erreur, d'interception de messages specifiques

   \param newData la donnee nouvellement recue
   \return --
   */
void CCamera::Reconstitution(unsigned char newData)
{
   switch(m_etatReconst)
   {
		// ----------------------------------------- ETATS PRIMAIRE D'AIGUILLAGE DU TYPE D'INFO RECUES
		case  cETAT_CAMERA_INIT :
			// Initialise les champs d'une précédente réception
			Init_Reconstitution();
			
			// Le message est une trame
			if (newData == 0xFF) {
				m_etatReconst = cETAT_CAMERA_ID_LSB;
			}
		break;
       	// ----------------------------------------- ETATS LIES A LA RECEPTION DE TRAMES
       	case  cETAT_CAMERA_ID_LSB :
			m_trameCourante.ID = newData;
			m_etatReconst = cETAT_CAMERA_ID_MSB_CHANNEL_DLC;
		break;
       	// ----------------------------------------- ETATS LIES A LA RECEPTION DE TRAMES
		case  cETAT_CAMERA_ID_MSB_CHANNEL_DLC :
			m_trameCourante.ID += ((unsigned int)(newData&0xE0) << 3);
			m_trameCourante.DLC = newData & 0x0F;
			m_trameCourante.Channel = (newData&0x10)>>4;
			m_numero_data = 0;
			if (m_trameCourante.DLC > NBRE_MAX_DATA_TRAME_CAMERA_TACTILE) {
			   m_etatReconst = cETAT_CAMERA_INIT;
			}
			else if (newData > 0)
			    {  m_etatReconst = cETAT_CAMERA_DATA_i; }
			else
			    {  m_etatReconst = cETAT_CAMERA_CHECKSUM; }
		break;
		// ----------------------------------------- Les DLC données
       	case  cETAT_CAMERA_DATA_i :
			m_trameCourante.Data[m_numero_data] = newData;
			m_numero_data++;
			if (m_trameCourante.DLC > m_numero_data)
			    {  /* ne rien faire : il reste des données à recevoir */ }
			else
			    {  m_etatReconst = cETAT_CAMERA_CHECKSUM; }
		break;
		// ----------------------------------------- Le checksum
        case  cETAT_CAMERA_CHECKSUM :
            if (newData == getChecksum(&m_trameCourante)) {
				DecodeTrame(&m_trameCourante);
			}
			m_etatReconst = cETAT_CAMERA_INIT;
		break;
   }
}



//___________________________________________________________________________
 /*!
   \brief Initialisation du module Reconstitution

    - Initialise tous les champs de la structure de donnee courante

   \param --
   \return --
   */
void CCamera::Init_Reconstitution(void)
{
  unsigned char i;

  // Initialise les champs de la trame courante
  m_trameCourante.ID = 0xFF;
  m_trameCourante.DLC = 0xFF;
  m_trameCourante.Channel = 0;
  for (i=0; i<NBRE_MAX_DATA_TRAME_CAMERA_TACTILE; i++) {
	  m_trameCourante.Data[i] = 0xFF;
  }

}


//___________________________________________________________________________
/*!
   \brief Point d'entree du module.

    - Fonction appelee lorsqu'une trame valide est recue
    - Implemente le necessaire pour transformer une trame brute en signaux de la structure dediee

   \param trameRecue la trame brute recue
   \return --
   */
void CCamera::DecodeTrame(tStructTrameBruteCamera *trameRecue)
{
   // Aiguillage en fonction de l'ID de la trame
   switch(trameRecue->ID)
   {
      case ID_CAM_RESULT_TRACKING :
		m_CAM_RESULT_TRACKING.Decode(trameRecue);
      break;
      default :  // L'ID de la trame n'est pas connue de la messagerie
         // ne rien faire
      break;
    }

 }








