#include "kmar.h"
#include "CGlobale.h"
#include "ConfigSpecifiqueCoupe.h"

CKmar::CKmar() :
    m_mouvement_init(this),
    m_mouvement_apprentissage_chariot(this),
    m_mouvement_prise_statette(this),
    m_mouvement_poser_statuette_sur_vitrine(this),
    m_mouvement_prendre_echantillon_au_sol(this),
    m_mouvement_deposer_echantillon_sur_galerie(this),
    m_mouvement_ranger_statuette_dans_robot(this),
    m_mouvement_lever_statuette_avant_deplacement(this)
{
    // En dur pour les essais
    m_servo_ax_id[0] = SERVO_AX_KMAR_AXIS_1;
    m_servo_ax_id[1] = SERVO_AX_KMAR_AXIS_2;
    m_servo_ax_id[2] = SERVO_AX_KMAR_AXIS_3;
    m_servo_ax_id[3] = SERVO_AX_KMAR_AXIS_4;

    m_servo_default_speed[0] = 80;
    m_servo_default_speed[1] = 80;
    m_servo_default_speed[2] = 80;
    m_servo_default_speed[3] = 80;
}

// __________________________________________________
void CKmar::start(int mouvement)
{
    switch(mouvement)
    {
    case MOUVEMENT_INIT :
        m_mouvement_en_cours = &m_mouvement_init;
        break;
    case MOUVEMENT_APPRENTISSAGE_CHARIOT :
        m_mouvement_en_cours = &m_mouvement_apprentissage_chariot;
        break;

    case MOUVEMENT_PRISE_STATUETTE :
        m_mouvement_en_cours = &m_mouvement_prise_statette;
        break;

    case MOUVEMENT_POSER_STATUETTE_SUR_VITRINE :
        m_mouvement_en_cours = &m_mouvement_poser_statuette_sur_vitrine;
        break;

    case MOUVEMENT_PRENDRE_ECHANTILLON_AU_SOL :
        m_mouvement_en_cours = &m_mouvement_prendre_echantillon_au_sol;
        break;

    case MOUVEMENT_DEPOSER_ECHANTILLON_SUR_GALERIE :
        m_mouvement_en_cours = &m_mouvement_deposer_echantillon_sur_galerie;
        break;

    case MOUVEMENT_RANGER_STATUETTE_DANS_ROBOT :
        m_mouvement_en_cours = &m_mouvement_ranger_statuette_dans_robot;
        break;

    case MOUVEMENT_LEVER_STATUETTE_AVANT_DEPLACEMENT :
        m_mouvement_en_cours = &m_mouvement_lever_statuette_avant_deplacement;

    default :
        break;
    }
    if (m_mouvement_en_cours) {
        m_num_mouvement_en_cours = mouvement;
        m_mouvement_en_cours->start();
    }
}

// __________________________________________________
bool CKmar::setAxisPosition(int axis, int pos, int speed)
{
    if (axis >=AXIS_NUMBER) return false;
    if (speed == -1) speed = m_servo_default_speed[axis];
    Application.m_servos_ax.setPositionSpeed(m_servo_ax_id[axis], pos, speed*m_speed_factor);
    return true;
}

// __________________________________________________
bool CKmar::setAxisSpeed(int axis, int speed)
{
    if (axis >=AXIS_NUMBER) return false;
    m_servo_default_speed[axis] = speed;
    return true;
}

// __________________________________________________
int CKmar::getAxisCount()
{
   return AXIS_NUMBER;
}

// __________________________________________________
bool CKmar::isMoving(int axis)
{
    if (axis >=AXIS_NUMBER) return false;
    int index= Application.m_servos_ax.servo_id_to_index_present(m_servo_ax_id[axis]);
    return Application.m_servos_ax.m_moving[index];
}

// __________________________________________________
int CKmar::getPosition(int axis)
{
    if (axis >=AXIS_NUMBER) return -1;
    int index= Application.m_servos_ax.servo_id_to_index_present(m_servo_ax_id[axis]);
    return Application.m_servos_ax.m_positions[index];
}

// __________________________________________________
void CKmar::arm(int axis)
{
    if (axis >=AXIS_NUMBER) return ;
    Application.m_servos_ax.enableTorque(m_servo_ax_id[axis], true);
}

// __________________________________________________
void CKmar::disarm(int axis)
{
    if (axis >=AXIS_NUMBER) return;
    Application.m_servos_ax.enableTorque(m_servo_ax_id[axis], false);
}

// __________________________________________________
int CKmar::getTime()
{
    return 0; //_Global_Timer.read_ms();
}

// __________________________________________________
void CKmar::delay_ms(int delay)
{
    // TODO
}

// __________________________________________________
void CKmar::catchObject()
{
    // TODO : voir quels actionneurs activer/désactiver pour prendre l'objet
    Application.m_power_electrobot.setOutput((dsPicPowerElectrobotBase::tSwitchOutput)POMPE, true);
    Application.m_power_electrobot.setOutput((dsPicPowerElectrobotBase::tSwitchOutput)ELECTROVANNE, false);
}

// __________________________________________________
void CKmar::releaseObject()
{
    // TODO : voir quels actionneurs activer/désactiver pour relâcher l'objet
    Application.m_power_electrobot.setOutput((dsPicPowerElectrobotBase::tSwitchOutput)POMPE, false);
    Application.m_power_electrobot.setOutput((dsPicPowerElectrobotBase::tSwitchOutput)ELECTROVANNE, false);
}

// __________________________________________________
bool CKmar::isObjectCatched()
{
    return Application.m_capteurs.getCapteurPressionKmar()>0.3f;
}
