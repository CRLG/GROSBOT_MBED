#include "kmar_LEVER_STATUETTE_AVANT_DEPLACEMENT.h"
#include "kmar.h"

// ===========================================================
void CKmarMouvement_LEVER_STATUETTE_AVANT_DEPLACEMENT::step()
{
    const int default_speed = 250;
    int target_pos;

    if (!m_kmar) return;
    if (isFinished()) return;

    switch(m_state)
    {
    case MOVEMENT_START :
        target_pos = 694;
        if (onEntry()) {
            m_kmar->setAxisSpeed(CKmar::AXIS_1, default_speed);
            m_kmar->setAxisSpeed(CKmar::AXIS_2, default_speed);
            m_kmar->setAxisSpeed(CKmar::AXIS_3, default_speed);
            m_kmar->setAxisSpeed(CKmar::AXIS_4, default_speed);

            m_kmar->setAxisPosition(CKmar::AXIS_1, target_pos);
        }
        gotoStateIfNear(m_state+1, CKmar::AXIS_1, target_pos, 50, 1000);
        if (onExit()) {  }
        break;

    case 1 :
        target_pos = 700;
        if (onEntry()) {
            m_kmar->setAxisPosition(CKmar::AXIS_2, target_pos);
        }
        gotoStateIfNear(m_state+1, CKmar::AXIS_2, target_pos, 50, 1000);
        if (onExit()) {  }
        break;

    case 2 :
        target_pos = 620;
        if (onEntry()) {
            m_kmar->setAxisPosition(CKmar::AXIS_3, target_pos);
        }
        gotoStateIfNear(m_state+1, CKmar::AXIS_3, target_pos, 50, 1000);
        if (onExit()) {  }
        break;
    case 3 :
        target_pos = 108;
        if (onEntry()) {
            m_kmar->setAxisPosition(CKmar::AXIS_4, target_pos);
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
