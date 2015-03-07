/*! \file CServoMoteur.cpp
	\brief Classe qui contient les méthodes pour le dialogue avec ANACONBOT
*/
#include "mbed.h"
#include "RessourcesHardware.h"
#include "CServoMoteur.h"


//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CServoMoteur::CServoMoteur() 
{
  unsigned char i=0;

  // Initialisation des données
  for (i=0; i<NBRE_SERVOS_SD20; i++) {
	 m_position[i] = 0;
	 m_vitesse[i] = 0;
	 m_update[i] = false;
	 m_timer_relache[i] = 0xFFFF;
     m_duree_relache[i] = 1000 / PERIODE_APPEL_TACHE_GESTION;  // 1 seconde par defaut
  }
}



//___________________________________________________________________________
 /*!
   \brief Destructeur

   \param --
   \return --
*/
CServoMoteur::~CServoMoteur() 
{

}

//___________________________________________________________________________
 /*!
   \brief Initialisation des servos pour la configuration matérielle courante
   \return --
*/
void CServoMoteur::Init(void)
{
  // Exemple : configure le comportement de relâché automatique pour chaque servo utilisé
  // setDureeAvantRelache(13, 2000); // servo n°13 relâché automatiquement au bout de 2sec
  // setDureeAvantRelache(14, RELACHE_SERVO_OFF);  // pour le servo 14, pas de relâché automatique de la commande
  // setDureeAvantRelache(17, 1000);
  // ...
    
  // Configure les durées min/max de l'impulsion du servo
  // si la fonction n'est pas appelée, c'est les valeurs par défaut du SD20
  // qui sont utilisées (1msec->2msec)
  setDureesMinMaxPulseSD20(500, 3000); // impulsion entre 500µsec(0.4msec) et 3000µsec (2.3msec)

}



//___________________________________________________________________________
 /*!
   \brief Commande d'un servo moteur

   \param numServo le servomoteur a piloter  (1 à 20)
   \param pos position du servomoteur
   \param vitesse vitesse a laquelle se deplace le servo

   \return --
*/
void CServoMoteur::CommandePositionVitesse(unsigned char numServo, unsigned int position, unsigned int vitesse)
{
  if (numServo>NBRE_SERVOS_SD20) { return; }
  if (numServo == 0) { return; } 

  numServo = numServo - 1;  // -1 car numServo varie entre 1 et 20 (et pas entre 0 et 19)
  
  if (m_position_utilisateur[numServo] != position) {
   	  m_position_utilisateur[numServo] = position;
      m_position[numServo] = position;
	  m_update[numServo] = true;
      if (m_duree_relache[numServo] != RELACHE_SERVO_OFF) {
        m_timer_relache[numServo] = 0;  // Relance la tempo avant relâché de la commande
      }  
  }

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
void CServoMoteur::GestionTransfert(void)
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
void CServoMoteur::setDureeAvantRelache(unsigned char numServo, unsigned int duree_ms)
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
   \brief Configure la duree min et max des impulsions du signal PMW.
   \description le SD20 permet d'utilisre un mode étendu dans lequel les impulsions peuvent aller au delà des servos standards [1msec;2msec].
    
   \param duree_min_us duree minimum de l'impulsion en [µsec]
   \param duree_max_us duree maximum de l'impulsion en [µsec]
   \description le registre 21 contient la variation possible de la largeur d'impulsion
                le registre 22:23 contient l'offset (lié à la duree min de l'impulsion)    
   \return --
*/
void CServoMoteur::setDureesMinMaxPulseSD20(unsigned int duree_min_us, unsigned int duree_max_us)
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

