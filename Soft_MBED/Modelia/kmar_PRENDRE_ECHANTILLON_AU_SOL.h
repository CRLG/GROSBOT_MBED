#ifndef _CKMAR_PRENDRE_ECHANTILLON_AU_SOL_H_
#define _CKMAR_PRENDRE_ECHANTILLON_AU_SOL_H_

#include "CKmarBase.h"

// __________________________________________________________
class CKmarMouvement_PRENDRE_ECHANTILLON_AU_SOL : public CKmarMouvement
{
public :
    CKmarMouvement_PRENDRE_ECHANTILLON_AU_SOL(CKmarBase *kmar) :
        CKmarMouvement(kmar)
    { }

    /*virtual*/void step();
};


#endif // _CKMAR_PRENDRE_ECHANTILLON_AU_SOL_H_
