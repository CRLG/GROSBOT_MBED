// FICHIER GENERE PAR L'OUTIL MESS2C_robot V1.0
// Date de génération : Tue May 05 22:19:15 2015
// PLATEFORME CIBLE : MINIBOT
/*************************************************************************************/
/*! \file MessagerieLaBotBox.h
    \brief Contient les definition de chaque trame

*/
/*************************************************************************************/
/*! \addtogroup MESSAGERIE_LaBotBox		- Ce module contient les definition des trames sous forme de classes heritees de la classe CTrameLaBotBox
		- Chaque signal de la trame a sa donnee membre dans la classe
		- La classse contient egalement des informations generales comme l'ID, DLC pour
		   que l'applicatif y ai acces si besoin
@{  */ 

#ifndef _MESSAGERIE_LaBotBox_H_
#define _MESSAGERIE_LaBotBox_H_


#include "CTrameLaBotBox.h"


// Enumérés, defines, ...
#define ID_ELECTROBOT_CDE_SERVOS_SD20 0x53
#define ID_ELECTROBOT_CDE_SERVOS_AX 0x52
#define ID_ELECTROBOT_CDE_MOTEURS 0x50
#define ID_COMMANDE_MVT_XY 0x102
#define ID_ASSERV_RESET 0x132
#define ID_AUTOAPPRENTISSAGE_ASSERV 0x107
#define ID_COMMANDE_REINIT_XY_TETA 0x106
#define ID_COMMANDE_VITESSE_MVT 0x105
#define ID_COMMANDE_REGUL_VITESSE 0x104
#define ID_COMMANDE_DISTANCE_ANGLE 0x103
#define ID_COMMANDE_MVT_XY_TETA 0x101
#define ID_ASSERV_DIAG_WRITE_PARAM 0x131
#define ID_ELECTROBOT_CDE_SERVOS 0x51
#define ID_COMMANDE_MVT_MANUEL 0x100
#define ID_ETAT_PID_ASSERVISSEMENT 0x153
#define ID_ETAT_ASSERVISSEMENT 0x150
#define ID_POSITION_CODEURS 0x152
#define ID_POSITION_ABSOLUE_XY_TETA 0x151
#define ID_ELECTROBOT_ETAT_CODEURS_1_2 0x30
#define ID_ELECTROBOT_ETAT_TELEMETRES 0x40
#define ID_ELECTROBOT_ETAT_CODEURS_3_4 0x31
#define ID_ELECTROBOT_ETAT_CAPTEURS_2 0x20
#define ID_ELECTROBOT_ETAT_CAPTEURS_1 0x10
#define ID_ETAT_RACK 0x154
#define ID_ELECTROBOT_COLOR_SENSOR 0x21
#define ID_ETAT_ECRAN 0x91
#define ID_ETAT_MATCH 0x41
#define ID_CONFIG_PERIODE_TRAME 0x108


#define DLC_ELECTROBOT_CDE_SERVOS_SD20 5
#define DLC_ELECTROBOT_CDE_SERVOS_AX 5
#define DLC_ELECTROBOT_CDE_MOTEURS 6
#define DLC_COMMANDE_MVT_XY 5
#define DLC_ASSERV_RESET 1
#define DLC_AUTOAPPRENTISSAGE_ASSERV 1
#define DLC_COMMANDE_REINIT_XY_TETA 6
#define DLC_COMMANDE_VITESSE_MVT 6
#define DLC_COMMANDE_REGUL_VITESSE 4
#define DLC_COMMANDE_DISTANCE_ANGLE 5
#define DLC_COMMANDE_MVT_XY_TETA 7
#define DLC_ASSERV_DIAG_WRITE_PARAM 4
#define DLC_ELECTROBOT_CDE_SERVOS 8
#define DLC_COMMANDE_MVT_MANUEL 4
#define DLC_ETAT_PID_ASSERVISSEMENT 8
#define DLC_ETAT_ASSERVISSEMENT 8
#define DLC_POSITION_CODEURS 8
#define DLC_POSITION_ABSOLUE_XY_TETA 6
#define DLC_ELECTROBOT_ETAT_CODEURS_1_2 8
#define DLC_ELECTROBOT_ETAT_TELEMETRES 4
#define DLC_ELECTROBOT_ETAT_CODEURS_3_4 8
#define DLC_ELECTROBOT_ETAT_CAPTEURS_2 8
#define DLC_ELECTROBOT_ETAT_CAPTEURS_1 8
#define DLC_ETAT_RACK 8
#define DLC_ELECTROBOT_COLOR_SENSOR 6
#define DLC_ETAT_ECRAN 4
#define DLC_ETAT_MATCH 3
#define DLC_CONFIG_PERIODE_TRAME 4

#define BRUTE2PHYS_valeur_commande_sd20(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_valeur_commande_sd20(val) (unsigned short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_commande_sd20(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_commande_sd20(val) (unsigned short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_num_servo_sd20(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_num_servo_sd20(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_valeur_commande_ax(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_valeur_commande_ax(val) (unsigned short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_commande_ax(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_commande_ax(val) (unsigned short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_num_servo_ax(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_num_servo_ax(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_cde_moteur_6(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_cde_moteur_6(val) (char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_cde_moteur_5(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_cde_moteur_5(val) (char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_cde_moteur_4(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_cde_moteur_4(val) (char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_cde_moteur_3(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_cde_moteur_3(val) (char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_cde_moteur_2(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_cde_moteur_2(val) (char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_cde_moteur_1(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_cde_moteur_1(val) (char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Y_consigne(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Y_consigne(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_X_consigne(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_X_consigne(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Type_mouvement(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Type_mouvement(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_SECURITE_RESET(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_SECURITE_RESET(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Type_autoapprentissage(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Type_autoapprentissage(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_reinit_teta_pos(val) ( ((float)val * (0.001000)) + (0.000000) ) 
#define PHYS2BRUTE_reinit_teta_pos(val) (short)( (val - (0.000000)) / (0.001000) ) 
#define BRUTE2PHYS_reinit_y_pos(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_reinit_y_pos(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_reinit_x_pos(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_reinit_x_pos(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_indice_sportivite_decel(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_indice_sportivite_decel(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_indice_sportivite_accel(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_indice_sportivite_accel(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_vitesse_rotation_max(val) ( ((float)val * (0.001000)) + (0.000000) ) 
#define PHYS2BRUTE_vitesse_rotation_max(val) (unsigned short)( (val - (0.000000)) / (0.001000) ) 
#define BRUTE2PHYS_vitesse_avance_max(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_vitesse_avance_max(val) (unsigned short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_consigne_vitesse_roue_D(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_consigne_vitesse_roue_D(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_consigne_vitesse_roue_G(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_consigne_vitesse_roue_G(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_angle_consigne(val) ( ((float)val * (0.001000)) + (0.000000) ) 
#define PHYS2BRUTE_angle_consigne(val) (short)( (val - (0.000000)) / (0.001000) ) 
#define BRUTE2PHYS_distance_consigne(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_distance_consigne(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_priorite_mouvement(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_priorite_mouvement(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_angle_consigne(val) ( ((float)val * (0.001000)) + (0.000000) ) 
#define PHYS2BRUTE_angle_consigne(val) (short)( (val - (0.000000)) / (0.001000) ) 
#define BRUTE2PHYS_Y_consigne(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Y_consigne(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_X_consigne(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_X_consigne(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Type_mouvement(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Type_mouvement(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_ASSERV_DIAG_WRITE_VALUE(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_ASSERV_DIAG_WRITE_VALUE(val) (short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_ASSERV_DIAG_WRITE_PARAM(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_ASSERV_DIAG_WRITE_PARAM(val) (unsigned short)( (val - (0.000000)) / (1.000000) ) 
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
#define BRUTE2PHYS_consigne_vitesse_rotation_filt(val) ( ((float)val * (0.000100)) + (0.000000) )
#define PHYS2BRUTE_consigne_vitesse_rotation_filt(val) (short)( (val - (0.000000)) / (0.000100) )
#define BRUTE2PHYS_vitesse_rotation_robot_filt(val) ( ((float)val * (0.000100)) + (0.000000) )
#define PHYS2BRUTE_vitesse_rotation_robot_filt(val) (short)( (val - (0.000000)) / (0.000100) )
#define BRUTE2PHYS_consigne_vitesse_avance_filt(val) ( ((float)val * (0.01000)) + (0.000000) )
#define PHYS2BRUTE_consigne_vitesse_avance_filt(val) (short)( (val - (0.000000)) / (0.01000) )
#define BRUTE2PHYS_vitesse_avance_robot_filt(val) ( ((float)val * (0.01000)) + (0.000000) )
#define PHYS2BRUTE_vitesse_avance_robot_filt(val) (short)( (val - (0.000000)) / (0.01000) )
#define BRUTE2PHYS_compteur_diag_blocage(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_compteur_diag_blocage(val) (unsigned short)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_ModeAsservissement(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_ModeAsservissement(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
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
#define BRUTE2PHYS_teta_pos(val) ( ((float)val * (0.000100)) + (0.000000) ) 
#define PHYS2BRUTE_teta_pos(val) (short)( (val - (0.000000)) / (0.000100) ) 
#define BRUTE2PHYS_y_pos(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_y_pos(val) (short)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_x_pos(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_x_pos(val) (short)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Codeur_2(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Codeur_2(val) (long)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Codeur_1(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Codeur_1(val) (long)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Telemetre4(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Telemetre4(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Telemetre3(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Telemetre3(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Telemetre2(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Telemetre2(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Telemetre1(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Telemetre1(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Codeur_4(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Codeur_4(val) (long)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Codeur_3(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Codeur_3(val) (long)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor_PGED1_dsPIC2(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor_PGED1_dsPIC2(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor_PGED1_dsPIC1(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor_PGED1_dsPIC1(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor_PGEC1_dsPIC2(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor_PGEC1_dsPIC2(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor_PGEC1_dsPIC1(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor_PGEC1_dsPIC1(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor_Codeur4_B(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor_Codeur4_B(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor_Codeur4_A(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor_Codeur4_A(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor_Codeur3_B(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor_Codeur3_B(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor_Codeur3_A(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor_Codeur3_A(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor_CAN_TX(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor_CAN_TX(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor_CAN_RX(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor_CAN_RX(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor6(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor6(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor5(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor5(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor4(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor4(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor3(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor3(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor2(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor2(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Etor1(val) ( ((float)val * (1.000000)) + (0.000000) ) 
#define PHYS2BRUTE_Etor1(val) (unsigned char)( (val - (0.000000)) / (1.000000) ) 
#define BRUTE2PHYS_Vbat(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Vbat(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana13(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana13(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana12(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana12(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana11(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana11(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana10(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana10(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana9(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana9(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana8(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana8(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana7(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana7(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana6(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana6(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana5(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana5(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana4(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana4(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana3(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana3(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana2(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana2(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_Eana1(val) ( ((float)val * (0.100000)) + (0.000000) ) 
#define PHYS2BRUTE_Eana1(val) (unsigned char)( (val - (0.000000)) / (0.100000) ) 
#define BRUTE2PHYS_rack_reserve(val) ( ((float)val * (1.000000)) + (0.000000) )
#define PHYS2BRUTE_rack_reserve(val) (short)( (val - (0.000000)) / (1.000000) )
#define BRUTE2PHYS_rack_modeAsservissement(val) ( ((float)val * (1.000000)) + (0.000000) )
#define PHYS2BRUTE_rack_modeAsservissement(val) (unsigned char)( (val - (0.000000)) / (1.000000) )
#define BRUTE2PHYS_rack_cde_moteur(val) ( ((float)val * (1.000000)) + (0.000000) )
#define PHYS2BRUTE_rack_cde_moteur(val) (short)( (val - (0.000000)) / (1.000000) )
#define BRUTE2PHYS_rack_consigne_moteur(val) ( ((float)val * (1.000000)) + (0.000000) )
#define PHYS2BRUTE_rack_consigne_moteur(val) (short)( (val - (0.000000)) / (1.000000) )
#define BRUTE2PHYS_rack_convergence(val) ( ((float)val * (1.000000)) + (0.000000) )
#define PHYS2BRUTE_rack_convergence(val) (unsigned char)( (val - (0.000000)) / (1.000000) )

// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_ELECTROBOT_CDE_SERVOS_SD20 : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	unsigned short valeur_commande_sd20;
	unsigned short commande_sd20;
	unsigned char num_servo_sd20;

	CTrameLaBotBox_ELECTROBOT_CDE_SERVOS_SD20();
	tStructTrameLaBotBox* Encode(void);
	void Decode(tStructTrameLaBotBox* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_ELECTROBOT_CDE_SERVOS_AX : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	unsigned short valeur_commande_ax;
	unsigned short commande_ax;
	unsigned char num_servo_ax;

	CTrameLaBotBox_ELECTROBOT_CDE_SERVOS_AX();
	void Decode(tStructTrameLaBotBox* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_ELECTROBOT_CDE_MOTEURS : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	char cde_moteur_6;
	char cde_moteur_5;
	char cde_moteur_4;
	char cde_moteur_3;
	char cde_moteur_2;
	char cde_moteur_1;

	CTrameLaBotBox_ELECTROBOT_CDE_MOTEURS();
	void Decode(tStructTrameLaBotBox* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_COMMANDE_MVT_XY : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	short Y_consigne;
	short X_consigne;
	unsigned char Type_mouvement;

	CTrameLaBotBox_COMMANDE_MVT_XY();
	void Decode(tStructTrameLaBotBox* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_ASSERV_RESET : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	unsigned char SECURITE_RESET;

	CTrameLaBotBox_ASSERV_RESET();
	void Decode(tStructTrameLaBotBox* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_AUTOAPPRENTISSAGE_ASSERV : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	unsigned char Type_autoapprentissage;

	CTrameLaBotBox_AUTOAPPRENTISSAGE_ASSERV();
	void Decode(tStructTrameLaBotBox* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_COMMANDE_REINIT_XY_TETA : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	short reinit_teta_pos;
	short reinit_y_pos;
	short reinit_x_pos;

	CTrameLaBotBox_COMMANDE_REINIT_XY_TETA();
	void Decode(tStructTrameLaBotBox* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_COMMANDE_VITESSE_MVT : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	unsigned char indice_sportivite_decel;
	unsigned char indice_sportivite_accel;
	unsigned short vitesse_rotation_max;
	unsigned short vitesse_avance_max;

	CTrameLaBotBox_COMMANDE_VITESSE_MVT();
	void Decode(tStructTrameLaBotBox* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_COMMANDE_REGUL_VITESSE : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	short consigne_vitesse_roue_D;
	short consigne_vitesse_roue_G;

	CTrameLaBotBox_COMMANDE_REGUL_VITESSE();
	void Decode(tStructTrameLaBotBox* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_COMMANDE_DISTANCE_ANGLE : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	short angle_consigne;
	short distance_consigne;
	unsigned char priorite_mouvement;

	CTrameLaBotBox_COMMANDE_DISTANCE_ANGLE();
	void Decode(tStructTrameLaBotBox* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_COMMANDE_MVT_XY_TETA : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	short angle_consigne;
	short Y_consigne;
	short X_consigne;
	unsigned char Type_mouvement;

	CTrameLaBotBox_COMMANDE_MVT_XY_TETA();
	void Decode(tStructTrameLaBotBox* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_ASSERV_DIAG_WRITE_PARAM : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	short ASSERV_DIAG_WRITE_VALUE;
	unsigned short ASSERV_DIAG_WRITE_PARAM;

	CTrameLaBotBox_ASSERV_DIAG_WRITE_PARAM();
	void Decode(tStructTrameLaBotBox* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_ELECTROBOT_CDE_SERVOS : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	unsigned short PositionServoMoteur2;
	unsigned char VitesseServoMoteur2;
	unsigned char NumeroServoMoteur2;
	unsigned short PositionServoMoteur1;
	unsigned char VitesseServoMoteur1;
	unsigned char NumeroServoMoteur1;

	CTrameLaBotBox_ELECTROBOT_CDE_SERVOS();
	void Decode(tStructTrameLaBotBox* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_COMMANDE_MVT_MANUEL : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	short PuissanceMotD;
	short PuissanceMotG;

	CTrameLaBotBox_COMMANDE_MVT_MANUEL();
	void Decode(tStructTrameLaBotBox* trameRecue);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_ETAT_PID_ASSERVISSEMENT : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	short consigne_vitesse_rotation_filt;
	short vitesse_rotation_robot_filt;
	short consigne_vitesse_avance_filt;
	short vitesse_avance_robot_filt;

	CTrameLaBotBox_ETAT_PID_ASSERVISSEMENT();
	tStructTrameLaBotBox* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_ETAT_ASSERVISSEMENT : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	unsigned short compteur_diag_blocage;
	unsigned char ModeAsservissement;
	short cde_moteur_D;
	short cde_moteur_G;
	unsigned char Convergence;

	CTrameLaBotBox_ETAT_ASSERVISSEMENT();
	tStructTrameLaBotBox* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_POSITION_CODEURS : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	short PosCodeurG;
	short PosCodeurD;

	CTrameLaBotBox_POSITION_CODEURS();
	tStructTrameLaBotBox* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_POSITION_ABSOLUE_XY_TETA : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	short teta_pos;
	short y_pos;
	short x_pos;

	CTrameLaBotBox_POSITION_ABSOLUE_XY_TETA();
	tStructTrameLaBotBox* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_ELECTROBOT_ETAT_CODEURS_1_2 : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	long Codeur_2;
	long Codeur_1;

	CTrameLaBotBox_ELECTROBOT_ETAT_CODEURS_1_2();
	tStructTrameLaBotBox* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_ELECTROBOT_ETAT_TELEMETRES : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	unsigned char Telemetre4;
	unsigned char Telemetre3;
	unsigned char Telemetre2;
	unsigned char Telemetre1;

	CTrameLaBotBox_ELECTROBOT_ETAT_TELEMETRES();
	tStructTrameLaBotBox* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_ELECTROBOT_ETAT_CODEURS_3_4 : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	long Codeur_4;
	long Codeur_3;

	CTrameLaBotBox_ELECTROBOT_ETAT_CODEURS_3_4();
	tStructTrameLaBotBox* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_ELECTROBOT_ETAT_CAPTEURS_2 : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	unsigned char Etor_PGED1_dsPIC2;
	unsigned char Etor_PGED1_dsPIC1;
	unsigned char Etor_PGEC1_dsPIC2;
	unsigned char Etor_PGEC1_dsPIC1;
	unsigned char Etor_Codeur4_B;
	unsigned char Etor_Codeur4_A;
	unsigned char Etor_Codeur3_B;
	unsigned char Etor_Codeur3_A;
	unsigned char Etor_CAN_TX;
	unsigned char Etor_CAN_RX;
	unsigned char Etor6;
	unsigned char Etor5;
	unsigned char Etor4;
	unsigned char Etor3;
	unsigned char Etor2;
	unsigned char Etor1;
	unsigned char Vbat;
	unsigned char Eana13;
	unsigned char Eana12;
	unsigned char Eana11;
	unsigned char Eana10;
	unsigned char Eana9;

	CTrameLaBotBox_ELECTROBOT_ETAT_CAPTEURS_2();
	tStructTrameLaBotBox* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_ELECTROBOT_ETAT_CAPTEURS_1 : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	unsigned char Eana8;
	unsigned char Eana7;
	unsigned char Eana6;
	unsigned char Eana5;
	unsigned char Eana4;
	unsigned char Eana3;
	unsigned char Eana2;
	unsigned char Eana1;

	CTrameLaBotBox_ELECTROBOT_ETAT_CAPTEURS_1();
	tStructTrameLaBotBox* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_ECRAN_ETAT_ECRAN : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	short Valeur;
	unsigned short CodeCommande;

	CTrameLaBotBox_ECRAN_ETAT_ECRAN();
	void Decode(tStructTrameLaBotBox* trameRecue);
};

// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_ECRAN_ETAT_MATCH : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	unsigned char ObstacleDetecte;
	unsigned char DiagBlocage;
	unsigned char ConvergenceAsserv;
	unsigned char ModeFonctionnement;
	unsigned char CouleurEquipe;
	unsigned char TempsMatch;

	CTrameLaBotBox_ECRAN_ETAT_MATCH();
	tStructTrameLaBotBox* Encode(void);
};


// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_ETAT_RACK : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	short rack_reserve;
	unsigned char rack_modeAsservissement;
	short rack_cde_moteur;
	short rack_consigne_moteur;
	unsigned char rack_convergence;

	CTrameLaBotBox_ETAT_RACK();
	tStructTrameLaBotBox* Encode(void);
};

// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox_ELECTROBOT_COLOR_SENSOR : public CTrameLaBotBox {
public :
	//! Les signaux de la messagerie
	short R;
	short G;
	short B;

	CTrameLaBotBox_ELECTROBOT_COLOR_SENSOR();
	tStructTrameLaBotBox* Encode(void);
};

// -----------------------------
//! Classe
class CTrameLaBotBox_CONFIG_PERIODE_TRAME : public CTrameLaBotBox {
public :
    //! Les signaux de la messagerie
    unsigned short ID;
    short Periode;

    CTrameLaBotBox_CONFIG_PERIODE_TRAME();
    void Decode(tStructTrameLaBotBox* trameRecue);
};


#endif
/*! @} */


