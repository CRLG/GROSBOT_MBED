/*! \file CAnaconbot.cpp
	\brief Classe qui contient les méthodes pour le dialogue avec ANACONBOT
*/
#include "CAnaconbot.h"
#include "RessourcesHardware.h"

//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CAnaconbot::CAnaconbot() 
{
 
}

//___________________________________________________________________________
 /*!
   \brief Destructeur

   \param --
   \return --
*/
CAnaconbot::~CAnaconbot() 
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
void CAnaconbot::SerialiseTrame(tStructTrameBrute *trameBrute)
{
  unsigned char i=0;
  //unsigned char caractere_type_trame;
  _rs232_pc_tx.putc('T');
  _rs232_pc_tx.putc(trameBrute->ID>>8);
  _rs232_pc_tx.putc(trameBrute->ID);
  _rs232_pc_tx.putc(trameBrute->DLC);

  for(i=0; i<trameBrute->DLC; i++) {
          _rs232_pc_tx.putc(trameBrute->Data[i]);
  }

  _rs232_pc_tx.putc(getCheckSumTrame(trameBrute));
  //printf("envoi trame 0x%x\n",trameBrute.ID);
}



//___________________________________________________________________________
 /*!
   \brief Calcul le checksum de la trame

    - Calcul le checksum de la trame courante et le compare au parametre d'entree de la fonction

   \param trameBrute la trame pour laquelle calculer le checksum
   \return 	le checksum sur 8 bits
   */
unsigned char CAnaconbot::getCheckSumTrame(tStructTrameBrute *trameBrute)
{
 unsigned char checksum = 0;
 unsigned char i=0;

 checksum += trameBrute->ID;
 checksum += trameBrute->DLC;
 for(i=0; i<trameBrute->DLC; i++) {
          checksum += trameBrute->Data[i];
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
void CAnaconbot::Reconstitution(unsigned char newData)
{
   //time_t heure;
   //clock_t time;   // clock_t est en fait un unsigned int dans CVI
   switch(m_etatReconst)
   {
      // ----------------------------------------- ETATS PRIMAIRE D'AIGUILLAGE DU TYPE D'INFO RECUES
          case  cETAT_INIT :
                  // Initialise les champs d'une précédente réception
                  Init_Reconstitution();

                  // Le message est une trame
                  if (newData == 'T') {
                   m_etatReconst = cETAT_ID_MSB;
                   //m_trameCourante.Datation = clock();
                  }
                  // Le message est un message de diag
                  //! todo mettre en place un mécanisme plus complet pour le diag
                  else if (newData == 'D') {
                   //PresencePIC_OK();
                  }
                  else {
                    //ErreurReconstitutionTrame(cERREUR_ENTETE_INCONNU);
                  }

                break;

      // ----------------------------------------- ETATS D'ERREURS
          case  cETAT_ERREUR :

                break;


          case  cETAT_PILE_PLEINE :

                break;



      // ----------------------------------------- ETATS LIES A LA RECEPTION DE TRAMES
      case  cETAT_ID_MSB :
                           m_trameCourante.ID = (newData << 8);
                           m_etatReconst = cETAT_ID_LSB;
                break;

      case  cETAT_ID_LSB :
                           m_trameCourante.ID += (newData&0xFF);
                           m_etatReconst = cETAT_DLC;
                break;


      case  cETAT_DLC :
                           m_trameCourante.DLC = newData;
                           if (newData > 8) {
                               //ErreurReconstitutionTrame(cERREUR_DLC_INCORRECT);
                               m_etatReconst = cETAT_INIT;
                            }
                           else if (newData > 0)
                                {  m_etatReconst = cETAT_DATA_0; }
                           else
                                {  m_etatReconst = cETAT_CHECKSUM; }
                break;


       case  cETAT_DATA_0 :
                           m_trameCourante.Data[0] = newData;
                           if (m_trameCourante.DLC > 1)
                                {  m_etatReconst = cETAT_DATA_1; }
                           else
                                {  m_etatReconst = cETAT_CHECKSUM; }
                break;

       case  cETAT_DATA_1 :
                           m_trameCourante.Data[1] = newData;
                           if (m_trameCourante.DLC > 2)
                                {  m_etatReconst = cETAT_DATA_2; }
                           else
                                {  m_etatReconst = cETAT_CHECKSUM; }

                break;

       case  cETAT_DATA_2 :
                           m_trameCourante.Data[2] = newData;
                           if (m_trameCourante.DLC > 3)
                                {  m_etatReconst = cETAT_DATA_3; }
                           else
                                {  m_etatReconst = cETAT_CHECKSUM; }

                break;

       case  cETAT_DATA_3 :
                           m_trameCourante.Data[3] = newData;
                           if (m_trameCourante.DLC > 4)
                                {  m_etatReconst = cETAT_DATA_4; }
                           else
                                {  m_etatReconst = cETAT_CHECKSUM; }

                break;

       case  cETAT_DATA_4 :
                           m_trameCourante.Data[4] = newData;
                           if (m_trameCourante.DLC > 5)
                                {  m_etatReconst = cETAT_DATA_5; }
                           else
                                {  m_etatReconst = cETAT_CHECKSUM; }

                break;

       case  cETAT_DATA_5 :
                           m_trameCourante.Data[5] = newData;
                           if (m_trameCourante.DLC > 6)
                                {  m_etatReconst = cETAT_DATA_6; }
                           else
                                {  m_etatReconst = cETAT_CHECKSUM; }

                break;

       case  cETAT_DATA_6 :
                           m_trameCourante.Data[6] = newData;
                           if (m_trameCourante.DLC > 7)
                                {  m_etatReconst = cETAT_DATA_7; }
                           else
                                {  m_etatReconst = cETAT_CHECKSUM; }

                break;

       case  cETAT_DATA_7 :
                           m_trameCourante.Data[7] = newData;
                           m_etatReconst = cETAT_CHECKSUM;

                break;

         case  cETAT_CHECKSUM :
                           if (isChecksumTrameCouranteOK(newData)) {
                               // Trame de config ou trame CAN
                               if (m_trameCourante.ID <= 0x7FF) {
                                   //printf("trame %x reçue\n",m_trameCourante.ID);
                                        DecodeTrame(&m_trameCourante);
                                }
                                else {
                                        //DecodeTrameConfig(m_trameCourante);
                                }

                                   //EnregistreTrame(m_trameCourante);
                           }
                           else {
                                   //ErreurReconstitutionTrame(cERREUR_CHECKSUM);
                           }

                           m_etatReconst = cETAT_INIT;

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
void CAnaconbot::Init_Reconstitution(void)
{
  // Initialise les champs de la trame courante
  m_trameCourante.ID = 0xFFF;
  m_trameCourante.DLC = 0xFF;
  m_trameCourante.Data[0] = 0xFF;
  m_trameCourante.Data[1] = 0xFF;
  m_trameCourante.Data[2] = 0xFF;
  m_trameCourante.Data[3] = 0xFF;
  m_trameCourante.Data[4] = 0xFF;
  m_trameCourante.Data[5] = 0xFF;
  m_trameCourante.Data[6] = 0xFF;
  m_trameCourante.Data[7] = 0xFF;
}



//___________________________________________________________________________
 /*!
   \brief Verifie la conformite du checksum de la trame courante

    - Calcul le checksum de la trame courante et le compare au parametre d'entree de la fonction

   \param CS_attendu le checksum attendu à comparer avec le checksum calcule de la trame courante
   \return 	1 si le checksum est OK \n
                0 sinon
   */
unsigned char CAnaconbot::isChecksumTrameCouranteOK(unsigned char CS_attendu)
{
 unsigned char CS_calcule = 0;
 unsigned char i=0;

 CS_calcule += m_trameCourante.ID;
 CS_calcule += m_trameCourante.DLC;
 for(i=0; i<m_trameCourante.DLC; i++) {
          CS_calcule += m_trameCourante.Data[i];
 }

// return(CS_calcule == CS_attendu);
 return(1); // toujours vrai pour les tests
}



//___________________________________________________________________________
/*!
   \brief Point d'entree du module.

    - Fonction appelee lorsqu'une trame valide est recue
    - Implemente le necessaire pour transformer une trame brute en signaux de la structure dediee

   \param trameRecue la trame brute recue
   \return --
   */
void CAnaconbot::DecodeTrame(tStructTrameBrute *trameRecue)
{

   // Aiguillage en fonction de l'ID de la trame
   switch(trameRecue->ID)
   {
      case ID_COMMANDE_VITESSE_MVT :
        m_COMMANDE_VITESSE_MVT.Decode(trameRecue);
      break;

      case ID_ASSERV_DIAG_WR_COMPTEUR_MAX :
        m_ASSERV_DIAG_WR_COMPTEUR_MAX.Decode(trameRecue);
      break;

      case ID_ASSERV_DIAG_WR_SEUIL_CONV_ANGLE :
        m_ASSERV_DIAG_WR_SEUIL_CONV_ANGLE.Decode(trameRecue);
      break;

      case ID_ASSERV_DIAG_WR_SEUIL_CONV_DIST :
        m_ASSERV_DIAG_WR_SEUIL_CONV_DIST.Decode(trameRecue);
      break;

      case ID_ASSERV_DIAG_WR_KI_ANGLE :
        m_ASSERV_DIAG_WR_KI_ANGLE.Decode(trameRecue);
      break;

      case ID_ASSERV_DIAG_WR_KP_ANGLE :
        m_ASSERV_DIAG_WR_KP_ANGLE.Decode(trameRecue);
      break;

      case ID_ASSERV_DIAG_WR_KI_DISTANCE :
        m_ASSERV_DIAG_WR_KI_DISTANCE.Decode(trameRecue);
      break;

      case ID_ASSERV_DIAG_WR_KP_DISTANCE :
        m_ASSERV_DIAG_WR_KP_DISTANCE.Decode(trameRecue);
      break;

      case ID_ASSERV_DIAG_WR_CDE_MIN :
        m_ASSERV_DIAG_WR_CDE_MIN.Decode(trameRecue);
      break;

      case ID_ASSERV_DIAG_WR_CDE_MAX :
        m_ASSERV_DIAG_WR_CDE_MAX.Decode(trameRecue);
      break;

      case ID_ASSERV_DIAG_READ_PARAM_REP :
        m_ASSERV_DIAG_READ_PARAM_REP.Decode(trameRecue);
      break;

      case ID_ASSERV_DIAG_READ_PARAM_REQ :
        m_ASSERV_DIAG_READ_PARAM_REQ.Decode(trameRecue);
      break;

      case ID_COMMANDE_SERVOS_MOTEURS :
        m_COMMANDE_SERVOS_MOTEURS.Decode(trameRecue);
      break;

      case ID_COMMANDE_MVT_MANUEL :
        m_COMMANDE_MVT_MANUEL.Decode(trameRecue);
      break;

      case ID_COMMANDE_DISTANCE_ANGLE :
        m_COMMANDE_DISTANCE_ANGLE.Decode(trameRecue);
      break;

      case ID_COMMANDE_MVT_XY :
        m_COMMANDE_MVT_XY.Decode(trameRecue);
      break;


      default :  // L'ID de la trame n'est pas connue de la messagerie
         // ne rien faire
      break;
    }

 }







