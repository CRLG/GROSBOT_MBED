#ifndef _CKMAR_LEVER_STATUETTE_AVANT_DEPLACEMENT_H_
#define _CKMAR_LEVER_STATUETTE_AVANT_DEPLACEMENT_H_

#include "CKmarBase.h"

// __________________________________________________________
class CKmarMouvement_LEVER_STATUETTE_AVANT_DEPLACEMENT : public CKmarMouvement
{
public :
    CKmarMouvement_LEVER_STATUETTE_AVANT_DEPLACEMENT(CKmarBase *kmar) :
        CKmarMouvement(kmar)
    { }

    /*virtual*/void step();
};


#endif // _CKMAR_LEVER_STATUETTE_AVANT_DEPLACEMENT_H_
