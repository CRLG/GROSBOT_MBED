/*! \file CRoues.cpp
	\brief Classe qui contient toute l'application
*/
#include "mbed.h"
#include "RessourcesHardware.h"
#include "CGlobale.h"

//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CRoues::CRoues() 
{
  resetCodeurs();
  _Mot1_PWM.period(1.0/FREQ_MOTEUR_ROUES);
  _Mot2_PWM.period(1.0/FREQ_MOTEUR_ROUES);

}

//___________________________________________________________________________
 /*!
   \brief Destructeur

   \param --
   \return --
*/
CRoues::~CRoues() 
{

}



//___________________________________________________________________________
 /*!
   \brief Applique la puissance au moteur gauche

   \param vitesse la vitesse signee en pourcentage [-100%;+100]
   \return --
*/
void CRoues::AdapteCommandeMoteur_G(float vitesse)
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

  m_cde_roue_G = vitesse;
}


//___________________________________________________________________________
 /*!
   \brief Applique la puissance au moteur droit

   \param vitesse la vitesse signee en pourcentage [-100%;+100]
   \return --
*/
void CRoues::AdapteCommandeMoteur_D(float vitesse)
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

  m_cde_roue_D = vitesse;
}



//___________________________________________________________________________
 /*!
   \brief Applique la puissance aux 2 moteurs

   \param vit_G la vitesse signee en pourcentage [-100%;+100] pour le moteur gauche
   \param vit_D la vitesse signee en pourcentage [-100%;+100] pour le moteur droit
   \return --
*/
void CRoues::AdapteCommandeMoteurs(float vit_G, float vit_D)
{
  AdapteCommandeMoteur_G(vit_G);
  AdapteCommandeMoteur_D(vit_D);
}


//___________________________________________________________________________
 /*!
   \brief Renvoie la position du codeur G

   \param --
   \return la position du codeur
*/
int CRoues::getCodeurG(void)
{
  return(Application.m_capteurs.m_CumulCodeurPosition4);
}


//___________________________________________________________________________
 /*!
   \brief Renvoie la position du codeur D

   \param --
   \return la position du codeur
*/
int CRoues::getCodeurD(void)
{
  return(Application.m_capteurs.m_CumulCodeurPosition2);
}


//___________________________________________________________________________
 /*!
   \brief Reset les pas cumules par les 2 ccodeurs G et D

   \param --
   \return --
*/
void CRoues::resetCodeurs(void)
{
  Application.m_capteurs.m_CumulCodeurPosition2 = 0;
  Application.m_capteurs.m_CumulCodeurPosition4 = 0;
}







