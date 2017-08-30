/*! \file RessoucesHardware.cpp
	\brief DÃ©clare les ressources hardware du MBED utilisÃ©es par le reste du logiciel
*/
#include "RessourcesHardware.h"

// __________________________________________________LEDs DU MBED
// Les LED du MBED
DigitalOut _led1(LED1);
DigitalOut _led2(LED2);
DigitalOut _led3(LED3);
DigitalOut _led4(LED4);

// __________________________________________________ENTREES TOUT OU RIEN
DigitalIn  	_Etor1(p5);
DigitalIn  	_Etor2(p6);
// DigitalIn  	_Etor3(p7);     -> configurÃ©e en STOR pour les besoins 2014
DigitalIn  	_Etor4(p8);
DigitalIn  	_Etor5(p11);
DigitalIn  	_Etor6(p12);
DigitalIn  	_Etor_CanRx(p30);	// pins du CAN utilisÃ©e en entrÃ©e TOR lorsque
DigitalIn  	_Etor_CanTx(p29);	//  l'application n'a pas besoin du bus CAN


// __________________________________________________ENTREES ANALOGIQUES
AnalogIn   _Mes_Vbat(p15);
AnalogIn   _Eana1(p16);
AnalogIn   _Eana2(p17);
AnalogIn   _Eana3(p18);
AnalogIn   _Eana4(p19);
AnalogIn   _Eana5(p20);

// __________________________________________________SORTIES TOUT OU RIEN
DigitalOut 	_Mot1_Sens1(p22);
DigitalOut 	_Mot1_Sens2(p23);
DigitalOut 	_Mot2_Sens1(p25);
DigitalOut 	_Mot2_Sens2(p26);
DigitalOut  _Stor3(p7);


// __________________________________________________SORTIES PWM
PwmOut _Mot1_PWM (p21);
PwmOut _Mot2_PWM (p24);


// __________________________________________________ TIMERS
Ticker periodicTick;
Timer  _Global_Timer;  // pour connaitre l'heure depuis le démarrage avec résolution usec (attention : débordement au bout de 30minutes)


// __________________________________________________ RS232
Serial _rs232_pc_tx(USBTX, USBRX);
Serial _rs232_pc_rx(USBTX, USBRX);

Serial _rs232_camera_tx(p28, p27);
Serial _rs232_camera_rx(p28, p27);


// __________________________________________________ I2C
I2C _i2c(p9, p10); //SDA, SCL pour les servos

// __________________________________________________ FICHIERS SUR MBED
LocalFileSystem local("local");

// __________________________________________________ RS232 de pilotage des servos AX
Serial _ax12_serial (p28, p27);



