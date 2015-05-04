/*! \file CServoMoteurSD20.cpp
	\brief Classe qui contient les m�thodes pour le dialogue avec ANACONBOT
*/
#include "mbed.h"
#include "RessourcesHardware.h"
#include "CGlobale.h" // pour l'acc�s au module EEPROM
#include "CServoMoteurSD20.h"


//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CServoMoteurSD20::CServoMoteurSD20() 
{
  unsigned char i=0;

  // Initialisation des donn�es
  for (i=0; i<NBRE_SERVOS_SD20; i++) {
	 m_position[i] = 0;
	 m_vitesse[i] = 0;
	 m_update[i] = true;
	 m_timer_relache[i] = 0xFFFF;
     m_duree_relache[i] = 1000 / PERIODE_APPEL_TACHE_GESTION;  // 1 seconde par defaut
     m_pos_butee_min[i] = BUTEE_SERVO_OFF;
     m_pos_butee_max[i] = BUTEE_SERVO_OFF;
  }
}



//___________________________________________________________________________
 /*!
   \brief Destructeur

   \param --
   \return --
*/
CServoMoteurSD20::~CServoMoteurSD20() 
{

}

//___________________________________________________________________________
 /*!
   \brief Initialisation des servos pour la configuration mat�rielle courante
   \return --
*/
void CServoMoteurSD20::Init(void)
{
  // Exemple : configure le comportement de rel�ch� automatique pour chaque servo utilis�
  // setDureeAvantRelache(13, 2000); // servo n�13 rel�ch� automatiquement au bout de 2sec
  // setDureeAvantRelache(14, RELACHE_SERVO_OFF);  // pour le servo 14, pas de rel�ch� automatique de la commande
  // setDureeAvantRelache(17, 1000);
  // ...
  // Configure les dur�es min/max de l'impulsion du servo
  // si la fonction n'est pas appel�e, c'est les valeurs par d�faut du SD20
  // qui sont utilis�es (1msec->2msec)
  setDureesMinMaxPulseSD20(500, 3000); // impulsion entre 500�sec(0.4msec) et 3000�sec (2.3msec)
  wait(0.05);

  // d�v�rouille tous les servos du SD20
  // Envoie une consigne de position � "0" sur chaque servo pour le d�v�rouiller
  // (pour que les commandes suivantes soient prises en compte) 
  for (unsigned int i=0; i<NBRE_SERVOS_SD20; i++) {
    m_update[i] = true;
    GestionTransfert();
    wait(0.01);
  }

  // Lit l'EEPROM et configure le module
  readEEPROM();



}

//___________________________________________________________________________
 /*!
   \brief Lecture des param�tres EEPROM du module
   \return --
    \remarks 
   Lecture des parma�tres de configuration des servos dans l'EEPROM : 
      - But�e min
      - But�e max
      - Position initiale � la mise sous tension
*/
void CServoMoteurSD20::readEEPROM(void)
{
  char sBuff[64]="\0";
  unsigned int servo_val;

  for (unsigned int i=1; i<=NBRE_SERVOS_SD20; i++) {
    sprintf(sBuff, "butee_min_servo_sd20_%d", i);
    if (Application.m_eeprom.getValue(sBuff, &servo_val)) {
         setButeeMinPosition(i, servo_val);       
    }

    sprintf(sBuff, "butee_max_servo_sd20_%d", i);
    if (Application.m_eeprom.getValue(sBuff, &servo_val)) {
         setButeeMaxPosition(i, servo_val);  
    }

    sprintf(sBuff, "vitesse_servo_sd20_%d", i);
    if (Application.m_eeprom.getValue(sBuff, &servo_val)) {
        CommandeVitesse(i, servo_val); 
    }

    sprintf(sBuff, "position_initiale_servo_sd20_%d", i);
    if (Application.m_eeprom.getValue(sBuff, &servo_val)) {
        CommandePositionVitesse(i, servo_val, 0);
    }    
  }
}


//___________________________________________________________________________
 /*!
   \brief Commande d'un servo moteur

   \param numServo le servomoteur a piloter  (1 � 20)
   \param pos position du servomoteur
   \param vitesse vitesse a laquelle se deplace le servo

   \return --
*/
void CServoMoteurSD20::CommandePositionVitesse(unsigned char numServo, unsigned int position, unsigned int vitesse)
{
  CommandePosition(numServo, position);
  CommandeVitesse(numServo, vitesse);
}

//___________________________________________________________________________
 /*!
   \brief Commande d'un servo moteur

   \param numServo le servomoteur a piloter  (1 � 20)
   \param pos position du servomoteur

   \return --
*/
void CServoMoteurSD20::CommandePosition(unsigned char numServo, unsigned int position)
{
  if (numServo>NBRE_SERVOS_SD20) { return; }
  if (numServo == 0) { return; } 

  numServo = numServo - 1;  // -1 car numServo varie entre 1 et 20 (et pas entre 0 et 19)

  // gestion des but�es min et max
  position = saturePositionButees(numServo, position, m_pos_butee_min[numServo], m_pos_butee_max[numServo]);

  if (m_position_utilisateur[numServo] != position) {
   	  m_position_utilisateur[numServo] = position;
      m_position[numServo] = position;
	  m_update[numServo] = true;
      if (m_duree_relache[numServo] != RELACHE_SERVO_OFF) {
        m_timer_relache[numServo] = 0;  // Relance la tempo avant rel�ch� de la commande
      }
  }
}

//___________________________________________________________________________
 /*!
   \brief Commande d'un servo moteur

   \param numServo le servomoteur a piloter  (1 � 20)
   \param vitesse vitesse a laquelle se deplace le servo

   \return --
*/
void CServoMoteurSD20::CommandeVitesse(unsigned char numServo, unsigned int vitesse)
{
  if (numServo>NBRE_SERVOS_SD20) { return; }
  if (numServo == 0) { return; } 

  numServo = numServo - 1;  // -1 car numServo varie entre 1 et 20 (et pas entre 0 et 19)

  if (m_vitesse[numServo] != vitesse) {
   	  m_vitesse[numServo] = vitesse;
	  m_update[numServo] = true;
  }
}


//___________________________________________________________________________
 /*!
   \brief Gestion des transferts
   \description le module SD20 ne permet pas une communication
   				continue. Entre la commande de 2 servos, il faut
				un temps de pause de environ 100�sec
				Cette fonction doit etre appelee periodiquement
				Cette fonction n'envoie qu'une seule commande de servo
				a la fois
				
   \param --
   \return --
*/
void CServoMoteurSD20::GestionTransfert(void)
{
  static unsigned char servo=0;	 // M�morise le dernier servo trait�
  char cmd[2];
  unsigned char i=0;
	
  // Gestion de l'arr�t automatique des servos au bout de quelques instants pour �viter les vibrations
  // Faut il stopper automatiquement la commande appliqu�e � un servo ?
  for (i=0; i<NBRE_SERVOS_SD20; i++) {
  	if (m_timer_relache[i] < 0xFFFF) {
		m_timer_relache[i]++;
		if (m_timer_relache[i] > m_duree_relache[i]) { 
			m_timer_relache[i] = 0xFFFF; // Pour ne plus incr�menter le timer et arr�ter le traitement
			m_position[i] = 0; // La valeur "0" permet de rel�cher la commande du servo (il reste � sa place, mais ne bouge plus)
			m_update[i] = true; // Un transfert est n�cessaire
		} // if il est temps de rel�cher le servo
     } // if le timer de rel�chement est � g�rer
  } // for tous les servos 
  

  
  // Recherche le prochain servo � piloter
  // servo est une variable static qui m�morise le dernier servo mis � jour
  // 
  for (i=0; i<NBRE_SERVOS_SD20; i++) {
     servo++;
	 if (servo>=NBRE_SERVOS_SD20) { servo = 0; }
	 
	 if (m_update[servo] == true) {
	   break;
	 }  
  }
  // En sortie de cette boucle, si update[servo] vaut "1", c'est que servo
  // contient le num�ro du servo � rafraichir
  if (m_update[servo] == true) {
    m_update[servo] = false;

	cmd[0] = servo+1;  // Register
    cmd[1] = m_position[servo];
    _i2c.write(ADRESSE_I2C_SD20, cmd, 2);
  }
}



//___________________________________________________________________________
 /*!
   \brief Configure la duree avant de rel�cher la commande du servo
   \description la rel�che de la commande permet de preserver la m�canique
   				en arr�tant la consigne de position au servo.
                Dans certains cas d'utilisation, il ne faut pas rel�cher la commande
   \param numServo le servomoteur a piloter  (1 � 20)
   \param duree la duree avant relach [msec] (ou RELACHE_SERVO_OFF pour que le servo ne 
                soit jamais rel�ch� automatiquement mais uniquement sur demande de l'applicatif)
   \return --
*/
void CServoMoteurSD20::setDureeAvantRelache(unsigned char numServo, unsigned int duree_ms)
{
  if (numServo>NBRE_SERVOS_SD20) { return; }
  if (numServo == 0) { return; } 

  numServo = numServo - 1;  // -1 car numServo varie entre 1 et 20 (et pas entre 0 et 19)

  if (duree_ms != RELACHE_SERVO_OFF) {
    m_duree_relache[numServo] = (duree_ms / PERIODE_APPEL_TACHE_GESTION);  // Convertit les [msec] en nombre de passage dans la fonction principale de gestion des servos
  }
  else {
    m_duree_relache[numServo] = RELACHE_SERVO_OFF;
  }
}

//___________________________________________________________________________
 /*!
   \brief Configure les but�es min et max a ne pas d�passer
   \description g�re les but�es pour pr�server le mat�riel
   \param numServo le servomoteur a piloter  (1 � 20)
   \param butee_min la but�e min � ne pas d�passer (ou BUTEE_SERVO_OFF pour le pas g�rer la but�e)
   \param butee_max la but�e max � ne pas d�passer (ou BUTEE_SERVO_OFF pour le pas g�rer la but�e)
   \return --
*/
void CServoMoteurSD20::setButeesMinMaxPosition(unsigned char numServo, unsigned int butee_min, unsigned int butee_max)
{
  setButeeMinPosition(numServo, butee_min);
  setButeeMaxPosition(numServo, butee_max);
}

//___________________________________________________________________________
 /*!
   \brief Configure les but�es min a ne pas d�passer
   \description g�re les but�es pour pr�server le mat�riel
   \param numServo le servomoteur a piloter  (1 � 20)
   \param butee_min la but�e min � ne pas d�passer (ou BUTEE_SERVO_OFF pour le pas g�rer la but�e)
   \return --
*/
void CServoMoteurSD20::setButeeMinPosition(unsigned char numServo, unsigned int butee_min)
{
  if (numServo>NBRE_SERVOS_SD20) { return; }
  if (numServo == 0) { return; } 

  numServo = numServo - 1;  // -1 car numServo varie entre 1 et 20 (et pas entre 0 et 19)
  m_pos_butee_min[numServo] = butee_min;
}
//___________________________________________________________________________
 /*!
   \brief Configure les but�es min et max a ne pas d�passer
   \description g�re les but�es pour pr�server le mat�riel
   \param numServo le servomoteur a piloter  (1 � 20)
   \param butee_min la but�e max � ne pas d�passer (ou BUTEE_SERVO_OFF pour le pas g�rer la but�e)
   \return --
*/
void CServoMoteurSD20::setButeeMaxPosition(unsigned char numServo, unsigned int butee_max)
{
  if (numServo>NBRE_SERVOS_SD20) { return; }
  if (numServo == 0) { return; } 

  numServo = numServo - 1;  // -1 car numServo varie entre 1 et 20 (et pas entre 0 et 19)
  m_pos_butee_max[numServo] = butee_max;
}

//___________________________________________________________________________
 /*!
   \brief Configure la duree min et max des impulsions du signal PMW.
   \description le SD20 permet d'utilisre un mode �tendu dans lequel les impulsions peuvent aller au del� des servos standards [1msec;2msec].
    
   \param duree_min_us duree minimum de l'impulsion en [�sec]
   \param duree_max_us duree maximum de l'impulsion en [�sec]
   \description le registre 21 contient la variation possible de la largeur d'impulsion
                le registre 22:23 contient l'offset (li� � la duree min de l'impulsion)    
   \return --
*/
void CServoMoteurSD20::setDureesMinMaxPulseSD20(unsigned int duree_min_us, unsigned int duree_max_us)
{
  char cmd[10];
  unsigned int reg21;
  unsigned int reg22_23;
                    
  // (duree_max_us - duree_min_us) donne le range de l'impulsion
  reg21     = 65280 / (duree_max_us - duree_min_us); // [�sec]. 65280 = 255*256 (voir formule SD20)
  reg22_23  = duree_min_us - 20; // [�sec].

  // L'�criture dans les registres se fait en 2 fois (contrainte du composant SD20)
  cmd[0] = 21;                      // Registre 21
  cmd[1] = (char)reg21;             // contenu du registre 21 : standard/expanded mode control
  _i2c.write(ADRESSE_I2C_SD20, cmd, 2);

  wait_ms(10); // temps n�cessaire au SD20 entre 2 �critures de registres
  cmd[0] = 22;                      // Registre 22-23
  cmd[1] = (char)(reg22_23 >> 8);   // contenu du registre 22 : expand mode offset MSB
  cmd[2] = (char)(reg22_23);        // contenu du registre 22 : expand mode offset MSB
  _i2c.write(ADRESSE_I2C_SD20, cmd, 3);
}

//___________________________________________________________________________
 /*!
   \brief Configure la duree min et max des impulsions du signal PMW.
   \description le SD20 permet d'utilisre un mode �tendu dans lequel les impulsions peuvent aller au del� des servos standards [1msec;2msec].
    
   \param duree_min_us duree minimum de l'impulsion en [�sec]
   \param duree_max_us duree maximum de l'impulsion en [�sec]
   \description le registre 21 contient la variation possible de la largeur d'impulsion
                le registre 22:23 contient l'offset (li� � la duree min de l'impulsion)    
   \return --
*/
unsigned int CServoMoteurSD20::saturePositionButees(unsigned char numServo, unsigned int position, unsigned int butee_min, unsigned int butee_max)
{
  unsigned int ret_pos = position;
  if (m_pos_butee_min[numServo] != BUTEE_SERVO_OFF) {
   if (position < m_pos_butee_min[numServo]) {
    ret_pos = m_pos_butee_min[numServo];
   }
  }
  if (m_pos_butee_max[numServo] != BUTEE_SERVO_OFF) {
   if (position > m_pos_butee_max[numServo]) {
    ret_pos = m_pos_butee_max[numServo];
   }
  }
  return(ret_pos);
}

