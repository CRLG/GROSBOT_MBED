#include "sm_activerphare.h"


SM_ActiverPhare::SM_ActiverPhare()
{
    m_main_mission_type = true;
}

const char* SM_ActiverPhare::getName()
{
    return "SM_ActiverPhare";
}

const char* SM_ActiverPhare::stateToName(unsigned short state)
{
    switch(state)
    {
    case ALLER_VERS_PHARE :         return "ALLER_VERS_PHARE";
    case ACCOSTER_PHARE :           return "ACCOSTER_PHARE";
    case ACTIVER_PHARE :            return "ACTIVER_PHARE";
    case VERIFIER_PHARE_ALLUME :    return "VERIFIER_PHARE_ALLUME";
    case FIN_MISSION_PHARE :        return "FIN_MISSION_PHARE";
    }
    return "UNKNOWN_STATE";
}

void SM_ActiverPhare::step()
{
    switch (m_state)
    {
    // ___________________________
    case ALLER_VERS_PHARE:
        if (onEntry()) {
        }

        gotoStateAfter(ACCOSTER_PHARE, 1000);

        if (onExit()) { }
        break;
    // ___________________________
    case ACCOSTER_PHARE:
        if (onEntry()) {
        }

        gotoStateAfter(ACTIVER_PHARE, 1000);

        if (onExit()) { }
        break;
    // ___________________________
    case ACTIVER_PHARE:
        if (onEntry()) {
        }

        gotoStateAfter(VERIFIER_PHARE_ALLUME, 1000);

        if (onExit()) { }
        break;

    // ___________________________
    case VERIFIER_PHARE_ALLUME:
        if (onEntry()) {
        }

        gotoStateAfter(FIN_MISSION_PHARE, 5000);

        if (onExit()) { }

        break;

    // ___________________________
    case FIN_MISSION_PHARE :
        if (onEntry()) { }

        m_succes = true;
        m_score = m_max_score;
        stop();

        if (onExit()) { }
        break;
    }
}
