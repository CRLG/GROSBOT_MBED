#ifndef IA_H
#define IA_H

#include "iabase.h"
#include "sm_autotest.h"
#include "sm_activerphare.h"
#include "sm_deployerpavillon.h"
#include "sm_deposerboueesdansport.h"
#include "sm_detecternordsud.h"
#include "sm_recup2boueeszonedepart.h"
#include "sm_recup4boueeschemin.h"
#include "sm_recupboueesdistributeur.h"
#include "sm_arriverabonport.h"
#include "sm_debuginterface.h"

class IA : public IABase
{
public:
    IA();

    // States machines
    SM_Autotest                 m_sm_autotest;
    SM_ActiverPhare             m_sm_activer_phare;
    SM_DeployerPavillon         m_sm_deployer_pavillon;
    SM_DeposerBoueesDansPort    m_sm_deposer_bouees_dans_port;
    SM_DetecterNordSud          m_sm_detecter_nord_sud;
    SM_Recup2BoueesZoneDepart   m_sm_recup_2_bouees_zone_depart;
    SM_Recup4BoueesChemin       m_sm_recup_4_bouees_chemin;
    SM_RecupBoueesDistributeur  m_sm_recup_bouees_distributeur;
    SM_ArriverABonPort          m_sm_arriver_a_bon_port;

    void step();
    void init();

    void setStrategie(unsigned char strategie);
    void setMaxScores();
};

#endif // IA_H
