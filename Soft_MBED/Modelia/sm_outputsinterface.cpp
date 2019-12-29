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
    // TODO
    // Arrêter tous les moteurs, servos et autres actionneurs
    Application.m_asservissement.CommandeManuelle(0, 0);
    Application.m_power_electrobot.setAllOutputs(0);
}
