/*! \file CCapteurs.h
	\brief Classe qui contient la gestion des roues motrices gauche et droite
*/

#ifndef _CAPTEURS_H_
#define _CAPTEURS_H_

#include "CTelemetres.h"
#include "CdsPIC.h"

#define NBRE_ECH_FILTRAGE_CAPTEURS_US		5
#define SEUIL_CM_DETECTION_OBSTACLE			30	// [cm]
                                
#define TENSION_REF_EANA_MBED	3.3

#define SEUIL_TENSION_BATT_FAIBLE 14.0

#define COEF_TENSION_ANA_dsPIC  (0.075796875)

#define ADRESSE_I2C_COLOR_SENSOR 	0x52

typedef enum {
 CODEUR_1 = 0,
 CODEUR_2,
 CODEUR_3,
 CODEUR_4
}eCODEURS_POSITION;

// -----------------------------
//! Classe de gestion des options d'exécution passees en ligne de commande
class CCapteurs {
public :
	//! Indique si la valeur lue par le capteur
	float m_suiveurLigne_ARM;
	//! Indique si la valeur lue par le capteur
	float m_suiveurLigne_ARG;
	//! Indique si la valeur lue par le capteur
	float m_suiveurLigne_ARD;

	//! Indique si le detecteur de ligne milieu voit la ligne ou non
	unsigned char m_suiveurLigne01_ARM;
	float m_seuil_suiveurLigne_ARM;
	//! Indique si le detecteur de ligne gauche voit la ligne ou non
	unsigned char m_suiveurLigne01_ARG;
	float m_seuil_suiveurLigne_ARG;
	//! Indique si le detecteur de ligne droit voit la ligne ou non
	unsigned char m_suiveurLigne01_ARD;
	float m_seuil_suiveurLigne_ARD;

	//! Valeurs lues par le cpateur de couleur
	int m_color_sensor_R;
	int m_color_sensor_G;
	int m_color_sensor_B;
	bool m_color_sensor_OK;

	//! Valeur lue par le capteur ultrason avant
	float m_ultrason_AV;
	//! Tableau du filtrage  
	float m_tabFiltUS_AV[NBRE_ECH_FILTRAGE_CAPTEURS_US];
	//! Flag d'indication d'un obstacle détecté
	unsigned char m_obstacleDetecte_AV;


	//! Valeur lue par le capteur ultrason arriere
	float m_ultrason_AR;
	//! Tableau du filtrage  
	float m_tabFiltUS_AR[NBRE_ECH_FILTRAGE_CAPTEURS_US];
	//! Flag d'indication d'un obstacle détecté
	unsigned char  m_obstacleDetecte_AR;

	//! Flag de recallage AVD
	unsigned char m_recalage_AVD;
	//! Flag de recallage AVG
	unsigned char m_recalage_AVG;

	

	//! Ordre de départ
	unsigned char DepartMatch;

    // Valeurs brutes sur les entrées TOR ("_b" pour "brute")
	unsigned char m_b_Etor1;
	unsigned char m_b_Etor2;
	unsigned char m_b_Etor3;
	unsigned char m_b_Etor4;
	unsigned char m_b_Etor5;
	unsigned char m_b_Etor6;
	unsigned char m_b_Etor_CanRx;
	unsigned char m_b_Etor_CanTx;

    // Valeurs brutes sur les entrées analogiques
	float m_b_Mes_Vbat;
	float m_b_Eana1;
	float m_b_Eana2;
	float m_b_Eana3;
	float m_b_Eana4;
	float m_b_Eana5;
	float m_b_Eana6;
	float m_b_Eana7;
	float m_b_Eana8;
	float m_b_Eana9;
	float m_b_Eana10;
	float m_b_Eana11;
	float m_b_Eana12;
	float m_b_Eana13;

	// Les codeurs de position
	signed short m_CodeurPosition1;
	signed short m_CodeurPosition2;
	signed short m_CodeurPosition3;
	signed short m_CodeurPosition4;

	signed long m_CumulCodeurPosition1;
	signed long m_CumulCodeurPosition2;
	signed long m_CumulCodeurPosition3;
	signed long m_CumulCodeurPosition4;

	// Les télémètres
    CTelemetres m_telemetres;
	float m_TelemetreAVD;
	float m_TelemetreAVG;
	float m_TelemetreARD;
	float m_TelemetreARG;

    // Diagnostic de communication avec les dsPIC
    unsigned long m_compteurErrCom_dsPIC1;
    unsigned long m_compteurErrCom_dsPIC2;

	// Buffer de communication avec le dsPIC
	char m_buff[50];

    // ___________________________________________________
    // Les grandeurs mises en forme pou l'application
    float m_tension_batterie;
    unsigned char m_alerte_batterie_faible;

	CCapteurs();
	~CCapteurs();

	//! Initialisation des capteurs
	void Init(void);
	//! Traitement des capteurs (aqcuisition, filtrage)
	void Traitement(void);
    //! RAZ de la position d'un codeur
    void RAZ_PositionCodeur(unsigned char num_codeur, signed long val=0);

	//! Lecture des donnees du capteur couleur TCS34725
	void Lecture_CapteurCouleur(void);
private : 

    //init du capteur couleur
    void Init_CapteurCouleur(void);

    //! Traitements pour les entrées TOR du MBED
	void AcquisitionEntreesTOR(void);
	//! Traitements pour les entrées analogiques du MBED
	void AcquisitionEntreesANA(void);

    //! Traitement pour la mesure de la tension batterie
    void TraitementTensionBatterie(void);
	//! Traitement pour les entrees capteurs ultrasons
	void TraitementTelemetresUltrason(void);
	//! Traitement ordre de debut de match
	void TraitementDepartMatch(void);
	//! Traitement des capteurs de recalage avant
	void TraitementCapteurRecalageBordure(void);

	//! Lecture des données du dsPIC1
	void Lecture_dsPIC1(void);
	//! Lecture des données du dsPIC2
	void Lecture_dsPIC2(void);

    // ____________________________________________
	// Fonctions de traitement du signal

	//! Moyenne glissante	
	float MoyenneGlissante_float(float currentVal, float *buf_oldSamples, unsigned int samplesNumbers);
 	//! Hysterisis
	unsigned char Hysterisis (float vin, unsigned char *etat, float swapOff, float swapOn, unsigned char valOff, unsigned char valOn);




};


#endif


