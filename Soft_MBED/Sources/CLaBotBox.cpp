/*! \file CLaBotBox.cpp
	\brief Classe qui contient les méthodes pour le dialogue avec ANACONBOT
*/
#include "CLaBotBox.h"
#include "RessourcesHardware.h"
#include "CGlobale.h"

//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CLaBotBox::CLaBotBox() 
{
    m_rx_enabled = false;
    m_tx_enabled = false;
    initListeTrames();
}

//___________________________________________________________________________
 /*!
   \brief Destructeur

   \param --
   \return --
*/
CLaBotBox::~CLaBotBox() 
{

}

//___________________________________________________________________________
 /*!
   \brief Créé la liste des trames.
    En cas d'ajout d'une trame à la messagerie, ajouter cette trame à la liste

   \param --
   \return --
*/
void CLaBotBox::initListeTrames()
{
    m_nombre_trames = 0;

    m_liste_trames[m_nombre_trames++] = &m_ELECTROBOT_CDE_MOTEURS;
    m_liste_trames[m_nombre_trames++] = &m_COMMANDE_MVT_XY;
    m_liste_trames[m_nombre_trames++] = &m_ASSERV_RESET;
    m_liste_trames[m_nombre_trames++] = &m_ASSERV_DIAG_WRITE_PARAM;
    m_liste_trames[m_nombre_trames++] = &m_AUTOAPPRENTISSAGE_ASSERV;
    m_liste_trames[m_nombre_trames++] = &m_COMMANDE_REINIT_XY_TETA;
    m_liste_trames[m_nombre_trames++] = &m_COMMANDE_VITESSE_MVT;
    m_liste_trames[m_nombre_trames++] = &m_COMMANDE_REGUL_VITESSE;
    m_liste_trames[m_nombre_trames++] = &m_COMMANDE_DISTANCE_ANGLE;
    m_liste_trames[m_nombre_trames++] = &m_COMMANDE_MVT_XY_TETA;
    m_liste_trames[m_nombre_trames++] = &m_ELECTROBOT_CDE_SERVOS;
    m_liste_trames[m_nombre_trames++] = &m_ELECTROBOT_CDE_SERVOS_AX;
    m_liste_trames[m_nombre_trames++] = &m_ELECTROBOT_CDE_SERVOS_SD20;
    m_liste_trames[m_nombre_trames++] = &m_COMMANDE_MVT_MANUEL;
    m_liste_trames[m_nombre_trames++] = &m_ETAT_PID_ASSERVISSEMENT;
    m_liste_trames[m_nombre_trames++] = &m_ETAT_ASSERVISSEMENT;
    m_liste_trames[m_nombre_trames++] = &m_POSITION_CODEURS;
    m_liste_trames[m_nombre_trames++] = &m_POSITION_ABSOLUE_XY_TETA;
    m_liste_trames[m_nombre_trames++] = &m_ELECTROBOT_ETAT_CODEURS_1_2;
    m_liste_trames[m_nombre_trames++] = &m_ELECTROBOT_ETAT_TELEMETRES;
    m_liste_trames[m_nombre_trames++] = &m_ELECTROBOT_ETAT_CODEURS_3_4;
    m_liste_trames[m_nombre_trames++] = &m_ELECTROBOT_ETAT_CAPTEURS_2;
    m_liste_trames[m_nombre_trames++] = &m_ELECTROBOT_ETAT_CAPTEURS_1;
    m_liste_trames[m_nombre_trames++] = &m_ETAT_ECRAN;
    m_liste_trames[m_nombre_trames++] = &m_ETAT_MATCH;
    m_liste_trames[m_nombre_trames++] = &m_ETAT_RACK;
    m_liste_trames[m_nombre_trames++] = &m_COLOR_SENSOR;
    m_liste_trames[m_nombre_trames++] = &m_CONFIG_PERIODE_TRAME;
}


//___________________________________________________________________________
/*!
   \brief Renvoie le pointeur sur la trame à partir de son identifiant.

    - Fonction appelee lorsqu'une trame valide est recue
    - Implemente le necessaire pour transformer une trame brute en signaux de la structure dediee

   \param trameRecue la trame brute recue
   \return --
   */
CTrameLaBotBox* CLaBotBox::getTrameFromID(unsigned int ID)
{
    for (unsigned int i=0; i<m_nombre_trames; i++)
    {
        if (ID == m_liste_trames[i]->m_trame_brute.ID)
            return m_liste_trames[i];
    }
    return nullptr;
}

//___________________________________________________________________________
 /*!
   \brief Commence la communication avec Labotbox

   \param --
   \return --
*/
void CLaBotBox::Start()
{
    if (!m_rx_enabled) {
        while (_rs232_pc_rx.readable()) _rs232_pc_rx.getc(); // Nettoie tout octet en attente dans le buffer
        for (unsigned int i=0; i<m_nombre_trames; i++) {  // Supprime les trames reçues en attente pas encore traitées
            if (m_liste_trames[i]) m_liste_trames[i]->isNewTrame();
        }
    }

    _rs232_pc_rx.attach(this, &CLaBotBox::IRQ_ReceiveRS232);  	// Callback sur réception d'une donnée sur la RS232

    m_rx_enabled = true;
    m_tx_enabled = true;
}

//___________________________________________________________________________
 /*!
   \brief Stoppe toute communication avec Labotbox

   \param --
   \return --
*/
void CLaBotBox::Stop()
{
    StopRx();
    StopTx();
}

//___________________________________________________________________________
 /*!
   \brief Stoppe la communication entrante (uniquement) avec Labotbox

   \param --
   \return --
   \remark Cette méthode permet d'inhiber les octets entrants
            tout en laissant la possibilité d'envoyer des octets
           Une fois que le match a commencé, cela permet de sécuriser
           les informations entrantes et ne pas prendre le risque de recevoir
           une trame par erreur qui pourrait perturber le match.
*/
void CLaBotBox::StopRx()
{
    _rs232_pc_rx.attach(NULL); // Supprime l'IRQ sur réception RS232
    m_rx_enabled = false;
}
//___________________________________________________________________________
 /*!
   \brief Stoppe la communication sortante (uniquement) avec Labotbox

   \param --
   \return --
*/
void CLaBotBox::StopTx()
{
    m_tx_enabled = false;
}

//___________________________________________________________________________
 /*!
   \brief Indique si la communication entrante est activée

   \param --
   \return --
*/
bool CLaBotBox::isRxEnabled()
{
    return m_rx_enabled;
}

//___________________________________________________________________________
 /*!
   \brief Indique si la communication sortante est activée

   \param --
   \return --
*/
bool CLaBotBox::isTxEnabled()
{
    return m_tx_enabled;
}

//___________________________________________________________________________
 /*!
   \brief Réalise les traitements périodiques

   \param --
   \return --
   \remark Fonction à appeler périodiquement par la couche supérieure (toutes les 10msec)
*/
void CLaBotBox::Execute()
{
    if (m_rx_enabled)
    {
        CheckReceptionTrame();
    }

    if (m_tx_enabled)
    {
        SendTramesLaBotBox();
    }
}


// =============================================================
//                      RECEPTION
// =============================================================

// _____________________________________________________________
void CLaBotBox::IRQ_ReceiveRS232(void)
{
  char rxData;
  rxData = _rs232_pc_rx.getc();
  Reconstitution(rxData);
}

//___________________________________________________________________________
 /*!
   \brief Point d'entree du module.

    - Fonction appelee lorsqu'une donnee arrive sur la liaison serie
    -   Implemente la machine d'etat de reconstitution d'une trame, de detection d'erreur, d'interception de messages specifiques

   \param newData la donnee nouvellement recue
   \return --
   */
void CLaBotBox::Reconstitution(unsigned char newData)
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
void CLaBotBox::Init_Reconstitution(void)
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

   \param CS_attendu le checksum attendu à  comparer avec le checksum calcule de la trame courante
   \return 	1 si le checksum est OK \n
                0 sinon
   */
unsigned char CLaBotBox::isChecksumTrameCouranteOK(unsigned char CS_attendu)
{
 unsigned char CS_calcule = 0;
 unsigned char i=0;

 CS_calcule += m_trameCourante.ID;
 CS_calcule += m_trameCourante.DLC;
 for(i=0; i<m_trameCourante.DLC; i++) {
          CS_calcule += m_trameCourante.Data[i];
 }

 return(CS_calcule == CS_attendu);
// return(1); // toujours vrai pour les tests
}




//___________________________________________________________________________
/*!
   \brief Point d'entree du module.

    - Fonction appelee lorsqu'une trame valide est recue
    - Implemente le necessaire pour transformer une trame brute en signaux de la structure dediee

   \param trameRecue la trame brute recue
   \return --
   */
void CLaBotBox::DecodeTrame(tStructTrameLaBotBox *trameRecue)
{
    for (unsigned int i=0; i<m_nombre_trames; i++)
    {
        if (trameRecue->ID == m_liste_trames[i]->m_trame_brute.ID)
        {
            if (m_liste_trames[i])
            {
                m_liste_trames[i]->Decode(trameRecue);
                return;
            }
        }
    }
 }


//___________________________________________________________________________
 /*!
   \brief Verifie et traite les trames recues en attente

   \param --
   \return --
*/
void CLaBotBox::CheckReceptionTrame(void)
{
  char cbuff[64];
  // ___________________________
  if  (m_ELECTROBOT_CDE_MOTEURS.isNewTrame() ) {
    Application.m_moteurs.CommandeVitesse(MOTEUR_1, (signed char)m_ELECTROBOT_CDE_MOTEURS.cde_moteur_1);  // Attention : obligation de mettre le cast explicit en "signed", sinon, la valeur est interprétée non signée
    wait_ms(5);
    Application.m_moteurs.CommandeVitesse(MOTEUR_2, (signed char)m_ELECTROBOT_CDE_MOTEURS.cde_moteur_2);
    wait_ms(5);
    Application.m_moteurs.CommandeVitesse(MOTEUR_3, (signed char)m_ELECTROBOT_CDE_MOTEURS.cde_moteur_3);
    wait_ms(5);
    Application.m_moteurs.CommandeVitesse(MOTEUR_4, (signed char)m_ELECTROBOT_CDE_MOTEURS.cde_moteur_4);
    wait_ms(5);
    Application.m_moteurs.CommandeVitesse(MOTEUR_5, (signed char)m_ELECTROBOT_CDE_MOTEURS.cde_moteur_5);
    wait_ms(5);
    Application.m_moteurs.CommandeVitesse(MOTEUR_6, (signed char)m_ELECTROBOT_CDE_MOTEURS.cde_moteur_6);
    //wait_ms(1);
  }

  // ___________________________
  if  (m_ELECTROBOT_CDE_SERVOS.isNewTrame() ) {
    //utilisation de la trame pour piloter le chariot
    if(m_ELECTROBOT_CDE_SERVOS.NumeroServoMoteur1==50)
    {
        float sens_position=0.0;
        if(m_ELECTROBOT_CDE_SERVOS.VitesseServoMoteur1<10)
            sens_position=1.0;
        else
            sens_position=-1.0;
        float new_consigne = (float)((m_ELECTROBOT_CDE_SERVOS.PositionServoMoteur1*10.0)*sens_position);
        Application.m_asservissement_chariot.setConsigne(new_consigne);
    }
    else if (m_ELECTROBOT_CDE_SERVOS.NumeroServoMoteur1==51)
        Application.m_asservissement_chariot.Stop_Chariot();
    else if (m_ELECTROBOT_CDE_SERVOS.NumeroServoMoteur1==52)
    {
        Application.m_asservissement_chariot.Recal_Chariot();
        //_led1 = !_led1;
    }
    else
    {
        Application.m_servos_sd20.CommandePositionVitesse(
                    m_ELECTROBOT_CDE_SERVOS.NumeroServoMoteur1,
                    m_ELECTROBOT_CDE_SERVOS.PositionServoMoteur1,
                    m_ELECTROBOT_CDE_SERVOS.VitesseServoMoteur1);
        Application.m_servos_sd20.CommandePositionVitesse(
                    m_ELECTROBOT_CDE_SERVOS.NumeroServoMoteur2,
                    m_ELECTROBOT_CDE_SERVOS.PositionServoMoteur2,
                    m_ELECTROBOT_CDE_SERVOS.VitesseServoMoteur2);
    }
   }

  // ___________________________
  if  (m_ELECTROBOT_CDE_SERVOS_AX.isNewTrame() ) {
    // sous adressage : le champ commande_ax donne le type d'action à  réaliser
    switch (m_ELECTROBOT_CDE_SERVOS_AX.commande_ax) {
        case cSERVO_AX_POSITION :
            Application.m_servos_ax.setPosition(
                        m_ELECTROBOT_CDE_SERVOS_AX.num_servo_ax,
                        m_ELECTROBOT_CDE_SERVOS_AX.valeur_commande_ax);
        break;
        case cSERVO_AX_VITESSE :
            Application.m_servos_ax.setSpeed(
                        m_ELECTROBOT_CDE_SERVOS_AX.num_servo_ax,
                        m_ELECTROBOT_CDE_SERVOS_AX.valeur_commande_ax);
        break;

        case cSERVO_AX_CHANGE_ID :
            Application.m_servos_ax.changeID(
                        m_ELECTROBOT_CDE_SERVOS_AX.num_servo_ax,
                        m_ELECTROBOT_CDE_SERVOS_AX.valeur_commande_ax);
        break;

        case cSERVO_AX_LED_STATE :
            Application.m_servos_ax.setLed(
                        m_ELECTROBOT_CDE_SERVOS_AX.num_servo_ax,
                        m_ELECTROBOT_CDE_SERVOS_AX.valeur_commande_ax);
        break;

        case cSERVO_AX_BUTEE_MIN :
            Application.m_servos_ax.setLimitPositionMin(
                        m_ELECTROBOT_CDE_SERVOS_AX.num_servo_ax,
                        m_ELECTROBOT_CDE_SERVOS_AX.valeur_commande_ax);
            sprintf(cbuff, "butee_min_servo_ax_%d", m_ELECTROBOT_CDE_SERVOS_AX.num_servo_ax);
            Application.m_eeprom.setValue(cbuff, m_ELECTROBOT_CDE_SERVOS_AX.valeur_commande_ax);
        break;

        case cSERVO_AX_BUTEE_MAX :
            Application.m_servos_ax.setLimitPositionMax(
                        m_ELECTROBOT_CDE_SERVOS_AX.num_servo_ax,
                        m_ELECTROBOT_CDE_SERVOS_AX.valeur_commande_ax);
            sprintf(cbuff, "butee_max_servo_ax_%d", m_ELECTROBOT_CDE_SERVOS_AX.num_servo_ax);
            Application.m_eeprom.setValue(cbuff, m_ELECTROBOT_CDE_SERVOS_AX.valeur_commande_ax);
        break;

        case cSERVO_AX_POSITION_INIT :
            sprintf(cbuff, "position_initiale_servo_ax_%d", m_ELECTROBOT_CDE_SERVOS_AX.num_servo_ax);
            Application.m_eeprom.setValue(cbuff, m_ELECTROBOT_CDE_SERVOS_AX.valeur_commande_ax);
        break;

        default :
        break; //  ne rien faire

    } // switch commande_ax
   }

  // ___________________________
  if  (m_ELECTROBOT_CDE_SERVOS_SD20.isNewTrame() ) {
     //_led2 = !_led2;
    // sous adressage : le champ commande_sd20 donne le type d'action à  réaliser
    switch (m_ELECTROBOT_CDE_SERVOS_SD20.commande_sd20) {
        case cSERVO_SD20_POSITION :
            Application.m_servos_sd20.CommandePosition(
                        m_ELECTROBOT_CDE_SERVOS_SD20.num_servo_sd20,
                        m_ELECTROBOT_CDE_SERVOS_SD20.valeur_commande_sd20);

        break;

        case cSERVO_SD20_BUTEE_MIN :
            Application.m_servos_sd20.setButeeMinPosition(
                        m_ELECTROBOT_CDE_SERVOS_SD20.num_servo_sd20,
                        m_ELECTROBOT_CDE_SERVOS_SD20.valeur_commande_sd20);
            sprintf(cbuff, "butee_min_servo_sd20_%d", m_ELECTROBOT_CDE_SERVOS_SD20.num_servo_sd20);
            Application.m_eeprom.setValue(cbuff, m_ELECTROBOT_CDE_SERVOS_SD20.valeur_commande_sd20);
        break;

        case cSERVO_SD20_BUTEE_MAX :
            Application.m_servos_sd20.setButeeMaxPosition(
                        m_ELECTROBOT_CDE_SERVOS_SD20.num_servo_sd20,
                        m_ELECTROBOT_CDE_SERVOS_SD20.valeur_commande_sd20);
            sprintf(cbuff, "butee_max_servo_sd20_%d", m_ELECTROBOT_CDE_SERVOS_SD20.num_servo_sd20);
            Application.m_eeprom.setValue(cbuff, m_ELECTROBOT_CDE_SERVOS_SD20.valeur_commande_sd20);
        break;

        case cSERVO_SD20_POSITION_INIT :
            sprintf(cbuff, "position_initiale_servo_sd20_%d", m_ELECTROBOT_CDE_SERVOS_SD20.num_servo_sd20);
            Application.m_eeprom.setValue(cbuff, m_ELECTROBOT_CDE_SERVOS_SD20.valeur_commande_sd20);
        break;

        default :
        break; //  ne rien faire

    } // switch commande_sd20
   }
  // ___________________________
  if  (m_ASSERV_DIAG_WRITE_PARAM.isNewTrame() ) {
    float fval_coef100 	= (float)m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE / 100.0f;
    //float fval_coef10 	= (float)m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE / 10.0f;
    // sous adressage : le champ commande_ax donne le type d'action à  réaliser
    switch (m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_PARAM) {
        case cASSERV_SEUIL_CONV_DIST :
            Application.m_asservissement.seuil_conv_distance=fval_coef100;
            Application.m_eeprom.setValue("seuil_conv_distance", fval_coef100);
        break;

        case cASSERV_SEUIL_CONV_ANGLE :
            Application.m_asservissement.seuil_conv_angle=fval_coef100;
            Application.m_eeprom.setValue("seuil_conv_angle", fval_coef100);
        break;

        case cASSERV_DIAG_WR_KI_ANGLE :
            Application.m_asservissement.ki_angle=fval_coef100;
            Application.m_eeprom.setValue("ki_angle", fval_coef100);
        break;

        case cASSERV_DIAG_WR_KP_ANGLE :
            Application.m_asservissement.kp_angle=fval_coef100;
            Application.m_eeprom.setValue("kp_angle", fval_coef100);
        break;

        case cASSERV_DIAG_WR_KI_DISTANCE :
            Application.m_asservissement.ki_distance=fval_coef100;
            Application.m_eeprom.setValue("ki_distance", fval_coef100);
        break;

        case cASSERV_DIAG_WR_KP_DISTANCE :
            Application.m_asservissement.kp_distance=fval_coef100;
            Application.m_eeprom.setValue("kp_distance", fval_coef100);
        break;

        case cASSERV_DIAG_WR_CDE_MIN :
            Application.m_asservissement.cde_min=m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE;
            Application.m_eeprom.setValue("cde_min", m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE);
        break;

        case cASSERV_DIAG_WR_CDE_MAX :
            Application.m_asservissement.cde_max=m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE;
            Application.m_eeprom.setValue("cde_max", m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE);
        break;

        case cASSERV_DIAG_RACK_CDE_MAX :
            Application.m_asservissement_chariot.setCommandeMax(m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE);
            Application.m_eeprom.setValue("rackCommandeMax", (float)m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE);
            break;

        case cASSERV_DIAG_RACK_K_POSVIT :
            Application.m_asservissement_chariot.setGainPosVit(fval_coef100);
            Application.m_eeprom.setValue("rackGainPosVit", (float)fval_coef100);
        break;

        case cASSERV_DIAG_RACK_KP :
            Application.m_asservissement_chariot.setGainP(fval_coef100);
            Application.m_eeprom.setValue("rackGainP", (float)fval_coef100);
        break;

        case cASSERV_DIAG_RACK_KI :
            Application.m_asservissement_chariot.setGainI(fval_coef100);
            Application.m_eeprom.setValue("rackGainI", (float)fval_coef100);
        break;

        case cASSERV_DIAG_RACK_CONV :
            Application.m_asservissement_chariot.setSeuilConv(m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE);
            Application.m_eeprom.setValue("rackSeuilConv", (float)m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE);
        break;

    } // switch
  }

  // ___________________________
  if  (m_COMMANDE_MVT_MANUEL.isNewTrame() ) {
      Application.m_asservissement.CommandeManuelle(
                  m_COMMANDE_MVT_MANUEL.PuissanceMotG,
                  m_COMMANDE_MVT_MANUEL.PuissanceMotD);
  }
  // ___________________________
  if  (m_COMMANDE_DISTANCE_ANGLE.isNewTrame() ) {
      Application.m_asservissement.CommandeMouvementDistanceAngle(
                  m_COMMANDE_DISTANCE_ANGLE.distance_consigne,
                  BRUTE2PHYS_angle_consigne(m_COMMANDE_DISTANCE_ANGLE.angle_consigne));
  }
  // ___________________________
  if  (m_COMMANDE_MVT_XY.isNewTrame() ) {
      Application.m_asservissement.CommandeMouvementXY(
                  m_COMMANDE_MVT_XY.X_consigne,
                  m_COMMANDE_MVT_XY.Y_consigne);
  }
  // ___________________________
  if  (m_COMMANDE_MVT_XY_TETA.isNewTrame() ) {
        Application.m_asservissement.CommandeMouvementXY_TETA(
                m_COMMANDE_MVT_XY_TETA.X_consigne,
                m_COMMANDE_MVT_XY_TETA.Y_consigne,
                BRUTE2PHYS_angle_consigne(m_COMMANDE_MVT_XY_TETA.angle_consigne));
    }
  // ___________________________
  if  (m_COMMANDE_VITESSE_MVT.isNewTrame() ) {
      Application.m_asservissement.CommandeVitesseMouvement(
                  (float)m_COMMANDE_VITESSE_MVT.vitesse_avance_max,
                  (float)m_COMMANDE_VITESSE_MVT.vitesse_rotation_max);

      //TODO : a quelle variable relier les indices de sportivité de la trame
      //m_COMMANDE_VITESSE_MVT.indice_sportivite_decel;
      Application.m_asservissement.Ind_perfo=m_COMMANDE_VITESSE_MVT.indice_sportivite_accel;
  }
  // ___________________________
  if (m_COMMANDE_REINIT_XY_TETA.isNewTrame()){
      Application.m_asservissement.setPosition_XYTeta(
                  m_COMMANDE_REINIT_XY_TETA.reinit_x_pos,
                  m_COMMANDE_REINIT_XY_TETA.reinit_y_pos,
                  BRUTE2PHYS_angle_consigne(m_COMMANDE_REINIT_XY_TETA.reinit_teta_pos));
  }
  // ___________________________
  if  (m_ETAT_ECRAN.isNewTrame() ) {
      //_led1 = !_led1;
      switch(m_ETAT_ECRAN.CodeCommande) {
      // _________________________________________
      case LBB_CMDE_CHOIX_EQUIPE : // Choix couleur équipe
          Application.m_match.m_couleur_equipe = m_ETAT_ECRAN.Valeur;
          break;
      // _________________________________________
      case LBB_CMDE_TEST_ACTIONNEURS :
          Application.m_match.m_dde_test_actionneurs=1;
          break;
      // _________________________________________
      case LBB_CMDE_CHOIX_NUMERO_STRATEGIE : //Choix de la stratégie
          Application.m_match.m_choix_strategie = m_ETAT_ECRAN.Valeur;
          break;
      // _______________________
      default :
          //_led1 = !_led1;
          break;
      } // switch
  }
  // ___________________________
  if  (m_CONFIG_PERIODE_TRAME.isNewTrame() ) {
      // Valeur particulière pour indiquer que la demande concerne toutes les trames d'un seul coup
      if (m_CONFIG_PERIODE_TRAME.ID == 0xFFFF)
      {
          setAllTransmitPeriod(m_CONFIG_PERIODE_TRAME.Periode);
      }
      else
      {
          CTrameLaBotBox *trame = getTrameFromID(m_CONFIG_PERIODE_TRAME.ID);
          if (trame)
          {
              trame->setTransmitPeriod(m_CONFIG_PERIODE_TRAME.Periode);
          }
      }
  }
}



// =============================================================
//                      EMISSION
// =============================================================

//___________________________________________________________________________
 /*!
   \brief Envoie les trames vers LABOTBOX

   \param --
   \return --
*/
void CLaBotBox::SendTramesLaBotBox(void)
{
    // _____________________________________________
    if (m_ETAT_ASSERVISSEMENT.isTimeToSend())
    {
        m_ETAT_ASSERVISSEMENT.cde_moteur_G = (int)Application.m_roues.m_cde_roue_G;
        m_ETAT_ASSERVISSEMENT.cde_moteur_D = (int)Application.m_roues.m_cde_roue_D;
        m_ETAT_ASSERVISSEMENT.Convergence = (Application.m_asservissement.diag_blocage==1)?2:Application.m_asservissement.convergence_conf;
        m_ETAT_ASSERVISSEMENT.ModeAsservissement = Application.m_asservissement.ModeAsservissement;
        SerialiseTrame(	m_ETAT_ASSERVISSEMENT.Encode());
    }
    // _____________________________________________
    if (m_POSITION_CODEURS.isTimeToSend())
    {
        m_POSITION_CODEURS.PosCodeurG = Application.m_roues.getCodeurG();
        m_POSITION_CODEURS.PosCodeurD = Application.m_roues.getCodeurD();
        SerialiseTrame(	m_POSITION_CODEURS.Encode());
    }
    // _____________________________________________
    if (m_POSITION_ABSOLUE_XY_TETA.isTimeToSend())
    {
        m_POSITION_ABSOLUE_XY_TETA.x_pos = PHYS2BRUTE_x_pos(Application.m_asservissement.X_robot);
        m_POSITION_ABSOLUE_XY_TETA.y_pos = PHYS2BRUTE_y_pos(Application.m_asservissement.Y_robot);
        m_POSITION_ABSOLUE_XY_TETA.teta_pos = PHYS2BRUTE_teta_pos(Application.m_asservissement.angle_robot);
        SerialiseTrame(	m_POSITION_ABSOLUE_XY_TETA.Encode());
    }
    // _____________________________________________
    if (m_ETAT_PID_ASSERVISSEMENT.isTimeToSend())
    {
        m_ETAT_PID_ASSERVISSEMENT.vitesse_avance_robot_filt      = PHYS2BRUTE_vitesse_avance_robot_filt(Application.m_asservissement.vitesse_avance_robot_filt);
        m_ETAT_PID_ASSERVISSEMENT.consigne_vitesse_avance_filt   = PHYS2BRUTE_consigne_vitesse_avance_filt(Application.m_asservissement.consigne_vitesse_avance_filt);
        m_ETAT_PID_ASSERVISSEMENT.vitesse_rotation_robot_filt    = PHYS2BRUTE_vitesse_rotation_robot_filt(Application.m_asservissement.vitesse_rotation_robot_filt);
        m_ETAT_PID_ASSERVISSEMENT.consigne_vitesse_rotation_filt = PHYS2BRUTE_consigne_vitesse_rotation_filt(Application.m_asservissement.consigne_vitesse_rotation_filt);
        SerialiseTrame(	m_ETAT_PID_ASSERVISSEMENT.Encode());
    }
    // _____________________________________________
    if (m_ELECTROBOT_ETAT_CAPTEURS_1.isTimeToSend())
    {
        m_ELECTROBOT_ETAT_CAPTEURS_1.Eana1 = PHYS2BRUTE_Eana1(Application.m_capteurs.m_b_Eana1);
        m_ELECTROBOT_ETAT_CAPTEURS_1.Eana2 = PHYS2BRUTE_Eana2(Application.m_capteurs.m_b_Eana2);
        m_ELECTROBOT_ETAT_CAPTEURS_1.Eana3 = PHYS2BRUTE_Eana3(Application.m_capteurs.m_b_Eana3);
        m_ELECTROBOT_ETAT_CAPTEURS_1.Eana4 = PHYS2BRUTE_Eana4(Application.m_capteurs.m_b_Eana4);
        m_ELECTROBOT_ETAT_CAPTEURS_1.Eana5 = PHYS2BRUTE_Eana5(Application.m_capteurs.m_b_Eana5);
        m_ELECTROBOT_ETAT_CAPTEURS_1.Eana6 = PHYS2BRUTE_Eana6(Application.m_capteurs.m_b_Eana6);
        m_ELECTROBOT_ETAT_CAPTEURS_1.Eana7 = PHYS2BRUTE_Eana7(Application.m_capteurs.m_b_Eana7);
        m_ELECTROBOT_ETAT_CAPTEURS_1.Eana8 = PHYS2BRUTE_Eana8(Application.m_capteurs.m_b_Eana8);
        SerialiseTrame(	m_ELECTROBOT_ETAT_CAPTEURS_1.Encode());
    }
    // _____________________________________________
    if (m_ELECTROBOT_ETAT_CAPTEURS_2.isTimeToSend())
    {
        m_ELECTROBOT_ETAT_CAPTEURS_2.Eana9 = PHYS2BRUTE_Eana9(Application.m_capteurs.m_b_Eana9);
        m_ELECTROBOT_ETAT_CAPTEURS_2.Eana10 = PHYS2BRUTE_Eana10(Application.m_capteurs.m_b_Eana10);
        m_ELECTROBOT_ETAT_CAPTEURS_2.Eana11 = PHYS2BRUTE_Eana11(Application.m_capteurs.m_b_Eana11);
        m_ELECTROBOT_ETAT_CAPTEURS_2.Eana12 = PHYS2BRUTE_Eana12(Application.m_capteurs.m_b_Eana12);
        m_ELECTROBOT_ETAT_CAPTEURS_2.Eana13 = PHYS2BRUTE_Eana13(Application.m_capteurs.m_b_Eana13);
        m_ELECTROBOT_ETAT_CAPTEURS_2.Vbat = PHYS2BRUTE_Vbat(Application.m_capteurs.m_tension_batterie);
        m_ELECTROBOT_ETAT_CAPTEURS_2.Etor1 = !Application.m_capteurs.m_b_Etor1;
        m_ELECTROBOT_ETAT_CAPTEURS_2.Etor2 = !Application.m_capteurs.m_b_Etor2;
        m_ELECTROBOT_ETAT_CAPTEURS_2.Etor3 = !Application.m_capteurs.m_b_Etor3;
        m_ELECTROBOT_ETAT_CAPTEURS_2.Etor4 = !Application.m_capteurs.m_b_Etor4;
        m_ELECTROBOT_ETAT_CAPTEURS_2.Etor5 = !Application.m_capteurs.m_b_Etor5;
        m_ELECTROBOT_ETAT_CAPTEURS_2.Etor6 = !Application.m_capteurs.m_b_Etor6;
        m_ELECTROBOT_ETAT_CAPTEURS_2.Etor_CAN_TX = !Application.m_capteurs.m_b_Etor_CanTx;
        m_ELECTROBOT_ETAT_CAPTEURS_2.Etor_CAN_RX = !Application.m_capteurs.m_b_Etor_CanRx;
        SerialiseTrame(	m_ELECTROBOT_ETAT_CAPTEURS_2.Encode());
    }
    // _____________________________________________
    if (m_ELECTROBOT_ETAT_CODEURS_1_2.isTimeToSend())
    {
        m_ELECTROBOT_ETAT_CODEURS_1_2.Codeur_1 = Application.m_capteurs.m_CumulCodeurPosition1;
        m_ELECTROBOT_ETAT_CODEURS_1_2.Codeur_2 = Application.m_capteurs.m_CumulCodeurPosition2;
        SerialiseTrame(m_ELECTROBOT_ETAT_CODEURS_1_2.Encode());
    }
    // _____________________________________________
    if (m_ELECTROBOT_ETAT_CODEURS_3_4.isTimeToSend())
    {
        m_ELECTROBOT_ETAT_CODEURS_3_4.Codeur_3 = Application.m_capteurs.m_CumulCodeurPosition3;
        m_ELECTROBOT_ETAT_CODEURS_3_4.Codeur_4 = Application.m_capteurs.m_CumulCodeurPosition4;
        SerialiseTrame(m_ELECTROBOT_ETAT_CODEURS_3_4.Encode());
    }
    // _____________________________________________
    if (m_ELECTROBOT_ETAT_TELEMETRES.isTimeToSend())
    {
        m_ELECTROBOT_ETAT_TELEMETRES.Telemetre1 = Application.m_capteurs.m_telemetres.m_distance[0];
        m_ELECTROBOT_ETAT_TELEMETRES.Telemetre2 = Application.m_capteurs.m_telemetres.m_distance[1];
        m_ELECTROBOT_ETAT_TELEMETRES.Telemetre3 = Application.m_capteurs.m_telemetres.m_distance[2];
        m_ELECTROBOT_ETAT_TELEMETRES.Telemetre4 = Application.m_capteurs.m_telemetres.m_distance[3];
        SerialiseTrame(m_ELECTROBOT_ETAT_TELEMETRES.Encode());
    }
    // _____________________________________________
    if (m_ETAT_MATCH.isTimeToSend())
    {
        m_ETAT_MATCH.TempsMatch = (unsigned char)(Application.m_match.m_duree);
        m_ETAT_MATCH.CouleurEquipe = Application.m_match.m_couleur_equipe;
        m_ETAT_MATCH.ModeFonctionnement = Application.ModeFonctionnement;
        m_ETAT_MATCH.ObstacleDetecte = Application.m_match.m_obstacleDetecte;
        m_ETAT_MATCH.ConvergenceAsserv = (Application.m_asservissement.convergence_conf == 1);
        m_ETAT_MATCH.DiagBlocage = Application.m_asservissement.diag_blocage;
        SerialiseTrame(	m_ETAT_MATCH.Encode());
    }
    // _____________________________________________
    if (m_ETAT_RACK.isTimeToSend())
    {
        m_ETAT_RACK.rack_cde_moteur = (int)Application.m_moteurs.m_cde_mot_6;
        m_ETAT_RACK.rack_consigne_moteur = (int)Application.m_asservissement_chariot.commande_moteur_chariot;
        m_ETAT_RACK.rack_convergence = (Application.m_asservissement_chariot.etat_asser_chariot==2)?1:0;
        m_ETAT_RACK.rack_modeAsservissement = Application.m_asservissement_chariot.etat_asser_chariot;
        SerialiseTrame(	m_ETAT_RACK.Encode());
    }
    // _____________________________________________
    if (m_COLOR_SENSOR.isTimeToSend())
    {
        m_COLOR_SENSOR.R=Application.m_capteurs.m_color_sensor_R;
        m_COLOR_SENSOR.G=Application.m_capteurs.m_color_sensor_G;
        m_COLOR_SENSOR.B=Application.m_capteurs.m_color_sensor_B;
        SerialiseTrame(	m_COLOR_SENSOR.Encode());
    }
}




//___________________________________________________________________________
 /*!
   \brief Point d'entree du module pour la serialisation de la trame

    - Fonction appelee pour demander la transformation d'une trame en serie d'octet envoyes sur la liaison serie
    - Prend les donnees une par une et les envoie sur la liaison serie
   \param trameBrute la trame a envoyer avec ses octets bruts
   \return --
   */
void CLaBotBox::SerialiseTrame(tStructTrameLaBotBox *trameBrute)
{
  unsigned char i=0;
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
unsigned char CLaBotBox::getCheckSumTrame(tStructTrameLaBotBox *trameBrute)
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
   \brief Fixe la même période d'émission pour toutes les trames
   \param period_msec la période souhaitée pour toutes les trames
            CTrameLaBotBox::NO_PERIODIC pour mettre toutes les trames non périodiques
   \return --
   */
void CLaBotBox::setAllTransmitPeriod(int period_msec)
{
    for (unsigned int i=0; i<m_nombre_trames; i++)
    {
        if (m_liste_trames[i])
        {
            m_liste_trames[i]->setTransmitPeriod(period_msec);
        }
    }
}











