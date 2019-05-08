
#ifndef IA_H_
#define IA_H_

#include "../src/sc_types.h"
#include "../src/StatemachineInterface.h"
#include "../src/TimedStatemachineInterface.h"
#include "../../Includes/ConfigSpecifiqueCoupe.h"
#include "../../ext/mbed-common-rob/Includes/CAsservissement.h"
#include "../../ext/mbed-common-rob/Includes/CGlobale.h"
#include "../../ext/CppRobLib/Communication/Messenger/MessagesGeneric/message_timestamp_match.h"
#include "../../ext/mbed-common-rob/Includes/CLeds.h"
#include "../../ext/CppRobLib/Communication/Messenger/DatabaseXbeeNetwork2019/databasexbeenetwork2019.h"
#include "../../ext/CppRobLib/ServosAX/servoaxbase.h"
#include "../../ext/mbed-common-rob/Includes/PowerSwitch.h"
#include "../../ext/mbed-common-rob/Includes/CAsservissementChariot.h"
#include "../../ext/mbed-common-rob/Includes/MessengerXbeeNetwork.h"
#include "../../ext/mbed-common-rob/Includes/CServoMoteurSD20.h"

/*! \file Header of the state machine 'IA'.
*/


/*! Define indices of states in the StateConfVector */
#define SCVI_MAIN_REGION_ATTENTE_TIRETTE 0
#define SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE 0
#define SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE_INIT_INIT 0
#define SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE_INIT_TOBOGGANS_HAUTS 0
#define SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE_INIT_APPRENTISSAGE_ASCENSEUR 0
#define SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE_INIT_TOBOGGANS_BAS 0
#define SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_01 0
#define SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_02 0
#define SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_01 0
#define SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_02 0
#define SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE_INIT_TOBOGGANS_HAUT 0
#define SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE_INIT_COPY_1_TOBOGGANS_BAS 0
#define SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_VIOLET 1
#define SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_JAUNE 1
#define SCVI_MAIN_REGION_ATTENTE_TIRETTE__REGION0_ATTENTE_TIRETTE_CHOIX_STRATEGIE_CHOIX_NUM_STRATEGIE 2
#define SCVI_MAIN_REGION_MATCH_EN_COURS 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_DETECTION_OBSTACLE 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_DETECTION_OBSTACLE_R1_ARRET_ROBOT 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_DETECTION_OBSTACLE_R1_SORTIE_EVITEMENT 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_DETECTION_OBSTACLE_R1__FINAL_ 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_NETTOYAGE 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_NETTOYAGE_R1_DEPASSE_ZONE_CHAOS 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_NETTOYAGE_R1_FACE_ZONE_CHAOS 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_NETTOYAGE_R1_STOCKAGE_DANS_ZONE_DEPART 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_NETTOYAGE_R1_PLACEMENT_DEVANT_DISTRIBUTEUR 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_NETTOYAGE_R1_VENTOUSAGE_ATOMES 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_NETTOYAGE_R1_RECUPERATION_ATOMES 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_NETTOYAGE_R1_DEVENTOUSAGE_ATOMES 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_NETTOYAGE_R1_GLISSADE 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_NETTOYAGE_R1_ON_RANGE 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_NETTOYAGE_R1_FIN_SEQUENCE 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_NETTOYAGE_R1__FINAL_ 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_SUPERVISOR 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_FACE_BLEUIUM 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_PREPA_POUSSETTE_GAUCHE 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_DEPLACEMENT_VERS_GOLDENIUM 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_PREPARATION_KMAR_POUR_GOLDENIUM 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_VENTOUSAGE_GOLDENIUM 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_PREPARATION_KMAR_GAUCHE 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_PREPARATION_KMAR_DROITE 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_PREPARATION_KMAR_GAUCHE_VENTOUSE_DROITE 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_PREPA_POUSSETTE_DROITE 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_GOLDENIUM_DANS_ROBOT_GAUCHE 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_PLACEMENT_DEVANT_BALANCE 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_PLUS_PROCHE_BALANCE 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_GOLDENIUM_EN_L_AIR 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_DROPAGE_GOLDENIUM 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_FIN 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1__FINAL_ 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_COPY_1_DROPAGE_GOLDENIUM 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_RECULE_AVEC_PRECAUTION 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_ARRET_MOTEURS 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_MISE_GOLDENIUM_BAS 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_RALENTISSEMENT_KMAR_01 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_RALENTISSEMENT_KMAR_02 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_POSE_GOLDENIUM 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_DECOLLAGE_GOLDENIUM_01 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_DECOLLAGE_GOLDENIUM_02 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_KMAR_SECURE 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_DECOLLAGE_GOLDENIUM_03 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_COPY_1_GOLDENIUM_DANS_ROBOT_GAUCHE 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_DESCEND_KMAR 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_KMAR_MONTE 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_KMAR_BIEN_DROIT 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_ROTATION_VERS_GOLDENIUM 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_PLACEMENT_FACE_GOLDENIUM 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_COPY_1_ACCOSTAGE_BALANCE 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_DECLENCHEMENT_ACCELERATEUR 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_COPY_1_FACE_BLEUIUM 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_COPY_1_DECLENCHEMENT_ACCELERATEUR 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_COPY_1_ROTATION_VERS_GOLDENIUM 0
#define SCVI_MAIN_REGION_MATCH_EN_COURS__REGION0_GOLDENIUM_R1_COPY_1_PREPA_POUSSETTE_GAUCHE 0
#define SCVI_MAIN_REGION_FIN_MATCH 0

class IA : public TimedStatemachineInterface, public StatemachineInterface
{
	public:
		IA();
		
		~IA();
		
		/*! Enumeration of all states */ 
		typedef enum
		{
			IA_last_state,
			main_region_ATTENTE_TIRETTE,
			main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE,
			main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_INIT,
			main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_HAUTS,
			main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_APPRENTISSAGE_ASCENSEUR,
			main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_BAS,
			main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_01,
			main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_02,
			main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_01,
			main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_02,
			main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_HAUT,
			main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_Copy_1_TOBOGGANS_BAS,
			main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_VIOLET,
			main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_JAUNE,
			main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_STRATEGIE_CHOIX_NUM_STRATEGIE,
			main_region_MATCH_EN_COURS,
			main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE,
			main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT,
			main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_SORTIE_EVITEMENT,
			main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_,
			main_region_MATCH_EN_COURS__region0_NETTOYAGE,
			main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS,
			main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS,
			main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART,
			main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR,
			main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES,
			main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES,
			main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES,
			main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_GLISSADE,
			main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_ON_RANGE,
			main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FIN_SEQUENCE,
			main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1__final_,
			main_region_MATCH_EN_COURS__region0_SUPERVISOR,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_FACE_BLEUIUM,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_PREPA_POUSSETTE_GAUCHE,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_DEPLACEMENT_VERS_GOLDENIUM,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_PREPARATION_KMAR_POUR_GOLDENIUM,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_VENTOUSAGE_GOLDENIUM,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_PREPARATION_KMAR_GAUCHE,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_PREPARATION_KMAR_DROITE,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_PREPARATION_KMAR_GAUCHE_VENTOUSE_DROITE,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_PREPA_POUSSETTE_DROITE,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_GOLDENIUM_DANS_ROBOT_GAUCHE,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_PLACEMENT_DEVANT_BALANCE,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_PLUS_PROCHE_BALANCE,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_GOLDENIUM_EN_L_AIR,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_DROPAGE_GOLDENIUM,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_FIN,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1__final_,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_Copy_1_DROPAGE_GOLDENIUM,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_RECULE_AVEC_PRECAUTION,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_ARRET_MOTEURS,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_MISE_GOLDENIUM_BAS,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_RALENTISSEMENT_KMAR_01,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_RALENTISSEMENT_KMAR_02,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_POSE_GOLDENIUM,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_DECOLLAGE_GOLDENIUM_01,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_DECOLLAGE_GOLDENIUM_02,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_KMAR_SECURE,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_DECOLLAGE_GOLDENIUM_03,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_Copy_1_GOLDENIUM_DANS_ROBOT_GAUCHE,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_DESCEND_KMAR,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_KMAR_MONTE,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_KMAR_BIEN_DROIT,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_ROTATION_VERS_GOLDENIUM,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_PLACEMENT_FACE_GOLDENIUM,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_Copy_1_ACCOSTAGE_BALANCE,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_DECLENCHEMENT_ACCELERATEUR,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_Copy_1_FACE_BLEUIUM,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_Copy_1_DECLENCHEMENT_ACCELERATEUR,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_Copy_1_ROTATION_VERS_GOLDENIUM,
			main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_Copy_1_PREPA_POUSSETTE_GAUCHE,
			main_region_FIN_MATCH
		} IAStates;
		
		//! Inner class for default interface scope.
		class DefaultSCI
		{
			
			public:
				/*! Raises the in event 'EV_Tirette' that is defined in the default interface scope. */
				void raise_eV_Tirette();
				
				/*! Raises the in event 'EV_Obstacle' that is defined in the default interface scope. */
				void raise_eV_Obstacle();
				
				/*! Raises the in event 'EV_ConvergenceMvt' that is defined in the default interface scope. */
				void raise_eV_ConvergenceMvt();
				
				/*! Raises the in event 'EV_ConvergenceMvt_Rapide' that is defined in the default interface scope. */
				void raise_eV_ConvergenceMvt_Rapide();
				
				/*! Raises the in event 'EV_ConvergenceChariot' that is defined in the default interface scope. */
				void raise_eV_ConvergenceChariot();
				
				/*! Gets the value of the variable 'IN_x_pos' that is defined in the default interface scope. */
				double get_iN_x_pos() const;
				
				/*! Sets the value of the variable 'IN_x_pos' that is defined in the default interface scope. */
				void set_iN_x_pos(double value);
				
				/*! Gets the value of the variable 'IN_y_pos' that is defined in the default interface scope. */
				double get_iN_y_pos() const;
				
				/*! Sets the value of the variable 'IN_y_pos' that is defined in the default interface scope. */
				void set_iN_y_pos(double value);
				
				/*! Gets the value of the variable 'IN_teta_pos' that is defined in the default interface scope. */
				double get_iN_teta_pos() const;
				
				/*! Sets the value of the variable 'IN_teta_pos' that is defined in the default interface scope. */
				void set_iN_teta_pos(double value);
				
				/*! Gets the value of the variable 'IN_vitesse' that is defined in the default interface scope. */
				double get_iN_vitesse() const;
				
				/*! Sets the value of the variable 'IN_vitesse' that is defined in the default interface scope. */
				void set_iN_vitesse(double value);
				
				/*! Gets the value of the variable 'IN_sens_deplacement' that is defined in the default interface scope. */
				double get_iN_sens_deplacement() const;
				
				/*! Sets the value of the variable 'IN_sens_deplacement' that is defined in the default interface scope. */
				void set_iN_sens_deplacement(double value);
				
				/*! Gets the value of the variable 'IN_Couleur' that is defined in the default interface scope. */
				int32_t get_iN_Couleur() const;
				
				/*! Sets the value of the variable 'IN_Couleur' that is defined in the default interface scope. */
				void set_iN_Couleur(int32_t value);
				
				/*! Gets the value of the variable 'IN_choixStrategie' that is defined in the default interface scope. */
				int32_t get_iN_choixStrategie() const;
				
				/*! Sets the value of the variable 'IN_choixStrategie' that is defined in the default interface scope. */
				void set_iN_choixStrategie(int32_t value);
				
				/*! Gets the value of the variable 'IN_Obstacle' that is defined in the default interface scope. */
				int32_t get_iN_Obstacle() const;
				
				/*! Sets the value of the variable 'IN_Obstacle' that is defined in the default interface scope. */
				void set_iN_Obstacle(int32_t value);
				
				/*! Gets the value of the variable 'IN_Depression' that is defined in the default interface scope. */
				sc_boolean get_iN_Depression() const;
				
				/*! Sets the value of the variable 'IN_Depression' that is defined in the default interface scope. */
				void set_iN_Depression(sc_boolean value);
				
				/*! Gets the value of the variable 'forceObstacle' that is defined in the default interface scope. */
				sc_boolean get_forceObstacle() const;
				
				/*! Sets the value of the variable 'forceObstacle' that is defined in the default interface scope. */
				void set_forceObstacle(sc_boolean value);
				
				/*! Gets the value of the variable 'US_AV' that is defined in the default interface scope. */
				sc_boolean get_uS_AV() const;
				
				/*! Sets the value of the variable 'US_AV' that is defined in the default interface scope. */
				void set_uS_AV(sc_boolean value);
				
				/*! Gets the value of the variable 'US_AR' that is defined in the default interface scope. */
				sc_boolean get_uS_AR() const;
				
				/*! Sets the value of the variable 'US_AR' that is defined in the default interface scope. */
				void set_uS_AR(sc_boolean value);
				
				/*! Gets the value of the variable 'Couleur' that is defined in the default interface scope. */
				int32_t get_couleur() const;
				
				/*! Sets the value of the variable 'Couleur' that is defined in the default interface scope. */
				void set_couleur(int32_t value);
				
				/*! Gets the value of the variable 'choixStrategie' that is defined in the default interface scope. */
				int32_t get_choixStrategie() const;
				
				/*! Sets the value of the variable 'choixStrategie' that is defined in the default interface scope. */
				void set_choixStrategie(int32_t value);
				
				/*! Gets the value of the variable 'countTimeMvt' that is defined in the default interface scope. */
				double get_countTimeMvt() const;
				
				/*! Sets the value of the variable 'countTimeMvt' that is defined in the default interface scope. */
				void set_countTimeMvt(double value);
				
				/*! Gets the value of the variable 'tempsMatch' that is defined in the default interface scope. */
				double get_tempsMatch() const;
				
				/*! Sets the value of the variable 'tempsMatch' that is defined in the default interface scope. */
				void set_tempsMatch(double value);
				
				/*! Gets the value of the variable 'countTempo' that is defined in the default interface scope. */
				int32_t get_countTempo() const;
				
				/*! Sets the value of the variable 'countTempo' that is defined in the default interface scope. */
				void set_countTempo(int32_t value);
				
				/*! Gets the value of the variable 'countTempo2' that is defined in the default interface scope. */
				int32_t get_countTempo2() const;
				
				/*! Sets the value of the variable 'countTempo2' that is defined in the default interface scope. */
				void set_countTempo2(int32_t value);
				
				/*! Gets the value of the variable 'countTime' that is defined in the default interface scope. */
				double get_countTime() const;
				
				/*! Sets the value of the variable 'countTime' that is defined in the default interface scope. */
				void set_countTime(double value);
				
				/*! Gets the value of the variable 'x_pos_mem' that is defined in the default interface scope. */
				double get_x_pos_mem() const;
				
				/*! Sets the value of the variable 'x_pos_mem' that is defined in the default interface scope. */
				void set_x_pos_mem(double value);
				
				/*! Gets the value of the variable 'y_pos_mem' that is defined in the default interface scope. */
				double get_y_pos_mem() const;
				
				/*! Sets the value of the variable 'y_pos_mem' that is defined in the default interface scope. */
				void set_y_pos_mem(double value);
				
				/*! Gets the value of the variable 'teta_pos_mem' that is defined in the default interface scope. */
				double get_teta_pos_mem() const;
				
				/*! Sets the value of the variable 'teta_pos_mem' that is defined in the default interface scope. */
				void set_teta_pos_mem(double value);
				
				/*! Gets the value of the variable 'nb_Modules' that is defined in the default interface scope. */
				int32_t get_nb_Modules() const;
				
				/*! Sets the value of the variable 'nb_Modules' that is defined in the default interface scope. */
				void set_nb_Modules(int32_t value);
				
				/*! Gets the value of the variable 'score_grosbot' that is defined in the default interface scope. */
				int32_t get_score_grosbot() const;
				
				/*! Sets the value of the variable 'score_grosbot' that is defined in the default interface scope. */
				void set_score_grosbot(int32_t value);
				
				/*! Gets the value of the variable 'score_minibot' that is defined in the default interface scope. */
				int32_t get_score_minibot() const;
				
				/*! Sets the value of the variable 'score_minibot' that is defined in the default interface scope. */
				void set_score_minibot(int32_t value);
				
				/*! Gets the value of the variable 'score_experience' that is defined in the default interface scope. */
				int32_t get_score_experience() const;
				
				/*! Sets the value of the variable 'score_experience' that is defined in the default interface scope. */
				void set_score_experience(int32_t value);
				
				/*! Gets the value of the variable 'score_total' that is defined in the default interface scope. */
				int32_t get_score_total() const;
				
				/*! Sets the value of the variable 'score_total' that is defined in the default interface scope. */
				void set_score_total(int32_t value);
				
				/*! Gets the value of the variable 'TOB_G_HAUT' that is defined in the default interface scope. */
				const int32_t get_tOB_G_HAUT() const;
				
				/*! Gets the value of the variable 'TOB_G_MILIEU' that is defined in the default interface scope. */
				const int32_t get_tOB_G_MILIEU() const;
				
				/*! Gets the value of the variable 'TOB_G_BAS' that is defined in the default interface scope. */
				const int32_t get_tOB_G_BAS() const;
				
				/*! Gets the value of the variable 'TOB_D_HAUT' that is defined in the default interface scope. */
				const int32_t get_tOB_D_HAUT() const;
				
				/*! Gets the value of the variable 'TOB_D_MILIEU' that is defined in the default interface scope. */
				const int32_t get_tOB_D_MILIEU() const;
				
				/*! Gets the value of the variable 'TOB_D_BAS' that is defined in the default interface scope. */
				const int32_t get_tOB_D_BAS() const;
				
				/*! Gets the value of the variable 'TOUSE_G_HAUT' that is defined in the default interface scope. */
				const int32_t get_tOUSE_G_HAUT() const;
				
				/*! Gets the value of the variable 'TOUSE_G_MILIEU' that is defined in the default interface scope. */
				const int32_t get_tOUSE_G_MILIEU() const;
				
				/*! Gets the value of the variable 'TOUSE_G_BAS' that is defined in the default interface scope. */
				const int32_t get_tOUSE_G_BAS() const;
				
				/*! Gets the value of the variable 'TOUSE_D_HAUT' that is defined in the default interface scope. */
				const int32_t get_tOUSE_D_HAUT() const;
				
				/*! Gets the value of the variable 'TOUSE_D_MILIEU' that is defined in the default interface scope. */
				const int32_t get_tOUSE_D_MILIEU() const;
				
				/*! Gets the value of the variable 'TOUSE_D_BAS' that is defined in the default interface scope. */
				const int32_t get_tOUSE_D_BAS() const;
				
				/*! Gets the value of the variable 'KMAR_G_HAUT' that is defined in the default interface scope. */
				const int32_t get_kMAR_G_HAUT() const;
				
				/*! Gets the value of the variable 'KMAR_G_MILIEU' that is defined in the default interface scope. */
				const int32_t get_kMAR_G_MILIEU() const;
				
				/*! Gets the value of the variable 'KMAR_G_BAS' that is defined in the default interface scope. */
				const int32_t get_kMAR_G_BAS() const;
				
				/*! Gets the value of the variable 'KMAR_D_HAUT' that is defined in the default interface scope. */
				const int32_t get_kMAR_D_HAUT() const;
				
				/*! Gets the value of the variable 'KMAR_D_MILIEU' that is defined in the default interface scope. */
				const int32_t get_kMAR_D_MILIEU() const;
				
				/*! Gets the value of the variable 'KMAR_D_BAS' that is defined in the default interface scope. */
				const int32_t get_kMAR_D_BAS() const;
				
				/*! Gets the value of the variable 'KMAR_DROITE' that is defined in the default interface scope. */
				const int32_t get_kMAR_DROITE() const;
				
				/*! Gets the value of the variable 'KMAR_MILIEU' that is defined in the default interface scope. */
				const int32_t get_kMAR_MILIEU() const;
				
				/*! Gets the value of the variable 'KMAR_GAUCHE' that is defined in the default interface scope. */
				const int32_t get_kMAR_GAUCHE() const;
				
				/*! Gets the value of the variable 'KMAR_ERECTION' that is defined in the default interface scope. */
				const int32_t get_kMAR_ERECTION() const;
				
				/*! Gets the value of the variable 'KMAR_MI_MOLLE' that is defined in the default interface scope. */
				const int32_t get_kMAR_MI_MOLLE() const;
				
				/*! Gets the value of the variable 'KMAR_MOLLE' that is defined in the default interface scope. */
				const int32_t get_kMAR_MOLLE() const;
				
				/*! Gets the value of the variable 'PARE_CHOC_BAS' that is defined in the default interface scope. */
				const int32_t get_pARE_CHOC_BAS() const;
				
				/*! Gets the value of the variable 'PARE_CHOC_HAUT' that is defined in the default interface scope. */
				const int32_t get_pARE_CHOC_HAUT() const;
				
				/*! Gets the value of the variable 'CHUCK_FERME' that is defined in the default interface scope. */
				const int32_t get_cHUCK_FERME() const;
				
				/*! Gets the value of the variable 'CHUCK_OUVERT' that is defined in the default interface scope. */
				const int32_t get_cHUCK_OUVERT() const;
				
				/*! Gets the value of the variable 'CODEUR_NON_DEFINI' that is defined in the default interface scope. */
				const int32_t get_cODEUR_NON_DEFINI() const;
				
				/*! Gets the value of the variable 'CODEUR_CHARIOT' that is defined in the default interface scope. */
				const int32_t get_cODEUR_CHARIOT() const;
				
				/*! Gets the value of the variable 'CODEUR_ROUE_DROITE' that is defined in the default interface scope. */
				const int32_t get_cODEUR_ROUE_DROITE() const;
				
				/*! Gets the value of the variable 'CODEUR_ROUE_GAUCHE' that is defined in the default interface scope. */
				const int32_t get_cODEUR_ROUE_GAUCHE() const;
				
				/*! Gets the value of the variable 'VIOLET' that is defined in the default interface scope. */
				const int32_t get_vIOLET() const;
				
				/*! Gets the value of the variable 'JAUNE' that is defined in the default interface scope. */
				const int32_t get_jAUNE() const;
				
				/*! Gets the value of the variable 'PI' that is defined in the default interface scope. */
				const float get_pI() const;
				
				
			protected:
				friend class IA;
				sc_boolean EV_Tirette_raised;
				sc_boolean EV_Obstacle_raised;
				sc_boolean EV_ConvergenceMvt_raised;
				sc_boolean EV_ConvergenceMvt_Rapide_raised;
				sc_boolean EV_ConvergenceChariot_raised;
				double IN_x_pos;
				double IN_y_pos;
				double IN_teta_pos;
				double IN_vitesse;
				double IN_sens_deplacement;
				int32_t IN_Couleur;
				int32_t IN_choixStrategie;
				int32_t IN_Obstacle;
				sc_boolean IN_Depression;
				sc_boolean forceObstacle;
				sc_boolean US_AV;
				sc_boolean US_AR;
				int32_t Couleur;
				int32_t choixStrategie;
				double countTimeMvt;
				double tempsMatch;
				int32_t countTempo;
				int32_t countTempo2;
				double countTime;
				double x_pos_mem;
				double y_pos_mem;
				double teta_pos_mem;
				int32_t nb_Modules;
				int32_t score_grosbot;
				int32_t score_minibot;
				int32_t score_experience;
				int32_t score_total;
				static const int32_t TOB_G_HAUT;
				static const int32_t TOB_G_MILIEU;
				static const int32_t TOB_G_BAS;
				static const int32_t TOB_D_HAUT;
				static const int32_t TOB_D_MILIEU;
				static const int32_t TOB_D_BAS;
				static const int32_t TOUSE_G_HAUT;
				static const int32_t TOUSE_G_MILIEU;
				static const int32_t TOUSE_G_BAS;
				static const int32_t TOUSE_D_HAUT;
				static const int32_t TOUSE_D_MILIEU;
				static const int32_t TOUSE_D_BAS;
				static const int32_t KMAR_G_HAUT;
				static const int32_t KMAR_G_MILIEU;
				static const int32_t KMAR_G_BAS;
				static const int32_t KMAR_D_HAUT;
				static const int32_t KMAR_D_MILIEU;
				static const int32_t KMAR_D_BAS;
				static const int32_t KMAR_DROITE;
				static const int32_t KMAR_MILIEU;
				static const int32_t KMAR_GAUCHE;
				static const int32_t KMAR_ERECTION;
				static const int32_t KMAR_MI_MOLLE;
				static const int32_t KMAR_MOLLE;
				static const int32_t PARE_CHOC_BAS;
				static const int32_t PARE_CHOC_HAUT;
				static const int32_t CHUCK_FERME;
				static const int32_t CHUCK_OUVERT;
				static const int32_t CODEUR_NON_DEFINI;
				static const int32_t CODEUR_CHARIOT;
				static const int32_t CODEUR_ROUE_DROITE;
				static const int32_t CODEUR_ROUE_GAUCHE;
				static const int32_t VIOLET;
				static const int32_t JAUNE;
				static const float PI;
		};
		
		/*! Returns an instance of the interface class 'DefaultSCI'. */
		DefaultSCI* getDefaultSCI();
		
		/*! Raises the in event 'EV_Tirette' that is defined in the default interface scope. */
		void raise_eV_Tirette();
		
		/*! Raises the in event 'EV_Obstacle' that is defined in the default interface scope. */
		void raise_eV_Obstacle();
		
		/*! Raises the in event 'EV_ConvergenceMvt' that is defined in the default interface scope. */
		void raise_eV_ConvergenceMvt();
		
		/*! Raises the in event 'EV_ConvergenceMvt_Rapide' that is defined in the default interface scope. */
		void raise_eV_ConvergenceMvt_Rapide();
		
		/*! Raises the in event 'EV_ConvergenceChariot' that is defined in the default interface scope. */
		void raise_eV_ConvergenceChariot();
		
		/*! Gets the value of the variable 'IN_x_pos' that is defined in the default interface scope. */
		double get_iN_x_pos() const;
		
		/*! Sets the value of the variable 'IN_x_pos' that is defined in the default interface scope. */
		void set_iN_x_pos(double value);
		
		/*! Gets the value of the variable 'IN_y_pos' that is defined in the default interface scope. */
		double get_iN_y_pos() const;
		
		/*! Sets the value of the variable 'IN_y_pos' that is defined in the default interface scope. */
		void set_iN_y_pos(double value);
		
		/*! Gets the value of the variable 'IN_teta_pos' that is defined in the default interface scope. */
		double get_iN_teta_pos() const;
		
		/*! Sets the value of the variable 'IN_teta_pos' that is defined in the default interface scope. */
		void set_iN_teta_pos(double value);
		
		/*! Gets the value of the variable 'IN_vitesse' that is defined in the default interface scope. */
		double get_iN_vitesse() const;
		
		/*! Sets the value of the variable 'IN_vitesse' that is defined in the default interface scope. */
		void set_iN_vitesse(double value);
		
		/*! Gets the value of the variable 'IN_sens_deplacement' that is defined in the default interface scope. */
		double get_iN_sens_deplacement() const;
		
		/*! Sets the value of the variable 'IN_sens_deplacement' that is defined in the default interface scope. */
		void set_iN_sens_deplacement(double value);
		
		/*! Gets the value of the variable 'IN_Couleur' that is defined in the default interface scope. */
		int32_t get_iN_Couleur() const;
		
		/*! Sets the value of the variable 'IN_Couleur' that is defined in the default interface scope. */
		void set_iN_Couleur(int32_t value);
		
		/*! Gets the value of the variable 'IN_choixStrategie' that is defined in the default interface scope. */
		int32_t get_iN_choixStrategie() const;
		
		/*! Sets the value of the variable 'IN_choixStrategie' that is defined in the default interface scope. */
		void set_iN_choixStrategie(int32_t value);
		
		/*! Gets the value of the variable 'IN_Obstacle' that is defined in the default interface scope. */
		int32_t get_iN_Obstacle() const;
		
		/*! Sets the value of the variable 'IN_Obstacle' that is defined in the default interface scope. */
		void set_iN_Obstacle(int32_t value);
		
		/*! Gets the value of the variable 'IN_Depression' that is defined in the default interface scope. */
		sc_boolean get_iN_Depression() const;
		
		/*! Sets the value of the variable 'IN_Depression' that is defined in the default interface scope. */
		void set_iN_Depression(sc_boolean value);
		
		/*! Gets the value of the variable 'forceObstacle' that is defined in the default interface scope. */
		sc_boolean get_forceObstacle() const;
		
		/*! Sets the value of the variable 'forceObstacle' that is defined in the default interface scope. */
		void set_forceObstacle(sc_boolean value);
		
		/*! Gets the value of the variable 'US_AV' that is defined in the default interface scope. */
		sc_boolean get_uS_AV() const;
		
		/*! Sets the value of the variable 'US_AV' that is defined in the default interface scope. */
		void set_uS_AV(sc_boolean value);
		
		/*! Gets the value of the variable 'US_AR' that is defined in the default interface scope. */
		sc_boolean get_uS_AR() const;
		
		/*! Sets the value of the variable 'US_AR' that is defined in the default interface scope. */
		void set_uS_AR(sc_boolean value);
		
		/*! Gets the value of the variable 'Couleur' that is defined in the default interface scope. */
		int32_t get_couleur() const;
		
		/*! Sets the value of the variable 'Couleur' that is defined in the default interface scope. */
		void set_couleur(int32_t value);
		
		/*! Gets the value of the variable 'choixStrategie' that is defined in the default interface scope. */
		int32_t get_choixStrategie() const;
		
		/*! Sets the value of the variable 'choixStrategie' that is defined in the default interface scope. */
		void set_choixStrategie(int32_t value);
		
		/*! Gets the value of the variable 'countTimeMvt' that is defined in the default interface scope. */
		double get_countTimeMvt() const;
		
		/*! Sets the value of the variable 'countTimeMvt' that is defined in the default interface scope. */
		void set_countTimeMvt(double value);
		
		/*! Gets the value of the variable 'tempsMatch' that is defined in the default interface scope. */
		double get_tempsMatch() const;
		
		/*! Sets the value of the variable 'tempsMatch' that is defined in the default interface scope. */
		void set_tempsMatch(double value);
		
		/*! Gets the value of the variable 'countTempo' that is defined in the default interface scope. */
		int32_t get_countTempo() const;
		
		/*! Sets the value of the variable 'countTempo' that is defined in the default interface scope. */
		void set_countTempo(int32_t value);
		
		/*! Gets the value of the variable 'countTempo2' that is defined in the default interface scope. */
		int32_t get_countTempo2() const;
		
		/*! Sets the value of the variable 'countTempo2' that is defined in the default interface scope. */
		void set_countTempo2(int32_t value);
		
		/*! Gets the value of the variable 'countTime' that is defined in the default interface scope. */
		double get_countTime() const;
		
		/*! Sets the value of the variable 'countTime' that is defined in the default interface scope. */
		void set_countTime(double value);
		
		/*! Gets the value of the variable 'x_pos_mem' that is defined in the default interface scope. */
		double get_x_pos_mem() const;
		
		/*! Sets the value of the variable 'x_pos_mem' that is defined in the default interface scope. */
		void set_x_pos_mem(double value);
		
		/*! Gets the value of the variable 'y_pos_mem' that is defined in the default interface scope. */
		double get_y_pos_mem() const;
		
		/*! Sets the value of the variable 'y_pos_mem' that is defined in the default interface scope. */
		void set_y_pos_mem(double value);
		
		/*! Gets the value of the variable 'teta_pos_mem' that is defined in the default interface scope. */
		double get_teta_pos_mem() const;
		
		/*! Sets the value of the variable 'teta_pos_mem' that is defined in the default interface scope. */
		void set_teta_pos_mem(double value);
		
		/*! Gets the value of the variable 'nb_Modules' that is defined in the default interface scope. */
		int32_t get_nb_Modules() const;
		
		/*! Sets the value of the variable 'nb_Modules' that is defined in the default interface scope. */
		void set_nb_Modules(int32_t value);
		
		/*! Gets the value of the variable 'score_grosbot' that is defined in the default interface scope. */
		int32_t get_score_grosbot() const;
		
		/*! Sets the value of the variable 'score_grosbot' that is defined in the default interface scope. */
		void set_score_grosbot(int32_t value);
		
		/*! Gets the value of the variable 'score_minibot' that is defined in the default interface scope. */
		int32_t get_score_minibot() const;
		
		/*! Sets the value of the variable 'score_minibot' that is defined in the default interface scope. */
		void set_score_minibot(int32_t value);
		
		/*! Gets the value of the variable 'score_experience' that is defined in the default interface scope. */
		int32_t get_score_experience() const;
		
		/*! Sets the value of the variable 'score_experience' that is defined in the default interface scope. */
		void set_score_experience(int32_t value);
		
		/*! Gets the value of the variable 'score_total' that is defined in the default interface scope. */
		int32_t get_score_total() const;
		
		/*! Sets the value of the variable 'score_total' that is defined in the default interface scope. */
		void set_score_total(int32_t value);
		
		/*! Gets the value of the variable 'TOB_G_HAUT' that is defined in the default interface scope. */
		const int32_t get_tOB_G_HAUT() const;
		
		/*! Gets the value of the variable 'TOB_G_MILIEU' that is defined in the default interface scope. */
		const int32_t get_tOB_G_MILIEU() const;
		
		/*! Gets the value of the variable 'TOB_G_BAS' that is defined in the default interface scope. */
		const int32_t get_tOB_G_BAS() const;
		
		/*! Gets the value of the variable 'TOB_D_HAUT' that is defined in the default interface scope. */
		const int32_t get_tOB_D_HAUT() const;
		
		/*! Gets the value of the variable 'TOB_D_MILIEU' that is defined in the default interface scope. */
		const int32_t get_tOB_D_MILIEU() const;
		
		/*! Gets the value of the variable 'TOB_D_BAS' that is defined in the default interface scope. */
		const int32_t get_tOB_D_BAS() const;
		
		/*! Gets the value of the variable 'TOUSE_G_HAUT' that is defined in the default interface scope. */
		const int32_t get_tOUSE_G_HAUT() const;
		
		/*! Gets the value of the variable 'TOUSE_G_MILIEU' that is defined in the default interface scope. */
		const int32_t get_tOUSE_G_MILIEU() const;
		
		/*! Gets the value of the variable 'TOUSE_G_BAS' that is defined in the default interface scope. */
		const int32_t get_tOUSE_G_BAS() const;
		
		/*! Gets the value of the variable 'TOUSE_D_HAUT' that is defined in the default interface scope. */
		const int32_t get_tOUSE_D_HAUT() const;
		
		/*! Gets the value of the variable 'TOUSE_D_MILIEU' that is defined in the default interface scope. */
		const int32_t get_tOUSE_D_MILIEU() const;
		
		/*! Gets the value of the variable 'TOUSE_D_BAS' that is defined in the default interface scope. */
		const int32_t get_tOUSE_D_BAS() const;
		
		/*! Gets the value of the variable 'KMAR_G_HAUT' that is defined in the default interface scope. */
		const int32_t get_kMAR_G_HAUT() const;
		
		/*! Gets the value of the variable 'KMAR_G_MILIEU' that is defined in the default interface scope. */
		const int32_t get_kMAR_G_MILIEU() const;
		
		/*! Gets the value of the variable 'KMAR_G_BAS' that is defined in the default interface scope. */
		const int32_t get_kMAR_G_BAS() const;
		
		/*! Gets the value of the variable 'KMAR_D_HAUT' that is defined in the default interface scope. */
		const int32_t get_kMAR_D_HAUT() const;
		
		/*! Gets the value of the variable 'KMAR_D_MILIEU' that is defined in the default interface scope. */
		const int32_t get_kMAR_D_MILIEU() const;
		
		/*! Gets the value of the variable 'KMAR_D_BAS' that is defined in the default interface scope. */
		const int32_t get_kMAR_D_BAS() const;
		
		/*! Gets the value of the variable 'KMAR_DROITE' that is defined in the default interface scope. */
		const int32_t get_kMAR_DROITE() const;
		
		/*! Gets the value of the variable 'KMAR_MILIEU' that is defined in the default interface scope. */
		const int32_t get_kMAR_MILIEU() const;
		
		/*! Gets the value of the variable 'KMAR_GAUCHE' that is defined in the default interface scope. */
		const int32_t get_kMAR_GAUCHE() const;
		
		/*! Gets the value of the variable 'KMAR_ERECTION' that is defined in the default interface scope. */
		const int32_t get_kMAR_ERECTION() const;
		
		/*! Gets the value of the variable 'KMAR_MI_MOLLE' that is defined in the default interface scope. */
		const int32_t get_kMAR_MI_MOLLE() const;
		
		/*! Gets the value of the variable 'KMAR_MOLLE' that is defined in the default interface scope. */
		const int32_t get_kMAR_MOLLE() const;
		
		/*! Gets the value of the variable 'PARE_CHOC_BAS' that is defined in the default interface scope. */
		const int32_t get_pARE_CHOC_BAS() const;
		
		/*! Gets the value of the variable 'PARE_CHOC_HAUT' that is defined in the default interface scope. */
		const int32_t get_pARE_CHOC_HAUT() const;
		
		/*! Gets the value of the variable 'CHUCK_FERME' that is defined in the default interface scope. */
		const int32_t get_cHUCK_FERME() const;
		
		/*! Gets the value of the variable 'CHUCK_OUVERT' that is defined in the default interface scope. */
		const int32_t get_cHUCK_OUVERT() const;
		
		/*! Gets the value of the variable 'CODEUR_NON_DEFINI' that is defined in the default interface scope. */
		const int32_t get_cODEUR_NON_DEFINI() const;
		
		/*! Gets the value of the variable 'CODEUR_CHARIOT' that is defined in the default interface scope. */
		const int32_t get_cODEUR_CHARIOT() const;
		
		/*! Gets the value of the variable 'CODEUR_ROUE_DROITE' that is defined in the default interface scope. */
		const int32_t get_cODEUR_ROUE_DROITE() const;
		
		/*! Gets the value of the variable 'CODEUR_ROUE_GAUCHE' that is defined in the default interface scope. */
		const int32_t get_cODEUR_ROUE_GAUCHE() const;
		
		/*! Gets the value of the variable 'VIOLET' that is defined in the default interface scope. */
		const int32_t get_vIOLET() const;
		
		/*! Gets the value of the variable 'JAUNE' that is defined in the default interface scope. */
		const int32_t get_jAUNE() const;
		
		/*! Gets the value of the variable 'PI' that is defined in the default interface scope. */
		const float get_pI() const;
		
		//! Inner class for asser interface scope.
		class SCI_Asser
		{
			
			public:
				
			protected:
				friend class IA;
		};
				//! Inner class for asser interface scope operation callbacks.
				class SCI_Asser_OCB
				{
					public:
						static void XY(double x, double y);
						
						static void XYTeta(double x, double y, double teta);
						
						static void Manuel(double mot_gauche, double mot_droit);
						
						static void DistanceAngle(double distance, double angle);
						
						static void Vitesse(double speedDist, double speedRot);
						
						static void setPosition(double x, double y, double teta);
						
						static void setSportivite(double idx);
				};
		
		/*! Returns an instance of the interface class 'SCI_Asser'. */
		SCI_Asser* getSCI_Asser();
		
		//! Inner class for servo interface scope.
		class SCI_Servo
		{
			
			public:
				
			protected:
				friend class IA;
		};
				//! Inner class for servo interface scope operation callbacks.
				class SCI_Servo_OCB
				{
					public:
						static void setPos(int32_t idServo, int32_t value);
						
						static void setPosSpd(int32_t idServo, int32_t pos, int32_t spd);
						
						static void setRelache(int32_t idServo, double time_ms);
				};
		
		/*! Returns an instance of the interface class 'SCI_Servo'. */
		SCI_Servo* getSCI_Servo();
		
		//! Inner class for ax interface scope.
		class SCI_Ax
		{
			
			public:
				/*! Gets the value of the variable 'BRAS_OUVERT' that is defined in the interface scope 'ax'. */
				int32_t get_bRAS_OUVERT() const;
				
				/*! Sets the value of the variable 'BRAS_OUVERT' that is defined in the interface scope 'ax'. */
				void set_bRAS_OUVERT(int32_t value);
				
				
			protected:
				friend class IA;
				int32_t BRAS_OUVERT;
		};
				//! Inner class for ax interface scope operation callbacks.
				class SCI_Ax_OCB
				{
					public:
						static void setPos(int32_t idServo, int32_t value);
						
						static void setPosSpd(int32_t idServo, int32_t pos, int32_t spd);
						
						static void setSpd(int32_t idServo, int32_t spd);
				};
		
		/*! Returns an instance of the interface class 'SCI_Ax'. */
		SCI_Ax* getSCI_Ax();
		
		//! Inner class for moteur interface scope.
		class SCI_Moteur
		{
			
			public:
				
			protected:
				friend class IA;
		};
				//! Inner class for moteur interface scope operation callbacks.
				class SCI_Moteur_OCB
				{
					public:
						static void setPWM(int32_t idMot, double pwm);
				};
		
		/*! Returns an instance of the interface class 'SCI_Moteur'. */
		SCI_Moteur* getSCI_Moteur();
		
		//! Inner class for chariot interface scope.
		class SCI_Chariot
		{
			
			public:
				/*! Gets the value of the variable 'isReady' that is defined in the interface scope 'chariot'. */
				sc_boolean get_isReady() const;
				
				/*! Sets the value of the variable 'isReady' that is defined in the interface scope 'chariot'. */
				void set_isReady(sc_boolean value);
				
				/*! Gets the value of the variable 'isConv' that is defined in the interface scope 'chariot'. */
				sc_boolean get_isConv() const;
				
				/*! Sets the value of the variable 'isConv' that is defined in the interface scope 'chariot'. */
				void set_isConv(sc_boolean value);
				
				
			protected:
				friend class IA;
				sc_boolean isReady;
				sc_boolean isConv;
		};
				//! Inner class for chariot interface scope operation callbacks.
				class SCI_Chariot_OCB
				{
					public:
						static void init();
						
						static void setPos(int32_t position);
				};
		
		/*! Returns an instance of the interface class 'SCI_Chariot'. */
		SCI_Chariot* getSCI_Chariot();
		
		//! Inner class for capteur interface scope.
		class SCI_Capteur
		{
			
			public:
				
			protected:
				friend class IA;
		};
				//! Inner class for capteur interface scope operation callbacks.
				class SCI_Capteur_OCB
				{
					public:
						static void resetCodeur(int32_t idCodeur, int32_t value);
				};
		
		/*! Returns an instance of the interface class 'SCI_Capteur'. */
		SCI_Capteur* getSCI_Capteur();
		
		//! Inner class for ihm interface scope.
		class SCI_Ihm
		{
			
			public:
				
			protected:
				friend class IA;
		};
				//! Inner class for ihm interface scope operation callbacks.
				class SCI_Ihm_OCB
				{
					public:
						static void setLed(int32_t idLed, sc_boolean onoff);
				};
		
		/*! Returns an instance of the interface class 'SCI_Ihm'. */
		SCI_Ihm* getSCI_Ihm();
		
		
		/*
		 * Functions inherited from StatemachineInterface
		 */
		virtual void init();
		
		virtual void enter();
		
		virtual void exit();
		
		virtual void runCycle();
		
		/*!
		* Checks if the state machine is active (until 2.4.1 this method was used for states).
		* A state machine is active if it has been entered. It is inactive if it has not been entered at all or if it has been exited.
		*/
		virtual sc_boolean isActive() const;
		
		
		/*!
		* Checks if all active states are final. 
		* If there are no active states then the state machine is considered being inactive. In this case this method returns false.
		*/
		virtual sc_boolean isFinal() const;
		
		/*
		 * Functions inherited from TimedStatemachineInterface
		 */
		virtual void setTimer(TimerInterface* timerInterface);
		
		virtual TimerInterface* getTimer();
		
		virtual void raiseTimeEvent(sc_eventid event);
		
		/*! Checks if the specified state is active (until 2.4.1 the used method for states was calles isActive()). */
		sc_boolean isStateActive(IAStates state) const;
		
		//! number of time events used by the state machine.
		static const sc_integer timeEventsCount = 57;
		
		//! number of time events that can be active at once.
		static const sc_integer parallelTimeEventsCount = 2;
	protected:
		IA(const IA &rhs);
		IA& operator=(const IA&);
		
		//! Inner class for internal interface scope.
		class InternalSCI
		{
			
			public:
				/*! Gets the value of the variable 'invMouv' that is defined in the internal scope. */
				int32_t get_invMouv() const;
				
				/*! Sets the value of the variable 'invMouv' that is defined in the internal scope. */
				void set_invMouv(int32_t value);
				
				/*! Gets the value of the variable 'Te' that is defined in the internal scope. */
				double get_te() const;
				
				/*! Sets the value of the variable 'Te' that is defined in the internal scope. */
				void set_te(double value);
				
				/*! Gets the value of the variable 'inhibeObstacle' that is defined in the internal scope. */
				sc_boolean get_inhibeObstacle() const;
				
				/*! Sets the value of the variable 'inhibeObstacle' that is defined in the internal scope. */
				void set_inhibeObstacle(sc_boolean value);
				
				/*! Gets the value of the variable 'evitementEnCours' that is defined in the internal scope. */
				sc_boolean get_evitementEnCours() const;
				
				/*! Sets the value of the variable 'evitementEnCours' that is defined in the internal scope. */
				void set_evitementEnCours(sc_boolean value);
				
				/*! Gets the value of the variable 'evitementTempo' that is defined in the internal scope. */
				double get_evitementTempo() const;
				
				/*! Sets the value of the variable 'evitementTempo' that is defined in the internal scope. */
				void set_evitementTempo(double value);
				
				/*! Gets the value of the variable 'sequence1' that is defined in the internal scope. */
				sc_boolean get_sequence1() const;
				
				/*! Sets the value of the variable 'sequence1' that is defined in the internal scope. */
				void set_sequence1(sc_boolean value);
				
				/*! Gets the value of the variable 'sequence2' that is defined in the internal scope. */
				sc_boolean get_sequence2() const;
				
				/*! Sets the value of the variable 'sequence2' that is defined in the internal scope. */
				void set_sequence2(sc_boolean value);
				
				/*! Gets the value of the variable 'pos_fusee' that is defined in the internal scope. */
				int32_t get_pos_fusee() const;
				
				/*! Sets the value of the variable 'pos_fusee' that is defined in the internal scope. */
				void set_pos_fusee(int32_t value);
				
				/*! Gets the value of the variable 'nb_tentatives' that is defined in the internal scope. */
				int32_t get_nb_tentatives() const;
				
				/*! Sets the value of the variable 'nb_tentatives' that is defined in the internal scope. */
				void set_nb_tentatives(int32_t value);
				
				/*! Gets the value of the variable 'etape' that is defined in the internal scope. */
				int32_t get_etape() const;
				
				/*! Sets the value of the variable 'etape' that is defined in the internal scope. */
				void set_etape(int32_t value);
				
				
			protected:
				friend class IA;
				int32_t invMouv;
				double Te;
				sc_boolean inhibeObstacle;
				sc_boolean evitementEnCours;
				double evitementTempo;
				sc_boolean sequence1;
				sc_boolean sequence2;
				int32_t pos_fusee;
				int32_t nb_tentatives;
				int32_t etape;
		};
		
		//! the maximum number of orthogonal states defines the dimension of the state configuration vector.
		static const sc_ushort maxOrthogonalStates = 3;
		//! dimension of the state configuration vector for history states
		static const sc_ushort maxHistoryStates = 2;
		
		TimerInterface* timer;
		sc_boolean timeEvents[timeEventsCount];
		
		IAStates stateConfVector[maxOrthogonalStates];
		
		IAStates historyVector[maxHistoryStates];
		sc_ushort stateConfVectorPosition;
		
		DefaultSCI iface;
		InternalSCI ifaceInternalSCI;
		SCI_Asser ifaceAsser;
		SCI_Servo ifaceServo;
		SCI_Ax ifaceAx;
		SCI_Moteur ifaceMoteur;
		SCI_Chariot ifaceChariot;
		SCI_Capteur ifaceCapteur;
		SCI_Ihm ifaceIhm;
		
		// prototypes of all internal functions
		
		void shenseq_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1();
		void shenseq_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1();
		void react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_INIT();
		void react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_HAUTS();
		void react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_APPRENTISSAGE_ASCENSEUR();
		void react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_BAS();
		void react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_01();
		void react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_RANGE_02();
		void react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_01();
		void react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_KMAR_SORTI_02();
		void react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_TOBOGGANS_HAUT();
		void react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_INIT_Copy_1_TOBOGGANS_BAS();
		void react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_VIOLET();
		void react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_COULEUR_CHOIX_COULEUR_JAUNE();
		void react_main_region_ATTENTE_TIRETTE__region0_ATTENTE_TIRETTE_CHOIX_STRATEGIE_CHOIX_NUM_STRATEGIE();
		void react_main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_ARRET_ROBOT();
		void react_main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1_SORTIE_EVITEMENT();
		void react_main_region_MATCH_EN_COURS__region0_DETECTION_OBSTACLE_r1__final_();
		void react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEPASSE_ZONE_CHAOS();
		void react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FACE_ZONE_CHAOS();
		void react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_STOCKAGE_DANS_ZONE_DEPART();
		void react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_PLACEMENT_DEVANT_DISTRIBUTEUR();
		void react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_VENTOUSAGE_ATOMES();
		void react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_RECUPERATION_ATOMES();
		void react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_DEVENTOUSAGE_ATOMES();
		void react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_GLISSADE();
		void react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_ON_RANGE();
		void react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1_FIN_SEQUENCE();
		void react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1__final_();
		void react_main_region_MATCH_EN_COURS__region0_SUPERVISOR();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_FACE_BLEUIUM();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_PREPA_POUSSETTE_GAUCHE();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_DEPLACEMENT_VERS_GOLDENIUM();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_PREPARATION_KMAR_POUR_GOLDENIUM();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_VENTOUSAGE_GOLDENIUM();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_PREPARATION_KMAR_GAUCHE();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_PREPARATION_KMAR_DROITE();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_PREPARATION_KMAR_GAUCHE_VENTOUSE_DROITE();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_PREPA_POUSSETTE_DROITE();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_GOLDENIUM_DANS_ROBOT_GAUCHE();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_PLACEMENT_DEVANT_BALANCE();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_PLUS_PROCHE_BALANCE();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_GOLDENIUM_EN_L_AIR();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_DROPAGE_GOLDENIUM();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_FIN();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1__final_();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_Copy_1_DROPAGE_GOLDENIUM();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_RECULE_AVEC_PRECAUTION();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_ARRET_MOTEURS();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_MISE_GOLDENIUM_BAS();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_RALENTISSEMENT_KMAR_01();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_RALENTISSEMENT_KMAR_02();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_POSE_GOLDENIUM();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_DECOLLAGE_GOLDENIUM_01();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_DECOLLAGE_GOLDENIUM_02();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_KMAR_SECURE();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_DECOLLAGE_GOLDENIUM_03();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_Copy_1_GOLDENIUM_DANS_ROBOT_GAUCHE();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_DESCEND_KMAR();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_KMAR_MONTE();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_KMAR_BIEN_DROIT();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_ROTATION_VERS_GOLDENIUM();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_PLACEMENT_FACE_GOLDENIUM();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_Copy_1_ACCOSTAGE_BALANCE();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_DECLENCHEMENT_ACCELERATEUR();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_Copy_1_FACE_BLEUIUM();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_Copy_1_DECLENCHEMENT_ACCELERATEUR();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_Copy_1_ROTATION_VERS_GOLDENIUM();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1_Copy_1_PREPA_POUSSETTE_GAUCHE();
		void react_main_region_FIN_MATCH();
		void react_main_region_MATCH_EN_COURS__region0_NETTOYAGE_r1__choice_0();
		void react_main_region_MATCH_EN_COURS__region0__choice_0();
		void react_main_region_MATCH_EN_COURS__region0_GOLDENIUM_r1__choice_0();
		void clearInEvents();
		void clearOutEvents();
		
	private:
};



#endif /* IA_H_ */
