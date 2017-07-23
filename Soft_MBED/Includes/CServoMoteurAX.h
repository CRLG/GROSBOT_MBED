/*! \file CServoMoteurAX.h
	\brief Classe qui contient la gestion des roues motrices gauche et droite
*/

#ifndef _SERVO_MOTEUR_AX_H_
#define _SERVO_MOTEUR_AX_H_


// -----------------------------
//! Classe de gestion des options d'exécution passees en ligne de commande
class CServoMoteurAX {
#define NBRE_SERVOS_AX              255
#define RELACHE_SERVO_OFF           0xFFFF
#define PERIODE_APPEL_TACHE_GESTION 10 // [msec]

//#define AX12_WRITE_DEBUG 0
//#define AX12_READ_DEBUG 0
//#define AX12_TRIGGER_DEBUG 0
//#define AX12_DEBUG 0

#define AX12_REG_ID 0x3
#define AX12_REG_BAUD 0x4
#define AX12_REG_CW_LIMIT 0x06
#define AX12_REG_CCW_LIMIT 0x08
#define AX12_REG_RETURN_LEVEL 0x10
#define AX12_REG_LED_STATE 0x19
#define AX12_REG_GOAL_POSITION 0x1E
#define AX12_REG_MOVING_SPEED 0x20
#define AX12_REG_VOLTS 0x2A
#define AX12_REG_TEMP 0x2B
#define AX12_REG_MOVING 0x2E
#define AX12_REG_POSITION 0x24

#define AX12_MODE_POSITION  0
#define AX12_MODE_ROTATION  1

#define AX12_CW 1
#define AX12_CCW 0



public :

	CServoMoteurAX();
	~CServoMoteurAX();

    void Init(void);
    void setButeesMinMaxPosition(unsigned char numServo, unsigned int butee_min, unsigned int butee_max);
    void setButeeMinPosition(unsigned char numServo, unsigned int butee_min);
    void setButeeMaxPosition(unsigned char numServo, unsigned int butee_max);
    void CommandePositionVitesse(unsigned char id, unsigned int position, unsigned int vitesse);
   	void CommandePosition(unsigned char id, unsigned int position);
	void CommandeVitesse(unsigned char id, unsigned int vitesse);

    // API de contrôle des servos
    /** Set the mode of the servo
     * @param unsigned char id, the Bus ID of the servo 1-255 
     * @param mode
     *    0 = Positional, default
     *    1 = Continuous rotation
     */
    int setMode(unsigned char id, int mode);

    /** Set baud rate of all attached servos
     * @param unsigned char id, the Bus ID of the servo 1-255 
     * @param mode
     *    0x01 = 1,000,000 bps
     *    0x03 =   500,000 bps
     *    0x04 =   400,000 bps
     *    0x07 =   250,000 bps
     *    0x09 =   200,000 bps
     *    0x10 =   115,200 bps
     *    0x22 =    57,600 bps
     *    0x67 =    19,200 bps
     *    0xCF =     9,600 bp
     */
    int setBaud(unsigned char id, int baud);


    /** Set goal angle in integer degrees, in positional mode
     *
     * @param unsigned char id, the Bus ID of the servo 1-255 
     * @param goal position 0-1023
     *
     */
    int setGoal(unsigned char id, int goal);


    /** Set the speed of the servo in continuous rotation mode
     *
     * @param unsigned char id, the Bus ID of the servo 1-255 
     * @param regul speed, 1 (min speed) -> 1023(max speed) / 0 = max speed (not regulated)
     */
    int setCRSpeed(unsigned char id, int speed);


    /** Set the clockwise limit of the servo
     *
     * @param unsigned char id, the Bus ID of the servo 1-255 
     * @param limit 0-1023
     */
    int setCWLimit(unsigned char id, int limit);
    
    /** Set the counter-clockwise limit of the servo
     *
     * @param unsigned char id, the Bus ID of the servo 1-255 
     * @param limit 0-1023
     */
    int setCCWLimit(unsigned char id, int limit);

    // Change the ID

    /** Change the ID of a servo
     *
     * @param CurentID 1-255
     * @param NewID 1-255
     *
     * If a servo ID is not know, the broadcast address of 0 can be used for CurrentID.
     * In this situation, only one servo should be connected to the bus
     */
    int setID(int CurrentID, int NewID);


    /** Set the return level
     *
     * @param unsigned char id, the Bus ID of the servo 1-255 
     * @param level
     */
    int setReturnLevel (unsigned char id, int level);

    /** Set the led sta
     *
     * @param unsigned char id, the Bus ID of the servo 1-255 
     * @param state
     */
    int setLedState(unsigned char id, int state);

    /** Send the broadcast "trigger" command, to activate any outstanding registered commands
     */
    void trigger(void);

    int write(unsigned char ID, int start, int length, char* data, int flag=0);

private : 
    //! Lecture de l'EEPROM
    void readEEPROM(void);

private : 
   // Baudrate de la communication série
    int _baud;
};


#endif // _SERVO_MOTEUR_AX_H_


