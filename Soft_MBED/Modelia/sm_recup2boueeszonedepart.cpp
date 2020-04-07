#include "CGlobale.h"
#include "sm_recup2boueeszonedepart.h"

SM_Recup2BoueesZoneDepart::SM_Recup2BoueesZoneDepart()
{
    m_main_mission_type = true;
}

const char* SM_Recup2BoueesZoneDepart::getName()
{
    return "SM_Recup2BoueesZoneDepart";
}

const char* SM_Recup2BoueesZoneDepart::stateToName(unsigned short state)
{
    switch(state)
    {
    //case ALLER_VERS_PHARE :         return "ALLER_VERS_PHARE";
    }
    return "UNKNOWN_STATE";
}


// _____________________________________
void SM_Recup2BoueesZoneDepart::step()
{
    switch (m_state)
    {
    // ___________________________
    case STATE_1:
        if (onEntry()) {
            Application.m_power_electrobot.setOutput((dsPicPowerElectrobotBase::tSwitchOutput)EV_AV, 1);
        }

        gotoStateAfter(STATE_2, 900);

        if (onExit()) { }
        break;
    // ___________________________
    case STATE_2:
        if (onEntry()) {
            Application.m_power_electrobot.setOutput((dsPicPowerElectrobotBase::tSwitchOutput)EV_AV, 0);
        }

        gotoStateAfter(STATE_1, 1600);

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
