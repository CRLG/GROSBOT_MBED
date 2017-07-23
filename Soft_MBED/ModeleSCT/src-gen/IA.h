
#ifndef IA_H_
#define IA_H_

#include "sc_types.h"
#include "StatemachineInterface.h"

/*! \file Header of the state machine 'IA'.
*/

class IA : public StatemachineInterface
{
	
	public:
		
		IA();
		
		~IA();
		
		/*! Enumeration of all states */ 
		typedef enum
		{
			STRATEGIE_ATTENTE_DEBUT_MATCH,
			STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1,
			STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2,
			STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_U065064,
			STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_Copy_1_POSITION_ASCENSEUR_INIT,
			STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_Copy_1_INIT,
			STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_INIT,
			STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_01,
			STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_02,
			STRATEGIE_MATCH,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU,
			STRATEGIE_MATCH_MATCH_REGION_EVITEMENT,
			STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT,
			STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT,
			STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_,
			STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE,
			STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE,
			STRATEGIE_FIN_MATCH,
			STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS,
			STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_FIN_FUNNY,
			STRATEGIE_FIN_MATCH_FIN_MATCH_REGION__final_,
			STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR,
			STRATEGIE_TEMPS_INIT,
			IA_last_state
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
				
				/*! Gets the value of the variable 'IN_Depression' that is defined in the default interface scope. */
				sc_boolean get_iN_Depression();
				
				/*! Sets the value of the variable 'IN_Depression' that is defined in the default interface scope. */
				void set_iN_Depression(sc_boolean value);
				
				/*! Gets the value of the variable 'countTimeMvt' that is defined in the default interface scope. */
				sc_real get_countTimeMvt();
				
				/*! Sets the value of the variable 'countTimeMvt' that is defined in the default interface scope. */
				void set_countTimeMvt(sc_real value);
				
				/*! Gets the value of the variable 'tempsMatch' that is defined in the default interface scope. */
				sc_integer get_tempsMatch();
				
				/*! Sets the value of the variable 'tempsMatch' that is defined in the default interface scope. */
				void set_tempsMatch(sc_integer value);
				
				/*! Gets the value of the variable 'countTempo' that is defined in the default interface scope. */
				sc_integer get_countTempo();
				
				/*! Sets the value of the variable 'countTempo' that is defined in the default interface scope. */
				void set_countTempo(sc_integer value);
				
				/*! Gets the value of the variable 'countTempo2' that is defined in the default interface scope. */
				sc_integer get_countTempo2();
				
				/*! Sets the value of the variable 'countTempo2' that is defined in the default interface scope. */
				void set_countTempo2(sc_integer value);
				
				/*! Gets the value of the variable 'countTime' that is defined in the default interface scope. */
				sc_real get_countTime();
				
				/*! Sets the value of the variable 'countTime' that is defined in the default interface scope. */
				void set_countTime(sc_real value);
				
				/*! Gets the value of the variable 'x_pos_mem' that is defined in the default interface scope. */
				sc_real get_x_pos_mem();
				
				/*! Sets the value of the variable 'x_pos_mem' that is defined in the default interface scope. */
				void set_x_pos_mem(sc_real value);
				
				/*! Gets the value of the variable 'y_pos_mem' that is defined in the default interface scope. */
				sc_real get_y_pos_mem();
				
				/*! Sets the value of the variable 'y_pos_mem' that is defined in the default interface scope. */
				void set_y_pos_mem(sc_real value);
				
				/*! Gets the value of the variable 'teta_pos_mem' that is defined in the default interface scope. */
				sc_real get_teta_pos_mem();
				
				/*! Sets the value of the variable 'teta_pos_mem' that is defined in the default interface scope. */
				void set_teta_pos_mem(sc_real value);
				
				/*! Gets the value of the variable 'nb_Modules' that is defined in the default interface scope. */
				sc_integer get_nb_Modules();
				
				/*! Sets the value of the variable 'nb_Modules' that is defined in the default interface scope. */
				void set_nb_Modules(sc_integer value);
				
				/*! Gets the value of the variable 'SERVO_VENTOUSE' that is defined in the default interface scope. */
				const sc_integer get_sERVO_VENTOUSE();
				
				/*! Gets the value of the variable 'SERVO_CENTREUR_G' that is defined in the default interface scope. */
				const sc_integer get_sERVO_CENTREUR_G();
				
				/*! Gets the value of the variable 'SERVO_CENTREUR_D' that is defined in the default interface scope. */
				const sc_integer get_sERVO_CENTREUR_D();
				
				/*! Gets the value of the variable 'SERVO_PINCE_D' that is defined in the default interface scope. */
				const sc_integer get_sERVO_PINCE_D();
				
				/*! Gets the value of the variable 'SERVO_PINCE_G' that is defined in the default interface scope. */
				const sc_integer get_sERVO_PINCE_G();
				
				/*! Gets the value of the variable 'SERVO_BALLE' that is defined in the default interface scope. */
				const sc_integer get_sERVO_BALLE();
				
				/*! Gets the value of the variable 'SERVO_RECOLTEURS' that is defined in the default interface scope. */
				const sc_integer get_sERVO_RECOLTEURS();
				
				/*! Gets the value of the variable 'SERVO_VOLET' that is defined in the default interface scope. */
				const sc_integer get_sERVO_VOLET();
				
				/*! Gets the value of the variable 'AX_ROTATION' that is defined in the default interface scope. */
				const sc_integer get_aX_ROTATION();
				
				/*! Gets the value of the variable 'AX_COULEUR' that is defined in the default interface scope. */
				const sc_integer get_aX_COULEUR();
				
				/*! Gets the value of the variable 'AX_LEVIER' that is defined in the default interface scope. */
				const sc_integer get_aX_LEVIER();
				
				/*! Gets the value of the variable 'KMAR_SORTI' that is defined in the default interface scope. */
				const sc_integer get_kMAR_SORTI();
				
				/*! Gets the value of the variable 'KMAR_RENTRE' that is defined in the default interface scope. */
				const sc_integer get_kMAR_RENTRE();
				
				/*! Gets the value of the variable 'KMAR_PRENDRE' that is defined in the default interface scope. */
				const sc_integer get_kMAR_PRENDRE();
				
				/*! Gets the value of the variable 'VENTOUSE_G' that is defined in the default interface scope. */
				const sc_integer get_vENTOUSE_G();
				
				/*! Gets the value of the variable 'VENTOUSE_D' that is defined in the default interface scope. */
				const sc_integer get_vENTOUSE_D();
				
				/*! Gets the value of the variable 'KMAR_DROIT' that is defined in the default interface scope. */
				const sc_integer get_kMAR_DROIT();
				
				/*! Gets the value of the variable 'MOTEUR_ROUE_GAUCHE' that is defined in the default interface scope. */
				const sc_integer get_mOTEUR_ROUE_GAUCHE();
				
				/*! Gets the value of the variable 'MOTEUR_ROUE_DROITE' that is defined in the default interface scope. */
				const sc_integer get_mOTEUR_ROUE_DROITE();
				
				/*! Gets the value of the variable 'MOTEUR_FUNNY' that is defined in the default interface scope. */
				const sc_integer get_mOTEUR_FUNNY();
				
				/*! Gets the value of the variable 'MOTEUR_MOELDAR' that is defined in the default interface scope. */
				const sc_integer get_mOTEUR_MOELDAR();
				
				/*! Gets the value of the variable 'CODEUR_NON_DEFINI' that is defined in the default interface scope. */
				const sc_integer get_cODEUR_NON_DEFINI();
				
				/*! Gets the value of the variable 'CODEUR_CHARIOT' that is defined in the default interface scope. */
				const sc_integer get_cODEUR_CHARIOT();
				
				/*! Gets the value of the variable 'CODEUR_ROUE_DROITE' that is defined in the default interface scope. */
				const sc_integer get_cODEUR_ROUE_DROITE();
				
				/*! Gets the value of the variable 'CODEUR_ROUE_GAUCHE' that is defined in the default interface scope. */
				const sc_integer get_cODEUR_ROUE_GAUCHE();
				
				/*! Gets the value of the variable 'JAUNE' that is defined in the default interface scope. */
				sc_integer get_jAUNE();
				
				/*! Gets the value of the variable 'BLEU' that is defined in the default interface scope. */
				sc_integer get_bLEU();
				
				
			protected:
				friend class IA;
				sc_boolean EV_Tirette_raised;
				sc_boolean EV_Obstacle_raised;
				sc_boolean EV_ConvergenceMvt_raised;
				sc_boolean EV_ConvergenceMvt_Rapide_raised;
				sc_boolean EV_ConvergenceChariot_raised;
				sc_real IN_x_pos;
				sc_real IN_y_pos;
				sc_real IN_teta_pos;
				sc_real IN_vitesse;
				sc_real IN_sens_deplacement;
				sc_integer IN_Couleur;
				sc_integer IN_Obstacle;
				sc_boolean IN_Depression;
				sc_real countTimeMvt;
				sc_integer tempsMatch;
				sc_integer countTempo;
				sc_integer countTempo2;
				sc_real countTime;
				sc_real x_pos_mem;
				sc_real y_pos_mem;
				sc_real teta_pos_mem;
				sc_integer nb_Modules;
				static const sc_integer SERVO_VENTOUSE;
				static const sc_integer SERVO_CENTREUR_G;
				static const sc_integer SERVO_CENTREUR_D;
				static const sc_integer SERVO_PINCE_D;
				static const sc_integer SERVO_PINCE_G;
				static const sc_integer SERVO_BALLE;
				static const sc_integer SERVO_RECOLTEURS;
				static const sc_integer SERVO_VOLET;
				static const sc_integer AX_ROTATION;
				static const sc_integer AX_COULEUR;
				static const sc_integer AX_LEVIER;
				static const sc_integer KMAR_SORTI;
				static const sc_integer KMAR_RENTRE;
				static const sc_integer KMAR_PRENDRE;
				static const sc_integer VENTOUSE_G;
				static const sc_integer VENTOUSE_D;
				static const sc_integer KMAR_DROIT;
				static const sc_integer MOTEUR_ROUE_GAUCHE;
				static const sc_integer MOTEUR_ROUE_DROITE;
				static const sc_integer MOTEUR_FUNNY;
				static const sc_integer MOTEUR_MOELDAR;
				static const sc_integer CODEUR_NON_DEFINI;
				static const sc_integer CODEUR_CHARIOT;
				static const sc_integer CODEUR_ROUE_DROITE;
				static const sc_integer CODEUR_ROUE_GAUCHE;
				sc_integer JAUNE;
				sc_integer BLEU;
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
		
		/*! Gets the value of the variable 'IN_Depression' that is defined in the default interface scope. */
		sc_boolean get_iN_Depression();
		
		/*! Sets the value of the variable 'IN_Depression' that is defined in the default interface scope. */
		void set_iN_Depression(sc_boolean value);
		
		/*! Gets the value of the variable 'countTimeMvt' that is defined in the default interface scope. */
		sc_real get_countTimeMvt();
		
		/*! Sets the value of the variable 'countTimeMvt' that is defined in the default interface scope. */
		void set_countTimeMvt(sc_real value);
		
		/*! Gets the value of the variable 'tempsMatch' that is defined in the default interface scope. */
		sc_integer get_tempsMatch();
		
		/*! Sets the value of the variable 'tempsMatch' that is defined in the default interface scope. */
		void set_tempsMatch(sc_integer value);
		
		/*! Gets the value of the variable 'countTempo' that is defined in the default interface scope. */
		sc_integer get_countTempo();
		
		/*! Sets the value of the variable 'countTempo' that is defined in the default interface scope. */
		void set_countTempo(sc_integer value);
		
		/*! Gets the value of the variable 'countTempo2' that is defined in the default interface scope. */
		sc_integer get_countTempo2();
		
		/*! Sets the value of the variable 'countTempo2' that is defined in the default interface scope. */
		void set_countTempo2(sc_integer value);
		
		/*! Gets the value of the variable 'countTime' that is defined in the default interface scope. */
		sc_real get_countTime();
		
		/*! Sets the value of the variable 'countTime' that is defined in the default interface scope. */
		void set_countTime(sc_real value);
		
		/*! Gets the value of the variable 'x_pos_mem' that is defined in the default interface scope. */
		sc_real get_x_pos_mem();
		
		/*! Sets the value of the variable 'x_pos_mem' that is defined in the default interface scope. */
		void set_x_pos_mem(sc_real value);
		
		/*! Gets the value of the variable 'y_pos_mem' that is defined in the default interface scope. */
		sc_real get_y_pos_mem();
		
		/*! Sets the value of the variable 'y_pos_mem' that is defined in the default interface scope. */
		void set_y_pos_mem(sc_real value);
		
		/*! Gets the value of the variable 'teta_pos_mem' that is defined in the default interface scope. */
		sc_real get_teta_pos_mem();
		
		/*! Sets the value of the variable 'teta_pos_mem' that is defined in the default interface scope. */
		void set_teta_pos_mem(sc_real value);
		
		/*! Gets the value of the variable 'nb_Modules' that is defined in the default interface scope. */
		sc_integer get_nb_Modules();
		
		/*! Sets the value of the variable 'nb_Modules' that is defined in the default interface scope. */
		void set_nb_Modules(sc_integer value);
		
		/*! Gets the value of the variable 'SERVO_VENTOUSE' that is defined in the default interface scope. */
		const sc_integer get_sERVO_VENTOUSE();
		
		/*! Gets the value of the variable 'SERVO_CENTREUR_G' that is defined in the default interface scope. */
		const sc_integer get_sERVO_CENTREUR_G();
		
		/*! Gets the value of the variable 'SERVO_CENTREUR_D' that is defined in the default interface scope. */
		const sc_integer get_sERVO_CENTREUR_D();
		
		/*! Gets the value of the variable 'SERVO_PINCE_D' that is defined in the default interface scope. */
		const sc_integer get_sERVO_PINCE_D();
		
		/*! Gets the value of the variable 'SERVO_PINCE_G' that is defined in the default interface scope. */
		const sc_integer get_sERVO_PINCE_G();
		
		/*! Gets the value of the variable 'SERVO_BALLE' that is defined in the default interface scope. */
		const sc_integer get_sERVO_BALLE();
		
		/*! Gets the value of the variable 'SERVO_RECOLTEURS' that is defined in the default interface scope. */
		const sc_integer get_sERVO_RECOLTEURS();
		
		/*! Gets the value of the variable 'SERVO_VOLET' that is defined in the default interface scope. */
		const sc_integer get_sERVO_VOLET();
		
		/*! Gets the value of the variable 'AX_ROTATION' that is defined in the default interface scope. */
		const sc_integer get_aX_ROTATION();
		
		/*! Gets the value of the variable 'AX_COULEUR' that is defined in the default interface scope. */
		const sc_integer get_aX_COULEUR();
		
		/*! Gets the value of the variable 'AX_LEVIER' that is defined in the default interface scope. */
		const sc_integer get_aX_LEVIER();
		
		/*! Gets the value of the variable 'KMAR_SORTI' that is defined in the default interface scope. */
		const sc_integer get_kMAR_SORTI();
		
		/*! Gets the value of the variable 'KMAR_RENTRE' that is defined in the default interface scope. */
		const sc_integer get_kMAR_RENTRE();
		
		/*! Gets the value of the variable 'KMAR_PRENDRE' that is defined in the default interface scope. */
		const sc_integer get_kMAR_PRENDRE();
		
		/*! Gets the value of the variable 'VENTOUSE_G' that is defined in the default interface scope. */
		const sc_integer get_vENTOUSE_G();
		
		/*! Gets the value of the variable 'VENTOUSE_D' that is defined in the default interface scope. */
		const sc_integer get_vENTOUSE_D();
		
		/*! Gets the value of the variable 'KMAR_DROIT' that is defined in the default interface scope. */
		const sc_integer get_kMAR_DROIT();
		
		/*! Gets the value of the variable 'MOTEUR_ROUE_GAUCHE' that is defined in the default interface scope. */
		const sc_integer get_mOTEUR_ROUE_GAUCHE();
		
		/*! Gets the value of the variable 'MOTEUR_ROUE_DROITE' that is defined in the default interface scope. */
		const sc_integer get_mOTEUR_ROUE_DROITE();
		
		/*! Gets the value of the variable 'MOTEUR_FUNNY' that is defined in the default interface scope. */
		const sc_integer get_mOTEUR_FUNNY();
		
		/*! Gets the value of the variable 'MOTEUR_MOELDAR' that is defined in the default interface scope. */
		const sc_integer get_mOTEUR_MOELDAR();
		
		/*! Gets the value of the variable 'CODEUR_NON_DEFINI' that is defined in the default interface scope. */
		const sc_integer get_cODEUR_NON_DEFINI();
		
		/*! Gets the value of the variable 'CODEUR_CHARIOT' that is defined in the default interface scope. */
		const sc_integer get_cODEUR_CHARIOT();
		
		/*! Gets the value of the variable 'CODEUR_ROUE_DROITE' that is defined in the default interface scope. */
		const sc_integer get_cODEUR_ROUE_DROITE();
		
		/*! Gets the value of the variable 'CODEUR_ROUE_GAUCHE' that is defined in the default interface scope. */
		const sc_integer get_cODEUR_ROUE_GAUCHE();
		
		/*! Gets the value of the variable 'JAUNE' that is defined in the default interface scope. */
		sc_integer get_jAUNE();
		
		/*! Gets the value of the variable 'BLEU' that is defined in the default interface scope. */
		sc_integer get_bLEU();
		
		
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
						static void XY(sc_real x, sc_real y);
						
						static void XYTeta(sc_real x, sc_real y, sc_real teta);
						
						static void Manuel(sc_real mot_gauche, sc_real mot_droit);
						
						static void DistanceAngle(sc_real distance, sc_real angle);
						
						static void Vitesse(sc_real speedDist, sc_real speedRot);
						
						static void setPosition(sc_real x, sc_real y, sc_real teta);
						
						static void setSportivite(sc_real idx);
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
						static void setPos(sc_integer idServo, sc_integer value);
						
						static void setPosSpd(sc_integer idServo, sc_integer pos, sc_integer spd);
						
						static void setRelache(sc_integer idServo, sc_real time_ms);
				};
		
		/*! Returns an instance of the interface class 'SCI_Servo'. */
		SCI_Servo* getSCI_Servo();
		
		//! Inner class for ax interface scope.
		class SCI_Ax
		{
			
			public:
				/*! Gets the value of the variable 'BRAS_OUVERT' that is defined in the interface scope 'ax'. */
				sc_integer get_bRAS_OUVERT();
				
				
			protected:
				friend class IA;
				sc_integer BRAS_OUVERT;
		};
				
				//! Inner class for ax interface scope operation callbacks.
				class SCI_Ax_OCB
				{
					public:
						static void setPos(sc_integer idServo, sc_integer value);
						
						static void setPosSpd(sc_integer idServo, sc_integer pos, sc_integer spd);
						
						static void setSpd(sc_integer idServo, sc_integer spd);
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
						static void setPWM(sc_integer idMot, sc_real pwm);
				};
		
		/*! Returns an instance of the interface class 'SCI_Moteur'. */
		SCI_Moteur* getSCI_Moteur();
		
		//! Inner class for chariot interface scope.
		class SCI_Chariot
		{
			
			public:
				/*! Gets the value of the variable 'isReady' that is defined in the interface scope 'chariot'. */
				sc_boolean get_isReady();
				
				/*! Sets the value of the variable 'isReady' that is defined in the interface scope 'chariot'. */
				void set_isReady(sc_boolean value);
				
				/*! Gets the value of the variable 'isConv' that is defined in the interface scope 'chariot'. */
				sc_boolean get_isConv();
				
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
						
						static void setPos(sc_integer position);
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
						static void resetCodeur(sc_integer idCodeur, sc_integer value);
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
						static void setLed(sc_integer idLed, sc_boolean onoff);
				};
		
		/*! Returns an instance of the interface class 'SCI_Ihm'. */
		SCI_Ihm* getSCI_Ihm();
		
		
		void init();
		
		void enter();
		
		void exit();
		
		void runCycle();
		
		/*!
		* Checks if the state machine is active (until 2.4.1 this method was used for states).
		* A state machine is active if it has been entered. It is inactive if it has not been entered at all or if it has been exited.
		*/
		sc_boolean isActive();
		
		
		/*!
		* Checks if all active states are final. 
		* If there are no active states then the state machine is considered being inactive. In this case this method returns false.
		*/
		sc_boolean isFinal();
		
		
		/*! Checks if the specified state is active (until 2.4.1 the used method for states was calles isActive()). */
		sc_boolean isStateActive(IAStates state);
	
	protected:
	
		//! Inner class for internal interface scope.
		class InternalSCI
		{
			
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
				
				/*! Gets the value of the variable 'sequence1' that is defined in the internal scope. */
				sc_boolean get_sequence1();
				
				/*! Sets the value of the variable 'sequence1' that is defined in the internal scope. */
				void set_sequence1(sc_boolean value);
				
				/*! Gets the value of the variable 'sequence2' that is defined in the internal scope. */
				sc_boolean get_sequence2();
				
				/*! Sets the value of the variable 'sequence2' that is defined in the internal scope. */
				void set_sequence2(sc_boolean value);
				
				/*! Gets the value of the variable 'pos_fusee' that is defined in the internal scope. */
				sc_integer get_pos_fusee();
				
				/*! Sets the value of the variable 'pos_fusee' that is defined in the internal scope. */
				void set_pos_fusee(sc_integer value);
				
				/*! Gets the value of the variable 'nb_tentatives' that is defined in the internal scope. */
				sc_integer get_nb_tentatives();
				
				/*! Sets the value of the variable 'nb_tentatives' that is defined in the internal scope. */
				void set_nb_tentatives(sc_integer value);
				
				
			protected:
				friend class IA;
				sc_integer Couleur;
				sc_integer invMouv;
				sc_real Te;
				sc_real PI;
				sc_boolean inhibeObstacle;
				sc_boolean evitementEnCours;
				sc_real evitementTempo;
				sc_boolean sequence1;
				sc_boolean sequence2;
				sc_integer pos_fusee;
				sc_integer nb_tentatives;
		};
	
		//! the maximum number of orthogonal states defines the dimension of the state configuration vector.
		static const sc_integer maxOrthogonalStates = 3;
		//! dimension of the state configuration vector for history states
		static const sc_integer maxHistoryStates = 2;
		
		
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
		
		void shenseq_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION();
		void shenseq_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE();
		void react_STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1();
		void react_STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2();
		void react_STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_U065064();
		void react_STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_Copy_1_POSITION_ASCENSEUR_INIT();
		void react_STRATEGIE_ATTENTE_DEBUT_MATCH_APPRENTISSAGE_ACTIONNEUR_Copy_1_INIT();
		void react_STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_INIT();
		void react_STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_01();
		void react_STRATEGIE_ATTENTE_DEBUT_MATCH_CHENILLARD_CHENILLARD_02();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DEPOSE_MODULE();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_LARGAGE_MODULES();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__final_();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_POSITION_INIT();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_DIRECTION_ZONE_ADVERSE();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_PRISE_MODULE_01();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_JAUNE();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION_FIN_DEPLACEMENT_BLEU();
		void react_STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT();
		void react_STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT();
		void react_STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION__final_();
		void react_STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_KMAR();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FACE_FUSEE();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_INCERTAIN();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ATTENTE_VENTOUSAGE();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RETIRE_MODULE();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEGAGE_MODULE();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_BORDURE();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_ROTATION();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_SOULEVE_MODULE();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHOISI_COULEUR();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_COULEUR();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RALENTI_AX_COULEUR();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_TOURNE_POUR_FUSEE();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_PROCHE_ZONE();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_AU_DESSUS_ZONE();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DEVENTOUSAGE();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_ROTATION();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_ACCELERE_AX_LEVIER();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_AX_LEVIER();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__final_();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_MAX_HORS_ZONE();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_DECALE_MODULES();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_INIT_CHARIOT_COTE();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RECENTRAGE_BRAS();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_FIN_INIT_CHARIOT_COTE();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_02();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_CHOISI_COULEUR();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_LEVIER_RECULE_AU_MAX();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_CHERCHE_FUSEE();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_LEVIER_RECULE_AU_MAX();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_VENTOUSAGE_CERTAIN();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_RANGE_BRAS_01();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_TOURNE_POUR_FUSEE();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE_Copy_1_AU_DESSUS_ZONE();
		void react_STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS();
		void react_STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_FIN_FUNNY();
		void react_STRATEGIE_FIN_MATCH_FIN_MATCH_REGION__final_();
		void react_STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_MOELDAR();
		void react_STRATEGIE_TEMPS_INIT();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_LUNAIRES_COTE_HOMOLOGATION_REGION__choice_0();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_0();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_1();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_2();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_3();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_4();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_5();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_6();
		void react_STRATEGIE_MATCH_MATCH_REGION_MODULES_COTE_JAUNE_SEQUENCE_MODULES_FUSEE__choice_7();
		void react_STRATEGIE_MATCH_MATCH_REGION__choice_0();
		void clearInEvents();
		void clearOutEvents();
		
};
#endif /* IA_H_ */
