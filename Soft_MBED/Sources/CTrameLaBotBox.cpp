/*! \file CTrameLaBotBox.cpp
	\brief Classe qui contient les méthodes pour le dialogue avec ANACONBOT
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
   \brief Decodage d'une trame brute re�ue
   \param trameRecue la trame brute � d�coder
   \return --
   \remark M�thode de la classe m�re jamais appel�e
*/
void CTrameLaBotBox::Decode(tStructTrameLaBotBox *trameRecue)
{
    (void*)trameRecue;  // pour �viter les warnings de compilation
}

//___________________________________________________________________________
 /*!
   \brief Encodage de la trame pour envoie
   \param --
   \return la trame � envoyer
   \remark M�thode de la classe m�re jamais appel�e
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







