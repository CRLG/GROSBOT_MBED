
#ifndef IA_H_
#define IA_H_

#include "sc_types.h"
#include "StatemachineInterface.h"

/*! \file Header of the state machine 'IA'.
*/

class IA : public StatemachineInterface {
	
	public:
		
		IA();
		
		~IA();
		
		//! enumeration of all states 
		typedef enum {
			STRATEGIE_ATTENTE_DEBUT_MATCH,
			STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1,
			STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2,
			STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_INIT,
			STRATEGIE_MATCH,
			STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION,
			STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_PREMIER_PAS,
			STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_INIT_POS,
			STRATEGIE_MATCH_MATCH_REGION_EVITEMENT,
			STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT,
			STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT,
			STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH,
			STRATEGIE_FIN_MATCH,
			STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS,
			IA_last_state
		} IAStates;
		
		//! Inner class for default interface scope.
		class DefaultSCI {
			
			public:
				/*! Raises the in event 'EV_Tirette' that is defined in the default interface scope. */ 
				void raise_eV_Tirette();
				
				/*! Raises the in event 'EV_Obstacle' that is defined in the default interface scope. */ 
				void raise_eV_Obstacle();
				
				/*! Raises the in event 'EV_ConvergenceMvt' that is defined in the default interface scope. */ 
				void raise_eV_ConvergenceMvt();
				
				/*! Raises the in event 'EV_ConvergenceMvt_Rapide' that is defined in the default interface scope. */ 
				void raise_eV_ConvergenceMvt_Rapide();
				
				/*! Gets the value of the variable 'IN_x_pos' that is defined in the default interface scope. */ 
				sc_real get_iN_x_pos();
				
				/*! Sets the value of the variable 'IN_x_pos' that is defined in the default interface scope. */ 
				void set_iN_x_pos(sc_real value);
				
				/*! Gets the value of the variable 'IN_y_pos' that is defined in the default interface scope. */ 
				sc_real get_iN_y_pos();
				
				/*! Sets the value of the variable 'IN_y_pos' that is defined in the default interface scope. */ 
				void set_iN_y_pos(sc_real value);
				
				/*! Gets the value of the variable 'IN_teta_pos' that is defined in the default interface scope. */ 
				sc_real get_iN_teta_pos();
				
				/*! Sets the value of the variable 'IN_teta_pos' that is defined in the default interface scope. */ 
				void set_iN_teta_pos(sc_real value);
				
				/*! Gets the value of the variable 'IN_vitesse' that is defined in the default interface scope. */ 
				sc_real get_iN_vitesse();
				
				/*! Sets the value of the variable 'IN_vitesse' that is defined in the default interface scope. */ 
				void set_iN_vitesse(sc_real value);
				
				/*! Gets the value of the variable 'IN_sens_deplacement' that is defined in the default interface scope. */ 
				sc_real get_iN_sens_deplacement();
				
				/*! Sets the value of the variable 'IN_sens_deplacement' that is defined in the default interface scope. */ 
				void set_iN_sens_deplacement(sc_real value);
				
				/*! Gets the value of the variable 'IN_Couleur' that is defined in the default interface scope. */ 
				sc_integer get_iN_Couleur();
				
				/*! Sets the value of the variable 'IN_Couleur' that is defined in the default interface scope. */ 
				void set_iN_Couleur(sc_integer value);
				
				/*! Gets the value of the variable 'IN_Obstacle' that is defined in the default interface scope. */ 
				sc_integer get_iN_Obstacle();
				
				/*! Sets the value of the variable 'IN_Obstacle' that is defined in the default interface scope. */ 
				void set_iN_Obstacle(sc_integer value);
				
				/*! Gets the value of the variable 'countTimeMvt' that is defined in the default interface scope. */ 
				sc_real get_countTimeMvt();
				
				/*! Sets the value of the variable 'countTimeMvt' that is defined in the default interface scope. */ 
				void set_countTimeMvt(sc_real value);
				
				/*! Gets the value of the variable 'tempsMatch' that is defined in the default interface scope. */ 
				sc_real get_tempsMatch();
				
				/*! Sets the value of the variable 'tempsMatch' that is defined in the default interface scope. */ 
				void set_tempsMatch(sc_real value);
				
				/*! Gets the value of the variable 'countTime' that is defined in the default interface scope. */ 
				sc_real get_countTime();
				
				/*! Sets the value of the variable 'countTime' that is defined in the default interface scope. */ 
				void set_countTime(sc_real value);
				
				/*! Gets the value of the variable 'SERVO_BRAS' that is defined in the default interface scope. */ 
				sc_integer get_sERVO_BRAS();
				
				/*! Gets the value of the variable 'SERVO_CENTREUR_G' that is defined in the default interface scope. */ 
				sc_integer get_sERVO_CENTREUR_G();
				
				/*! Gets the value of the variable 'SERVO_CENTREUR_D' that is defined in the default interface scope. */ 
				sc_integer get_sERVO_CENTREUR_D();
				
				/*! Gets the value of the variable 'SERVO_PINCE_D' that is defined in the default interface scope. */ 
				sc_integer get_sERVO_PINCE_D();
				
				/*! Gets the value of the variable 'SERVO_PINCE_G' that is defined in the default interface scope. */ 
				sc_integer get_sERVO_PINCE_G();
				
				/*! Gets the value of the variable 'SERVO_BALLE' that is defined in the default interface scope. */ 
				sc_integer get_sERVO_BALLE();
				
				/*! Gets the value of the variable 'SERVO_RECOLTEURS' that is defined in the default interface scope. */ 
				sc_integer get_sERVO_RECOLTEURS();
				
				/*! Gets the value of the variable 'SERVO_VOLET' that is defined in the default interface scope. */ 
				sc_integer get_sERVO_VOLET();
				
				/*! Gets the value of the variable 'MOTEUR_ROUE_GAUCHE' that is defined in the default interface scope. */ 
				sc_integer get_mOTEUR_ROUE_GAUCHE();
				
				/*! Gets the value of the variable 'MOTEUR_ROUE_DROITE' that is defined in the default interface scope. */ 
				sc_integer get_mOTEUR_ROUE_DROITE();
				
				/*! Gets the value of the variable 'MOTEUR_ASCENSEUR' that is defined in the default interface scope. */ 
				sc_integer get_mOTEUR_ASCENSEUR();
				
				/*! Gets the value of the variable 'MOTEUR_DISTRIBUTEUR' that is defined in the default interface scope. */ 
				sc_integer get_mOTEUR_DISTRIBUTEUR();
				
				/*! Gets the value of the variable 'MOTEUR_NON_DEFINI' that is defined in the default interface scope. */ 
				sc_integer get_mOTEUR_NON_DEFINI();
				
				/*! Gets the value of the variable 'MOTEUR_SOUFFLEUR' that is defined in the default interface scope. */ 
				sc_integer get_mOTEUR_SOUFFLEUR();
				
				/*! Gets the value of the variable 'CODEUR_NON_DEFINI' that is defined in the default interface scope. */ 
				sc_integer get_cODEUR_NON_DEFINI();
				
				/*! Gets the value of the variable 'CODEUR_ASCENSEUR' that is defined in the default interface scope. */ 
				sc_integer get_cODEUR_ASCENSEUR();
				
				/*! Gets the value of the variable 'CODEUR_ROUE_DROITE' that is defined in the default interface scope. */ 
				sc_integer get_cODEUR_ROUE_DROITE();
				
				/*! Gets the value of the variable 'CODEUR_ROUE_GAUCHE' that is defined in the default interface scope. */ 
				sc_integer get_cODEUR_ROUE_GAUCHE();
				
				/*! Gets the value of the variable 'JAUNE' that is defined in the default interface scope. */ 
				sc_integer get_jAUNE();
				
				/*! Gets the value of the variable 'VERT' that is defined in the default interface scope. */ 
				sc_integer get_vERT();
				
				
			protected:
				friend class IA;
				sc_boolean EV_Tirette_raised;
				sc_boolean EV_Obstacle_raised;
				sc_boolean EV_ConvergenceMvt_raised;
				sc_boolean EV_ConvergenceMvt_Rapide_raised;
				sc_real IN_x_pos;
				sc_real IN_y_pos;
				sc_real IN_teta_pos;
				sc_real IN_vitesse;
				sc_real IN_sens_deplacement;
				sc_integer IN_Couleur;
				sc_integer IN_Obstacle;
				sc_real countTimeMvt;
				sc_real tempsMatch;
				sc_real countTime;
				sc_integer SERVO_BRAS;
				sc_integer SERVO_CENTREUR_G;
				sc_integer SERVO_CENTREUR_D;
				sc_integer SERVO_PINCE_D;
				sc_integer SERVO_PINCE_G;
				sc_integer SERVO_BALLE;
				sc_integer SERVO_RECOLTEURS;
				sc_integer SERVO_VOLET;
				sc_integer MOTEUR_ROUE_GAUCHE;
				sc_integer MOTEUR_ROUE_DROITE;
				sc_integer MOTEUR_ASCENSEUR;
				sc_integer MOTEUR_DISTRIBUTEUR;
				sc_integer MOTEUR_NON_DEFINI;
				sc_integer MOTEUR_SOUFFLEUR;
				sc_integer CODEUR_NON_DEFINI;
				sc_integer CODEUR_ASCENSEUR;
				sc_integer CODEUR_ROUE_DROITE;
				sc_integer CODEUR_ROUE_GAUCHE;
				sc_integer JAUNE;
				sc_integer VERT;
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
		
		/*! Gets the value of the variable 'IN_x_pos' that is defined in the default interface scope. */ 
		sc_real get_iN_x_pos();
		
		/*! Sets the value of the variable 'IN_x_pos' that is defined in the default interface scope. */ 
		void set_iN_x_pos(sc_real value);
		
		/*! Gets the value of the variable 'IN_y_pos' that is defined in the default interface scope. */ 
		sc_real get_iN_y_pos();
		
		/*! Sets the value of the variable 'IN_y_pos' that is defined in the default interface scope. */ 
		void set_iN_y_pos(sc_real value);
		
		/*! Gets the value of the variable 'IN_teta_pos' that is defined in the default interface scope. */ 
		sc_real get_iN_teta_pos();
		
		/*! Sets the value of the variable 'IN_teta_pos' that is defined in the default interface scope. */ 
		void set_iN_teta_pos(sc_real value);
		
		/*! Gets the value of the variable 'IN_vitesse' that is defined in the default interface scope. */ 
		sc_real get_iN_vitesse();
		
		/*! Sets the value of the variable 'IN_vitesse' that is defined in the default interface scope. */ 
		void set_iN_vitesse(sc_real value);
		
		/*! Gets the value of the variable 'IN_sens_deplacement' that is defined in the default interface scope. */ 
		sc_real get_iN_sens_deplacement();
		
		/*! Sets the value of the variable 'IN_sens_deplacement' that is defined in the default interface scope. */ 
		void set_iN_sens_deplacement(sc_real value);
		
		/*! Gets the value of the variable 'IN_Couleur' that is defined in the default interface scope. */ 
		sc_integer get_iN_Couleur();
		
		/*! Sets the value of the variable 'IN_Couleur' that is defined in the default interface scope. */ 
		void set_iN_Couleur(sc_integer value);
		
		/*! Gets the value of the variable 'IN_Obstacle' that is defined in the default interface scope. */ 
		sc_integer get_iN_Obstacle();
		
		/*! Sets the value of the variable 'IN_Obstacle' that is defined in the default interface scope. */ 
		void set_iN_Obstacle(sc_integer value);
		
		/*! Gets the value of the variable 'countTimeMvt' that is defined in the default interface scope. */ 
		sc_real get_countTimeMvt();
		
		/*! Sets the value of the variable 'countTimeMvt' that is defined in the default interface scope. */ 
		void set_countTimeMvt(sc_real value);
		
		/*! Gets the value of the variable 'tempsMatch' that is defined in the default interface scope. */ 
		sc_real get_tempsMatch();
		
		/*! Sets the value of the variable 'tempsMatch' that is defined in the default interface scope. */ 
		void set_tempsMatch(sc_real value);
		
		/*! Gets the value of the variable 'countTime' that is defined in the default interface scope. */ 
		sc_real get_countTime();
		
		/*! Sets the value of the variable 'countTime' that is defined in the default interface scope. */ 
		void set_countTime(sc_real value);
		
		/*! Gets the value of the variable 'SERVO_BRAS' that is defined in the default interface scope. */ 
		sc_integer get_sERVO_BRAS();
		
		/*! Gets the value of the variable 'SERVO_CENTREUR_G' that is defined in the default interface scope. */ 
		sc_integer get_sERVO_CENTREUR_G();
		
		/*! Gets the value of the variable 'SERVO_CENTREUR_D' that is defined in the default interface scope. */ 
		sc_integer get_sERVO_CENTREUR_D();
		
		/*! Gets the value of the variable 'SERVO_PINCE_D' that is defined in the default interface scope. */ 
		sc_integer get_sERVO_PINCE_D();
		
		/*! Gets the value of the variable 'SERVO_PINCE_G' that is defined in the default interface scope. */ 
		sc_integer get_sERVO_PINCE_G();
		
		/*! Gets the value of the variable 'SERVO_BALLE' that is defined in the default interface scope. */ 
		sc_integer get_sERVO_BALLE();
		
		/*! Gets the value of the variable 'SERVO_RECOLTEURS' that is defined in the default interface scope. */ 
		sc_integer get_sERVO_RECOLTEURS();
		
		/*! Gets the value of the variable 'SERVO_VOLET' that is defined in the default interface scope. */ 
		sc_integer get_sERVO_VOLET();
		
		/*! Gets the value of the variable 'MOTEUR_ROUE_GAUCHE' that is defined in the default interface scope. */ 
		sc_integer get_mOTEUR_ROUE_GAUCHE();
		
		/*! Gets the value of the variable 'MOTEUR_ROUE_DROITE' that is defined in the default interface scope. */ 
		sc_integer get_mOTEUR_ROUE_DROITE();
		
		/*! Gets the value of the variable 'MOTEUR_ASCENSEUR' that is defined in the default interface scope. */ 
		sc_integer get_mOTEUR_ASCENSEUR();
		
		/*! Gets the value of the variable 'MOTEUR_DISTRIBUTEUR' that is defined in the default interface scope. */ 
		sc_integer get_mOTEUR_DISTRIBUTEUR();
		
		/*! Gets the value of the variable 'MOTEUR_NON_DEFINI' that is defined in the default interface scope. */ 
		sc_integer get_mOTEUR_NON_DEFINI();
		
		/*! Gets the value of the variable 'MOTEUR_SOUFFLEUR' that is defined in the default interface scope. */ 
		sc_integer get_mOTEUR_SOUFFLEUR();
		
		/*! Gets the value of the variable 'CODEUR_NON_DEFINI' that is defined in the default interface scope. */ 
		sc_integer get_cODEUR_NON_DEFINI();
		
		/*! Gets the value of the variable 'CODEUR_ASCENSEUR' that is defined in the default interface scope. */ 
		sc_integer get_cODEUR_ASCENSEUR();
		
		/*! Gets the value of the variable 'CODEUR_ROUE_DROITE' that is defined in the default interface scope. */ 
		sc_integer get_cODEUR_ROUE_DROITE();
		
		/*! Gets the value of the variable 'CODEUR_ROUE_GAUCHE' that is defined in the default interface scope. */ 
		sc_integer get_cODEUR_ROUE_GAUCHE();
		
		/*! Gets the value of the variable 'JAUNE' that is defined in the default interface scope. */ 
		sc_integer get_jAUNE();
		
		/*! Gets the value of the variable 'VERT' that is defined in the default interface scope. */ 
		sc_integer get_vERT();
		
		
		//! Inner class for asser interface scope.
		class SCI_Asser {
			
			public:
				
			protected:
				friend class IA;
		};
		
		//! Inner class for asser interface scope operation callbacks.
		class SCI_Asser_OCB {
			public:
				static void XY(sc_real x, sc_real y);
				
				static void XYTeta(sc_real x, sc_real y, sc_real teta);
				
				static void Manuel(sc_real mot_gauche, sc_real mot_droit);
				
				static void DistanceAngle(sc_real distance, sc_real angle);
				
				static void Vitesse(sc_real speedDist, sc_real speedRot);
				
				static void setPosition(sc_real x, sc_real y, sc_real teta);
		};
		
		/*! Returns an instance of the interface class 'SCI_Asser'. */
		SCI_Asser* getSCI_Asser();
		
		//! Inner class for servo interface scope.
		class SCI_Servo {
			
			public:
				
			protected:
				friend class IA;
		};
		
		//! Inner class for servo interface scope operation callbacks.
		class SCI_Servo_OCB {
			public:
				static void setPos(sc_integer idServo, sc_integer value);
				
				static void setPosSpd(sc_integer idServo, sc_integer pos, sc_integer spd);
				
				static void setRelache(sc_integer idServo, sc_real time_ms);
		};
		
		/*! Returns an instance of the interface class 'SCI_Servo'. */
		SCI_Servo* getSCI_Servo();
		
		//! Inner class for moteur interface scope.
		class SCI_Moteur {
			
			public:
				
			protected:
				friend class IA;
		};
		
		//! Inner class for moteur interface scope operation callbacks.
		class SCI_Moteur_OCB {
			public:
				static void setPWM(sc_integer idMot, sc_real pwm);
		};
		
		/*! Returns an instance of the interface class 'SCI_Moteur'. */
		SCI_Moteur* getSCI_Moteur();
		
		//! Inner class for ascenseur interface scope.
		class SCI_Ascenseur {
			
			public:
				
			protected:
				friend class IA;
		};
		
		//! Inner class for ascenseur interface scope operation callbacks.
		class SCI_Ascenseur_OCB {
			public:
				static void init();
				
				static void goTo_ID(sc_integer position);
		};
		
		/*! Returns an instance of the interface class 'SCI_Ascenseur'. */
		SCI_Ascenseur* getSCI_Ascenseur();
		
		//! Inner class for capteur interface scope.
		class SCI_Capteur {
			
			public:
				
			protected:
				friend class IA;
		};
		
		//! Inner class for capteur interface scope operation callbacks.
		class SCI_Capteur_OCB {
			public:
				static void resetCodeur(sc_integer idCodeur, sc_integer value);
		};
		
		/*! Returns an instance of the interface class 'SCI_Capteur'. */
		SCI_Capteur* getSCI_Capteur();
		
		//! Inner class for ihm interface scope.
		class SCI_Ihm {
			
			public:
				
			protected:
				friend class IA;
		};
		
		//! Inner class for ihm interface scope operation callbacks.
		class SCI_Ihm_OCB {
			public:
				static void setLed(sc_integer idLed, sc_boolean onoff);
		};
		
		/*! Returns an instance of the interface class 'SCI_Ihm'. */
		SCI_Ihm* getSCI_Ihm();
		
		
		void init();
		
		void enter();
		
		void exit();
		
		void runCycle();
		
		
		/*! Checks if the specified state is active. */
		sc_boolean isActive(IAStates state);
	
	protected:
	
		//! Inner class for internal interface scope.
		class InternalSCI {
			
			public:
				/*! Gets the value of the variable 'Couleur' that is defined in the internal scope. */ 
				sc_integer get_couleur();
				
				/*! Sets the value of the variable 'Couleur' that is defined in the internal scope. */ 
				void set_couleur(sc_integer value);
				
				/*! Gets the value of the variable 'invMouv' that is defined in the internal scope. */ 
				sc_integer get_invMouv();
				
				/*! Sets the value of the variable 'invMouv' that is defined in the internal scope. */ 
				void set_invMouv(sc_integer value);
				
				/*! Gets the value of the variable 'Te' that is defined in the internal scope. */ 
				sc_real get_te();
				
				/*! Sets the value of the variable 'Te' that is defined in the internal scope. */ 
				void set_te(sc_real value);
				
				/*! Gets the value of the variable 'PI' that is defined in the internal scope. */ 
				sc_real get_pI();
				
				/*! Gets the value of the variable 'inhibeObstacle' that is defined in the internal scope. */ 
				sc_boolean get_inhibeObstacle();
				
				/*! Sets the value of the variable 'inhibeObstacle' that is defined in the internal scope. */ 
				void set_inhibeObstacle(sc_boolean value);
				
				/*! Gets the value of the variable 'evitementEnCours' that is defined in the internal scope. */ 
				sc_boolean get_evitementEnCours();
				
				/*! Sets the value of the variable 'evitementEnCours' that is defined in the internal scope. */ 
				void set_evitementEnCours(sc_boolean value);
				
				/*! Gets the value of the variable 'evitementTempo' that is defined in the internal scope. */ 
				sc_real get_evitementTempo();
				
				/*! Sets the value of the variable 'evitementTempo' that is defined in the internal scope. */ 
				void set_evitementTempo(sc_real value);
				
				
			protected:
				friend class IA;
				sc_integer Couleur;
				sc_integer invMouv;
				sc_real Te;
				sc_real PI;
				sc_boolean inhibeObstacle;
				sc_boolean evitementEnCours;
				sc_real evitementTempo;
		};
	
		//! the maximum number of orthogonal states defines the dimension of the state configuration vector.
		static const sc_integer maxOrthogonalStates = 2;
		//! dimension of the state configuration vector for history states
		static const sc_integer maxHistoryStates = 1;
		
		
		IAStates stateConfVector[maxOrthogonalStates];
		
		IAStates historyVector[maxHistoryStates];
		sc_ushort stateConfVectorPosition;
		
		DefaultSCI iface;
		InternalSCI ifaceInternalSCI;
		SCI_Asser ifaceAsser;
		SCI_Servo ifaceServo;
		SCI_Moteur ifaceMoteur;
		SCI_Ascenseur ifaceAscenseur;
		SCI_Capteur ifaceCapteur;
		SCI_Ihm ifaceIhm;
		
		// prototypes of all internal functions
		
		sc_boolean check_lr0();
		void effect_lr0();
		void enact_SequenceImpl();
		void exact_SequenceImpl();
		void shenseq_SequenceImpl();
		void react_STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1();
		void react_STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2();
		void react_STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_INIT();
		void react_STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_PREMIER_PAS();
		void react_STRATEGIE_MATCH_MATCH_REGION_HOMOLOGATION_HOMOLOGATION_REGION_INIT_POS();
		void react_STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT();
		void react_STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT();
		void react_STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH();
		void react_STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS();
		void clearInEvents();
		void clearOutEvents();
		
};
#endif /* IA_H_ */
