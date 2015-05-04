/*! \file CGlobale_ModePiloteLaBotBox.cpp
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
void CGlobale::ModePiloteLaBotBox(void)
{
   _rs232_pc_tx.printf("\n\rCeci est le mode piloté via LABOTBOX\n\r");
   // Initialise une IRQ sur réception RS232 d'LABOTBOX
   _rs232_pc_rx.attach(&Application, &CGlobale::ReceiveRS232_ModePiloteLaBotBox);  	// Callback sur réception d'une donnée sur la RS232

   periodicTick.attach(&Application, &CGlobale::IRQ_Tick_ModePiloteLaBotBox, (float(PERIODE_TICK)/1000.0));

   while(1) {
		if (Tick) {
			Tick = 0;
			CheckReceptionTrame();
			SequenceurModePiloteLaBotBox();
		}	
   }

}



// _____________________________________________________________
void CGlobale::ReceiveRS232_ModePiloteLaBotBox(void)
{
  char rxData;
  rxData = _rs232_pc_rx.getc();
  m_LaBotBox.Reconstitution(rxData);
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
   \brief Sequenceur de taches en mode autonome

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
	
	//SendTramesLaBotBox();
  }

  // ______________________________
  cpt100msec++;
  if (cpt100msec >= TEMPO_100msec) {
  	cpt100msec = 0;

	_led3 = !_led3;
  }

  // ______________________________
  cpt200msec++;
  if (cpt200msec >= TEMPO_200msec) {
  	cpt200msec = 0;

	//_rs232_pc_tx.printf("PuissanceG=%d / PuissanceD=%d", m_LaBotBox.in.PuissanceMotG, m_LaBotBox.in.PuissanceMotD); 
	//_rs232_pc_tx.putc(0xC);
	//_rs232_pc_tx.printf("VitesseConsigneAngle=%f - VitesseConsigneDist=%f\n\r", m_LaBotBox.m_COMMANDE_VITESSE_MVT.VitesseConsigneAngle, m_LaBotBox.m_COMMANDE_VITESSE_MVT.VitesseConsigneDist);
	//_rs232_pc_tx.printf("Capteur analogique = %f\n\r", _Eana1.read()*3.3);
	//_rs232_pc_tx.printf("Capteur Etor1 = %d\n\r", _Etor1.read());

	SendTramesLaBotBox();

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
  char cbuff[32];
  // ___________________________
  if  (m_LaBotBox.m_ELECTROBOT_CDE_MOTEURS.isNewTrame() ) {
    m_moteurs.CommandeVitesse(MOTEUR_1, (signed char)m_LaBotBox.m_ELECTROBOT_CDE_MOTEURS.cde_moteur_1);  // Attention : obligation de mettre le cast explicit en "signed", sinon, la valeur est interprétée non signée
    m_moteurs.CommandeVitesse(MOTEUR_2, (signed char)m_LaBotBox.m_ELECTROBOT_CDE_MOTEURS.cde_moteur_2);
    m_moteurs.CommandeVitesse(MOTEUR_3, (signed char)m_LaBotBox.m_ELECTROBOT_CDE_MOTEURS.cde_moteur_3);
    m_moteurs.CommandeVitesse(MOTEUR_4, (signed char)m_LaBotBox.m_ELECTROBOT_CDE_MOTEURS.cde_moteur_4);
    m_moteurs.CommandeVitesse(MOTEUR_5, (signed char)m_LaBotBox.m_ELECTROBOT_CDE_MOTEURS.cde_moteur_5);
    m_moteurs.CommandeVitesse(MOTEUR_6, (signed char)m_LaBotBox.m_ELECTROBOT_CDE_MOTEURS.cde_moteur_6);
  }

  // ___________________________
  if  (m_LaBotBox.m_ELECTROBOT_CDE_SERVOS.isNewTrame() ) {
	m_servos_sd20.CommandePositionVitesse(	m_LaBotBox.m_ELECTROBOT_CDE_SERVOS.NumeroServoMoteur1,
										m_LaBotBox.m_ELECTROBOT_CDE_SERVOS.PositionServoMoteur1,
										m_LaBotBox.m_ELECTROBOT_CDE_SERVOS.VitesseServoMoteur1
									);
	m_servos_sd20.CommandePositionVitesse(	m_LaBotBox.m_ELECTROBOT_CDE_SERVOS.NumeroServoMoteur2,
										m_LaBotBox.m_ELECTROBOT_CDE_SERVOS.PositionServoMoteur2,
										m_LaBotBox.m_ELECTROBOT_CDE_SERVOS.VitesseServoMoteur2
									);

   }

  // ___________________________
  if  (m_LaBotBox.m_ELECTROBOT_CDE_SERVOS_AX.isNewTrame() ) {
	// sous adressage : le champ commande_ax donne le type d'action à réaliser 
    switch (m_LaBotBox.m_ELECTROBOT_CDE_SERVOS_AX.commande_ax) {
        case cSERVO_AX_POSITION :
            m_servos_ax.setGoal(m_LaBotBox.m_ELECTROBOT_CDE_SERVOS_AX.num_servo_ax, 
                                m_LaBotBox.m_ELECTROBOT_CDE_SERVOS_AX.valeur_commande_ax); 
        break;
        case cSERVO_AX_VITESSE :
            m_servos_ax.setCRSpeed( m_LaBotBox.m_ELECTROBOT_CDE_SERVOS_AX.num_servo_ax, 
                                    m_LaBotBox.m_ELECTROBOT_CDE_SERVOS_AX.valeur_commande_ax); 
        break;

        case cSERVO_AX_CHANGE_ID :
            m_servos_ax.setID( m_LaBotBox.m_ELECTROBOT_CDE_SERVOS_AX.num_servo_ax, 
                               m_LaBotBox.m_ELECTROBOT_CDE_SERVOS_AX.valeur_commande_ax); 
        break;

        case cSERVO_AX_LED_STATE :
            m_servos_ax.setLedState( m_LaBotBox.m_ELECTROBOT_CDE_SERVOS_AX.num_servo_ax, 
                                     m_LaBotBox.m_ELECTROBOT_CDE_SERVOS_AX.valeur_commande_ax); 
        break;

        case cSERVO_AX_BUTEE_MIN :
            m_servos_ax.setButeeMinPosition( m_LaBotBox.m_ELECTROBOT_CDE_SERVOS_AX.num_servo_ax, 
                                             m_LaBotBox.m_ELECTROBOT_CDE_SERVOS_AX.valeur_commande_ax); 
           	sprintf(cbuff, "butee_min_servo_ax_%d", m_LaBotBox.m_ELECTROBOT_CDE_SERVOS_AX.num_servo_ax);  
            m_eeprom.setValue(cbuff, m_LaBotBox.m_ELECTROBOT_CDE_SERVOS_AX.valeur_commande_ax);
        break;

        case cSERVO_AX_BUTEE_MAX :
            m_servos_ax.setButeeMaxPosition( m_LaBotBox.m_ELECTROBOT_CDE_SERVOS_AX.num_servo_ax, 
                                            m_LaBotBox.m_ELECTROBOT_CDE_SERVOS_AX.valeur_commande_ax); 
           	sprintf(cbuff, "butee_max_servo_ax_%d", m_LaBotBox.m_ELECTROBOT_CDE_SERVOS_AX.num_servo_ax);  
            m_eeprom.setValue(cbuff, m_LaBotBox.m_ELECTROBOT_CDE_SERVOS_AX.valeur_commande_ax);
        break;

        default : 
        break; //  ne rien faire

    } // switch commande_ax
   }
    
  // ___________________________
  if  (m_LaBotBox.m_ASSERV_DIAG_WRITE_PARAM.isNewTrame() ) {
	// sous adressage : le champ commande_ax donne le type d'action à réaliser 
    switch (m_LaBotBox.m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_PARAM) {
        case cASSERV_SEUIL_CONV_DIST :
        	Application.m_asservissement.seuil_conv_distance=m_LaBotBox.m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE;
        	m_eeprom.setValue("seuil_conv_distance", m_LaBotBox.m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE);
        break;

        case cASSERV_SEUIL_CONV_ANGLE :
        	Application.m_asservissement.seuil_conv_angle=m_LaBotBox.m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE;
        	m_eeprom.setValue("seuil_conv_angle", m_LaBotBox.m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE);
        break;

        case cASSERV_DIAG_WR_KI_ANGLE : 
        	Application.m_asservissement.ki_angle=m_LaBotBox.m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE;
        	m_eeprom.setValue("ki_angle", m_LaBotBox.m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE);
        break;

        case cASSERV_DIAG_WR_KP_ANGLE : 
        	Application.m_asservissement.kp_angle=m_LaBotBox.m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE;
        	m_eeprom.setValue("kp_angle", m_LaBotBox.m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE);
        break;

        case cASSERV_DIAG_WR_KI_DISTANCE : 
        	Application.m_asservissement.ki_distance=m_LaBotBox.m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE;
        	m_eeprom.setValue("ki_distance", m_LaBotBox.m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE);
        break;

        case cASSERV_DIAG_WR_KP_DISTANCE : 
        	Application.m_asservissement.kp_distance=m_LaBotBox.m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE;
        	m_eeprom.setValue("kp_distance", m_LaBotBox.m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE);
        break;
        
        case cASSERV_DIAG_WR_CDE_MIN : 
        	Application.m_asservissement.cde_min=m_LaBotBox.m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE;
        	m_eeprom.setValue("cde_min", m_LaBotBox.m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE);
        break;

        case cASSERV_DIAG_WR_CDE_MAX : 
        	Application.m_asservissement.cde_max=m_LaBotBox.m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE;
        	m_eeprom.setValue("cde_max", m_LaBotBox.m_ASSERV_DIAG_WRITE_PARAM.ASSERV_DIAG_WRITE_VALUE);
        break;

    } // switch 
  }
 
//

  // ___________________________
  if  (m_LaBotBox.m_COMMANDE_MVT_MANUEL.isNewTrame() ) {
	m_asservissement.CommandeManuelle(	m_LaBotBox.m_COMMANDE_MVT_MANUEL.PuissanceMotG, 
										m_LaBotBox.m_COMMANDE_MVT_MANUEL.PuissanceMotD
									 );
  }

  // ___________________________
  if  (m_LaBotBox.m_COMMANDE_DISTANCE_ANGLE.isNewTrame() ) {
   m_asservissement.CommandeMouvementDistanceAngle(	m_LaBotBox.m_COMMANDE_DISTANCE_ANGLE.distance_consigne,
   													m_LaBotBox.m_COMMANDE_DISTANCE_ANGLE.angle_consigne
   												  );
  }

  // ___________________________
  if  (m_LaBotBox.m_COMMANDE_MVT_XY.isNewTrame() ) {
   m_asservissement.CommandeMouvementXY_A(	m_LaBotBox.m_COMMANDE_MVT_XY.X_consigne,
   											m_LaBotBox.m_COMMANDE_MVT_XY.Y_consigne
   										 );
  }




  // ___________________________
  if  (m_LaBotBox.m_COMMANDE_VITESSE_MVT.isNewTrame() ) {
	m_asservissement.CommandeVitesseMouvement(	(float)m_LaBotBox.m_COMMANDE_VITESSE_MVT.vitesse_avance_max,
												(float)m_LaBotBox.m_COMMANDE_VITESSE_MVT.vitesse_rotation_max
											 );

/*  TODO : a quelle variable relier les indices de sportivité de la trame
	m_LaBotBox.m_COMMANDE_VITESSE_MVT.indice_sportivite_decel;
	m_LaBotBox.m_COMMANDE_VITESSE_MVT.indice_sportivite_accel;
*/

  }
}





//___________________________________________________________________________
 /*!
   \brief Envoie les trames vers LABOTBOX

   \param --
   \return --
*/
void CGlobale::SendTramesLaBotBox(void)
{   // _____________________________________________
	m_LaBotBox.m_ETAT_ASSERVISSEMENT.cde_moteur_G = (int)m_roues.m_cde_roue_G;
	m_LaBotBox.m_ETAT_ASSERVISSEMENT.cde_moteur_D = (int)m_roues.m_cde_roue_D;
	m_LaBotBox.m_ETAT_ASSERVISSEMENT.Convergence = (m_asservissement.diag_blocage==1)?2:m_asservissement.convergence_conf;
	m_LaBotBox.m_ETAT_ASSERVISSEMENT.ModeAsservissement = m_asservissement.ModeAsservissement;
	m_LaBotBox.SerialiseTrame(	m_LaBotBox.m_ETAT_ASSERVISSEMENT.Encode());

    // _____________________________________________
	m_LaBotBox.m_POSITION_CODEURS.PosCodeurG = m_roues.getCodeurG();
	m_LaBotBox.m_POSITION_CODEURS.PosCodeurD = m_roues.getCodeurD();
 	m_LaBotBox.SerialiseTrame(	m_LaBotBox.m_POSITION_CODEURS.Encode());
    // _____________________________________________
	m_LaBotBox.m_POSITION_ABSOLUE_XY_TETA.x_pos = PHYS2BRUTE_x_pos(m_asservissement.X_robot);
	m_LaBotBox.m_POSITION_ABSOLUE_XY_TETA.y_pos = PHYS2BRUTE_y_pos(m_asservissement.Y_robot);
	m_LaBotBox.m_POSITION_ABSOLUE_XY_TETA.teta_pos = PHYS2BRUTE_teta_pos(m_asservissement.angle_robot);
 	m_LaBotBox.SerialiseTrame(	m_LaBotBox.m_POSITION_ABSOLUE_XY_TETA.Encode());
	// _____________________________________________
    m_LaBotBox.m_ETAT_PID_ASSERVISSEMENT.vitesse_avance_robot_filt      = PHYS2BRUTE_vitesse_avance_robot_filt(m_asservissement.vitesse_avance_robot_filt);
    m_LaBotBox.m_ETAT_PID_ASSERVISSEMENT.consigne_vitesse_avance_filt   = PHYS2BRUTE_consigne_vitesse_avance_filt(m_asservissement.consigne_vitesse_avance_filt);
    m_LaBotBox.m_ETAT_PID_ASSERVISSEMENT.vitesse_rotation_robot_filt    = PHYS2BRUTE_vitesse_rotation_robot_filt(m_asservissement.vitesse_rotation_robot_filt);
    m_LaBotBox.m_ETAT_PID_ASSERVISSEMENT.consigne_vitesse_rotation_filt = PHYS2BRUTE_consigne_vitesse_rotation_filt(m_asservissement.consigne_vitesse_rotation_filt);
 	m_LaBotBox.SerialiseTrame(	m_LaBotBox.m_ETAT_PID_ASSERVISSEMENT.Encode());
    // _____________________________________________
	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_1.Eana1 = PHYS2BRUTE_Eana1(Application.m_capteurs.m_b_Eana1);
	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_1.Eana2 = PHYS2BRUTE_Eana2(Application.m_capteurs.m_b_Eana2);
	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_1.Eana3 = PHYS2BRUTE_Eana3(Application.m_capteurs.m_b_Eana3);
	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_1.Eana4 = PHYS2BRUTE_Eana4(Application.m_capteurs.m_b_Eana4);
	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_1.Eana5 = PHYS2BRUTE_Eana5(Application.m_capteurs.m_b_Eana5);
	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_1.Eana6 = PHYS2BRUTE_Eana6(Application.m_capteurs.m_b_Eana6);
	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_1.Eana7 = PHYS2BRUTE_Eana7(Application.m_capteurs.m_b_Eana7);
	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_1.Eana8 = PHYS2BRUTE_Eana8(Application.m_capteurs.m_b_Eana8);
 	m_LaBotBox.SerialiseTrame(	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_1.Encode());
   // _____________________________________________
	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_2.Eana9 = PHYS2BRUTE_Eana9(Application.m_capteurs.m_b_Eana9);
	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_2.Eana10 = PHYS2BRUTE_Eana10(Application.m_capteurs.m_b_Eana10);
	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_2.Eana11 = PHYS2BRUTE_Eana11(Application.m_capteurs.m_b_Eana11);
	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_2.Eana12 = PHYS2BRUTE_Eana12(Application.m_capteurs.m_b_Eana12);
	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_2.Eana13 = PHYS2BRUTE_Eana13(Application.m_capteurs.m_b_Eana13);
	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_2.Vbat = PHYS2BRUTE_Vbat(Application.m_capteurs.m_tension_batterie);
	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_2.Etor1 = !Application.m_capteurs.m_b_Etor1;
	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_2.Etor2 = !Application.m_capteurs.m_b_Etor2;
	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_2.Etor3 = !Application.m_capteurs.m_b_Etor3;
	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_2.Etor4 = !Application.m_capteurs.m_b_Etor4;
	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_2.Etor5 = !Application.m_capteurs.m_b_Etor5;
	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_2.Etor6 = !Application.m_capteurs.m_b_Etor6;
	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_2.Etor_CAN_TX = !Application.m_capteurs.m_b_Etor_CanTx;
	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_2.Etor_CAN_RX = !Application.m_capteurs.m_b_Etor_CanRx;
	m_LaBotBox.SerialiseTrame(	m_LaBotBox.m_ELECTROBOT_ETAT_CAPTEURS_2.Encode());
    // _____________________________________________
	m_LaBotBox.m_ELECTROBOT_ETAT_CODEURS_1_2.Codeur_1 = Application.m_capteurs.m_CumulCodeurPosition1;
	m_LaBotBox.m_ELECTROBOT_ETAT_CODEURS_1_2.Codeur_2 = Application.m_capteurs.m_CumulCodeurPosition2;
	m_LaBotBox.SerialiseTrame(m_LaBotBox.m_ELECTROBOT_ETAT_CODEURS_1_2.Encode());
    // _____________________________________________
	m_LaBotBox.m_ELECTROBOT_ETAT_CODEURS_3_4.Codeur_3 = Application.m_capteurs.m_CumulCodeurPosition3;
	m_LaBotBox.m_ELECTROBOT_ETAT_CODEURS_3_4.Codeur_4 = Application.m_capteurs.m_CumulCodeurPosition4;
	m_LaBotBox.SerialiseTrame(m_LaBotBox.m_ELECTROBOT_ETAT_CODEURS_3_4.Encode());
    // _____________________________________________
	m_LaBotBox.m_ELECTROBOT_ETAT_TELEMETRES.Telemetre1 = Application.m_capteurs.m_telemetres.m_distance[0];
	m_LaBotBox.m_ELECTROBOT_ETAT_TELEMETRES.Telemetre2 = Application.m_capteurs.m_telemetres.m_distance[1];
	m_LaBotBox.m_ELECTROBOT_ETAT_TELEMETRES.Telemetre3 = Application.m_capteurs.m_telemetres.m_distance[2];
	m_LaBotBox.m_ELECTROBOT_ETAT_TELEMETRES.Telemetre4 = Application.m_capteurs.m_telemetres.m_distance[3];
	m_LaBotBox.SerialiseTrame(m_LaBotBox.m_ELECTROBOT_ETAT_TELEMETRES.Encode());
}





