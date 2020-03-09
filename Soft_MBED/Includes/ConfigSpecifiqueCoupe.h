/*! \file ConfigSpecifiqueCoupe.h
	\brief Déclare
*/
#ifndef _CONFIG_SPECIFIQUE_COUPE 
#define _CONFIG_SPECIFIQUE_COUPE

#include "CMoteurs.h"
#include "CElectrobot.h"
#include "CServoMoteurSD20.h"
#include "PowerSwitch.h"

// Couleur de l'équipe
#define EQUIPE_BLEU     SM_DatasInterface::EQUIPE_COULEUR_1
#define EQUIPE_JAUNE    SM_DatasInterface::EQUIPE_COULEUR_2

// Affectation des numéros de stratégie
typedef enum {
    STRATEGIE_PAR_DEFAUT= 0,
    STRATEGIE_HOMOLO1,
    STRATEGIE_HOMOLO2,
    STRATEGIE_01,
    STRATEGIE_02,
    STRATEGIE_03,
    STRATEGIE_04,
    STRATEGIE_05,
    STRATEGIE_06,
    // _____________________
    STRATEGIE_TEST_01 = 30,
    STRATEGIE_TEST_02,
    STRATEGIE_TEST_03,
    STRATEGIE_TEST_04,
    STRATEGIE_TEST_05,
    STRATEGIE_TEST_06,
    STRATEGIE_TEST_07
}eATTRIBUTION_STRATEGIES;

// Affectation des sorties moteurs
typedef enum {
   MOTEUR_ROUE_GAUCHE = MOTEUR_1,
   MOTEUR_ROUE_DROITE,  // MOTEUR_2
   MOTEUR_NON_DEFINI_1, 	// MOTEUR_3
   MOTEUR_NON_DEFINI_2, 	// MOTEUR_4
   MOTEUR_NON_DEFINI_3, 	    // MOTEUR_5
   MOTEUR_CHARIOT,    // MOTEUR_6
   MOTEUR_NON_DEFINI_4  // MOTEUR_7-> Moteur piloté en ON/OFF (sans PWM)
}eATTRIBUTION_MOTEURS;

// Affectation des codeurs de position
// ATTENTION : obsolète
typedef enum {
   CODEUR_NON_DEFINI  =   CODEUR_1,
   CODEUR_CHARIOT,    // CODEUR_2
   CODEUR_ROUE_DROITE,  // CODEUR_3
   CODEUR_ROUE_GAUCHE   // CODEUR_4

}eATTRIBUTION_CODEURS;

//! cet enumere contient les numeros d'attribution des servos SD20
typedef enum {
    SERVO_PARE_CHOC=13,
    SERVO_BRAS_ARD=14,
    SERVO_PLATEAU_G=15,
    SERVO_BARRIERE_AVG=16,
    SERVO_BRAS_ARG = 18,
    SERVO_PLATEAU_D=19,
    SERVO_BARRIERE_AVD=20,
} eATTRIBUTION_SERVOS_SD20;

//! cet enumere contient les numeros d'attribution des servos AX
// VERT = Vertical / HORIZ = Horizontal
typedef enum {
    SERVO_VENTOUSE_ARD_VERT=0,
    SERVO_VENTOUSE_ARG_VERT,
    SERVO_VENTOUSE_AV_HORIZ,
    SERVO_VENTOUSE_AV_VERT,
    SERVO_CHUCK_NORRIS,
    SERVO_AX_TOUS = 0xFE
} eATTRIBUTION_SERVOS_AX;

// affectation des sorties de la carte PowerSwitch
// EV = Electrovanne
// AV = Avant / AR = Arrière
// Pompe = Pompe à air
typedef enum {
    POMPE_AV = PowerSwitch::XT1_OUTPUT,
    EV_AV = PowerSwitch::XT4_OUTPUT,
    POMPE_ARG = PowerSwitch::XT5_OUTPUT,
    POMPE_ARD = PowerSwitch::XT6_OUTPUT,
    EV_ARG = PowerSwitch::XT7_OUTPUT,
    EV_ARD = PowerSwitch::XT8_OUTPUT
}eATTRIBUTION_POWER_SWITCH;


// Affectation des numéros de télémètres SRF08
#define INDEX_TELEMETRE_AVG 2
#define INDEX_TELEMETRE_AVD 0
#define INDEX_TELEMETRE_ARG 3
#define INDEX_TELEMETRE_ARD 1


//! Période d'appel du modèle
#define PERIODE_APPEL_MODELIA 0.02f // [sec]

//! Durée du match
#define DUREE_MATCH 100 // [sec]

// Consignes "tout doux" pour l'asserviseement
// utilisé dans la stratégie d'évitement et propre au robot
// TODO : peut être qu'il serait mieux de faire une méthode
// dans la classe Asservissement getCdeMinToutDoux() et getCdeMaxToutDoux()
// à ré-implémenter pour chaque robot en fonction de moteurs
#define CDE_MIN_TOUT_DOUX (-10)
#define CDE_MAX_TOUT_DOUX (10)

// Position d'init du robot dans le repère absolue terrain
#define X_ROBOT_TERRAIN_INIT_COULEUR_1        (18)
#define Y_ROBOT_TERRAIN_INIT_COULEUR_1        (129)
#define ANGLE_ROBOT_TERRAIN_INIT_COULEUR_1    (0)

#define X_ROBOT_TERRAIN_INIT_COULEUR_2        (282)
#define Y_ROBOT_TERRAIN_INIT_COULEUR_2        (129)
#define ANGLE_ROBOT_TERRAIN_INIT_COULEUR_2    (3.14f)

// Coordonnées dans le repère absolue terrain
// à partir desquelles il faut interdire la détection d'obstacle
// pour éviter les fausses détections hors du terrain
// Valeurs en [cm]
#define X_MAX_INTERDIT_DETECTION    (265)
#define X_MIN_INTERDIT_DETECTION    (35)
#define Y_MIN_INTERDIT_DETECTION    (35)
#define Y_MAX_INTERDIT_DETECTION    (165)

#define HOMOLO 1

#endif // _CONFIG_SPECIFIQUE_COUPE


