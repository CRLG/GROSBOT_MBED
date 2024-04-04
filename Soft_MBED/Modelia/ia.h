#ifndef IA_H
#define IA_H

#include "iabase.h"
#include "sm_autotest.h"

#include "sm_retourzonedepart.h"
#include "sm_chasseneige.h"
#include "sm_prendreplantespreszonedepart.h"
#include "sm_debuginterface.h"


class IA : public IABase
{
public:
    IA();

    // States machines

    void step();
    void init();
    void match_started();
    void match_finished();

    void setStrategie(unsigned char strategie);
    void setMaxScores();
};

#endif // IA_H
