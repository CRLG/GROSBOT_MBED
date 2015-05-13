/*
 * File: ModeleRobot.h
 *
 * Real-Time Workshop code generated for Simulink model ModeleRobot.
 *
 * Model version                        : 1.1436
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Wed May 13 20:14:58 2015
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Wed May 13 20:14:59 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objective: Efficiency
 * Validation result: Passed (9), Warning (1), Error (0)
 */

#ifndef RTW_HEADER_ModeleRobot_h_
#define RTW_HEADER_ModeleRobot_h_
#ifndef ModeleRobot_COMMON_INCLUDES_
# define ModeleRobot_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* ModeleRobot_COMMON_INCLUDES_ */

#include "ModeleRobot_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((void*) 0)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((void) 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/* Block states (auto storage) for system '<S1>/isFrontMontantMvtBloque' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S10>/Delay Input1' */
} rtDW_isFrontMontantMvtBloque_Mo;

/* Block signals (auto storage) */
typedef struct {
  real_T ConsigneX;                    /* '<Root>/COMPORTEMENT' */
  real_T ConsigneY;                    /* '<Root>/COMPORTEMENT' */
  real_T DdeMvtXY;                     /* '<Root>/COMPORTEMENT' */
  real_T ConsigneTeta;                 /* '<Root>/COMPORTEMENT' */
  real_T ConsigneVitesseAngle;         /* '<Root>/COMPORTEMENT' */
  real_T ConsigneDistance;             /* '<Root>/COMPORTEMENT' */
  real_T ConsigneVitesseDistance;      /* '<Root>/COMPORTEMENT' */
  real_T DdeMvtDistanceAngle;          /* '<Root>/COMPORTEMENT' */
  real_T CommandeManuelleG;            /* '<Root>/COMPORTEMENT' */
  real_T CommandeManuelleD;            /* '<Root>/COMPORTEMENT' */
  real_T DdeMvtManuel;                 /* '<Root>/COMPORTEMENT' */
  real_T EtatLed1;                     /* '<Root>/COMPORTEMENT' */
  real_T EtatLed2;                     /* '<Root>/COMPORTEMENT' */
  real_T EtatLed3;                     /* '<Root>/COMPORTEMENT' */
  real_T EtatLed4;                     /* '<Root>/COMPORTEMENT' */
  real_T DdeRecalagePosition[4];       /* '<Root>/COMPORTEMENT' */
  real_T ResetCodeurAscenseur;         /* '<Root>/COMPORTEMENT' */
  real_T ResetCodeurBarillet;          /* '<Root>/COMPORTEMENT' */
  real_T DdeMvtXYTeta;                 /* '<Root>/COMPORTEMENT' */
  real_T CommandeMoteur[8];            /* '<Root>/COMPORTEMENT' */
  real_T CommandeServo[20];            /* '<Root>/COMPORTEMENT' */
  real_T SpeedServo[20];               /* '<Root>/COMPORTEMENT' */
  real_T RelacheServo[20];             /* '<Root>/COMPORTEMENT' */
  real_T ConvergenceMouvement;         /* '<Root>/COMPORTEMENT' */
  boolean_T LogicalOperator_j;         /* '<S4>/Logical Operator' */
} BlockIO_ModeleRobot;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S7>/Delay Input1' */
  real_T DureeMatch;                   /* '<Root>/COMPORTEMENT' */
  real_T CompteurTimeoutMvt;           /* '<Root>/COMPORTEMENT' */
  real_T invMouv;                      /* '<Root>/COMPORTEMENT' */
  real_T finHomologation;              /* '<Root>/COMPORTEMENT' */
  real_T TempoInit;                    /* '<Root>/COMPORTEMENT' */
  real_T TempoMot;                     /* '<Root>/COMPORTEMENT' */
  real_T ObstacleDetecte;              /* '<Root>/COMPORTEMENT' */
  real_T TempoImage;                   /* '<Root>/COMPORTEMENT' */
  real_T TempoTestActionneurs;         /* '<Root>/COMPORTEMENT' */
  real_T EvitementEnCours;             /* '<Root>/COMPORTEMENT' */
  real_T x_old;                        /* '<Root>/COMPORTEMENT' */
  real_T y_old;                        /* '<Root>/COMPORTEMENT' */
  real_T local_Tempo;                  /* '<Root>/COMPORTEMENT' */
  real_T inhibeObstacle;               /* '<Root>/COMPORTEMENT' */
  uint8_T is_active_c1_ModeleRobot;    /* '<Root>/COMPORTEMENT' */
  uint8_T is_active_COMPORTEMENT_ROBOT;/* '<Root>/COMPORTEMENT' */
  uint8_T is_COMPORTEMENT_ROBOT;       /* '<Root>/COMPORTEMENT' */
  uint8_T is_active_FONCTIONS_GLOBALES_DE;/* '<Root>/COMPORTEMENT' */
  uint8_T is_active_FONCTIONS_GLOBALES_CO;/* '<Root>/COMPORTEMENT' */
  uint8_T is_active_FONCTIONS_GLOBALES__j;/* '<Root>/COMPORTEMENT' */
  uint8_T is_active_ACTIONNEURS_REPOS; /* '<Root>/COMPORTEMENT' */
  uint8_T is_ACTIONNEURS_REPOS;        /* '<Root>/COMPORTEMENT' */
  uint8_T is_active_CHOIX_EQUIPE;      /* '<Root>/COMPORTEMENT' */
  uint8_T is_CHOIX_EQUIPE;             /* '<Root>/COMPORTEMENT' */
  uint8_T is_active_RECALAGE;          /* '<Root>/COMPORTEMENT' */
  uint8_T is_active_FONCTIONS_GLOBALES__m;/* '<Root>/COMPORTEMENT' */
  uint8_T is_active_TESTS_ACTIONNEUR;  /* '<Root>/COMPORTEMENT' */
  uint8_T is_TESTS_ACTIONNEUR;         /* '<Root>/COMPORTEMENT' */
  uint8_T is_active_FONCTIONS_GLOBALES_DI;/* '<Root>/COMPORTEMENT' */
  uint8_T is_FIN_MATCH;                /* '<Root>/COMPORTEMENT' */
  uint8_T is_active_STRATEGIE;         /* '<Root>/COMPORTEMENT' */
  uint8_T is_STRATEGIE;                /* '<Root>/COMPORTEMENT' */
  uint8_T is_STRATEGIE1;               /* '<Root>/COMPORTEMENT' */
  uint8_T was_STRATEGIE1;              /* '<Root>/COMPORTEMENT' */
  uint8_T is_DEMO;                     /* '<Root>/COMPORTEMENT' */
  uint8_T was_DEMO;                    /* '<Root>/COMPORTEMENT' */
  uint8_T is_active_CLOCK;             /* '<Root>/COMPORTEMENT' */
  uint8_T is_active_FONCTIONS_RECalAGE_PO;/* '<Root>/COMPORTEMENT' */
  uint8_T is_EVITEMENT;                /* '<Root>/COMPORTEMENT' */
  boolean_T Relay_Mode;                /* '<S2>/Relay' */
  rtDW_isFrontMontantMvtBloque_Mo isFrontMontantMvtBloque;/* '<S1>/isFrontMontantMvtBloque' */
} D_Work_ModeleRobot;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T IN_Tirette;                   /* '<Root>/IN_Tirette' */
  real_T IN_x_pos;                     /* '<Root>/IN_x_pos' */
  real_T IN_y_pos;                     /* '<Root>/IN_y_pos' */
  real_T IN_teta_pos;                  /* '<Root>/IN_teta_pos' */
  real_T IN_ConvergenceMvt;            /* '<Root>/IN_ConvergenceMvt' */
  real_T IN_CouleurEquipe;             /* '<Root>/IN_CouleurEquipe' */
  real_T IN_ObstacleAVG;               /* '<Root>/IN_ObstacleAVG' */
  real_T IN_ObstacleAVD;               /* '<Root>/IN_ObstacleAVD' */
  real_T IN_Temps_absolu;              /* '<Root>/IN_Temps_absolu' */
  uint8_T IN_demande_test_actionneurs; /* '<Root>/IN_demande_test_actionneurs' */
  real_T IN_ObstacleARD;               /* '<Root>/IN_ObstacleARD' */
  real_T IN_AngleVersObjet;            /* '<Root>/IN_AngleVersObjet' */
  real_T IN_DistanceVersObjet;         /* '<Root>/IN_DistanceVersObjet' */
  real_T IN_ObstacleARG;               /* '<Root>/IN_ObstacleARG' */
  uint8_T IN_FinCourseAscenseur;       /* '<Root>/IN_FinCourseAscenseur' */
  real_T IN_Ascenseur_pos;             /* '<Root>/IN_Ascenseur_pos' */
  uint8_T IN_FinCourseBarillet;        /* '<Root>/IN_FinCourseBarillet' */
  real_T IN_Barillet_pos;              /* '<Root>/IN_Barillet_pos' */
  real_T IN_ConvergenceMvt_Rapide;     /* '<Root>/IN_ConvergenceMvt_Rapide' */
  real_T IN_Vitesse;                   /* '<Root>/IN_Vitesse' */
  real_T IN_SensDeplacement;           /* '<Root>/IN_SensDeplacement' */
  uint8_T IN_isDepression;             /* '<Root>/IN_isDepression' */
  uint8_T IN_FinCourseHauteAscenseur;  /* '<Root>/IN_FinCourseHauteAscenseur' */
} ExternalInputs_ModeleRobot;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T OUT_ConsigneX;                /* '<Root>/OUT_ConsigneX' */
  real_T OUT_ConsigneY;                /* '<Root>/OUT_ConsigneY' */
  real_T OUT_DdeMvtXY;                 /* '<Root>/OUT_DdeMvtXY' */
  real_T OUT_ConsigneTeta;             /* '<Root>/OUT_ConsigneTeta' */
  real_T OUT_ConsigneVitesseAngle;     /* '<Root>/OUT_ConsigneVitesseAngle' */
  real_T OUT_ConsigneDistance;         /* '<Root>/OUT_ConsigneDistance' */
  real_T OUT_ConsigneVitesseDistance;  /* '<Root>/OUT_ConsigneVitesseDistance' */
  real_T OUT_DdeMvtDistanceAngle;      /* '<Root>/OUT_DdeMvtDistanceAngle' */
  real_T OUT_CommandeManuelleG;        /* '<Root>/OUT_CommandeManuelleG' */
  real_T OUT_CommandeManuelleD;        /* '<Root>/OUT_CommandeManuelleD' */
  real_T OUT_DdeMvtManuel;             /* '<Root>/OUT_DdeMvtManuel' */
  real_T OUT_SpeedServo[20];           /* '<Root>/OUT_SpeedServo' */
  real_T OUT_EtatLed1;                 /* '<Root>/OUT_EtatLed1' */
  real_T OUT_EtatLed2;                 /* '<Root>/OUT_EtatLed2' */
  real_T OUT_EtatLed3;                 /* '<Root>/OUT_EtatLed3' */
  real_T OUT_EtatLed4;                 /* '<Root>/OUT_EtatLed4' */
  real_T OUT_DdeRecalagePosition[4];   /* '<Root>/OUT_DdeRecalagePosition' */
  real_T OUT_ResetCodeurAscenseur;     /* '<Root>/OUT_ResetCodeurAscenseur' */
  real_T OUT_ResetCodeurBarillet;      /* '<Root>/OUT_ResetCodeurBarillet' */
  real_T OUT_DdeMvtXYTeta;             /* '<Root>/OUT_DdeMvtXYTeta' */
  uint8_T OUT_isObstacle;              /* '<Root>/OUT_isObstacle' */
  real_T OUT_CommandeMoteur[8];        /* '<Root>/OUT_CommandeMoteur' */
  real_T OUT_CommandeServo[20];        /* '<Root>/OUT_CommandeServo' */
  real_T OUT_RelacheServo[20];         /* '<Root>/OUT_RelacheServo' */
} ExternalOutputs_ModeleRobot;

/* Parameters for system: '<S1>/isFrontMontantMvtBloque' */
struct rtP_isFrontMontantMvtBloque_Mod_ {
  real_T Constant_Value;               /* Expression: const
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T DelayInput1_X0;               /* Expression: vinit
                                        * Referenced by: '<S10>/Delay Input1'
                                        */
};

/* Parameters (auto storage) */
struct Parameters_ModeleRobot_ {
  real_T SeuilDistance_Value;          /* Expression: 15
                                        * Referenced by: '<S2>/SeuilDistance'
                                        */
  real_T Relay_OnVal;                  /* Expression: 1
                                        * Referenced by: '<S2>/Relay'
                                        */
  real_T Relay_OffVal;                 /* Expression: -1
                                        * Referenced by: '<S2>/Relay'
                                        */
  real_T Relay_YOn;                    /* Expression: 1
                                        * Referenced by: '<S2>/Relay'
                                        */
  real_T Relay_YOff;                   /* Expression: -1
                                        * Referenced by: '<S2>/Relay'
                                        */
  real_T Constant_Value;               /* Expression: const
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T DelayInput1_X0;               /* Expression: vinit
                                        * Referenced by: '<S7>/Delay Input1'
                                        */
  real_T SFunction_p1;                 /* Expression: DEBUG_TORCHE
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p2;                 /* Expression: EQUIPE_JAUNE
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p3;                 /* Expression: EQUIPE_VERTE
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p5;                 /* Expression: KMAR_POSITION_AU_DESSUS_SPOT_AVEC_SPOT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p6;                 /* Expression: KMAR_POSITION_AU_DESSUS_SPOT_SANS_SPOT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p7;                 /* Expression: KMAR_POSITION_DEPART
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p8;                 /* Expression: KMAR_POSITION_HAUT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p9;                 /* Expression: KMAR_POSITION_SPOT_BAS
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p10;                /* Expression: MAX_SPEED_SERVOS
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p12;                /* Expression: MOTEUR_ASCENSEUR
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p13;                /* Expression: MOTEUR_DISTRIBUTEUR
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p14;                /* Expression: MOTEUR_NON_DEFINI
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p15;                /* Expression: MOTEUR_SOUFFLEUR
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p16;                /* Expression: PI
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p17;                /* Expression: SERVO_CENTREUR_D
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p18;                /* Expression: SERVO_CENTREUR_D_FERME
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p19;                /* Expression: SERVO_CENTREUR_D_OUVERT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p20;                /* Expression: SERVO_CENTREUR_G
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p21;                /* Expression: SERVO_CENTREUR_G_FERME
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p22;                /* Expression: SERVO_CENTREUR_G_OUVERT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p23;                /* Expression: SERVO_PINCE_D
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p24;                /* Expression: SERVO_PINCE_D_ENTRE_OUVERT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p25;                /* Expression: SERVO_PINCE_D_FERME
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p26;                /* Expression: SERVO_PINCE_D_OUVERT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p27;                /* Expression: SERVO_PINCE_G
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p28;                /* Expression: SERVO_PINCE_G_ENTRE_OUVERT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p29;                /* Expression: SERVO_PINCE_G_FERME
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p30;                /* Expression: SERVO_PINCE_G_OUVERT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p31;                /* Expression: SERVO_RECOLTEURS
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p32;                /* Expression: SERVO_RECOLTEURS_FERME
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p33;                /* Expression: SERVO_RECOLTEURS_OUVERT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p35;                /* Expression: Te
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/Constant1'
                                        */
  int8_T SFunction_p4;                 /* Computed Parameter: SFunction_p4
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  int8_T SFunction_p11;                /* Computed Parameter: SFunction_p11
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  int8_T SFunction_p34;                /* Computed Parameter: SFunction_p34
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  uint8_T Switch_Threshold;            /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S2>/Switch'
                                        */
  uint8_T Switch1_Threshold;           /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S2>/Switch1'
                                        */
  rtP_isFrontMontantMvtBloque_Mod isFrontMontantMvtBloque;/* '<S1>/isFrontMontantMvtBloque' */
};

/* Block parameters (auto storage) */
extern Parameters_ModeleRobot ModeleRobot_P;

/* Block signals (auto storage) */
extern BlockIO_ModeleRobot ModeleRobot_B;

/* Block states (auto storage) */
extern D_Work_ModeleRobot ModeleRobot_DWork;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_ModeleRobot ModeleRobot_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_ModeleRobot ModeleRobot_Y;

/* Model entry point functions */
extern void ModeleRobot_initialize(boolean_T firstTime);
extern void ModeleRobot_step(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : ModeleRobot
 * '<S1>'   : ModeleRobot/COMPORTEMENT
 * '<S2>'   : ModeleRobot/DetectionObstacle
 * '<S3>'   : ModeleRobot/Model Info
 * '<S4>'   : ModeleRobot/COMPORTEMENT/isFrontMontantConvergence
 * '<S5>'   : ModeleRobot/COMPORTEMENT/isFrontMontantMvtBloque
 * '<S6>'   : ModeleRobot/COMPORTEMENT/isFrontMontantConvergence/Compare To Constant
 * '<S7>'   : ModeleRobot/COMPORTEMENT/isFrontMontantConvergence/Detect Change
 * '<S8>'   : ModeleRobot/COMPORTEMENT/isFrontMontantConvergence/Model Info
 * '<S9>'   : ModeleRobot/COMPORTEMENT/isFrontMontantMvtBloque/Compare To Constant
 * '<S10>'  : ModeleRobot/COMPORTEMENT/isFrontMontantMvtBloque/Detect Change
 * '<S11>'  : ModeleRobot/COMPORTEMENT/isFrontMontantMvtBloque/Model Info
 * '<S12>'  : ModeleRobot/DetectionObstacle/Model Info
 * '<S13>'  : ModeleRobot/DetectionObstacle/marcheArriere
 * '<S14>'  : ModeleRobot/DetectionObstacle/marcheAvant
 */
#endif                                 /* RTW_HEADER_ModeleRobot_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
