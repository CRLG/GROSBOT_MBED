#ifndef IA_H
#define IA_H

#include "iabase.h"
#include "sm_autotest.h"

#include "sm_retourzonedepart.h"
#include "sm_chasseneige.h"
#include "sm_prendreplantespreszonedepart.h"
#include "sm_prendrepotspreszonedepart.h"
#include "sm_ramenerpotzonepami.h"
#include "sm_tournerpanneauxsolaires.h"
#include "sm_sauvegardeplantes.h"
#include "sm_debuginterface.h"

class IA : public IABase
{
public:
    IA();

    // States machines
    SM_Autotest                         m_sm_autotest;
    SM_ChasseNeige                      m_sm_chasse_neige;
    SM_PrendrePlantesPresZoneDepart     m_sm_prendre_plantes_pres_zone_depart;
    SM_PrendrePotsPresZoneDepart        m_sm_prendre_pots_pres_zone_depart;
    SM_RamenerPotZonePAMI               m_sm_ramener_pot_zone_pami;
    SM_TournerPanneauxSolaires          m_sm_tourner_panneaux_solaires;
    SM_SauvegardePlantes                m_sauvegarde_plantes;
    SM_RetourZoneDepart                 m_sm_retour_zone_depart;

    void step();
    void init();
    void match_started();
    void match_finished();

    void setStrategie(unsigned char strategie);
    void setMaxScores();
};

#endif // IA_H
