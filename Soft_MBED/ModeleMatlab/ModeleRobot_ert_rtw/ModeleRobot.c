/*
 * File: ModeleRobot.c
 *
 * Real-Time Workshop code generated for Simulink model ModeleRobot.
 *
 * Model version                        : 1.1464
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Thu May 14 14:05:32 2015
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Thu May 14 14:05:33 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objective: Efficiency
 * Validation result: Passed (9), Warning (1), Error (0)
 */

#include "ModeleRobot.h"
#include "ModeleRobot_private.h"

/* Named constants for Stateflow: '<Root>/COMPORTEMENT' */
#define ModeleR_IN_FIN_REPOS_ACTIONNEUR (4)
#define ModeleRobot_IN_ACTION_0        (1)
#define ModeleRobot_IN_ACTION_10       (2)
#define ModeleRobot_IN_ACTION_12       (3)
#define ModeleRobot_IN_ACTION_14       (4)
#define ModeleRobot_IN_ACTION_16       (5)
#define ModeleRobot_IN_ACTION_18       (6)
#define ModeleRobot_IN_ACTION_2        (7)
#define ModeleRobot_IN_ACTION_4        (8)
#define ModeleRobot_IN_ACTION_6        (9)
#define ModeleRobot_IN_ACTION_8        (10)
#define ModeleRobot_IN_ACTION_HOMOLO_0 (11)
#define ModeleRobot_IN_ACTION_HOMOLO_01 (12)
#define ModeleRobot_IN_ACTION_HOMOLO_02 (13)
#define ModeleRobot_IN_ACTION_HOMOLO_03 (14)
#define ModeleRobot_IN_ACTION_HOMOLO_05 (15)
#define ModeleRobot_IN_ACTION_HOMOLO_06 (16)
#define ModeleRobot_IN_ACTION_HOMOLO_07 (17)
#define ModeleRobot_IN_ACTION_HOMOLO_08 (18)
#define ModeleRobot_IN_ACTION_HOMOLO_10 (19)
#define ModeleRobot_IN_ACTION_HOMOLO_11 (20)
#define ModeleRobot_IN_ACTION_HOMOLO_12 (21)
#define ModeleRobot_IN_ACTION_HOMOLO_13 (22)
#define ModeleRobot_IN_ACTION_HOMOLO_14 (23)
#define ModeleRobot_IN_ACTION_HOMOLO_15 (24)
#define ModeleRobot_IN_ACTION_HOMOLO_16 (25)
#define ModeleRobot_IN_ACTION_HOMOLO_17 (26)
#define ModeleRobot_IN_ACTION_HOMOLO_18 (27)
#define ModeleRobot_IN_ACTION_HOMOLO_19 (28)
#define ModeleRobot_IN_ACTION_HOMOLO_2 (29)
#define ModeleRobot_IN_ACTION_HOMOLO_20 (30)
#define ModeleRobot_IN_ACTION_HOMOLO_21 (31)
#define ModeleRobot_IN_ACTION_HOMOLO_22 (32)
#define ModeleRobot_IN_ACTION_HOMOLO_23 (33)
#define ModeleRobot_IN_ACTION_HOMOLO_4 (34)
#define ModeleRobot_IN_ACTION_HOMOLO_5 (35)
#define ModeleRobot_IN_ACTION_HOMOLO_6 (36)
#define ModeleRobot_IN_ACTION_HOMOLO_7 (37)
#define ModeleRobot_IN_ACTION_HOMOLO_8 (38)
#define ModeleRobot_IN_ACTION_HOMOLO_9 (39)
#define ModeleRobot_IN_ATTENTE_TIRETTE (1)
#define ModeleRobot_IN_DEMO            (1)
#define ModeleRobot_IN_DETECT_OBSTACLE (1)
#define ModeleRobot_IN_DETECT_OBSTACLE1 (2)
#define ModeleRobot_IN_EQUIPE_1        (1)
#define ModeleRobot_IN_EQUIPE_2        (2)
#define ModeleRobot_IN_EVITEMENT       (1)
#define ModeleRobot_IN_FIN_MATCH       (2)
#define ModeleRobot_IN_FIN_MATCH_01    (1)
#define ModeleRobot_IN_FIN_MATCH_02    (2)
#define ModeleRobot_IN_FIN_MATCH_03    (3)
#define ModeleRobot_IN_FIN_MATCH_04    (4)
#define ModeleRobot_IN_FIN_MATCH_05    (5)
#define ModeleRobot_IN_INIT            (1)
#define ModeleRobot_IN_INIT1           (2)
#define ModeleRobot_IN_INIT_STRATEGIE  (2)
#define ModeleRobot_IN_MATCH           (3)
#define ModeleRobot_IN_NO_ACTIVE_CHILD (0)
#define ModeleRobot_IN_REPOS_SERVOS    (5)
#define ModeleRobot_IN_STRATEGIE1      (2)
#define ModeleRobot_IN_TEST_ACT_1      (3)
#define ModeleRobot_IN_TEST_ACT_2      (4)
#define ModeleRobot_IN_TEST_ACT_3      (5)
#define ModeleRobot_IN_TEST_ACT_FIN    (6)
#define Modele_IN_APPRENTISSAGE_KMAR_01 (1)
#define Modele_IN_APPRENTISSAGE_KMAR_02 (2)
#define Modele_IN_APPRENTISSAGE_KMAR_03 (3)

/* Block signals (auto storage) */
BlockIO_ModeleRobot ModeleRobot_B;

/* Block states (auto storage) */
D_Work_ModeleRobot ModeleRobot_DWork;

/* External inputs (root inport signals with auto storage) */
ExternalInputs_ModeleRobot ModeleRobot_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_ModeleRobot ModeleRobot_Y;

/* Forward declaration for local functions */
static void enter_internal_ACTIONNEURS_REPO(void);
static void enter_internal_COMPORTEMENT_ROB(void);
static void ModeleRobot_enter_atomic_DEMO(void);
static void ModeleRobot_enter_internal_DEMO(void);
static void Model_enter_internal_STRATEGIE1(void);
static void ModeleRobot_ACTION_HOMOLO_5(void);
static void ModeleRobot_ACTION_HOMOLO_6(void);
static void ModeleRobot_ACTION_HOMOLO_7(void);
static void ModeleRobot_ACTION_HOMOLO_8(void);
static void ModeleRobot_ACTION_HOMOLO_9(void);
static void ModeleRobot_DEMO(void);

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void enter_internal_ACTIONNEURS_REPO(void)
{
  /* Transition: '<S1>:1007' */
  /* Entry 'REPOS_SERVOS': '<S1>:1009' */
  ModeleRobot_DWork.is_ACTIONNEURS_REPOS = (uint8_T)ModeleRobot_IN_REPOS_SERVOS;

  /* on ne bouge pas en attendant le depart */
  /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
  /* Transition: '<S1>:1301' */
  ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
  ModeleRobot_B.CommandeManuelleG = 0.0;
  ModeleRobot_B.CommandeManuelleD = 0.0;

  /* Graphical Function 'setPWM': '<S1>:4112' */
  /* Transition: '<S1>:4114' */
  ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p14 - 1.0)] =
    0.0;

  /* Graphical Function 'setPWM': '<S1>:4112' */
  /* Transition: '<S1>:4114' */
  ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p15 - 1.0)] =
    0.0;

  /* Graphical Function 'setPWM': '<S1>:4112' */
  /* Transition: '<S1>:4114' */
  ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p16 - 1.0)] =
    0.0;

  /* Graphical Function 'setPWM': '<S1>:4112' */
  /* Transition: '<S1>:4114' */
  ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p17 - 1.0)] =
    0.0;

  /* meme si la vitesse n'est pas utilise, on l'initialise pour les servos */
  /* Graphical Function 'setServoSpeed': '<S1>:4153' */
  /* Transition: '<S1>:4155' */
  ModeleRobot_B.SpeedServo[(int32_T)(ModeleRobot_P.SFunction_p33 - 1.0)] =
    ModeleRobot_P.SFunction_p12;

  /* Graphical Function 'setServoSpeed': '<S1>:4153' */
  /* Transition: '<S1>:4155' */
  ModeleRobot_B.SpeedServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
    ModeleRobot_P.SFunction_p12;

  /* Graphical Function 'setServoSpeed': '<S1>:4153' */
  /* Transition: '<S1>:4155' */
  ModeleRobot_B.SpeedServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
    ModeleRobot_P.SFunction_p12;

  /* Graphical Function 'setServoSpeed': '<S1>:4153' */
  /* Transition: '<S1>:4155' */
  ModeleRobot_B.SpeedServo[(int32_T)(ModeleRobot_P.SFunction_p19 - 1.0)] =
    ModeleRobot_P.SFunction_p12;

  /* de meme pour le maintient ou non des servos on initialise */
  /* Graphical Function 'setServoRelache': '<S1>:4198' */
  /* Transition: '<S1>:4200' */
  ModeleRobot_B.RelacheServo[(int32_T)(ModeleRobot_P.SFunction_p33 - 1.0)] = 0.0;

  /* Graphical Function 'setServoRelache': '<S1>:4198' */
  /* Transition: '<S1>:4200' */
  ModeleRobot_B.RelacheServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] = 0.0;

  /* Graphical Function 'setServoRelache': '<S1>:4198' */
  /* Transition: '<S1>:4200' */
  ModeleRobot_B.RelacheServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
    1000.0;

  /* Graphical Function 'setServoRelache': '<S1>:4198' */
  /* Transition: '<S1>:4200' */
  ModeleRobot_B.RelacheServo[(int32_T)(ModeleRobot_P.SFunction_p19 - 1.0)] =
    1000.0;

  /* on ecarte les pinces pour qu'elles soient bien dans le robot */
  /* Graphical Function 'setServo': '<S1>:4141' */
  /* Transition: '<S1>:4143' */
  ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p33 - 1.0)] =
    ModeleRobot_P.SFunction_p37;

  /* Graphical Function 'setServo': '<S1>:4141' */
  /* Transition: '<S1>:4143' */
  ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
    ModeleRobot_P.SFunction_p31;

  /* l'inverse pour les centreurs */
  /* Graphical Function 'setServo': '<S1>:4141' */
  /* Transition: '<S1>:4143' */
  ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
    ModeleRobot_P.SFunction_p25;

  /* Graphical Function 'setServo': '<S1>:4141' */
  /* Transition: '<S1>:4143' */
  ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p19 - 1.0)] =
    ModeleRobot_P.SFunction_p21;

  /* on lance le timer pour laisser un petit temps aux actions precedentes */
  ModeleRobot_DWork.TempoInit = 0.0;
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void enter_internal_COMPORTEMENT_ROB(void)
{
  /* Transition: '<S1>:1264' */
  /* Entry 'ATTENTE_TIRETTE': '<S1>:1005' */
  ModeleRobot_DWork.is_COMPORTEMENT_ROBOT = (uint8_T)
    ModeleRobot_IN_ATTENTE_TIRETTE;

  /* Entry 'ACTIONNEURS_REPOS': '<S1>:1006' */
  ModeleRobot_DWork.is_active_ACTIONNEURS_REPOS = 1U;
  enter_internal_ACTIONNEURS_REPO();

  /* Entry 'CHOIX_EQUIPE': '<S1>:1011' */
  ModeleRobot_DWork.is_active_CHOIX_EQUIPE = 1U;

  /* Transition: '<S1>:1012' */
  /* Entry 'EQUIPE_1': '<S1>:1016' */
  ModeleRobot_DWork.is_CHOIX_EQUIPE = (uint8_T)ModeleRobot_IN_EQUIPE_1;
  ModeleRobot_B.EtatLed1 = 1.0;
  ModeleRobot_B.EtatLed2 = 0.0;
  ModeleRobot_DWork.invMouv = -1.0;

  /* Entry 'RECALAGE': '<S1>:1017' */
  ModeleRobot_DWork.is_active_RECALAGE = 1U;

  /* TODO: a faire si on veut respecter le terrain */
  ModeleRobot_DWork.TempoMot = 0.0;

  /* Entry 'TESTS_ACTIONNEUR': '<S1>:1036' */
  ModeleRobot_DWork.is_active_TESTS_ACTIONNEUR = 1U;
  ModeleRobot_DWork.TempoTestActionneurs = 0.0;

  /* Transition: '<S1>:1064' */
  /* Entry 'INIT': '<S1>:1109' */
  ModeleRobot_DWork.is_TESTS_ACTIONNEUR = (uint8_T)ModeleRobot_IN_INIT;
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_enter_atomic_DEMO(void)
{
  /* Entry 'DEMO': '<S1>:3463' */
  ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)ModeleRobot_IN_DEMO;
  ModeleRobot_DWork.was_STRATEGIE1 = (uint8_T)ModeleRobot_IN_DEMO;
  ModeleRobot_DWork.TempoMot = 0.0;
  ModeleRobot_DWork.x_old = 0.0;
  ModeleRobot_DWork.y_old = 0.0;
  ModeleRobot_DWork.inhibeObstacle = 0.0;
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_enter_internal_DEMO(void)
{
  switch (ModeleRobot_DWork.was_DEMO) {
   case ModeleRobot_IN_ACTION_0:
    /* Entry 'ACTION_0': '<S1>:4121' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_0;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_0;

    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = 46.00;
    ModeleRobot_B.ConsigneY = 0.00;
    ModeleRobot_B.ConsigneTeta = 0.0000;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobot_IN_ACTION_10:
    /* Entry 'ACTION_10': '<S1>:4131' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_10;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_10;

    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = 27.00;
    ModeleRobot_B.ConsigneY = 65.00;
    ModeleRobot_B.ConsigneTeta = -1.57;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

    /* j ai les premiers popcorn je degage */
    break;

   case ModeleRobot_IN_ACTION_12:
    /* Entry 'ACTION_12': '<S1>:4133' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_12;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_12;

    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = -3.0;
    ModeleRobot_B.ConsigneY = 65.00;
    ModeleRobot_B.ConsigneTeta = -1.57;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

    /* en position pour ramasser les popcorn */
    break;

   case ModeleRobot_IN_ACTION_14:
    /* Entry 'ACTION_14': '<S1>:4135' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_14;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_14;

    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = -3.0;
    ModeleRobot_B.ConsigneY = 65.00;
    ModeleRobot_B.ConsigneTeta = -1.57;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

    /* j ai tous les popcorn je degage */
    break;

   case ModeleRobot_IN_ACTION_16:
    /* Entry 'ACTION_16': '<S1>:4137' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_16;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_16;

    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = -3.0;
    ModeleRobot_B.ConsigneY = 76.0;
    ModeleRobot_B.ConsigneTeta = -1.57;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

    /* accostage distri 1 */
    break;

   case ModeleRobot_IN_ACTION_18:
    /* Entry 'ACTION_18': '<S1>:4139' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_18;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_18;

    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = 46.00;
    ModeleRobot_B.ConsigneY = 0.00;
    ModeleRobot_B.ConsigneTeta = -1.57;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    ModeleRobot_DWork.finHomologation = 1.0;
    break;

   case ModeleRobot_IN_ACTION_2:
    /* Entry 'ACTION_2': '<S1>:4123' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_2;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_2;

    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = 46.00;
    ModeleRobot_B.ConsigneY = 61.00;
    ModeleRobot_B.ConsigneTeta = 1.5700;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

    /* ramassage d un spot */
    ModeleRobot_DWork.inhibeObstacle = 1.0;
    break;

   case ModeleRobot_IN_ACTION_4:
    /* Entry 'ACTION_4': '<S1>:4125' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_4;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_4;

    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = 46.00;
    ModeleRobot_B.ConsigneY = 68.00;
    ModeleRobot_B.ConsigneTeta = 1.5700;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

    /* ramassage d un deuxieme spot */
    break;

   case ModeleRobot_IN_ACTION_6:
    /* Entry 'ACTION_6': '<S1>:4127' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_6;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_6;

    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = 27.00;
    ModeleRobot_B.ConsigneY = 65.00;
    ModeleRobot_B.ConsigneTeta = -1.57;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

    /* en position pour ramasser les popcorn */
    break;

   case ModeleRobot_IN_ACTION_8:
    /* Entry 'ACTION_8': '<S1>:4129' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_8;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_8;

    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = 27.00;
    ModeleRobot_B.ConsigneY = 76.00;
    ModeleRobot_B.ConsigneTeta = -1.57;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

    /* accostage distri 1 */
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_0:
    /* Entry 'ACTION_HOMOLO_0': '<S1>:4165' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_0;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_0;

    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p14 - 1.0)] =
      0.0;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_01:
    /* Entry 'ACTION_HOMOLO_01': '<S1>:4181' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_01;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_01;

    /* on prend la balle de tennis */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p33 - 1.0)] =
      ModeleRobot_P.SFunction_p35;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
      ModeleRobot_P.SFunction_p29;

    /* tempo */
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_02:
    /* Entry 'ACTION_HOMOLO_02': '<S1>:4183' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_02;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_02;

    /* on monte l'ascenseur pour etre au dessus d'un spot */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p14 - 1.0)] =
      60.0;

    /* tempo */
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_03:
    /* Entry 'ACTION_HOMOLO_03': '<S1>:4220' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_03;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_03;

    /* on sort de la zone de départ
       on a mis une tempo pour minibot et desactiver la detection d'obstacle
       pour le defoncer s'il merde, a priori l'action avec la balle dure juste ce qu'il faut (à potarder) */
    ModeleRobot_DWork.inhibeObstacle = 1.0;

    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = 38.0;
    ModeleRobot_B.ConsigneY = 0.0;
    ModeleRobot_B.ConsigneTeta = ModeleRobot_P.SFunction_p18;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_05:
    /* Entry 'ACTION_HOMOLO_05': '<S1>:4239' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_05;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_05;

    /* on descend l'ascenseur pour emprisonner spot + balle */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p14 - 1.0)] =
      -60.0;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p33 - 1.0)] =
      ModeleRobot_P.SFunction_p34;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
      ModeleRobot_P.SFunction_p28;

    /* tempo */
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_06:
    /* Entry 'ACTION_HOMOLO_06': '<S1>:4254' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_06;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_06;

    /* on prend le gobelet */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p33 - 1.0)] =
      ModeleRobot_P.SFunction_p38;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
      ModeleRobot_P.SFunction_p32;

    /* tempo */
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_07:
    /* Entry 'ACTION_HOMOLO_07': '<S1>:4261' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_07;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_07;

    /* on lache le gobelet */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p33 - 1.0)] =
      ModeleRobot_P.SFunction_p37;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
      ModeleRobot_P.SFunction_p31;

    /* tempo */
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_08:
    /* Entry 'ACTION_HOMOLO_08': '<S1>:4265' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_08;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_08;

    /* on remonte les pinces */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p14 - 1.0)] =
      60.0;

    /* tempo */
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_10:
    /* Entry 'ACTION_HOMOLO_10': '<S1>:4204' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_10;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_10;
    ModeleRobot_DWork.inhibeObstacle = 0.0;

    /* on se tourne vers le distributeur en lui presentant l'arriere du robot */
    /* Graphical Function 'Mouvement_Angle': '<S1>:1354' */
    /* Transition: '<S1>:1356' */
    ModeleRobot_B.DdeMvtDistanceAngle = ModeleRobot_B.DdeMvtDistanceAngle + 1.0;
    ModeleRobot_B.ConsigneDistance = 0.0;
    ModeleRobot_B.ConsigneTeta = -1.57;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_11:
    /* Entry 'ACTION_HOMOLO_11': '<S1>:4207' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_11;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_11;

    /* pas de robot possible dans ce coin, on inhibe la detection d'obstacle */
    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = 36.0;
    ModeleRobot_B.ConsigneY = 75.0;
    ModeleRobot_B.ConsigneTeta = -1.57;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_12:
    /* Entry 'ACTION_HOMOLO_12': '<S1>:4210' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_12;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_12;

    /* on sort les recolteurs et on leur laisse 1sec */
    ModeleRobot_DWork.TempoMot = 0.0;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p39 - 1.0)] =
      ModeleRobot_P.SFunction_p41;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_13:
    /* Entry 'ACTION_HOMOLO_13': '<S1>:4213' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_13;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_13;

    /* on souffle pendant 2 secondes */
    ModeleRobot_DWork.TempoMot = 0.0;

    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p17 - 1.0)] =
      100.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_14:
    /* Entry 'ACTION_HOMOLO_14': '<S1>:4215' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_14;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_14;

    /* on arrete de souffler et on rentre les recolteurs */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p17 - 1.0)] =
      0.0;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p39 - 1.0)] =
      ModeleRobot_P.SFunction_p40;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_15:
    /* Entry 'ACTION_HOMOLO_15': '<S1>:4237' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_15;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_15;

    /* on relache la balle */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p33 - 1.0)] =
      ModeleRobot_P.SFunction_p36;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
      ModeleRobot_P.SFunction_p30;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_16:
    /* Entry 'ACTION_HOMOLO_16': '<S1>:4243' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_16;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_16;

    /* on relache la balle */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p33 - 1.0)] =
      ModeleRobot_P.SFunction_p36;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
      ModeleRobot_P.SFunction_p30;

    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p14 - 1.0)] =
      0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_17:
    /* Entry 'ACTION_HOMOLO_17': '<S1>:4249' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_17;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_17;

    /* on centre le spot */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
      ModeleRobot_P.SFunction_p26;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p19 - 1.0)] =
      ModeleRobot_P.SFunction_p22;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_18:
    /* Entry 'ACTION_HOMOLO_18': '<S1>:4251' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_18;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_18;

    /* on avance vers le gobelet */
    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = 13.0;
    ModeleRobot_B.ConsigneY = -67.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_B.ConsigneTeta = -2.68 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_19:
    /* Entry 'ACTION_HOMOLO_19': '<S1>:4255' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_19;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_19;

    /* inhibeObstacle=0;
       on va vers la zone de départ */
    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = 67.0;
    ModeleRobot_B.ConsigneY = 0.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_B.ConsigneTeta = 3.14 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_2:
    /* Entry 'ACTION_HOMOLO_2': '<S1>:4167' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_2;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_2;

    /* on fait une diagonale pour pousser le deuxieme spots dans la zone de construction */
    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = 85.0;
    ModeleRobot_B.ConsigneY = -72.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_B.ConsigneTeta = -0.99 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_20:
    /* Entry 'ACTION_HOMOLO_20': '<S1>:4258' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_20;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_20;

    /* on avance pour déposer le gobelet */
    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = 39.0;
    ModeleRobot_B.ConsigneY = 0.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_B.ConsigneTeta = 3.14 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_21:
    /* Entry 'ACTION_HOMOLO_21': '<S1>:4262' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_21;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_21;

    /* on recule pour déposer le gobelet */
    ModeleRobot_DWork.inhibeObstacle = 0.0;

    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = 67.0;
    ModeleRobot_B.ConsigneY = 0.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_B.ConsigneTeta = 3.14 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_22:
    /* Entry 'ACTION_HOMOLO_22': '<S1>:4266' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_22;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_22;

    /* on rentre les centreurs */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p14 - 1.0)] =
      0.0;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p19 - 1.0)] =
      ModeleRobot_P.SFunction_p21;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_23:
    /* Entry 'ACTION_HOMOLO_23': '<S1>:4269' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_23;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_23;

    /* on rentre les centreurs */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
      ModeleRobot_P.SFunction_p25;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_4:
    /* Entry 'ACTION_HOMOLO_4': '<S1>:4169' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_4;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_4;

    /* on recule pour laisser les spots */
    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = 67.0;
    ModeleRobot_B.ConsigneY = -45.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_B.ConsigneTeta = -0.99 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_5:
    /* Entry 'ACTION_HOMOLO_5': '<S1>:4171' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_5;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_5;

    /* on se tourne vers le gobelet */
    /* Graphical Function 'Mouvement_Angle': '<S1>:1354' */
    /* Transition: '<S1>:1356' */
    ModeleRobot_B.DdeMvtDistanceAngle = ModeleRobot_B.DdeMvtDistanceAngle + 1.0;
    ModeleRobot_B.ConsigneDistance = 0.0;
    ModeleRobot_B.ConsigneTeta = -2.68 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_6:
    /* Entry 'ACTION_HOMOLO_6': '<S1>:4187' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_6;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_6;

    /* on se dirige vers le 1er spot */
    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = 60.0;
    ModeleRobot_B.ConsigneY = -27.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_B.ConsigneTeta = -1.06 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_7:
    /* Entry 'ACTION_HOMOLO_7': '<S1>:4189' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_7;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_7;

    /* inhibeObstacle=0;
       on se tourne vers les spots */
    /* Graphical Function 'Mouvement_Angle': '<S1>:1354' */
    /* Transition: '<S1>:1356' */
    ModeleRobot_B.DdeMvtDistanceAngle = ModeleRobot_B.DdeMvtDistanceAngle + 1.0;
    ModeleRobot_B.ConsigneDistance = 0.0;
    ModeleRobot_B.ConsigneTeta = -0.99 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
      ModeleRobot_P.SFunction_p26;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p19 - 1.0)] =
      ModeleRobot_P.SFunction_p22;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_8:
    /* Entry 'ACTION_HOMOLO_8': '<S1>:4192' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_8;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_8;

    /* on centre le spot */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
      ModeleRobot_P.SFunction_p24;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p19 - 1.0)] =
      ModeleRobot_P.SFunction_p20;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_9:
    /* Entry 'ACTION_HOMOLO_9': '<S1>:4203' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_9;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_9;

    /* on accoste le distributeur à 10 cm */
    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = 36.0;
    ModeleRobot_B.ConsigneY = 65.0;
    ModeleRobot_B.ConsigneTeta = -1.57;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   default:
    /* Transition: '<S1>:4225' */
    /* Entry 'ACTION_HOMOLO_01': '<S1>:4181' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_01;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_01;

    /* on prend la balle de tennis */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p33 - 1.0)] =
      ModeleRobot_P.SFunction_p35;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
      ModeleRobot_P.SFunction_p29;

    /* tempo */
    ModeleRobot_DWork.TempoMot = 0.0;
    break;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void Model_enter_internal_STRATEGIE1(void)
{
  switch (ModeleRobot_DWork.was_STRATEGIE1) {
   case ModeleRobot_IN_DEMO:
    ModeleRobot_enter_atomic_DEMO();
    ModeleRobot_enter_internal_DEMO();
    break;

   case ModeleRobot_IN_INIT_STRATEGIE:
    /* Entry 'INIT_STRATEGIE': '<S1>:1128' */
    ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)ModeleRobot_IN_INIT_STRATEGIE;
    ModeleRobot_DWork.was_STRATEGIE1 = (uint8_T)ModeleRobot_IN_INIT_STRATEGIE;
    ModeleRobot_B.ConsigneVitesseAngle = 3.0;

    /*  [rad/sec] */
    ModeleRobot_B.ConsigneVitesseDistance = 40.0;

    /* [cm/sec] */
    ModeleRobot_DWork.finHomologation = 0.0;

    /* pour 2015 on part en marche arrière */
    /* Graphical Function 'setPosition': '<S1>:4174' */
    /* Transition: '<S1>:4176' */
    ModeleRobot_B.DdeRecalagePosition[0] = ModeleRobot_B.DdeRecalagePosition[0]
      + 1.0;
    ModeleRobot_B.DdeRecalagePosition[1] = 0.0;
    ModeleRobot_B.DdeRecalagePosition[2] = 0.0;
    ModeleRobot_B.DdeRecalagePosition[3] = ModeleRobot_P.SFunction_p18;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   default:
    /* Transition: '<S1>:1125' */
    /* Entry 'INIT_STRATEGIE': '<S1>:1128' */
    ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)ModeleRobot_IN_INIT_STRATEGIE;
    ModeleRobot_DWork.was_STRATEGIE1 = (uint8_T)ModeleRobot_IN_INIT_STRATEGIE;
    ModeleRobot_B.ConsigneVitesseAngle = 3.0;

    /*  [rad/sec] */
    ModeleRobot_B.ConsigneVitesseDistance = 40.0;

    /* [cm/sec] */
    ModeleRobot_DWork.finHomologation = 0.0;

    /* pour 2015 on part en marche arrière */
    /* Graphical Function 'setPosition': '<S1>:4174' */
    /* Transition: '<S1>:4176' */
    ModeleRobot_B.DdeRecalagePosition[0] = ModeleRobot_B.DdeRecalagePosition[0]
      + 1.0;
    ModeleRobot_B.DdeRecalagePosition[1] = 0.0;
    ModeleRobot_B.DdeRecalagePosition[2] = 0.0;
    ModeleRobot_B.DdeRecalagePosition[3] = ModeleRobot_P.SFunction_p18;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_ACTION_HOMOLO_5(void)
{
  /* During 'ACTION_HOMOLO_5': '<S1>:4171' */
  /* Graphical Function 'isFinMouvement': '<S1>:1282' */
  /* Transition: '<S1>:1285' */
  ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt +
    1.0;

  /* Transition: '<S1>:1286' */
  /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
  if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 / ModeleRobot_P.SFunction_p43)
       || (ModeleRobot_B.DataTypeConversion != 0.0)) != 0) {
    /* Transition: '<S1>:4253' */
    /* Exit 'ACTION_HOMOLO_5': '<S1>:4171' */
    /* Entry 'ACTION_HOMOLO_18': '<S1>:4251' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_18;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_18;

    /* on avance vers le gobelet */
    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = 13.0;
    ModeleRobot_B.ConsigneY = -67.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_B.ConsigneTeta = -2.68 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_ACTION_HOMOLO_6(void)
{
  /* During 'ACTION_HOMOLO_6': '<S1>:4187' */
  /* Graphical Function 'isFinMouvement': '<S1>:1282' */
  /* Transition: '<S1>:1285' */
  ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt +
    1.0;

  /* Transition: '<S1>:1286' */
  /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
  if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 / ModeleRobot_P.SFunction_p43)
       || (ModeleRobot_B.DataTypeConversion != 0.0)) != 0) {
    /* Transition: '<S1>:4168' */
    /* Exit 'ACTION_HOMOLO_6': '<S1>:4187' */
    /* Entry 'ACTION_HOMOLO_8': '<S1>:4192' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_8;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_8;

    /* on centre le spot */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
      ModeleRobot_P.SFunction_p24;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p19 - 1.0)] =
      ModeleRobot_P.SFunction_p20;
    ModeleRobot_DWork.TempoMot = 0.0;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_ACTION_HOMOLO_7(void)
{
  /* During 'ACTION_HOMOLO_7': '<S1>:4189' */
  /* Graphical Function 'isFinMouvement': '<S1>:1282' */
  /* Transition: '<S1>:1285' */
  ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt +
    1.0;

  /* Transition: '<S1>:1286' */
  /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
  if (((ModeleRobot_DWork.CompteurTimeoutMvt > 2.0 / ModeleRobot_P.SFunction_p43)
       || (ModeleRobot_B.DataTypeConversion != 0.0)) != 0) {
    /* Transition: '<S1>:4188' */
    /* Exit 'ACTION_HOMOLO_7': '<S1>:4189' */
    /* Entry 'ACTION_HOMOLO_6': '<S1>:4187' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_6;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_6;

    /* on se dirige vers le 1er spot */
    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = 60.0;
    ModeleRobot_B.ConsigneY = -27.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_B.ConsigneTeta = -1.06 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_ACTION_HOMOLO_8(void)
{
  /* During 'ACTION_HOMOLO_8': '<S1>:4192' */
  if (ModeleRobot_DWork.TempoMot > 1.0 / ModeleRobot_P.SFunction_p43) {
    /* Transition: '<S1>:4238' */
    /* Exit 'ACTION_HOMOLO_8': '<S1>:4192' */
    /* Entry 'ACTION_HOMOLO_17': '<S1>:4249' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_17;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_17;

    /* on centre le spot */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
      ModeleRobot_P.SFunction_p26;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p19 - 1.0)] =
      ModeleRobot_P.SFunction_p22;
    ModeleRobot_DWork.TempoMot = 0.0;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_ACTION_HOMOLO_9(void)
{
  /* During 'ACTION_HOMOLO_9': '<S1>:4203' */
  /* Graphical Function 'isFinMouvement': '<S1>:1282' */
  /* Transition: '<S1>:1285' */
  ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt +
    1.0;

  /* Transition: '<S1>:1286' */
  /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
  if (((ModeleRobot_DWork.CompteurTimeoutMvt > 5.0 / ModeleRobot_P.SFunction_p43)
       || (ModeleRobot_B.DataTypeConversion != 0.0)) != 0) {
    /* Transition: '<S1>:4208' */
    /* Exit 'ACTION_HOMOLO_9': '<S1>:4203' */
    /* Entry 'ACTION_HOMOLO_11': '<S1>:4207' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_11;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_11;

    /* pas de robot possible dans ce coin, on inhibe la detection d'obstacle */
    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = 36.0;
    ModeleRobot_B.ConsigneY = 75.0;
    ModeleRobot_B.ConsigneTeta = -1.57;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_DEMO(void)
{
  /* During 'DEMO': '<S1>:3463' */
  ModeleRobot_DWork.TempoMot = ModeleRobot_DWork.TempoMot + 1.0;

  /* CommandeLEDS_RVBO(ObstacleARG,ObstacleARD, ObstacleAVG,ObstacleAVD);vv */
  switch (ModeleRobot_DWork.is_DEMO) {
   case ModeleRobot_IN_ACTION_0:
    /* During 'ACTION_0': '<S1>:4121' */
    /* Graphical Function 'isFinMouvement': '<S1>:1282' */
    /* Transition: '<S1>:1285' */
    ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt
      + 1.0;

    /* Transition: '<S1>:1286' */
    /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
    if (((ModeleRobot_DWork.CompteurTimeoutMvt > 5.0 /
          ModeleRobot_P.SFunction_p43) || (ModeleRobot_B.DataTypeConversion !=
          0.0)) != 0) {
      /* Transition: '<S1>:4124' */
      /* Exit 'ACTION_0': '<S1>:4121' */
      /* Entry 'ACTION_2': '<S1>:4123' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_2;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_2;

      /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
      /* Transition: '<S1>:3697' */
      ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
      ModeleRobot_B.ConsigneX = 46.00;
      ModeleRobot_B.ConsigneY = 61.00;
      ModeleRobot_B.ConsigneTeta = 1.5700;
      ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

      /* ramassage d un spot */
      ModeleRobot_DWork.inhibeObstacle = 1.0;
    }
    break;

   case ModeleRobot_IN_ACTION_10:
    /* During 'ACTION_10': '<S1>:4131' */
    /* Graphical Function 'isFinMouvement': '<S1>:1282' */
    /* Transition: '<S1>:1285' */
    ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt
      + 1.0;

    /* Transition: '<S1>:1286' */
    /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
    if (((ModeleRobot_DWork.CompteurTimeoutMvt > 5.0 /
          ModeleRobot_P.SFunction_p43) || (ModeleRobot_B.DataTypeConversion !=
          0.0)) != 0) {
      /* Transition: '<S1>:4134' */
      /* Exit 'ACTION_10': '<S1>:4131' */
      /* Entry 'ACTION_12': '<S1>:4133' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_12;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_12;

      /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
      /* Transition: '<S1>:3697' */
      ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
      ModeleRobot_B.ConsigneX = -3.0;
      ModeleRobot_B.ConsigneY = 65.00;
      ModeleRobot_B.ConsigneTeta = -1.57;
      ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

      /* en position pour ramasser les popcorn */
    }
    break;

   case ModeleRobot_IN_ACTION_12:
    /* During 'ACTION_12': '<S1>:4133' */
    /* Graphical Function 'isFinMouvement': '<S1>:1282' */
    /* Transition: '<S1>:1285' */
    ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt
      + 1.0;

    /* Transition: '<S1>:1286' */
    /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
    if (((ModeleRobot_DWork.CompteurTimeoutMvt > 5.0 /
          ModeleRobot_P.SFunction_p43) || (ModeleRobot_B.DataTypeConversion !=
          0.0)) != 0) {
      /* Transition: '<S1>:4136' */
      /* Exit 'ACTION_12': '<S1>:4133' */
      /* Entry 'ACTION_14': '<S1>:4135' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_14;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_14;

      /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
      /* Transition: '<S1>:3697' */
      ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
      ModeleRobot_B.ConsigneX = -3.0;
      ModeleRobot_B.ConsigneY = 65.00;
      ModeleRobot_B.ConsigneTeta = -1.57;
      ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

      /* j ai tous les popcorn je degage */
    }
    break;

   case ModeleRobot_IN_ACTION_14:
    /* During 'ACTION_14': '<S1>:4135' */
    /* Graphical Function 'isFinMouvement': '<S1>:1282' */
    /* Transition: '<S1>:1285' */
    ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt
      + 1.0;

    /* Transition: '<S1>:1286' */
    /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
    if (((ModeleRobot_DWork.CompteurTimeoutMvt > 5.0 /
          ModeleRobot_P.SFunction_p43) || (ModeleRobot_B.DataTypeConversion !=
          0.0)) != 0) {
      /* Transition: '<S1>:4138' */
      /* Exit 'ACTION_14': '<S1>:4135' */
      /* Entry 'ACTION_16': '<S1>:4137' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_16;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_16;

      /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
      /* Transition: '<S1>:3697' */
      ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
      ModeleRobot_B.ConsigneX = -3.0;
      ModeleRobot_B.ConsigneY = 76.0;
      ModeleRobot_B.ConsigneTeta = -1.57;
      ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

      /* accostage distri 1 */
    }
    break;

   case ModeleRobot_IN_ACTION_16:
    /* During 'ACTION_16': '<S1>:4137' */
    /* Graphical Function 'isFinMouvement': '<S1>:1282' */
    /* Transition: '<S1>:1285' */
    ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt
      + 1.0;

    /* Transition: '<S1>:1286' */
    /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
    if (((ModeleRobot_DWork.CompteurTimeoutMvt > 5.0 /
          ModeleRobot_P.SFunction_p43) || (ModeleRobot_B.DataTypeConversion !=
          0.0)) != 0) {
      /* Transition: '<S1>:4140' */
      /* Exit 'ACTION_16': '<S1>:4137' */
      /* Entry 'ACTION_18': '<S1>:4139' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_18;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_18;

      /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
      /* Transition: '<S1>:3697' */
      ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
      ModeleRobot_B.ConsigneX = 46.00;
      ModeleRobot_B.ConsigneY = 0.00;
      ModeleRobot_B.ConsigneTeta = -1.57;
      ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
      ModeleRobot_DWork.finHomologation = 1.0;
    }
    break;

   case ModeleRobot_IN_ACTION_18:
    break;

   case ModeleRobot_IN_ACTION_2:
    /* During 'ACTION_2': '<S1>:4123' */
    /* Graphical Function 'isFinMouvement': '<S1>:1282' */
    /* Transition: '<S1>:1285' */
    ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt
      + 1.0;

    /* Transition: '<S1>:1286' */
    /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
    if (((ModeleRobot_DWork.CompteurTimeoutMvt > 5.0 /
          ModeleRobot_P.SFunction_p43) || (ModeleRobot_B.DataTypeConversion !=
          0.0)) != 0) {
      /* Transition: '<S1>:4126' */
      /* Exit 'ACTION_2': '<S1>:4123' */
      /* Entry 'ACTION_4': '<S1>:4125' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_4;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_4;

      /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
      /* Transition: '<S1>:3697' */
      ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
      ModeleRobot_B.ConsigneX = 46.00;
      ModeleRobot_B.ConsigneY = 68.00;
      ModeleRobot_B.ConsigneTeta = 1.5700;
      ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

      /* ramassage d un deuxieme spot */
    }
    break;

   case ModeleRobot_IN_ACTION_4:
    /* During 'ACTION_4': '<S1>:4125' */
    /* Graphical Function 'isFinMouvement': '<S1>:1282' */
    /* Transition: '<S1>:1285' */
    ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt
      + 1.0;

    /* Transition: '<S1>:1286' */
    /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
    if (((ModeleRobot_DWork.CompteurTimeoutMvt > 5.0 /
          ModeleRobot_P.SFunction_p43) || (ModeleRobot_B.DataTypeConversion !=
          0.0)) != 0) {
      /* Transition: '<S1>:4128' */
      /* Exit 'ACTION_4': '<S1>:4125' */
      /* Entry 'ACTION_6': '<S1>:4127' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_6;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_6;

      /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
      /* Transition: '<S1>:3697' */
      ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
      ModeleRobot_B.ConsigneX = 27.00;
      ModeleRobot_B.ConsigneY = 65.00;
      ModeleRobot_B.ConsigneTeta = -1.57;
      ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

      /* en position pour ramasser les popcorn */
    }
    break;

   case ModeleRobot_IN_ACTION_6:
    /* During 'ACTION_6': '<S1>:4127' */
    /* Graphical Function 'isFinMouvement': '<S1>:1282' */
    /* Transition: '<S1>:1285' */
    ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt
      + 1.0;

    /* Transition: '<S1>:1286' */
    /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
    if (((ModeleRobot_DWork.CompteurTimeoutMvt > 5.0 /
          ModeleRobot_P.SFunction_p43) || (ModeleRobot_B.DataTypeConversion !=
          0.0)) != 0) {
      /* Transition: '<S1>:4130' */
      /* Exit 'ACTION_6': '<S1>:4127' */
      /* Entry 'ACTION_8': '<S1>:4129' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_8;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_8;

      /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
      /* Transition: '<S1>:3697' */
      ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
      ModeleRobot_B.ConsigneX = 27.00;
      ModeleRobot_B.ConsigneY = 76.00;
      ModeleRobot_B.ConsigneTeta = -1.57;
      ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

      /* accostage distri 1 */
    }
    break;

   case ModeleRobot_IN_ACTION_8:
    /* During 'ACTION_8': '<S1>:4129' */
    /* Graphical Function 'isFinMouvement': '<S1>:1282' */
    /* Transition: '<S1>:1285' */
    ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt
      + 1.0;

    /* Transition: '<S1>:1286' */
    /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
    if (((ModeleRobot_DWork.CompteurTimeoutMvt > 5.0 /
          ModeleRobot_P.SFunction_p43) || (ModeleRobot_B.DataTypeConversion !=
          0.0)) != 0) {
      /* Transition: '<S1>:4132' */
      /* Exit 'ACTION_8': '<S1>:4129' */
      /* Entry 'ACTION_10': '<S1>:4131' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_10;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_10;

      /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
      /* Transition: '<S1>:3697' */
      ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
      ModeleRobot_B.ConsigneX = 27.00;
      ModeleRobot_B.ConsigneY = 65.00;
      ModeleRobot_B.ConsigneTeta = -1.57;
      ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

      /* j ai les premiers popcorn je degage */
    }
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_0:
    /* During 'ACTION_HOMOLO_0': '<S1>:4165' */
    if (ModeleRobot_DWork.TempoMot > 4.0 / ModeleRobot_P.SFunction_p43) {
      /* Transition: '<S1>:4191' */
      /* Exit 'ACTION_HOMOLO_0': '<S1>:4165' */
      /* Entry 'ACTION_HOMOLO_03': '<S1>:4220' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_03;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_03;

      /* on sort de la zone de départ
         on a mis une tempo pour minibot et desactiver la detection d'obstacle
         pour le defoncer s'il merde, a priori l'action avec la balle dure juste ce qu'il faut (à potarder) */
      ModeleRobot_DWork.inhibeObstacle = 1.0;

      /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
      /* Transition: '<S1>:3697' */
      ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
      ModeleRobot_B.ConsigneX = 38.0;
      ModeleRobot_B.ConsigneY = 0.0;
      ModeleRobot_B.ConsigneTeta = ModeleRobot_P.SFunction_p18;
      ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    }
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_01:
    /* During 'ACTION_HOMOLO_01': '<S1>:4181' */
    if (ModeleRobot_DWork.TempoMot > 1.0 / ModeleRobot_P.SFunction_p43) {
      /* Transition: '<S1>:4185' */
      /* Exit 'ACTION_HOMOLO_01': '<S1>:4181' */
      /* Entry 'ACTION_HOMOLO_02': '<S1>:4183' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_02;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_02;

      /* on monte l'ascenseur pour etre au dessus d'un spot */
      /* Graphical Function 'setPWM': '<S1>:4112' */
      /* Transition: '<S1>:4114' */
      ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p14 - 1.0)]
        = 60.0;

      /* tempo */
      ModeleRobot_DWork.TempoMot = 0.0;
    }
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_02:
    /* During 'ACTION_HOMOLO_02': '<S1>:4183' */
    if ((ModeleRobot_U.IN_Ascenseur_pos >= ModeleRobot_P.SFunction_p8) ||
        (ModeleRobot_DWork.TempoMot > 4.0 / ModeleRobot_P.SFunction_p43)) {
      /* Transition: '<S1>:4182' */
      /* Exit 'ACTION_HOMOLO_02': '<S1>:4183' */
      /* Entry 'ACTION_HOMOLO_0': '<S1>:4165' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_0;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_0;

      /* Graphical Function 'setPWM': '<S1>:4112' */
      /* Transition: '<S1>:4114' */
      ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p14 - 1.0)]
        = 0.0;
      ModeleRobot_DWork.TempoMot = 0.0;
    }
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_03:
    /* During 'ACTION_HOMOLO_03': '<S1>:4220' */
    /* Graphical Function 'isFinMouvement': '<S1>:1282' */
    /* Transition: '<S1>:1285' */
    ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt
      + 1.0;

    /* Transition: '<S1>:1286' */
    /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
    if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 /
          ModeleRobot_P.SFunction_p43) || (ModeleRobot_B.DataTypeConversion !=
          0.0)) != 0) {
      /* Transition: '<S1>:4221' */
      /* Exit 'ACTION_HOMOLO_03': '<S1>:4220' */
      /* Entry 'ACTION_HOMOLO_7': '<S1>:4189' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_7;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_7;

      /* inhibeObstacle=0;
         on se tourne vers les spots */
      /* Graphical Function 'Mouvement_Angle': '<S1>:1354' */
      /* Transition: '<S1>:1356' */
      ModeleRobot_B.DdeMvtDistanceAngle = ModeleRobot_B.DdeMvtDistanceAngle +
        1.0;
      ModeleRobot_B.ConsigneDistance = 0.0;
      ModeleRobot_B.ConsigneTeta = -0.99 * ModeleRobot_DWork.invMouv;
      ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

      /* Graphical Function 'setServo': '<S1>:4141' */
      /* Transition: '<S1>:4143' */
      ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
        ModeleRobot_P.SFunction_p26;

      /* Graphical Function 'setServo': '<S1>:4141' */
      /* Transition: '<S1>:4143' */
      ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p19 - 1.0)] =
        ModeleRobot_P.SFunction_p22;
    }
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_05:
    /* During 'ACTION_HOMOLO_05': '<S1>:4239' */
    if ((ModeleRobot_U.IN_Ascenseur_pos <= ModeleRobot_P.SFunction_p9) ||
        (ModeleRobot_DWork.TempoMot > 4.0 / ModeleRobot_P.SFunction_p43)) {
      /* Transition: '<S1>:4242' */
      /* Exit 'ACTION_HOMOLO_05': '<S1>:4239' */
      /* Entry 'ACTION_HOMOLO_16': '<S1>:4243' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_16;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_16;

      /* on relache la balle */
      /* Graphical Function 'setServo': '<S1>:4141' */
      /* Transition: '<S1>:4143' */
      ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p33 - 1.0)] =
        ModeleRobot_P.SFunction_p36;

      /* Graphical Function 'setServo': '<S1>:4141' */
      /* Transition: '<S1>:4143' */
      ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
        ModeleRobot_P.SFunction_p30;

      /* Graphical Function 'setPWM': '<S1>:4112' */
      /* Transition: '<S1>:4114' */
      ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p14 - 1.0)]
        = 0.0;
    }
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_06:
    /* During 'ACTION_HOMOLO_06': '<S1>:4254' */
    if (ModeleRobot_DWork.TempoMot > 1.0 / ModeleRobot_P.SFunction_p43) {
      /* Transition: '<S1>:4256' */
      /* Exit 'ACTION_HOMOLO_06': '<S1>:4254' */
      /* Entry 'ACTION_HOMOLO_19': '<S1>:4255' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_19;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_19;

      /* inhibeObstacle=0;
         on va vers la zone de départ */
      /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
      /* Transition: '<S1>:3697' */
      ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
      ModeleRobot_B.ConsigneX = 67.0;
      ModeleRobot_B.ConsigneY = 0.0 * ModeleRobot_DWork.invMouv;
      ModeleRobot_B.ConsigneTeta = 3.14 * ModeleRobot_DWork.invMouv;
      ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    }
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_07:
    /* During 'ACTION_HOMOLO_07': '<S1>:4261' */
    if (ModeleRobot_DWork.TempoMot > 1.0 / ModeleRobot_P.SFunction_p43) {
      /* Transition: '<S1>:4264' */
      /* Exit 'ACTION_HOMOLO_07': '<S1>:4261' */
      /* Entry 'ACTION_HOMOLO_21': '<S1>:4262' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_21;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_21;

      /* on recule pour déposer le gobelet */
      ModeleRobot_DWork.inhibeObstacle = 0.0;

      /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
      /* Transition: '<S1>:3697' */
      ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
      ModeleRobot_B.ConsigneX = 67.0;
      ModeleRobot_B.ConsigneY = 0.0 * ModeleRobot_DWork.invMouv;
      ModeleRobot_B.ConsigneTeta = 3.14 * ModeleRobot_DWork.invMouv;
      ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    }
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_08:
    /* During 'ACTION_HOMOLO_08': '<S1>:4265' */
    if ((ModeleRobot_U.IN_Ascenseur_pos >= ModeleRobot_P.SFunction_p8) ||
        (ModeleRobot_DWork.TempoMot > 4.0 / ModeleRobot_P.SFunction_p43)) {
      /* Transition: '<S1>:4267' */
      /* Exit 'ACTION_HOMOLO_08': '<S1>:4265' */
      /* Entry 'ACTION_HOMOLO_22': '<S1>:4266' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_22;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_22;

      /* on rentre les centreurs */
      /* Graphical Function 'setPWM': '<S1>:4112' */
      /* Transition: '<S1>:4114' */
      ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p14 - 1.0)]
        = 0.0;

      /* Graphical Function 'setServo': '<S1>:4141' */
      /* Transition: '<S1>:4143' */
      ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p19 - 1.0)] =
        ModeleRobot_P.SFunction_p21;
      ModeleRobot_DWork.TempoMot = 0.0;
    }
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_10:
    /* During 'ACTION_HOMOLO_10': '<S1>:4204' */
    /* Graphical Function 'isFinMouvement': '<S1>:1282' */
    /* Transition: '<S1>:1285' */
    ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt
      + 1.0;

    /* Transition: '<S1>:1286' */
    /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
    if (((ModeleRobot_DWork.CompteurTimeoutMvt > 5.0 /
          ModeleRobot_P.SFunction_p43) || (ModeleRobot_B.DataTypeConversion !=
          0.0)) != 0) {
      /* Transition: '<S1>:4205' */
      /* Exit 'ACTION_HOMOLO_10': '<S1>:4204' */
      /* Entry 'ACTION_HOMOLO_9': '<S1>:4203' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_9;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_9;

      /* on accoste le distributeur à 10 cm */
      /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
      /* Transition: '<S1>:3697' */
      ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
      ModeleRobot_B.ConsigneX = 36.0;
      ModeleRobot_B.ConsigneY = 65.0;
      ModeleRobot_B.ConsigneTeta = -1.57;
      ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    }
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_11:
    /* During 'ACTION_HOMOLO_11': '<S1>:4207' */
    /* Graphical Function 'isFinMouvement': '<S1>:1282' */
    /* Transition: '<S1>:1285' */
    ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt
      + 1.0;

    /* Transition: '<S1>:1286' */
    /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
    if (((ModeleRobot_DWork.CompteurTimeoutMvt > 5.0 /
          ModeleRobot_P.SFunction_p43) || (ModeleRobot_B.DataTypeConversion !=
          0.0)) != 0) {
      /* Transition: '<S1>:4211' */
      /* Exit 'ACTION_HOMOLO_11': '<S1>:4207' */
      /* Entry 'ACTION_HOMOLO_12': '<S1>:4210' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_12;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_12;

      /* on sort les recolteurs et on leur laisse 1sec */
      ModeleRobot_DWork.TempoMot = 0.0;

      /* Graphical Function 'setServo': '<S1>:4141' */
      /* Transition: '<S1>:4143' */
      ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p39 - 1.0)] =
        ModeleRobot_P.SFunction_p41;
    }
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_12:
    /* During 'ACTION_HOMOLO_12': '<S1>:4210' */
    if (ModeleRobot_DWork.TempoMot > 1.0 / ModeleRobot_P.SFunction_p43) {
      /* Transition: '<S1>:4214' */
      /* Exit 'ACTION_HOMOLO_12': '<S1>:4210' */
      /* Entry 'ACTION_HOMOLO_13': '<S1>:4213' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_13;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_13;

      /* on souffle pendant 2 secondes */
      ModeleRobot_DWork.TempoMot = 0.0;

      /* Graphical Function 'setPWM': '<S1>:4112' */
      /* Transition: '<S1>:4114' */
      ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p17 - 1.0)]
        = 100.0;
    }
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_13:
    /* During 'ACTION_HOMOLO_13': '<S1>:4213' */
    if (ModeleRobot_DWork.TempoMot > 2.0 / ModeleRobot_P.SFunction_p43) {
      /* Transition: '<S1>:4216' */
      /* Exit 'ACTION_HOMOLO_13': '<S1>:4213' */
      /* Entry 'ACTION_HOMOLO_14': '<S1>:4215' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_14;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_14;

      /* on arrete de souffler et on rentre les recolteurs */
      /* Graphical Function 'setPWM': '<S1>:4112' */
      /* Transition: '<S1>:4114' */
      ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p17 - 1.0)]
        = 0.0;

      /* Graphical Function 'setServo': '<S1>:4141' */
      /* Transition: '<S1>:4143' */
      ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p39 - 1.0)] =
        ModeleRobot_P.SFunction_p40;
    }
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_14:
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_15:
    /* During 'ACTION_HOMOLO_15': '<S1>:4237' */
    if (ModeleRobot_DWork.TempoMot > 0.3 / ModeleRobot_P.SFunction_p43) {
      /* Transition: '<S1>:4196' */
      /* Exit 'ACTION_HOMOLO_15': '<S1>:4237' */
      /* Entry 'ACTION_HOMOLO_05': '<S1>:4239' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_05;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_05;

      /* on descend l'ascenseur pour emprisonner spot + balle */
      /* Graphical Function 'setPWM': '<S1>:4112' */
      /* Transition: '<S1>:4114' */
      ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p14 - 1.0)]
        = -60.0;

      /* Graphical Function 'setServo': '<S1>:4141' */
      /* Transition: '<S1>:4143' */
      ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p33 - 1.0)] =
        ModeleRobot_P.SFunction_p34;

      /* Graphical Function 'setServo': '<S1>:4141' */
      /* Transition: '<S1>:4143' */
      ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
        ModeleRobot_P.SFunction_p28;

      /* tempo */
      ModeleRobot_DWork.TempoMot = 0.0;
    }
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_16:
    /* During 'ACTION_HOMOLO_16': '<S1>:4243' */
    if (ModeleRobot_DWork.TempoMot > 0.5 / ModeleRobot_P.SFunction_p43) {
      /* Transition: '<S1>:4236' */
      /* Exit 'ACTION_HOMOLO_16': '<S1>:4243' */
      /* Entry 'ACTION_HOMOLO_2': '<S1>:4167' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_2;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_2;

      /* on fait une diagonale pour pousser le deuxieme spots dans la zone de construction */
      /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
      /* Transition: '<S1>:3697' */
      ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
      ModeleRobot_B.ConsigneX = 85.0;
      ModeleRobot_B.ConsigneY = -72.0 * ModeleRobot_DWork.invMouv;
      ModeleRobot_B.ConsigneTeta = -0.99 * ModeleRobot_DWork.invMouv;
      ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    }
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_17:
    /* During 'ACTION_HOMOLO_17': '<S1>:4249' */
    if (ModeleRobot_DWork.TempoMot > 1.0 / ModeleRobot_P.SFunction_p43) {
      /* Transition: '<S1>:4250' */
      /* Exit 'ACTION_HOMOLO_17': '<S1>:4249' */
      /* Entry 'ACTION_HOMOLO_15': '<S1>:4237' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_15;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_15;

      /* on relache la balle */
      /* Graphical Function 'setServo': '<S1>:4141' */
      /* Transition: '<S1>:4143' */
      ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p33 - 1.0)] =
        ModeleRobot_P.SFunction_p36;

      /* Graphical Function 'setServo': '<S1>:4141' */
      /* Transition: '<S1>:4143' */
      ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
        ModeleRobot_P.SFunction_p30;
      ModeleRobot_DWork.TempoMot = 0.0;
    }
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_18:
    /* During 'ACTION_HOMOLO_18': '<S1>:4251' */
    /* Graphical Function 'isFinMouvement': '<S1>:1282' */
    /* Transition: '<S1>:1285' */
    ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt
      + 1.0;

    /* Transition: '<S1>:1286' */
    /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
    if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 /
          ModeleRobot_P.SFunction_p43) || (ModeleRobot_B.DataTypeConversion !=
          0.0)) != 0) {
      /* Transition: '<S1>:4252' */
      /* Exit 'ACTION_HOMOLO_18': '<S1>:4251' */
      /* Entry 'ACTION_HOMOLO_06': '<S1>:4254' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_06;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_06;

      /* on prend le gobelet */
      /* Graphical Function 'setServo': '<S1>:4141' */
      /* Transition: '<S1>:4143' */
      ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p33 - 1.0)] =
        ModeleRobot_P.SFunction_p38;

      /* Graphical Function 'setServo': '<S1>:4141' */
      /* Transition: '<S1>:4143' */
      ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
        ModeleRobot_P.SFunction_p32;

      /* tempo */
      ModeleRobot_DWork.TempoMot = 0.0;
    }
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_19:
    /* During 'ACTION_HOMOLO_19': '<S1>:4255' */
    /* Graphical Function 'isFinMouvement': '<S1>:1282' */
    /* Transition: '<S1>:1285' */
    ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt
      + 1.0;

    /* Transition: '<S1>:1286' */
    /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
    if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 /
          ModeleRobot_P.SFunction_p43) || (ModeleRobot_B.DataTypeConversion !=
          0.0)) != 0) {
      /* Transition: '<S1>:4260' */
      /* Exit 'ACTION_HOMOLO_19': '<S1>:4255' */
      /* Entry 'ACTION_HOMOLO_20': '<S1>:4258' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_20;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_20;

      /* on avance pour déposer le gobelet */
      /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
      /* Transition: '<S1>:3697' */
      ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
      ModeleRobot_B.ConsigneX = 39.0;
      ModeleRobot_B.ConsigneY = 0.0 * ModeleRobot_DWork.invMouv;
      ModeleRobot_B.ConsigneTeta = 3.14 * ModeleRobot_DWork.invMouv;
      ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    }
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_2:
    /* During 'ACTION_HOMOLO_2': '<S1>:4167' */
    /* Graphical Function 'isFinMouvement': '<S1>:1282' */
    /* Transition: '<S1>:1285' */
    ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt
      + 1.0;

    /* Transition: '<S1>:1286' */
    /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
    if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 /
          ModeleRobot_P.SFunction_p43) || (ModeleRobot_B.DataTypeConversion !=
          0.0)) != 0) {
      /* Transition: '<S1>:4170' */
      /* Exit 'ACTION_HOMOLO_2': '<S1>:4167' */
      /* Graphical Function 'setServo': '<S1>:4141' */
      /* Transition: '<S1>:4143' */
      ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p33 - 1.0)] =
        ModeleRobot_P.SFunction_p37;

      /* Graphical Function 'setServo': '<S1>:4141' */
      /* Transition: '<S1>:4143' */
      ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
        ModeleRobot_P.SFunction_p31;

      /* Entry 'ACTION_HOMOLO_4': '<S1>:4169' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_4;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_4;

      /* on recule pour laisser les spots */
      /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
      /* Transition: '<S1>:3697' */
      ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
      ModeleRobot_B.ConsigneX = 67.0;
      ModeleRobot_B.ConsigneY = -45.0 * ModeleRobot_DWork.invMouv;
      ModeleRobot_B.ConsigneTeta = -0.99 * ModeleRobot_DWork.invMouv;
      ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    }
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_20:
    /* During 'ACTION_HOMOLO_20': '<S1>:4258' */
    /* Graphical Function 'isFinMouvement': '<S1>:1282' */
    /* Transition: '<S1>:1285' */
    ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt
      + 1.0;

    /* Transition: '<S1>:1286' */
    /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
    if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 /
          ModeleRobot_P.SFunction_p43) || (ModeleRobot_B.DataTypeConversion !=
          0.0)) != 0) {
      /* Transition: '<S1>:4259' */
      /* Exit 'ACTION_HOMOLO_20': '<S1>:4258' */
      /* Entry 'ACTION_HOMOLO_07': '<S1>:4261' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_07;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_07;

      /* on lache le gobelet */
      /* Graphical Function 'setServo': '<S1>:4141' */
      /* Transition: '<S1>:4143' */
      ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p33 - 1.0)] =
        ModeleRobot_P.SFunction_p37;

      /* Graphical Function 'setServo': '<S1>:4141' */
      /* Transition: '<S1>:4143' */
      ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
        ModeleRobot_P.SFunction_p31;

      /* tempo */
      ModeleRobot_DWork.TempoMot = 0.0;
    }
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_21:
    /* During 'ACTION_HOMOLO_21': '<S1>:4262' */
    /* Transition: '<S1>:4268' */
    /* Exit 'ACTION_HOMOLO_21': '<S1>:4262' */
    /* Entry 'ACTION_HOMOLO_08': '<S1>:4265' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_08;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_08;

    /* on remonte les pinces */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p14 - 1.0)] =
      60.0;

    /* tempo */
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_22:
    /* During 'ACTION_HOMOLO_22': '<S1>:4266' */
    if (ModeleRobot_DWork.TempoMot > 0.5 / ModeleRobot_P.SFunction_p43) {
      /* Transition: '<S1>:4270' */
      /* Exit 'ACTION_HOMOLO_22': '<S1>:4266' */
      /* Entry 'ACTION_HOMOLO_23': '<S1>:4269' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_23;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_23;

      /* on rentre les centreurs */
      /* Graphical Function 'setServo': '<S1>:4141' */
      /* Transition: '<S1>:4143' */
      ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
        ModeleRobot_P.SFunction_p25;
      ModeleRobot_DWork.TempoMot = 0.0;
    }
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_23:
    /* During 'ACTION_HOMOLO_23': '<S1>:4269' */
    if (ModeleRobot_P.SFunction_p6 == 0) {
      /* Transition: '<S1>:4122' */
      /* Exit 'ACTION_HOMOLO_23': '<S1>:4269' */
      /* Entry 'ACTION_0': '<S1>:4121' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_0;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_0;

      /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
      /* Transition: '<S1>:3697' */
      ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
      ModeleRobot_B.ConsigneX = 46.00;
      ModeleRobot_B.ConsigneY = 0.00;
      ModeleRobot_B.ConsigneTeta = 0.0000;
      ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    }
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_4:
    /* During 'ACTION_HOMOLO_4': '<S1>:4169' */
    /* Graphical Function 'isFinMouvement': '<S1>:1282' */
    /* Transition: '<S1>:1285' */
    ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt
      + 1.0;

    /* Transition: '<S1>:1286' */
    /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
    if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 /
          ModeleRobot_P.SFunction_p43) || (ModeleRobot_B.DataTypeConversion !=
          0.0)) != 0) {
      /* Transition: '<S1>:4173' */
      /* Exit 'ACTION_HOMOLO_4': '<S1>:4169' */
      /* Entry 'ACTION_HOMOLO_5': '<S1>:4171' */
      ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_5;
      ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_5;

      /* on se tourne vers le gobelet */
      /* Graphical Function 'Mouvement_Angle': '<S1>:1354' */
      /* Transition: '<S1>:1356' */
      ModeleRobot_B.DdeMvtDistanceAngle = ModeleRobot_B.DdeMvtDistanceAngle +
        1.0;
      ModeleRobot_B.ConsigneDistance = 0.0;
      ModeleRobot_B.ConsigneTeta = -2.68 * ModeleRobot_DWork.invMouv;
      ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    }
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_5:
    ModeleRobot_ACTION_HOMOLO_5();
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_6:
    ModeleRobot_ACTION_HOMOLO_6();
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_7:
    ModeleRobot_ACTION_HOMOLO_7();
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_8:
    ModeleRobot_ACTION_HOMOLO_8();
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_9:
    ModeleRobot_ACTION_HOMOLO_9();
    break;

   default:
    ModeleRobot_enter_internal_DEMO();
    break;
  }
}

/* Initial conditions for atomic system: '<Root>/COMPORTEMENT' */
void ModeleRobot_COMPORTEMENT_Init(void)
{
  /* InitializeConditions for Stateflow: '<Root>/COMPORTEMENT' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/isFrontMontantConvergence'
   *  InitializeConditions for SubSystem: '<S1>/isFrontMontantMvtBloque'
   */

  /* InitializeConditions for UnitDelay: '<S8>/Delay Input1' */
  ModeleRobot_DWork.DelayInput1_DSTATE_d = ModeleRobot_P.DelayInput1_X0_m;

  /* InitializeConditions for UnitDelay: '<S11>/Delay Input1' */
  ModeleRobot_DWork.DelayInput1_DSTATE_p = ModeleRobot_P.DelayInput1_X0_o;
}

/* Output and update for atomic system: '<Root>/COMPORTEMENT' */
void ModeleRobot_COMPORTEMENT(void)
{
  /* Stateflow: '<Root>/COMPORTEMENT' incorporates:
   *  Inport: '<Root>/IN_Ascenseur_pos'
   *  Inport: '<Root>/IN_CouleurEquipe'
   *  Inport: '<Root>/IN_FinCourseAscenseur'
   *  Inport: '<Root>/IN_Tirette'
   *  Inport: '<Root>/IN_demande_test_actionneurs'
   */
  /* Gateway: COMPORTEMENT */
  /* During: COMPORTEMENT */
  if (ModeleRobot_DWork.is_active_c1_ModeleRobot == 0) {
    /* Entry: COMPORTEMENT */
    ModeleRobot_DWork.is_active_c1_ModeleRobot = 1U;

    /* Entry 'COMPORTEMENT_ROBOT': '<S1>:1004' */
    ModeleRobot_DWork.is_active_COMPORTEMENT_ROBOT = 1U;
    enter_internal_COMPORTEMENT_ROB();

    /* Entry 'FONCTIONS_GLOBALES_DEPLACEMENT_ROBOT': '<S1>:936' */
    ModeleRobot_DWork.is_active_FONCTIONS_GLOBALES_DE = 1U;

    /* Entry 'FONCTIONS_GLOBALES_COMMANDE_SERVOS_MOTEURS': '<S1>:1312' */
    ModeleRobot_DWork.is_active_FONCTIONS_GLOBALES__m = 1U;

    /* Entry 'FONCTIONS_GLOBALES_DETECTION_OBSTACLES': '<S1>:1315' */
    ModeleRobot_DWork.is_active_FONCTIONS_GLOBALES__j = 1U;

    /* Entry 'FONCTIONS_GLOBALES_COMMANDE_LEDS': '<S1>:1318' */
    ModeleRobot_DWork.is_active_FONCTIONS_GLOBALES_CO = 1U;

    /* Entry 'FONCTIONS_GLOBALES_DIVERS': '<S1>:1335' */
    ModeleRobot_DWork.is_active_FONCTIONS_GLOBALES_DI = 1U;

    /* Entry 'FONCTIONS_RECalAGE_POSITION': '<S1>:2810' */
    ModeleRobot_DWork.is_active_FONCTIONS_RECalAGE_PO = 1U;
  } else {
    /* During 'COMPORTEMENT_ROBOT': '<S1>:1004' */
    switch (ModeleRobot_DWork.is_COMPORTEMENT_ROBOT) {
     case ModeleRobot_IN_ATTENTE_TIRETTE:
      /* During 'ATTENTE_TIRETTE': '<S1>:1005' */
      if (ModeleRobot_U.IN_Tirette != 0.0) {
        /* Transition: '<S1>:1265' */
        /* Exit 'INIT': '<S1>:1109' */
        ModeleRobot_DWork.is_TESTS_ACTIONNEUR = (uint8_T)
          ModeleRobot_IN_NO_ACTIVE_CHILD;

        /* Exit 'INIT1': '<S1>:3674' */
        /* Exit 'TEST_ACT_1': '<S1>:1417' */
        /* Exit 'TEST_ACT_2': '<S1>:3798' */
        /* Exit 'TEST_ACT_3': '<S1>:4151' */
        /* Exit 'TEST_ACT_FIN': '<S1>:1515' */
        /* Exit 'TESTS_ACTIONNEUR': '<S1>:1036' */
        ModeleRobot_DWork.is_active_TESTS_ACTIONNEUR = 0U;

        /* Exit 'RECALAGE': '<S1>:1017' */
        ModeleRobot_DWork.is_active_RECALAGE = 0U;

        /* Exit 'EQUIPE_1': '<S1>:1016' */
        ModeleRobot_DWork.is_CHOIX_EQUIPE = (uint8_T)
          ModeleRobot_IN_NO_ACTIVE_CHILD;

        /* Exit 'EQUIPE_2': '<S1>:1015' */
        /* Exit 'CHOIX_EQUIPE': '<S1>:1011' */
        ModeleRobot_DWork.is_active_CHOIX_EQUIPE = 0U;

        /* Exit 'APPRENTISSAGE_KMAR_01': '<S1>:1010' */
        ModeleRobot_DWork.is_ACTIONNEURS_REPOS = (uint8_T)
          ModeleRobot_IN_NO_ACTIVE_CHILD;

        /* Exit 'APPRENTISSAGE_KMAR_02': '<S1>:3687' */
        /* Exit 'APPRENTISSAGE_KMAR_03': '<S1>:3689' */
        /* Exit 'FIN_REPOS_ACTIONNEUR': '<S1>:3692' */
        /* Exit 'REPOS_SERVOS': '<S1>:1009' */
        /* Exit 'ACTIONNEURS_REPOS': '<S1>:1006' */
        ModeleRobot_DWork.is_active_ACTIONNEURS_REPOS = 0U;

        /* Exit 'ATTENTE_TIRETTE': '<S1>:1005' */
        /* Entry 'MATCH': '<S1>:1117' */
        ModeleRobot_DWork.is_COMPORTEMENT_ROBOT = (uint8_T)ModeleRobot_IN_MATCH;

        /* Entry 'CLOCK': '<S1>:1118' */
        ModeleRobot_DWork.is_active_CLOCK = 1U;

        /* Entry 'STRATEGIE': '<S1>:1119' */
        ModeleRobot_DWork.is_active_STRATEGIE = 1U;

        /* Transition: '<S1>:1120' */
        /* Entry 'STRATEGIE1': '<S1>:1123' */
        ModeleRobot_DWork.is_STRATEGIE = (uint8_T)ModeleRobot_IN_STRATEGIE1;
        Model_enter_internal_STRATEGIE1();
      } else {
        /* During 'ACTIONNEURS_REPOS': '<S1>:1006' */
        switch (ModeleRobot_DWork.is_ACTIONNEURS_REPOS) {
         case Modele_IN_APPRENTISSAGE_KMAR_01:
          /* During 'APPRENTISSAGE_KMAR_01': '<S1>:1010' */
          if ((ModeleRobot_U.IN_FinCourseAscenseur == 1) ||
              (ModeleRobot_DWork.TempoInit > 5.0 / ModeleRobot_P.SFunction_p43))
          {
            /* Transition: '<S1>:3688' */
            /* Exit 'APPRENTISSAGE_KMAR_01': '<S1>:1010' */
            /* Entry 'APPRENTISSAGE_KMAR_02': '<S1>:3687' */
            ModeleRobot_DWork.is_ACTIONNEURS_REPOS = (uint8_T)
              Modele_IN_APPRENTISSAGE_KMAR_02;

            /* on est en butee on arrete immediatement l'ascenseur */
            /* Graphical Function 'setPWM': '<S1>:4112' */
            /* Transition: '<S1>:4114' */
            ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p14 -
              1.0)] = 0.0;

            /* On fait le reset du codeur ascenseur */
            ModeleRobot_B.ResetCodeurAscenseur = 1.0;
            ModeleRobot_DWork.TempoInit = 0.0;
          } else {
            ModeleRobot_DWork.TempoInit = ModeleRobot_DWork.TempoInit + 1.0;
          }
          break;

         case Modele_IN_APPRENTISSAGE_KMAR_02:
          /* During 'APPRENTISSAGE_KMAR_02': '<S1>:3687' */
          if (ModeleRobot_DWork.TempoInit > 1.0 / ModeleRobot_P.SFunction_p43) {
            /* Transition: '<S1>:3691' */
            /* Exit 'APPRENTISSAGE_KMAR_02': '<S1>:3687' */
            /* Entry 'APPRENTISSAGE_KMAR_03': '<S1>:3689' */
            ModeleRobot_DWork.is_ACTIONNEURS_REPOS = (uint8_T)
              Modele_IN_APPRENTISSAGE_KMAR_03;

            /* on remonte l'ascenseur jusqu'a la position d'un feu en haut de la torche */
            /* Graphical Function 'setPWM': '<S1>:4112' */
            /* Transition: '<S1>:4114' */
            ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p14 -
              1.0)] = 60.0;

            /* On relache le reset du codeur ascenseur */
            ModeleRobot_B.ResetCodeurAscenseur = 0.0;

            /* meme si on a un apprentissage des positions par securite on met une tempo */
            ModeleRobot_DWork.TempoInit = 0.0;
          } else {
            ModeleRobot_DWork.TempoInit = ModeleRobot_DWork.TempoInit + 1.0;
          }
          break;

         case Modele_IN_APPRENTISSAGE_KMAR_03:
          /* During 'APPRENTISSAGE_KMAR_03': '<S1>:3689' */
          if ((ModeleRobot_U.IN_Ascenseur_pos >= ModeleRobot_P.SFunction_p9) ||
              (ModeleRobot_DWork.TempoInit > 4.0 / ModeleRobot_P.SFunction_p43))
          {
            /* Transition: '<S1>:3693' */
            /* Exit 'APPRENTISSAGE_KMAR_03': '<S1>:3689' */
            /* Entry 'FIN_REPOS_ACTIONNEUR': '<S1>:3692' */
            ModeleRobot_DWork.is_ACTIONNEURS_REPOS = (uint8_T)
              ModeleR_IN_FIN_REPOS_ACTIONNEUR;

            /* on arrete l'ascenseur */
            /* Graphical Function 'setPWM': '<S1>:4112' */
            /* Transition: '<S1>:4114' */
            ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p14 -
              1.0)] = 0.0;
          } else {
            ModeleRobot_DWork.TempoInit = ModeleRobot_DWork.TempoInit + 1.0;
          }
          break;

         case ModeleR_IN_FIN_REPOS_ACTIONNEUR:
          break;

         case ModeleRobot_IN_REPOS_SERVOS:
          /* During 'REPOS_SERVOS': '<S1>:1009' */
          if (ModeleRobot_DWork.TempoInit > 2.0 / ModeleRobot_P.SFunction_p43) {
            /* Transition: '<S1>:1008' */
            /* Exit 'REPOS_SERVOS': '<S1>:1009' */
            /* Entry 'APPRENTISSAGE_KMAR_01': '<S1>:1010' */
            ModeleRobot_DWork.is_ACTIONNEURS_REPOS = (uint8_T)
              Modele_IN_APPRENTISSAGE_KMAR_01;

            /* les pinces sont rangees on peut descendre l'ascenseur */
            /* Graphical Function 'setPWM': '<S1>:4112' */
            /* Transition: '<S1>:4114' */
            ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p14 -
              1.0)] = -60.0;

            /* meme si on a un capteur de fin de course, par securite on met une tempo */
            ModeleRobot_DWork.TempoInit = 0.0;
          } else {
            ModeleRobot_DWork.TempoInit = ModeleRobot_DWork.TempoInit + 1.0;
          }
          break;

         default:
          enter_internal_ACTIONNEURS_REPO();
          break;
        }

        /* During 'CHOIX_EQUIPE': '<S1>:1011' */
        switch (ModeleRobot_DWork.is_CHOIX_EQUIPE) {
         case ModeleRobot_IN_EQUIPE_1:
          /* During 'EQUIPE_1': '<S1>:1016' */
          if (ModeleRobot_U.IN_CouleurEquipe == ModeleRobot_P.SFunction_p4) {
            /* Transition: '<S1>:1013' */
            /* Exit 'EQUIPE_1': '<S1>:1016' */
            /* Entry 'EQUIPE_2': '<S1>:1015' */
            ModeleRobot_DWork.is_CHOIX_EQUIPE = (uint8_T)ModeleRobot_IN_EQUIPE_2;
            ModeleRobot_B.EtatLed1 = 0.0;
            ModeleRobot_B.EtatLed2 = 1.0;
            ModeleRobot_DWork.invMouv = 1.0;
          }
          break;

         case ModeleRobot_IN_EQUIPE_2:
          /* During 'EQUIPE_2': '<S1>:1015' */
          if (ModeleRobot_U.IN_CouleurEquipe == ModeleRobot_P.SFunction_p5) {
            /* Transition: '<S1>:1014' */
            /* Exit 'EQUIPE_2': '<S1>:1015' */
            /* Entry 'EQUIPE_1': '<S1>:1016' */
            ModeleRobot_DWork.is_CHOIX_EQUIPE = (uint8_T)ModeleRobot_IN_EQUIPE_1;
            ModeleRobot_B.EtatLed1 = 1.0;
            ModeleRobot_B.EtatLed2 = 0.0;
            ModeleRobot_DWork.invMouv = -1.0;
          }
          break;

         default:
          /* Transition: '<S1>:1012' */
          /* Entry 'EQUIPE_1': '<S1>:1016' */
          ModeleRobot_DWork.is_CHOIX_EQUIPE = (uint8_T)ModeleRobot_IN_EQUIPE_1;
          ModeleRobot_B.EtatLed1 = 1.0;
          ModeleRobot_B.EtatLed2 = 0.0;
          ModeleRobot_DWork.invMouv = -1.0;
          break;
        }

        /* During 'RECALAGE': '<S1>:1017' */
        ModeleRobot_DWork.TempoMot = ModeleRobot_DWork.TempoMot + 1.0;

        /* During 'TESTS_ACTIONNEUR': '<S1>:1036' */
        ModeleRobot_DWork.TempoTestActionneurs =
          ModeleRobot_DWork.TempoTestActionneurs + 1.0;
        switch (ModeleRobot_DWork.is_TESTS_ACTIONNEUR) {
         case ModeleRobot_IN_INIT:
          /* During 'INIT': '<S1>:1109' */
          /* Transition: '<S1>:3675' */
          if (ModeleRobot_U.IN_demande_test_actionneurs != 0) {
            /* Transition: '<S1>:3677' */
            /* Exit 'INIT': '<S1>:1109' */
            /* Entry 'INIT1': '<S1>:3674' */
            ModeleRobot_DWork.is_TESTS_ACTIONNEUR = (uint8_T)
              ModeleRobot_IN_INIT1;
            ModeleRobot_DWork.TempoTestActionneurs = 0.0;
          }
          break;

         case ModeleRobot_IN_INIT1:
          /* During 'INIT1': '<S1>:3674' */
          if (ModeleRobot_DWork.TempoTestActionneurs > 2.0 /
              ModeleRobot_P.SFunction_p43) {
            /* Transition: '<S1>:1418' */
            /* Exit 'INIT1': '<S1>:3674' */
            /* Entry 'TEST_ACT_1': '<S1>:1417' */
            ModeleRobot_DWork.is_TESTS_ACTIONNEUR = (uint8_T)
              ModeleRobot_IN_TEST_ACT_1;
            ModeleRobot_DWork.TempoTestActionneurs = 0.0;

            /* Graphical Function 'setServo': '<S1>:4141' */
            /* Transition: '<S1>:4143' */
            ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p33 -
              1.0)] = ModeleRobot_P.SFunction_p35;
          }
          break;

         case ModeleRobot_IN_TEST_ACT_1:
          /* During 'TEST_ACT_1': '<S1>:1417' */
          if (ModeleRobot_DWork.TempoTestActionneurs > 2.0 /
              ModeleRobot_P.SFunction_p43) {
            /* Transition: '<S1>:1446' */
            /* Exit 'TEST_ACT_1': '<S1>:1417' */
            /* Entry 'TEST_ACT_2': '<S1>:3798' */
            ModeleRobot_DWork.is_TESTS_ACTIONNEUR = (uint8_T)
              ModeleRobot_IN_TEST_ACT_2;
            ModeleRobot_DWork.TempoTestActionneurs = 0.0;

            /* Graphical Function 'setServo': '<S1>:4141' */
            /* Transition: '<S1>:4143' */
            ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p33 -
              1.0)] = ModeleRobot_P.SFunction_p37;

            /* Graphical Function 'setServo': '<S1>:4141' */
            /* Transition: '<S1>:4143' */
            ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 -
              1.0)] = ModeleRobot_P.SFunction_p29;
          }
          break;

         case ModeleRobot_IN_TEST_ACT_2:
          /* During 'TEST_ACT_2': '<S1>:3798' */
          if (ModeleRobot_DWork.TempoTestActionneurs > 2.0 /
              ModeleRobot_P.SFunction_p43) {
            /* Transition: '<S1>:3803' */
            /* Exit 'TEST_ACT_2': '<S1>:3798' */
            /* Entry 'TEST_ACT_3': '<S1>:4151' */
            ModeleRobot_DWork.is_TESTS_ACTIONNEUR = (uint8_T)
              ModeleRobot_IN_TEST_ACT_3;
            ModeleRobot_DWork.TempoTestActionneurs = 0.0;

            /* Graphical Function 'setServo': '<S1>:4141' */
            /* Transition: '<S1>:4143' */
            ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 -
              1.0)] = ModeleRobot_P.SFunction_p31;
          }
          break;

         case ModeleRobot_IN_TEST_ACT_3:
          /* During 'TEST_ACT_3': '<S1>:4151' */
          if (ModeleRobot_DWork.TempoTestActionneurs > 2.0 /
              ModeleRobot_P.SFunction_p43) {
            /* Transition: '<S1>:4152' */
            /* Exit 'TEST_ACT_3': '<S1>:4151' */
            /* Entry 'TEST_ACT_FIN': '<S1>:1515' */
            ModeleRobot_DWork.is_TESTS_ACTIONNEUR = (uint8_T)
              ModeleRobot_IN_TEST_ACT_FIN;
            ModeleRobot_DWork.TempoTestActionneurs = 0.0;
          }
          break;

         case ModeleRobot_IN_TEST_ACT_FIN:
          /* During 'TEST_ACT_FIN': '<S1>:1515' */
          /* Transition: '<S1>:3678' */
          if (ModeleRobot_U.IN_demande_test_actionneurs != 0) {
            /* Transition: '<S1>:3677' */
            /* Exit 'TEST_ACT_FIN': '<S1>:1515' */
            /* Entry 'INIT1': '<S1>:3674' */
            ModeleRobot_DWork.is_TESTS_ACTIONNEUR = (uint8_T)
              ModeleRobot_IN_INIT1;
            ModeleRobot_DWork.TempoTestActionneurs = 0.0;
          }
          break;

         default:
          /* Transition: '<S1>:1064' */
          /* Entry 'INIT': '<S1>:1109' */
          ModeleRobot_DWork.is_TESTS_ACTIONNEUR = (uint8_T)ModeleRobot_IN_INIT;
          break;
        }
      }
      break;

     case ModeleRobot_IN_FIN_MATCH:
      /* During 'FIN_MATCH': '<S1>:1258' */
      switch (ModeleRobot_DWork.is_FIN_MATCH) {
       case ModeleRobot_IN_FIN_MATCH_01:
        /* During 'FIN_MATCH_01': '<S1>:1262' */
        /* Transition: '<S1>:1260' */
        /* Exit 'FIN_MATCH_01': '<S1>:1262' */
        /* Entry 'FIN_MATCH_02': '<S1>:1263' */
        ModeleRobot_DWork.is_FIN_MATCH = (uint8_T)ModeleRobot_IN_FIN_MATCH_02;

        /* chenillard de led */
        /* Graphical Function 'CommandeLEDS_RVBO': '<S1>:1339' */
        /* Transition: '<S1>:1341' */
        ModeleRobot_B.EtatLed1 = 1.0;
        ModeleRobot_B.EtatLed2 = 0.0;
        ModeleRobot_B.EtatLed3 = 0.0;
        ModeleRobot_B.EtatLed4 = 0.0;
        ModeleRobot_DWork.TempoImage = 0.0;
        break;

       case ModeleRobot_IN_FIN_MATCH_02:
        /* During 'FIN_MATCH_02': '<S1>:1263' */
        if (ModeleRobot_DWork.TempoImage > 1.0 / ModeleRobot_P.SFunction_p43) {
          /* Transition: '<S1>:3781' */
          /* Exit 'FIN_MATCH_02': '<S1>:1263' */
          /* Entry 'FIN_MATCH_03': '<S1>:3777' */
          ModeleRobot_DWork.is_FIN_MATCH = (uint8_T)ModeleRobot_IN_FIN_MATCH_03;

          /* chenillard de led */
          /* Graphical Function 'CommandeLEDS_RVBO': '<S1>:1339' */
          /* Transition: '<S1>:1341' */
          ModeleRobot_B.EtatLed1 = 0.0;
          ModeleRobot_B.EtatLed2 = 1.0;
          ModeleRobot_B.EtatLed3 = 0.0;
          ModeleRobot_B.EtatLed4 = 0.0;
          ModeleRobot_DWork.TempoImage = 0.0;
        } else {
          ModeleRobot_DWork.TempoImage = ModeleRobot_DWork.TempoImage + 1.0;
        }
        break;

       case ModeleRobot_IN_FIN_MATCH_03:
        /* During 'FIN_MATCH_03': '<S1>:3777' */
        if (ModeleRobot_DWork.TempoImage > 1.0 / ModeleRobot_P.SFunction_p43) {
          /* Transition: '<S1>:3782' */
          /* Exit 'FIN_MATCH_03': '<S1>:3777' */
          /* Entry 'FIN_MATCH_04': '<S1>:3778' */
          ModeleRobot_DWork.is_FIN_MATCH = (uint8_T)ModeleRobot_IN_FIN_MATCH_04;

          /* chenillard de led */
          /* Graphical Function 'CommandeLEDS_RVBO': '<S1>:1339' */
          /* Transition: '<S1>:1341' */
          ModeleRobot_B.EtatLed1 = 0.0;
          ModeleRobot_B.EtatLed2 = 0.0;
          ModeleRobot_B.EtatLed3 = 1.0;
          ModeleRobot_B.EtatLed4 = 0.0;
          ModeleRobot_DWork.TempoImage = 0.0;
        } else {
          ModeleRobot_DWork.TempoImage = ModeleRobot_DWork.TempoImage + 1.0;
        }
        break;

       case ModeleRobot_IN_FIN_MATCH_04:
        /* During 'FIN_MATCH_04': '<S1>:3778' */
        if (ModeleRobot_DWork.TempoImage > 1.0 / ModeleRobot_P.SFunction_p43) {
          /* Transition: '<S1>:3783' */
          /* Exit 'FIN_MATCH_04': '<S1>:3778' */
          /* Entry 'FIN_MATCH_05': '<S1>:3779' */
          ModeleRobot_DWork.is_FIN_MATCH = (uint8_T)ModeleRobot_IN_FIN_MATCH_05;

          /* chenillard de led */
          /* Graphical Function 'CommandeLEDS_RVBO': '<S1>:1339' */
          /* Transition: '<S1>:1341' */
          ModeleRobot_B.EtatLed1 = 0.0;
          ModeleRobot_B.EtatLed2 = 0.0;
          ModeleRobot_B.EtatLed3 = 0.0;
          ModeleRobot_B.EtatLed4 = 1.0;
          ModeleRobot_DWork.TempoImage = 0.0;
        } else {
          ModeleRobot_DWork.TempoImage = ModeleRobot_DWork.TempoImage + 1.0;
        }
        break;

       case ModeleRobot_IN_FIN_MATCH_05:
        /* During 'FIN_MATCH_05': '<S1>:3779' */
        if (ModeleRobot_DWork.TempoImage > 1.0 / ModeleRobot_P.SFunction_p43) {
          /* Transition: '<S1>:3784' */
          /* Exit 'FIN_MATCH_05': '<S1>:3779' */
          /* Entry 'FIN_MATCH_02': '<S1>:1263' */
          ModeleRobot_DWork.is_FIN_MATCH = (uint8_T)ModeleRobot_IN_FIN_MATCH_02;

          /* chenillard de led */
          /* Graphical Function 'CommandeLEDS_RVBO': '<S1>:1339' */
          /* Transition: '<S1>:1341' */
          ModeleRobot_B.EtatLed1 = 1.0;
          ModeleRobot_B.EtatLed2 = 0.0;
          ModeleRobot_B.EtatLed3 = 0.0;
          ModeleRobot_B.EtatLed4 = 0.0;
          ModeleRobot_DWork.TempoImage = 0.0;
        } else {
          ModeleRobot_DWork.TempoImage = ModeleRobot_DWork.TempoImage + 1.0;
        }
        break;

       default:
        /* Transition: '<S1>:1259' */
        /* Entry 'FIN_MATCH_01': '<S1>:1262' */
        ModeleRobot_DWork.is_FIN_MATCH = (uint8_T)ModeleRobot_IN_FIN_MATCH_01;

        /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
        /* Transition: '<S1>:1301' */
        ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
        ModeleRobot_B.CommandeManuelleG = 0.0;
        ModeleRobot_B.CommandeManuelleD = 0.0;

        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p33 - 1.0)]
          = ModeleRobot_P.SFunction_p37;

        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)]
          = ModeleRobot_P.SFunction_p31;

        /* Graphical Function 'CommandeLEDS_RVBO': '<S1>:1339' */
        /* Transition: '<S1>:1341' */
        ModeleRobot_B.EtatLed1 = 1.0;
        ModeleRobot_B.EtatLed2 = 1.0;
        ModeleRobot_B.EtatLed3 = 1.0;
        ModeleRobot_B.EtatLed4 = 1.0;
        break;
      }
      break;

     case ModeleRobot_IN_MATCH:
      /* During 'MATCH': '<S1>:1117' */
      if ((ModeleRobot_DWork.DureeMatch > 300.0 / ModeleRobot_P.SFunction_p43) ||
          (ModeleRobot_DWork.finHomologation == 1.0)) {
        /* Transition: '<S1>:1266' */
        if (ModeleRobot_DWork.is_STRATEGIE == ModeleRobot_IN_STRATEGIE1) {
          if (ModeleRobot_DWork.is_STRATEGIE1 == ModeleRobot_IN_DEMO) {
            if (ModeleRobot_DWork.is_DEMO == ModeleRobot_IN_ACTION_HOMOLO_2) {
              /* Exit 'ACTION_HOMOLO_2': '<S1>:4167' */
              /* Graphical Function 'setServo': '<S1>:4141' */
              /* Transition: '<S1>:4143' */
              ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p33
                - 1.0)] = ModeleRobot_P.SFunction_p37;

              /* Graphical Function 'setServo': '<S1>:4141' */
              /* Transition: '<S1>:4143' */
              ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27
                - 1.0)] = ModeleRobot_P.SFunction_p31;
              ModeleRobot_DWork.is_DEMO = (uint8_T)
                ModeleRobot_IN_NO_ACTIVE_CHILD;
            } else {
              /* Exit 'ACTION_0': '<S1>:4121' */
              /* Exit 'ACTION_10': '<S1>:4131' */
              /* Exit 'ACTION_12': '<S1>:4133' */
              /* Exit 'ACTION_14': '<S1>:4135' */
              /* Exit 'ACTION_16': '<S1>:4137' */
              /* Exit 'ACTION_18': '<S1>:4139' */
              /* Exit 'ACTION_2': '<S1>:4123' */
              /* Exit 'ACTION_4': '<S1>:4125' */
              /* Exit 'ACTION_6': '<S1>:4127' */
              /* Exit 'ACTION_8': '<S1>:4129' */
              /* Exit 'ACTION_HOMOLO_0': '<S1>:4165' */
              /* Exit 'ACTION_HOMOLO_01': '<S1>:4181' */
              /* Exit 'ACTION_HOMOLO_02': '<S1>:4183' */
              /* Exit 'ACTION_HOMOLO_03': '<S1>:4220' */
              /* Exit 'ACTION_HOMOLO_05': '<S1>:4239' */
              /* Exit 'ACTION_HOMOLO_06': '<S1>:4254' */
              /* Exit 'ACTION_HOMOLO_07': '<S1>:4261' */
              /* Exit 'ACTION_HOMOLO_08': '<S1>:4265' */
              /* Exit 'ACTION_HOMOLO_10': '<S1>:4204' */
              /* Exit 'ACTION_HOMOLO_11': '<S1>:4207' */
              /* Exit 'ACTION_HOMOLO_12': '<S1>:4210' */
              /* Exit 'ACTION_HOMOLO_13': '<S1>:4213' */
              /* Exit 'ACTION_HOMOLO_14': '<S1>:4215' */
              /* Exit 'ACTION_HOMOLO_15': '<S1>:4237' */
              /* Exit 'ACTION_HOMOLO_16': '<S1>:4243' */
              /* Exit 'ACTION_HOMOLO_17': '<S1>:4249' */
              /* Exit 'ACTION_HOMOLO_18': '<S1>:4251' */
              /* Exit 'ACTION_HOMOLO_19': '<S1>:4255' */
              /* Exit 'ACTION_HOMOLO_20': '<S1>:4258' */
              /* Exit 'ACTION_HOMOLO_21': '<S1>:4262' */
              /* Exit 'ACTION_HOMOLO_22': '<S1>:4266' */
              /* Exit 'ACTION_HOMOLO_23': '<S1>:4269' */
              /* Exit 'ACTION_HOMOLO_4': '<S1>:4169' */
              /* Exit 'ACTION_HOMOLO_5': '<S1>:4171' */
              /* Exit 'ACTION_HOMOLO_6': '<S1>:4187' */
              /* Exit 'ACTION_HOMOLO_7': '<S1>:4189' */
              /* Exit 'ACTION_HOMOLO_8': '<S1>:4192' */
              /* Exit 'ACTION_HOMOLO_9': '<S1>:4203' */
            }

            /* Exit 'DEMO': '<S1>:3463' */
            ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)
              ModeleRobot_IN_NO_ACTIVE_CHILD;
          } else {
            /* Exit 'INIT_STRATEGIE': '<S1>:1128' */
          }

          /* Exit 'STRATEGIE1': '<S1>:1123' */
          ModeleRobot_DWork.is_STRATEGIE = (uint8_T)
            ModeleRobot_IN_NO_ACTIVE_CHILD;
        } else {
          /* Exit 'DETECT_OBSTACLE': '<S1>:3816' */
          ModeleRobot_DWork.is_EVITEMENT = (uint8_T)
            ModeleRobot_IN_NO_ACTIVE_CHILD;

          /* Exit 'DETECT_OBSTACLE1': '<S1>:3815' */
          /* Exit 'EVITEMENT': '<S1>:3814' */
        }

        /* Exit 'STRATEGIE': '<S1>:1119' */
        ModeleRobot_DWork.is_active_STRATEGIE = 0U;

        /* Exit 'CLOCK': '<S1>:1118' */
        ModeleRobot_DWork.is_active_CLOCK = 0U;

        /* Exit 'MATCH': '<S1>:1117' */
        /* Entry 'FIN_MATCH': '<S1>:1258' */
        ModeleRobot_DWork.is_COMPORTEMENT_ROBOT = (uint8_T)
          ModeleRobot_IN_FIN_MATCH;

        /* Transition: '<S1>:1259' */
        /* Entry 'FIN_MATCH_01': '<S1>:1262' */
        ModeleRobot_DWork.is_FIN_MATCH = (uint8_T)ModeleRobot_IN_FIN_MATCH_01;

        /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
        /* Transition: '<S1>:1301' */
        ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
        ModeleRobot_B.CommandeManuelleG = 0.0;
        ModeleRobot_B.CommandeManuelleD = 0.0;

        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p33 - 1.0)]
          = ModeleRobot_P.SFunction_p37;

        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)]
          = ModeleRobot_P.SFunction_p31;

        /* Graphical Function 'CommandeLEDS_RVBO': '<S1>:1339' */
        /* Transition: '<S1>:1341' */
        ModeleRobot_B.EtatLed1 = 1.0;
        ModeleRobot_B.EtatLed2 = 1.0;
        ModeleRobot_B.EtatLed3 = 1.0;
        ModeleRobot_B.EtatLed4 = 1.0;
      } else {
        /* During 'CLOCK': '<S1>:1118' */
        ModeleRobot_DWork.DureeMatch = ModeleRobot_DWork.DureeMatch + 1.0;

        /* During 'STRATEGIE': '<S1>:1119' */
        switch (ModeleRobot_DWork.is_STRATEGIE) {
         case ModeleRobot_IN_EVITEMENT:
          /* During 'EVITEMENT': '<S1>:3814' */
          if (ModeleRobot_DWork.EvitementEnCours == 0.0) {
            /* Transition: '<S1>:3819' */
            /* Exit 'DETECT_OBSTACLE': '<S1>:3816' */
            ModeleRobot_DWork.is_EVITEMENT = (uint8_T)
              ModeleRobot_IN_NO_ACTIVE_CHILD;

            /* Exit 'DETECT_OBSTACLE1': '<S1>:3815' */
            /* Exit 'EVITEMENT': '<S1>:3814' */
            /* Entry 'STRATEGIE1': '<S1>:1123' */
            ModeleRobot_DWork.is_STRATEGIE = (uint8_T)ModeleRobot_IN_STRATEGIE1;
            Model_enter_internal_STRATEGIE1();
          } else {
            ModeleRobot_DWork.local_Tempo = ModeleRobot_DWork.local_Tempo + 1.0;
            switch (ModeleRobot_DWork.is_EVITEMENT) {
             case ModeleRobot_IN_DETECT_OBSTACLE:
              /* During 'DETECT_OBSTACLE': '<S1>:3816' */
              if (ModeleRobot_DWork.local_Tempo > 2.0 /
                  ModeleRobot_P.SFunction_p43) {
                /* Transition: '<S1>:3818' */
                /* Exit 'DETECT_OBSTACLE': '<S1>:3816' */
                /* Entry 'DETECT_OBSTACLE1': '<S1>:3815' */
                ModeleRobot_DWork.is_EVITEMENT = (uint8_T)
                  ModeleRobot_IN_DETECT_OBSTACLE1;
                ModeleRobot_B.ConsigneVitesseAngle = 3.0;

                /*  [rad/sec] */
                ModeleRobot_B.ConsigneVitesseDistance = 40.0;

                /* [cm/sec] */
                ModeleRobot_DWork.EvitementEnCours = 0.0;
              }
              break;

             case ModeleRobot_IN_DETECT_OBSTACLE1:
              break;

             default:
              /* Transition: '<S1>:3817' */
              /* Entry 'DETECT_OBSTACLE': '<S1>:3816' */
              ModeleRobot_DWork.is_EVITEMENT = (uint8_T)
                ModeleRobot_IN_DETECT_OBSTACLE;
              ModeleRobot_DWork.local_Tempo = 0.0;

              /* Graphical Function 'Mouvement_ArretBrutal': '<S1>:1979' */
              /* Transition: '<S1>:1981' */
              ModeleRobot_B.ConsigneVitesseDistance = 0.0;
              ModeleRobot_B.ConsigneVitesseAngle = 0.0;

              /*  Arrête tout pendant un instant */
              break;
            }
          }
          break;

         case ModeleRobot_IN_STRATEGIE1:
          /* During 'STRATEGIE1': '<S1>:1123' */
          if ((ModeleRobot_Y.OUT_isObstacle == 1) &&
              (ModeleRobot_DWork.inhibeObstacle == 0.0)) {
            /* Transition: '<S1>:3821' */
            if (ModeleRobot_DWork.is_STRATEGIE1 == ModeleRobot_IN_DEMO) {
              if (ModeleRobot_DWork.is_DEMO == ModeleRobot_IN_ACTION_HOMOLO_2) {
                /* Exit 'ACTION_HOMOLO_2': '<S1>:4167' */
                /* Graphical Function 'setServo': '<S1>:4141' */
                /* Transition: '<S1>:4143' */
                ModeleRobot_B.CommandeServo[(int32_T)
                  (ModeleRobot_P.SFunction_p33 - 1.0)] =
                  ModeleRobot_P.SFunction_p37;

                /* Graphical Function 'setServo': '<S1>:4141' */
                /* Transition: '<S1>:4143' */
                ModeleRobot_B.CommandeServo[(int32_T)
                  (ModeleRobot_P.SFunction_p27 - 1.0)] =
                  ModeleRobot_P.SFunction_p31;
                ModeleRobot_DWork.is_DEMO = (uint8_T)
                  ModeleRobot_IN_NO_ACTIVE_CHILD;
              } else {
                /* Exit 'ACTION_0': '<S1>:4121' */
                /* Exit 'ACTION_10': '<S1>:4131' */
                /* Exit 'ACTION_12': '<S1>:4133' */
                /* Exit 'ACTION_14': '<S1>:4135' */
                /* Exit 'ACTION_16': '<S1>:4137' */
                /* Exit 'ACTION_18': '<S1>:4139' */
                /* Exit 'ACTION_2': '<S1>:4123' */
                /* Exit 'ACTION_4': '<S1>:4125' */
                /* Exit 'ACTION_6': '<S1>:4127' */
                /* Exit 'ACTION_8': '<S1>:4129' */
                /* Exit 'ACTION_HOMOLO_0': '<S1>:4165' */
                /* Exit 'ACTION_HOMOLO_01': '<S1>:4181' */
                /* Exit 'ACTION_HOMOLO_02': '<S1>:4183' */
                /* Exit 'ACTION_HOMOLO_03': '<S1>:4220' */
                /* Exit 'ACTION_HOMOLO_05': '<S1>:4239' */
                /* Exit 'ACTION_HOMOLO_06': '<S1>:4254' */
                /* Exit 'ACTION_HOMOLO_07': '<S1>:4261' */
                /* Exit 'ACTION_HOMOLO_08': '<S1>:4265' */
                /* Exit 'ACTION_HOMOLO_10': '<S1>:4204' */
                /* Exit 'ACTION_HOMOLO_11': '<S1>:4207' */
                /* Exit 'ACTION_HOMOLO_12': '<S1>:4210' */
                /* Exit 'ACTION_HOMOLO_13': '<S1>:4213' */
                /* Exit 'ACTION_HOMOLO_14': '<S1>:4215' */
                /* Exit 'ACTION_HOMOLO_15': '<S1>:4237' */
                /* Exit 'ACTION_HOMOLO_16': '<S1>:4243' */
                /* Exit 'ACTION_HOMOLO_17': '<S1>:4249' */
                /* Exit 'ACTION_HOMOLO_18': '<S1>:4251' */
                /* Exit 'ACTION_HOMOLO_19': '<S1>:4255' */
                /* Exit 'ACTION_HOMOLO_20': '<S1>:4258' */
                /* Exit 'ACTION_HOMOLO_21': '<S1>:4262' */
                /* Exit 'ACTION_HOMOLO_22': '<S1>:4266' */
                /* Exit 'ACTION_HOMOLO_23': '<S1>:4269' */
                /* Exit 'ACTION_HOMOLO_4': '<S1>:4169' */
                /* Exit 'ACTION_HOMOLO_5': '<S1>:4171' */
                /* Exit 'ACTION_HOMOLO_6': '<S1>:4187' */
                /* Exit 'ACTION_HOMOLO_7': '<S1>:4189' */
                /* Exit 'ACTION_HOMOLO_8': '<S1>:4192' */
                /* Exit 'ACTION_HOMOLO_9': '<S1>:4203' */
              }

              /* Exit 'DEMO': '<S1>:3463' */
              ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)
                ModeleRobot_IN_NO_ACTIVE_CHILD;
            } else {
              /* Exit 'INIT_STRATEGIE': '<S1>:1128' */
            }

            /* Exit 'STRATEGIE1': '<S1>:1123' */
            /* Entry 'EVITEMENT': '<S1>:3814' */
            ModeleRobot_DWork.is_STRATEGIE = (uint8_T)ModeleRobot_IN_EVITEMENT;
            ModeleRobot_DWork.EvitementEnCours = 1.0;

            /* Dans le cas d'un mouvement distance on calcule la distance parcourue pour repartir
               avec une consigne adapte */
            /* Transition: '<S1>:3817' */
            /* Entry 'DETECT_OBSTACLE': '<S1>:3816' */
            ModeleRobot_DWork.is_EVITEMENT = (uint8_T)
              ModeleRobot_IN_DETECT_OBSTACLE;
            ModeleRobot_DWork.local_Tempo = 0.0;

            /* Graphical Function 'Mouvement_ArretBrutal': '<S1>:1979' */
            /* Transition: '<S1>:1981' */
            ModeleRobot_B.ConsigneVitesseDistance = 0.0;
            ModeleRobot_B.ConsigneVitesseAngle = 0.0;

            /*  Arrête tout pendant un instant */
          } else {
            switch (ModeleRobot_DWork.is_STRATEGIE1) {
             case ModeleRobot_IN_DEMO:
              ModeleRobot_DEMO();
              break;

             case ModeleRobot_IN_INIT_STRATEGIE:
              /* During 'INIT_STRATEGIE': '<S1>:1128' */
              if (ModeleRobot_DWork.DureeMatch > 0.5 /
                  ModeleRobot_P.SFunction_p43) {
                /* Transition: '<S1>:2244' */
                /* Exit 'INIT_STRATEGIE': '<S1>:1128' */
                ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)
                  ModeleRobot_IN_NO_ACTIVE_CHILD;
                ModeleRobot_enter_atomic_DEMO();
                ModeleRobot_enter_internal_DEMO();
              }
              break;

             default:
              Model_enter_internal_STRATEGIE1();
              break;
            }
          }
          break;

         default:
          /* Transition: '<S1>:1120' */
          /* Entry 'STRATEGIE1': '<S1>:1123' */
          ModeleRobot_DWork.is_STRATEGIE = (uint8_T)ModeleRobot_IN_STRATEGIE1;
          Model_enter_internal_STRATEGIE1();
          break;
        }
      }
      break;

     default:
      enter_internal_COMPORTEMENT_ROB();
      break;
    }
  }
}

/* Model step function */
void ModeleRobot_step(void)
{
  real_T rtb_Switch1;
  real_T rtb_Switch;
  int32_T i;

  /* Relay: '<S2>/Relay' incorporates:
   *  Inport: '<Root>/IN_SensDeplacement'
   */
  if (ModeleRobot_U.IN_SensDeplacement >= ModeleRobot_P.Relay_OnVal) {
    ModeleRobot_DWork.Relay_Mode = true;
  } else {
    if (ModeleRobot_U.IN_SensDeplacement <= ModeleRobot_P.Relay_OffVal) {
      ModeleRobot_DWork.Relay_Mode = false;
    }
  }

  if (ModeleRobot_DWork.Relay_Mode) {
    rtb_Switch1 = ModeleRobot_P.Relay_YOn;
  } else {
    rtb_Switch1 = ModeleRobot_P.Relay_YOff;
  }

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/SeuilDistance'
   *  Inport: '<Root>/IN_ObstacleAVD'
   *  Inport: '<Root>/IN_ObstacleAVG'
   *  Logic: '<S2>/Logical Operator'
   *  RelationalOperator: '<S15>/Compare'
   *  RelationalOperator: '<S2>/Relational Operator'
   *  RelationalOperator: '<S2>/Relational Operator1'
   */
  if ((rtb_Switch1 > 0.0) >= ModeleRobot_P.Switch_Threshold) {
    rtb_Switch = (real_T)((ModeleRobot_U.IN_ObstacleAVG <=
      ModeleRobot_P.SeuilDistance_Value) || (ModeleRobot_U.IN_ObstacleAVD <=
      ModeleRobot_P.SeuilDistance_Value));
  } else {
    rtb_Switch = ModeleRobot_P.Constant1_Value;
  }

  /* Switch: '<S2>/Switch1' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/SeuilDistance'
   *  Inport: '<Root>/IN_ObstacleARD'
   *  Inport: '<Root>/IN_ObstacleARG'
   *  Logic: '<S2>/Logical Operator1'
   *  RelationalOperator: '<S14>/Compare'
   *  RelationalOperator: '<S2>/Relational Operator2'
   *  RelationalOperator: '<S2>/Relational Operator3'
   */
  if ((rtb_Switch1 < 0.0) >= ModeleRobot_P.Switch1_Threshold) {
    rtb_Switch1 = (real_T)((ModeleRobot_U.IN_ObstacleARG <=
      ModeleRobot_P.SeuilDistance_Value) || (ModeleRobot_U.IN_ObstacleARD <=
      ModeleRobot_P.SeuilDistance_Value));
  } else {
    rtb_Switch1 = ModeleRobot_P.Constant_Value_e;
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Logic: '<S2>/Logical Operator2'
   */
  ModeleRobot_Y.OUT_isObstacle = ((rtb_Switch != 0.0) || (rtb_Switch1 != 0.0));

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  Constant: '<S16>/Constant'
   *  Inport: '<Root>/IN_ConvergenceMvt'
   *  Logic: '<S3>/Logical Operator'
   *  RelationalOperator: '<S16>/Compare'
   *  RelationalOperator: '<S17>/FixPt Relational Operator'
   *  UnitDelay: '<S17>/Delay Input1'
   */
  ModeleRobot_B.DataTypeConversion = (real_T)(((ModeleRobot_U.IN_ConvergenceMvt
    != ModeleRobot_DWork.DelayInput1_DSTATE) != 0) &&
    ((ModeleRobot_U.IN_ConvergenceMvt == ModeleRobot_P.Constant_Value) != 0));

  /* Stateflow: '<Root>/COMPORTEMENT' */
  ModeleRobot_COMPORTEMENT();

  /* Outport: '<Root>/OUT_ConsigneX' */
  ModeleRobot_Y.OUT_ConsigneX = ModeleRobot_B.ConsigneX;

  /* Outport: '<Root>/OUT_ConsigneY' */
  ModeleRobot_Y.OUT_ConsigneY = ModeleRobot_B.ConsigneY;

  /* Outport: '<Root>/OUT_DdeMvtXY' */
  ModeleRobot_Y.OUT_DdeMvtXY = ModeleRobot_B.DdeMvtXY;

  /* Outport: '<Root>/OUT_ConsigneTeta' */
  ModeleRobot_Y.OUT_ConsigneTeta = ModeleRobot_B.ConsigneTeta;

  /* Outport: '<Root>/OUT_ConsigneVitesseAngle' */
  ModeleRobot_Y.OUT_ConsigneVitesseAngle = ModeleRobot_B.ConsigneVitesseAngle;

  /* Outport: '<Root>/OUT_ConsigneDistance' */
  ModeleRobot_Y.OUT_ConsigneDistance = ModeleRobot_B.ConsigneDistance;

  /* Outport: '<Root>/OUT_ConsigneVitesseDistance' */
  ModeleRobot_Y.OUT_ConsigneVitesseDistance =
    ModeleRobot_B.ConsigneVitesseDistance;

  /* Outport: '<Root>/OUT_DdeMvtDistanceAngle' */
  ModeleRobot_Y.OUT_DdeMvtDistanceAngle = ModeleRobot_B.DdeMvtDistanceAngle;

  /* Outport: '<Root>/OUT_CommandeManuelleG' */
  ModeleRobot_Y.OUT_CommandeManuelleG = ModeleRobot_B.CommandeManuelleG;

  /* Outport: '<Root>/OUT_CommandeManuelleD' */
  ModeleRobot_Y.OUT_CommandeManuelleD = ModeleRobot_B.CommandeManuelleD;

  /* Outport: '<Root>/OUT_DdeMvtManuel' */
  ModeleRobot_Y.OUT_DdeMvtManuel = ModeleRobot_B.DdeMvtManuel;

  /* Outport: '<Root>/OUT_SpeedServo' */
  memcpy((void *)(&ModeleRobot_Y.OUT_SpeedServo[0]), (void *)
         (&ModeleRobot_B.SpeedServo[0]), 20U * sizeof(real_T));

  /* Outport: '<Root>/OUT_EtatLed1' */
  ModeleRobot_Y.OUT_EtatLed1 = ModeleRobot_B.EtatLed1;

  /* Outport: '<Root>/OUT_EtatLed2' */
  ModeleRobot_Y.OUT_EtatLed2 = ModeleRobot_B.EtatLed2;

  /* Outport: '<Root>/OUT_EtatLed3' */
  ModeleRobot_Y.OUT_EtatLed3 = ModeleRobot_B.EtatLed3;

  /* Outport: '<Root>/OUT_EtatLed4' */
  ModeleRobot_Y.OUT_EtatLed4 = ModeleRobot_B.EtatLed4;

  /* Outport: '<Root>/OUT_DdeRecalagePosition' */
  ModeleRobot_Y.OUT_DdeRecalagePosition[0] = ModeleRobot_B.DdeRecalagePosition[0];
  ModeleRobot_Y.OUT_DdeRecalagePosition[1] = ModeleRobot_B.DdeRecalagePosition[1];
  ModeleRobot_Y.OUT_DdeRecalagePosition[2] = ModeleRobot_B.DdeRecalagePosition[2];
  ModeleRobot_Y.OUT_DdeRecalagePosition[3] = ModeleRobot_B.DdeRecalagePosition[3];

  /* Outport: '<Root>/OUT_ResetCodeurAscenseur' */
  ModeleRobot_Y.OUT_ResetCodeurAscenseur = ModeleRobot_B.ResetCodeurAscenseur;

  /* Outport: '<Root>/OUT_ResetCodeurBarillet' */
  ModeleRobot_Y.OUT_ResetCodeurBarillet = ModeleRobot_B.ResetCodeurBarillet;

  /* Outport: '<Root>/OUT_DdeMvtXYTeta' */
  ModeleRobot_Y.OUT_DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta;

  /* Outport: '<Root>/OUT_CommandeMoteur' */
  memcpy((void *)(&ModeleRobot_Y.OUT_CommandeMoteur[0]), (void *)
         (&ModeleRobot_B.CommandeMoteur[0]), sizeof(real_T) << 3U);
  for (i = 0; i < 20; i++) {
    /* Outport: '<Root>/OUT_CommandeServo' */
    ModeleRobot_Y.OUT_CommandeServo[i] = ModeleRobot_B.CommandeServo[i];

    /* Outport: '<Root>/OUT_RelacheServo' */
    ModeleRobot_Y.OUT_RelacheServo[i] = ModeleRobot_B.RelacheServo[i];
  }

  /* Update for UnitDelay: '<S17>/Delay Input1' incorporates:
   *  Update for Inport: '<Root>/IN_ConvergenceMvt'
   */
  ModeleRobot_DWork.DelayInput1_DSTATE = ModeleRobot_U.IN_ConvergenceMvt;
}

/* Model initialize function */
void ModeleRobot_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* InitializeConditions for UnitDelay: '<S17>/Delay Input1' */
  ModeleRobot_DWork.DelayInput1_DSTATE = ModeleRobot_P.DelayInput1_X0;

  /* InitializeConditions for Stateflow: '<Root>/COMPORTEMENT' */
  ModeleRobot_COMPORTEMENT_Init();
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
