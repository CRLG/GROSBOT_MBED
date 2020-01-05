/*! \file CAsservissement.h
    \brief Classe qui contient l'asservissement vitesse/position du robot
*/

#ifndef _ASSERVISSEMENT_H_
#define _ASSERVISSEMENT_H_

#include "CAsservissementBase.h"

// -----------------------------
//! Classe de gestion des options d'exécution passees en ligne de commande
class CAsservissement : public CAsservissementBase
{
public :
    //! Constructeur
    CAsservissement();

    //! Initilise tous les paramètres et valeurs
    void Init(void);
};


#endif


