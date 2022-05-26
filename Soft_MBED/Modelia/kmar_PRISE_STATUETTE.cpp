#include "kmar_PRISE_STATUETTE.h"
#include "kmar.h"

// ===========================================================
void CKmarMouvement_PRISE_STATUETTE::step()
{
    const int default_speed = 250;

    if (!m_kmar) return;
    if (isFinished()) return;

    switch(m_state)
    {
    case MOVEMENT_START :
        if (onEntry()) {
            m_kmar->setAxisSpeed(CKmar::AXIS_1, default_speed);
            m_kmar->setAxisSpeed(CKmar::AXIS_2, default_speed);
            m_kmar->setAxisSpeed(CKmar::AXIS_3, default_speed);
            m_kmar->setAxisSpeed(CKmar::AXIS_4, default_speed);
        }

        m_kmar->catchObject();  // active la pompe pendant quelques msec pour mettre le circuit sous pression
        gotoStateAfter(1, 800);

        if (onExit()) {  }
        break;

    case 1 :
        if (onEntry()) {
            m_kmar->setAxisPosition(CKmar::AXIS_4, 96);
        }
        else {
            if (!m_kmar->isMoveInProgress()) gotoNextState();
        }

        if (onExit()) {  }
        break;

    case 2 :
        if (onEntry()) {
            m_kmar->setAxisPosition(CKmar::AXIS_3, 625);
        }
        else {
            if (!m_kmar->isMoveInProgress()) gotoNextState();
        }
        if (onExit()) {  }
        break;
    case 3 :
        if (onEntry()) {
            m_kmar->setAxisPosition(CKmar::AXIS_2, 639);
            m_kmar->setAxisPosition(CKmar::AXIS_1, 691);
        }
        else {
            if (!m_kmar->isMoveInProgress()) gotoFinish();
        }
        if (onExit()) {  }
        break;

    case MOVEMENT_FINISHED :
    default:
        break;
    }
}
