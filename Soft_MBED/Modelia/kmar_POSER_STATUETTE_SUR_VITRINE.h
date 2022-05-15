#ifndef _CKMAR_POSER_STATUETTE_SUR_VITRINE_H_
#define _CKMAR_POSER_STATUETTE_SUR_VITRINE_H_

#include "CKmarBase.h"

// __________________________________________________________
class CKmarMouvement_POSER_STATUETTE_SUR_VITRINE : public CKmarMouvement
{
public :
    CKmarMouvement_POSER_STATUETTE_SUR_VITRINE(CKmarBase *kmar) :
        CKmarMouvement(kmar)
    { }

    /*virtual*/void step();
};


#endif // _CKMAR_POSER_STATUETTE_SUR_VITRINE_H_
