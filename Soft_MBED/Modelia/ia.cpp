// ________________________________________________
// !! ATTENTION !!
// Ce code est commun aux projets du robot réel et simulation
// Il ne doit pas y avoir de code spécifique MBED
//  ou d'appel à une classe non gérée par une couche d'abstraction
//  au risque de ne plus pouvoir tourner sur en simulation

#include "ia.h"
#include "CGlobale.h"
#include "ConfigSpecifiqueCoupe.h"

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
void IA::init()
{
    m_inputs_interface.TE_Modele = PERIODE_APPEL_MODELIA;
    m_datas_interface.init();
    m_inputs_interface.init();
    m_outputs_interface.init();
    for (int i=0; i<m_state_machine_count; i++) {
        if (m_sm_liste[i]) {
            m_sm_liste[i]->init(this);
        }
    }
    setMaxScores();
    m_sm_main.start();
}

// ________________________________________________
// Définit l'ordre d'exécution des "main missions"
// Cette année, pour ce robot, les mains missions sont :
//   - m_sm_activer_phare;
//   - m_sm_deposer_bouees_dans_port;
//   - m_sm_recup_2_bouees_zone_depart;
//   - m_sm_recup_4_bouees_chemin;
//   - m_sm_recup_bouees_distributeur;
//   - m_sm_arriver_a_bon_port;
// Pour interdire l'exécution d'une mission :
//   - m_sm_xxx.setEnabled(false);
void IA::setStrategie(unsigned char strategie)
{
    int ordre = 0;
    resetAllSMPriority();
    switch (strategie) {
    //
    case STRATEGIE_PAR_DEFAUT:
        m_datas_interface.choix_algo_next_mission = ALGO_PERTINENT_MISSION_CHOIX_PRIORITE;
        m_sm_recup_2_bouees_zone_depart.setPrioriteExecution(ordre++);
        //m_datas_interface.evit_inhibe_obstacle=true;
        m_sm_activer_phare.setEnabled(false);
        m_sm_arriver_a_bon_port.setEnabled(false);
        m_sm_autotest.setEnabled(false);
        m_sm_deployer_pavillon.setEnabled(false);
        m_sm_deposer_bouees_dans_port.setEnabled(false);
        m_sm_detecter_nord_sud.setEnabled(false);
        m_sm_recup_4_bouees_chemin.setEnabled(false);
        m_sm_recup_bouees_distributeur.setEnabled(false);
        break;
    // ________________________ Attention : c'est juste un exemple pour montrer comment ça s'utilise
    case STRATEGIE_TEST_01:
        m_datas_interface.choix_algo_next_mission = ALGO_PERTINENT_MISSION_CHOIX_PRIORITE;
        Application.m_modelia.m_sm_recup_bouees_distributeur.setPrioriteExecution(ordre++);
        break;
    // ________________________ Attention : c'est juste un exemple pour montrer comment ça s'utilise
    case STRATEGIE_HOMOLO1:
        m_datas_interface.choix_algo_next_mission = ALGO_PERTINENT_MISSION_CHOIX_PRIORITE;
        //m_datas_interface.evit_inhibe_obstacle=true;
        m_datas_interface.evit_choix_strategie= SM_DatasInterface::STRATEGIE_EVITEMENT_ATTENDRE;
        Application.m_detection_obstacles.setSeuilDetectionObstacle(12);
        m_datas_interface.evit_nombre_max_tentatives=1;
        m_sm_recup_2_bouees_zone_depart.setPrioriteExecution(ordre++);
        m_sm_activer_phare.setPrioriteExecution(ordre++);
        m_sm_detecter_nord_sud.setPrioriteExecution(ordre++);
        m_sm_deployer_pavillon.setEnabled(false);

        m_sm_recup_bouees_distributeur.setEnabled(false);
        m_sm_arriver_a_bon_port.setEnabled(false);
        m_sm_autotest.setEnabled(false);
        m_sm_deposer_bouees_dans_port.setEnabled(false);

        m_sm_recup_4_bouees_chemin.setEnabled(false);

        //m_sm_recup_bouees_distributeur.setPrioriteExecution(ordre++);
        //m_sm_activer_phare.setPrioriteExecution(ordre++);  // Pour l'essai
        break;
    // ________________________ Attention : c'est juste un exemple pour montrer comment ça s'utilise
    case STRATEGIE_HOMOLO2:
        m_datas_interface.choix_algo_next_mission = ALGO_PERTINENT_MISSION_CHOIX_PRIORITE;
        //m_sm_deployer_pavillon.setPrioriteExecution(ordre++);
        m_sm_activer_phare.setEnabled(false);  // celle là, on ne veut surtout pas qu'elle s'exécute dans cette stratégie
        break;
    // ________________________ Attention : c'est juste un exemple pour montrer comment ça s'utilise
    case STRATEGIE_01:
        m_datas_interface.choix_algo_next_mission = ALGO_PERTINENT_MISSION_SCORE_MAX;
        m_sm_activer_phare.setEnabled(false);  // celle là, on ne veut surtout pas qu'elle s'exécute dans cette stratégie
        break;
    // ________________________
    // TODO : configurer les autres stratégies

    // ________________________  A VERIFIER
    default:
        m_datas_interface.choix_algo_next_mission = ALGO_PERTINENT_MISSION_CHOIX_PRIORITE;
        m_sm_recup_2_bouees_zone_depart.setPrioriteExecution(ordre++);
        //m_datas_interface.evit_inhibe_obstacle=true;
        m_sm_activer_phare.setEnabled(false);
        m_sm_arriver_a_bon_port.setEnabled(false);
        m_sm_autotest.setEnabled(false);
        m_sm_deployer_pavillon.setEnabled(false);
        m_sm_deposer_bouees_dans_port.setEnabled(false);
        m_sm_detecter_nord_sud.setEnabled(false);
        m_sm_recup_4_bouees_chemin.setEnabled(false);
        m_sm_recup_bouees_distributeur.setEnabled(false);
        break;
    }
    m_datas_interface.ChoixStrategieMatch = strategie;
}

// ________________________________________________
void IA::setMaxScores()
{
    // TODO : valeurs des scores max fixées au pif.
    // Mettre les vraies valeurs
    m_sm_recup_2_bouees_zone_depart.setScoreMax(6);
    m_sm_deployer_pavillon.setScoreMax(10);
    m_sm_activer_phare.setScoreMax(15);
    /*m_sm_recup_4_bouees_chemin.setScoreMax(12);
    m_sm_recup_bouees_distributeur.setScoreMax(13);
    m_sm_deposer_bouees_dans_port.setScoreMax(14);
    m_sm_arriver_a_bon_port.setScoreMax(15);*/
}

// ________________________________________________
// TODO : à voir sur le long terme si la couche de recopie des donées
// externes dans m_inputs_interface.xxxx est toujours nécessaire
// ou si le modèle ne peut pas utiliser directement Application.m_xxxxx.yyyy
void IA::step()
{
    m_inputs_interface.Tirette             = Application.m_capteurs.getTirette();

    m_inputs_interface.Convergence         = Application.m_asservissement.convergence_conf;
    m_inputs_interface.Convergence_rapide  = Application.m_asservissement.convergence_rapide;
    m_inputs_interface.ConvergenceRack     = Application.m_asservissement_chariot.isConverged();
    m_inputs_interface.X_robot             = Application.m_asservissement.X_robot;
    m_inputs_interface.Y_robot             = Application.m_asservissement.Y_robot;
    m_inputs_interface.angle_robot         = Application.m_asservissement.angle_robot;

    // Coordonnées du robot dans le repère absolue terrain (pour que ce soit valable pour les 2 couleurs d'équipe)
    if (m_datas_interface.couleur_equipe == SM_DatasInterface::EQUIPE_COULEUR_1) {
        m_inputs_interface.X_robot_terrain     = X_ROBOT_TERRAIN_INIT_COULEUR_1 + Application.m_asservissement.X_robot;
        m_inputs_interface.Y_robot_terrain     = Y_ROBOT_TERRAIN_INIT_COULEUR_1 + Application.m_asservissement.Y_robot;
        m_inputs_interface.angle_robot_terrain = Application.m_asservissement.angle_robot - ANGLE_ROBOT_TERRAIN_INIT_COULEUR_1;
    }
    else {
        m_inputs_interface.X_robot_terrain     = X_ROBOT_TERRAIN_INIT_COULEUR_2 - Application.m_asservissement.X_robot;
        m_inputs_interface.Y_robot_terrain     = Y_ROBOT_TERRAIN_INIT_COULEUR_2 - Application.m_asservissement.Y_robot;
        m_inputs_interface.angle_robot_terrain = Application.m_asservissement.angle_robot - ANGLE_ROBOT_TERRAIN_INIT_COULEUR_2;
        // Ramène l'angle entre [-Pi;Pi]
        if (m_inputs_interface.angle_robot_terrain > 3.14)   m_inputs_interface.angle_robot_terrain = m_inputs_interface.angle_robot_terrain - 6.28;
        if (m_inputs_interface.angle_robot_terrain <= -3.14) m_inputs_interface.angle_robot_terrain = m_inputs_interface.angle_robot_terrain + 6.28;
    }

    // Télémètres et obstacles
    m_inputs_interface.Telemetre_AVG       = Application.m_telemetres.getDistanceAVG();
    m_inputs_interface.Telemetre_AVD       = Application.m_telemetres.getDistanceAVD();
    m_inputs_interface.Telemetre_ARG       = Application.m_telemetres.getDistanceARG();
    m_inputs_interface.Telemetre_ARD       = Application.m_telemetres.getDistanceARD();

    //    inhibition forcée de la détection d'obstacle
    if (m_datas_interface.evit_inhibe_obstacle) {
        Application.m_detection_obstacles.inhibeDetection(true);
    }
    //    Tient compte de la position du robot sur le terrain pour inhiber les obstacles
    //      -> Trop proche des bordures -> inhibe la détection
    //      Inhibe soit les capteurs AV soit les capteurs AR en fonction de l'angle robot et de la proximité bordure si l'obstacle est détecté en dehors du terrain
    else if (m_datas_interface.evit_force_obstacle == false) {
        m_datas_interface.proximite_bordure_Xdroite = m_inputs_interface.X_robot_terrain > X_MAX_INTERDIT_DETECTION;
        m_datas_interface.proximite_bordure_Xgauche = m_inputs_interface.X_robot_terrain < X_MIN_INTERDIT_DETECTION;
        m_datas_interface.proximite_bordure_Ybasse = m_inputs_interface.Y_robot_terrain < Y_MIN_INTERDIT_DETECTION;
        m_datas_interface.proximite_bordure_Yhaute = m_inputs_interface.Y_robot_terrain > Y_MAX_INTERDIT_DETECTION;
        m_datas_interface.inhibe_detection_AV = false;
        m_datas_interface.inhibe_detection_AR = false;

        if (m_datas_interface.proximite_bordure_Ybasse) {
            if ( (m_inputs_interface.angle_robot_terrain >= -3.14) && (m_inputs_interface.angle_robot_terrain <= 0) ) {
               m_datas_interface.inhibe_detection_AV = true;
            }
            if ( (m_inputs_interface.angle_robot_terrain >= 0.) && (m_inputs_interface.angle_robot_terrain <= 3.14) ) {
               m_datas_interface.inhibe_detection_AR = true;
            }
        }
        if (m_datas_interface.proximite_bordure_Yhaute) {
            if ( (m_inputs_interface.angle_robot_terrain >= -3.14) && (m_inputs_interface.angle_robot_terrain <= 0) ) {
               m_datas_interface.inhibe_detection_AR = true;
            }
            if ( (m_inputs_interface.angle_robot_terrain >= 0.) && (m_inputs_interface.angle_robot_terrain <= 3.14) ) {
               m_datas_interface.inhibe_detection_AV = true;
            }
        }
        if (m_datas_interface.proximite_bordure_Xgauche) {
            if (    ((m_inputs_interface.angle_robot_terrain >= 1.57) && (m_inputs_interface.angle_robot_terrain <= 3.14) )
                 || ((m_inputs_interface.angle_robot_terrain <= -1.57) && (m_inputs_interface.angle_robot_terrain >= -3.14))
               ) {
               m_datas_interface.inhibe_detection_AV = true;
            }
            if (    ((m_inputs_interface.angle_robot_terrain >= 0) && (m_inputs_interface.angle_robot_terrain <= 1.57) )
                 || ((m_inputs_interface.angle_robot_terrain >= -1.57) && (m_inputs_interface.angle_robot_terrain <= 0.))
               ) {
               m_datas_interface.inhibe_detection_AR = true;
            }
        }
        if (m_datas_interface.proximite_bordure_Xdroite) {
            if (    ((m_inputs_interface.angle_robot_terrain >= 1.57) && (m_inputs_interface.angle_robot_terrain <= 3.14) )
                 || ((m_inputs_interface.angle_robot_terrain <= -1.57) && (m_inputs_interface.angle_robot_terrain >= -3.14))
               ) {
               m_datas_interface.inhibe_detection_AR = true;
            }
            if (    ((m_inputs_interface.angle_robot_terrain >= 0) && (m_inputs_interface.angle_robot_terrain <= 1.57) )
                 || ((m_inputs_interface.angle_robot_terrain >= -1.57) && (m_inputs_interface.angle_robot_terrain <= 0.))
               ) {
               m_datas_interface.inhibe_detection_AV = true;
            }
        }
        Application.m_detection_obstacles.inhibeDetectionAV(m_datas_interface.inhibe_detection_AV);
        Application.m_detection_obstacles.inhibeDetectionAR(m_datas_interface.inhibe_detection_AR);
    }
    else {
        Application.m_detection_obstacles.inhibeDetection(false);
    }

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

    // Mise en forme de données pour le modèle
    m_inputs_interface.FrontM_Convergence = m_inputs_interface.Convergence && !m_inputs_interface.Convergence_old;
    m_inputs_interface.Convergence_old = m_inputs_interface.Convergence;

    m_inputs_interface.FrontM_Convergence_rapide = m_inputs_interface.Convergence_rapide && !m_inputs_interface.Convergence_rapide_old;
    m_inputs_interface.Convergence_rapide_old = m_inputs_interface.Convergence_rapide;

    m_inputs_interface.FrontM_ConvergenceRack = m_inputs_interface.ConvergenceRack && !m_inputs_interface.ConvergenceRack_old;
    m_inputs_interface.ConvergenceRack_old = m_inputs_interface.ConvergenceRack;

    stepAllStateMachines();
}



