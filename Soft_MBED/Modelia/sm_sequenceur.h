#ifndef SM_SEQUENCEUR_H
#define SM_SEQUENCEUR_H

#include "sm_statemachinebase.h"


class SM_Sequenceur : public SM_StateMachineBase
{
public:
    SM_Sequenceur();

    void step();
    const char* getName();
    const char* stateToName(unsigned short state);

    typedef enum {
        RECHERCHE_SEQUENCE_OPTIMUM = SM_StateMachineBase::SM_FIRST_STATE,
        SEQUENCE_EN_COURS,
        EVITEMENT_EN_COURS,
    }tState;

    typedef enum {
        RETOUR_EVIT_RECHERCHE_MEILLEUR_ALGO = 0,
        RETOUR_EVIT_REPRENDS_MISSION_INTERROMPUE
    }tComportementRetourEvitement;


    SM_StateMachineBase *m_current_mission;
};

#endif // SM_SEQUENCEUR_H
