/*! \file CServoMoteur.h
	\brief Classe qui contient la gestion des roues motrices gauche et droite
*/

#ifndef _SERVO_MOTEUR_H_
#define _SERVO_MOTEUR_H_


// -----------------------------
//! Classe de gestion des options d'exécution passees en ligne de commande
class CServoMoteur {
#define ADRESSE_I2C_SD20 	0xC2
#define NBRE_SERVOS_SD20	20

#define RELACHE_SERVO_OFF           0xFFFF
#define PERIODE_APPEL_TACHE_GESTION 10 // [msec]

public :

	CServoMoteur();
	~CServoMoteur();
	
    void Init(void);
	void CommandePositionVitesse(unsigned char numServo, unsigned int position, unsigned int vitesse);
	void setDureeAvantRelache(unsigned char numServo, unsigned int duree_ms);
	void GestionTransfert(void);
    void setDureesMinMaxPulseSD20(unsigned int duree_min_us, unsigned int duree_max_us);
private :	 
	//! Memorise la position relle envoyee au servo
	unsigned int m_position[NBRE_SERVOS_SD20];
	//! Memorise la consigne de position demandée par l'applicatif
	unsigned int m_position_utilisateur[NBRE_SERVOS_SD20];
	//! Memorise la vitesse
	unsigned int m_vitesse[NBRE_SERVOS_SD20];
	//! Flag qui indique s'il faut renvoyer la valeur au SD20 pour ce servo
	bool m_update[NBRE_SERVOS_SD20];
	//! Timer de relâché de la commande du servo 
    unsigned int m_timer_relache[NBRE_SERVOS_SD20];
	//! Duree avant relâchée de la commande du servo (unité = nombre de passage dans la boucle de gestion)
    unsigned int m_duree_relache[NBRE_SERVOS_SD20];
	 


};


#endif

