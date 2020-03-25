#include "sm_outputsinterface.h"
#include "CGlobale.h"

SM_OutputsInterface::SM_OutputsInterface()
{
    init();
}

void SM_OutputsInterface::init()
{

}

void SM_OutputsInterface::stopAll()
{
    // TODO : voir pour arrêter aussi tous les servos
    // Arrêter tous les moteurs, servos et autres actionneurs
    Application.m_asservissement.CommandeManuelle(0, 0);
    Application.m_asservissement_chariot.Stop_Chariot();
    Application.m_power_electrobot.setAllOutputs(0);
}

// Ces méthodes permettent de simplifier l'écriture des machines d'état
// car elles tiennent compte de la couleur de l'équipe pour inverser
// ou non les consignes envoyées à l'asserv
void SM_OutputsInterface::CommandeMouvementXY_sym(float x, float y)
{
    int inv = 1;
    if (Application.m_modelia.m_datas_interface.inverse_consignes_XYTeta) inv = -1;
    Application.m_asservissement.CommandeMouvementXY(x, y*inv);
}

void SM_OutputsInterface::CommandeMouvementXY_TETA_sym(float x, float y, float teta)
{
    int inv = 1;
    if (Application.m_modelia.m_datas_interface.inverse_consignes_XYTeta) inv = -1;
    Application.m_asservissement.CommandeMouvementXY_TETA(x, y*inv, teta*inv);
}
