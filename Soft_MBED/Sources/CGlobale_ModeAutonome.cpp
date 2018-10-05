/*! \file CGlobale_ModeAutonome.cpp
	\brief Classe qui contient toute l'application pour le mode de fonctionnement autonome
*/
#include "mbed.h"
#include "RessourcesHardware.h"
#include "CGlobale.h"
#include "ConfigSpecifiqueCoupe.h"




//___________________________________________________________________________
 /*!
   \brief Point d'entrée pour l'execution de toute l'application

   \param --
   \return --
*/
void CGlobale::ModeAutonome(void)
{
   _rs232_pc_tx.printf("\n\rCeci est le mode autonome\n\r");
   m_x_debug=0;
   m_y_debug=0;
   m_teta_debug=0;

   m_LaBotBox.Start();

   m_match.Initialise();

   // Initialise une IRQ sur réception RS232 de la caméra
   // Ligne ci-dessous mise en commentaire volontairement tant que la pinoche RX est en l'air (pour éviter d'avoir des IRQ parasites)
   // TODO: à  décommenter dès que la caméra sera branchée
   //_rs232_camera_rx.attach(&Application, &CGlobale::ReceiveRS232_Camera);  	// Callback sur réception d'une donnée sur la RS232
  
   periodicTick.attach(&Application, &CGlobale::IRQ_Tick_ModeAutonome, (float(PERIODE_TICK)/1000.0f));

   while(1) {
       fflush(stdout); // ajout obligatoire ou un wait_us(1) sinon blocage de l'application
       if (Tick) {
           Tick = 0;
           SequenceurModeAutonome();
       }
   }
}

//___________________________________________________________________________
 /*!
   \brief Fonction d'IRQ du timer

   \param --
   \return --
*/
void CGlobale::IRQ_Tick_ModeAutonome(void)
{
	Tick = 1;
}

//___________________________________________________________________________
 /*!
   \brief Fonction d'IRQ sur reception RS232 de l'ecran

   \param --
   \return --
*/
void CGlobale::ReceiveRS232_Camera(void)
{
  char rxData;
  rxData = _rs232_camera_rx.getc();
  m_camera.Reconstitution(rxData);
}


//___________________________________________________________________________
 /*!
   \brief Sequenceur de taches en mode autonome

   \param --
   \return --
*/
void CGlobale::SequenceurModeAutonome(void)
{
  static unsigned int cpt10msec = 0;
  static unsigned int cpt20msec = 0;
  static unsigned int cpt50msec = 0;
  static unsigned int cpt100msec = 0;
  static unsigned int cpt200msec = 0;
  static unsigned int cpt500msec = 0;
  static unsigned int cpt1sec = 0;

  // ______________________________
  cpt10msec++;
  if (cpt10msec >= TEMPO_10msec) {
  	cpt10msec = 0;

    m_servos_sd20.GestionTransfert();
    m_LaBotBox.Execute();
  }	 

  // ______________________________
  cpt20msec++;
  if (cpt20msec >= TEMPO_20msec) {
	cpt20msec = 0;

    _led1 = !_led1;
   // _led1 = !_led1;

    m_capteurs.Traitement();
	m_asservissement.CalculsMouvementsRobots();
    m_asservissement_chariot.Asser_chariot();

	// Execute un pas de calcul du modele
    m_match.step();
 }


  // ______________________________
  cpt50msec++;
  if (cpt50msec >= TEMPO_50msec) {
  	cpt50msec = 0;

    m_leds.compute();

  }

  // ______________________________
  cpt100msec++;
  if (cpt100msec >= TEMPO_100msec) {
  	cpt100msec = 0;
  }

  // ______________________________
  cpt200msec++;
  if (cpt200msec >= TEMPO_200msec) {
  	cpt200msec = 0;

    // dès que le match est commencé, supprime l'IRQ sur RS232 de l'ecran pour ne pas risquer d'interrompre le match
    // lorsque le match est terminé, ré-active la communication entrante et diffuse à nouveau toutes les trames
    if (m_match.isMatchEnCours()) {
        if (m_LaBotBox.isRxEnabled()) {  // Ca permet de détecter un front montant du début de match
            m_LaBotBox.StopRx();
            m_LaBotBox.setAllTransmitPeriod(CTrameLaBotBox::NO_PERIODIC);  // Inhibe toutes les émissions de trames
            m_LaBotBox.m_ETAT_MATCH.setTransmitPeriod(200);                // sauf la trame spécifique match
        }
    }
    else {
        if (!m_LaBotBox.isRxEnabled()) {
            m_LaBotBox.Start();
            m_LaBotBox.setAllTransmitPeriod(200);  // Toutes les trames sont envoyées à Labotbox avec la même période
        }
    }
  }
  // ______________________________
  cpt500msec++;
  if (cpt500msec >= TEMPO_500msec) {
  	cpt500msec = 0;
  }
  // ______________________________
  cpt1sec++;
  if (cpt1sec >= TEMPO_1sec) {
  	cpt1sec = 0;

  }

}


//___________________________________________________________________________
 /*!
   \brief Verifie et traite les trames recues en attente

   \param --
   \return --
*/
void CGlobale::CheckReceptionTrameCamera(void)
{
  // ___________________________
  if  (m_camera.m_CAM_RESULT_TRACKING.isNewTrame() ) {
    // TODO : à  relier avec les entrées du modèle SIMULINK
    // modele.IN_xxx = m_camera.m_CAM_RESULT_TRACKING.Pos_X;
    // modele.IN_xxx = m_camera.m_CAM_RESULT_TRACKING.Pos_Y;
  }

}




