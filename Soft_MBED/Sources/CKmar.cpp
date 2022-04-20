#include "CKmar.h"
#include "CGlobale.h"
#include "ConfigSpecifiqueCoupe.h"

CKmar::CKmar() :
    m_mouvement_init(this),
    m_mouvement_ramasse(this)
{
    // En dur pour les essais
    m_servo_ax_id[0] = 1;
    m_servo_ax_id[1] = 2;
    m_servo_ax_id[2] = 3;
    m_servo_ax_id[3] = 4;

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
    case MOUVEMENT_RAMASSE :
        m_mouvement_en_cours = &m_mouvement_ramasse;
        break;

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
    return _Global_Timer.read_ms();
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
    Application.m_power_electrobot.setOutput((PowerElectrobot::tSwitchOutput)POMPE_AV, true);
}

// __________________________________________________
void CKmar::releaseObject()
{
    // TODO : voir quels actionneurs activer/désactiver pour relâcher l'objet
    Application.m_power_electrobot.setOutput((PowerElectrobot::tSwitchOutput)POMPE_AV, false);
}

// __________________________________________________
bool CKmar::isObjectCatched()
{
    // TODO : faire le lien avec le capteur de pression
    return false; // bouchon pour renvoyer quelque chose
}
