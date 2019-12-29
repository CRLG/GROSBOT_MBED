#include "sm_recup4boueeschemin.h"

SM_Recup4BoueesChemin::SM_Recup4BoueesChemin()
{
    m_main_mission_type = true;
    m_max_score = 2;  // TODO : à vérifier
}

const char* SM_Recup4BoueesChemin::getName()
{
    return "SM_Recup4BoueesChemin";
}

const char* SM_Recup4BoueesChemin::stateToName(unsigned short state)
{
    switch(state)
    {
    //case ALLER_VERS_PHARE :         return "ALLER_VERS_PHARE";
    }
    return "UNKNOWN_STATE";
}

// _____________________________________
void SM_Recup4BoueesChemin::step()
{
    switch (m_state)
    {
    // ___________________________
    case STATE_1:
        if (onEntry()) {
        }

        gotoStateAfter(STATE_2, 3000);

        if (onExit()) { }
        break;
    // ___________________________
    case STATE_2:
        if (onEntry()) {
        }

        gotoStateAfter(STATE_3, 2300);

        if (onExit()) { }
        break;
    // ___________________________
    case STATE_3:
        if (onEntry()) {
        }

        gotoStateAfter(STATE_4, 1200);

        if (onExit()) { }
        break;

    // ___________________________
    case STATE_4:
        if (onEntry()) {
        }

        gotoStateAfter(FIN_MISSION, 4000);

        if (onExit()) { }

        break;

    // ___________________________
    case FIN_MISSION :
        m_succes = true;
        m_score = m_max_score;
        stop();
        break;
    }
}
