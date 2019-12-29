#ifndef SM_INPUTSINTERFACE_H
#define SM_INPUTSINTERFACE_H


class SM_InputsInterface
{
public:
    SM_InputsInterface();

    void init();

    int Tirette;
    bool obstacle_AVD;
    bool obstacle_AVG;
    bool obstacle_ARD;
    bool obstacle_ARG;
    bool obstacleDetecte;
    bool Convergence;
    float TE_Modele;

    unsigned int dde_couleur_equipe=1;
    unsigned int couleur_equipe;
    unsigned int dde_test_actionneurs = 0;
    unsigned int dde_choix_strategie = 0;


    // Evitement
    unsigned char evit_choix_strategie;


};

#endif // SM_INPUTSINTERFACE_H
