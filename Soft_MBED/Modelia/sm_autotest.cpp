#include "CGlobale.h"
#include "sm_autotest.h"

SM_Autotest::SM_Autotest()
{
}

const char* SM_Autotest::getName()
{
    return "SM_Autotest";
}

const char* SM_Autotest::stateToName(unsigned short state)
{
    switch(state)
    {
    //case ALLER_VERS_PHARE :         return "ALLER_VERS_PHARE";
    }
    return "UNKNOWN_STATE";
}



// _____________________________________
void SM_Autotest::step()
{
    switch(m_state)
    {
    // ___________________________________
    case STATE_1 :
        if (onEntry()) {
            //Application.m_asservissement.CommandeManuelle(10.1, 20);
            Application.m_power_electrobot.setOutput((dsPicPowerElectrobotBase::tSwitchOutput)ELECTROVANNE, 1);
        }
        gotoStateAfter(m_state+1, 800);
        if (onExit()) {
            //if (Application.m_power_electrobot.getGlobalCurrent() > 0.3) qDebug() << "ELECTROVANNE1 is OK" << Application.m_power_electrobot.getGlobalCurrent();
            //else qDebug() << "ELECTROVANNE1 is KO";
            Application.m_power_electrobot.setOutput((dsPicPowerElectrobotBase::tSwitchOutput)ELECTROVANNE, 0);
        }
        break;
    // ___________________________________
    case STATE_2 :
        if (onEntry()) {
            Application.m_power_electrobot.setOutput((dsPicPowerElectrobotBase::tSwitchOutput)POMPE, 1);
        }
        gotoStateAfter(SM_STATE_END, 800);
        if (onExit()) {
            Application.m_power_electrobot.setOutput((dsPicPowerElectrobotBase::tSwitchOutput)POMPE, 0);
        }
        break;

    // ___________________________________
    case SM_STATE_END :
        if (onEntry()) {
            gotoState(STATE_1);  // Autorise la machine d'état à être relancée au début
            stop();
        }

        if (onExit()) { }
        break;
    }
}
