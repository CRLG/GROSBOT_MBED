#ifndef _CKMAR_INIT_H_
#define _CKMAR_INIT_H_

#include "CKmarBase.h"

// __________________________________________________________
class CKmarMouvement_INIT : public CKmarMouvement
{
public :
    CKmarMouvement_INIT(CKmarBase *kmar) :
        CKmarMouvement(kmar)
    { }

    /*virtual*/void step();
};


#endif // _CKMAR_INIT_H_
