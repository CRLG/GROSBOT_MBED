/*! \file CGlobale_ModePiloteLaBotBox.cpp
	\brief Classe qui contient toute l'application pour le mode de fonctionnement pilote via Anaconbot
*/
#include "mbed.h"
#include "RessourcesHardware.h"
#include "CGlobale.h"

//___________________________________________________________________________
 /*!
   \brief Gestion du mode piloté via Labotbox

   \param --
   \return --
*/
void CGlobale::ModePiloteLaBotBox(void)
{
   _rs232_pc_tx.printf("\n\rCeci est le mode piloté via LABOTBOX\n\r");
   m_LaBotBox.Start();
   m_LaBotBox.setAllTransmitPeriod(200);  // Toutes les trames sont envoyées à Labotbox avec la même période

   periodicTick.attach(&Application, &CGlobale::IRQ_Tick_ModePiloteLaBotBox, float(PERIODE_TICK)/1000.0f);

   while(1) {
       fflush(stdout); // ajout obligatoire ou un wait_us(1) sinon blocage de l'application
       if (Tick>0) {
           Tick = 0;
           SequenceurModePiloteLaBotBox();
       }
   }
}

//___________________________________________________________________________
 /*!
   \brief Fonction d'IRQ du timer

   \param --
   \return --
*/
void CGlobale::IRQ_Tick_ModePiloteLaBotBox(void)
{
    Tick = 1;
}


//___________________________________________________________________________
 /*!
   \brief Sequenceur de taches en mode Labotbox

   \param --
   \return --
*/
void CGlobale::SequenceurModePiloteLaBotBox(void)
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

    m_capteurs.Traitement();
    m_asservissement.CalculsMouvementsRobots();
    m_asservissement_chariot.Asser_chariot();
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
  }
  // ______________________________
  cpt500msec++;
  if (cpt500msec >= TEMPO_500msec) {
  	cpt500msec = 0;

    _led1 = !_led1;
  }
  // ______________________________
  cpt1sec++;
  if (cpt1sec >= TEMPO_1sec) {
  	cpt1sec = 0;
  }

}
