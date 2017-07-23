/*! \file CTrameCamera.cpp
	\brief Classe qui contient les méthodes pour le dialogue avec ANACONBOT
*/
#include "mbed.h"
#include "RessourcesHardware.h"
#include "CTrameCamera.h"

//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CTrameCamera::CTrameCamera() 
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
CTrameCamera::~CTrameCamera() 
{

}


//___________________________________________________________________________
 /*!
   \brief Indique si une nouvelle trame a ete recue
   \param --
   \return true si une trame a ete recue / false sinon
*/
bool CTrameCamera::isNewTrame(void)
{
  if (m_new_trame) { 
  		m_new_trame = false; 
		return(true); 
  }
  return(false);
}





