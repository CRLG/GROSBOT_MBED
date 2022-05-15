#ifndef _CKMAR_APPRENTISSAGE_CHARIOT_H_
#define _CKMAR_APPRENTISSAGE_CHARIOT_H_

#include "CKmarBase.h"

// __________________________________________________________
class CKmarMouvement_APPRENTISSAGE_CHARIOT : public CKmarMouvement
{
public :
    CKmarMouvement_APPRENTISSAGE_CHARIOT(CKmarBase *kmar) :
        CKmarMouvement(kmar)
    { }

    /*virtual*/void step();
};

#endif // _CKMAR_APPRENTISSAGE_CHARIOT_H_
