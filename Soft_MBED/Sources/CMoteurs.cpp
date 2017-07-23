/*! \file CRoues.cpp
	\brief Classe qui contient toute l'application
*/
#include "mbed.h"
#include "CMoteurs.h"
#include "CdsPIC.h"
#include "RessourcesHardware.h"

//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CMoteurs::CMoteurs() 
{
  
}

//___________________________________________________________________________
 /*!
   \brief Destructeur

   \param --
   \return --
*/
CMoteurs::~CMoteurs() 
{

}



//___________________________________________________________________________
 /*!
   \brief Applique la puissance au moteur gauche

   \param vitesse la vitesse signee en pourcentage [-100%;+100]
   \return --
*/
void CMoteurs::CommandeVitesse(unsigned char num_mot, float vitesse)
{
  // Saturation de la commande
  if (vitesse > 100.0)          { vitesse  = 100.0; }
  else if (vitesse < -100.0)    { vitesse = -100.0; }

  switch(num_mot) {
    case MOTEUR_1 : 
      CommandeVitesse_1(vitesse);
      m_cde_mot_1 = vitesse;    
    break;
    case MOTEUR_2 :
      CommandeVitesse_2(vitesse);
      m_cde_mot_2 = vitesse;    
    break;
    case MOTEUR_3 : 
        if (m_cde_mot_3 != vitesse) {  // Pas de dialogue si la consigne n'a pas changé
            CommandeVitesse_3(vitesse);
            m_cde_mot_3 = vitesse;
        }    
    break;
    case MOTEUR_4 : 
        if (m_cde_mot_4 != vitesse) {  // Pas de dialogue si la consigne n'a pas changé
            CommandeVitesse_4(vitesse);
            m_cde_mot_4 = vitesse;
        }    
    break;
    case MOTEUR_5 : 
        if (m_cde_mot_5 != vitesse) {  // Pas de dialogue si la consigne n'a pas changé
            CommandeVitesse_5(vitesse);
            m_cde_mot_5 = vitesse;
        }
    break;
    case MOTEUR_6 : 
        if (m_cde_mot_6 != vitesse) {  // Pas de dialogue si la consigne n'a pas changé
            CommandeVitesse_6(vitesse);
            m_cde_mot_6 = vitesse;
        }    
    break;
    case MOTEUR_7 : 
        _Stor3 = (vitesse>0.1);    
    break;
 
    default : /* ne rien faire */ break;
  }

}

//___________________________________________________________________________
 /*!
   \brief Applique la puissance au moteur 1

   \param vitesse la vitesse signee en pourcentage [-100%;+100]
   \return --
*/
void CMoteurs::CommandeVitesse_1(float vitesse)
{
  if (vitesse > 0) {
	 _Mot1_Sens1 = 0;
	 _Mot1_Sens2 = 1;
	 _Mot1_PWM.write(vitesse/100.0);
  }
  else if (vitesse < 0) {  
	 _Mot1_Sens1 = 1;
	 _Mot1_Sens2 = 0;
  	 _Mot1_PWM.write(vitesse/(-100.0));
 }
  else { 					// Mise en court circuit du pont en H
	 _Mot1_Sens1 = 1;
	 _Mot1_Sens2 = 1;
	 _Mot1_PWM.write(0.0);
  }
}


//___________________________________________________________________________
 /*!
   \brief Applique la puissance au moteur 2

   \param vitesse la vitesse signee en pourcentage [-100%;+100]
   \return --
*/
void CMoteurs::CommandeVitesse_2(float vitesse)
{
  if (vitesse > 0) {
	 _Mot2_Sens1 = 1;
	 _Mot2_Sens2 = 0;
	 _Mot2_PWM.write(vitesse/100.0);
  }
  else if (vitesse < 0) {  
	 _Mot2_Sens1 = 0;
	 _Mot2_Sens2 = 1;
  	 _Mot2_PWM.write(vitesse/(-100.0));
 }
  else { 					// Mise en court circuit du pont en H
	 _Mot2_Sens1 = 1;
	 _Mot2_Sens2 = 1;
	 _Mot2_PWM.write(0.0);
  }
}

//___________________________________________________________________________
 /*!
   \brief Applique la puissance au moteur 3

   \param vitesse la vitesse signee en pourcentage [-100%;+100]
   \return --
*/
void CMoteurs::CommandeVitesse_3(float vitesse)
{
  char buff[10];

  buff[0] = 3;
  buff[1] = REG_COMMANDE_MOTEUR_3;
  buff[2] = (signed char)vitesse;
  buff[3] =  buff[0] + buff[1] + buff[2];
  _i2c.write(ADRESSE_I2C_dsPIC1, buff, 4);
}

//___________________________________________________________________________
 /*!
   \brief Applique la puissance au moteur 4

   \param vitesse la vitesse signee en pourcentage [-100%;+100]
   \return --
*/
void CMoteurs::CommandeVitesse_4(float vitesse)
{
  char buff[10];

  buff[0] = 3;
  buff[1] = REG_COMMANDE_MOTEUR_4;
  buff[2] = (signed char)vitesse;
  buff[3] =  buff[0] + buff[1] + buff[2];
  _i2c.write(ADRESSE_I2C_dsPIC1, buff, 4);
}


//___________________________________________________________________________
 /*!
   \brief Applique la puissance au moteur 5

   \param vitesse la vitesse signee en pourcentage [-100%;+100]
   \return --
*/
void CMoteurs::CommandeVitesse_5(float vitesse)
{
  char buff[10];

  buff[0] = 3;
  buff[1] = REG_COMMANDE_MOTEUR_3;
  buff[2] = (signed char)vitesse;
  buff[3] =  buff[0] + buff[1] + buff[2];
  _i2c.write(ADRESSE_I2C_dsPIC2, buff, 4);
}

//___________________________________________________________________________
 /*!
   \brief Applique la puissance au moteur 6

   \param vitesse la vitesse signee en pourcentage [-100%;+100]
   \return --
*/
void CMoteurs::CommandeVitesse_6(float vitesse)
{
  char buff[10];

  buff[0] = 3;
  buff[1] = REG_COMMANDE_MOTEUR_4;
  buff[2] = (signed char)vitesse;
  buff[3] =  buff[0] + buff[1] + buff[2];
  _i2c.write(ADRESSE_I2C_dsPIC2, buff, 4);
}




