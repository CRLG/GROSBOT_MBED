#include "sm_inputsinterface.h"

SM_InputsInterface::SM_InputsInterface()
{
    init();
}


void SM_InputsInterface::init()
{
    dde_couleur_equipe = 1;
    couleur_equipe = dde_couleur_equipe;
    dde_test_actionneurs = 0;
    dde_choix_strategie = 0;
}
