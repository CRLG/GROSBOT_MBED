#include "sm_inputsinterface.h"

SM_InputsInterface::SM_InputsInterface()
{
    init();
}


void SM_InputsInterface::init()
{
    dde_couleur_equipe = 0;
    dde_test_actionneurs = 1;

    m_distance_balise1=250.;
    m_distance_balise2=250.;
    m_nord=0;
    m_sud=0;

    m_lidar_status = LidarUtils::LIDAR_DISCONNECTED;
}
