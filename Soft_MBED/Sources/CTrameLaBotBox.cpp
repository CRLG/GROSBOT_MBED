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
  m_tx_periode = NO_PERIODIC;
  m_last_time_tx = 0;
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

//___________________________________________________________________________
 /*!
   \brief Fixe la période d'émission de la trame
   \param period_msec la période souhaitée en msec
   \return --
*/
void CTrameLaBotBox::setTransmitPeriod(short period_msec)
{
    m_tx_periode = period_msec;
}

//___________________________________________________________________________
 /*!
   \brief Vérifie s'il est l'heure d'émettre la trame périodique
   \param --
   \return true si l'heure est venue d'émettre la trame / false sinon
*/
bool CTrameLaBotBox::isTimeToSend()
{
    if (m_tx_periode == NO_PERIODIC) return false;

    int current_time = _Global_Timer.read_ms();
    int diff = current_time - m_last_time_tx;
    if ( (diff >= m_tx_periode) || (diff < 0) )  // test sur diff<0 : prend en compte le cas du débordement du  GLobal_Timer au bout de 30minutes après le boot
    {
        m_last_time_tx = current_time;
        return true;
    }
    return false;
}







