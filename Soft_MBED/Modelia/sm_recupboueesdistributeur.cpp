#include "sm_recupboueesdistributeur.h"
#include "CGlobale.h"

SM_RecupBoueesDistributeur::SM_RecupBoueesDistributeur()
{
    m_main_mission_type = true;
    m_max_score = 0;
}

const char* SM_RecupBoueesDistributeur::getName()
{
    return "SM_RecupBoueesDistributeur";
}

const char* SM_RecupBoueesDistributeur::stateToName(unsigned short state)
{
    switch(state)
    {
    //case ALLER_VERS_PHARE :         return "ALLER_VERS_PHARE";
    }
    return "UNKNOWN_STATE";
}

// _____________________________________
void SM_RecupBoueesDistributeur::step()
{
    switch (m_state)
    {
    // ___________________________
    case STATE_1:
        if (onEntry()) {
            //Application.m_asservissement.CommandeManuelle(50., 20.);
            Application.m_asservissement.CommandeMouvementXY_TETA(50., 10.f, 0);
            //Application.m_asservissement.CommandeMouvementDistanceAngle(55., 0);
            Application.m_servos_ax.setPosition(1, 100);
            Application.m_servos_ax.setPositionSpeed(1, 100, 10);
            Application.m_servos_ax.setSpeed(2, 10);

            Application.m_servos_sd20.CommandePosition(2, 100);
            Application.m_servos_sd20.CommandePositionVitesse(2, 100, 4);
            Application.m_servos_sd20.CommandeVitesse(2, 3);
        }

        //gotoStateAfter(STATE_2, 3000);
        gotoStateIfConvergence(STATE_2);
        //gotoStateIfTrue(STATE_2, !Application.m_servos_ax.isMoving(1));

        if (onExit()) { }
        break;
    // ___________________________
    case STATE_2:
        if (onEntry()) {
            Application.m_servos_ax.setPosition(1, 0);
            Application.m_servos_sd20.CommandePosition(3, 123);
            Application.m_asservissement.CommandeMouvementXY_TETA(0., 0.f, 0);
        }

        gotoStateIfConvergence(STATE_3);
        //gotoStateAfter(STATE_3, 2300);

        if (onExit()) { }
        break;
    // ___________________________
    case STATE_3:
        if (onEntry()) {
            Application.m_asservissement.CommandeMouvementXY_TETA(20., 0.f, 0);
            //Application.m_asservissement.CommandeManuelle(20., 0.);
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
