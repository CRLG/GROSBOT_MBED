/*! \file CMatch.cpp
	\brief Classe qui contient toute l'application
*/
#include "mbed.h"
#include "RessourcesHardware.h"
#include "CMatch.h"
#include "CGlobale.h"
#include "ConfigSpecifiqueCoupe.h"

extern "C" {
 #include "ModeleRobot.h"  		// Le code généré par Matlab Simulink est en "C" et pas en "C++"
}



//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CMatch::CMatch() 
{
    Initialise();
}

//___________________________________________________________________________
 /*!
   \brief Destructeur

   \param --
   \return --
*/
CMatch::~CMatch() 
{

}


//___________________________________________________________________________
 /*!
   \brief Initialise toutes les structures de donnéess du match à jouer

   \param --
   \return --
*/
void CMatch::Initialise(void)
{
  m_duree = 0;
  m_couleur_equipe = 0;
  m_dde_test_actionneurs = 0;
  m_choix_strategie = 0;

  ModeleRobot_initialize(0);
  m_DdeMvtManuel_old = 0;
  m_DdeMvtDistanceAngle_old = 0;
  m_DdeMvtXY_old = 0;
  m_DdeMvtXYTeta_old=0;

  m_ResetCodeurAscenseur_old=0;
  m_ResetCodeurBarillet_old=0;
  //ModeleRobot_P.SFunction_p22=Application.TempsMaxGonflage;

  m_obstacleDetecte=0;

  _led1 = 0;
  _led2 = 0;
	_led3 = 0;
	_led4 = 0;
}
	

//___________________________________________________________________________
 /*!
   \brief Execute un pas de calcul du match

   \param --
   \return --
*/
void CMatch::step(void)
{
	// ___________________________ 
	// Recopie les entrées des capteurs vers les entrées du modèle
	
	//Ecran
	ModeleRobot_U.IN_CouleurEquipe = m_couleur_equipe;
	ModeleRobot_U.IN_demande_test_actionneurs = m_dde_test_actionneurs;
    // TODO : relier le numéro de stratégie à une entrée du modèle
    // ModeleRobot_U.IN_xxx = m_choix_strategie;
	//Pour binariser le capteur de depression
	if (Application.m_capteurs.m_b_Eana1>=0.75)
		ModeleRobot_U.IN_isDepression = 1;
	else
		ModeleRobot_U.IN_isDepression = 0;
	
	//capteurs US
	//pour les obstacles on ne passe plus un booleen a la strategie mais la distance
	ModeleRobot_U.IN_ObstacleAVG=Application.m_capteurs.m_telemetres.m_distance[0];
	ModeleRobot_U.IN_ObstacleARD=Application.m_capteurs.m_telemetres.m_distance[1];
	ModeleRobot_U.IN_ObstacleARG=Application.m_capteurs.m_telemetres.m_distance[2];
	ModeleRobot_U.IN_ObstacleAVD=Application.m_capteurs.m_telemetres.m_distance[3];

	//Capteurs TOR
	ModeleRobot_U.IN_Tirette = Application.m_capteurs.m_b_Etor1; //1 = tirette enlevee
	ModeleRobot_U.IN_FinCourseAscenseur =!Application.m_capteurs.m_b_Etor2; //0=fin de course on inverse pour avoir une logique 1 = atteint
	//m_b_Etor3 est déjà pris pour piloter l'electrovanne
	ModeleRobot_U.IN_FinCourseHauteAscenseur =!Application.m_capteurs.m_b_Etor4;

	//codeurs
	ModeleRobot_U.IN_Ascenseur_pos=Application.m_capteurs.m_CumulCodeurPosition2;
	ModeleRobot_U.IN_Barillet_pos=Application.m_capteurs.m_CumulCodeurPosition1;
		
	//____________________________
	//Variables de l'aservissement
	ModeleRobot_U.IN_ConvergenceMvt = Application.m_asservissement.convergence_conf;  
	ModeleRobot_U.IN_x_pos = Application.m_asservissement.X_robot;
	ModeleRobot_U.IN_y_pos = Application.m_asservissement.Y_robot;
	ModeleRobot_U.IN_teta_pos = Application.m_asservissement.angle_robot;
	ModeleRobot_U.IN_ConvergenceMvt_Rapide = Application.m_asservissement.convergence_rapide;
	ModeleRobot_U.IN_Vitesse = Application.m_asservissement.vitesse_avance_robot; //vitesse de deplacement: a verifier avec guigui
	ModeleRobot_U.IN_SensDeplacement = Application.m_asservissement.erreur_distance; //sens de deplacement: en fonction du signe si + alors marche avant
	//TODO:
	//diag de blocage, pour l'instant on claque les tempo
	
	// ___________________________ 
	//Appel de la strategie du modele matlab
	ModeleRobot_step();
	
	// ___________________________ 
	// Remise à zéro des variables pour les tests actionneurs pour pouvoir les recommencer   
	//ModeleRobot_U.IN_demande_test_actionneurs=0;
	//m_dde_test_actionneurs=0;
	
	
	// ___________________________ 
	//Consignes pour l'asservissement
	Application.m_asservissement.CommandeVitesseMouvement(ModeleRobot_Y.OUT_ConsigneVitesseDistance, ModeleRobot_Y.OUT_ConsigneVitesseAngle);
	
	//Mvt Manuel
	if (ModeleRobot_Y.OUT_DdeMvtManuel != m_DdeMvtManuel_old) {
		Application.m_asservissement.CommandeManuelle(ModeleRobot_Y.OUT_CommandeManuelleG, ModeleRobot_Y.OUT_CommandeManuelleD);
	}
	m_DdeMvtManuel_old = ModeleRobot_Y.OUT_DdeMvtManuel;
	
	//Mvt Distance Angle
	if (ModeleRobot_Y.OUT_DdeMvtDistanceAngle != m_DdeMvtDistanceAngle_old) {
		Application.m_asservissement.CommandeMouvementDistanceAngle(ModeleRobot_Y.OUT_ConsigneDistance, ModeleRobot_Y.OUT_ConsigneTeta);
	}
	m_DdeMvtDistanceAngle_old = ModeleRobot_Y.OUT_DdeMvtDistanceAngle;
	
	//Mvt XY
	if (ModeleRobot_Y.OUT_DdeMvtXY != m_DdeMvtXY_old) {
		Application.m_asservissement.CommandeMouvementXY(ModeleRobot_Y.OUT_ConsigneX, ModeleRobot_Y.OUT_ConsigneY);
	}
	m_DdeMvtXY_old = ModeleRobot_Y.OUT_DdeMvtXY;
	
	//Mvt XYTeta
	if (ModeleRobot_Y.OUT_DdeMvtXYTeta != m_DdeMvtXYTeta_old) {
		Application.m_asservissement.CommandeMouvementXY_TETA(ModeleRobot_Y.OUT_ConsigneX, ModeleRobot_Y.OUT_ConsigneY, ModeleRobot_Y.OUT_ConsigneTeta);
	}
	m_DdeMvtXYTeta_old = ModeleRobot_Y.OUT_DdeMvtXYTeta;
	
	if (ModeleRobot_Y.OUT_DdeRecalagePosition[0] != m_DdeRecalagePosition_old) {
		Application.m_asservissement.setPosition_XYTeta(ModeleRobot_Y.OUT_DdeRecalagePosition[1], ModeleRobot_Y.OUT_DdeRecalagePosition[2], ModeleRobot_Y.OUT_DdeRecalagePosition[3]);
	}
	m_DdeRecalagePosition_old = ModeleRobot_Y.OUT_DdeRecalagePosition[0];
	
	//RAZ des codeurs
	if (ModeleRobot_Y.OUT_ResetCodeurAscenseur!=m_ResetCodeurAscenseur_old){
		if (ModeleRobot_Y.OUT_ResetCodeurAscenseur==1) {
        	Application.m_capteurs.RAZ_PositionCodeur(CODEUR_ASCENSEUR,0);
		}
    }
	m_ResetCodeurAscenseur_old=ModeleRobot_Y.OUT_ResetCodeurAscenseur;

/*	if (ModeleRobot_Y.OUT_ResetCodeurBarillet!=m_ResetCodeurBarillet_old){
		if (ModeleRobot_Y.OUT_ResetCodeurBarillet==1) {
        	Application.m_capteurs.RAZ_PositionCodeur(CODEUR_BARILLET,0);
		}
    }
	m_ResetCodeurBarillet_old=ModeleRobot_Y.OUT_ResetCodeurBarillet;   */
	
	// ___________________________ 
	//Consignes actionneurs
    // Les commande d'actionneurs peuvent venir soit du modèle, soit de l'écran tactile

	
	if (ModeleRobot_Y.OUT_CommandeMoteur[MOTEUR_ASCENSEUR-1] != m_old_cde_mot[MOTEUR_ASCENSEUR]) { 
        Application.m_moteurs.CommandeVitesse(MOTEUR_ASCENSEUR, ModeleRobot_Y.OUT_CommandeMoteur[MOTEUR_ASCENSEUR-1]); //ASCENSEUR
        m_old_cde_mot[MOTEUR_ASCENSEUR] = ModeleRobot_Y.OUT_CommandeMoteur[MOTEUR_ASCENSEUR-1];
    }

	//ALERTE: codé en dur
	//si l'ascenseur atteint son capteur de fin de course et que la consigne est négative
	//on coupe la commande (valeur écrasée)
 	if ((Application.m_capteurs.m_b_Etor2<=0)&& (ModeleRobot_Y.OUT_CommandeMoteur[MOTEUR_ASCENSEUR-1]<0)){
		Application.m_moteurs.CommandeVitesse(MOTEUR_ASCENSEUR, 0); //ASCENSEUR
	}

	// ___________________________ 
	// Commande des servos moteurs
	 
	if (ModeleRobot_Y.OUT_CommandeServo[SERVO_PINCE_G-1] != m_old_cde_servo[SERVO_PINCE_G]) {
		if (ModeleRobot_Y.OUT_RelacheServo[SERVO_PINCE_G-1]==0)
			Application.m_servos_sd20.setDureeAvantRelache(SERVO_PINCE_G, RELACHE_SERVO_OFF);
		else
			Application.m_servos_sd20.setDureeAvantRelache(SERVO_PINCE_G, ModeleRobot_Y.OUT_RelacheServo[SERVO_PINCE_G-1]);
        Application.m_servos_sd20.CommandePositionVitesse(SERVO_PINCE_G, ModeleRobot_Y.OUT_CommandeServo[SERVO_PINCE_G-1], ModeleRobot_Y.OUT_SpeedServo[SERVO_PINCE_G-1]);
        m_old_cde_servo[SERVO_PINCE_G] = ModeleRobot_Y.OUT_CommandeServo[SERVO_PINCE_G-1];
    } 
	
	if (ModeleRobot_Y.OUT_CommandeServo[SERVO_PINCE_D-1] != m_old_cde_servo[SERVO_PINCE_D]) {
		if (ModeleRobot_Y.OUT_RelacheServo[SERVO_PINCE_D-1]==0)
			Application.m_servos_sd20.setDureeAvantRelache(SERVO_PINCE_D, RELACHE_SERVO_OFF);
		else
			Application.m_servos_sd20.setDureeAvantRelache(SERVO_PINCE_D, ModeleRobot_Y.OUT_RelacheServo[SERVO_PINCE_D-1]); 
        Application.m_servos_sd20.CommandePositionVitesse(SERVO_PINCE_D, ModeleRobot_Y.OUT_CommandeServo[SERVO_PINCE_D-1],ModeleRobot_Y.OUT_SpeedServo[SERVO_PINCE_D-1]);
        m_old_cde_servo[SERVO_PINCE_D] = ModeleRobot_Y.OUT_CommandeServo[SERVO_PINCE_D-1];
    } 

	if (ModeleRobot_Y.OUT_CommandeServo[SERVO_CENTREUR_G-1] != m_old_cde_servo[SERVO_CENTREUR_G]) {
		if (ModeleRobot_Y.OUT_RelacheServo[SERVO_CENTREUR_G-1]==0)
			Application.m_servos_sd20.setDureeAvantRelache(SERVO_CENTREUR_G, RELACHE_SERVO_OFF);
		else
			Application.m_servos_sd20.setDureeAvantRelache(SERVO_CENTREUR_G, ModeleRobot_Y.OUT_RelacheServo[SERVO_CENTREUR_G-1]);
        Application.m_servos_sd20.CommandePositionVitesse(SERVO_CENTREUR_G, ModeleRobot_Y.OUT_CommandeServo[SERVO_CENTREUR_G-1], ModeleRobot_Y.OUT_SpeedServo[SERVO_CENTREUR_G-1]);
        m_old_cde_servo[SERVO_CENTREUR_G] = ModeleRobot_Y.OUT_CommandeServo[SERVO_CENTREUR_G-1];
    } 
	
	if (ModeleRobot_Y.OUT_CommandeServo[SERVO_CENTREUR_D-1] != m_old_cde_servo[SERVO_CENTREUR_D]) {
		if (ModeleRobot_Y.OUT_RelacheServo[SERVO_CENTREUR_D-1]==0)
			Application.m_servos_sd20.setDureeAvantRelache(SERVO_CENTREUR_D, RELACHE_SERVO_OFF);
		else
			Application.m_servos_sd20.setDureeAvantRelache(SERVO_CENTREUR_D, ModeleRobot_Y.OUT_RelacheServo[SERVO_CENTREUR_D-1]);
        Application.m_servos_sd20.CommandePositionVitesse(SERVO_CENTREUR_D, ModeleRobot_Y.OUT_CommandeServo[SERVO_CENTREUR_D-1],ModeleRobot_Y.OUT_SpeedServo[SERVO_CENTREUR_D-1]);
        m_old_cde_servo[SERVO_CENTREUR_D] = ModeleRobot_Y.OUT_CommandeServo[SERVO_CENTREUR_D-1];
    }

	if (ModeleRobot_Y.OUT_CommandeServo[SERVO_BRAS-1] != m_old_cde_servo[SERVO_BRAS]) {
		if (ModeleRobot_Y.OUT_RelacheServo[SERVO_BRAS-1]==0)
			Application.m_servos_sd20.setDureeAvantRelache(SERVO_BRAS, RELACHE_SERVO_OFF);
		else
			Application.m_servos_sd20.setDureeAvantRelache(SERVO_BRAS, ModeleRobot_Y.OUT_RelacheServo[SERVO_BRAS-1]);
        Application.m_servos_sd20.CommandePositionVitesse(SERVO_BRAS, ModeleRobot_Y.OUT_CommandeServo[SERVO_BRAS-1], ModeleRobot_Y.OUT_SpeedServo[SERVO_BRAS-1]);
        m_old_cde_servo[SERVO_BRAS] = ModeleRobot_Y.OUT_CommandeServo[SERVO_BRAS-1];
    }

	if (ModeleRobot_Y.OUT_CommandeServo[SERVO_BALLE-1] != m_old_cde_servo[SERVO_BALLE]) {
		if (ModeleRobot_Y.OUT_RelacheServo[SERVO_BALLE-1]==0)
			Application.m_servos_sd20.setDureeAvantRelache(SERVO_BALLE, RELACHE_SERVO_OFF);
		else
			Application.m_servos_sd20.setDureeAvantRelache(SERVO_BALLE, ModeleRobot_Y.OUT_RelacheServo[SERVO_BALLE-1]);
        Application.m_servos_sd20.CommandePositionVitesse(SERVO_BALLE, ModeleRobot_Y.OUT_CommandeServo[SERVO_BALLE-1], ModeleRobot_Y.OUT_SpeedServo[SERVO_BALLE-1]);
        m_old_cde_servo[SERVO_BALLE] = ModeleRobot_Y.OUT_CommandeServo[SERVO_BALLE-1];
    }

	if (ModeleRobot_Y.OUT_CommandeServo[SERVO_RECOLTEURS-1] != m_old_cde_servo[SERVO_RECOLTEURS]) {
		if (ModeleRobot_Y.OUT_RelacheServo[SERVO_RECOLTEURS-1]==0)
			Application.m_servos_sd20.setDureeAvantRelache(SERVO_RECOLTEURS, RELACHE_SERVO_OFF);
		else
			Application.m_servos_sd20.setDureeAvantRelache(SERVO_RECOLTEURS, ModeleRobot_Y.OUT_RelacheServo[SERVO_RECOLTEURS-1]);
        Application.m_servos_sd20.CommandePositionVitesse(SERVO_RECOLTEURS, ModeleRobot_Y.OUT_CommandeServo[SERVO_RECOLTEURS-1], ModeleRobot_Y.OUT_SpeedServo[SERVO_RECOLTEURS-1]);
        m_old_cde_servo[SERVO_RECOLTEURS] = ModeleRobot_Y.OUT_CommandeServo[SERVO_RECOLTEURS-1];
    }

	if (ModeleRobot_Y.OUT_CommandeServo[SERVO_VOLET-1] != m_old_cde_servo[SERVO_VOLET]) {
		if (ModeleRobot_Y.OUT_RelacheServo[SERVO_VOLET-1]==0)
			Application.m_servos_sd20.setDureeAvantRelache(SERVO_VOLET, RELACHE_SERVO_OFF);
		else
			Application.m_servos_sd20.setDureeAvantRelache(SERVO_VOLET, ModeleRobot_Y.OUT_RelacheServo[SERVO_VOLET-1]);
        Application.m_servos_sd20.CommandePositionVitesse(SERVO_VOLET, ModeleRobot_Y.OUT_CommandeServo[SERVO_VOLET-1], ModeleRobot_Y.OUT_SpeedServo[SERVO_VOLET-1]);
        m_old_cde_servo[SERVO_VOLET] = ModeleRobot_Y.OUT_CommandeServo[SERVO_VOLET-1];
    }

	
	//SORTIES de MODELE
	m_obstacleDetecte=ModeleRobot_Y.OUT_isObstacle;

	// ___________________________ 
	// Divers
	m_duree = ModeleRobot_DWork.DureeMatch * 0.02;    // m_match.m_duree est en nombre de passage dans la boucle de 20msec
	
	
	// ___________________________ 
	// Les LEDs
	_led1 = ModeleRobot_Y.OUT_EtatLed1;
	_led2 = ModeleRobot_Y.OUT_EtatLed2;
	_led3 = ModeleRobot_Y.OUT_EtatLed3;
	_led4 = ModeleRobot_Y.OUT_EtatLed4;


	// Asservissement
	Application.m_asservissement.CalculsMouvementsRobots();
}




//___________________________________________________________________________
 /*!
   \brief Envoie les infos sur la  RS232

   \param --
   \return --
*/
void CMatch::debug(void)
{
   _rs232_pc_tx.putc(0xC);	// Saut de page pour que toutes les infos soient affichées toujours au meme endroit sur la page (avec hyperterminal)
   _rs232_pc_tx.printf("DureeMatch=%f\r\n", m_duree); 
   _rs232_pc_tx.printf("MvtManuel=%f(%f, %f)\n\r", ModeleRobot_Y.OUT_DdeMvtManuel, ModeleRobot_Y.OUT_CommandeManuelleG, ModeleRobot_Y.OUT_CommandeManuelleD);
   _rs232_pc_tx.printf("MvtDistAngle=%f(%f, %f)\n\r", ModeleRobot_Y.OUT_DdeMvtDistanceAngle, ModeleRobot_Y.OUT_ConsigneDistance, ModeleRobot_Y.OUT_ConsigneTeta);
   _rs232_pc_tx.printf("MvtXY=%f(%f, %f)\n\r", ModeleRobot_Y.OUT_DdeMvtXY, ModeleRobot_Y.OUT_ConsigneX, ModeleRobot_Y.OUT_ConsigneY); 
   _rs232_pc_tx.printf("CdeMotG=%f - CdeMotD=%f\n\r", Application.m_asservissement.cde_moteur_G, Application.m_asservissement.cde_moteur_D); 
}




