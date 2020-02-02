#ifndef SM_INPUTSINTERFACE_H
#define SM_INPUTSINTERFACE_H


class SM_InputsInterface
{
public:
    SM_InputsInterface();

    void init();

    float TE_Modele;

    int Tirette;

    // En provenance de l'écran
    unsigned int dde_couleur_equipe;
    unsigned int couleur_equipe;
    unsigned int dde_test_actionneurs;
    unsigned int dde_choix_strategie;

    // Détection d'obstacles
    bool obstacle_AVD;
    bool obstacle_AVG;
    bool obstacle_ARD;
    bool obstacle_ARG;
    bool obstacleDetecte;
    float Telemetre_AVD;
    float Telemetre_AVG;
    float Telemetre_ARD;
    float Telemetre_ARG;

    // Evitement d'obstacles
    unsigned char evit_choix_strategie;

    // Sortie de l'asservissement
    float X_robot;
    float Y_robot;
    float angle_robot;

    bool Convergence;
    bool Convergence_old;
    bool FrontM_Convergence;
    bool Convergence_rapide;
    bool Convergence_rapide_old;
    bool FrontM_Convergence_rapide;
    bool ConvergenceRack;
    bool ConvergenceRack_old;
    bool FrontM_ConvergenceRack;


};

#endif // SM_INPUTSINTERFACE_H
