/*! \file CAsservissementChariot.h
    \brief Classe qui contient l'asservissement vitesse/position du chariot du kmar
*/

#ifndef _ASSERVISSEMENT_CHARIOT_H_
#define _ASSERVISSEMENT_CHARIOT_H_

#include "CAsservissementChariotBase.h"

class CAsservissementChariot : public CAsservissementChariotBase
{
public :
    CAsservissementChariot();

    virtual void Init();

    // Ré_impléméntation des méthodes virtuelles pures
    // en lien avec le hardware
    virtual bool isButeeBasse();
    virtual bool isButeeHaute();
    virtual int getPositionCodeur();
    virtual void resetPositionCodeur(int pos);
    virtual void commandeMoteur(float pourcent);
};

#endif



