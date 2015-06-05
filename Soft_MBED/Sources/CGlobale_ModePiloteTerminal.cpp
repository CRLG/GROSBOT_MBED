/*! \file CGlobale_ModePiloteTerminal.cpp
	\brief Classe qui contient toute l'application pour le mode de fonctionnement pilote via Anaconbot
*/
#include "mbed.h"
#include "RessourcesHardware.h"
#include "CGlobale.h"

void SendTrameEcran(void);
void ScanI2C(void);

//___________________________________________________________________________
 /*!
   \brief Gestion du mode piloté via Anaconbot

   \param --
   \return --
*/
void CGlobale::ModePiloteTerminal(void)
{
   	_rs232_pc_tx.printf("%c", 0xc);
   _rs232_pc_tx.printf("\n\rCeci est le mode piloté par un terminal RS232\n\r");
   // Initialise une IRQ sur réception RS232 d'ANACONBOT
   _rs232_pc_rx.attach(&Application, &CGlobale::ReceiveRS232_ModePiloteTerminal);  	// Callback sur réception d'une donnée sur la RS232
   // Initialise une IRQ sur réception RS232 de l'écran
   _rs232_ecran_rx.attach(&Application, &CGlobale::ReceiveRS232_Ecran);  	// Callback sur réception d'une donnée sur la RS232

   periodicTick.attach(&Application, &CGlobale::IRQ_Tick_ModePiloteTerminal, (float(PERIODE_TICK)/1000.0));
   

    ScanI2C();
    wait_ms(4000);
   
   while(1) {
        CheckReceptionTrame();
        CheckReceptionTrameEcran();
        if (Tick) {
			Tick = 0;
			SequenceurModePiloteTerminal();
		}	
   }

}



// _____________________________________________________________
void CGlobale::ReceiveRS232_ModePiloteTerminal(void)
{
  char rxData;
  rxData = _rs232_pc_rx.getc();
}


//___________________________________________________________________________
 /*!
   \brief Fonction d'IRQ du timer

   \param --
   \return --
*/
void CGlobale::IRQ_Tick_ModePiloteTerminal(void)
{
	Tick = 1;
}


//___________________________________________________________________________
 /*!
   \brief Sequenceur de taches en mode autonome

   \param --
   \return --
*/
void CGlobale::SequenceurModePiloteTerminal(void)
{
  static unsigned int cpt10msec = 0;
  static unsigned int cpt20msec = 0;
  static unsigned int cpt50msec = 0;
  static unsigned int cpt100msec = 0;
  static unsigned int cpt200msec = 0;
  static unsigned int cpt500msec = 0;
  static unsigned int cpt1sec = 0;

  static unsigned char compteur=1;
  static unsigned char toggle=0;

  // ______________________________
  cpt10msec++;
  if (cpt10msec >= TEMPO_10msec) {
  	cpt10msec = 0;

 	m_servos_sd20.GestionTransfert();
 }

  // ______________________________
  cpt20msec++;
  if (cpt20msec >= TEMPO_20msec) {
  	cpt20msec = 0;

	m_capteurs.Traitement();
	//TO REMOVE: Pour tester le codeur ascenseur
	unsigned char fincourse;
	fincourse=!Application.m_capteurs.m_b_Etor2;
	if(fincourse==1)
		Application.m_capteurs.m_CumulCodeurPosition2 = 0;
		
    m_asservissement.CalculsMouvementsRobots();

  }


  // ______________________________
  cpt50msec++;
  if (cpt50msec >= TEMPO_50msec) {
  	cpt50msec = 0;
							
  }

  // ______________________________
  cpt100msec++;
  if (cpt100msec >= TEMPO_100msec) {
  	cpt100msec = 0;
	SendTramesEcran();

  }

  // ______________________________
  cpt200msec++;
  if (cpt200msec >= TEMPO_200msec) {
  	cpt200msec = 0;

	_rs232_pc_tx.printf("%c", 0xc);
	_rs232_pc_tx.printf("Entrees Etor = %d %d %d %d %d %d %d %d\n\r", 
				Application.m_capteurs.m_b_Etor1,
				Application.m_capteurs.m_b_Etor2,
				Application.m_capteurs.m_b_Etor3,
				Application.m_capteurs.m_b_Etor4,
				Application.m_capteurs.m_b_Etor5,
				Application.m_capteurs.m_b_Etor6,
                Application.m_capteurs.m_b_Etor_CanRx,
                Application.m_capteurs.m_b_Etor_CanTx
				);

	_rs232_pc_tx.printf("Entrees Eana MBED = %.3f %.3f %.3f %.3f %.3f %.3f\n\r", 
				Application.m_capteurs.m_b_Mes_Vbat,
				Application.m_capteurs.m_b_Eana1,
				Application.m_capteurs.m_b_Eana2,
				Application.m_capteurs.m_b_Eana3,
				Application.m_capteurs.m_b_Eana4,
				Application.m_capteurs.m_b_Eana5
				);

	_rs232_pc_tx.printf("Entrees Eana dsPIC1 = %.3f %.3f %.3f %.3f\n\r", 
				Application.m_capteurs.m_b_Eana6,
				Application.m_capteurs.m_b_Eana7,
				Application.m_capteurs.m_b_Eana8,
				Application.m_capteurs.m_b_Eana9
				);

	_rs232_pc_tx.printf("Entrees Eana dsPIC2 = %.3f %.3f %.3f %.3f\n\r", 
				Application.m_capteurs.m_b_Eana10,
				Application.m_capteurs.m_b_Eana11,
				Application.m_capteurs.m_b_Eana12,
				Application.m_capteurs.m_b_Eana13
				);

 	_rs232_pc_tx.printf("Tension batterie = %.2f [V] / %s\n\r", 
				Application.m_capteurs.m_tension_batterie,
				((Application.m_capteurs.m_alerte_batterie_faible==0)?"OK":"! Batterie faible")
                );
	_rs232_pc_tx.printf("Codeurs brut = %d %d %d %d\n\r", 
				Application.m_capteurs.m_CodeurPosition1,
				Application.m_capteurs.m_CodeurPosition2,
				Application.m_capteurs.m_CodeurPosition3,
				Application.m_capteurs.m_CodeurPosition4
				);

	_rs232_pc_tx.printf("Codeurs cumul = %d %d %d %d\n\r", 
				Application.m_capteurs.m_CumulCodeurPosition1,
				Application.m_capteurs.m_CumulCodeurPosition2,
				Application.m_capteurs.m_CumulCodeurPosition3,
				Application.m_capteurs.m_CumulCodeurPosition4
				);

	_rs232_pc_tx.printf("Err COM dsPIC1=%d / dsPIC2=%d\n\r", 
				Application.m_capteurs.m_compteurErrCom_dsPIC1,
				Application.m_capteurs.m_compteurErrCom_dsPIC2
				);


	_rs232_pc_tx.printf("Capteurs US = %.2f %.2f %.2f %.2f\n\r", 
				Application.m_capteurs.m_telemetres.m_distance[0],
				Application.m_capteurs.m_telemetres.m_distance[1],
                Application.m_capteurs.m_telemetres.m_distance[2],
                Application.m_capteurs.m_telemetres.m_distance[3]
				);

	_rs232_pc_tx.printf("Commandes moteurs = %.1f %.1f %.1f %.1f %.1f %.1f\n\r",
                Application.m_roues.m_cde_roue_G,
                Application.m_roues.m_cde_roue_D,
                Application.m_moteurs.m_cde_mot_3,
                Application.m_moteurs.m_cde_mot_4,
                Application.m_moteurs.m_cde_mot_5,
                Application.m_moteurs.m_cde_mot_6
                ); 

	_rs232_pc_tx.printf("Position Ascenseur = %d\n\r",
                Application.m_capteurs.m_CumulCodeurPosition2                
                );

	_rs232_pc_tx.printf("Position robot x=%.4f / y=%.4f / teta=%.4f rad\n\r",
                Application.m_asservissement.X_robot,
                Application.m_asservissement.Y_robot,
                Application.m_asservissement.angle_robot                
                );

  }
  // ______________________________
  cpt500msec++;
  if (cpt500msec >= TEMPO_500msec) {
  	cpt500msec = 0;
	_led1=!_led1;

    compteur++;
    if (compteur>2) { 
        compteur = 0; 
        toggle = !toggle;
        //Application.m_servos_sd20.CommandePositionVitesse(13, (toggle&0x1)==0?800:130, 100);

        //Application.m_moteurs.CommandeVitesse(MOTEUR_3, (toggle&0x1)==0?-50:50);
        //Application.m_moteurs.CommandeVitesse(MOTEUR_4, (toggle&0x1)==0?50:-50);
        //Application.m_moteurs.CommandeVitesse(MOTEUR_5, (toggle&0x1)==0?-50:50);
        //Application.m_moteurs.CommandeVitesse(MOTEUR_6, (toggle&0x1)==0?-50:50);
    }


  }
  // ______________________________
  cpt1sec++;
  if (cpt1sec >= TEMPO_1sec) {
  	cpt1sec = 0;

	//_led3 = !_led3;
  }

}


void ScanI2C(void)
{
 int i;
 char buff[1];
 unsigned char result;

 _rs232_pc_tx.printf("SCAN DU BUS I2C:\n\r");
 for (i=0; i<0xFF; i=i+2) {
    result = _i2c.read(i, buff, 1);
    if (result==0) {
      _rs232_pc_tx.printf("Echo sur @0x%x\n\r", i);
    }
 }
}

//___________________________________________________________________________
 /*!
   \brief Envoie les trames vers l'ecran

   \param --
   \return --
   \remarks n'emet pas toutes les trames d'un seul coup pour ne pas risquer
   			de retarder le sequenceur
*/
#define CONVERSION_VOLT2TRAME 10.0







