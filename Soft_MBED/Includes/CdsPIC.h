/*! \file CdsPIC.h
	\brief Classe qui contient la gestion des dialogues avec le dsPIC
*/

#ifndef _dsPIC_H_
#define _dsPIC_H_

#define ADRESSE_I2C_dsPIC1	0x50
#define ADRESSE_I2C_dsPIC2	0x52


typedef enum {
    REG_VERSION_SOFT_MAJ = 0,
    REG_VERSION_SOFT_MIN,
    REG_PTR_REG_LECTURE_I2C,
    REG_NBRE_REGISTRES_LECTURE_I2C,
    REG_CODEUR_1_MSB,
    REG_CODEUR_1_LSB,
    REG_CODEUR_2_MSB,
    REG_CODEUR_2_LSB,
    REG_EANA_6_10,
    REG_EANA_7_11,
    REG_EANA_8_12,
    REG_EANA_9_13,
    REG_ETOR_CODEUR_1A,
    REG_ETOR_CODEUR_1B,
    REG_ETOR_CODEUR_2A,
    REG_ETOR_CODEUR_2B,
    REG_ETOR_MOT3_PWM,
    REG_ETOR_MOT3_SENS1,
    REG_ETOR_MOT3_SENS2,
    REG_ETOR_MOT4_PWM,
    REG_ETOR_MOT4_SENS1,
    REG_ETOR_MOT4_SENS2,
    REG_ETOR_PGED,
    REG_ETOR_PGEC,
    REG_COMMANDE_MOTEUR_3,
    REG_COMMANDE_MOTEUR_4,
    REG_STOR_CODEUR_1A,
    REG_STOR_CODEUR_1B,
    REG_STOR_CODEUR_2A,
    REG_STOR_CODEUR_2B,
    REG_STOR_MOT3_PWM,
    REG_STOR_MOT3_SENS1,
    REG_STOR_MOT3_SENS2,
    REG_STOR_MOT4_PWM,
    REG_STOR_MOT4_SENS1,
    REG_STOR_MOT4_SENS2,
    REG_STOR_PGED,
    REG_STOR_PGEC,
    REG_PINCFG_CODEUR_1A,
    REG_PINCFG_CODEUR_1B,
    REG_PINCFG_CODEUR_2A,
    REG_PINCFG_CODEUR_2B,
    REG_PINCFG_MOT3_PWM,
    REG_PINCFG_MOT3_SENS1,
    REG_PINCFG_MOT3_SENS2,
    REG_PINCFG_MOT4_PWM,
    REG_PINCFG_MOT4_SENS1,
    REG_PINCFG_MOT4_SENS2,
    REG_PINCFG_PGED,
    REG_PINCFG_PGEC,
    
    MAX_REGISTRES_NUMBER
    
}T_REG_ADDRESS;   



// -----------------------------
//! Classe de gestion des options d'exécution passees en ligne de commande
class CdsPIC {
public :
	//static int ReadRegister(void);	// TODO : mettre les bons paramètres
	//static int WriteRegister(void); // TODO : mettre les bons paramètres

private : 

};


#endif


