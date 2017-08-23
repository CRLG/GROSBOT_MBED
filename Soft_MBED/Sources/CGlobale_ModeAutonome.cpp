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

   // Initialise une IRQ sur réception RS232 d'LABOTBOX
   _rs232_pc_rx.attach(&Application, &CGlobale::ReceiveRS232_ModePiloteLaBotBox);

   // Initialise une IRQ sur réception RS232 de la caméra
   // Ligne ci-dessous mise en commentaire volontairement tant que la pinoche RX est en l'air (pour éviter d'avoir des IRQ parasites)
   // TODO: �  décommenter dès que la caméra sera branchée
   //_rs232_camera_rx.attach(&Application, &CGlobale::ReceiveRS232_Camera);  	// Callback sur réception d'une donnée sur la RS232
  
   periodicTick.attach(&Application, &CGlobale::IRQ_Tick_ModeAutonome, (float(PERIODE_TICK)/1000.0f));
    m_match.Initialise();

   while(1) {
	   CheckReceptionTrame();
        //CheckReceptionTrameCamera();
	   wait_us(1);
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
  bool matchEnCours = false;

  matchEnCours = ( (m_match.m_duree >=0.02) && (m_match.m_duree < 89.92) );
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
	m_asservissement_chariot.Asser_chariot();

	// TODO : des que le match est commence, supprime l'IRQ sur RS232 de l'ecran pour ne pas risquer d'interrompre le match

	// Execute un pas de calcul du modele
	m_match.step();

	// Avant et apres le match, on peut se permettre d'envoyer plus rapidement
	// les trames a  l'ecran pour une meilleure fluidite
	/*if (!matchEnCours) {
		SendTramesEcranLaBotBox(matchEnCours);
	} */
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
  }

  // ______________________________
  cpt200msec++;
  if (cpt200msec >= TEMPO_200msec) {
  	cpt200msec = 0;
    SendTramesEcranLaBotBox(matchEnCours);
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
  	_led1 = (!_led1);

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
    // TODO : �  relier avec les entrées du modèle SIMULINK
    // modele.IN_xxx = m_camera.m_CAM_RESULT_TRACKING.Pos_X;
    // modele.IN_xxx = m_camera.m_CAM_RESULT_TRACKING.Pos_Y;
  }

}

//___________________________________________________________________________
 /*!
   \brief Envoie les trames vers LABOTBOX

   \param --
   \return --
*/
void CGlobale::SendTramesEcranLaBotBox(bool activMode)
{
	if (activMode)
	{
		m_LaBotBox.m_ETAT_MATCH.TempsMatch = (unsigned char)(m_match.m_duree);
		m_LaBotBox.m_ETAT_MATCH.CouleurEquipe = m_match.m_couleur_equipe;
		m_LaBotBox.m_ETAT_MATCH.ModeFonctionnement = Application.ModeFonctionnement;
		m_LaBotBox.m_ETAT_MATCH.ObstacleDetecte = m_match.m_obstacleDetecte;
		m_LaBotBox.m_ETAT_MATCH.ConvergenceAsserv = (Application.m_asservissement.convergence_conf == 1);
		m_LaBotBox.m_ETAT_MATCH.DiagBlocage = Application.m_asservissement.diag_blocage;
		m_LaBotBox.SerialiseTrame(	m_LaBotBox.m_ETAT_MATCH.Encode());

	}
	else
	{
		m_LaBotBox.m_ETAT_MATCH.TempsMatch = (unsigned char)(m_match.m_duree);
		m_LaBotBox.m_ETAT_MATCH.CouleurEquipe = m_match.m_couleur_equipe;
		m_LaBotBox.m_ETAT_MATCH.ModeFonctionnement = Application.ModeFonctionnement;
		m_LaBotBox.m_ETAT_MATCH.ObstacleDetecte = m_match.m_obstacleDetecte;
		m_LaBotBox.m_ETAT_MATCH.ConvergenceAsserv = (Application.m_asservissement.convergence_conf == 1);
		m_LaBotBox.m_ETAT_MATCH.DiagBlocage = Application.m_asservissement.diag_blocage;
		m_LaBotBox.SerialiseTrame(	m_LaBotBox.m_ETAT_MATCH.Encode());

		// _____________________________________________
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
}


