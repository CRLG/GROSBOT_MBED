/*! \file ConfigSpecifiqueCoupe.h
	\brief Déclare
*/
#ifndef _CONFIG_SPECIFIQUE_COUPE 
#define _CONFIG_SPECIFIQUE_COUPE

#include "CMoteurs.h"
#include "CServoMoteur.h"

// Affectation des sorties moteurs
typedef enum {
   MOTEUR_ROUE_GAUCHE = MOTEUR_1,
   MOTEUR_ROUE_DROITE,  // MOTEUR_2
   MOTEUR_ASCENSEUR, 	// MOTEUR_3
   MOTEUR_BARILLET, 	// MOTEUR_4
   MOTEUR_MOELDAR, 	    // MOTEUR_5
   MOTEUR_SOUFFLEUR,    // MOTEUR_6
   MOTEUR_ELECTROVANNE  // MOTEUR_7-> Moteur piloté en ON/OFF (sans PWM)
}eATTRIBUTION_MOTEURS;

// Affectation des codeurs de position
typedef enum {
   CODEUR_BARILLET  =   CODEUR_1,
   CODEUR_ASCENSEUR,    // CODEUR_2
   CODEUR_ROUE_DROITE,  // CODEUR_3
   CODEUR_ROUE_GAUCHE   // CODEUR_4

}eATTRIBUTION_CODEURS;

//! cet enumere contient les numeros d'attribution des servos pour 2014
typedef enum {
	SERVO_ANCRAGE_FILET=13,
	SERVO_CROCHET_AR,
	SERVO_RETOURNE_FEU,
	SERVO_NERF,
	SERVO_KMAR
} eATTRIBUTION_SERVOS;


#endif // _CONFIG_SPECIFIQUE_COUPE

