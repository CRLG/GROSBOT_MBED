#include "kmar_RAMASSE.h"
#include "CKmar.h"


// ===========================================================
void CKmarMouvement_RAMASSE::step()
{
    const int default_speed = 250;

    if (!m_kmar) return;
    if (isFinished()) return;

    switch(m_state)
    {
    case MOVEMENT_START :
        if (onEntry()) {
            m_kmar->setAxisSpeed(CKmar::AXIS_1, default_speed*2);
            m_kmar->setAxisSpeed(CKmar::AXIS_2, default_speed/2);
            m_kmar->setAxisSpeed(CKmar::AXIS_3, default_speed);
            m_kmar->setAxisSpeed(CKmar::AXIS_4, default_speed);

            m_kmar->setAxisPosition(CKmar::AXIS_1, 223);
            m_kmar->setAxisPosition(CKmar::AXIS_2, 170);
            m_kmar->setAxisPosition(CKmar::AXIS_3, 680);
            m_kmar->setAxisPosition(CKmar::AXIS_4, 320);
        }
        else {
            if (!m_kmar->isMoveInProgress()) gotoNextState();
        }

        if (onExit()) {  }
        break;

    case 1 :
        if (onEntry()) {
            m_kmar->setAxisPosition(CKmar::AXIS_1, 163);
            m_kmar->setAxisPosition(CKmar::AXIS_2, 295);
            m_kmar->setAxisPosition(CKmar::AXIS_3, 821);
            m_kmar->setAxisPosition(CKmar::AXIS_4, 731);
        }
        else {
            if (!m_kmar->isMoveInProgress()) gotoNextState();
        }

        if (onExit()) {  }
        break;

    case 2 :
        if (onEntry()) {
            m_kmar->setAxisPosition(CKmar::AXIS_1, 640);
            m_kmar->setAxisPosition(CKmar::AXIS_2, 681);
            m_kmar->setAxisPosition(CKmar::AXIS_3, 429);
            m_kmar->setAxisPosition(CKmar::AXIS_4, 427);
        }
        else {
            if (!m_kmar->isMoveInProgress()) gotoNextState();
        }
        if (onExit()) {  }
        break;
    case 3 : // Pause
        if (onEntry()) { }

        gotoStateAfter(m_state+1, 500);

        if (onExit()) {  }
        break;

    case 4 :
        if (onEntry()) {
            m_kmar->setAxisPosition(CKmar::AXIS_1, 512);
            m_kmar->setAxisPosition(CKmar::AXIS_2, 512);
            m_kmar->setAxisPosition(CKmar::AXIS_3, 512);
            m_kmar->setAxisPosition(CKmar::AXIS_4, 512);
        }
        else {
            if (!m_kmar->isMoveInProgress()) gotoNextState();
        }

        if (onExit()) {  }
        break;

    case MOVEMENT_FINISHED :
    default:
        break;
    }
}

