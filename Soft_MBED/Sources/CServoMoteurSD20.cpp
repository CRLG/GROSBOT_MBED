/*! \file CServoMoteurSD20.cpp
	\brief Classe qui contient les méthodes pour le dialogue avec ANACONBOT
*/
#include "mbed.h"
#include "RessourcesHardware.h"
#include "CGlobale.h" // pour l'accès au module EEPROM
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

  // Initialisation des données
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
   \brief Initialisation des servos pour la configuration matérielle courante
   \return --
*/
void CServoMoteurSD20::Init(void)
{
  // Exemple : configure le comportement de relâché automatique pour chaque servo utilisé
  // setDureeAvantRelache(13, 2000); // servo n°13 relâché automatiquement au bout de 2sec
  // setDureeAvantRelache(14, RELACHE_SERVO_OFF);  // pour le servo 14, pas de relâché automatique de la commande
  // setDureeAvantRelache(17, 1000);
  // ...
  // Configure les durées min/max de l'impulsion du servo
  // si la fonction n'est pas appelée, c'est les valeurs par défaut du SD20
  // qui sont utilisées (1msec->2msec)
  //setDureesMinMaxPulseSD20(500, 3000); // impulsion entre 500µsec(0.4msec) et 3000µsec (2.3msec)
	setDureesMinMaxPulseSD20(900, 2100); // impulsion entre 500µsec(0.4msec) et 3000µsec (2.3msec)
  wait(0.05);

  // dévérouille tous les servos du SD20
  // Envoie une consigne de position à "0" sur chaque servo pour le dévérouiller
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
   \brief Lecture des paramètres EEPROM du module
   \return --
    \remarks 
   Lecture des parmaètres de configuration des servos dans l'EEPROM : 
      - Butée min
      - Butée max
      - Position initiale à la mise sous tension
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

   \param numServo le servomoteur a piloter  (1 à 20)
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

   \param numServo le servomoteur a piloter  (1 à 20)
   \param pos position du servomoteur

   \return --
*/
void CServoMoteurSD20::CommandePosition(unsigned char numServo, unsigned int position)
{
  if (numServo>NBRE_SERVOS_SD20) { return; }
  if (numServo == 0) { return; } 

  numServo = numServo - 1;  // -1 car numServo varie entre 1 et 20 (et pas entre 0 et 19)

  // gestion des butées min et max
  position = saturePositionButees(numServo, position, m_pos_butee_min[numServo], m_pos_butee_max[numServo]);

  if (m_position_utilisateur[numServo] != position) {
   	  m_position_utilisateur[numServo] = position;
      m_position[numServo] = position;
	  m_update[numServo] = true;
      if (m_duree_relache[numServo] != RELACHE_SERVO_OFF) {
        m_timer_relache[numServo] = 0;  // Relance la tempo avant relâché de la commande
      }
  }
}

//___________________________________________________________________________
 /*!
   \brief Commande d'un servo moteur

   \param numServo le servomoteur a piloter  (1 à 20)
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
				un temps de pause de environ 100µsec
				Cette fonction doit etre appelee periodiquement
				Cette fonction n'envoie qu'une seule commande de servo
				a la fois
				
   \param --
   \return --
*/
void CServoMoteurSD20::GestionTransfert(void)
{
  static unsigned char servo=0;	 // Mémorise le dernier servo traité
  char cmd[2];
  unsigned char i=0;
	
  // Gestion de l'arrêt automatique des servos au bout de quelques instants pour éviter les vibrations
  // Faut il stopper automatiquement la commande appliquée à un servo ?
  for (i=0; i<NBRE_SERVOS_SD20; i++) {
  	if (m_timer_relache[i] < 0xFFFF) {
		m_timer_relache[i]++;
		if (m_timer_relache[i] > m_duree_relache[i]) { 
			m_timer_relache[i] = 0xFFFF; // Pour ne plus incrémenter le timer et arrêter le traitement
			m_position[i] = 0; // La valeur "0" permet de relâcher la commande du servo (il reste à sa place, mais ne bouge plus)
			m_update[i] = true; // Un transfert est nécessaire
		} // if il est temps de relâcher le servo
     } // if le timer de relâchement est à gérer
  } // for tous les servos 
  

  
  // Recherche le prochain servo à piloter
  // servo est une variable static qui mémorise le dernier servo mis à jour
  // 
  for (i=0; i<NBRE_SERVOS_SD20; i++) {
     servo++;
	 if (servo>=NBRE_SERVOS_SD20) { servo = 0; }
	 
	 if (m_update[servo] == true) {
	   break;
	 }  
  }
  // En sortie de cette boucle, si update[servo] vaut "1", c'est que servo
  // contient le numéro du servo à rafraichir
  if (m_update[servo] == true) {
    m_update[servo] = false;

	cmd[0] = servo+1;  // Register
    cmd[1] = m_position[servo];
    _i2c.write(ADRESSE_I2C_SD20, cmd, 2);
  }
}



//___________________________________________________________________________
 /*!
   \brief Configure la duree avant de relâcher la commande du servo
   \description la relâche de la commande permet de preserver la mécanique
   				en arrêtant la consigne de position au servo.
                Dans certains cas d'utilisation, il ne faut pas relâcher la commande
   \param numServo le servomoteur a piloter  (1 à 20)
   \param duree la duree avant relach [msec] (ou RELACHE_SERVO_OFF pour que le servo ne 
                soit jamais relâché automatiquement mais uniquement sur demande de l'applicatif)
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
   \brief Configure les butées min et max a ne pas dépasser
   \description gère les butées pour préserver le matériel
   \param numServo le servomoteur a piloter  (1 à 20)
   \param butee_min la butée min à ne pas dépasser (ou BUTEE_SERVO_OFF pour le pas gérer la butée)
   \param butee_max la butée max à ne pas dépasser (ou BUTEE_SERVO_OFF pour le pas gérer la butée)
   \return --
*/
void CServoMoteurSD20::setButeesMinMaxPosition(unsigned char numServo, unsigned int butee_min, unsigned int butee_max)
{
  setButeeMinPosition(numServo, butee_min);
  setButeeMaxPosition(numServo, butee_max);
}

//___________________________________________________________________________
 /*!
   \brief Configure les butées min a ne pas dépasser
   \description gère les butées pour préserver le matériel
   \param numServo le servomoteur a piloter  (1 à 20)
   \param butee_min la butée min à ne pas dépasser (ou BUTEE_SERVO_OFF pour le pas gérer la butée)
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
   \brief Configure les butées min et max a ne pas dépasser
   \description gère les butées pour préserver le matériel
   \param numServo le servomoteur a piloter  (1 à 20)
   \param butee_min la butée max à ne pas dépasser (ou BUTEE_SERVO_OFF pour le pas gérer la butée)
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
   \description le SD20 permet d'utilisre un mode étendu dans lequel les impulsions peuvent aller au delà des servos standards [1msec;2msec].
    
   \param duree_min_us duree minimum de l'impulsion en [µsec]
   \param duree_max_us duree maximum de l'impulsion en [µsec]
   \description le registre 21 contient la variation possible de la largeur d'impulsion
                le registre 22:23 contient l'offset (lié à la duree min de l'impulsion)    
   \return --
*/
void CServoMoteurSD20::setDureesMinMaxPulseSD20(unsigned int duree_min_us, unsigned int duree_max_us)
{
  char cmd[10];
  unsigned int reg21;
  unsigned int reg22_23;
                    
  // (duree_max_us - duree_min_us) donne le range de l'impulsion
  reg21     = 65280 / (duree_max_us - duree_min_us); // [µsec]. 65280 = 255*256 (voir formule SD20)
  reg22_23  = duree_min_us - 20; // [µsec].

  // L'écriture dans les registres se fait en 2 fois (contrainte du composant SD20)
  cmd[0] = 21;                      // Registre 21
  cmd[1] = (char)reg21;             // contenu du registre 21 : standard/expanded mode control
  _i2c.write(ADRESSE_I2C_SD20, cmd, 2);

  wait_ms(10); // temps nécessaire au SD20 entre 2 écritures de registres
  cmd[0] = 22;                      // Registre 22-23
  cmd[1] = (char)(reg22_23 >> 8);   // contenu du registre 22 : expand mode offset MSB
  cmd[2] = (char)(reg22_23);        // contenu du registre 22 : expand mode offset MSB
  _i2c.write(ADRESSE_I2C_SD20, cmd, 3);
}

//___________________________________________________________________________
 /*!
   \brief Configure la duree min et max des impulsions du signal PMW.
   \description le SD20 permet d'utilisre un mode étendu dans lequel les impulsions peuvent aller au delà des servos standards [1msec;2msec].
    
   \param duree_min_us duree minimum de l'impulsion en [µsec]
   \param duree_max_us duree maximum de l'impulsion en [µsec]
   \description le registre 21 contient la variation possible de la largeur d'impulsion
                le registre 22:23 contient l'offset (lié à la duree min de l'impulsion)    
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


