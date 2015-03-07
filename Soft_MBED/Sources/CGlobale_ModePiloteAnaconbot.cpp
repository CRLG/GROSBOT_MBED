/*! \file CGlobale_ModePiloteAnaconbot.cpp
	\brief Classe qui contient toute l'application pour le mode de fonctionnement pilote via Anaconbot
*/
#include "mbed.h"
#include "RessourcesHardware.h"
#include "CGlobale.h"

void SendTrameEcran(void);

//___________________________________________________________________________
 /*!
   \brief Gestion du mode piloté via Anaconbot

   \param --
   \return --
*/
void CGlobale::ModePiloteAnaconbot(void)
{
   _rs232_pc_tx.printf("\n\rCeci est le mode piloté via ANACONBOT\n\r");
   // Initialise une IRQ sur réception RS232 d'ANACONBOT
   _rs232_pc_rx.attach(&Application, &CGlobale::ReceiveRS232_ModePiloteAnaconbot);  	// Callback sur réception d'une donnée sur la RS232


   periodicTick.attach(&Application, &CGlobale::IRQ_Tick_ModePiloteAnaconbot, (float(PERIODE_TICK)/1000.0));

   while(1) {
		if (Tick) {
			Tick = 0;
			CheckReceptionTrame();
			SequenceurModePiloteAnaconbot();
		}	
   }

}



// _____________________________________________________________
void CGlobale::ReceiveRS232_ModePiloteAnaconbot(void)
{
  char rxData;
  rxData = _rs232_pc_rx.getc();
  m_Anaconbot.Reconstitution(rxData);
}



//___________________________________________________________________________
 /*!
   \brief Fonction d'IRQ du timer

   \param --
   \return --
*/
void CGlobale::IRQ_Tick_ModePiloteAnaconbot(void)
{
	Tick = 1;
}


//___________________________________________________________________________
 /*!
   \brief Sequenceur de taches en mode autonome

   \param --
   \return --
*/
void CGlobale::SequenceurModePiloteAnaconbot(void)
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

 	m_Servos.GestionTransfert();
 }

  // ______________________________
  cpt20msec++;
  if (cpt20msec >= TEMPO_20msec) {
  	cpt20msec = 0;

	m_capteurs.Traitement();
    m_asservissement.CalculsMouvementsRobots();

  }


  // ______________________________
  cpt50msec++;
  if (cpt50msec >= TEMPO_50msec) {
  	cpt50msec = 0;
	
	//SendTramesAnaconbot();
  }

  // ______________________________
  cpt100msec++;
  if (cpt100msec >= TEMPO_100msec) {
  	cpt100msec = 0;

	//_led3 = !_led3;
  }

  // ______________________________
  cpt200msec++;
  if (cpt200msec >= TEMPO_200msec) {
  	cpt200msec = 0;

	//_rs232_pc_tx.printf("PuissanceG=%d / PuissanceD=%d", m_Anaconbot.in.PuissanceMotG, m_Anaconbot.in.PuissanceMotD); 
	//_rs232_pc_tx.putc(0xC);
	//_rs232_pc_tx.printf("VitesseConsigneAngle=%f - VitesseConsigneDist=%f\n\r", m_Anaconbot.m_COMMANDE_VITESSE_MVT.VitesseConsigneAngle, m_Anaconbot.m_COMMANDE_VITESSE_MVT.VitesseConsigneDist);
	//_rs232_pc_tx.printf("Capteur analogique = %f\n\r", _Eana1.read()*3.3);
	//_rs232_pc_tx.printf("Capteur Etor1 = %d\n\r", _Etor1.read());

	SendTramesAnaconbot();

  }
  // ______________________________
  cpt500msec++;
  if (cpt500msec >= TEMPO_500msec) {
  	cpt500msec = 0;
	_led1=!_led1;

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
void CGlobale::CheckReceptionTrame(void)
{
  // ___________________________
  if  (m_Anaconbot.m_COMMANDE_MVT_MANUEL.isNewTrame() ) {
	m_asservissement.CommandeManuelle(	(float)m_Anaconbot.m_COMMANDE_MVT_MANUEL.PuissanceMotG, 
										(float)m_Anaconbot.m_COMMANDE_MVT_MANUEL.PuissanceMotD
									 );
	//_led4 = !_led4;
  }

  // ___________________________
  if  (m_Anaconbot.m_COMMANDE_DISTANCE_ANGLE.isNewTrame() ) {
   m_asservissement.CommandeMouvementDistanceAngle(	m_Anaconbot.m_COMMANDE_DISTANCE_ANGLE.distance_consigne,
   													m_Anaconbot.m_COMMANDE_DISTANCE_ANGLE.angle_consigne
   												  );
  }

  // ___________________________
  if  (m_Anaconbot.m_COMMANDE_MVT_XY.isNewTrame() ) {
   m_asservissement.CommandeMouvementXY_A(	m_Anaconbot.m_COMMANDE_MVT_XY.consigne_X,
   											m_Anaconbot.m_COMMANDE_MVT_XY.consigne_Y
   										 );
  }




  // ___________________________
  if  (m_Anaconbot.m_COMMANDE_VITESSE_MVT.isNewTrame() ) {
	m_asservissement.CommandeVitesseMouvement(	(float)m_Anaconbot.m_COMMANDE_VITESSE_MVT.VitesseConsigneDist,
												(float)m_Anaconbot.m_COMMANDE_VITESSE_MVT.VitesseConsigneAngle
											 );
  }


  // ___________________________
  if  (m_Anaconbot.m_COMMANDE_SERVOS_MOTEURS.isNewTrame() ) {
	m_Servos.CommandePositionVitesse(	m_Anaconbot.m_COMMANDE_SERVOS_MOTEURS.NumeroServoMoteur1,
										m_Anaconbot.m_COMMANDE_SERVOS_MOTEURS.PositionServoMoteur1,
										m_Anaconbot.m_COMMANDE_SERVOS_MOTEURS.VitesseServoMoteur1
									);
	m_Servos.CommandePositionVitesse(	m_Anaconbot.m_COMMANDE_SERVOS_MOTEURS.NumeroServoMoteur2,
										m_Anaconbot.m_COMMANDE_SERVOS_MOTEURS.PositionServoMoteur2,
										m_Anaconbot.m_COMMANDE_SERVOS_MOTEURS.VitesseServoMoteur2
									);
	//_led2 = !_led2;
   }

  // ___________________________
  if  (m_Anaconbot.m_ASSERV_DIAG_WR_KI_DISTANCE.isNewTrame() ) {
	Application.m_asservissement.ki_distance=m_Anaconbot.m_ASSERV_DIAG_WR_KI_DISTANCE.KI_DISTANCE;
	m_eeprom.setValue("ki_distance",m_Anaconbot.m_ASSERV_DIAG_WR_KI_DISTANCE.KI_DISTANCE);
   }
  // ___________________________
  if  (m_Anaconbot.m_ASSERV_DIAG_WR_KP_DISTANCE.isNewTrame() ) {
	Application.m_asservissement.kp_distance=m_Anaconbot.m_ASSERV_DIAG_WR_KP_DISTANCE.KP_DISTANCE;
	m_eeprom.setValue("kp_distance",m_Anaconbot.m_ASSERV_DIAG_WR_KP_DISTANCE.KP_DISTANCE);
   }
  // ___________________________
  if  (m_Anaconbot.m_ASSERV_DIAG_WR_KI_ANGLE.isNewTrame() ) {
	Application.m_asservissement.ki_angle=m_Anaconbot.m_ASSERV_DIAG_WR_KI_ANGLE.KI_ANGLE;
	m_eeprom.setValue("ki_angle",m_Anaconbot.m_ASSERV_DIAG_WR_KI_ANGLE.KI_ANGLE);
   }
  // ___________________________
  if  (m_Anaconbot.m_ASSERV_DIAG_WR_KP_ANGLE.isNewTrame() ) {
	Application.m_asservissement.kp_angle=m_Anaconbot.m_ASSERV_DIAG_WR_KP_ANGLE.KP_ANGLE;
	m_eeprom.setValue("kp_angle",m_Anaconbot.m_ASSERV_DIAG_WR_KP_ANGLE.KP_ANGLE);
   }   
		
  // ___________________________
  if  (m_Anaconbot.m_ASSERV_DIAG_WR_SEUIL_CONV_ANGLE.isNewTrame() ) {
	Application.m_asservissement.seuil_conv_angle=m_Anaconbot.m_ASSERV_DIAG_WR_SEUIL_CONV_ANGLE.SEUIL_CONV_ANGLE;
	m_eeprom.setValue("seuil_conv_angle",m_Anaconbot.m_ASSERV_DIAG_WR_SEUIL_CONV_ANGLE.SEUIL_CONV_ANGLE);
   }
  // ___________________________
  if  (m_Anaconbot.m_ASSERV_DIAG_WR_SEUIL_CONV_DIST.isNewTrame() ) {
	Application.m_asservissement.seuil_conv_distance=m_Anaconbot.m_ASSERV_DIAG_WR_SEUIL_CONV_DIST.SEUIL_CONV_DIST;
	m_eeprom.setValue("seuil_conv_distance",m_Anaconbot.m_ASSERV_DIAG_WR_SEUIL_CONV_DIST.SEUIL_CONV_DIST);
   }
// ___________________________
  if  (m_Anaconbot.m_ASSERV_DIAG_WR_COMPTEUR_MAX.isNewTrame() ) {
	Application.m_asservissement.compteur_max=m_Anaconbot.m_ASSERV_DIAG_WR_COMPTEUR_MAX.COMPTEUR_MAX;
	m_eeprom.setValue("compteur_max",m_Anaconbot.m_ASSERV_DIAG_WR_COMPTEUR_MAX.COMPTEUR_MAX);
   }
   
 // ___________________________
  if  (m_Anaconbot.m_ASSERV_DIAG_WR_CDE_MIN.isNewTrame() ) {
	Application.m_asservissement.cde_min=m_Anaconbot.m_ASSERV_DIAG_WR_CDE_MIN.CDE_MIN;
	m_eeprom.setValue("cde_min",m_Anaconbot.m_ASSERV_DIAG_WR_CDE_MIN.CDE_MIN);
   }

// ___________________________
  if  (m_Anaconbot.m_ASSERV_DIAG_WR_CDE_MAX.isNewTrame() ) {
	Application.m_asservissement.cde_max=m_Anaconbot.m_ASSERV_DIAG_WR_CDE_MAX.CDE_MAX;
	m_eeprom.setValue("cde_max",m_Anaconbot.m_ASSERV_DIAG_WR_CDE_MAX.CDE_MAX);
   }   




}





//___________________________________________________________________________
 /*!
   \brief Envoie les trames vers ANACONBOT

   \param --
   \return --
*/
void CGlobale::SendTramesAnaconbot(void)
{
	m_Anaconbot.m_ETAT_ASSERVISSEMENT.cde_moteur_G = (int)m_roues.m_cde_roue_G;
	m_Anaconbot.m_ETAT_ASSERVISSEMENT.cde_moteur_D = (int)m_roues.m_cde_roue_D;
	m_Anaconbot.m_ETAT_ASSERVISSEMENT.Convergence = m_asservissement.convergence_conf;
	m_Anaconbot.SerialiseTrame(	m_Anaconbot.m_ETAT_ASSERVISSEMENT.Encode());
    //_led4 = !_led4;

	m_Anaconbot.m_POSITION_CODEURS.PosCodeurG = m_roues.getCodeurG();
	m_Anaconbot.m_POSITION_CODEURS.PosCodeurD = m_roues.getCodeurD();
 	m_Anaconbot.SerialiseTrame(	m_Anaconbot.m_POSITION_CODEURS.Encode());

	m_Anaconbot.m_POSITION_ABSOLUE_TETA.teta_pos = m_asservissement.angle_robot;
 	m_Anaconbot.SerialiseTrame(	m_Anaconbot.m_POSITION_ABSOLUE_TETA.Encode());
	
	m_Anaconbot.m_POSITION_ABSOLUE_XY.x_pos = m_asservissement.X_robot;
	m_Anaconbot.m_POSITION_ABSOLUE_XY.y_pos = m_asservissement.Y_robot;
 	m_Anaconbot.SerialiseTrame(	m_Anaconbot.m_POSITION_ABSOLUE_XY.Encode());
	
	// Dans la trame 0x154, mettre : 
	//	consigne_vitesse_avance_filt -> 1ere partie de la trame
	//	vitesse_avance_robot_filt	 -> 2ème partie de la trame
	// Petite astuce pour cette trame : les noms ne sont pas les mêmes car ce sont les flux de l'ancienne messagerie qui sont utilisés
	m_Anaconbot.m_ETAT_PID_DISTANCE.int_terme_distance = m_asservissement.vitesse_avance_robot_filt;
	m_Anaconbot.m_ETAT_PID_DISTANCE.cde_distance = 	m_asservissement.consigne_vitesse_avance_filt;
	m_Anaconbot.SerialiseTrame(m_Anaconbot.m_ETAT_PID_DISTANCE.Encode());

	// Dans la trame 0x155, mettre : 
	//  consigne_vitesse_rotation_filt -> 1ère partie de la trame
	// vitesse_rotation_robot_filt	   -> 2ème partie de la trame
	// Petite astuce pour cette trame : les noms ne sont pas les mêmes car ce sont les flux de l'ancienne messagerie qui sont utilisés
	m_Anaconbot.m_ETAT_PID_ANGLE.cde_angle = m_asservissement.consigne_vitesse_rotation_filt;
	m_Anaconbot.m_ETAT_PID_ANGLE.int_terme_angle = m_asservissement.vitesse_rotation_robot_filt; 
	m_Anaconbot.SerialiseTrame(m_Anaconbot.m_ETAT_PID_ANGLE.Encode());


	// Trame des capteurs analogiques
	/*
	if (m_capteurs.m_ultrason_AV < 255) 	{ m_Anaconbot.m_ETAT_CAPTEURS_ANA.Eana0_J20 = m_capteurs.m_ultrason_AV; 	}
	else 									{ m_Anaconbot.m_ETAT_CAPTEURS_ANA.Eana0_J20 = 255;	}

	if (m_capteurs.m_ultrason_AR < 255) 	{ m_Anaconbot.m_ETAT_CAPTEURS_ANA.Eana1_J21 = m_capteurs.m_ultrason_AR; 	}
	else 									{ m_Anaconbot.m_ETAT_CAPTEURS_ANA.Eana1_J21 = 255;	}
	*/
	m_Anaconbot.m_ETAT_CAPTEURS_ANA.Eana0_J20 = 0;
	m_Anaconbot.m_ETAT_CAPTEURS_ANA.Eana1_J21 = 0;
	m_Anaconbot.m_ETAT_CAPTEURS_ANA.Eana2_J22 = 0;
	m_Anaconbot.m_ETAT_CAPTEURS_ANA.Eana3_J26 = 0;
	m_Anaconbot.m_ETAT_CAPTEURS_ANA.Eana4_J27 = 0;
	m_Anaconbot.m_ETAT_CAPTEURS_ANA.Eana5_J23 = 0;
	m_Anaconbot.m_ETAT_CAPTEURS_ANA.Eana6_J28 = 0;
	m_Anaconbot.m_ETAT_CAPTEURS_ANA.Eana7_J29 = 0;

	m_Anaconbot.SerialiseTrame(m_Anaconbot.m_ETAT_CAPTEURS_ANA.Encode());

	// Trame des capteurs TOR
	m_Anaconbot.m_ETAT_CAPTEURS_TOR.IOA0_J2 = Application.m_capteurs.m_b_Etor1; //tirette
	m_Anaconbot.m_ETAT_CAPTEURS_TOR.IOA1_J3 = Application.m_capteurs.m_b_Etor2;
	m_Anaconbot.m_ETAT_CAPTEURS_TOR.IOA2_J4 = Application.m_capteurs.m_b_Etor3;
	m_Anaconbot.m_ETAT_CAPTEURS_TOR.IOA3_J5 = Application.m_capteurs.m_b_Etor4;
	m_Anaconbot.m_ETAT_CAPTEURS_TOR.IOA4_J6 = Application.m_capteurs.m_b_Etor5;
	m_Anaconbot.m_ETAT_CAPTEURS_TOR.IOA5_J12 = Application.m_capteurs.m_b_Etor6;
	m_Anaconbot.m_ETAT_CAPTEURS_TOR.IOA6_J12 = Application.m_capteurs.m_b_Etor_CanRx;
	m_Anaconbot.m_ETAT_CAPTEURS_TOR.IOA7_J12 = Application.m_capteurs.m_b_Etor_CanTx;
	m_Anaconbot.SerialiseTrame(m_Anaconbot.m_ETAT_CAPTEURS_TOR.Encode());
	
	m_Anaconbot.m_ETAT_CAPTEURS_SPECIAUX.ULTRASON_1 = Application.m_capteurs.m_telemetres.m_distance[0];
	m_Anaconbot.m_ETAT_CAPTEURS_SPECIAUX.ULTRASON_2 = Application.m_capteurs.m_telemetres.m_distance[1];
	m_Anaconbot.m_ETAT_CAPTEURS_SPECIAUX.ULTRASON_3 = Application.m_capteurs.m_telemetres.m_distance[2];
	m_Anaconbot.m_ETAT_CAPTEURS_SPECIAUX.ULTRASON_4 = Application.m_capteurs.m_telemetres.m_distance[3];
	m_Anaconbot.m_ETAT_CAPTEURS_SPECIAUX.ULTRASON_5 = 0;
	m_Anaconbot.m_ETAT_CAPTEURS_SPECIAUX.ULTRASON_6 = 0;
	m_Anaconbot.m_ETAT_CAPTEURS_SPECIAUX.ULTRASON_7 = 0;
	m_Anaconbot.m_ETAT_CAPTEURS_SPECIAUX.ULTRASON_8 = 0;
	m_Anaconbot.SerialiseTrame(m_Anaconbot.m_ETAT_CAPTEURS_SPECIAUX.Encode());

}





