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

   // Initialise une IRQ sur réception RS232 de l'écran
   _rs232_ecran_rx.attach(&Application, &CGlobale::ReceiveRS232_Ecran);  	// Callback sur réception d'une donnée sur la RS232
   
   // Initialise une IRQ sur réception RS232 de la caméra
   // Ligne ci-dessous mise en commentaire volontairement tant que la pinoche RX est en l'air (pour éviter d'avoir des IRQ parasites)
   // TODO: à décommenter dès que la caméra sera branchée
   //_rs232_camera_rx.attach(&Application, &CGlobale::ReceiveRS232_Camera);  	// Callback sur réception d'une donnée sur la RS232
  
  
   
   periodicTick.attach(&Application, &CGlobale::IRQ_Tick_ModeAutonome, (float(PERIODE_TICK)/1000.0));

   while(1) {
		if (Tick) {
			Tick = 0;
			CheckReceptionTrameEcran();
            CheckReceptionTrameCamera();
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
void CGlobale::ReceiveRS232_Ecran(void)
{
  char rxData;
  rxData = _rs232_ecran_rx.getc();
  m_ecran_tactile.Reconstitution(rxData);
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
  unsigned char matchEnCours = 0;

  matchEnCours = ( (m_match.m_duree >=0.02) && (m_match.m_duree < 89.92) );
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

	// TODO : dès que le match est commencé, supprime l'IRQ sur RS232 de l'écran pour ne pas risquer d'interrompre le match
	// Exécute un pas de calcul du modèle
	m_match.step();

    // Avant et après le match, on peut se permettre d'envoyer plus rapidement 
    // les trames à l'écran pour une meilleur fluidité
    if (matchEnCours == 0) {
        SendTramesEcran();    
    } 
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
				
	//m_match.debug();
	if (matchEnCours) {
        SendTramesEcran();
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
   \brief Envoie les trames vers l'ecran

   \param --
   \return --
   \remarks n'emet pas toutes les trames d'un seul coup pour ne pas risquer
   			de retarder le sequenceur
*/
#define CONVERSION_VOLT2TRAME 10.0
void CGlobale::SendTramesEcran(void)
{
  static unsigned char numTrame=0;

  // Petit patch pour n'envoyer que la trame "durée"
  // à la fin pour que l'affichage "9...8...7..." soit fluide sur l'écran
  if ( (m_match.m_duree >= 1.0f) && (m_match.m_duree < 89.09) ) {
    numTrame = 2; // 2 = trame qui contient "Duree match"
  }

  switch(numTrame)
  {

    // _______________________
	case 0 :
		m_ecran_tactile.m_ETAT_CAPTEURS_1.Eana1 = Application.m_capteurs.m_b_Eana1 * CONVERSION_VOLT2TRAME;
		m_ecran_tactile.m_ETAT_CAPTEURS_1.Eana2 = Application.m_capteurs.m_b_Eana2 * CONVERSION_VOLT2TRAME;
		m_ecran_tactile.m_ETAT_CAPTEURS_1.Eana3 = Application.m_capteurs.m_b_Eana3 * CONVERSION_VOLT2TRAME;
		m_ecran_tactile.m_ETAT_CAPTEURS_1.Eana4 = Application.m_capteurs.m_b_Eana4 * CONVERSION_VOLT2TRAME;
		m_ecran_tactile.m_ETAT_CAPTEURS_1.Eana5 = Application.m_capteurs.m_b_Eana5 * CONVERSION_VOLT2TRAME;
		m_ecran_tactile.m_ETAT_CAPTEURS_1.Eana6 = Application.m_capteurs.m_b_Eana6 * CONVERSION_VOLT2TRAME;
		m_ecran_tactile.m_ETAT_CAPTEURS_1.Eana7 = Application.m_capteurs.m_b_Eana7 * CONVERSION_VOLT2TRAME;
		m_ecran_tactile.m_ETAT_CAPTEURS_1.Eana8 = Application.m_capteurs.m_b_Eana8 * CONVERSION_VOLT2TRAME;
		m_ecran_tactile.SerialiseTrame(	m_ecran_tactile.m_ETAT_CAPTEURS_1.Encode());
	    numTrame++;
	break;

     // _______________________
	case 1 :
		m_ecran_tactile.m_ETAT_CAPTEURS_2.Eana9 = Application.m_capteurs.m_b_Eana9 * CONVERSION_VOLT2TRAME;
		m_ecran_tactile.m_ETAT_CAPTEURS_2.Eana10 = Application.m_capteurs.m_b_Eana10 * CONVERSION_VOLT2TRAME;
		m_ecran_tactile.m_ETAT_CAPTEURS_2.Eana11 = Application.m_capteurs.m_b_Eana11 * CONVERSION_VOLT2TRAME;
		m_ecran_tactile.m_ETAT_CAPTEURS_2.Eana12 = Application.m_capteurs.m_b_Eana12 * CONVERSION_VOLT2TRAME;
		m_ecran_tactile.m_ETAT_CAPTEURS_2.Eana13 = Application.m_capteurs.m_b_Eana13 * CONVERSION_VOLT2TRAME;
		m_ecran_tactile.m_ETAT_CAPTEURS_2.Vbat = Application.m_capteurs.m_tension_batterie * CONVERSION_VOLT2TRAME;

		m_ecran_tactile.m_ETAT_CAPTEURS_2.Etor1 = !Application.m_capteurs.m_b_Etor1;
		m_ecran_tactile.m_ETAT_CAPTEURS_2.Etor2 = !Application.m_capteurs.m_b_Etor2;
		m_ecran_tactile.m_ETAT_CAPTEURS_2.Etor3 = !Application.m_capteurs.m_b_Etor3;
		m_ecran_tactile.m_ETAT_CAPTEURS_2.Etor4 = !Application.m_capteurs.m_b_Etor4;
		m_ecran_tactile.m_ETAT_CAPTEURS_2.Etor5 = !Application.m_capteurs.m_b_Etor5;
		m_ecran_tactile.m_ETAT_CAPTEURS_2.Etor6 = !Application.m_capteurs.m_b_Etor6;
		m_ecran_tactile.m_ETAT_CAPTEURS_2.Etor_CAN_TX = !Application.m_capteurs.m_b_Etor_CanTx;
		m_ecran_tactile.m_ETAT_CAPTEURS_2.Etor_CAN_RX = !Application.m_capteurs.m_b_Etor_CanRx;

		m_ecran_tactile.SerialiseTrame(	m_ecran_tactile.m_ETAT_CAPTEURS_2.Encode());
	    numTrame++;
	break;

  // _______________________
   case 2 : 
   		m_ecran_tactile.m_ETAT_MATCH.TempsMatch = (unsigned char)(m_match.m_duree);
		m_ecran_tactile.m_ETAT_MATCH.CouleurEquipe = m_match.m_couleur_equipe==1?0x69:0x96;   
		m_ecran_tactile.m_ETAT_MATCH.ModeFonctionnement = Application.ModeFonctionnement;   
		m_ecran_tactile.m_ETAT_MATCH.ObstacleDetecte = m_match.m_obstacleDetecte; 
		m_ecran_tactile.m_ETAT_MATCH.ConvergenceAsserv = (Application.m_asservissement.convergence_conf == 1);
		m_ecran_tactile.m_ETAT_MATCH.DiagBlocage = Application.m_asservissement.diag_blocage;

		m_ecran_tactile.SerialiseTrame(	m_ecran_tactile.m_ETAT_MATCH.Encode());

	    numTrame++;
   break;
  // _______________________
   case 3 : 
   		m_ecran_tactile.m_ETAT_CODEURS_1_2.Codeur_1 = Application.m_capteurs.m_CodeurPosition1;
   		m_ecran_tactile.m_ETAT_CODEURS_1_2.Codeur_2 = Application.m_capteurs.m_CodeurPosition2;

		m_ecran_tactile.SerialiseTrame(m_ecran_tactile.m_ETAT_CODEURS_1_2.Encode());

	    numTrame++;
   break;
  // _______________________
   case 4 : 
   		m_ecran_tactile.m_ETAT_CODEURS_3_4.Codeur_3 = Application.m_capteurs.m_CodeurPosition3;
   		m_ecran_tactile.m_ETAT_CODEURS_3_4.Codeur_3 = Application.m_capteurs.m_CodeurPosition4;

		m_ecran_tactile.SerialiseTrame(m_ecran_tactile.m_ETAT_CODEURS_3_4.Encode());

	    numTrame++;
   break;
  // _______________________
   case 5 : 
   		m_ecran_tactile.m_ETAT_TELEMETRE.Telemetre1 = Application.m_capteurs.m_telemetres.m_distance[0];
   		m_ecran_tactile.m_ETAT_TELEMETRE.Telemetre2 = Application.m_capteurs.m_telemetres.m_distance[1];
   		m_ecran_tactile.m_ETAT_TELEMETRE.Telemetre3 = Application.m_capteurs.m_telemetres.m_distance[2];
   		m_ecran_tactile.m_ETAT_TELEMETRE.Telemetre4 = Application.m_capteurs.m_telemetres.m_distance[3];

		m_ecran_tactile.SerialiseTrame(m_ecran_tactile.m_ETAT_TELEMETRE.Encode());

	    numTrame++;
   break;
  // _______________________
   case 6 : 
   		m_ecran_tactile.m_POSITION_ROBOT.PositionRobot_X = Application.m_asservissement.X_robot * 10.0f;
   		m_ecran_tactile.m_POSITION_ROBOT.PositionRobot_Y = Application.m_asservissement.Y_robot * 10.0f;
   		m_ecran_tactile.m_POSITION_ROBOT.PositionRobot_Teta = Application.m_asservissement.angle_robot * 1000.0f;

		m_ecran_tactile.SerialiseTrame(m_ecran_tactile.m_POSITION_ROBOT.Encode());

	    numTrame = 0;
   break;       
   // _______________________
   default : 
   		numTrame = 0;
   break;
  }


}


//___________________________________________________________________________
 /*!
   \brief Verifie et traite les trames recues en attente

   \param --
   \return --
*/
void CGlobale::CheckReceptionTrameEcran(void)
{
  // ___________________________
  if  (m_ecran_tactile.m_ETAT_ECRAN.isNewTrame() ) {
    //_led3 = !_led3;
    switch(m_ecran_tactile.m_ETAT_ECRAN.CodeCommande) {
        // _________________________________________
		case CMDE_CHOIX_EQUIPE : // Choix couleur équipe
			if (m_ecran_tactile.m_ETAT_ECRAN.Valeur == 0x96) { 
              m_match.m_couleur_equipe = 0;
			}
			else if (m_ecran_tactile.m_ETAT_ECRAN.Valeur == 0x69) {
			  m_match.m_couleur_equipe = 1;
			}
			else {
			 	// ne rien faire : commande invalide
			}
		break;
        // _________________________________________
		case CMDE_TEST_ACTIONNEURS :		
			 m_match.m_dde_test_actionneurs=1;
		break;
        // _________________________________________
		case CMDE_PILOTAGE_MOTEUR_1 : //...		
            m_moteurs.CommandeVitesse(MOTEUR_1, m_ecran_tactile.m_ETAT_ECRAN.Valeur);
		break;
        // _________________________________________
		case CMDE_PILOTAGE_MOTEUR_2 : //...		
            m_moteurs.CommandeVitesse(MOTEUR_2, m_ecran_tactile.m_ETAT_ECRAN.Valeur);
		break;
        // _________________________________________
		case CMDE_PILOTAGE_MOTEUR_3 : //...		
            m_moteurs.CommandeVitesse(MOTEUR_3, m_ecran_tactile.m_ETAT_ECRAN.Valeur);
		break;
        // _________________________________________
		case CMDE_PILOTAGE_MOTEUR_4 : //...	
			if ((m_ecran_tactile.m_ETAT_ECRAN.Valeur == 60) || (m_ecran_tactile.m_ETAT_ECRAN.Valeur == -60)) {
				m_moteurs.CommandeVitesse(MOTEUR_4, 50);
			}
			else {
				m_moteurs.CommandeVitesse(MOTEUR_4, m_ecran_tactile.m_ETAT_ECRAN.Valeur);			
			}	
            //m_moteurs.CommandeVitesse(MOTEUR_4, m_ecran_tactile.m_ETAT_ECRAN.Valeur);
		break;
        // _________________________________________
		case CMDE_PILOTAGE_MOTEUR_5 : //...		
            m_moteurs.CommandeVitesse(MOTEUR_5, m_ecran_tactile.m_ETAT_ECRAN.Valeur);
		break;
        // _________________________________________
		case CMDE_PILOTAGE_MOTEUR_6 : //...		
            m_moteurs.CommandeVitesse(MOTEUR_6, m_ecran_tactile.m_ETAT_ECRAN.Valeur);
		break;
        // _________________________________________
		case CMDE_CHOIX_NUMERO_STRATEGIE : //Choix de la stratégie		
            m_match.m_choix_strategie = m_ecran_tactile.m_ETAT_ECRAN.Valeur;
		break;


        // _________________________________________
		case CMDE_PILOTAGE_ELECTROVANNE :
            m_moteurs.CommandeVitesse(MOTEUR_ELECTROVANNE, m_ecran_tactile.m_ETAT_ECRAN.Valeur); 
		break;
		  
        // _________________________________________
		case CMDE_PILOTAGE_SERVO_NERF :
            m_Servos.CommandePositionVitesse(SERVO_NERF, m_ecran_tactile.m_ETAT_ECRAN.Valeur*25.5f, 0);
		break;
        // _________________________________________
		case CMDE_PILOTAGE_SERVO_KMAR :
            m_Servos.CommandePositionVitesse(SERVO_KMAR, m_ecran_tactile.m_ETAT_ECRAN.Valeur*25.5f, 0);
		break;
        // _________________________________________
		case CMDE_PILOTAGE_SERVO_FEU :
            m_Servos.CommandePositionVitesse(SERVO_RETOURNE_FEU, m_ecran_tactile.m_ETAT_ECRAN.Valeur*25.5f, 0);
		break;
        // _________________________________________
		case CMDE_PILOTAGE_SERVO_CROCHET_AR :
            m_Servos.CommandePositionVitesse(SERVO_CROCHET_AR, m_ecran_tactile.m_ETAT_ECRAN.Valeur*25.5f, 0);
		break;
        // _________________________________________
		case CMDE_PILOTAGE_SERVO_ANCRAGE_FILET :
            m_Servos.CommandePositionVitesse(SERVO_ANCRAGE_FILET, m_ecran_tactile.m_ETAT_ECRAN.Valeur*25.5f, 0);
		break;

		// _______________________
		default : 
		break;


	} // switch


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
    // TODO : à relier avec les entrées du modèle SIMULINK
    // modele.IN_xxx = m_camera.m_CAM_RESULT_TRACKING.Pos_X;
    // modele.IN_xxx = m_camera.m_CAM_RESULT_TRACKING.Pos_Y;
  }

}

