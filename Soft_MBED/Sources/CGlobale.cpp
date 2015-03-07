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
   \brief Point d'entr�e pour l'execution de toute l'application

   \param --
   \return --
*/
void CGlobale::Run(void)
{
  // Initialise la vitesse de transmission avec le PC
  _rs232_pc_tx.baud(57600);
  _rs232_pc_tx.format(8, Serial::None, 1);   	// 8 bits de donn�es / Pas de parit� / 1 bit de stop
  _rs232_pc_rx.baud(57600);
  _rs232_pc_rx.format(8, Serial::None, 1);   	// 8 bits de donn�es / Pas de parit� / 1 bit de stop

 _rs232_pc_tx.printf("\n\rHello\n\r");

  // Initialise la vitesse de transmission avec l'�cran
  _rs232_ecran_tx.baud(57600);
  _rs232_ecran_tx.format(8, Serial::None, 1);   	// 8 bits de donn�es / Pas de parit� / 1 bit de stop
  _rs232_ecran_tx.baud(57600);
  _rs232_ecran_tx.format(8, Serial::None, 1);   	// 8 bits de donn�es / Pas de parit� / 1 bit de stop

  // Attends la mont�e de toutes les alimentation et l'initialisation de l'�cran
  // Temps n�cessaire en pratique pour que l'�cran tactile ai fini de d�marrer
  // avant de commencer � lui en envoyer des messages (et d'en recevoir) 
  wait_ms(3000); 


  // Active les pull up sur les entr�es
  //_Etor1.mode(PullUp);
  //_Etor2.mode(PullUp);
  m_capteurs.Init();

 // Lecture des param�tres EEPROM et recopie dans les donn�es membres 
 // de chaque classe en RAM
 m_eeprom.Read();
 
 // Initialisation des servos moteurs
 m_Servos.Init();

 _rs232_pc_tx.printf("ki_angle = %f\n\r", Application.m_asservissement.ki_angle);
 _rs232_pc_tx.printf("cde_max = %d\n\r", Application.m_asservissement.cde_max);
 _rs232_pc_tx.printf("cde_min = %d\n\r", Application.m_asservissement.cde_min);

 switch(ModeFonctionnement) {
  	case MODE_AUTONOME : 			ModeAutonome();			break;
	case MODE_PILOTE_ANACONBOT : 	ModePiloteAnaconbot();	break;
	case MODE_PILOTE_TERMINAL : 	ModePiloteTerminal();	break;
	default : 						ModeAutonome();			break;
 }

  while(1) {
		// Ce code ne devrait jamais �tre atteint
  }
}









