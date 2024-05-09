/*! \file ConfigSpecifiqueCoupe.h
	\brief Déclare
*/
#ifndef _CONFIG_SPECIFIQUE_COUPE 
#define _CONFIG_SPECIFIQUE_COUPE

#include "CMoteurs.h"
#include "CElectrobot.h"
#include "CServoMoteurSD20.h"
#include "PowerSwitch.h"
#include "kmar.h"

// Directives pour la compilation conditionnelle
// Permet d'activer ou desactiver une fonctionnalite d'une annee sur l'autre ou d'un robot a l'autre
//#define UTILSATION_SERVOS_AX
//#define UTILISATION_KMAR
//#define UTILISATION_CHARIOT
//#define UTILISATION_XBEE

// Couleur de l'équipe
#define EQUIPE_BLEU     SM_DatasInterface::EQUIPE_COULEUR_2
#define EQUIPE_JAUNE    SM_DatasInterface::EQUIPE_COULEUR_1

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
    SERVO_GROSSE_TAPETTE    = 13,
    SERVO_INCLINE_PLANTE    = 18,
    SERVO_PINCE_PLANTE      = 19
} eATTRIBUTION_SERVOS_SD20;

typedef enum {
    // Positions references du servo TAPETTE
    POSITION_GROSSE_TAPETTE_LEVE    = 140,
    POSITION_GROSSE_TAPETTE_BAISSE  = 220,
    POSITION_GROSSE_TAPETTE_RANGE   = 230,

    // Positions de references du servo PINCE_PLANTE
    POSITION_PINCE_PLANTE_OUVERT    = 200,
    POSITION_PINCE_PLANTE_FERME     = 80,

    // Positions de references du servo INCLINE_PLANTE
    POSITION_INCLINE_PLANTE_LEVE = 180,
    POSITION_INCLINE_PLANTE_BAISSE = 20
}eVALUES_SERVOS_SD20;

//! cet enumere contient les numeros d'attribution des servos AX (ID)
typedef enum {
    SERVO_AX_KMAR_AXIS_1 = 1,
    SERVO_AX_KMAR_AXIS_2 = 2,
    SERVO_AX_KMAR_AXIS_3 = 3,
    SERVO_AX_KMAR_AXIS_4 = 4,
    SERVO_AX_TOUS = 0xFE
} eATTRIBUTION_SERVOS_AX;

//! cet enumere contient les numeros d'attribution des servos AX
typedef enum {
} eVALUES_SERVOS_AX;

// affectation des sorties de la carte PowerSwitch
// EV = Electrovanne
// AV = Avant / AR = Arrière
// Pompe = Pompe à air
typedef enum {
    ELECTROVANNE            = PowerSwitch::XT7_OUTPUT,
    POMPE                   = PowerSwitch::XT8_OUTPUT,
    DECO_LED_CRLG           = PowerSwitch::XT6_OUTPUT,
}eATTRIBUTION_POWER_SWITCH;

//code des demandes MBED vers LABOTBOX (trame générique)
typedef enum {
    DMDE_DEFAULT = 0,
    DMDE_DISTANCE_BALISE = 1,
    DMDE_VIDEO_NORD_SUD = 2,
    DMDE_VIDEO_CODE_COULEUR = 3
}eVALUES_DMDE_GEN;

//code des commandes/traitements LABOTBOX vers MBED (trame générique)
typedef enum {
    CMDE_DEFAULT = 0,
    CMDE_DISTANCE_BALISE = 1, // c'est un traitement: reco des balises aruco et distance par rapport au robot
    CMDE_VIDEO_NORD_SUD = 2, // SPECIFIQUE 2020/2021 - c'est un traitement: reco du nord-sud
    CMDE_VIDEO_CODE_COULEUR = 3 // SPECIFIQUE 2020/2021 - c'est un traitement : reco d'une série de couleur (pour les gobelets)
}eVALUES_CMDE_GEN;

typedef enum {
    MOUVEMENT_INIT = (CKmar::NO_MOUVEMENT + 1),
    MOUVEMENT_APPRENTISSAGE_CHARIOT,
    MOUVEMENT_PRISE_STATUETTE,
    MOUVEMENT_POSER_STATUETTE_SUR_VITRINE,
    MOUVEMENT_PRENDRE_ECHANTILLON_AU_SOL,
    MOUVEMENT_DEPOSER_ECHANTILLON_SUR_GALERIE,
    MOUVEMENT_RANGER_STATUETTE_DANS_ROBOT,
    MOUVEMENT_LEVER_STATUETTE_AVANT_DEPLACEMENT
}eKMAR_MOUVEMENTS;

// Affectation des numéros de télémètres SRF08 et ANA
#define INDEX_TELEMETRE_AVG 2
#define INDEX_TELEMETRE_AVD 0
#define INDEX_TELEMETRE_ARG 3
#define INDEX_TELEMETRE_ARD 1
#define INDEX_TELEMETRE_ARGCentre 4
#define INDEX_TELEMETRE_ARDCentre 5

//Seuil de détection des capteurs US et du Lidar
#define SEUIL_DETECTION_US  20
#define SEUIL_DETECTION_LIDAR 50


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
#define X_ROBOT_TERRAIN_INIT_COULEUR_1        (12)
#define Y_ROBOT_TERRAIN_INIT_COULEUR_1        (177)
#define ANGLE_ROBOT_TERRAIN_INIT_COULEUR_1    (0.0f)

#define X_ROBOT_TERRAIN_INIT_COULEUR_2        (12)
#define Y_ROBOT_TERRAIN_INIT_COULEUR_2        (23)
#define ANGLE_ROBOT_TERRAIN_INIT_COULEUR_2    (0.0f)

// Coordonnées dans le repère absolue terrain
// à partir desquelles il faut interdire la détection d'obstacle
// pour éviter les fausses détections hors du terrain
// Valeurs en [cm]
#define X_MAX_INTERDIT_DETECTION    (280)
#define X_MIN_INTERDIT_DETECTION    (20)
#define Y_MIN_INTERDIT_DETECTION    (10)
#define Y_MAX_INTERDIT_DETECTION    (190)

#define HOMOLO 1

#endif // _CONFIG_SPECIFIQUE_COUPE


