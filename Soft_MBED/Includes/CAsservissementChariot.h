/*! \file CAsservissementChariot.h
	\brief Classe qui contient l'asservissement vitesse/position du chariot du kmar
*/

#ifndef _ASSERVISSEMENT_CHARIOT_H_
#define _ASSERVISSEMENT_CHARIOT_H_


//etat_recalage_butee=0; 		// 0 non fait, 1 en cours, 2 fait et OK, 3 Raté(timeout)
#define NON_FAIT 0
#define EN_COURS 1
#define FAIT 2
#define ECHEC 3
//etat_asser_chariot=0; //0 stopped, 1 deplacement, 2 converge
#define STOP 0
#define DEPLACEMENT 1
#define CONVERGE 2
 

// -----------------------------
//! Classe de gestion des options d'exécution passees en ligne de commande
class CAsservissementChariot {
public :
 
	//! Constructeur / destructeur
	CAsservissementChariot();
	~CAsservissementChariot();

	//! Réinitialise tous les paramètres et valeurs
	void Init(void);
	
	void Asser_chariot(void);
	void Regul_chariot(void); // Régulateutr de vitesse PI
	
	void Stop_Chariot(void);
	void Recal_Chariot(void);
	
	void setConsigne(int pos);
	void setCommandeMax(float calib);
	void setGainPosVit(float calib);
	void setGainP(float calib);
	void setGainI(float calib);
	void setSeuilConv(float calib);
	
	//Input
	int codeur_position_chariot;		// Registre du codeur en Pas
	int position_consigne;				// Consigne en Pas pour le moment
	char demande_recalage_butee;
	char demande_stop_chariot;
	

	//Output
	float commande_moteur_chariot;
	char etat_recalage_butee; 			//0 non fait, 1 en cours, 2 fait et OK, 3 Raté(timeout)
	char etat_asser_chariot; 			//0 stopped, 1 deplacement, 2 converge

	// Calibrations
	float pas_C;						//nb de pas codeur par cm
	char apprentissage_auto_C;			// Si l'apprentissage n'est pas fait, il se réalise sans demande externe
	float compensation_zone_morte_C;	// A quantifier
    float compensation_zone_morte_dw_C;
    float compensation_zone_morte_up_C;
	float vitesse_consigne_recalage_C; 	// Pas par seconde

	float seuil_min_blocage_C;			// vitesse de détection blocage
	float seuil_tempo_conf_C;			// Nb de Te pour confirmer la mise en butée
	float seuil_tempo_time_out_C;		// Nb de Te pour

	float gain_position_vitesse_C;		// Carto à faire
	float commande_chariot_max_C;		// Saturation pour la sécurité ou limiter
	float gain_int_C;					//Gain integrateur du PI
	float gain_prop_C;					//Gain proportionnel du PI
	float seuil_conv_C;					//seuil de convergence
    float offset_vitesse_max_C;         // gradient de consigne de vitesse / Te


private : 
// Variables internes
int butee_basse;
int butee_haute;

float erreur_position;
float erreur_vitesse;
float vitesse_consigne;
//float erreur_vitesse;
int	tempo_conf;
int tempo_time_out;
int codeur_position_chariot_prev;
char saturation;
float terme_integral_prev;
float vitesse_chariot;
char demande_stop_chariot_prev;
int position_consigne_prev;
 float vitesse_consigne_filt;




};


#endif



