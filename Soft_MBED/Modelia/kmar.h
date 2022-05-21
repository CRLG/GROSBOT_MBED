#ifndef CKMAR_H
#define CKMAR_H

#include "CKmarBase.h"
#include "kmar_INIT.h"
#include "kmar_APPRENTISSAGE_CHARIOT.h"
#include "kmar_PRENDRE_ECHANTILLON_AU_SOL.h"
#include "kmar_DEPOSER_ECHANTILLON_SUR_GALERIE.h"
#include "kmar_PRISE_STATUETTE.h"
#include "kmar_POSER_STATUETTE_SUR_VITRINE.h"
#include "kmar_RANGER_STATUETTE_DANS_ROBOT.h"

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

    /*virtual*/void catchObject();
    /*virtual*/void releaseObject();
    /*virtual*/bool isObjectCatched();

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

    CKmarMouvement_INIT                             m_mouvement_init;
    CKmarMouvement_APPRENTISSAGE_CHARIOT            m_mouvement_apprentissage_chariot;
    CKmarMouvement_PRISE_STATUETTE                  m_mouvement_prise_statette;
    CKmarMouvement_POSER_STATUETTE_SUR_VITRINE      m_mouvement_poser_statuette_sur_vitrine;
    CKmarMouvement_PRENDRE_ECHANTILLON_AU_SOL       m_mouvement_prendre_echantillon_au_sol;
    CKmarMouvement_DEPOSER_ECHANTILLON_SUR_GALERIE  m_mouvement_deposer_echantillon_sur_galerie;
    CKmarMouvement_RANGER_STATUETTE_DANS_ROBOT      m_mouvement_ranger_statuette_dans_robot;
};

#endif // CKMAR_H
