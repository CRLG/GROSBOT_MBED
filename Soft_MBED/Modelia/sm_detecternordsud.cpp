#include "sm_detecternordsud.h"

SM_DetecterNordSud::SM_DetecterNordSud()
{

}

const char* SM_DetecterNordSud::getName()
{
    return "SM_DetecterNordSud";
}

const char* SM_DetecterNordSud::stateToName(unsigned short state)
{
    switch(state)
    {
    //case ALLER_VERS_PHARE :         return "ALLER_VERS_PHARE";
    }
    return "UNKNOWN_STATE";
}

// _____________________________________
void SM_DetecterNordSud::step()
{
    switch (m_state)
    {
    // ___________________________
    case STATE_1:
        if (onEntry()) {
        }

        gotoStateAfter(STATE_2, 2000);

        if (onExit()) { }
        break;
    // ___________________________
    case STATE_2:
        if (onEntry()) {
        }

        gotoStateAfter(STATE_3, 1300);

        if (onExit()) { }
        break;
    // ___________________________
    case STATE_3:
        if (onEntry()) {
        }

        gotoStateAfter(STATE_4, 2200);

        if (onExit()) { }
        break;

    // ___________________________
    case STATE_4:
        if (onEntry()) {
        }

        gotoStateAfter(FIN_MISSION, 1000);

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
