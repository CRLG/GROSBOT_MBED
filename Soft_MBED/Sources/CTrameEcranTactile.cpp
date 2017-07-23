/*! \file CTrameEcranTactile.cpp
	\brief Classe qui contient les méthodes pour le dialogue avec l'écran tactile
*/
#include "mbed.h"
#include "RessourcesHardware.h"
#include "CTrameEcranTactile.h"

//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CTrameEcranTactile::CTrameEcranTactile() 
{
  m_nombre_recue = 0;
  m_new_trame = false;
}

//___________________________________________________________________________
 /*!
   \brief Destructeur

   \param --
   \return --
*/
CTrameEcranTactile::~CTrameEcranTactile() 
{

}


//___________________________________________________________________________
 /*!
   \brief Indique si une nouvelle trame a ete recue
   \param --
   \return true si une trame a ete recue / false sinon
*/
bool CTrameEcranTactile::isNewTrame(void)
{
  if (m_new_trame) { 
  		m_new_trame = false; 
		return(true); 
  }
  return(false);
}





