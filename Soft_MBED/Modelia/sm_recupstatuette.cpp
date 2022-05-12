#include "sm_recupstatuette.h"

SM_RecupStatuette::SM_RecupStatuette()
{
    m_main_mission_type = true;
}

const char* SM_RecupStatuette::getName()
{
    return "SM_RecupStatuette";
}

const char* SM_RecupStatuette::stateToName(unsigned short state)
{
    switch(state)
    {
    //case XXX :         return "XXX";
    }
    return "UNKNOWN_STATE";
}


void SM_RecupStatuette::step()
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
