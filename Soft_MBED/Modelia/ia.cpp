#include "ia.h"
#include "CGlobale.h"

IA::IA()
    : IABase()
{
    m_sm_liste[m_state_machine_count++] = &m_sm_autotest;
    m_sm_liste[m_state_machine_count++] = &m_sm_activer_phare;
    m_sm_liste[m_state_machine_count++] = &m_sm_recup_2_bouees_zone_depart;
    m_sm_liste[m_state_machine_count++] = &m_sm_recup_bouees_distributeur;
    m_sm_liste[m_state_machine_count++] = &m_sm_deployer_pavillon;
    m_sm_liste[m_state_machine_count++] = &m_sm_deposer_bouees_dans_port;
    m_sm_liste[m_state_machine_count++] = &m_sm_detecter_nord_sud;
    m_sm_liste[m_state_machine_count++] = &m_sm_recup_4_bouees_chemin;
    m_sm_liste[m_state_machine_count++] = &m_sm_arriver_a_bon_port;
}

// ________________________________________________
void IA::step()
{
    m_inputs_interface.Telemetre_AVG       = Application.m_telemetres.getDistanceAVG();
    m_inputs_interface.Telemetre_AVD       = Application.m_telemetres.getDistanceAVD();
    m_inputs_interface.Telemetre_ARG       = Application.m_telemetres.getDistanceARG();
    m_inputs_interface.Telemetre_ARD       = Application.m_telemetres.getDistanceARD();

    m_inputs_interface.obstacle_AVG        = Application.m_detection_obstacles.isObstacleAVG();
    m_inputs_interface.obstacle_AVD        = Application.m_detection_obstacles.isObstacleAVD();
    m_inputs_interface.obstacle_ARG        = Application.m_detection_obstacles.isObstacleARG();
    m_inputs_interface.obstacle_ARD        = Application.m_detection_obstacles.isObstacleARD();
    m_inputs_interface.obstacleDetecte     = Application.m_detection_obstacles.isObstacle();

    // Permet de reconstituer une valeur entre 0 et 15 représentant toutes les situations de blocage
    m_datas_interface.evit_detection_obstacle_bitfield =
            (m_inputs_interface.obstacle_ARG << 3) |
            (m_inputs_interface.obstacle_ARD << 2) |
            (m_inputs_interface.obstacle_AVG << 1) |
            (m_inputs_interface.obstacle_AVD << 0);

    m_inputs_interface.Convergence         = Application.m_asservissement.convergence_conf;
    m_inputs_interface.Convergence_rapide  = Application.m_asservissement.convergence_rapide;
    m_inputs_interface.ConvergenceRack     = Application.m_asservissement_chariot.isConverged();
    m_inputs_interface.X_robot             = Application.m_asservissement.X_robot;
    m_inputs_interface.Y_robot             = Application.m_asservissement.Y_robot;
    m_inputs_interface.angle_robot         = Application.m_asservissement.angle_robot;

    m_inputs_interface.FrontM_Convergence = m_inputs_interface.Convergence && !m_inputs_interface.Convergence_old;
    m_inputs_interface.Convergence_old = m_inputs_interface.Convergence;

    m_inputs_interface.FrontM_Convergence_rapide = m_inputs_interface.Convergence_rapide && !m_inputs_interface.Convergence_rapide_old;
    m_inputs_interface.Convergence_rapide_old = m_inputs_interface.Convergence_rapide;

    m_inputs_interface.FrontM_ConvergenceRack = m_inputs_interface.ConvergenceRack && !m_inputs_interface.ConvergenceRack_old;
    m_inputs_interface.ConvergenceRack_old = m_inputs_interface.ConvergenceRack;

    stepAllStateMachines();
}


// ________________________________________________
void IA::initAllStateMachines()
{
    m_datas_interface.init();
    m_inputs_interface.init();
    m_outputs_interface.init();
    for (int i=0; i<m_state_machine_count; i++) {
        if (m_sm_liste[i]) {
            m_sm_liste[i]->init(this);
        }
    }
}
