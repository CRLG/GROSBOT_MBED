#ifndef _CKMAR_RANGER_STATUETTE_DANS_ROBOT_H_
#define _CKMAR_RANGER_STATUETTE_DANS_ROBOT_H_

#include "CKmarBase.h"

// __________________________________________________________
class CKmarMouvement_RANGER_STATUETTE_DANS_ROBOT : public CKmarMouvement
{
public :
    CKmarMouvement_RANGER_STATUETTE_DANS_ROBOT(CKmarBase *kmar) :
        CKmarMouvement(kmar)
    { }

    /*virtual*/void step();
};


#endif // _CKMAR_RANGER_STATUETTE_DANS_ROBOT_H_
