#ifndef _CKMAR_RAMASSE_H_
#define _CKMAR_RAMASSE_H_

#include "CKmarBase.h"

// __________________________________________________________
class CKmarMouvement_RAMASSE : public CKmarMouvement
{
public :
    CKmarMouvement_RAMASSE(CKmarBase *kmar) :
        CKmarMouvement(kmar)
    { }

    /*virtual*/void step();
};

#endif // _CKMAR_RAMASSE_H_
