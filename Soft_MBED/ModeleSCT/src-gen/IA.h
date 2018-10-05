
#ifndef IA_H_
#define IA_H_

#include "../src/sc_types.h"
#include "../src/StatemachineInterface.h"
#include "../src/TimedStatemachineInterface.h"
#include "../../Includes/CGlobale.h"
#include "../../Includes/CLeds.h"
#include "../../Includes/CAsservissement.h"

/*! \file Header of the state machine 'IA'.
*/


/*! Define indices of states in the StateConfVector */
#define SCVI_MAIN_REGION_STATEA 0
#define SCVI_MAIN_REGION_STATEB 0

class IA : public TimedStatemachineInterface, public StatemachineInterface
{
	public:
		IA();
		
		~IA();
		
		/*! Enumeration of all states */ 
		typedef enum
		{
			IA_last_state,
			main_region_StateA,
			main_region_StateB
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
				
				/*! Gets the value of the variable 'IN_Obstacle' that is defined in the default interface scope. */
				int32_t get_iN_Obstacle() const;
				
				/*! Sets the value of the variable 'IN_Obstacle' that is defined in the default interface scope. */
				void set_iN_Obstacle(int32_t value);
				
				/*! Gets the value of the variable 'IN_Depression' that is defined in the default interface scope. */
				sc_boolean get_iN_Depression() const;
				
				/*! Sets the value of the variable 'IN_Depression' that is defined in the default interface scope. */
				void set_iN_Depression(sc_boolean value);
				
				/*! Gets the value of the variable 'countTimeMvt' that is defined in the default interface scope. */
				double get_countTimeMvt() const;
				
				/*! Sets the value of the variable 'countTimeMvt' that is defined in the default interface scope. */
				void set_countTimeMvt(double value);
				
				/*! Gets the value of the variable 'tempsMatch' that is defined in the default interface scope. */
				int32_t get_tempsMatch() const;
				
				/*! Sets the value of the variable 'tempsMatch' that is defined in the default interface scope. */
				void set_tempsMatch(int32_t value);
				
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
				
				/*! Gets the value of the variable 'SERVO_VENTOUSE' that is defined in the default interface scope. */
				const int32_t get_sERVO_VENTOUSE() const;
				
				/*! Gets the value of the variable 'SERVO_CENTREUR_G' that is defined in the default interface scope. */
				const int32_t get_sERVO_CENTREUR_G() const;
				
				/*! Gets the value of the variable 'SERVO_CENTREUR_D' that is defined in the default interface scope. */
				const int32_t get_sERVO_CENTREUR_D() const;
				
				/*! Gets the value of the variable 'SERVO_PINCE_D' that is defined in the default interface scope. */
				const int32_t get_sERVO_PINCE_D() const;
				
				/*! Gets the value of the variable 'SERVO_PINCE_G' that is defined in the default interface scope. */
				const int32_t get_sERVO_PINCE_G() const;
				
				/*! Gets the value of the variable 'SERVO_BALLE' that is defined in the default interface scope. */
				const int32_t get_sERVO_BALLE() const;
				
				/*! Gets the value of the variable 'SERVO_RECOLTEURS' that is defined in the default interface scope. */
				const int32_t get_sERVO_RECOLTEURS() const;
				
				/*! Gets the value of the variable 'SERVO_VOLET' that is defined in the default interface scope. */
				const int32_t get_sERVO_VOLET() const;
				
				/*! Gets the value of the variable 'AX_ROTATION' that is defined in the default interface scope. */
				const int32_t get_aX_ROTATION() const;
				
				/*! Gets the value of the variable 'AX_COULEUR' that is defined in the default interface scope. */
				const int32_t get_aX_COULEUR() const;
				
				/*! Gets the value of the variable 'AX_LEVIER' that is defined in the default interface scope. */
				const int32_t get_aX_LEVIER() const;
				
				/*! Gets the value of the variable 'KMAR_SORTI' that is defined in the default interface scope. */
				const int32_t get_kMAR_SORTI() const;
				
				/*! Gets the value of the variable 'KMAR_RENTRE' that is defined in the default interface scope. */
				const int32_t get_kMAR_RENTRE() const;
				
				/*! Gets the value of the variable 'KMAR_PRENDRE' that is defined in the default interface scope. */
				const int32_t get_kMAR_PRENDRE() const;
				
				/*! Gets the value of the variable 'VENTOUSE_G' that is defined in the default interface scope. */
				const int32_t get_vENTOUSE_G() const;
				
				/*! Gets the value of the variable 'VENTOUSE_D' that is defined in the default interface scope. */
				const int32_t get_vENTOUSE_D() const;
				
				/*! Gets the value of the variable 'KMAR_DROIT' that is defined in the default interface scope. */
				const int32_t get_kMAR_DROIT() const;
				
				/*! Gets the value of the variable 'MOTEUR_ROUE_GAUCHE' that is defined in the default interface scope. */
				const int32_t get_mOTEUR_ROUE_GAUCHE() const;
				
				/*! Gets the value of the variable 'MOTEUR_ROUE_DROITE' that is defined in the default interface scope. */
				const int32_t get_mOTEUR_ROUE_DROITE() const;
				
				/*! Gets the value of the variable 'MOTEUR_FUNNY' that is defined in the default interface scope. */
				const int32_t get_mOTEUR_FUNNY() const;
				
				/*! Gets the value of the variable 'MOTEUR_MOELDAR' that is defined in the default interface scope. */
				const int32_t get_mOTEUR_MOELDAR() const;
				
				/*! Gets the value of the variable 'CODEUR_NON_DEFINI' that is defined in the default interface scope. */
				const int32_t get_cODEUR_NON_DEFINI() const;
				
				/*! Gets the value of the variable 'CODEUR_CHARIOT' that is defined in the default interface scope. */
				const int32_t get_cODEUR_CHARIOT() const;
				
				/*! Gets the value of the variable 'CODEUR_ROUE_DROITE' that is defined in the default interface scope. */
				const int32_t get_cODEUR_ROUE_DROITE() const;
				
				/*! Gets the value of the variable 'CODEUR_ROUE_GAUCHE' that is defined in the default interface scope. */
				const int32_t get_cODEUR_ROUE_GAUCHE() const;
				
				/*! Gets the value of the variable 'ORANGE' that is defined in the default interface scope. */
				int32_t get_oRANGE() const;
				
				/*! Sets the value of the variable 'ORANGE' that is defined in the default interface scope. */
				void set_oRANGE(int32_t value);
				
				/*! Gets the value of the variable 'VERT' that is defined in the default interface scope. */
				int32_t get_vERT() const;
				
				/*! Sets the value of the variable 'VERT' that is defined in the default interface scope. */
				void set_vERT(int32_t value);
				
				/*! Gets the value of the variable 'BLEU' that is defined in the default interface scope. */
				int32_t get_bLEU() const;
				
				/*! Sets the value of the variable 'BLEU' that is defined in the default interface scope. */
				void set_bLEU(int32_t value);
				
				/*! Gets the value of the variable 'JAUNE' that is defined in the default interface scope. */
				int32_t get_jAUNE() const;
				
				/*! Sets the value of the variable 'JAUNE' that is defined in the default interface scope. */
				void set_jAUNE(int32_t value);
				
				
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
				int32_t IN_Obstacle;
				sc_boolean IN_Depression;
				double countTimeMvt;
				int32_t tempsMatch;
				int32_t countTempo;
				int32_t countTempo2;
				double countTime;
				double x_pos_mem;
				double y_pos_mem;
				double teta_pos_mem;
				int32_t nb_Modules;
				static const int32_t SERVO_VENTOUSE;
				static const int32_t SERVO_CENTREUR_G;
				static const int32_t SERVO_CENTREUR_D;
				static const int32_t SERVO_PINCE_D;
				static const int32_t SERVO_PINCE_G;
				static const int32_t SERVO_BALLE;
				static const int32_t SERVO_RECOLTEURS;
				static const int32_t SERVO_VOLET;
				static const int32_t AX_ROTATION;
				static const int32_t AX_COULEUR;
				static const int32_t AX_LEVIER;
				static const int32_t KMAR_SORTI;
				static const int32_t KMAR_RENTRE;
				static const int32_t KMAR_PRENDRE;
				static const int32_t VENTOUSE_G;
				static const int32_t VENTOUSE_D;
				static const int32_t KMAR_DROIT;
				static const int32_t MOTEUR_ROUE_GAUCHE;
				static const int32_t MOTEUR_ROUE_DROITE;
				static const int32_t MOTEUR_FUNNY;
				static const int32_t MOTEUR_MOELDAR;
				static const int32_t CODEUR_NON_DEFINI;
				static const int32_t CODEUR_CHARIOT;
				static const int32_t CODEUR_ROUE_DROITE;
				static const int32_t CODEUR_ROUE_GAUCHE;
				int32_t ORANGE;
				int32_t VERT;
				int32_t BLEU;
				int32_t JAUNE;
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
		
		/*! Gets the value of the variable 'IN_Obstacle' that is defined in the default interface scope. */
		int32_t get_iN_Obstacle() const;
		
		/*! Sets the value of the variable 'IN_Obstacle' that is defined in the default interface scope. */
		void set_iN_Obstacle(int32_t value);
		
		/*! Gets the value of the variable 'IN_Depression' that is defined in the default interface scope. */
		sc_boolean get_iN_Depression() const;
		
		/*! Sets the value of the variable 'IN_Depression' that is defined in the default interface scope. */
		void set_iN_Depression(sc_boolean value);
		
		/*! Gets the value of the variable 'countTimeMvt' that is defined in the default interface scope. */
		double get_countTimeMvt() const;
		
		/*! Sets the value of the variable 'countTimeMvt' that is defined in the default interface scope. */
		void set_countTimeMvt(double value);
		
		/*! Gets the value of the variable 'tempsMatch' that is defined in the default interface scope. */
		int32_t get_tempsMatch() const;
		
		/*! Sets the value of the variable 'tempsMatch' that is defined in the default interface scope. */
		void set_tempsMatch(int32_t value);
		
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
		
		/*! Gets the value of the variable 'SERVO_VENTOUSE' that is defined in the default interface scope. */
		const int32_t get_sERVO_VENTOUSE() const;
		
		/*! Gets the value of the variable 'SERVO_CENTREUR_G' that is defined in the default interface scope. */
		const int32_t get_sERVO_CENTREUR_G() const;
		
		/*! Gets the value of the variable 'SERVO_CENTREUR_D' that is defined in the default interface scope. */
		const int32_t get_sERVO_CENTREUR_D() const;
		
		/*! Gets the value of the variable 'SERVO_PINCE_D' that is defined in the default interface scope. */
		const int32_t get_sERVO_PINCE_D() const;
		
		/*! Gets the value of the variable 'SERVO_PINCE_G' that is defined in the default interface scope. */
		const int32_t get_sERVO_PINCE_G() const;
		
		/*! Gets the value of the variable 'SERVO_BALLE' that is defined in the default interface scope. */
		const int32_t get_sERVO_BALLE() const;
		
		/*! Gets the value of the variable 'SERVO_RECOLTEURS' that is defined in the default interface scope. */
		const int32_t get_sERVO_RECOLTEURS() const;
		
		/*! Gets the value of the variable 'SERVO_VOLET' that is defined in the default interface scope. */
		const int32_t get_sERVO_VOLET() const;
		
		/*! Gets the value of the variable 'AX_ROTATION' that is defined in the default interface scope. */
		const int32_t get_aX_ROTATION() const;
		
		/*! Gets the value of the variable 'AX_COULEUR' that is defined in the default interface scope. */
		const int32_t get_aX_COULEUR() const;
		
		/*! Gets the value of the variable 'AX_LEVIER' that is defined in the default interface scope. */
		const int32_t get_aX_LEVIER() const;
		
		/*! Gets the value of the variable 'KMAR_SORTI' that is defined in the default interface scope. */
		const int32_t get_kMAR_SORTI() const;
		
		/*! Gets the value of the variable 'KMAR_RENTRE' that is defined in the default interface scope. */
		const int32_t get_kMAR_RENTRE() const;
		
		/*! Gets the value of the variable 'KMAR_PRENDRE' that is defined in the default interface scope. */
		const int32_t get_kMAR_PRENDRE() const;
		
		/*! Gets the value of the variable 'VENTOUSE_G' that is defined in the default interface scope. */
		const int32_t get_vENTOUSE_G() const;
		
		/*! Gets the value of the variable 'VENTOUSE_D' that is defined in the default interface scope. */
		const int32_t get_vENTOUSE_D() const;
		
		/*! Gets the value of the variable 'KMAR_DROIT' that is defined in the default interface scope. */
		const int32_t get_kMAR_DROIT() const;
		
		/*! Gets the value of the variable 'MOTEUR_ROUE_GAUCHE' that is defined in the default interface scope. */
		const int32_t get_mOTEUR_ROUE_GAUCHE() const;
		
		/*! Gets the value of the variable 'MOTEUR_ROUE_DROITE' that is defined in the default interface scope. */
		const int32_t get_mOTEUR_ROUE_DROITE() const;
		
		/*! Gets the value of the variable 'MOTEUR_FUNNY' that is defined in the default interface scope. */
		const int32_t get_mOTEUR_FUNNY() const;
		
		/*! Gets the value of the variable 'MOTEUR_MOELDAR' that is defined in the default interface scope. */
		const int32_t get_mOTEUR_MOELDAR() const;
		
		/*! Gets the value of the variable 'CODEUR_NON_DEFINI' that is defined in the default interface scope. */
		const int32_t get_cODEUR_NON_DEFINI() const;
		
		/*! Gets the value of the variable 'CODEUR_CHARIOT' that is defined in the default interface scope. */
		const int32_t get_cODEUR_CHARIOT() const;
		
		/*! Gets the value of the variable 'CODEUR_ROUE_DROITE' that is defined in the default interface scope. */
		const int32_t get_cODEUR_ROUE_DROITE() const;
		
		/*! Gets the value of the variable 'CODEUR_ROUE_GAUCHE' that is defined in the default interface scope. */
		const int32_t get_cODEUR_ROUE_GAUCHE() const;
		
		/*! Gets the value of the variable 'ORANGE' that is defined in the default interface scope. */
		int32_t get_oRANGE() const;
		
		/*! Sets the value of the variable 'ORANGE' that is defined in the default interface scope. */
		void set_oRANGE(int32_t value);
		
		/*! Gets the value of the variable 'VERT' that is defined in the default interface scope. */
		int32_t get_vERT() const;
		
		/*! Sets the value of the variable 'VERT' that is defined in the default interface scope. */
		void set_vERT(int32_t value);
		
		/*! Gets the value of the variable 'BLEU' that is defined in the default interface scope. */
		int32_t get_bLEU() const;
		
		/*! Sets the value of the variable 'BLEU' that is defined in the default interface scope. */
		void set_bLEU(int32_t value);
		
		/*! Gets the value of the variable 'JAUNE' that is defined in the default interface scope. */
		int32_t get_jAUNE() const;
		
		/*! Sets the value of the variable 'JAUNE' that is defined in the default interface scope. */
		void set_jAUNE(int32_t value);
		
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
		static const sc_integer timeEventsCount = 2;
		
		//! number of time events that can be active at once.
		static const sc_integer parallelTimeEventsCount = 1;
	protected:
		IA(const IA &rhs);
		IA& operator=(const IA&);
		
		//! Inner class for internal interface scope.
		class InternalSCI
		{
			
			public:
				/*! Gets the value of the variable 'Couleur' that is defined in the internal scope. */
				int32_t get_couleur() const;
				
				/*! Sets the value of the variable 'Couleur' that is defined in the internal scope. */
				void set_couleur(int32_t value);
				
				/*! Gets the value of the variable 'invMouv' that is defined in the internal scope. */
				int32_t get_invMouv() const;
				
				/*! Sets the value of the variable 'invMouv' that is defined in the internal scope. */
				void set_invMouv(int32_t value);
				
				/*! Gets the value of the variable 'Te' that is defined in the internal scope. */
				double get_te() const;
				
				/*! Sets the value of the variable 'Te' that is defined in the internal scope. */
				void set_te(double value);
				
				/*! Gets the value of the variable 'PI' that is defined in the internal scope. */
				double get_pI() const;
				
				/*! Sets the value of the variable 'PI' that is defined in the internal scope. */
				void set_pI(double value);
				
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
				
				
			protected:
				friend class IA;
				int32_t Couleur;
				int32_t invMouv;
				double Te;
				double PI;
				sc_boolean inhibeObstacle;
				sc_boolean evitementEnCours;
				double evitementTempo;
				sc_boolean sequence1;
				sc_boolean sequence2;
				int32_t pos_fusee;
				int32_t nb_tentatives;
		};
		
		//! the maximum number of orthogonal states defines the dimension of the state configuration vector.
		static const sc_ushort maxOrthogonalStates = 1;
		
		TimerInterface* timer;
		sc_boolean timeEvents[timeEventsCount];
		
		IAStates stateConfVector[maxOrthogonalStates];
		
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
		
		void react_main_region_StateA();
		void react_main_region_StateB();
		void clearInEvents();
		void clearOutEvents();
		
	private:
};



#endif /* IA_H_ */
