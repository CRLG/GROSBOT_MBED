#ifndef _SRF08_H_
#define _SRF08_H_

#include "CTelemetresBase.h"

// Constantes 
// ---------------------------------

// AdresseI2C
#define ADRESSE_SRF08_BASE      0xE0
#define ADRESSE_SRF08_N0_1      0xE0
#define ADRESSE_SRF08_N0_2      0xE2
#define ADRESSE_SRF08_N0_3      0xE4
#define ADRESSE_SRF08_N0_4      0xE6
#define ADRESSE_SRF08_N0_5      0xE8
#define ADRESSE_SRF08_N0_6      0xEA
#define ADRESSE_SRF08_N0_7      0xEC
#define ADRESSE_SRF08_N0_8      0xEE
#define ADRESSE_SRF08_N0_9      0xF0
#define ADRESSE_SRF08_N0_10     0xF2
#define ADRESSE_SRF08_N0_11     0xF4
#define ADRESSE_SRF08_N0_12     0xF6
#define ADRESSE_SRF08_N0_13     0xF8
#define ADRESSE_SRF08_N0_14     0xFA
#define ADRESSE_SRF08_N0_15     0xFC
#define ADRESSE_SRF08_N0_16     0xFE

// Enum pour les adresses des registres : modèle en BANK0
// Registres accessibles en lecture
#define SRF08_reg_SWVERSION     0x00
#define SRF08_reg_LIGHT_SENSOR  0x01
#define SRF08_reg_1st_ECHO_MSB  0x02
#define SRF08_reg_1st_ECHO_LSB  0x03
#define SRF08_reg_2nd_ECHO_MSB  0x04
#define SRF08_reg_2nd_ECHO_LSB  0x05



// Registres accessibles en écriture
#define SRF08_reg_COMMAND     0x00
#define SRF08_reg_MAX_GAIN    0x01
#define SRF08_reg_RANGE       0x02
   
// Liste des commandes 
#define SRF08_MEASURE_INCHES  0x50
#define SRF08_MEASURE_CM      0x51
#define SRF08_MEASURE_USEC    0x52


#define SRF08_RESOLUTION_MAX    46
#define SRF08_MAX_GAIN          0

#define NOMBRE_TELEMETRES_I2C   4
#define NOMBRE_TELEMETRES_ANA   2
#define NOMBRE_TELEMETRES (NOMBRE_TELEMETRES_I2C+NOMBRE_TELEMETRES_ANA)
// Types
// ---------------------------------

// -----------------------------
//! Classe de gestion des options d'exécution passees en ligne de commande
class CTelemetres : public CTelemetresBase
{
public :
	CTelemetres();
	~CTelemetres();
	
    // Ré-implémentation des méthodes virtuelles pures de la classe de base
    /*virtual*/ float getDistanceAVG();
    /*virtual*/ float getDistanceAVD();
    /*virtual*/ float getDistanceARG();
    /*virtual*/ float getDistanceARD();
    /*virtual*/ float getDistanceARGCentre();
    /*virtual*/ float getDistanceARDCentre();

	//! Configuration de l'adresse I2C
	void Config(void);
	//! Traitements
    void Traitement(void);
    void Traitement_I2C(void);
    void Traitement_Analog(void);
    //! Ecrit une valeur dans un registre du SRF08
    void WriteRegister(unsigned char add, unsigned char reg, unsigned char val);
    //! Change l'adresse I2C d'un capteur
    void ChangeAdresse(unsigned char oldAdd, unsigned char newAdd);

    //! Mémorise la dernière distanc mesurée 
    float m_distance[NOMBRE_TELEMETRES];

    //! Compte rendu de l'autodiagnostic

    // Filtrage des capteurs US analogiques
    float MoyenneGlissante_float(float currentVal, float *buf_oldSamples, unsigned int samplesNumbers);

private :
    unsigned char m_adresseI2C[NOMBRE_TELEMETRES_I2C];
    //! Buffer pour la transmission
    char m_buff[10];
    // Pour la machine d'état    
    unsigned char m_numSRF08;  

    static const unsigned int TAILLE_MOYENNE_GLISSANTE_CAPTEURS_US_ANA = 5;
    static const unsigned int TAILLE_MOYENNE_GLISSANTE_CAPTEURS_US_I2C = 5;
    float m_buff_moy_us_arg_centre[TAILLE_MOYENNE_GLISSANTE_CAPTEURS_US_ANA];
    float m_buff_moy_us_ard_centre[TAILLE_MOYENNE_GLISSANTE_CAPTEURS_US_ANA];
    float m_buff_moy_us_i2c[NOMBRE_TELEMETRES_I2C][TAILLE_MOYENNE_GLISSANTE_CAPTEURS_US_I2C];
};

#endif

// END


