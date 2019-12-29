#include "sm_datasinterface.h"
#include "sm_sequenceur.h"

SM_DatasInterface::SM_DatasInterface()
{
    init();
}


void SM_DatasInterface::init()
{
    //evit_comportement_retour_evitement = RETOUR_EVIT_RECHERCHE_MEILLEUR_ALGO;
    evit_comportement_retour_evitement = SM_Sequenceur::RETOUR_EVIT_REPRENDS_MISSION_INTERROMPUE;
    TempsMatch = -1;
}
