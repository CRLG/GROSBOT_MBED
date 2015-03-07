// FICHIER GENERE PAR L'OUTIL MESS2C_robot V1.0
// Date de génération : Wed Dec 14 22:48:43 2011
// PLATEFORME CIBLE : MINIBOT
/*************************************************************************************/
/*! \file MessagerieAnaconbot.h
    \brief Contient les definition de chaque trame

*/
/*************************************************************************************/
/*! \addtogroup MESSAGERIE_ANACONBOT		- Ce module contient les definition des trames sous forme de classes heritees de la classe CTrameCAN
		- Chaque signal de la trame a sa donnee membre dans la classe
		- La classse contient egalement des informations generales comme l'ID, DLC pour
		   que l'applicatif y ai acces si besoin
@{  */ 

#ifndef _MESSAGERIE_ANACONBOT_H_
#define _MESSAGERIE_ANACONBOT_H_


#include "CTrameCAN.h"


// Enumérés, defines, ...
#define ID_DIAG_ULTRASON_SRF08 0x230
#define ID_COMMANDE_VITESSE_MVT 0x104
#define ID_ASSERV_DIAG_WR_COMPTEUR_MAX 0x139
#define ID_ASSERV_DIAG_WR_SEUIL_CONV_ANGLE 0x138
#define ID_ASSERV_DIAG_WR_SEUIL_CONV_DIST 0x137
#define ID_ASSERV_DIAG_WR_KI_ANGLE 0x136
#define ID_ASSERV_DIAG_WR_KP_ANGLE 0x135
#define ID_ASSERV_DIAG_WR_KI_DISTANCE 0x134
#define ID_ASSERV_DIAG_WR_KP_DISTANCE 0x133
#define ID_ASSERV_DIAG_WR_CDE_MIN 0x132
#define ID_ASSERV_DIAG_WR_CDE_MAX 0x131
#define ID_ASSERV_DIAG_READ_PARAM_REP 0x120
#define ID_ASSERV_DIAG_READ_PARAM_REQ 0x130
#define ID_COMMANDE_SERVOS_MOTEURS 0x105
#define ID_COMMANDE_MVT_MANUEL 0x102
#define ID_COMMANDE_DISTANCE_ANGLE 0x101
#define ID_COMMANDE_MVT_XY 0x100
#define ID_ETAT_PID_ANGLE 0x155
#define ID_ETAT_PID_DISTANCE 0x154
#define ID_ETAT_ASSERVISSEMENT 0x150
#define ID_POSITION_CODEURS 0x153
#define ID_POSITION_ABSOLUE_TETA 0x152
#define ID_POSITION_ABSOLUE_XY 0x151
#define ID_ETAT_CAPTEURS_SPECIAUX 0x253
#define ID_ETAT_CAPTEURS_TOR 0x252
#define ID_ETAT_CAPTEURS_ANA 0x250

#define DLC_DIAG_ULTRASON_SRF08 2
#define DLC_COMMANDE_VITESSE_MVT 4
#define DLC_ASSERV_DIAG_WR_COMPTEUR_MAX 2
#define DLC_ASSERV_DIAG_WR_SEUIL_CONV_ANGLE 4
#define DLC_ASSERV_DIAG_WR_SEUIL_CONV_DIST 4
#define DLC_ASSERV_DIAG_WR_KI_ANGLE 4
#define DLC_ASSERV_DIAG_WR_KP_ANGLE 2
#define DLC_ASSERV_DIAG_WR_KI_DISTANCE 4
#define DLC_ASSERV_DIAG_WR_KP_DISTANCE 4
#define DLC_ASSERV_DIAG_WR_CDE_MIN 2
#define DLC_ASSERV_DIAG_WR_CDE_MAX 2
#define DLC_ASSERV_DIAG_READ_PARAM_REP 6
#define DLC_ASSERV_DIAG_READ_PARAM_REQ 2
#define DLC_COMMANDE_SERVOS_MOTEURS 8
#define DLC_COMMANDE_MVT_MANUEL 4
#define DLC_COMMANDE_DISTANCE_ANGLE 8
#define DLC_COMMANDE_MVT_XY 8
#define DLC_ETAT_PID_ANGLE 8
#define DLC_ETAT_PID_DISTANCE 8
#define DLC_ETAT_ASSERVISSEMENT 6
#define DLC_POSITION_CODEURS 8
#define DLC_POSITION_ABSOLUE_TETA 4
#define DLC_POSITION_ABSOLUE_XY 8
#define DLC_ETAT_CAPTEURS_SPECIAUX 8
#define DLC_ETAT_CAPTEURS_TOR 8
#define DLC_ETAT_CAPTEURS_ANA 8

#define BRUTE2PHYS_SRF08_NEW_ADRESSE(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_SRF08_NEW_ADRESSE(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_SRF08_OLD_ADRESSE(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_SRF08_OLD_ADRESSE(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_VitesseConsigneAngle(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_VitesseConsigneAngle(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_VitesseConsigneDist(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_VitesseConsigneDist(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_COMPTEUR_MAX(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_COMPTEUR_MAX(val) (unsigned short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_SEUIL_CONV_ANGLE(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_SEUIL_CONV_ANGLE(val) (float)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_SEUIL_CONV_DIST(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_SEUIL_CONV_DIST(val) (float)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_KI_ANGLE(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_KI_ANGLE(val) (float)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_KP_ANGLE(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_KP_ANGLE(val) (float)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_KI_DISTANCE(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_KI_DISTANCE(val) (float)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_KP_DISTANCE(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_KP_DISTANCE(val) (float)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_CDE_MIN(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_CDE_MIN(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_CDE_MAX(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_CDE_MAX(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_DIAG_READ_VALUE_4(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_DIAG_READ_VALUE_4(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_DIAG_READ_VALUE_3(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_DIAG_READ_VALUE_3(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_DIAG_READ_VALUE_2(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_DIAG_READ_VALUE_2(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_DIAG_READ_VALUE_1(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_DIAG_READ_VALUE_1(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_DIAG_READ_PARAM(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_DIAG_READ_PARAM(val) (unsigned short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_DIAG_READ_PARAM(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_DIAG_READ_PARAM(val) (unsigned short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_PositionServoMoteur2(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_PositionServoMoteur2(val) (unsigned short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_VitesseServoMoteur2(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_VitesseServoMoteur2(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_NumeroServoMoteur2(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_NumeroServoMoteur2(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_PositionServoMoteur1(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_PositionServoMoteur1(val) (unsigned short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_VitesseServoMoteur1(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_VitesseServoMoteur1(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_NumeroServoMoteur1(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_NumeroServoMoteur1(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_PuissanceMotD(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_PuissanceMotD(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_PuissanceMotG(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_PuissanceMotG(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_angle_consigne(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_angle_consigne(val) (float)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_distance_consigne(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_distance_consigne(val) (float)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_consigne_Y(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_consigne_Y(val) (float)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_consigne_X(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_consigne_X(val) (float)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_int_terme_angle(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_int_terme_angle(val) (float)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_cde_angle(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_cde_angle(val) (float)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_int_terme_distance(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_int_terme_distance(val) (float)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_cde_distance(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_cde_distance(val) (float)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_cde_moteur_D(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_cde_moteur_D(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_cde_moteur_G(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_cde_moteur_G(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Convergence(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Convergence(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_PosCodeurG(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_PosCodeurG(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_PosCodeurD(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_PosCodeurD(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_teta_pos(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_teta_pos(val) (float)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_y_pos(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_y_pos(val) (float)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_x_pos(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_x_pos(val) (float)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_ULTRASON_8(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_ULTRASON_8(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_ULTRASON_7(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_ULTRASON_7(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_ULTRASON_6(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_ULTRASON_6(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_ULTRASON_5(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_ULTRASON_5(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_ULTRASON_4(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_ULTRASON_4(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_ULTRASON_3(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_ULTRASON_3(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_ULTRASON_2(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_ULTRASON_2(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_ULTRASON_1(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_ULTRASON_1(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_IOB7_J30(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_IOB7_J30(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_IOB6_J30(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_IOB6_J30(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_IOB5_J14(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_IOB5_J14(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_IOB4_J14(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_IOB4_J14(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_IOB3_J14(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_IOB3_J14(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_IOB2_J13(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_IOB2_J13(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_IOB1_J13(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_IOB1_J13(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_IOB0_J13(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_IOB0_J13(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_IOA7_J12(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_IOA7_J12(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_IOA6_J12(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_IOA6_J12(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_IOA5_J12(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_IOA5_J12(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_IOA4_J6(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_IOA4_J6(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_IOA3_J5(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_IOA3_J5(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_IOA2_J4(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_IOA2_J4(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_IOA1_J3(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_IOA1_J3(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_IOA0_J2(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_IOA0_J2(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Eana7_J29(val) ( ((float)val * (0.019608)) + (0.000000) ) 
#define PHYS2BRUTE_Eana7_J29(val) (unsigned char)( (val - (0.000000)) / (0.019608) ) 
#define BRUTE2PHYS_Eana6_J28(val) ( ((float)val * (0.019608)) + (0.000000) ) 
#define PHYS2BRUTE_Eana6_J28(val) (unsigned char)( (val - (0.000000)) / (0.019608) ) 
#define BRUTE2PHYS_Eana5_J23(val) ( ((float)val * (0.019608)) + (0.000000) ) 
#define PHYS2BRUTE_Eana5_J23(val) (unsigned char)( (val - (0.000000)) / (0.019608) ) 
#define BRUTE2PHYS_Eana4_J27(val) ( ((float)val * (0.019608)) + (0.000000) ) 
#define PHYS2BRUTE_Eana4_J27(val) (unsigned char)( (val - (0.000000)) / (0.019608) ) 
#define BRUTE2PHYS_Eana3_J26(val) ( ((float)val * (0.019608)) + (0.000000) ) 
#define PHYS2BRUTE_Eana3_J26(val) (unsigned char)( (val - (0.000000)) / (0.019608) ) 
#define BRUTE2PHYS_Eana2_J22(val) ( ((float)val * (0.019608)) + (0.000000) ) 
#define PHYS2BRUTE_Eana2_J22(val) (unsigned char)( (val - (0.000000)) / (0.019608) ) 
#define BRUTE2PHYS_Eana1_J21(val) ( ((float)val * (0.019608)) + (0.000000) ) 
#define PHYS2BRUTE_Eana1_J21(val) (unsigned char)( (val - (0.000000)) / (0.019608) ) 
#define BRUTE2PHYS_Eana0_J20(val) ( ((float)val * (0.019608)) + (0.000000) ) 
#define PHYS2BRUTE_Eana0_J20(val) (unsigned char)( (val - (0.000000)) / (0.019608) ) 


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_DIAG_ULTRASON_SRF08 : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	unsigned char SRF08_NEW_ADRESSE;
	unsigned char SRF08_OLD_ADRESSE;

	CTrame_DIAG_ULTRASON_SRF08();
	tStructTrameBrute* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_COMMANDE_VITESSE_MVT : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	short VitesseConsigneAngle;
	short VitesseConsigneDist;

	CTrame_COMMANDE_VITESSE_MVT();
	void Decode(tStructTrameBrute* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_ASSERV_DIAG_WR_COMPTEUR_MAX : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	unsigned short COMPTEUR_MAX;

	CTrame_ASSERV_DIAG_WR_COMPTEUR_MAX();
	void Decode(tStructTrameBrute* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_ASSERV_DIAG_WR_SEUIL_CONV_ANGLE : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	float SEUIL_CONV_ANGLE;

	CTrame_ASSERV_DIAG_WR_SEUIL_CONV_ANGLE();
	void Decode(tStructTrameBrute* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_ASSERV_DIAG_WR_SEUIL_CONV_DIST : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	float SEUIL_CONV_DIST;

	CTrame_ASSERV_DIAG_WR_SEUIL_CONV_DIST();
	void Decode(tStructTrameBrute* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_ASSERV_DIAG_WR_KI_ANGLE : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	float KI_ANGLE;

	CTrame_ASSERV_DIAG_WR_KI_ANGLE();
	void Decode(tStructTrameBrute* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_ASSERV_DIAG_WR_KP_ANGLE : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	float KP_ANGLE;

	CTrame_ASSERV_DIAG_WR_KP_ANGLE();
	void Decode(tStructTrameBrute* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_ASSERV_DIAG_WR_KI_DISTANCE : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	float KI_DISTANCE;

	CTrame_ASSERV_DIAG_WR_KI_DISTANCE();
	void Decode(tStructTrameBrute* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_ASSERV_DIAG_WR_KP_DISTANCE : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	float KP_DISTANCE;

	CTrame_ASSERV_DIAG_WR_KP_DISTANCE();
	void Decode(tStructTrameBrute* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_ASSERV_DIAG_WR_CDE_MIN : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	short CDE_MIN;

	CTrame_ASSERV_DIAG_WR_CDE_MIN();
	void Decode(tStructTrameBrute* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_ASSERV_DIAG_WR_CDE_MAX : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	short CDE_MAX;

	CTrame_ASSERV_DIAG_WR_CDE_MAX();
	void Decode(tStructTrameBrute* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_ASSERV_DIAG_READ_PARAM_REP : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	unsigned char DIAG_READ_VALUE_4;
	unsigned char DIAG_READ_VALUE_3;
	unsigned char DIAG_READ_VALUE_2;
	unsigned char DIAG_READ_VALUE_1;
	unsigned short DIAG_READ_PARAM;

	CTrame_ASSERV_DIAG_READ_PARAM_REP();
	void Decode(tStructTrameBrute* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_ASSERV_DIAG_READ_PARAM_REQ : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	unsigned short DIAG_READ_PARAM;

	CTrame_ASSERV_DIAG_READ_PARAM_REQ();
	void Decode(tStructTrameBrute* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_COMMANDE_SERVOS_MOTEURS : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	unsigned short PositionServoMoteur2;
	unsigned char VitesseServoMoteur2;
	unsigned char NumeroServoMoteur2;
	unsigned short PositionServoMoteur1;
	unsigned char VitesseServoMoteur1;
	unsigned char NumeroServoMoteur1;

	CTrame_COMMANDE_SERVOS_MOTEURS();
	void Decode(tStructTrameBrute* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_COMMANDE_MVT_MANUEL : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	short PuissanceMotD;
	short PuissanceMotG;

	CTrame_COMMANDE_MVT_MANUEL();
	void Decode(tStructTrameBrute* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_COMMANDE_DISTANCE_ANGLE : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	float angle_consigne;
	float distance_consigne;

	CTrame_COMMANDE_DISTANCE_ANGLE();
	void Decode(tStructTrameBrute* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_COMMANDE_MVT_XY : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	float consigne_Y;
	float consigne_X;

	CTrame_COMMANDE_MVT_XY();
	void Decode(tStructTrameBrute* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_ETAT_PID_ANGLE : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	float int_terme_angle;
	float cde_angle;

	CTrame_ETAT_PID_ANGLE();
	tStructTrameBrute* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_ETAT_PID_DISTANCE : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	float int_terme_distance;
	float cde_distance;

	CTrame_ETAT_PID_DISTANCE();
	tStructTrameBrute* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_ETAT_ASSERVISSEMENT : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	short cde_moteur_D;
	short cde_moteur_G;
	unsigned char Convergence;

	CTrame_ETAT_ASSERVISSEMENT();
	tStructTrameBrute* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_POSITION_CODEURS : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	short PosCodeurG;
	short PosCodeurD;

	CTrame_POSITION_CODEURS();
	tStructTrameBrute* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_POSITION_ABSOLUE_TETA : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	float teta_pos;

	CTrame_POSITION_ABSOLUE_TETA();
	tStructTrameBrute* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_POSITION_ABSOLUE_XY : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	float y_pos;
	float x_pos;

	CTrame_POSITION_ABSOLUE_XY();
	tStructTrameBrute* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_ETAT_CAPTEURS_SPECIAUX : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	unsigned char ULTRASON_8;
	unsigned char ULTRASON_7;
	unsigned char ULTRASON_6;
	unsigned char ULTRASON_5;
	unsigned char ULTRASON_4;
	unsigned char ULTRASON_3;
	unsigned char ULTRASON_2;
	unsigned char ULTRASON_1;

	CTrame_ETAT_CAPTEURS_SPECIAUX();
	tStructTrameBrute* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_ETAT_CAPTEURS_TOR : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	unsigned char IOB7_J30;
	unsigned char IOB6_J30;
	unsigned char IOB5_J14;
	unsigned char IOB4_J14;
	unsigned char IOB3_J14;
	unsigned char IOB2_J13;
	unsigned char IOB1_J13;
	unsigned char IOB0_J13;
	unsigned char IOA7_J12;
	unsigned char IOA6_J12;
	unsigned char IOA5_J12;
	unsigned char IOA4_J6;
	unsigned char IOA3_J5;
	unsigned char IOA2_J4;
	unsigned char IOA1_J3;
	unsigned char IOA0_J2;

	CTrame_ETAT_CAPTEURS_TOR();
	tStructTrameBrute* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrame_ETAT_CAPTEURS_ANA : public CTrameCAN {
public :
	//! Les signaux de la messagerie
	unsigned char Eana7_J29;
	unsigned char Eana6_J28;
	unsigned char Eana5_J23;
	unsigned char Eana4_J27;
	unsigned char Eana3_J26;
	unsigned char Eana2_J22;
	unsigned char Eana1_J21;
	unsigned char Eana0_J20;

	CTrame_ETAT_CAPTEURS_ANA();
	tStructTrameBrute* Encode(void);
};




#endif
/*! @} */

