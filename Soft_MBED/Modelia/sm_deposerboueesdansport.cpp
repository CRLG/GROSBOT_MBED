#include "sm_deposerboueesdansport.h"

SM_DeposerBoueesDansPort::SM_DeposerBoueesDansPort()
{
    m_main_mission_type = true;
    m_max_score = 2;  // TODO : à vérifier
}

const char* SM_DeposerBoueesDansPort::getName()
{
    return "SM_DeposerBoueesDansPort";
}

const char* SM_DeposerBoueesDansPort::stateToName(unsigned short state)
{
    switch(state)
    {
    //case ALLER_VERS_PHARE :         return "ALLER_VERS_PHARE";
    }
    return "UNKNOWN_STATE";
}


// _____________________________________
void SM_DeposerBoueesDansPort::step()
{
    // Cette SM ne devrait jamais être succès
    // car il y aura potentiellement toujours des bouées à récupérer
    // Si la SM est lancée alors qu'il n'y a pas de verre dans le robot,
    // elle rend la main et pourra être rappelée plus tard

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
