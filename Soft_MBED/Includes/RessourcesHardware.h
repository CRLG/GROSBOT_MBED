/*! \file RessoucesHardware.h
	\brief Déclare les ressources hardware du MBED utilisées par le reste du logiciel
*/
#ifndef _RESSOURCES_HARDWARE_H_ 
#define _RESSOURCES_HARDWARE_H_

#include "mbed.h"


extern DigitalOut _led1;
extern DigitalOut _led2;
extern DigitalOut _led3;
extern DigitalOut _led4;

extern DigitalIn _Etor1;
extern DigitalIn _Etor2;
//extern DigitalIn _Etor3;  -> configurée en STOR pour les besoins 2014
extern DigitalIn _Etor4;
extern DigitalIn _Etor5;
extern DigitalIn _Etor6;
extern DigitalIn _Etor_CanRx;
extern DigitalIn _Etor_CanTx;

extern DigitalOut _Stor3;

extern AnalogIn _Mes_Vbat;
extern AnalogIn _Eana1;
extern AnalogIn _Eana2;
extern AnalogIn _Eana3;
extern AnalogIn _Eana4;
extern AnalogIn _Eana5;

extern DigitalOut _Mot1_Sens1; 
extern DigitalOut _Mot1_Sens2;
extern DigitalOut _Mot2_Sens1;
extern DigitalOut _Mot2_Sens2;
extern PwmOut _Mot1_PWM;
extern PwmOut _Mot2_PWM;
extern PwmOut _Moeldar_PWM;
extern Ticker periodicTick;
extern Timer  _Global_Timer;


extern Serial _rs232_pc_tx;
extern Serial _rs232_pc_rx;
extern Serial _rs232_camera_tx;
extern Serial _rs232_camera_rx;
extern I2C _i2c;
//extern SerialHalfDuplex _ax12_serial;
extern Serial _ax12_serial;
extern LocalFileSystem local;
#endif


