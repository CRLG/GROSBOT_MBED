/*! \file CCapteurs.cpp
	\brief Classe qui contient toute l'application
*/

#include "CCapteurs.h"
#include "CGlobale.h"

//___________________________________________________________________________
CCapteurs::CCapteurs()
{
}

// ____________________________________________
void CCapteurs::Traitement(void)
{
}

// ____________________________________________
// Liste tous les capteurs possibles (pour tous les robots)
bool CCapteurs::getTirette()
{
    return Application.m_electrobot.m_b_Eana1<2.0f;
}

// ____________________________________________
bool CCapteurs::getAscenseurButeeHaute()
{
    return (Application.m_electrobot.m_b_Etor2==false);
}
bool CCapteurs::getAscenseurButeeBasse()
{
    return (Application.m_electrobot.m_b_Etor4==false);
}

// ____________________________________________
float CCapteurs::getCapteurPressionKmar()
{
    return Application.m_electrobot.m_b_Eana2;
}
