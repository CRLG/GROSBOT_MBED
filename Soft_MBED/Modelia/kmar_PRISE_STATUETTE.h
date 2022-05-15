#ifndef _CKMAR_PRISE_STATUETTE_H_
#define _CKMAR_PRISE_STATUETTE_H_

#include "CKmarBase.h"

// __________________________________________________________
class CKmarMouvement_PRISE_STATUETTE : public CKmarMouvement
{
public :
    CKmarMouvement_PRISE_STATUETTE(CKmarBase *kmar) :
        CKmarMouvement(kmar)
    { }

    /*virtual*/void step();
};


#endif // _CKMAR_PRISE_STATUETTE_H_
