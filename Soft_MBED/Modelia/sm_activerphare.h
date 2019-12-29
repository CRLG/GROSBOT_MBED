#ifndef SM_ACTIVERPHARE_H
#define SM_ACTIVERPHARE_H

#include "sm_statemachinebase.h"


class SM_ActiverPhare : public SM_StateMachineBase
{
public:
    SM_ActiverPhare();

    void step();
    const char* getName();
    const char* stateToName(unsigned short state);

    typedef enum {
        ALLER_VERS_PHARE = SM_StateMachineBase::SM_FIRST_STATE,
        ACCOSTER_PHARE,
        ACTIVER_PHARE,
        VERIFIER_PHARE_ALLUME,
        FIN_MISSION_PHARE
    }tState;
};

#endif // SM_ACTIVERPHARE_H
