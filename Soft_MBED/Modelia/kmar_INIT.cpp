#include "kmar_INIT.h"
#include "CKmar.h"

// ===========================================================
void CKmarMouvement_INIT::step()
{
    const int default_speed = 250;
    if (!m_kmar) return;
    if (isFinished()) return;

    switch(m_state)
    {
    // __________________________________________________
    case MOVEMENT_START :
        if (onEntry()) {
            m_kmar->setAxisSpeed(CKmar::AXIS_1, default_speed);
            m_kmar->setAxisSpeed(CKmar::AXIS_2, default_speed);
            m_kmar->setAxisSpeed(CKmar::AXIS_3, default_speed);
            m_kmar->setAxisSpeed(CKmar::AXIS_4, default_speed);
            m_kmar->setAxisPosition(CKmar::AXIS_1, 250, default_speed/4);
            //m_kmar->setAxisPosition(CKmar::AXIS_2, 700);
        }
        else {
            gotoStateIfNear(m_state+1, CKmar::AXIS_1, 325, 90);
            gotoStateIfTrue(m_state+1, !m_kmar->isMoving(CKmar::AXIS_1));
        }

        if (onExit()) {  }
        break;
        // __________________________________________________
    case 1 :
        if (onEntry()) {
            m_kmar->setAxisPosition(CKmar::AXIS_2, 160, default_speed/3);
        }
        else {
            //gotoStateIfTrue(m_state+1, !m_kmar->isMoving(CKmar::AXIS_2));
            gotoStateIfNear(m_state+1, CKmar::AXIS_2, 160, 90);

        }

        //gotoStateAfter(m_state+1, 3000);

        if (onExit()) {  }
        break;
        // __________________________________________________
    case 2 :
        if (onEntry()) {
            m_kmar->setAxisPosition(CKmar::AXIS_3, 400, default_speed*3);
        }
        else {
            gotoStateIfTrue(m_state+1, !m_kmar->isMoveInProgress());
        }
        //gotoStateAfter(m_state+1, 3000);

        if (onExit()) {  }
        break;
        // __________________________________________________
    case 3 :
        if (onEntry()) {
            m_kmar->setAxisPosition(CKmar::AXIS_4, 400);
        }
        else {
            gotoStateIfTrue(m_state+1, !m_kmar->isMoveInProgress()); // Tous les servos sont en position
        }
        //gotoStateAfter(m_state+1, 3000);

        if (onExit()) {  }
        break;
        // __________________________________________________
    case 4 : // Pause
        if (onEntry()) { }

        gotoStateAfter(m_state+1, 2000);

        if (onExit()) {  }
        break;
        // __________________________________________________
    case 5 :
        if (onEntry()) {
            m_kmar->setAxisPosition(CKmar::AXIS_1, 225);
        }
        else {
            gotoStateIfNear(m_state+1, CKmar::AXIS_1, 225, 50);
        }
        //gotoStateAfter(m_state+1, 3000);

        if (onExit()) {  }
        break;
        // __________________________________________________
    case 6 :
        if (onEntry()) {
            m_kmar->setAxisPosition(CKmar::AXIS_2, 512);
        }
        else {
            gotoStateIfTrue(m_state+1, !m_kmar->isMoving(CKmar::AXIS_2));
        }
        //gotoStateAfter(m_state+1, 3000);

        if (onExit()) {  }
        break;
        // __________________________________________________
    case 7 :
        if (onEntry()) {
            m_kmar->setAxisPosition(CKmar::AXIS_3, 512, default_speed/5);
        }
        else {
            gotoStateIfTrue(m_state+1, !m_kmar->isMoving(CKmar::AXIS_3));
        }
        //gotoStateAfter(m_state+1, 3000);

        if (onExit()) {  }
        break;
        // __________________________________________________
    case 8 :
        if (onEntry()) {
            m_kmar->setAxisPosition(CKmar::AXIS_4, 512);
        }
        else {
            gotoStateIfTrue(m_state+1, !m_kmar->isMoveInProgress());
        }
        //gotoStateAfter(m_state+1, 3000);

        if (onExit()) {  }
        break;
        // __________________________________________________
    case 9 : // Pause
        if (onEntry()) { }

        gotoStateAfter(m_state+1, 700);

        if (onExit()) {  }
        break;
        // __________________________________________________
    case 10 :
        if (onEntry()) {
            m_kmar->setAxisPosition(CKmar::AXIS_1, 512, 60);
        }
        else {
            gotoStateIfTrue(m_state+1, !m_kmar->isMoveInProgress());
        }
        //gotoStateAfter(m_state+1, 3000);

        if (onExit()) {  }
        break;
        // __________________________________________________
    case 11 :
        if (onEntry()) {
            m_kmar->disarm();
        }
        gotoStateAfter(MOVEMENT_FINISHED, 3000);

        if (onExit()) {  }
        break;


    case MOVEMENT_FINISHED :
    default:
        break;
    }
}


