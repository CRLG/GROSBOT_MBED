/*! \file CCapteurs.h
    \brief Classe capteurs spécifique au robot
*/

#ifndef _CAPTEURS_H_
#define _CAPTEURS_H_

#include "CCapteursBase.h"

class CApplication;

class CCapteurs : public CCapteursBase
{
public :
    CCapteurs();

    /*virtual*/ void Traitement(void);

    // ____________________________________________
    // Liste tous les capteurs possibles (pour tous les robots)
    /*virtual*/ bool getTirette();

    /*virtual*/ bool getAscenseurButeeHaute();
    /*virtual*/ bool getAscenseurButeeBasse();

    /*virtual*/ float getCapteurPressionKmar();
};
#endif


