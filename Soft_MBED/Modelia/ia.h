#ifndef IA_H
#define IA_H

#include "iabase.h"
#include "sm_autotest.h"
#include "sm_recupechantillonzonedepart.h"
#include "sm_recupstatuette.h"
#include "sm_recup3echantillonsdistrib.h"
#include "sm_deposerstatuetteactivervitrine.h"
#include "sm_deposerechantillonsgalerieexpo.h"
#include "sm_retourzonedepart.h"
#include "sm_deposerechantillonscampement.h"

#include "sm_debuginterface.h"


class IA : public IABase
{
public:
    IA();

    // States machines
    SM_Autotest                         m_sm_autotest;
    SM_RecupEchantillonZoneDepart       m_sm_recup_echantillon_zone_depart;
    SM_RecupStatuette                   m_sm_recup_statuette;
    SM_Recup3EchantillonsDistrib        m_sm_recup_3_echantillons_distrib;
    SM_DeposerStatuetteActiverVitrine   m_sm_deposer_statuette_activer_vitrine;
    SM_DeposerEchantillonsGalerieExpo   m_sm_deposer_echantillons_galerie_expo;
    SM_RetourZoneDepart                 m_sm_retour_zone_depart;
    SM_DeposerEchantillonsCampement     m_sm_deposer_echantillons_campement;

    void step();
    void init();

    void setStrategie(unsigned char strategie);
    void setMaxScores();
};

#endif // IA_H
