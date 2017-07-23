/*! \file CServoMoteurAX.cpp
	\brief Classe qui contient les méthodes pour le dialogue avec ANACONBOT
*/
#include "mbed.h"
#include "RessourcesHardware.h"
#include "CGlobale.h"  // pour l'accès au module EEPROM
#include "CServoMoteurAX.h"

//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CServoMoteurAX::CServoMoteurAX() 
    : _baud(1000000)
{
  _ax12_serial.baud(_baud);
  setReturnLevel(0xFE, 1);  // réponse demandée uniquement sur les requêtes de LECTURE
}



//___________________________________________________________________________
 /*!
   \brief Destructeur

   \param --
   \return --
*/
CServoMoteurAX::~CServoMoteurAX() 
{

}

//___________________________________________________________________________
 /*!
   \brief Initialisation des servos pour la configuration matérielle courante
   \return --
*/
void CServoMoteurAX::Init(void)
{
  // Exemple : configure le comportement de relâché automatique pour chaque servo utilisé
  // setDureeAvantRelache(13, 2000); // servo n°13 relâché automatiquement au bout de 2sec
  // setDureeAvantRelache(14, RELACHE_SERVO_OFF);  // pour le servo 14, pas de relâché automatique de la commande
  // setDureeAvantRelache(17, 1000);
  // ...

  // Lit l'EEPROM et configure le module
  readEEPROM();
}

//___________________________________________________________________________
 /*!
   \brief Lecture des paramètres EEPROM du module
   \return --
    \remarks 
   Lecture des parmaètres de configuration des servos dans l'EEPROM : 
      - Butée min
      - Butée max
      - Position initiale à la mise sous tension
    \warning les butées min et max sont déjà mémorisées dans l'EEPROM des servos AX
             ré-écrire la valeur à chaque démarrage peut réduire la durée de vie de l'EEPROM du servo
*/
void CServoMoteurAX::readEEPROM(void)
{
  // _________________________
  // Lecture des parmaètres de configuration des servos dans l'EEPROM : 
  //    - Butée min
  //    - Butée max
  //    - Position initiale à la mise sous tension
  char sBuff[64]="\0";
  unsigned int servo_val;
  for (unsigned int i=0; i<NBRE_SERVOS_AX; i++) {
    sprintf(sBuff, "butee_min_servo_ax_%d", i);
    if (Application.m_eeprom.getValue(sBuff, &servo_val)) {
         setButeeMinPosition(i, servo_val);       
    }

    sprintf(sBuff, "butee_max_servo_ax_%d", i);
    if (Application.m_eeprom.getValue(sBuff, &servo_val)) {
         setButeeMaxPosition(i, servo_val);  
    }

    sprintf(sBuff, "position_initiale_servo_ax_%d", i);
    if (Application.m_eeprom.getValue(sBuff, &servo_val)) {
         setGoal(i, servo_val);
         wait (0.4); // Tempo pour être certain que tous les servos ne bougent pas en même temps (surconsommation)
    }
  }
}



//___________________________________________________________________________
 /*!
   \brief Commande d'un servo moteur

   \param numServo le servomoteur a piloter  (1 à 20)
   \param pos position du servomoteur
   \param vitesse vitesse a laquelle se deplace le servo

   \return --
*/
void CServoMoteurAX::CommandePositionVitesse(unsigned char id, unsigned int position, unsigned int vitesse)
{
 setGoal(id, position);
 setCRSpeed(id, vitesse);
}

//___________________________________________________________________________
 /*!
   \brief Commande d'un servo moteur

   \param numServo le servomoteur a piloter  (1 à 20)
   \param pos position du servomoteur

   \return --
*/
void CServoMoteurAX::CommandePosition(unsigned char id, unsigned int position)
{
 setGoal(id, position);
}


//___________________________________________________________________________
 /*!
   \brief Commande d'un servo moteur

   \param numServo le servomoteur a piloter  (1 à 20)
   \param vitesse vitesse a laquelle se deplace le servo

   \return --
*/
void CServoMoteurAX::CommandeVitesse(unsigned char id, unsigned int vitesse)
{
 setCRSpeed(id, vitesse);
}



//___________________________________________________________________________
 /*!
   \brief Configure les butées min et max a ne pas dépasser
   \description gère les butées pour préserver le matériel
   \param numServo le servomoteur a piloter  (1 à 20)
   \param butee_min la butée min à ne pas dépasser (ou BUTEE_SERVO_OFF pour le pas gérer la butée)
   \param butee_max la butée max à ne pas dépasser (ou BUTEE_SERVO_OFF pour le pas gérer la butée)
   \return --
*/
void CServoMoteurAX::setButeesMinMaxPosition(unsigned char id, unsigned int butee_min, unsigned int butee_max)
{
 setCWLimit(id, butee_min);
 setCCWLimit(id, butee_max);
}
//___________________________________________________________________________
 /*!
   \brief Configure les butées min a ne pas dépasser
   \description gère les butées pour préserver le matériel
   \param numServo le servomoteur a piloter  (1 à 20)
   \param butee_min la butée min à ne pas dépasser (ou BUTEE_SERVO_OFF pour le pas gérer la butée)
   \return --
*/
void CServoMoteurAX::setButeeMinPosition(unsigned char id, unsigned int butee_min)
{
 setCWLimit(id, butee_min);
}
//___________________________________________________________________________
 /*!
   \brief Configure les butées min et max a ne pas dépasser
   \description gère les butées pour préserver le matériel
   \param numServo le servomoteur a piloter  (1 à 20)
   \param butee_min la butée max à ne pas dépasser (ou BUTEE_SERVO_OFF pour le pas gérer la butée)
   \return --
*/
void CServoMoteurAX::setButeeMaxPosition(unsigned char id, unsigned int butee_max)
{
 setCCWLimit(id, butee_max);
}




// Set the mode of the servo
//  0 = Positional (0-300 degrees)
//  1 = Rotational -1 to 1 speed
int CServoMoteurAX::setMode(unsigned char id, int mode) 
{
     if (mode == 1) { // set CR
        setCWLimit(id, 0);
        setCCWLimit(id, 0);
        setCRSpeed(id, 0.0);
    } else {
        setCWLimit(id, 0);
        setCCWLimit(id, 300);
        setCRSpeed(id, 0.0);
    }
    return(0);
}


int CServoMoteurAX::setGoal(unsigned char id, int goal)
{
    char data[2];

#ifdef AX12_DEBUG
    printf("SetGoal to 0x%x\n",goal);
#endif

    data[0] = goal & 0xff; // bottom 8 bits
    data[1] = goal >> 8;   // top 8 bits

    // write the packet, return the error code
    int rVal = write(id, AX12_REG_GOAL_POSITION, 2, data);
    return(rVal);
}


// Set continuous rotation speed from -1 to 1
int CServoMoteurAX::setCRSpeed(unsigned char id, int speed)
{
    // bit 10     = direction, 0 = CCW, 1=CW
    // bits 9-0   = Speed
    char data[2];

    data[0] = speed & 0xff; // bottom 8 bits
    data[1] = speed >> 8;   // top 8 bits

    // write the packet, return the error code
    int rVal = write(id, AX12_REG_MOVING_SPEED, 2, data);

    return(rVal);
}


int CServoMoteurAX::setCWLimit (unsigned char id, int limit) 
{
    char data[2];

#ifdef AX12_DEBUG
    printf("SetCWLimit to 0x%x\n",limit);
#endif

    data[0] = limit & 0xff; // bottom 8 bits
    data[1] = limit >> 8;   // top 8 bits

    // write the packet, return the error code
    return (write(id, AX12_REG_CW_LIMIT, 2, data));

}

int CServoMoteurAX::setCCWLimit (unsigned char id, int limit) 
{
    char data[2];

#ifdef AX12_DEBUG
    printf("SetCCWLimit to 0x%x\n",limit);
#endif

    data[0] = limit & 0xff; // bottom 8 bits
    data[1] = limit >> 8;   // top 8 bits

    // write the packet, return the error code
    return (write(id, AX12_REG_CCW_LIMIT, 2, data));
}


int CServoMoteurAX::setID (int CurrentID, int NewID) 
{
    char data[1];
    data[0] = NewID;

#ifdef AX12_DEBUG
    printf("Setting ID from 0x%x to 0x%x\n",CurrentID,NewID);
#endif

    return (write(CurrentID, AX12_REG_ID, 1, data));

}


int CServoMoteurAX::setBaud (unsigned char id, int baud)
{
    char data[1];
    data[0] = baud;

#ifdef AX12_DEBUG
    printf("Setting Baud rate to %d\n",baud);
#endif

    return (write(0xFE, AX12_REG_BAUD, 1, data));

}


int CServoMoteurAX::setReturnLevel (unsigned char id, int level) 
{
    char data[1];
    data[0] = level;

#ifdef AX12_DEBUG
    printf("Setting return level %d\n", level);
#endif

    return (write(0xFE, AX12_REG_RETURN_LEVEL, 1, data));

}


int CServoMoteurAX::setLedState(unsigned char id, int state) 
{
    char data[1];
    data[0] = state;

#ifdef AX12_DEBUG
    printf("Setting LED state %d\n", state);
#endif

    return (write(id, AX12_REG_LED_STATE, 1, data));

}




void CServoMoteurAX::trigger(void) 
{
    char TxBuf[16];
    char sum = 0;

#ifdef AX12_TRIGGER_DEBUG
    // Build the TxPacket first in RAM, then we'll send in one go
    printf("\nTriggered\n");
    printf("\nTrigger Packet\n  Header : 0xFF, 0xFF\n");
#endif

    TxBuf[0] = 0xFF;
    TxBuf[1] = 0xFF;

    // ID - Broadcast
    TxBuf[2] = 0xFE;
    sum += TxBuf[2];

#ifdef AX12_TRIGGER_DEBUG
    printf("  ID : %d\n",TxBuf[2]);
#endif

    // Length
    TxBuf[3] = 0x02;
    sum += TxBuf[3];

#ifdef AX12_TRIGGER_DEBUG
    printf("  Length %d\n",TxBuf[3]);
#endif

    // Instruction - ACTION
    TxBuf[4] = 0x04;
    sum += TxBuf[4];

#ifdef AX12_TRIGGER_DEBUG
    printf("  Instruction 0x%X\n",TxBuf[5]);
#endif

    // Checksum
    TxBuf[5] = 0xFF - sum;
#ifdef AX12_TRIGGER_DEBUG
    printf("  Checksum 0x%X\n",TxBuf[5]);
#endif

    // Transmit the packet in one burst with no pausing
    for (int i = 0; i < 6 ; i++) {
        _ax12_serial.putc(TxBuf[i]);
    }

    // This is a broadcast packet, so there will be no reply
    return;
}





int CServoMoteurAX::write(unsigned char id, int start, int bytes, char* data, int flag) {
// 0xff, 0xff, ID, Length, Intruction(write), Address, Param(s), Checksum

    char TxBuf[16];
    char sum = 0;

#ifdef AX12_WRITE_DEBUG
    printf("\nwrite(%d,0x%x,%d,data,%d)\n",ID,start,bytes,flag);
#endif

    // Build the TxPacket first in RAM, then we'll send in one go
#ifdef AX12_WRITE_DEBUG
    printf("\nInstruction Packet\n  Header : 0xFF, 0xFF\n");
#endif

    TxBuf[0] = 0xff;
    TxBuf[1] = 0xff;

    // ID
    TxBuf[2] = id;
    sum += TxBuf[2];

#ifdef AX12_WRITE_DEBUG
    printf("  ID : %d\n",TxBuf[2]);
#endif

    // packet Length
    TxBuf[3] = 3+bytes;
    sum += TxBuf[3];

#ifdef AX12_WRITE_DEBUG
    printf("  Length : %d\n",TxBuf[3]);
#endif


    TxBuf[4]=0x03;
    sum += TxBuf[4];
#ifdef AX12_WRITE_DEBUG
    printf("  Instruction : 0x%x\n",TxBuf[4]);
#endif

    // Start Address
    TxBuf[5] = start;
    sum += TxBuf[5];

#ifdef AX12_WRITE_DEBUG
    printf("  Start : 0x%x\n",TxBuf[5]);
#endif

    // data
    for (char i=0; i<bytes ; i++) {
        TxBuf[6+i] = data[i];
        sum += TxBuf[6+i];

#ifdef AX12_WRITE_DEBUG
        printf("  Data : 0x%x\n",TxBuf[6+i]);
#endif

    }

    // checksum
    TxBuf[6+bytes] = 0xFF - sum;

#ifdef AX12_WRITE_DEBUG
    printf("  Checksum : 0x%x\n",TxBuf[6+bytes]);
#endif

    // Transmit the packet in one burst with no pausing
    for (int i = 0; i < (7 + bytes) ; i++) {
        _ax12_serial.putc(TxBuf[i]);
    }

    // Wait for data to transmit
    wait (0.00002);

    return(0); // return error code
}


