#ifndef CKMAR_H
#define CKMAR_H

#include "CKmarBase.h"
#include "kmar_INIT.h"
#include "kmar_RAMASSE.h"

class CKmar : public CKmarBase
{
public:
    CKmar();

    /*virtual*/bool setAxisPosition(int axis, int pos, int speed=-1);
    /*virtual*/bool setAxisSpeed(int axis, int speed);
    /*virtual*/int getAxisCount();
    /*virtual*/bool isMoving(int axis);
    /*virtual*/int getPosition(int axis);
    /*virtual*/void arm(int axis);
    /*virtual*/void disarm(int axis);
    /*virtual*/int getTime();
    /*virtual*/void delay_ms(int delay);
    /*virtual*/void start(int mouvement);

    typedef enum {
        MOUVEMENT_INIT = 0,
        MOUVEMENT_RAMASSE
    }tMouvements;

    //! ATTENTION : Dans les fonctions, le numéro d'axe commence à "0"
    //! Ex : isMoving(0) interroge le 1er axe du Kmar (équivaut à isMoving(AXIS_1))
    typedef enum {
        AXIS_1 = 0,
        AXIS_2,
        AXIS_3,
        AXIS_4,
        // _______________
        AXIS_NUMBER
    }tAxisNumber;

    unsigned char m_servo_ax_id[AXIS_NUMBER];
    unsigned int m_servo_default_speed[AXIS_NUMBER];

    CKmarMouvement_INIT         m_mouvement_init;
    CKmarMouvement_RAMASSE      m_mouvement_ramasse;
};

#endif // CKMAR_H
