/*! \file CGlobale.cpp
	\brief Classe qui contient toute l'application
*/
#include "mbed.h"
#include "RessourcesHardware.h"
#include "CGlobale.h"



//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CGlobale::CGlobale() 
{
  ModeFonctionnement = MODE_AUTONOME;
}

//___________________________________________________________________________
 /*!
   \brief Destructeur

   \param --
   \return --
*/
CGlobale::~CGlobale() 
{

}

//___________________________________________________________________________
 /*!
   \brief Point d'entrée pour l'execution de toute l'application

   \param --
   \return --
*/
void CGlobale::Run(void)
{
  // Initialise la vitesse de transmission avec le PC
  _rs232_pc_tx.baud(115200);
  _rs232_pc_tx.format(8, Serial::None, 1);   	// 8 bits de données / Pas de parité / 1 bit de stop
  _rs232_pc_rx.baud(115200);
  _rs232_pc_rx.format(8, Serial::None, 1);   	// 8 bits de données / Pas de parité / 1 bit de stop

 _rs232_pc_tx.printf("\n\rHello\n\r");

  //initialise la vitesse i2c
  //_i2c.frequency(200000);

  // Attends la montée de toutes les alimentation et l'initialisation de l'écran
  // Temps nécessaire en pratique pour que l'écran tactile ai fini de démarrer
  // avant de commencer à  lui en envoyer des messages (et d'en recevoir) 
  wait_ms(3000);

  // Active les pull up sur les entrées
  //_Etor1.mode(PullUp);
  //_Etor2.mode(PullUp);
  m_capteurs.Init();
  /*if(m_capteurs.m_color_sensor_OK)
	  _rs232_pc_tx.printf("\n\rCapteur couleur present\n\r");
  else {
	  _rs232_pc_tx.printf("\n\rPas de capteur couleur\n\r");
}*/
  //wait_ms(3000);

  //Init de l'asservissement chariot
  m_asservissement_chariot.Init();


 // Lecture des paramètres EEPROM et recopie dans les données membres 
 // de chaque classe en RAM
 m_eeprom.Read();

 // Initialisation des servos moteurs
 m_servos_sd20.Init();
 m_servos_ax.Init();
 
 //Init de l'asservissement chariot en cas de plantage de l'eeprom
 if ((Application.m_asservissement_chariot.commande_chariot_max_C==0) ||
     (Application.m_asservissement_chariot.compensation_zone_morte_dw_C==0) ||
     (Application.m_asservissement_chariot.compensation_zone_morte_up_C==0))
        m_asservissement_chariot.Init();

 _rs232_pc_tx.printf("ki_angle = %f\n\r", Application.m_asservissement.ki_angle);
 _rs232_pc_tx.printf("cde_max = %d\n\r", Application.m_asservissement.cde_max);
 _rs232_pc_tx.printf("cde_min = %d\n\r", Application.m_asservissement.cde_min);

 /*_led1 = true;_led2 = false;_led3 = false;_led4 = false;wait(1);
 _led1 = false;_led2 = true;_led3 = false;_led4 = false;wait(1);
 _led1 = false;_led2 = false;_led3 = true;_led4 = false;wait(1);
 _led1 = false;_led2 = false;_led3 = false;_led4 = true;wait(1);
 _led1 = false;_led2 = false;_led3 = false;_led4 = false;wait(1);*/

 switch(ModeFonctionnement) {
  	case MODE_AUTONOME : 			ModeAutonome();			break;
	case MODE_PILOTE_LABOTBOX : 	ModePiloteLaBotBox();	break;
	case MODE_PILOTE_TERMINAL : 	ModePiloteTerminal();	break;
	default : 						ModeAutonome();			break;
 }

  while(1) {
		// Ce code ne devrait jamais être atteint
  }
}










