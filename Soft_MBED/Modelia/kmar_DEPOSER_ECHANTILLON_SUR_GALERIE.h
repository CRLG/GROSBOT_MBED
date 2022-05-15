#ifndef _CKMAR_DEPOSER_ECHANTILLON_SUR_GALERIE_H_
#define _CKMAR_DEPOSER_ECHANTILLON_SUR_GALERIE_H_

#include "CKmarBase.h"

// __________________________________________________________
class CKmarMouvement_DEPOSER_ECHANTILLON_SUR_GALERIE : public CKmarMouvement
{
public :
    CKmarMouvement_DEPOSER_ECHANTILLON_SUR_GALERIE(CKmarBase *kmar) :
        CKmarMouvement(kmar)
    { }

    /*virtual*/void step();
};


#endif // _CKMAR_DEPOSER_ECHANTILLON_SUR_GALERIE_H_
