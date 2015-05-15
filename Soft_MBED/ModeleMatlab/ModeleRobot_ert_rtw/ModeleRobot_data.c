/*
 * File: ModeleRobot_data.c
 *
 * Real-Time Workshop code generated for Simulink model ModeleRobot.
 *
 * Model version                        : 1.1501
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Fri May 15 08:09:39 2015
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Fri May 15 08:09:39 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objective: Efficiency
 * Validation result: Passed (9), Warning (1), Error (0)
 */

#include "ModeleRobot.h"
#include "ModeleRobot_private.h"

/* Block parameters (auto storage) */
Parameters_ModeleRobot ModeleRobot_P = {
  15.0,                                /* Expression: 15
                                        * Referenced by: '<S2>/SeuilDistance'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Relay'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S2>/Relay'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Relay'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S2>/Relay'
                                        */
  0.0,                                 /* Expression: vinit
                                        * Referenced by: '<S17>/Delay Input1'
                                        */
  1.0,                                 /* Expression: const
                                        * Referenced by: '<S16>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  1.0,                                 /* Expression: const
                                        * Referenced by: '<S7>/Constant'
                                        */
  0.0,                                 /* Expression: vinit
                                        * Referenced by: '<S8>/Delay Input1'
                                        */
  2.0,                                 /* Expression: const
                                        * Referenced by: '<S10>/Constant'
                                        */
  0.0,                                 /* Expression: vinit
                                        * Referenced by: '<S11>/Delay Input1'
                                        */
  0.0,                                 /* Expression: DEBUG_ASCENSEUR
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  1.0,                                 /* Expression: DEBUG_BOUT_STRATEGIE
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  0.0,                                 /* Expression: DEBUG_TORCHE
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  1.0,                                 /* Expression: DEGAGE_PREMIER_GOBELET
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  0.0,                                 /* Expression: EQUIPE_JAUNE
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  1.0,                                 /* Expression: EQUIPE_VERTE
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  1833.0,                              /* Expression: KMAR_POSITION_AU_DESSUS_SPOT_AVEC_SPOT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  1385.0,                              /* Expression: KMAR_POSITION_AU_DESSUS_SPOT_SANS_SPOT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  220.0,                               /* Expression: KMAR_POSITION_DEPART
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  2476.0,                              /* Expression: KMAR_POSITION_HAUT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  810.0,                               /* Expression: KMAR_POSITION_SPOT_BAS
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  0.0,                                 /* Expression: MAX_SPEED_SERVOS
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  3.0,                                 /* Expression: MOTEUR_ASCENSEUR
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  4.0,                                 /* Expression: MOTEUR_DISTRIBUTEUR
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  5.0,                                 /* Expression: MOTEUR_NON_DEFINI
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  6.0,                                 /* Expression: MOTEUR_SOUFFLEUR
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  3.1415926535897931E+000,             /* Expression: PI
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  13.0,                                /* Expression: SERVO_BRAS
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  147.0,                               /* Expression: SERVO_BRAS_FERME
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  55.0,                                /* Expression: SERVO_BRAS_OUVERT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  15.0,                                /* Expression: SERVO_CENTREUR_D
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  86.0,                                /* Expression: SERVO_CENTREUR_D_CENTRE_SPOT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  130.0,                               /* Expression: SERVO_CENTREUR_D_FERME
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  21.0,                                /* Expression: SERVO_CENTREUR_D_OUVERT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  14.0,                                /* Expression: SERVO_CENTREUR_G
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  62.0,                                /* Expression: SERVO_CENTREUR_G_CENTRE_SPOT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  27.0,                                /* Expression: SERVO_CENTREUR_G_FERME
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  134.0,                               /* Expression: SERVO_CENTREUR_G_OUVERT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  16.0,                                /* Expression: SERVO_PINCE_D
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  41.0,                                /* Expression: SERVO_PINCE_D_ENTRE_OUVERT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  120.0,                               /* Expression: SERVO_PINCE_D_FERME
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  110.0,                               /* Expression: SERVO_PINCE_D_LACHE_BALLE
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  1.0,                                 /* Expression: SERVO_PINCE_D_OUVERT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  95.0,                                /* Expression: SERVO_PINCE_D_PRISE_GOBELET
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  17.0,                                /* Expression: SERVO_PINCE_G
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  155.0,                               /* Expression: SERVO_PINCE_G_ENTRE_OUVERT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  80.0,                                /* Expression: SERVO_PINCE_G_FERME
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  104.0,                               /* Expression: SERVO_PINCE_G_LACHE_BALLE
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  205.0,                               /* Expression: SERVO_PINCE_G_OUVERT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  101.0,                               /* Expression: SERVO_PINCE_G_PRISE_GOBELET
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  19.0,                                /* Expression: SERVO_RECOLTEURS
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  60.0,                                /* Expression: SERVO_RECOLTEURS_FERME
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  191.0,                               /* Expression: SERVO_RECOLTEURS_OUVERT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  20.0,                                /* Expression: SERVO_VOLET
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  60.0,                                /* Expression: SERVO_VOLET_OUVERT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  0.02,                                /* Expression: Te
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant1'
                                        */
  1,                                   /* Computed Parameter: SFunction_p7
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  1,                                   /* Computed Parameter: SFunction_p14
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  1,                                   /* Computed Parameter: SFunction_p48
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  1U,                                  /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S2>/Switch'
                                        */
  1U                                   /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S2>/Switch1'
                                        */
};

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
