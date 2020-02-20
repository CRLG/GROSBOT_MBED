#include "CAsservissementChariot.h"
#include "CGlobale.h"

CAsservissementChariot::CAsservissementChariot()
    : CAsservissementChariotBase()
{
}

// ___________________________________________________
void CAsservissementChariot::Init()
{
    CAsservissementChariotBase::Init();
}

// ___________________________________________________
bool CAsservissementChariot::isButeeBasse()
{
    return (Application.m_electrobot.m_b_Etor4==false);
}

// ___________________________________________________
bool CAsservissementChariot::isButeeHaute()
{
    return (Application.m_electrobot.m_b_Etor2==false);
}

// ___________________________________________________
int CAsservissementChariot::getPositionCodeur()
{
    return (Application.m_electrobot.m_CumulCodeurPosition3);
}

// ___________________________________________________
void CAsservissementChariot::resetPositionCodeur(int pos)
{
    Application.m_electrobot.RAZ_PositionCodeur(CODEUR_3, pos);
}


// ___________________________________________________
void CAsservissementChariot::commandeMoteur(float pourcent)
{
    Application.m_moteurs.CommandeVitesse(MOTEUR_CHARIOT, pourcent);
}

