#include "ia.h"

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
