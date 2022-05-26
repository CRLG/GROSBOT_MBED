/*! \file CAsservissement.cpp
	\brief Classe qui contient toute l'application
*/

#include "CAsservissement.h"
#include "CGlobale.h"

// Constantes spécifiques au robot
const float CAsservissementBase::DISTANCE_PAR_PAS_CODEUR_G = 0.00330905f;
const float CAsservissementBase::DISTANCE_PAR_PAS_CODEUR_D = 0.00330905f;
const float CAsservissementBase::VOIE_ROBOT = 31.6867261f;

// Cartos spécifique au robo
const float CAsservissementBase::ini_conv_erreur_dist_vitesse_cur_x[NBRE_POINTS_CARTO_ERREUR] = {-40, -20, -10, -4, -2, -1, 0, 1, 2, 4, 10, 20, 40};							// [cm]
const float CAsservissementBase::ini_conv_erreur_dist_vitesse_1_cur[NBRE_POINTS_CARTO_ERREUR] = {-50, -35, -20, -8, -2, -1, 0, 1, 2, 8, 20, 35, 50};						// [cm/s] Carto perfo 0% environ 30cm/s2
const float CAsservissementBase::ini_conv_erreur_dist_vitesse_2_cur[NBRE_POINTS_CARTO_ERREUR] = {-130, -100, -50, -16, -4, -2, 0, 2, 4, 16, 50, 100, 130};

const float CAsservissementBase::ini_conv_erreur_angle_vitesse_cur_x[NBRE_POINTS_CARTO_ERREUR] = {-1.6, -0.8, -0.4, -0.2, -0.1, -0.05, 0, 0.05, 0.1, 0.2, 0.4, 0.8, 1.6};	// [rad]
const float CAsservissementBase::ini_conv_erreur_angle_vitesse_1_cur[NBRE_POINTS_CARTO_ERREUR] = {-4, -2.8, -2, -1.4, -1, -0.5, 0, 0.5, 1, 1.4, 2, 2.8, 4};					// [rad/s] Carto perfo 0% environ 5rad/s2
const float CAsservissementBase::ini_conv_erreur_angle_vitesse_2_cur[NBRE_POINTS_CARTO_ERREUR] = {-8, -5.65, -4, -2.82, -2, -0.5, 0, 0.5, 2, 2.82, 4, 5.65, 8};				// [rad/s] Carto perfo 100% environ 20rad/s2


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
void CAsservissement::Init(void)
{
 int i;
 
 CAsservissementBase::Init();

 // initialisation des paramètres de l'asservissement
 cde_max = 100;				// %	Commande maximum normalisée pour saturer la régulation
 cde_min = -100 ;			// %	Commande minimum normalisée pour saturer la régulation
 kp_distance =  1.2;//1.7;		// 		Gain proportionnel pour la régulation en distance
 ki_distance =  1.0;//3.0;		// 		Gain intégral pour la régulation en distance
 kp_angle =  7.0;			// 		Gain proportionnel pour la régulation en angle
 ki_angle =  5.0;			// 		Gain intégral pour la régulation en angle
 k_angle = 0.5;				//		Coeff de filtrage pour le terme dérivé
 seuil_conv_distance =  0.5;	// cm	Erreur en dessous de laquelle on considère que le robot est en position sur la distance
 seuil_conv_angle =  0.01;	// rad	Erreur en dessous de laquelle on considère que le robot est en position sur l'angle
 compteur_max = 3;			// 		Nombre de coups d'horloge (N*te) avant de confirmer que le robot est en position

 // Initialisation des zones mortes
 zone_morte_D = 0;
 zone_morte_G = 0;

 cde_offset_min_D = zone_morte_D;
 cde_offset_min_G = zone_morte_G;
 correction_ubatt = 1;
 //m_tension_batterie; // Externe
 ubatt_nominale=15.5;
 m_tension_batterie_filt = 1.44;
 m_tension_batterie_filt_prec = 14.4;
 k_batt = 0.9;							// Coeff de filtrage de la tension batterie (1 = pas de filtrage)
 k_filt_avance = 0.7;					// Coeff de filtrage de la vitesse d'avance (1 = pas de filtrage)
 k_filt_rotation = 0.8;					// Coeff de filtrage de la vitesse de rotation (1 = pas de filtrage)
 seuil_vitesse_diag_blocage = 2;		// cm/s
 commande_min_diag_blocage = 38;		// En cas de blocage l'égrateur charge rapidement à des valeurs importantes
 seuil_vitesse_diag_rotation = 0.1;	// rad/s
 seuil_max_compteur_diag_blocage = 500;	// k * te = g secondes
 inc_diag_blocage = 1;
 dec_diag_blocage = 2;

 vitesse_avance_max = 80;				//	[cm/s]
 vitesse_rotation_max = 3;				//	[rad/s]
 Ind_perfo = 0.5;

 // Initialisation des valeurs par défauts des tableaux
 for (i=0; i<NBRE_POINTS_CARTO_ERREUR; i++) {
	 conv_erreur_dist_vitesse_cur_x[i] = ini_conv_erreur_dist_vitesse_cur_x[i];
	 conv_erreur_dist_vitesse_1_cur[i] = ini_conv_erreur_dist_vitesse_1_cur[i];
	 conv_erreur_dist_vitesse_2_cur[i] = ini_conv_erreur_dist_vitesse_2_cur[i];
	 
	 conv_erreur_angle_vitesse_cur_x[i] = ini_conv_erreur_angle_vitesse_cur_x[i];
	 conv_erreur_angle_vitesse_1_cur[i] = ini_conv_erreur_angle_vitesse_1_cur[i];
	 conv_erreur_angle_vitesse_2_cur[i] = ini_conv_erreur_angle_vitesse_2_cur[i];
 }


 // Initialise les positions des codeurs
 Application.m_roues.resetCodeurs();
}

