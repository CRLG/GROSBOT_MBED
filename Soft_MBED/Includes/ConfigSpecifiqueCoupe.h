/*! \file ConfigSpecifiqueCoupe.h
	\brief Déclare
*/
#ifndef _CONFIG_SPECIFIQUE_COUPE 
#define _CONFIG_SPECIFIQUE_COUPE

#include "CMoteurs.h"
#include "CCapteurs.h"
#include "CServoMoteurSD20.h"
#include "PowerSwitch.h"

// Affectation des numéros de stratégie
typedef enum {
   STRATEGIE_PAR_DEFAUT= 0,
   HOMOLO1,
   HOMOLO2,
   STRATEGIE_01,
   STRATEGIE_02,
   STRATEGIE_03,
   STRATEGIE_04,
   STRATEGIE_05,
   STRATEGIE_06
}eATTRIBUTION_STRATEGIES;

// Affectation des numéros de stratégie d'évitement d'obstacle
typedef enum {
    EVITEMENT_NEUTRE= 0,
    EVITEMENT_NORMAL
}eATTRIBUTION_STRATEGIES_EVITEMENT;

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

//! Durée du match
#define DUREE_MATCH 100 // [sec]

#define HOMOLO 1

#endif // _CONFIG_SPECIFIQUE_COUPE


