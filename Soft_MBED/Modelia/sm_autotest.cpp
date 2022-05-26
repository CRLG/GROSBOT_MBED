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
            //on sort le kmar
            Application.m_kmar.start(MOUVEMENT_APPRENTISSAGE_CHARIOT);
        }
        gotoStateIfConvergenceKmar(m_state+1, 4000);
        if (onExit()) {
        }
        break;
    // ___________________________________
    case STATE_2 :
        if (onEntry()) { }
        gotoStateAfter(m_state+1, 2000);
        if (onExit()) { }
        break;
        // ___________________________________
    case STATE_3 :
        if (onEntry()) {
            //on initialise les butées du rack
            Application.m_asservissement_chariot.Recal_Chariot();
        }
        gotoStateIfConvergenceRack(SM_STATE_END, 4000);
        if (onExit()) {
            //on range le kmar
            Application.m_kmar.start(MOUVEMENT_INIT);
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
