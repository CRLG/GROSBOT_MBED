/*! \file CTrameLaBotBox.cpp
	\brief Classe qui contient les mÃ©thodes pour le dialogue avec ANACONBOT
*/
#include "mbed.h"
#include "RessourcesHardware.h"
#include "CTrameLaBotBox.h"

//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CTrameLaBotBox::CTrameLaBotBox() 
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
CTrameLaBotBox::~CTrameLaBotBox() 
{

}

//___________________________________________________________________________
 /*!
   \brief Decodage d'une trame brute reçue
   \param trameRecue la trame brute à décoder
   \return --
   \remark Méthode de la classe mère jamais appelée
*/
void CTrameLaBotBox::Decode(tStructTrameLaBotBox *trameRecue)
{
    (void*)trameRecue;  // pour éviter les warnings de compilation
}

//___________________________________________________________________________
 /*!
   \brief Encodage de la trame pour envoie
   \param --
   \return la trame à envoyer
   \remark Méthode de la classe mère jamais appelée
*/
tStructTrameLaBotBox* CTrameLaBotBox::Encode(void)
{
    return nullptr;
}

//___________________________________________________________________________
 /*!
   \brief Indique si une nouvelle trame a ete recue
   \param --
   \return true si une trame a ete recue / false sinon
*/
bool CTrameLaBotBox::isNewTrame(void)
{
  if (m_new_trame) { 
  		m_new_trame = false; 
		return(true); 
  }
  return(false);
}







