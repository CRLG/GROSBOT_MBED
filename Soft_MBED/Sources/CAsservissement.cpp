/*! \file CAsservissement.cpp
	\brief Classe qui contient toute l'application
*/
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

#include "CAsservissement.h"
#include "CGlobale.h"

//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CAsservissement::CAsservissement() 
{
  Init();
}

//___________________________________________________________________________
 /*!
   \brief Initialisation

   \param --
   \return --
*/
// Constantes spécifique au robot
const float CAsservissementBase::DISTANCE_PAR_PAS_CODEUR_G = 0.00325568f;  // valeur par défaut reprise de GROSBOT
const float CAsservissementBase::DISTANCE_PAR_PAS_CODEUR_D = 0.00325568f;
const float CAsservissementBase::VOIE_ROBOT = 31.6867261f;
void CAsservissement::Init(void)
{
 int i;
 
 // initialisation des paramètres de l'asservissement
 cde_max = 100;				// %	Commande maximum normalisée pour saturer la régulation
 cde_min = -100 ;			// %	Commande minimum normalisée pour saturer la régulation
 kp_distance =  1.6;//1.7;		// 		Gain proportionnel pour la régulation en distance
 ki_distance =  2.5;//3.0;		// 		Gain intégral pour la régulation en distance
 kp_angle =  20;			// 		Gain proportionnel pour la régulation en angle
 ki_angle =  10;			// 		Gain intégral pour la régulation en angle
 k_angle = 0.5;				//		Coeff de filtrage pour le terme dérivé
 seuil_conv_distance =  1;	// cm	Erreur en dessous de laquelle on considère que le robot est en position sur la distance
 seuil_conv_angle =  0.02;	// rad	Erreur en dessous de laquelle on considère que le robot est en position sur l'angle
 compteur_max = 3;			// 		Nombre de coups d'horloge (N*te) avant de confirmer que le robot est en position

 // Initialisation des zones mortes
 zone_morte_D = 12;
 zone_morte_G = 12;

 // Les variables de l'asservissement
 distance_consigne = 0;
 angle_consigne = 0;
 distance_roue_D = 0;
 distance_roue_G = 0;
 erreur_distance = 0;
 erreur_angle = 0;
 erreur_vitesse_avance = 0;
 erreur_vitesse_rotation = 0;
 int_terme_prec_distance = 0;
 int_terme_distance = 0;
 cde_distance_ulim = 0;
 cde_distance_recal = 0;
 cde_distance = 0;
 int_terme_prec_angle = 0;
 int_terme_angle = 0;
 cde_angle_ulim = 0;
 cde_angle = 0;
 cde_moteur_D = 0;
 cde_moteur_D_ulim = 0;
 cde_moteur_G = 0;
 cde_moteur_G_ulim = 0;
 angle_robot_prec = 0;
 distance_roue_D_prec = 0;
 distance_roue_G_prec = 0;
 X_robot_prec = 0;
 Y_robot_prec = 0;
 ddistance_roue_D = 0;
 ddistance_roue_G = 0;
 ddistance_robot = 0;
 distance_robot = 0;
 dangle_robot = 0;
 angle_robot = 0;
 dX_robot = 0;
 dY_robot = 0;
 X_robot = 0;
 X_consigne = 0;
 Y_robot = 0;
 X_erreur = 0;
 Y_erreur = 0;
 Y_consigne = 0;
 temp_cos_angle_robot = 0;
 temp_sin_angle_robot = 0;
 Xa = 0;
 Ya = 0;
 Xb = 0;
 Yb = 0;
 Offset_a = 0;
 Offset_b = 0;
 cde_offset_min_D = zone_morte_D;
 cde_offset_min_G = zone_morte_G;
 correction_ubatt = 1;
 //m_tension_batterie; // Externe
 ubatt_nominale=15.5;
 m_tension_batterie_filt = 1.44;
 m_tension_batterie_filt_prec = 14.4;
 k_batt = 0.9;							// Coeff de filtrage de la tension batterie (1 = pas de filtrage)
 vitesse_avance_robot = 0;
 vitesse_rotation_robot = 0;
 vitesse_avance_robot_filt_prec = 0;
 vitesse_avance_robot_filt = 0;
 k_filt_avance = 0.7;					// Coeff de filtrage de la vitesse d'avance (1 = pas de filtrage)
 vitesse_rotation_robot_filt_prec = 0;
 vitesse_rotation_robot_filt = 0;
 k_filt_rotation = 0.8;					// Coeff de filtrage de la vitesse de rotation (1 = pas de filtrage)
 consigne_vitesse_avance = 0;
 consigne_vitesse_rotation = 0;
 consigne_vitesse_avance_filt = 0;
 consigne_vitesse_avance_recal = 0;
 consigne_vitesse_rotation_cm = 0;
 consigne_vitesse_rotation_filt = 0;
 facteur_correction_avance_angle = 0;
 seuil_vitesse_diag_blocage = 2;		// cm/s
 commande_min_diag_blocage = 38;		// En cas de blocage l'égrateur charge rapidement à des valeurs importantes
 seuil_vitesse_diag_rotation = 0.1;	// rad/s
 seuil_max_compteur_diag_blocage = 500;	// k * te = g secondes
 inc_diag_blocage = 1;
 dec_diag_blocage = 2;
 compteur_diag_blocage = 0;
 diag_blocage = 0;
 convergence = 0;
 convergence_conf = 0;					// 0: Mvt en cours, 1: Convergence ok, 2: Blocage détecté
 saturation_distance = 0;
 saturation_angle = 0;
 saturation_moteur_D = 0;
 saturation_moteur_G = 0;
 verouillage_approche = 0;
 compteur_convergence = 0;
 ModeAsservissement = cMODE_MANUEL;
 TETA_consigne=0;
 convergence_rapide = 0;

 offset_vitesse_avance = 0;				//	[cm/s-2]
 offset_vitesse_rotation = 0;			//	[rad/s-2]
 vitesse_avance_max = 80;				//	[cm/s]
 vitesse_rotation_max = 3;				//	[rad/s]
 Ind_perfo = 0.7;

 // Initialisation des valeurs par défauts des tableaux
 for (i=0; i<NBRE_POINTS_CARTO_ERREUR; i++) {
	 conv_erreur_dist_vitesse_cur_x[i] = ini_conv_erreur_dist_vitesse_cur_x[i];
	 conv_erreur_dist_vitesse_1_cur[i] = ini_conv_erreur_dist_vitesse_1_cur[i];
	 conv_erreur_dist_vitesse_2_cur[i] = ini_conv_erreur_dist_vitesse_2_cur[i];
	 
	 conv_erreur_angle_vitesse_cur_x[i] = ini_conv_erreur_angle_vitesse_cur_x[i];
	 conv_erreur_angle_vitesse_1_cur[i] = ini_conv_erreur_angle_vitesse_1_cur[i];
	 conv_erreur_angle_vitesse_2_cur[i] = ini_conv_erreur_angle_vitesse_2_cur[i];
	 
	 //facteur_cor_vitesse_avance_cur_x[i] = ini_facteur_cor_vitesse_avance_cur_x[i];
	 //facteur_cor_vitesse_avance_cur[i] = ini_facteur_cor_vitesse_avance_cur[i];
 }


 // Initialise les positions des codeurs
 Application.m_roues.resetCodeurs();
}

