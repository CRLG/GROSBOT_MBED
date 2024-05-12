#ifndef SM_INPUTSINTERFACE_H
#define SM_INPUTSINTERFACE_H

#include "Lidar_utils.h"

class SM_InputsInterface
{
public:
    SM_InputsInterface();

    void init();

    float TE_Modele;

    int Tirette;

    // En provenance de l'écran
    unsigned int dde_couleur_equipe;
    unsigned int dde_test_actionneurs;

    // Détection d'obstacles
    bool obstacle_AVD;
    bool obstacle_AVG;
    bool obstacle_ARD;
    bool obstacle_ARG;
    bool obstacleDetecte;
    bool obstacleDetecte_non_filtre;
    float Telemetre_AVD;
    float Telemetre_AVG;
    float Telemetre_ARD;
    float Telemetre_ARG;
    float Telemetre_ARDCentre;
    float Telemetre_ARGCentre;

    // Lidar
    unsigned char m_lidar_status;
    LidarUtils::tLidarObstacles m_lidar_obstacles;

    // Sortie de l'asservissement
    float X_robot;
    float Y_robot;
    float angle_robot;

    float X_robot_terrain;  // Coordonnées absolue dans le repère terrain
    float Y_robot_terrain;
    float angle_robot_terrain;

    bool Convergence;
    bool Convergence_old;
    bool FrontM_Convergence;
    bool Convergence_rapide;
    bool Convergence_rapide_old;
    bool FrontM_Convergence_rapide;
    bool ConvergenceRack;
    bool ConvergenceRack_old;
    bool FrontM_ConvergenceRack;

    bool ConvergenceKmar;

    //en provenance de la rasp
    float m_distance_balise1;
    float m_distance_balise2;
    int m_nord;
    int m_sud;
};

#endif // SM_INPUTSINTERFACE_H
