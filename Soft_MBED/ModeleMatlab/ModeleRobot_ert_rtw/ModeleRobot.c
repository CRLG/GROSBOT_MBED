/*
 * File: ModeleRobot.c
 *
 * Real-Time Workshop code generated for Simulink model ModeleRobot.
 *
 * Model version                        : 1.1550
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Fri May 15 18:56:54 2015
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Fri May 15 18:56:54 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objective: Efficiency
 * Validation result: Passed (9), Warning (1), Error (0)
 */

#include "ModeleRobot.h"
#include "ModeleRobot_private.h"

/* Named constants for Stateflow: '<Root>/COMPORTEMENT' */
#define IN_ACTION_RETOUR_Z0_DECHARGE_01 (1)
#define IN_ACTION_RETOUR_Z0_DECHARGE_02 (2)
#define IN_ACTION_RETOUR_Z0_DECHARGE_03 (3)
#define IN_ACTION_RETOUR_Z0_DECHARGE_04 (4)
#define IN_ACTION_RETOUR_Z0_DECHARGE_06 (5)
#define IN_ACTION_RETOUR_Z0_DECHARGE_07 (6)
#define IN_JAUNE_GOTO_DISTRIBUTEURS_ET_ (3)
#define IN_JAUNE_RETOUR_ZONE_DEPART_ET_ (4)
#define IN_VERT_GOTO_DISTRIBUTEURS_ET_R (5)
#define IN_VERT_RETOUR_ZONE_DEPART_ET_D (6)
#define ModeleR_IN_FIN_REPOS_ACTIONNEUR (4)
#define ModeleRob_IN_ACTION_DISTRIB_010 (2)
#define ModeleRob_IN_ACTION_DISTRIB_011 (3)
#define ModeleRobo_IN_ACTION_DISTRIB_01 (1)
#define ModeleRobo_IN_ACTION_DISTRIB_02 (4)
#define ModeleRobo_IN_ACTION_DISTRIB_03 (5)
#define ModeleRobo_IN_ACTION_DISTRIB_04 (6)
#define ModeleRobo_IN_ACTION_DISTRIB_05 (7)
#define ModeleRobo_IN_ACTION_DISTRIB_06 (8)
#define ModeleRobo_IN_ACTION_DISTRIB_07 (9)
#define ModeleRobo_IN_ACTION_DISTRIB_08 (10)
#define ModeleRobo_IN_ACTION_DISTRIB_09 (11)
#define ModeleRobot_IN_ACTION_18       (1)
#define ModeleRobot_IN_ACTION_HOMOLO_0 (2)
#define ModeleRobot_IN_ACTION_HOMOLO_01 (3)
#define ModeleRobot_IN_ACTION_HOMOLO_02 (4)
#define ModeleRobot_IN_ACTION_HOMOLO_03 (5)
#define ModeleRobot_IN_ACTION_HOMOLO_05 (6)
#define ModeleRobot_IN_ACTION_HOMOLO_09 (7)
#define ModeleRobot_IN_ACTION_HOMOLO_10 (8)
#define ModeleRobot_IN_ACTION_HOMOLO_11 (9)
#define ModeleRobot_IN_ACTION_HOMOLO_12 (10)
#define ModeleRobot_IN_ACTION_HOMOLO_13 (11)
#define ModeleRobot_IN_ACTION_HOMOLO_14 (12)
#define ModeleRobot_IN_ACTION_HOMOLO_15 (13)
#define ModeleRobot_IN_ACTION_HOMOLO_16 (14)
#define ModeleRobot_IN_ACTION_HOMOLO_2 (15)
#define ModeleRobot_IN_ACTION_HOMOLO_24 (16)
#define ModeleRobot_IN_ACTION_HOMOLO_25 (17)
#define ModeleRobot_IN_ACTION_HOMOLO_30 (18)
#define ModeleRobot_IN_ACTION_HOMOLO_33 (19)
#define ModeleRobot_IN_ACTION_HOMOLO_34 (20)
#define ModeleRobot_IN_ACTION_HOMOLO_35 (21)
#define ModeleRobot_IN_ACTION_HOMOLO_36 (22)
#define ModeleRobot_IN_ACTION_HOMOLO_4 (23)
#define ModeleRobot_IN_ACTION_HOMOLO_40 (24)
#define ModeleRobot_IN_ACTION_HOMOLO_41 (25)
#define ModeleRobot_IN_ACTION_HOMOLO_43 (26)
#define ModeleRobot_IN_ACTION_HOMOLO_44 (27)
#define ModeleRobot_IN_ACTION_HOMOLO_45 (28)
#define ModeleRobot_IN_ACTION_HOMOLO_46 (29)
#define ModeleRobot_IN_ACTION_HOMOLO_47 (30)
#define ModeleRobot_IN_ACTION_HOMOLO_48 (31)
#define ModeleRobot_IN_ACTION_HOMOLO_49 (32)
#define ModeleRobot_IN_ACTION_HOMOLO_50 (33)
#define ModeleRobot_IN_ACTION_HOMOLO_51 (34)
#define ModeleRobot_IN_ACTION_HOMOLO_52 (35)
#define ModeleRobot_IN_ACTION_HOMOLO_53 (36)
#define ModeleRobot_IN_ACTION_HOMOLO_54 (37)
#define ModeleRobot_IN_ACTION_HOMOLO_55 (38)
#define ModeleRobot_IN_ACTION_HOMOLO_56 (39)
#define ModeleRobot_IN_ACTION_HOMOLO_57 (40)
#define ModeleRobot_IN_ACTION_HOMOLO_58 (41)
#define ModeleRobot_IN_ACTION_HOMOLO_6 (42)
#define ModeleRobot_IN_ACTION_HOMOLO_7 (43)
#define ModeleRobot_IN_ACTION_HOMOLO_8 (44)
#define ModeleRobot_IN_ACTION_HOMOLO_9 (45)
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
static void Mod_enter_atomic_INIT_STRATEGIE(void);
static void ModeleRobot_enter_atomic_DEMO(void);
static void Mo_enter_atomic_ACTION_HOMOLO_8(void);
static void ModeleRobot_enter_internal_DEMO(void);
static void enter_atomic_JAUNE_GOTO_DISTRIB(void);
static void enter_internal_JAUNE_GOTO_DISTR(void);
static void enter_atomic_JAUNE_RETOUR_ZONE_(void);
static void enter_internal_JAUNE_RETOUR_ZON(void);
static void enter_atomic_VERT_GOTO_DISTRIBU(void);
static void enter_internal_VERT_GOTO_DISTRI(void);
static void enter_atomic_VERT_RETOUR_ZONE_D(void);
static void enter_internal_VERT_RETOUR_ZONE(void);
static void Model_enter_internal_STRATEGIE1(void);
static void ModeleRobot_ACTION_HOMOLO_46(void);
static void ModeleRobot_ACTION_HOMOLO_47(void);
static void ModeleRobot_ACTION_HOMOLO_48(void);
static void ModeleRobot_ACTION_HOMOLO_49(void);
static void ModeleRobot_ACTION_HOMOLO_50(void);
static void ModeleRobot_ACTION_HOMOLO_51(void);
static void ModeleRobot_ACTION_HOMOLO_52(void);
static void ModeleRobot_ACTION_HOMOLO_53(void);
static void ModeleRobot_ACTION_HOMOLO_54(void);
static void ModeleRobot_ACTION_HOMOLO_55(void);
static void ModeleRobot_ACTION_HOMOLO_56(void);
static void ModeleRobot_ACTION_HOMOLO_57(void);
static void ModeleRobot_ACTION_HOMOLO_58(void);
static void ModeleRobot_ACTION_HOMOLO_6(void);
static void ModeleRobot_ACTION_HOMOLO_7(void);
static void ModeleRobot_ACTION_HOMOLO_8(void);
static void ModeleRobot_ACTION_HOMOLO_9(void);
static void ModeleRobot_exit_internal_DEMO(void);
static void ModeleRobot_DEMO(void);
static void VERT_GOTO_DISTRIBUTEURS_ET_RECU(void);
static void ModeleRobot_STRATEGIE1(void);

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

  /* Graphical Function 'setPWM': '<S1>:4112' */
  /* Transition: '<S1>:4114' */
  ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p18 - 1.0)] =
    0.0;

  /* meme si la vitesse n'est pas utilise, on l'initialise pour les servos */
  /* Graphical Function 'setServoSpeed': '<S1>:4153' */
  /* Transition: '<S1>:4155' */
  ModeleRobot_B.SpeedServo[(int32_T)(ModeleRobot_P.SFunction_p37 - 1.0)] =
    ModeleRobot_P.SFunction_p13;

  /* Graphical Function 'setServoSpeed': '<S1>:4153' */
  /* Transition: '<S1>:4155' */
  ModeleRobot_B.SpeedServo[(int32_T)(ModeleRobot_P.SFunction_p31 - 1.0)] =
    ModeleRobot_P.SFunction_p13;

  /* Graphical Function 'setServoSpeed': '<S1>:4153' */
  /* Transition: '<S1>:4155' */
  ModeleRobot_B.SpeedServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
    ModeleRobot_P.SFunction_p13;

  /* Graphical Function 'setServoSpeed': '<S1>:4153' */
  /* Transition: '<S1>:4155' */
  ModeleRobot_B.SpeedServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
    ModeleRobot_P.SFunction_p13;

  /* de meme pour le maintient ou non des servos on initialise */
  /* Graphical Function 'setServoRelache': '<S1>:4198' */
  /* Transition: '<S1>:4200' */
  ModeleRobot_B.RelacheServo[(int32_T)(ModeleRobot_P.SFunction_p37 - 1.0)] = 0.0;

  /* Graphical Function 'setServoRelache': '<S1>:4198' */
  /* Transition: '<S1>:4200' */
  ModeleRobot_B.RelacheServo[(int32_T)(ModeleRobot_P.SFunction_p31 - 1.0)] = 0.0;

  /* Graphical Function 'setServoRelache': '<S1>:4198' */
  /* Transition: '<S1>:4200' */
  ModeleRobot_B.RelacheServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
    1000.0;

  /* Graphical Function 'setServoRelache': '<S1>:4198' */
  /* Transition: '<S1>:4200' */
  ModeleRobot_B.RelacheServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
    1000.0;

  /* on ecarte les pinces pour qu'elles soient bien dans le robot */
  /* Graphical Function 'setServo': '<S1>:4141' */
  /* Transition: '<S1>:4143' */
  ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p37 - 1.0)] =
    ModeleRobot_P.SFunction_p41;

  /* Graphical Function 'setServo': '<S1>:4141' */
  /* Transition: '<S1>:4143' */
  ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p31 - 1.0)] =
    ModeleRobot_P.SFunction_p35;

  /* l'inverse pour les centreurs */
  /* Graphical Function 'setServo': '<S1>:4141' */
  /* Transition: '<S1>:4143' */
  ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
    ModeleRobot_P.SFunction_p29;

  /* Graphical Function 'setServo': '<S1>:4141' */
  /* Transition: '<S1>:4143' */
  ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
    ModeleRobot_P.SFunction_p25;

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
static void Mod_enter_atomic_INIT_STRATEGIE(void)
{
  /* Entry 'INIT_STRATEGIE': '<S1>:1128' */
  ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)ModeleRobot_IN_INIT_STRATEGIE;
  ModeleRobot_DWork.was_STRATEGIE1 = (uint8_T)ModeleRobot_IN_INIT_STRATEGIE;
  ModeleRobot_B.ConsigneVitesseAngle = 3.0;

  /*  [rad/sec] */
  ModeleRobot_B.ConsigneVitesseDistance = 40.0;

  /* [cm/sec] */
  ModeleRobot_DWork.finHomologation = 0.0;
  ModeleRobot_DWork.Etape_recuperationDistributeurs = 1.0;

  /* pour 2015 on part en marche arrière */
  /* Graphical Function 'setPosition': '<S1>:4174' */
  /* Transition: '<S1>:4176' */
  ModeleRobot_B.DdeRecalagePosition[0] = ModeleRobot_B.DdeRecalagePosition[0] +
    1.0;
  ModeleRobot_B.DdeRecalagePosition[1] = 0.0;
  ModeleRobot_B.DdeRecalagePosition[2] = 0.0;
  ModeleRobot_B.DdeRecalagePosition[3] = ModeleRobot_P.SFunction_p19;
  ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
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
static void Mo_enter_atomic_ACTION_HOMOLO_8(void)
{
  /* Entry 'ACTION_HOMOLO_8': '<S1>:4192' */
  ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_8;
  ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_8;

  /* on centre le spot */
  /* Graphical Function 'setServo': '<S1>:4141' */
  /* Transition: '<S1>:4143' */
  ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
    ModeleRobot_P.SFunction_p28;

  /* Graphical Function 'setServo': '<S1>:4141' */
  /* Transition: '<S1>:4143' */
  ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
    ModeleRobot_P.SFunction_p24;
  ModeleRobot_DWork.TempoMot = 0.0;
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_enter_internal_DEMO(void)
{
  switch (ModeleRobot_DWork.was_DEMO) {
   case ModeleRobot_IN_ACTION_18:
    /* Entry 'ACTION_18': '<S1>:4139' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_18;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_18;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p20 - 1.0)] =
      ModeleRobot_P.SFunction_p21;
    ModeleRobot_DWork.finHomologation = 1.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_0:
    /* Entry 'ACTION_HOMOLO_0': '<S1>:4165' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_0;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_0;

    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p15 - 1.0)] =
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
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p37 - 1.0)] =
      ModeleRobot_P.SFunction_p39;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p31 - 1.0)] =
      ModeleRobot_P.SFunction_p33;

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
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p15 - 1.0)] =
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
    ModeleRobot_B.ConsigneTeta = ModeleRobot_P.SFunction_p19;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_05:
    /* Entry 'ACTION_HOMOLO_05': '<S1>:4239' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_05;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_05;

    /* on descend l'ascenseur pour emprisonner spot + balle */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p15 - 1.0)] =
      -60.0;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p37 - 1.0)] =
      ModeleRobot_P.SFunction_p38;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p31 - 1.0)] =
      ModeleRobot_P.SFunction_p32;

    /* tempo */
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_09:
    /* Entry 'ACTION_HOMOLO_09': '<S1>:4280' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_09;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_09;

    /* on remonte les pinces */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p15 - 1.0)] =
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
    ModeleRobot_DWork.inhibeObstacle = 1.0;

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
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p43 - 1.0)] =
      ModeleRobot_P.SFunction_p45;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_13:
    /* Entry 'ACTION_HOMOLO_13': '<S1>:4213' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_13;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_13;

    /* on souffle pendant 2 secondes */
    ModeleRobot_DWork.TempoMot = 0.0;

    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p18 - 1.0)] =
      100.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_14:
    /* Entry 'ACTION_HOMOLO_14': '<S1>:4215' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_14;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_14;

    /* on arrete de souffler et on rentre les recolteurs */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p18 - 1.0)] =
      0.0;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p43 - 1.0)] =
      ModeleRobot_P.SFunction_p44;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_15:
    /* Entry 'ACTION_HOMOLO_15': '<S1>:4237' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_15;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_15;

    /* on relache la balle */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p37 - 1.0)] =
      ModeleRobot_P.SFunction_p40;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p31 - 1.0)] =
      ModeleRobot_P.SFunction_p34;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_16:
    /* Entry 'ACTION_HOMOLO_16': '<S1>:4243' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_16;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_16;

    /* on relache la balle */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p37 - 1.0)] =
      ModeleRobot_P.SFunction_p40;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p31 - 1.0)] =
      ModeleRobot_P.SFunction_p34;

    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p15 - 1.0)] =
      0.0;
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

   case ModeleRobot_IN_ACTION_HOMOLO_24:
    /* Entry 'ACTION_HOMOLO_24': '<S1>:4279' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_24;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_24;

    /* on avance vers le gobelet */
    /* Graphical Function 'Mouvement_XY': '<S1>:1289' */
    /* Transition: '<S1>:1291' */
    ModeleRobot_B.DdeMvtXY = ModeleRobot_B.DdeMvtXY + 1.0;
    ModeleRobot_B.ConsigneX = 22.0;
    ModeleRobot_B.ConsigneY = -77.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_25:
    /* Entry 'ACTION_HOMOLO_25': '<S1>:4281' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_25;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_25;

    /* on rentre un  centreur */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p15 - 1.0)] =
      0.0;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
      ModeleRobot_P.SFunction_p29;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_30:
    /* Entry 'ACTION_HOMOLO_30': '<S1>:4296' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_30;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_30;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p20 - 1.0)] =
      ModeleRobot_P.SFunction_p22;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_33:
    /* Entry 'ACTION_HOMOLO_33': '<S1>:4309' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_33;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_33;

    /* on rentre un  centreur */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p15 - 1.0)] =
      0.0;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
      ModeleRobot_P.SFunction_p25;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_34:
    /* Entry 'ACTION_HOMOLO_34': '<S1>:4311' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_34;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_34;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
      ModeleRobot_P.SFunction_p25;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_35:
    /* Entry 'ACTION_HOMOLO_35': '<S1>:4314' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_35;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_35;

    /* on se positionne face au gobelet */
    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = 41.0;
    ModeleRobot_B.ConsigneY = -77.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_B.ConsigneTeta = 3.14;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_36:
    /* Entry 'ACTION_HOMOLO_36': '<S1>:4316' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_36;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_36;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
      ModeleRobot_P.SFunction_p29;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_4:
    /* Entry 'ACTION_HOMOLO_4': '<S1>:4169' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_4;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_4;

    /* on recule pour laisser les spots */
    /* Graphical Function 'Mouvement_XY': '<S1>:1289' */
    /* Transition: '<S1>:1291' */
    ModeleRobot_B.DdeMvtXY = ModeleRobot_B.DdeMvtXY + 1.0;
    ModeleRobot_B.ConsigneX = 67.0;
    ModeleRobot_B.ConsigneY = -45.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_40:
    /* Entry 'ACTION_HOMOLO_40': '<S1>:4338' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_40;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_40;

    /* le bras est à droite du robot, demi tour */
    /* Graphical Function 'Mouvement_Angle': '<S1>:1354' */
    /* Transition: '<S1>:1356' */
    ModeleRobot_B.DdeMvtDistanceAngle = ModeleRobot_B.DdeMvtDistanceAngle + 1.0;
    ModeleRobot_B.ConsigneDistance = 0.0;
    ModeleRobot_B.ConsigneTeta = 0.0;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_41:
    /* Entry 'ACTION_HOMOLO_41': '<S1>:4339' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_41;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_41;

    /* BO pour pousser les spots */
    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = -25.0;
    ModeleRobot_B.CommandeManuelleD = -25.0;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_43:
    /* Entry 'ACTION_HOMOLO_43': '<S1>:4343' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_43;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_43;

    /* BO pour pousser les spots */
    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 25.0;
    ModeleRobot_B.CommandeManuelleD = 25.0;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_44:
    /* Entry 'ACTION_HOMOLO_44': '<S1>:4348' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_44;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_44;

    /* on avance parallelement a la bordure et on ferme les claps */
    /* Graphical Function 'Mouvement_XY': '<S1>:1289' */
    /* Transition: '<S1>:1291' */
    ModeleRobot_B.DdeMvtXY = ModeleRobot_B.DdeMvtXY + 1.0;
    ModeleRobot_B.ConsigneX = 14.5;
    ModeleRobot_B.ConsigneY = -77.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_45:
    /* Entry 'ACTION_HOMOLO_45': '<S1>:4350' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_45;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_45;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p20 - 1.0)] =
      ModeleRobot_P.SFunction_p21;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_46:
    /* Entry 'ACTION_HOMOLO_46': '<S1>:4395' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_46;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_46;

    /* on centre le spot */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
      ModeleRobot_P.SFunction_p30;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
      ModeleRobot_P.SFunction_p26;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_47:
    /* Entry 'ACTION_HOMOLO_47': '<S1>:4409' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_47;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_47;

    /* on avance parallelement a la bordure et on ferme les claps */
    /* Graphical Function 'Mouvement_XY': '<S1>:1289' */
    /* Transition: '<S1>:1291' */
    ModeleRobot_B.DdeMvtXY = ModeleRobot_B.DdeMvtXY + 1.0;
    ModeleRobot_B.ConsigneX = 56.0;
    ModeleRobot_B.ConsigneY = -77.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_48:
    /* Entry 'ACTION_HOMOLO_48': '<S1>:4411' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_48;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_48;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p20 - 1.0)] =
      ModeleRobot_P.SFunction_p22;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_49:
    /* Entry 'ACTION_HOMOLO_49': '<S1>:4413' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_49;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_49;

    /* on avance parallelement a la bordure et on ferme les claps */
    /* Graphical Function 'Mouvement_XY': '<S1>:1289' */
    /* Transition: '<S1>:1291' */
    ModeleRobot_B.DdeMvtXY = ModeleRobot_B.DdeMvtXY + 1.0;
    ModeleRobot_B.ConsigneX = 74.0;
    ModeleRobot_B.ConsigneY = -77.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_50:
    /* Entry 'ACTION_HOMOLO_50': '<S1>:4471' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_50;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_50;

    /* on avance parallelement a la bordure et on ferme les claps */
    /* Graphical Function 'Mouvement_XY': '<S1>:1289' */
    /* Transition: '<S1>:1291' */
    ModeleRobot_B.DdeMvtXY = ModeleRobot_B.DdeMvtXY + 1.0;
    ModeleRobot_B.ConsigneX = 19.0;
    ModeleRobot_B.ConsigneY = -77.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_51:
    /* Entry 'ACTION_HOMOLO_51': '<S1>:4477' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_51;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_51;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p20 - 1.0)] =
      ModeleRobot_P.SFunction_p21;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_52:
    /* Entry 'ACTION_HOMOLO_52': '<S1>:4489' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_52;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_52;

    /* on avance parallelement a la bordure et on ferme les claps */
    /* Graphical Function 'Mouvement_XY': '<S1>:1289' */
    /* Transition: '<S1>:1291' */
    ModeleRobot_B.DdeMvtXY = ModeleRobot_B.DdeMvtXY + 1.0;
    ModeleRobot_B.ConsigneX = 62.0;
    ModeleRobot_B.ConsigneY = -77.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_53:
    /* Entry 'ACTION_HOMOLO_53': '<S1>:4490' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_53;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_53;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p20 - 1.0)] =
      ModeleRobot_P.SFunction_p22;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_54:
    /* Entry 'ACTION_HOMOLO_54': '<S1>:4491' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_54;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_54;

    /* on avance parallelement a la bordure et on ferme les claps */
    /* Graphical Function 'Mouvement_XY': '<S1>:1289' */
    /* Transition: '<S1>:1291' */
    ModeleRobot_B.DdeMvtXY = ModeleRobot_B.DdeMvtXY + 1.0;
    ModeleRobot_B.ConsigneX = 82.0;
    ModeleRobot_B.ConsigneY = -77.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_55:
    /* Entry 'ACTION_HOMOLO_55': '<S1>:4498' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_55;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_55;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
      ModeleRobot_P.SFunction_p26;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_56:
    /* Entry 'ACTION_HOMOLO_56': '<S1>:4500' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_56;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_56;

    /* Graphical Function 'setServoRelache': '<S1>:4198' */
    /* Transition: '<S1>:4200' */
    ModeleRobot_B.RelacheServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
      0.0;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
      ModeleRobot_P.SFunction_p30;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_57:
    /* Entry 'ACTION_HOMOLO_57': '<S1>:4502' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_57;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_57;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
      ModeleRobot_P.SFunction_p25;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_58:
    /* Entry 'ACTION_HOMOLO_58': '<S1>:4504' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_58;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_58;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
      ModeleRobot_P.SFunction_p29;
    ModeleRobot_DWork.TempoMot = 0.0;
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
    ModeleRobot_DWork.inhibeObstacle = 0.0;

    /* on se tourne vers les spots */
    /* Graphical Function 'Mouvement_Angle': '<S1>:1354' */
    /* Transition: '<S1>:1356' */
    ModeleRobot_B.DdeMvtDistanceAngle = ModeleRobot_B.DdeMvtDistanceAngle + 1.0;
    ModeleRobot_B.ConsigneDistance = 0.0;
    ModeleRobot_B.ConsigneTeta = -0.99 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
      ModeleRobot_P.SFunction_p30;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
      ModeleRobot_P.SFunction_p26;
    break;

   case ModeleRobot_IN_ACTION_HOMOLO_8:
    Mo_enter_atomic_ACTION_HOMOLO_8();
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
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p37 - 1.0)] =
      ModeleRobot_P.SFunction_p39;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p31 - 1.0)] =
      ModeleRobot_P.SFunction_p33;

    /* tempo */
    ModeleRobot_DWork.TempoMot = 0.0;
    break;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void enter_atomic_JAUNE_GOTO_DISTRIB(void)
{
  /* Entry 'JAUNE_GOTO_DISTRIBUTEURS_ET_RECUPERE': '<S1>:4353' */
  ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)IN_JAUNE_GOTO_DISTRIBUTEURS_ET_;
  ModeleRobot_DWork.was_STRATEGIE1 = (uint8_T)IN_JAUNE_GOTO_DISTRIBUTEURS_ET_;
  ModeleRobot_DWork.TempoMot = 0.0;
  ModeleRobot_DWork.inhibeObstacle = 0.0;
  ModeleRobot_DWork.nbreDistributeursTraites = 0.0;
  ModeleRobot_DWork.x_old = 0.0;
  ModeleRobot_DWork.y_old = 0.0;
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void enter_internal_JAUNE_GOTO_DISTR(void)
{
  switch (ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET) {
   case ModeleRobo_IN_ACTION_DISTRIB_01:
    /* Entry 'ACTION_DISTRIB_01': '<S1>:4365' */
    ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_01;
    ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_01;

    /* Graphical Function 'CommandeLEDS_RVBO': '<S1>:1339' */
    /* Transition: '<S1>:1341' */
    ModeleRobot_B.EtatLed1 = 1.0;
    ModeleRobot_B.EtatLed2 = 1.0;
    ModeleRobot_B.EtatLed3 = 1.0;
    ModeleRobot_B.EtatLed4 = 1.0;
    ModeleRobot_DWork.positionDistributeur_X = 30.0;

    /*  erreur constatée en pratique (normalement 36cm)
       va vers une position de référence */
    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = ModeleRobot_DWork.posXReferenceEntreEtapes;
    ModeleRobot_B.ConsigneY = 0.0;
    ModeleRobot_B.ConsigneTeta = ModeleRobot_P.SFunction_p19;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRob_IN_ACTION_DISTRIB_010:
    /* Entry 'ACTION_DISTRIB_010': '<S1>:4407' */
    ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRob_IN_ACTION_DISTRIB_010;
    ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET = (uint8_T)
      ModeleRob_IN_ACTION_DISTRIB_010;

    /* va en marche arrière jusque devant le distributeur sans l'atteindre */
    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = ModeleRobot_DWork.positionDistributeur_X;
    ModeleRobot_B.ConsigneY = 60.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_B.ConsigneTeta = (-ModeleRobot_P.SFunction_p19) / 2.0 *
      ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRob_IN_ACTION_DISTRIB_011:
    /* Entry 'ACTION_DISTRIB_011': '<S1>:4415' */
    ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRob_IN_ACTION_DISTRIB_011;
    ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET = (uint8_T)
      ModeleRob_IN_ACTION_DISTRIB_011;

    /*  s'éloinge de la bordure */
    ModeleRobot_DWork.inhibeObstacle = 0.0;

    /* Graphical Function 'Mouvement_Distance': '<S1>:1347' */
    /* Transition: '<S1>:1349' */
    ModeleRobot_B.DdeMvtDistanceAngle = ModeleRobot_B.DdeMvtDistanceAngle + 1.0;
    ModeleRobot_B.ConsigneDistance = 15.0;

    /*  ConsigneTeta reste inchangé. */
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobo_IN_ACTION_DISTRIB_02:
    /* Entry 'ACTION_DISTRIB_02': '<S1>:4366' */
    ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_02;
    ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_02;
    ModeleRobot_DWork.inhibeObstacle = 1.0;
    break;

   case ModeleRobo_IN_ACTION_DISTRIB_03:
    /* Entry 'ACTION_DISTRIB_03': '<S1>:4368' */
    ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_03;
    ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_03;

    /*  termine en boucle ouverte pour venir buter contre la bordure */
    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = -25.0;
    ModeleRobot_B.CommandeManuelleD = -25.0;

    /*  le souffleur évacue les boules éventuellement derrière le robot qu pourraient gêner */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p18 - 1.0)] =
      -100.0;

    /*  sort le tobogan et lance la souflerie */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p43 - 1.0)] =
      ModeleRobot_P.SFunction_p45;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobo_IN_ACTION_DISTRIB_04:
    /* Entry 'ACTION_DISTRIB_04': '<S1>:4369' */
    ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_04;
    ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_04;

    /*  arrête de buter contre la bordure */
    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 0.0;
    ModeleRobot_B.CommandeManuelleD = 0.0;

    /*  ATTENTION : recalage de la position du robot
       setPosition(36,77.5*invMouv, (-PI/2)*invMouv); */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p16 - 1.0)] =
      100.0;

    /*  arrête le souffleur du bas */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p18 - 1.0)] =
      0.0;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobo_IN_ACTION_DISTRIB_05:
    /* Entry 'ACTION_DISTRIB_05': '<S1>:4370' */
    ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_05;
    ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_05;

    /*  Arrête la souflerie pour laisser les balles tomber (et attend un peu) */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p16 - 1.0)] =
      0.0;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobo_IN_ACTION_DISTRIB_06:
    /* Entry 'ACTION_DISTRIB_06': '<S1>:4372' */
    ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_06;
    ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_06;
    ModeleRobot_DWork.nbreDistributeursTraites =
      ModeleRobot_DWork.nbreDistributeursTraites + 1.0;
    break;

   case ModeleRobo_IN_ACTION_DISTRIB_07:
    /* Entry 'ACTION_DISTRIB_07': '<S1>:4373' */
    ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_07;
    ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_07;

    /*  Ferme le servo du recolteur une fois tout terminé */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p43 - 1.0)] =
      ModeleRobot_P.SFunction_p44;

    /*  retourne à la position de référence */
    ModeleRobot_DWork.inhibeObstacle = 1.0;

    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = ModeleRobot_DWork.posXReferenceEntreEtapes + 20.0;
    ModeleRobot_B.ConsigneY = 0.0;
    ModeleRobot_B.ConsigneTeta = 0.0;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobo_IN_ACTION_DISTRIB_08:
    /* Entry 'ACTION_DISTRIB_08': '<S1>:4375' */
    ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_08;
    ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_08;

    /* Fin d'étape */
    ModeleRobot_DWork.Etape_recuperationDistributeurs = 0.0;
    break;

   case ModeleRobo_IN_ACTION_DISTRIB_09:
    /* Entry 'ACTION_DISTRIB_09': '<S1>:4405' */
    ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_09;
    ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_09;

    /* va en marche arrière jusque devant le distributeur sans l'atteindre */
    /* Graphical Function 'Mouvement_Angle': '<S1>:1354' */
    /* Transition: '<S1>:1356' */
    ModeleRobot_B.DdeMvtDistanceAngle = ModeleRobot_B.DdeMvtDistanceAngle + 1.0;
    ModeleRobot_B.ConsigneDistance = 0.0;
    ModeleRobot_B.ConsigneTeta = (-ModeleRobot_P.SFunction_p19) / 2.0 *
      ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   default:
    /* Transition: '<S1>:4355' */
    /* Entry 'ACTION_DISTRIB_01': '<S1>:4365' */
    ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_01;
    ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_01;

    /* Graphical Function 'CommandeLEDS_RVBO': '<S1>:1339' */
    /* Transition: '<S1>:1341' */
    ModeleRobot_B.EtatLed1 = 1.0;
    ModeleRobot_B.EtatLed2 = 1.0;
    ModeleRobot_B.EtatLed3 = 1.0;
    ModeleRobot_B.EtatLed4 = 1.0;
    ModeleRobot_DWork.positionDistributeur_X = 30.0;

    /*  erreur constatée en pratique (normalement 36cm)
       va vers une position de référence */
    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = ModeleRobot_DWork.posXReferenceEntreEtapes;
    ModeleRobot_B.ConsigneY = 0.0;
    ModeleRobot_B.ConsigneTeta = ModeleRobot_P.SFunction_p19;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void enter_atomic_JAUNE_RETOUR_ZONE_(void)
{
  /* Entry 'JAUNE_RETOUR_ZONE_DEPART_ET_DECHARGE': '<S1>:4377' */
  ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)IN_JAUNE_RETOUR_ZONE_DEPART_ET_;
  ModeleRobot_DWork.was_STRATEGIE1 = (uint8_T)IN_JAUNE_RETOUR_ZONE_DEPART_ET_;
  ModeleRobot_DWork.TempoMot = 0.0;
  ModeleRobot_DWork.inhibeObstacle = 0.0;
  ModeleRobot_DWork.x_old = 0.0;
  ModeleRobot_DWork.y_old = 0.0;
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void enter_internal_JAUNE_RETOUR_ZON(void)
{
  switch (ModeleRobot_DWork.was_JAUNE_RETOUR_ZONE_DEPART_ET) {
   case IN_ACTION_RETOUR_Z0_DECHARGE_01:
    /* Entry 'ACTION_RETOUR_Z0_DECHARGE_01': '<S1>:4387' */
    ModeleRobot_DWork.is_JAUNE_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_01;
    ModeleRobot_DWork.was_JAUNE_RETOUR_ZONE_DEPART_ET = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_01;

    /* va vers une position de référence */
    /* Graphical Function 'Mouvement_Distance': '<S1>:1347' */
    /* Transition: '<S1>:1349' */
    ModeleRobot_B.DdeMvtDistanceAngle = ModeleRobot_B.DdeMvtDistanceAngle + 1.0;
    ModeleRobot_B.ConsigneDistance = -80.0;

    /*  ConsigneTeta reste inchangé. */
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

    /*  le souffleur évacue les boules éventuellement derrière le robot qu pourraient gêner */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p18 - 1.0)] =
      -100.0;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case IN_ACTION_RETOUR_Z0_DECHARGE_02:
    /* Entry 'ACTION_RETOUR_Z0_DECHARGE_02': '<S1>:4388' */
    ModeleRobot_DWork.is_JAUNE_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_02;
    ModeleRobot_DWork.was_JAUNE_RETOUR_ZONE_DEPART_ET = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_02;

    /*  termine en boucle ouverte pour venir buter contre la bordure */
    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = -20.0;
    ModeleRobot_B.CommandeManuelleD = -20.0;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case IN_ACTION_RETOUR_Z0_DECHARGE_03:
    /* Entry 'ACTION_RETOUR_Z0_DECHARGE_03': '<S1>:4392' */
    ModeleRobot_DWork.is_JAUNE_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_03;
    ModeleRobot_DWork.was_JAUNE_RETOUR_ZONE_DEPART_ET = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_03;

    /*  fin d'étape */
    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 0.0;
    ModeleRobot_B.CommandeManuelleD = 0.0;
    break;

   case IN_ACTION_RETOUR_Z0_DECHARGE_04:
    /* Entry 'ACTION_RETOUR_Z0_DECHARGE_04': '<S1>:4389' */
    ModeleRobot_DWork.is_JAUNE_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_04;
    ModeleRobot_DWork.was_JAUNE_RETOUR_ZONE_DEPART_ET = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_04;
    ModeleRobot_DWork.TempoMot = 0.0;

    /*  arrête de buter contre la bordure */
    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 0.0;
    ModeleRobot_B.CommandeManuelleD = 0.0;

    /*  ouvre le clapet de déchargement */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p46 - 1.0)] =
      ModeleRobot_P.SFunction_p47;

    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p18 - 1.0)] =
      0.0;
    break;

   case IN_ACTION_RETOUR_Z0_DECHARGE_06:
    /* Entry 'ACTION_RETOUR_Z0_DECHARGE_06': '<S1>:4390' */
    ModeleRobot_DWork.is_JAUNE_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_06;
    ModeleRobot_DWork.was_JAUNE_RETOUR_ZONE_DEPART_ET = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_06;
    ModeleRobot_DWork.TempoMot = 0.0;

    /*  aide à l'évacuation */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p16 - 1.0)] =
      -100.0;
    break;

   case IN_ACTION_RETOUR_Z0_DECHARGE_07:
    /* Entry 'ACTION_RETOUR_Z0_DECHARGE_07': '<S1>:4391' */
    ModeleRobot_DWork.is_JAUNE_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_07;
    ModeleRobot_DWork.was_JAUNE_RETOUR_ZONE_DEPART_ET = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_07;
    ModeleRobot_DWork.TempoMot = 0.0;

    /*  aide à l'évacuation */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p16 - 1.0)] =
      0.0;

    /*  remet le robot dans une position connue pour la prochaine étape */
    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 20.0;
    ModeleRobot_B.CommandeManuelleD = 20.0;
    break;

   default:
    /* Transition: '<S1>:4379' */
    /* Entry 'ACTION_RETOUR_Z0_DECHARGE_01': '<S1>:4387' */
    ModeleRobot_DWork.is_JAUNE_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_01;
    ModeleRobot_DWork.was_JAUNE_RETOUR_ZONE_DEPART_ET = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_01;

    /* va vers une position de référence */
    /* Graphical Function 'Mouvement_Distance': '<S1>:1347' */
    /* Transition: '<S1>:1349' */
    ModeleRobot_B.DdeMvtDistanceAngle = ModeleRobot_B.DdeMvtDistanceAngle + 1.0;
    ModeleRobot_B.ConsigneDistance = -80.0;

    /*  ConsigneTeta reste inchangé. */
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

    /*  le souffleur évacue les boules éventuellement derrière le robot qu pourraient gêner */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p18 - 1.0)] =
      -100.0;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void enter_atomic_VERT_GOTO_DISTRIBU(void)
{
  /* Entry 'VERT_GOTO_DISTRIBUTEURS_ET_RECUPERE': '<S1>:4423' */
  ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)IN_VERT_GOTO_DISTRIBUTEURS_ET_R;
  ModeleRobot_DWork.was_STRATEGIE1 = (uint8_T)IN_VERT_GOTO_DISTRIBUTEURS_ET_R;
  ModeleRobot_DWork.TempoMot = 0.0;
  ModeleRobot_DWork.inhibeObstacle = 0.0;
  ModeleRobot_DWork.nbreDistributeursTraites = 0.0;
  ModeleRobot_DWork.x_old = 0.0;
  ModeleRobot_DWork.y_old = 0.0;
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void enter_internal_VERT_GOTO_DISTRI(void)
{
  switch (ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_) {
   case ModeleRobo_IN_ACTION_DISTRIB_01:
    /* Entry 'ACTION_DISTRIB_01': '<S1>:4437' */
    ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_01;
    ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_01;

    /* Graphical Function 'CommandeLEDS_RVBO': '<S1>:1339' */
    /* Transition: '<S1>:1341' */
    ModeleRobot_B.EtatLed1 = 1.0;
    ModeleRobot_B.EtatLed2 = 1.0;
    ModeleRobot_B.EtatLed3 = 1.0;
    ModeleRobot_B.EtatLed4 = 1.0;
    ModeleRobot_DWork.positionDistributeur_X = 42.0;

    /*  erreur constatée en pratique (normalement 36cm)
       va vers une position de référence */
    /* Graphical Function 'Mouvement_XY': '<S1>:1289' */
    /* Transition: '<S1>:1291' */
    ModeleRobot_B.DdeMvtXY = ModeleRobot_B.DdeMvtXY + 1.0;
    ModeleRobot_B.ConsigneX = ModeleRobot_DWork.positionDistributeur_X;
    ModeleRobot_B.ConsigneY = 0.0;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRob_IN_ACTION_DISTRIB_010:
    /* Entry 'ACTION_DISTRIB_010': '<S1>:4439' */
    ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
      ModeleRob_IN_ACTION_DISTRIB_010;
    ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRob_IN_ACTION_DISTRIB_010;

    /* va en marche arrière jusque devant le distributeur sans l'atteindre */
    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = ModeleRobot_DWork.positionDistributeur_X;
    ModeleRobot_B.ConsigneY = 70.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_B.ConsigneTeta = (-ModeleRobot_P.SFunction_p19) / 2.0 *
      ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRob_IN_ACTION_DISTRIB_011:
    /* Entry 'ACTION_DISTRIB_011': '<S1>:4445' */
    ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
      ModeleRob_IN_ACTION_DISTRIB_011;
    ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRob_IN_ACTION_DISTRIB_011;

    /*  s'éloinge de la bordure */
    ModeleRobot_DWork.inhibeObstacle = 0.0;

    /* Graphical Function 'Mouvement_XY': '<S1>:1289' */
    /* Transition: '<S1>:1291' */
    ModeleRobot_B.DdeMvtXY = ModeleRobot_B.DdeMvtXY + 1.0;
    ModeleRobot_B.ConsigneX = ModeleRobot_DWork.positionDistributeur_X;
    ModeleRobot_B.ConsigneY = 63.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p43 - 1.0)] =
      ModeleRobot_P.SFunction_p44;

    /*  petite pichnette sur le servo pour éviter de racler contre le distributeur */
    break;

   case ModeleRobo_IN_ACTION_DISTRIB_02:
    /* Entry 'ACTION_DISTRIB_02': '<S1>:4441' */
    ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_02;
    ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_02;
    ModeleRobot_DWork.inhibeObstacle = 1.0;
    break;

   case ModeleRobo_IN_ACTION_DISTRIB_03:
    /* Entry 'ACTION_DISTRIB_03': '<S1>:4442' */
    ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_03;
    ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_03;

    /*  termine en boucle ouverte pour venir buter contre la bordure */
    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = -25.0;
    ModeleRobot_B.CommandeManuelleD = -25.0;

    /*  le souffleur évacue les boules éventuellement derrière le robot qu pourraient gêner */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p18 - 1.0)] =
      -100.0;

    /*  sort le tobogan et lance la souflerie */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p43 - 1.0)] =
      ModeleRobot_P.SFunction_p45;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobo_IN_ACTION_DISTRIB_04:
    /* Entry 'ACTION_DISTRIB_04': '<S1>:4443' */
    ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_04;
    ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_04;

    /*  arrête de buter contre la bordure */
    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 0.0;
    ModeleRobot_B.CommandeManuelleD = 0.0;

    /*  ATTENTION : recalage de la position du robot
       setPosition(36,77.5*invMouv, (-PI/2)*invMouv); */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p16 - 1.0)] =
      100.0;

    /*  arrête le souffleur du bas */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p18 - 1.0)] =
      0.0;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobo_IN_ACTION_DISTRIB_05:
    /* Entry 'ACTION_DISTRIB_05': '<S1>:4444' */
    ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_05;
    ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_05;

    /*  Arrête la souflerie pour laisser les balles tomber (et attend un peu) */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p16 - 1.0)] =
      0.0;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case ModeleRobo_IN_ACTION_DISTRIB_06:
    /* Entry 'ACTION_DISTRIB_06': '<S1>:4447' */
    ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_06;
    ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_06;
    ModeleRobot_DWork.nbreDistributeursTraites =
      ModeleRobot_DWork.nbreDistributeursTraites + 1.0;
    break;

   case ModeleRobo_IN_ACTION_DISTRIB_07:
    /* Entry 'ACTION_DISTRIB_07': '<S1>:4448' */
    ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_07;
    ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_07;

    /*  Ferme le servo du recolteur une fois tout terminé */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p43 - 1.0)] =
      ModeleRobot_P.SFunction_p44;

    /*  retourne à la position de référence */
    ModeleRobot_DWork.inhibeObstacle = 1.0;

    /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
    /* Transition: '<S1>:3697' */
    ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
    ModeleRobot_B.ConsigneX = 75.0;
    ModeleRobot_B.ConsigneY = 0.0;
    ModeleRobot_B.ConsigneTeta = 0.0;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    break;

   case ModeleRobo_IN_ACTION_DISTRIB_08:
    /* Entry 'ACTION_DISTRIB_08': '<S1>:4450' */
    ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_08;
    ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_08;

    /* Fin d'étape */
    ModeleRobot_DWork.Etape_recuperationDistributeurs = 0.0;
    break;

   case ModeleRobo_IN_ACTION_DISTRIB_09:
    /* Entry 'ACTION_DISTRIB_09': '<S1>:4438' */
    ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_09;
    ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_09;

    /* va en marche arrière jusque devant le distributeur sans l'atteindre */
    /* Graphical Function 'Mouvement_Angle': '<S1>:1354' */
    /* Transition: '<S1>:1356' */
    ModeleRobot_B.DdeMvtDistanceAngle = ModeleRobot_B.DdeMvtDistanceAngle + 1.0;
    ModeleRobot_B.ConsigneDistance = 0.0;
    ModeleRobot_B.ConsigneTeta = (-ModeleRobot_P.SFunction_p19) / 2.0 *
      ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   default:
    /* Transition: '<S1>:4425' */
    /* Entry 'ACTION_DISTRIB_01': '<S1>:4437' */
    ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_01;
    ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
      ModeleRobo_IN_ACTION_DISTRIB_01;

    /* Graphical Function 'CommandeLEDS_RVBO': '<S1>:1339' */
    /* Transition: '<S1>:1341' */
    ModeleRobot_B.EtatLed1 = 1.0;
    ModeleRobot_B.EtatLed2 = 1.0;
    ModeleRobot_B.EtatLed3 = 1.0;
    ModeleRobot_B.EtatLed4 = 1.0;
    ModeleRobot_DWork.positionDistributeur_X = 42.0;

    /*  erreur constatée en pratique (normalement 36cm)
       va vers une position de référence */
    /* Graphical Function 'Mouvement_XY': '<S1>:1289' */
    /* Transition: '<S1>:1291' */
    ModeleRobot_B.DdeMvtXY = ModeleRobot_B.DdeMvtXY + 1.0;
    ModeleRobot_B.ConsigneX = ModeleRobot_DWork.positionDistributeur_X;
    ModeleRobot_B.ConsigneY = 0.0;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void enter_atomic_VERT_RETOUR_ZONE_D(void)
{
  /* Entry 'VERT_RETOUR_ZONE_DEPART_ET_DECHARGE': '<S1>:4451' */
  ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)IN_VERT_RETOUR_ZONE_DEPART_ET_D;
  ModeleRobot_DWork.was_STRATEGIE1 = (uint8_T)IN_VERT_RETOUR_ZONE_DEPART_ET_D;
  ModeleRobot_DWork.TempoMot = 0.0;
  ModeleRobot_DWork.inhibeObstacle = 0.0;
  ModeleRobot_DWork.x_old = 0.0;
  ModeleRobot_DWork.y_old = 0.0;
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void enter_internal_VERT_RETOUR_ZONE(void)
{
  switch (ModeleRobot_DWork.was_VERT_RETOUR_ZONE_DEPART_ET_) {
   case IN_ACTION_RETOUR_Z0_DECHARGE_01:
    /* Entry 'ACTION_RETOUR_Z0_DECHARGE_01': '<S1>:4461' */
    ModeleRobot_DWork.is_VERT_RETOUR_ZONE_DEPART_ET_D = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_01;
    ModeleRobot_DWork.was_VERT_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_01;

    /* va vers une position de référence */
    /* Graphical Function 'Mouvement_XY': '<S1>:1289' */
    /* Transition: '<S1>:1291' */
    ModeleRobot_B.DdeMvtXY = ModeleRobot_B.DdeMvtXY + 1.0;
    ModeleRobot_B.ConsigneX = 11.0;
    ModeleRobot_B.ConsigneY = 0.0;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

    /*  le souffleur évacue les boules éventuellement derrière le robot qu pourraient gêner */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p18 - 1.0)] =
      -100.0;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case IN_ACTION_RETOUR_Z0_DECHARGE_02:
    /* Entry 'ACTION_RETOUR_Z0_DECHARGE_02': '<S1>:4462' */
    ModeleRobot_DWork.is_VERT_RETOUR_ZONE_DEPART_ET_D = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_02;
    ModeleRobot_DWork.was_VERT_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_02;

    /*  termine en boucle ouverte pour venir buter contre la bordure */
    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = -20.0;
    ModeleRobot_B.CommandeManuelleD = -20.0;
    ModeleRobot_DWork.TempoMot = 0.0;
    break;

   case IN_ACTION_RETOUR_Z0_DECHARGE_03:
    /* Entry 'ACTION_RETOUR_Z0_DECHARGE_03': '<S1>:4466' */
    ModeleRobot_DWork.is_VERT_RETOUR_ZONE_DEPART_ET_D = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_03;
    ModeleRobot_DWork.was_VERT_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_03;

    /*  fin d'étape */
    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 0.0;
    ModeleRobot_B.CommandeManuelleD = 0.0;
    break;

   case IN_ACTION_RETOUR_Z0_DECHARGE_04:
    /* Entry 'ACTION_RETOUR_Z0_DECHARGE_04': '<S1>:4463' */
    ModeleRobot_DWork.is_VERT_RETOUR_ZONE_DEPART_ET_D = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_04;
    ModeleRobot_DWork.was_VERT_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_04;
    ModeleRobot_DWork.TempoMot = 0.0;

    /*  arrête de buter contre la bordure */
    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 0.0;
    ModeleRobot_B.CommandeManuelleD = 0.0;

    /*  ouvre le clapet de déchargement */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p46 - 1.0)] =
      ModeleRobot_P.SFunction_p47;

    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p18 - 1.0)] =
      0.0;
    break;

   case IN_ACTION_RETOUR_Z0_DECHARGE_06:
    /* Entry 'ACTION_RETOUR_Z0_DECHARGE_06': '<S1>:4464' */
    ModeleRobot_DWork.is_VERT_RETOUR_ZONE_DEPART_ET_D = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_06;
    ModeleRobot_DWork.was_VERT_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_06;
    ModeleRobot_DWork.TempoMot = 0.0;

    /*  aide à l'évacuation */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p16 - 1.0)] =
      -100.0;
    break;

   case IN_ACTION_RETOUR_Z0_DECHARGE_07:
    /* Entry 'ACTION_RETOUR_Z0_DECHARGE_07': '<S1>:4465' */
    ModeleRobot_DWork.is_VERT_RETOUR_ZONE_DEPART_ET_D = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_07;
    ModeleRobot_DWork.was_VERT_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_07;
    ModeleRobot_DWork.TempoMot = 0.0;

    /*  aide à l'évacuation */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p16 - 1.0)] =
      0.0;

    /*  remet le robot dans une position connue pour la prochaine étape */
    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 20.0;
    ModeleRobot_B.CommandeManuelleD = 20.0;
    break;

   default:
    /* Transition: '<S1>:4453' */
    /* Entry 'ACTION_RETOUR_Z0_DECHARGE_01': '<S1>:4461' */
    ModeleRobot_DWork.is_VERT_RETOUR_ZONE_DEPART_ET_D = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_01;
    ModeleRobot_DWork.was_VERT_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
      IN_ACTION_RETOUR_Z0_DECHARGE_01;

    /* va vers une position de référence */
    /* Graphical Function 'Mouvement_XY': '<S1>:1289' */
    /* Transition: '<S1>:1291' */
    ModeleRobot_B.DdeMvtXY = ModeleRobot_B.DdeMvtXY + 1.0;
    ModeleRobot_B.ConsigneX = 11.0;
    ModeleRobot_B.ConsigneY = 0.0;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

    /*  le souffleur évacue les boules éventuellement derrière le robot qu pourraient gêner */
    /* Graphical Function 'setPWM': '<S1>:4112' */
    /* Transition: '<S1>:4114' */
    ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p18 - 1.0)] =
      -100.0;
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
    Mod_enter_atomic_INIT_STRATEGIE();
    break;

   case IN_JAUNE_GOTO_DISTRIBUTEURS_ET_:
    enter_atomic_JAUNE_GOTO_DISTRIB();
    enter_internal_JAUNE_GOTO_DISTR();
    break;

   case IN_JAUNE_RETOUR_ZONE_DEPART_ET_:
    enter_atomic_JAUNE_RETOUR_ZONE_();
    enter_internal_JAUNE_RETOUR_ZON();
    break;

   case IN_VERT_GOTO_DISTRIBUTEURS_ET_R:
    enter_atomic_VERT_GOTO_DISTRIBU();
    enter_internal_VERT_GOTO_DISTRI();
    break;

   case IN_VERT_RETOUR_ZONE_DEPART_ET_D:
    enter_atomic_VERT_RETOUR_ZONE_D();
    enter_internal_VERT_RETOUR_ZONE();
    break;

   default:
    /* Transition: '<S1>:1125' */
    Mod_enter_atomic_INIT_STRATEGIE();
    break;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_ACTION_HOMOLO_46(void)
{
  /* During 'ACTION_HOMOLO_46': '<S1>:4395' */
  if (ModeleRobot_DWork.TempoMot > 1.0 / ModeleRobot_P.SFunction_p49) {
    /* Transition: '<S1>:4250' */
    /* Exit 'ACTION_HOMOLO_46': '<S1>:4395' */
    /* Entry 'ACTION_HOMOLO_15': '<S1>:4237' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_15;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_15;

    /* on relache la balle */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p37 - 1.0)] =
      ModeleRobot_P.SFunction_p40;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p31 - 1.0)] =
      ModeleRobot_P.SFunction_p34;
    ModeleRobot_DWork.TempoMot = 0.0;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_ACTION_HOMOLO_47(void)
{
  /* During 'ACTION_HOMOLO_47': '<S1>:4409' */
  /* Graphical Function 'isFinMouvementRapide': '<S1>:3865' */
  /* Transition: '<S1>:3868' */
  ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt +
    1.0;

  /* Transition: '<S1>:3869' */
  if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 / ModeleRobot_P.SFunction_p49)
       || (ModeleRobot_B.DataTypeConversion_g != 0.0)) != 0) {
    /* Transition: '<S1>:4410' */
    /* Exit 'ACTION_HOMOLO_47': '<S1>:4409' */
    /* Entry 'ACTION_HOMOLO_48': '<S1>:4411' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_48;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_48;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p20 - 1.0)] =
      ModeleRobot_P.SFunction_p22;
    ModeleRobot_DWork.TempoMot = 0.0;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_ACTION_HOMOLO_48(void)
{
  /* During 'ACTION_HOMOLO_48': '<S1>:4411' */
  if (ModeleRobot_DWork.TempoMot > 0.5 / ModeleRobot_P.SFunction_p49) {
    /* Transition: '<S1>:4414' */
    /* Exit 'ACTION_HOMOLO_48': '<S1>:4411' */
    /* Entry 'ACTION_HOMOLO_49': '<S1>:4413' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_49;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_49;

    /* on avance parallelement a la bordure et on ferme les claps */
    /* Graphical Function 'Mouvement_XY': '<S1>:1289' */
    /* Transition: '<S1>:1291' */
    ModeleRobot_B.DdeMvtXY = ModeleRobot_B.DdeMvtXY + 1.0;
    ModeleRobot_B.ConsigneX = 74.0;
    ModeleRobot_B.ConsigneY = -77.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_ACTION_HOMOLO_49(void)
{
  /* During 'ACTION_HOMOLO_49': '<S1>:4413' */
  /* Graphical Function 'isFinMouvementRapide': '<S1>:3865' */
  /* Transition: '<S1>:3868' */
  ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt +
    1.0;

  /* Transition: '<S1>:3869' */
  if (((ModeleRobot_DWork.CompteurTimeoutMvt > 2.0 / ModeleRobot_P.SFunction_p49)
       || (ModeleRobot_B.DataTypeConversion_g != 0.0)) != 0) {
    /* Transition: '<S1>:4417' */
    /* Exit 'ACTION_HOMOLO_49': '<S1>:4413' */
    /* Entry 'ACTION_18': '<S1>:4139' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_18;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_18;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p20 - 1.0)] =
      ModeleRobot_P.SFunction_p21;
    ModeleRobot_DWork.finHomologation = 1.0;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_ACTION_HOMOLO_50(void)
{
  /* During 'ACTION_HOMOLO_50': '<S1>:4471' */
  /* Graphical Function 'isFinMouvementRapide': '<S1>:3865' */
  /* Transition: '<S1>:3868' */
  ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt +
    1.0;

  /* Transition: '<S1>:3869' */
  if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 / ModeleRobot_P.SFunction_p49)
       || (ModeleRobot_B.DataTypeConversion_g != 0.0)) != 0) {
    /* Transition: '<S1>:4476' */
    /* Exit 'ACTION_HOMOLO_50': '<S1>:4471' */
    /* Entry 'ACTION_HOMOLO_51': '<S1>:4477' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_51;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_51;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p20 - 1.0)] =
      ModeleRobot_P.SFunction_p21;
    ModeleRobot_DWork.TempoMot = 0.0;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_ACTION_HOMOLO_51(void)
{
  /* During 'ACTION_HOMOLO_51': '<S1>:4477' */
  if (ModeleRobot_DWork.TempoMot > 0.5 / ModeleRobot_P.SFunction_p49) {
    /* Transition: '<S1>:4492' */
    /* Exit 'ACTION_HOMOLO_51': '<S1>:4477' */
    /* Entry 'ACTION_HOMOLO_52': '<S1>:4489' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_52;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_52;

    /* on avance parallelement a la bordure et on ferme les claps */
    /* Graphical Function 'Mouvement_XY': '<S1>:1289' */
    /* Transition: '<S1>:1291' */
    ModeleRobot_B.DdeMvtXY = ModeleRobot_B.DdeMvtXY + 1.0;
    ModeleRobot_B.ConsigneX = 62.0;
    ModeleRobot_B.ConsigneY = -77.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_ACTION_HOMOLO_52(void)
{
  /* During 'ACTION_HOMOLO_52': '<S1>:4489' */
  /* Graphical Function 'isFinMouvementRapide': '<S1>:3865' */
  /* Transition: '<S1>:3868' */
  ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt +
    1.0;

  /* Transition: '<S1>:3869' */
  if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 / ModeleRobot_P.SFunction_p49)
       || (ModeleRobot_B.DataTypeConversion_g != 0.0)) != 0) {
    /* Transition: '<S1>:4493' */
    /* Exit 'ACTION_HOMOLO_52': '<S1>:4489' */
    /* Entry 'ACTION_HOMOLO_53': '<S1>:4490' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_53;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_53;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p20 - 1.0)] =
      ModeleRobot_P.SFunction_p22;
    ModeleRobot_DWork.TempoMot = 0.0;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_ACTION_HOMOLO_53(void)
{
  /* During 'ACTION_HOMOLO_53': '<S1>:4490' */
  if (ModeleRobot_DWork.TempoMot > 0.5 / ModeleRobot_P.SFunction_p49) {
    /* Transition: '<S1>:4494' */
    /* Exit 'ACTION_HOMOLO_53': '<S1>:4490' */
    /* Entry 'ACTION_HOMOLO_54': '<S1>:4491' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_54;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_54;

    /* on avance parallelement a la bordure et on ferme les claps */
    /* Graphical Function 'Mouvement_XY': '<S1>:1289' */
    /* Transition: '<S1>:1291' */
    ModeleRobot_B.DdeMvtXY = ModeleRobot_B.DdeMvtXY + 1.0;
    ModeleRobot_B.ConsigneX = 82.0;
    ModeleRobot_B.ConsigneY = -77.0 * ModeleRobot_DWork.invMouv;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_ACTION_HOMOLO_54(void)
{
  /* During 'ACTION_HOMOLO_54': '<S1>:4491' */
  /* Graphical Function 'isFinMouvementRapide': '<S1>:3865' */
  /* Transition: '<S1>:3868' */
  ModeleRobot_DWork.CompteurTimeoutMvt = ModeleRobot_DWork.CompteurTimeoutMvt +
    1.0;

  /* Transition: '<S1>:3869' */
  if (((ModeleRobot_DWork.CompteurTimeoutMvt > 2.0 / ModeleRobot_P.SFunction_p49)
       || (ModeleRobot_B.DataTypeConversion_g != 0.0)) != 0) {
    /* Transition: '<S1>:4495' */
    /* Exit 'ACTION_HOMOLO_54': '<S1>:4491' */
    /* Entry 'ACTION_18': '<S1>:4139' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_18;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_18;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p20 - 1.0)] =
      ModeleRobot_P.SFunction_p21;
    ModeleRobot_DWork.finHomologation = 1.0;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_ACTION_HOMOLO_55(void)
{
  /* During 'ACTION_HOMOLO_55': '<S1>:4498' */
  if (ModeleRobot_DWork.TempoMot > 1.0 / ModeleRobot_P.SFunction_p49) {
    /* Transition: '<S1>:4499' */
    /* Exit 'ACTION_HOMOLO_55': '<S1>:4498' */
    /* Entry 'ACTION_HOMOLO_57': '<S1>:4502' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_57;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_57;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
      ModeleRobot_P.SFunction_p25;
    ModeleRobot_DWork.TempoMot = 0.0;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_ACTION_HOMOLO_56(void)
{
  /* During 'ACTION_HOMOLO_56': '<S1>:4500' */
  if (ModeleRobot_DWork.TempoMot > 1.0 / ModeleRobot_P.SFunction_p49) {
    /* Transition: '<S1>:4501' */
    /* Exit 'ACTION_HOMOLO_56': '<S1>:4500' */
    /* Entry 'ACTION_HOMOLO_58': '<S1>:4504' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_58;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_58;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
      ModeleRobot_P.SFunction_p29;
    ModeleRobot_DWork.TempoMot = 0.0;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_ACTION_HOMOLO_57(void)
{
  /* During 'ACTION_HOMOLO_57': '<S1>:4502' */
  if (ModeleRobot_DWork.TempoMot > 0.5 / ModeleRobot_P.SFunction_p49) {
    /* Transition: '<S1>:4503' */
    /* Exit 'ACTION_HOMOLO_57': '<S1>:4502' */
    /* Entry 'ACTION_HOMOLO_40': '<S1>:4338' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_40;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_40;

    /* le bras est à droite du robot, demi tour */
    /* Graphical Function 'Mouvement_Angle': '<S1>:1354' */
    /* Transition: '<S1>:1356' */
    ModeleRobot_B.DdeMvtDistanceAngle = ModeleRobot_B.DdeMvtDistanceAngle + 1.0;
    ModeleRobot_B.ConsigneDistance = 0.0;
    ModeleRobot_B.ConsigneTeta = 0.0;
    ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_ACTION_HOMOLO_58(void)
{
  /* During 'ACTION_HOMOLO_58': '<S1>:4504' */
  if (ModeleRobot_DWork.TempoMot > 0.5 / ModeleRobot_P.SFunction_p49) {
    /* Transition: '<S1>:4505' */
    /* Exit 'ACTION_HOMOLO_58': '<S1>:4504' */
    /* Entry 'ACTION_HOMOLO_43': '<S1>:4343' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_43;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_43;

    /* BO pour pousser les spots */
    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 25.0;
    ModeleRobot_B.CommandeManuelleD = 25.0;
    ModeleRobot_DWork.TempoMot = 0.0;
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
  if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 / ModeleRobot_P.SFunction_p49)
       || (ModeleRobot_B.DataTypeConversion != 0.0)) != 0) {
    /* Transition: '<S1>:4168' */
    /* Exit 'ACTION_HOMOLO_6': '<S1>:4187' */
    /* Entry 'ACTION_HOMOLO_8': '<S1>:4192' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_8;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_8;

    /* on centre le spot */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
      ModeleRobot_P.SFunction_p28;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
      ModeleRobot_P.SFunction_p24;
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
  if (((ModeleRobot_DWork.CompteurTimeoutMvt > 2.0 / ModeleRobot_P.SFunction_p49)
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
  if (ModeleRobot_DWork.TempoMot > 1.0 / ModeleRobot_P.SFunction_p49) {
    /* Transition: '<S1>:4238' */
    /* Exit 'ACTION_HOMOLO_8': '<S1>:4192' */
    /* Entry 'ACTION_HOMOLO_46': '<S1>:4395' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_46;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_46;

    /* on centre le spot */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)] =
      ModeleRobot_P.SFunction_p30;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)] =
      ModeleRobot_P.SFunction_p26;
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
  if (((ModeleRobot_DWork.CompteurTimeoutMvt > 5.0 / ModeleRobot_P.SFunction_p49)
       || (ModeleRobot_B.DataTypeConversion != 0.0)) != 0) {
    /* Transition: '<S1>:4208' */
    /* Exit 'ACTION_HOMOLO_9': '<S1>:4203' */
    /* Entry 'ACTION_HOMOLO_11': '<S1>:4207' */
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_11;
    ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_11;

    /* pas de robot possible dans ce coin, on inhibe la detection d'obstacle */
    ModeleRobot_DWork.inhibeObstacle = 1.0;

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
static void ModeleRobot_exit_internal_DEMO(void)
{
  if (ModeleRobot_DWork.is_DEMO == ModeleRobot_IN_ACTION_HOMOLO_2) {
    /* Exit 'ACTION_HOMOLO_2': '<S1>:4167' */
    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p37 - 1.0)] =
      ModeleRobot_P.SFunction_p41;

    /* Graphical Function 'setServo': '<S1>:4141' */
    /* Transition: '<S1>:4143' */
    ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p31 - 1.0)] =
      ModeleRobot_P.SFunction_p35;
    ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_NO_ACTIVE_CHILD;
  } else {
    /* Exit 'ACTION_18': '<S1>:4139' */
    /* Exit 'ACTION_HOMOLO_0': '<S1>:4165' */
    /* Exit 'ACTION_HOMOLO_01': '<S1>:4181' */
    /* Exit 'ACTION_HOMOLO_02': '<S1>:4183' */
    /* Exit 'ACTION_HOMOLO_03': '<S1>:4220' */
    /* Exit 'ACTION_HOMOLO_05': '<S1>:4239' */
    /* Exit 'ACTION_HOMOLO_09': '<S1>:4280' */
    /* Exit 'ACTION_HOMOLO_10': '<S1>:4204' */
    /* Exit 'ACTION_HOMOLO_11': '<S1>:4207' */
    /* Exit 'ACTION_HOMOLO_12': '<S1>:4210' */
    /* Exit 'ACTION_HOMOLO_13': '<S1>:4213' */
    /* Exit 'ACTION_HOMOLO_14': '<S1>:4215' */
    /* Exit 'ACTION_HOMOLO_15': '<S1>:4237' */
    /* Exit 'ACTION_HOMOLO_16': '<S1>:4243' */
    /* Exit 'ACTION_HOMOLO_24': '<S1>:4279' */
    /* Exit 'ACTION_HOMOLO_25': '<S1>:4281' */
    /* Exit 'ACTION_HOMOLO_30': '<S1>:4296' */
    /* Exit 'ACTION_HOMOLO_33': '<S1>:4309' */
    /* Exit 'ACTION_HOMOLO_34': '<S1>:4311' */
    /* Exit 'ACTION_HOMOLO_35': '<S1>:4314' */
    /* Exit 'ACTION_HOMOLO_36': '<S1>:4316' */
    /* Exit 'ACTION_HOMOLO_4': '<S1>:4169' */
    /* Exit 'ACTION_HOMOLO_40': '<S1>:4338' */
    /* Exit 'ACTION_HOMOLO_41': '<S1>:4339' */
    /* Exit 'ACTION_HOMOLO_43': '<S1>:4343' */
    /* Exit 'ACTION_HOMOLO_44': '<S1>:4348' */
    /* Exit 'ACTION_HOMOLO_45': '<S1>:4350' */
    /* Exit 'ACTION_HOMOLO_46': '<S1>:4395' */
    /* Exit 'ACTION_HOMOLO_47': '<S1>:4409' */
    /* Exit 'ACTION_HOMOLO_48': '<S1>:4411' */
    /* Exit 'ACTION_HOMOLO_49': '<S1>:4413' */
    /* Exit 'ACTION_HOMOLO_50': '<S1>:4471' */
    /* Exit 'ACTION_HOMOLO_51': '<S1>:4477' */
    /* Exit 'ACTION_HOMOLO_52': '<S1>:4489' */
    /* Exit 'ACTION_HOMOLO_53': '<S1>:4490' */
    /* Exit 'ACTION_HOMOLO_54': '<S1>:4491' */
    /* Exit 'ACTION_HOMOLO_55': '<S1>:4498' */
    /* Exit 'ACTION_HOMOLO_56': '<S1>:4500' */
    /* Exit 'ACTION_HOMOLO_57': '<S1>:4502' */
    /* Exit 'ACTION_HOMOLO_58': '<S1>:4504' */
    /* Exit 'ACTION_HOMOLO_6': '<S1>:4187' */
    /* Exit 'ACTION_HOMOLO_7': '<S1>:4189' */
    /* Exit 'ACTION_HOMOLO_8': '<S1>:4192' */
    /* Exit 'ACTION_HOMOLO_9': '<S1>:4203' */
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_DEMO(void)
{
  /* During 'DEMO': '<S1>:3463' */
  if (ModeleRobot_DWork.finHomologation == 1.0) {
    /* Transition: '<S1>:4396' */
    if (ModeleRobot_DWork.CouleurEquipe_memo == ModeleRobot_P.SFunction_p5) {
      /* Transition: '<S1>:4421' */
      ModeleRobot_exit_internal_DEMO();

      /* Exit 'DEMO': '<S1>:3463' */
      ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)ModeleRobot_IN_NO_ACTIVE_CHILD;
      enter_atomic_JAUNE_GOTO_DISTRIB();
      enter_internal_JAUNE_GOTO_DISTR();
    } else {
      /* Transition: '<S1>:4468' */
      if (ModeleRobot_DWork.is_DEMO == ModeleRobot_IN_ACTION_HOMOLO_2) {
        /* Exit 'ACTION_HOMOLO_2': '<S1>:4167' */
        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p37 - 1.0)]
          = ModeleRobot_P.SFunction_p41;

        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p31 - 1.0)]
          = ModeleRobot_P.SFunction_p35;
        ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_NO_ACTIVE_CHILD;
      } else {
        /* Exit 'ACTION_18': '<S1>:4139' */
        /* Exit 'ACTION_HOMOLO_0': '<S1>:4165' */
        /* Exit 'ACTION_HOMOLO_01': '<S1>:4181' */
        /* Exit 'ACTION_HOMOLO_02': '<S1>:4183' */
        /* Exit 'ACTION_HOMOLO_03': '<S1>:4220' */
        /* Exit 'ACTION_HOMOLO_05': '<S1>:4239' */
        /* Exit 'ACTION_HOMOLO_09': '<S1>:4280' */
        /* Exit 'ACTION_HOMOLO_10': '<S1>:4204' */
        /* Exit 'ACTION_HOMOLO_11': '<S1>:4207' */
        /* Exit 'ACTION_HOMOLO_12': '<S1>:4210' */
        /* Exit 'ACTION_HOMOLO_13': '<S1>:4213' */
        /* Exit 'ACTION_HOMOLO_14': '<S1>:4215' */
        /* Exit 'ACTION_HOMOLO_15': '<S1>:4237' */
        /* Exit 'ACTION_HOMOLO_16': '<S1>:4243' */
        /* Exit 'ACTION_HOMOLO_24': '<S1>:4279' */
        /* Exit 'ACTION_HOMOLO_25': '<S1>:4281' */
        /* Exit 'ACTION_HOMOLO_30': '<S1>:4296' */
        /* Exit 'ACTION_HOMOLO_33': '<S1>:4309' */
        /* Exit 'ACTION_HOMOLO_34': '<S1>:4311' */
        /* Exit 'ACTION_HOMOLO_35': '<S1>:4314' */
        /* Exit 'ACTION_HOMOLO_36': '<S1>:4316' */
        /* Exit 'ACTION_HOMOLO_4': '<S1>:4169' */
        /* Exit 'ACTION_HOMOLO_40': '<S1>:4338' */
        /* Exit 'ACTION_HOMOLO_41': '<S1>:4339' */
        /* Exit 'ACTION_HOMOLO_43': '<S1>:4343' */
        /* Exit 'ACTION_HOMOLO_44': '<S1>:4348' */
        /* Exit 'ACTION_HOMOLO_45': '<S1>:4350' */
        /* Exit 'ACTION_HOMOLO_46': '<S1>:4395' */
        /* Exit 'ACTION_HOMOLO_47': '<S1>:4409' */
        /* Exit 'ACTION_HOMOLO_48': '<S1>:4411' */
        /* Exit 'ACTION_HOMOLO_49': '<S1>:4413' */
        /* Exit 'ACTION_HOMOLO_50': '<S1>:4471' */
        /* Exit 'ACTION_HOMOLO_51': '<S1>:4477' */
        /* Exit 'ACTION_HOMOLO_52': '<S1>:4489' */
        /* Exit 'ACTION_HOMOLO_53': '<S1>:4490' */
        /* Exit 'ACTION_HOMOLO_54': '<S1>:4491' */
        /* Exit 'ACTION_HOMOLO_55': '<S1>:4498' */
        /* Exit 'ACTION_HOMOLO_56': '<S1>:4500' */
        /* Exit 'ACTION_HOMOLO_57': '<S1>:4502' */
        /* Exit 'ACTION_HOMOLO_58': '<S1>:4504' */
        /* Exit 'ACTION_HOMOLO_6': '<S1>:4187' */
        /* Exit 'ACTION_HOMOLO_7': '<S1>:4189' */
        /* Exit 'ACTION_HOMOLO_8': '<S1>:4192' */
        /* Exit 'ACTION_HOMOLO_9': '<S1>:4203' */
      }

      /* Exit 'DEMO': '<S1>:3463' */
      ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)ModeleRobot_IN_NO_ACTIVE_CHILD;
      enter_atomic_VERT_GOTO_DISTRIBU();
      enter_internal_VERT_GOTO_DISTRI();
    }
  } else {
    ModeleRobot_DWork.TempoMot = ModeleRobot_DWork.TempoMot + 1.0;

    /* CommandeLEDS_RVBO(ObstacleARG,ObstacleARD, ObstacleAVG,ObstacleAVD);vv */
    switch (ModeleRobot_DWork.is_DEMO) {
     case ModeleRobot_IN_ACTION_18:
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_0:
      /* During 'ACTION_HOMOLO_0': '<S1>:4165' */
      if (ModeleRobot_DWork.TempoMot > 4.0 / ModeleRobot_P.SFunction_p49) {
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
        ModeleRobot_B.ConsigneTeta = ModeleRobot_P.SFunction_p19;
        ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_01:
      /* During 'ACTION_HOMOLO_01': '<S1>:4181' */
      if (ModeleRobot_DWork.TempoMot > 1.0 / ModeleRobot_P.SFunction_p49) {
        /* Transition: '<S1>:4185' */
        /* Exit 'ACTION_HOMOLO_01': '<S1>:4181' */
        /* Entry 'ACTION_HOMOLO_02': '<S1>:4183' */
        ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_02;
        ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_02;

        /* on monte l'ascenseur pour etre au dessus d'un spot */
        /* Graphical Function 'setPWM': '<S1>:4112' */
        /* Transition: '<S1>:4114' */
        ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p15 - 1.0)]
          = 60.0;

        /* tempo */
        ModeleRobot_DWork.TempoMot = 0.0;
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_02:
      /* During 'ACTION_HOMOLO_02': '<S1>:4183' */
      if ((ModeleRobot_U.IN_Ascenseur_pos >= ModeleRobot_P.SFunction_p9) ||
          (ModeleRobot_DWork.TempoMot > 4.0 / ModeleRobot_P.SFunction_p49)) {
        /* Transition: '<S1>:4182' */
        /* Exit 'ACTION_HOMOLO_02': '<S1>:4183' */
        /* Entry 'ACTION_HOMOLO_0': '<S1>:4165' */
        ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_0;
        ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_0;

        /* Graphical Function 'setPWM': '<S1>:4112' */
        /* Transition: '<S1>:4114' */
        ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p15 - 1.0)]
          = 0.0;
        ModeleRobot_DWork.TempoMot = 0.0;
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_03:
      /* During 'ACTION_HOMOLO_03': '<S1>:4220' */
      /* Graphical Function 'isFinMouvement': '<S1>:1282' */
      /* Transition: '<S1>:1285' */
      ModeleRobot_DWork.CompteurTimeoutMvt =
        ModeleRobot_DWork.CompteurTimeoutMvt + 1.0;

      /* Transition: '<S1>:1286' */
      /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
      if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 /
            ModeleRobot_P.SFunction_p49) || (ModeleRobot_B.DataTypeConversion !=
            0.0)) != 0) {
        /* Transition: '<S1>:4221' */
        /* Exit 'ACTION_HOMOLO_03': '<S1>:4220' */
        /* Entry 'ACTION_HOMOLO_7': '<S1>:4189' */
        ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_7;
        ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_7;
        ModeleRobot_DWork.inhibeObstacle = 0.0;

        /* on se tourne vers les spots */
        /* Graphical Function 'Mouvement_Angle': '<S1>:1354' */
        /* Transition: '<S1>:1356' */
        ModeleRobot_B.DdeMvtDistanceAngle = ModeleRobot_B.DdeMvtDistanceAngle +
          1.0;
        ModeleRobot_B.ConsigneDistance = 0.0;
        ModeleRobot_B.ConsigneTeta = -0.99 * ModeleRobot_DWork.invMouv;
        ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)]
          = ModeleRobot_P.SFunction_p30;

        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)]
          = ModeleRobot_P.SFunction_p26;
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_05:
      /* During 'ACTION_HOMOLO_05': '<S1>:4239' */
      if ((ModeleRobot_U.IN_Ascenseur_pos <= ModeleRobot_P.SFunction_p10) ||
          (ModeleRobot_DWork.TempoMot > 4.0 / ModeleRobot_P.SFunction_p49)) {
        /* Transition: '<S1>:4242' */
        /* Exit 'ACTION_HOMOLO_05': '<S1>:4239' */
        /* Entry 'ACTION_HOMOLO_16': '<S1>:4243' */
        ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_16;
        ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_16;

        /* on relache la balle */
        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p37 - 1.0)]
          = ModeleRobot_P.SFunction_p40;

        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p31 - 1.0)]
          = ModeleRobot_P.SFunction_p34;

        /* Graphical Function 'setPWM': '<S1>:4112' */
        /* Transition: '<S1>:4114' */
        ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p15 - 1.0)]
          = 0.0;
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_09:
      /* During 'ACTION_HOMOLO_09': '<S1>:4280' */
      if ((ModeleRobot_U.IN_Ascenseur_pos >= ModeleRobot_P.SFunction_p9) ||
          (ModeleRobot_DWork.TempoMot > 4.0 / ModeleRobot_P.SFunction_p49)) {
        /* Transition: '<S1>:4282' */
        if (ModeleRobot_DWork.CouleurEquipe_memo == ModeleRobot_P.SFunction_p5)
        {
          /* Transition: '<S1>:4285' */
          /* Exit 'ACTION_HOMOLO_09': '<S1>:4280' */
          /* Entry 'ACTION_HOMOLO_25': '<S1>:4281' */
          ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_25;
          ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_25;

          /* on rentre un  centreur */
          /* Graphical Function 'setPWM': '<S1>:4112' */
          /* Transition: '<S1>:4114' */
          ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p15 -
            1.0)] = 0.0;

          /* Graphical Function 'setServo': '<S1>:4141' */
          /* Transition: '<S1>:4143' */
          ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 -
            1.0)] = ModeleRobot_P.SFunction_p29;
          ModeleRobot_DWork.TempoMot = 0.0;
        } else {
          /* Transition: '<S1>:4310' */
          /* Exit 'ACTION_HOMOLO_09': '<S1>:4280' */
          /* Entry 'ACTION_HOMOLO_33': '<S1>:4309' */
          ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_33;
          ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_33;

          /* on rentre un  centreur */
          /* Graphical Function 'setPWM': '<S1>:4112' */
          /* Transition: '<S1>:4114' */
          ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p15 -
            1.0)] = 0.0;

          /* Graphical Function 'setServo': '<S1>:4141' */
          /* Transition: '<S1>:4143' */
          ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 -
            1.0)] = ModeleRobot_P.SFunction_p25;
          ModeleRobot_DWork.TempoMot = 0.0;
        }
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_10:
      /* During 'ACTION_HOMOLO_10': '<S1>:4204' */
      /* Graphical Function 'isFinMouvement': '<S1>:1282' */
      /* Transition: '<S1>:1285' */
      ModeleRobot_DWork.CompteurTimeoutMvt =
        ModeleRobot_DWork.CompteurTimeoutMvt + 1.0;

      /* Transition: '<S1>:1286' */
      /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
      if (((ModeleRobot_DWork.CompteurTimeoutMvt > 5.0 /
            ModeleRobot_P.SFunction_p49) || (ModeleRobot_B.DataTypeConversion !=
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
      ModeleRobot_DWork.CompteurTimeoutMvt =
        ModeleRobot_DWork.CompteurTimeoutMvt + 1.0;

      /* Transition: '<S1>:1286' */
      /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
      if (((ModeleRobot_DWork.CompteurTimeoutMvt > 5.0 /
            ModeleRobot_P.SFunction_p49) || (ModeleRobot_B.DataTypeConversion !=
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
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p43 - 1.0)]
          = ModeleRobot_P.SFunction_p45;
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_12:
      /* During 'ACTION_HOMOLO_12': '<S1>:4210' */
      if (ModeleRobot_DWork.TempoMot > 1.0 / ModeleRobot_P.SFunction_p49) {
        /* Transition: '<S1>:4214' */
        /* Exit 'ACTION_HOMOLO_12': '<S1>:4210' */
        /* Entry 'ACTION_HOMOLO_13': '<S1>:4213' */
        ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_13;
        ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_13;

        /* on souffle pendant 2 secondes */
        ModeleRobot_DWork.TempoMot = 0.0;

        /* Graphical Function 'setPWM': '<S1>:4112' */
        /* Transition: '<S1>:4114' */
        ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p18 - 1.0)]
          = 100.0;
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_13:
      /* During 'ACTION_HOMOLO_13': '<S1>:4213' */
      if (ModeleRobot_DWork.TempoMot > 2.0 / ModeleRobot_P.SFunction_p49) {
        /* Transition: '<S1>:4216' */
        /* Exit 'ACTION_HOMOLO_13': '<S1>:4213' */
        /* Entry 'ACTION_HOMOLO_14': '<S1>:4215' */
        ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_14;
        ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_14;

        /* on arrete de souffler et on rentre les recolteurs */
        /* Graphical Function 'setPWM': '<S1>:4112' */
        /* Transition: '<S1>:4114' */
        ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p18 - 1.0)]
          = 0.0;

        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p43 - 1.0)]
          = ModeleRobot_P.SFunction_p44;
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_14:
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_15:
      /* During 'ACTION_HOMOLO_15': '<S1>:4237' */
      if (ModeleRobot_DWork.TempoMot > 0.3 / ModeleRobot_P.SFunction_p49) {
        /* Transition: '<S1>:4196' */
        /* Exit 'ACTION_HOMOLO_15': '<S1>:4237' */
        /* Entry 'ACTION_HOMOLO_05': '<S1>:4239' */
        ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_05;
        ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_05;

        /* on descend l'ascenseur pour emprisonner spot + balle */
        /* Graphical Function 'setPWM': '<S1>:4112' */
        /* Transition: '<S1>:4114' */
        ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p15 - 1.0)]
          = -60.0;

        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p37 - 1.0)]
          = ModeleRobot_P.SFunction_p38;

        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p31 - 1.0)]
          = ModeleRobot_P.SFunction_p32;

        /* tempo */
        ModeleRobot_DWork.TempoMot = 0.0;
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_16:
      /* During 'ACTION_HOMOLO_16': '<S1>:4243' */
      if (ModeleRobot_DWork.TempoMot > 0.5 / ModeleRobot_P.SFunction_p49) {
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

     case ModeleRobot_IN_ACTION_HOMOLO_2:
      /* During 'ACTION_HOMOLO_2': '<S1>:4167' */
      /* Graphical Function 'isFinMouvement': '<S1>:1282' */
      /* Transition: '<S1>:1285' */
      ModeleRobot_DWork.CompteurTimeoutMvt =
        ModeleRobot_DWork.CompteurTimeoutMvt + 1.0;

      /* Transition: '<S1>:1286' */
      /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
      if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 /
            ModeleRobot_P.SFunction_p49) || (ModeleRobot_B.DataTypeConversion !=
            0.0)) != 0) {
        /* Transition: '<S1>:4170' */
        /* Exit 'ACTION_HOMOLO_2': '<S1>:4167' */
        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p37 - 1.0)]
          = ModeleRobot_P.SFunction_p41;

        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p31 - 1.0)]
          = ModeleRobot_P.SFunction_p35;

        /* Entry 'ACTION_HOMOLO_4': '<S1>:4169' */
        ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_4;
        ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_4;

        /* on recule pour laisser les spots */
        /* Graphical Function 'Mouvement_XY': '<S1>:1289' */
        /* Transition: '<S1>:1291' */
        ModeleRobot_B.DdeMvtXY = ModeleRobot_B.DdeMvtXY + 1.0;
        ModeleRobot_B.ConsigneX = 67.0;
        ModeleRobot_B.ConsigneY = -45.0 * ModeleRobot_DWork.invMouv;
        ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_24:
      /* During 'ACTION_HOMOLO_24': '<S1>:4279' */
      /* Graphical Function 'isFinMouvement': '<S1>:1282' */
      /* Transition: '<S1>:1285' */
      ModeleRobot_DWork.CompteurTimeoutMvt =
        ModeleRobot_DWork.CompteurTimeoutMvt + 1.0;

      /* Transition: '<S1>:1286' */
      /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
      if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 /
            ModeleRobot_P.SFunction_p49) || (ModeleRobot_B.DataTypeConversion !=
            0.0)) != 0) {
        /* Transition: '<S1>:4327' */
        if (ModeleRobot_DWork.CouleurEquipe_memo == ModeleRobot_P.SFunction_p5)
        {
          /* Transition: '<S1>:4335' */
          /* Exit 'ACTION_HOMOLO_24': '<S1>:4279' */
          /* Entry 'ACTION_HOMOLO_55': '<S1>:4498' */
          ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_55;
          ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_55;

          /* Graphical Function 'setServo': '<S1>:4141' */
          /* Transition: '<S1>:4143' */
          ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 -
            1.0)] = ModeleRobot_P.SFunction_p26;
          ModeleRobot_DWork.TempoMot = 0.0;
        } else {
          /* Transition: '<S1>:4336' */
          /* Exit 'ACTION_HOMOLO_24': '<S1>:4279' */
          /* Entry 'ACTION_HOMOLO_56': '<S1>:4500' */
          ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_56;
          ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_56;

          /* Graphical Function 'setServoRelache': '<S1>:4198' */
          /* Transition: '<S1>:4200' */
          ModeleRobot_B.RelacheServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)]
            = 0.0;

          /* Graphical Function 'setServo': '<S1>:4141' */
          /* Transition: '<S1>:4143' */
          ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 -
            1.0)] = ModeleRobot_P.SFunction_p30;
          ModeleRobot_DWork.TempoMot = 0.0;
        }
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_25:
      /* During 'ACTION_HOMOLO_25': '<S1>:4281' */
      if (ModeleRobot_DWork.TempoMot > 1.0 / ModeleRobot_P.SFunction_p49) {
        /* Transition: '<S1>:4313' */
        /* Exit 'ACTION_HOMOLO_25': '<S1>:4281' */
        /* Entry 'ACTION_HOMOLO_34': '<S1>:4311' */
        ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_34;
        ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_34;

        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p23 - 1.0)]
          = ModeleRobot_P.SFunction_p25;
        ModeleRobot_DWork.TempoMot = 0.0;
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_30:
      /* During 'ACTION_HOMOLO_30': '<S1>:4296' */
      if (ModeleRobot_DWork.TempoMot > 0.5 / ModeleRobot_P.SFunction_p49) {
        /* Transition: '<S1>:4349' */
        if (ModeleRobot_DWork.CouleurEquipe_memo == ModeleRobot_P.SFunction_p5)
        {
          /* Transition: '<S1>:4474' */
          /* Exit 'ACTION_HOMOLO_30': '<S1>:4296' */
          /* Entry 'ACTION_HOMOLO_44': '<S1>:4348' */
          ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_44;
          ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_44;

          /* on avance parallelement a la bordure et on ferme les claps */
          /* Graphical Function 'Mouvement_XY': '<S1>:1289' */
          /* Transition: '<S1>:1291' */
          ModeleRobot_B.DdeMvtXY = ModeleRobot_B.DdeMvtXY + 1.0;
          ModeleRobot_B.ConsigneX = 14.5;
          ModeleRobot_B.ConsigneY = -77.0 * ModeleRobot_DWork.invMouv;
          ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
        } else {
          /* Transition: '<S1>:4475' */
          /* Exit 'ACTION_HOMOLO_30': '<S1>:4296' */
          /* Entry 'ACTION_HOMOLO_50': '<S1>:4471' */
          ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_50;
          ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_50;

          /* on avance parallelement a la bordure et on ferme les claps */
          /* Graphical Function 'Mouvement_XY': '<S1>:1289' */
          /* Transition: '<S1>:1291' */
          ModeleRobot_B.DdeMvtXY = ModeleRobot_B.DdeMvtXY + 1.0;
          ModeleRobot_B.ConsigneX = 19.0;
          ModeleRobot_B.ConsigneY = -77.0 * ModeleRobot_DWork.invMouv;
          ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
        }
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_33:
      /* During 'ACTION_HOMOLO_33': '<S1>:4309' */
      if (ModeleRobot_DWork.TempoMot > 1.0 / ModeleRobot_P.SFunction_p49) {
        /* Transition: '<S1>:4318' */
        /* Exit 'ACTION_HOMOLO_33': '<S1>:4309' */
        /* Entry 'ACTION_HOMOLO_36': '<S1>:4316' */
        ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_36;
        ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_36;

        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p27 - 1.0)]
          = ModeleRobot_P.SFunction_p29;
        ModeleRobot_DWork.TempoMot = 0.0;
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_34:
      /* During 'ACTION_HOMOLO_34': '<S1>:4311' */
      if (ModeleRobot_DWork.TempoMot > 1.0 / ModeleRobot_P.SFunction_p49) {
        /* Transition: '<S1>:4312' */
        /* Exit 'ACTION_HOMOLO_34': '<S1>:4311' */
        /* Entry 'ACTION_HOMOLO_35': '<S1>:4314' */
        ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_35;
        ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_35;

        /* on se positionne face au gobelet */
        /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
        /* Transition: '<S1>:3697' */
        ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
        ModeleRobot_B.ConsigneX = 41.0;
        ModeleRobot_B.ConsigneY = -77.0 * ModeleRobot_DWork.invMouv;
        ModeleRobot_B.ConsigneTeta = 3.14;
        ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_35:
      /* During 'ACTION_HOMOLO_35': '<S1>:4314' */
      /* Graphical Function 'isFinMouvement': '<S1>:1282' */
      /* Transition: '<S1>:1285' */
      ModeleRobot_DWork.CompteurTimeoutMvt =
        ModeleRobot_DWork.CompteurTimeoutMvt + 1.0;

      /* Transition: '<S1>:1286' */
      /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
      if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 /
            ModeleRobot_P.SFunction_p49) || (ModeleRobot_B.DataTypeConversion !=
            0.0)) != 0) {
        /* Transition: '<S1>:4315' */
        /* Exit 'ACTION_HOMOLO_35': '<S1>:4314' */
        /* Entry 'ACTION_HOMOLO_24': '<S1>:4279' */
        ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_24;
        ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_24;

        /* on avance vers le gobelet */
        /* Graphical Function 'Mouvement_XY': '<S1>:1289' */
        /* Transition: '<S1>:1291' */
        ModeleRobot_B.DdeMvtXY = ModeleRobot_B.DdeMvtXY + 1.0;
        ModeleRobot_B.ConsigneX = 22.0;
        ModeleRobot_B.ConsigneY = -77.0 * ModeleRobot_DWork.invMouv;
        ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_36:
      /* During 'ACTION_HOMOLO_36': '<S1>:4316' */
      if (ModeleRobot_DWork.TempoMot > 1.0 / ModeleRobot_P.SFunction_p49) {
        /* Transition: '<S1>:4317' */
        /* Exit 'ACTION_HOMOLO_36': '<S1>:4316' */
        /* Entry 'ACTION_HOMOLO_35': '<S1>:4314' */
        ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_35;
        ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_35;

        /* on se positionne face au gobelet */
        /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
        /* Transition: '<S1>:3697' */
        ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
        ModeleRobot_B.ConsigneX = 41.0;
        ModeleRobot_B.ConsigneY = -77.0 * ModeleRobot_DWork.invMouv;
        ModeleRobot_B.ConsigneTeta = 3.14;
        ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_4:
      /* During 'ACTION_HOMOLO_4': '<S1>:4169' */
      /* Graphical Function 'isFinMouvement': '<S1>:1282' */
      /* Transition: '<S1>:1285' */
      ModeleRobot_DWork.CompteurTimeoutMvt =
        ModeleRobot_DWork.CompteurTimeoutMvt + 1.0;

      /* Transition: '<S1>:1286' */
      /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
      if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 /
            ModeleRobot_P.SFunction_p49) || (ModeleRobot_B.DataTypeConversion !=
            0.0)) != 0) {
        /* Transition: '<S1>:4253' */
        /* Exit 'ACTION_HOMOLO_4': '<S1>:4169' */
        /* Entry 'ACTION_HOMOLO_09': '<S1>:4280' */
        ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_09;
        ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_09;

        /* on remonte les pinces */
        /* Graphical Function 'setPWM': '<S1>:4112' */
        /* Transition: '<S1>:4114' */
        ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p15 - 1.0)]
          = 60.0;

        /* tempo */
        ModeleRobot_DWork.TempoMot = 0.0;
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_40:
      /* During 'ACTION_HOMOLO_40': '<S1>:4338' */
      /* Graphical Function 'isFinMouvementRapide': '<S1>:3865' */
      /* Transition: '<S1>:3868' */
      ModeleRobot_DWork.CompteurTimeoutMvt =
        ModeleRobot_DWork.CompteurTimeoutMvt + 1.0;

      /* Transition: '<S1>:3869' */
      if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 /
            ModeleRobot_P.SFunction_p49) || (ModeleRobot_B.DataTypeConversion_g
            != 0.0)) != 0) {
        /* Transition: '<S1>:4341' */
        /* Exit 'ACTION_HOMOLO_40': '<S1>:4338' */
        /* Entry 'ACTION_HOMOLO_41': '<S1>:4339' */
        ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_41;
        ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_41;

        /* BO pour pousser les spots */
        /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
        /* Transition: '<S1>:1301' */
        ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
        ModeleRobot_B.CommandeManuelleG = -25.0;
        ModeleRobot_B.CommandeManuelleD = -25.0;
        ModeleRobot_DWork.TempoMot = 0.0;
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_41:
      /* During 'ACTION_HOMOLO_41': '<S1>:4339' */
      /* Transition: '<S1>:4344' */
      if (ModeleRobot_DWork.TempoMot > 2.0 / ModeleRobot_P.SFunction_p49) {
        /* Transition: '<S1>:4347' */
        /* Exit 'ACTION_HOMOLO_41': '<S1>:4339' */
        /* Entry 'ACTION_HOMOLO_30': '<S1>:4296' */
        ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_30;
        ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_30;

        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p20 - 1.0)]
          = ModeleRobot_P.SFunction_p22;
        ModeleRobot_DWork.TempoMot = 0.0;
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_43:
      /* During 'ACTION_HOMOLO_43': '<S1>:4343' */
      /* Transition: '<S1>:4345' */
      if (ModeleRobot_DWork.TempoMot > 2.0 / ModeleRobot_P.SFunction_p49) {
        /* Transition: '<S1>:4347' */
        /* Exit 'ACTION_HOMOLO_43': '<S1>:4343' */
        /* Entry 'ACTION_HOMOLO_30': '<S1>:4296' */
        ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_30;
        ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_30;

        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p20 - 1.0)]
          = ModeleRobot_P.SFunction_p22;
        ModeleRobot_DWork.TempoMot = 0.0;
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_44:
      /* During 'ACTION_HOMOLO_44': '<S1>:4348' */
      /* Graphical Function 'isFinMouvementRapide': '<S1>:3865' */
      /* Transition: '<S1>:3868' */
      ModeleRobot_DWork.CompteurTimeoutMvt =
        ModeleRobot_DWork.CompteurTimeoutMvt + 1.0;

      /* Transition: '<S1>:3869' */
      if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 /
            ModeleRobot_P.SFunction_p49) || (ModeleRobot_B.DataTypeConversion_g
            != 0.0)) != 0) {
        /* Transition: '<S1>:4351' */
        /* Exit 'ACTION_HOMOLO_44': '<S1>:4348' */
        /* Entry 'ACTION_HOMOLO_45': '<S1>:4350' */
        ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_45;
        ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_45;

        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p20 - 1.0)]
          = ModeleRobot_P.SFunction_p21;
        ModeleRobot_DWork.TempoMot = 0.0;
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_45:
      /* During 'ACTION_HOMOLO_45': '<S1>:4350' */
      if (ModeleRobot_DWork.TempoMot > 0.5 / ModeleRobot_P.SFunction_p49) {
        /* Transition: '<S1>:4298' */
        /* Exit 'ACTION_HOMOLO_45': '<S1>:4350' */
        /* Entry 'ACTION_HOMOLO_47': '<S1>:4409' */
        ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_47;
        ModeleRobot_DWork.was_DEMO = (uint8_T)ModeleRobot_IN_ACTION_HOMOLO_47;

        /* on avance parallelement a la bordure et on ferme les claps */
        /* Graphical Function 'Mouvement_XY': '<S1>:1289' */
        /* Transition: '<S1>:1291' */
        ModeleRobot_B.DdeMvtXY = ModeleRobot_B.DdeMvtXY + 1.0;
        ModeleRobot_B.ConsigneX = 56.0;
        ModeleRobot_B.ConsigneY = -77.0 * ModeleRobot_DWork.invMouv;
        ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
      }
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_46:
      ModeleRobot_ACTION_HOMOLO_46();
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_47:
      ModeleRobot_ACTION_HOMOLO_47();
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_48:
      ModeleRobot_ACTION_HOMOLO_48();
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_49:
      ModeleRobot_ACTION_HOMOLO_49();
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_50:
      ModeleRobot_ACTION_HOMOLO_50();
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_51:
      ModeleRobot_ACTION_HOMOLO_51();
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_52:
      ModeleRobot_ACTION_HOMOLO_52();
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_53:
      ModeleRobot_ACTION_HOMOLO_53();
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_54:
      ModeleRobot_ACTION_HOMOLO_54();
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_55:
      ModeleRobot_ACTION_HOMOLO_55();
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_56:
      ModeleRobot_ACTION_HOMOLO_56();
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_57:
      ModeleRobot_ACTION_HOMOLO_57();
      break;

     case ModeleRobot_IN_ACTION_HOMOLO_58:
      ModeleRobot_ACTION_HOMOLO_58();
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
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void VERT_GOTO_DISTRIBUTEURS_ET_RECU(void)
{
  /* During 'VERT_GOTO_DISTRIBUTEURS_ET_RECUPERE': '<S1>:4423' */
  if (ModeleRobot_DWork.Etape_recuperationDistributeurs == 0.0) {
    /* Transition: '<S1>:4467' */
    /* Exit 'ACTION_DISTRIB_01': '<S1>:4437' */
    ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
      ModeleRobot_IN_NO_ACTIVE_CHILD;

    /* Exit 'ACTION_DISTRIB_010': '<S1>:4439' */
    /* Exit 'ACTION_DISTRIB_011': '<S1>:4445' */
    /* Exit 'ACTION_DISTRIB_02': '<S1>:4441' */
    /* Exit 'ACTION_DISTRIB_03': '<S1>:4442' */
    /* Exit 'ACTION_DISTRIB_04': '<S1>:4443' */
    /* Exit 'ACTION_DISTRIB_05': '<S1>:4444' */
    /* Exit 'ACTION_DISTRIB_06': '<S1>:4447' */
    /* Exit 'ACTION_DISTRIB_07': '<S1>:4448' */
    /* Exit 'ACTION_DISTRIB_08': '<S1>:4450' */
    /* Exit 'ACTION_DISTRIB_09': '<S1>:4438' */
    /* Exit 'VERT_GOTO_DISTRIBUTEURS_ET_RECUPERE': '<S1>:4423' */
    ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)ModeleRobot_IN_NO_ACTIVE_CHILD;
    enter_atomic_VERT_RETOUR_ZONE_D();
    enter_internal_VERT_RETOUR_ZONE();
  } else {
    ModeleRobot_DWork.TempoMot = ModeleRobot_DWork.TempoMot + 1.0;
    switch (ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R) {
     case ModeleRobo_IN_ACTION_DISTRIB_01:
      /* During 'ACTION_DISTRIB_01': '<S1>:4437' */
      /* Graphical Function 'isFinMouvementRapide': '<S1>:3865' */
      /* Transition: '<S1>:3868' */
      ModeleRobot_DWork.CompteurTimeoutMvt =
        ModeleRobot_DWork.CompteurTimeoutMvt + 1.0;

      /* Transition: '<S1>:3869' */
      if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 /
            ModeleRobot_P.SFunction_p49) || (ModeleRobot_B.DataTypeConversion_g
            != 0.0)) != 0) {
        /* Transition: '<S1>:4426' */
        /* Exit 'ACTION_DISTRIB_01': '<S1>:4437' */
        /* Entry 'ACTION_DISTRIB_09': '<S1>:4438' */
        ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
          ModeleRobo_IN_ACTION_DISTRIB_09;
        ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
          ModeleRobo_IN_ACTION_DISTRIB_09;

        /* va en marche arrière jusque devant le distributeur sans l'atteindre */
        /* Graphical Function 'Mouvement_Angle': '<S1>:1354' */
        /* Transition: '<S1>:1356' */
        ModeleRobot_B.DdeMvtDistanceAngle = ModeleRobot_B.DdeMvtDistanceAngle +
          1.0;
        ModeleRobot_B.ConsigneDistance = 0.0;
        ModeleRobot_B.ConsigneTeta = (-ModeleRobot_P.SFunction_p19) / 2.0 *
          ModeleRobot_DWork.invMouv;
        ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
        ModeleRobot_DWork.TempoMot = 0.0;
      }
      break;

     case ModeleRob_IN_ACTION_DISTRIB_010:
      /* During 'ACTION_DISTRIB_010': '<S1>:4439' */
      if (fabs(ModeleRobot_U.IN_y_pos) > 50.0) {
        /* Transition: '<S1>:4429' */
        /* Exit 'ACTION_DISTRIB_010': '<S1>:4439' */
        /* Entry 'ACTION_DISTRIB_02': '<S1>:4441' */
        ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
          ModeleRobo_IN_ACTION_DISTRIB_02;
        ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
          ModeleRobo_IN_ACTION_DISTRIB_02;
        ModeleRobot_DWork.inhibeObstacle = 1.0;
      }
      break;

     case ModeleRob_IN_ACTION_DISTRIB_011:
      /* During 'ACTION_DISTRIB_011': '<S1>:4445' */
      /* Graphical Function 'isFinMouvementRapide': '<S1>:3865' */
      /* Transition: '<S1>:3868' */
      ModeleRobot_DWork.CompteurTimeoutMvt =
        ModeleRobot_DWork.CompteurTimeoutMvt + 1.0;

      /* Transition: '<S1>:3869' */
      if (((ModeleRobot_DWork.CompteurTimeoutMvt > 2.0 /
            ModeleRobot_P.SFunction_p49) || (ModeleRobot_B.DataTypeConversion_g
            != 0.0)) != 0) {
        /* Transition: '<S1>:4434' */
        /* Exit 'ACTION_DISTRIB_011': '<S1>:4445' */
        /* Entry 'ACTION_DISTRIB_06': '<S1>:4447' */
        ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
          ModeleRobo_IN_ACTION_DISTRIB_06;
        ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
          ModeleRobo_IN_ACTION_DISTRIB_06;
        ModeleRobot_DWork.nbreDistributeursTraites =
          ModeleRobot_DWork.nbreDistributeursTraites + 1.0;
      }
      break;

     case ModeleRobo_IN_ACTION_DISTRIB_02:
      /* During 'ACTION_DISTRIB_02': '<S1>:4441' */
      /* Graphical Function 'isFinMouvement': '<S1>:1282' */
      /* Transition: '<S1>:1285' */
      ModeleRobot_DWork.CompteurTimeoutMvt =
        ModeleRobot_DWork.CompteurTimeoutMvt + 1.0;

      /* Transition: '<S1>:1286' */
      /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
      if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 /
            ModeleRobot_P.SFunction_p49) || (ModeleRobot_B.DataTypeConversion !=
            0.0)) != 0) {
        /* Transition: '<S1>:4430' */
        /* Exit 'ACTION_DISTRIB_02': '<S1>:4441' */
        /* Entry 'ACTION_DISTRIB_03': '<S1>:4442' */
        ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
          ModeleRobo_IN_ACTION_DISTRIB_03;
        ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
          ModeleRobo_IN_ACTION_DISTRIB_03;

        /*  termine en boucle ouverte pour venir buter contre la bordure */
        /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
        /* Transition: '<S1>:1301' */
        ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
        ModeleRobot_B.CommandeManuelleG = -25.0;
        ModeleRobot_B.CommandeManuelleD = -25.0;

        /*  le souffleur évacue les boules éventuellement derrière le robot qu pourraient gêner */
        /* Graphical Function 'setPWM': '<S1>:4112' */
        /* Transition: '<S1>:4114' */
        ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p18 - 1.0)]
          = -100.0;

        /*  sort le tobogan et lance la souflerie */
        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p43 - 1.0)]
          = ModeleRobot_P.SFunction_p45;
        ModeleRobot_DWork.TempoMot = 0.0;
      }
      break;

     case ModeleRobo_IN_ACTION_DISTRIB_03:
      /* During 'ACTION_DISTRIB_03': '<S1>:4442' */
      if (ModeleRobot_DWork.TempoMot > 2.0 / ModeleRobot_P.SFunction_p49) {
        /* Transition: '<S1>:4431' */
        /* Exit 'ACTION_DISTRIB_03': '<S1>:4442' */
        /* Entry 'ACTION_DISTRIB_04': '<S1>:4443' */
        ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
          ModeleRobo_IN_ACTION_DISTRIB_04;
        ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
          ModeleRobo_IN_ACTION_DISTRIB_04;

        /*  arrête de buter contre la bordure */
        /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
        /* Transition: '<S1>:1301' */
        ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
        ModeleRobot_B.CommandeManuelleG = 0.0;
        ModeleRobot_B.CommandeManuelleD = 0.0;

        /*  ATTENTION : recalage de la position du robot
           setPosition(36,77.5*invMouv, (-PI/2)*invMouv); */
        /* Graphical Function 'setPWM': '<S1>:4112' */
        /* Transition: '<S1>:4114' */
        ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p16 - 1.0)]
          = 100.0;

        /*  arrête le souffleur du bas */
        /* Graphical Function 'setPWM': '<S1>:4112' */
        /* Transition: '<S1>:4114' */
        ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p18 - 1.0)]
          = 0.0;
        ModeleRobot_DWork.TempoMot = 0.0;
      }
      break;

     case ModeleRobo_IN_ACTION_DISTRIB_04:
      /* During 'ACTION_DISTRIB_04': '<S1>:4443' */
      if (ModeleRobot_DWork.TempoMot > 3.0 / ModeleRobot_P.SFunction_p49) {
        /* Transition: '<S1>:4432' */
        /* Exit 'ACTION_DISTRIB_04': '<S1>:4443' */
        /* Entry 'ACTION_DISTRIB_05': '<S1>:4444' */
        ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
          ModeleRobo_IN_ACTION_DISTRIB_05;
        ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
          ModeleRobo_IN_ACTION_DISTRIB_05;

        /*  Arrête la souflerie pour laisser les balles tomber (et attend un peu) */
        /* Graphical Function 'setPWM': '<S1>:4112' */
        /* Transition: '<S1>:4114' */
        ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p16 - 1.0)]
          = 0.0;
        ModeleRobot_DWork.TempoMot = 0.0;
      }
      break;

     case ModeleRobo_IN_ACTION_DISTRIB_05:
      /* During 'ACTION_DISTRIB_05': '<S1>:4444' */
      if (ModeleRobot_DWork.TempoMot > 1.0 / ModeleRobot_P.SFunction_p49) {
        /* Transition: '<S1>:4433' */
        /* Exit 'ACTION_DISTRIB_05': '<S1>:4444' */
        /* Entry 'ACTION_DISTRIB_011': '<S1>:4445' */
        ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
          ModeleRob_IN_ACTION_DISTRIB_011;
        ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
          ModeleRob_IN_ACTION_DISTRIB_011;

        /*  s'éloinge de la bordure */
        ModeleRobot_DWork.inhibeObstacle = 0.0;

        /* Graphical Function 'Mouvement_XY': '<S1>:1289' */
        /* Transition: '<S1>:1291' */
        ModeleRobot_B.DdeMvtXY = ModeleRobot_B.DdeMvtXY + 1.0;
        ModeleRobot_B.ConsigneX = ModeleRobot_DWork.positionDistributeur_X;
        ModeleRobot_B.ConsigneY = 63.0 * ModeleRobot_DWork.invMouv;
        ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;

        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p43 - 1.0)]
          = ModeleRobot_P.SFunction_p44;

        /*  petite pichnette sur le servo pour éviter de racler contre le distributeur */
      }
      break;

     case ModeleRobo_IN_ACTION_DISTRIB_06:
      /* During 'ACTION_DISTRIB_06': '<S1>:4447' */
      if (ModeleRobot_DWork.nbreDistributeursTraites >= 2.0) {
        /* Transition: '<S1>:4435' */
        /* Exit 'ACTION_DISTRIB_06': '<S1>:4447' */
        /* Entry 'ACTION_DISTRIB_07': '<S1>:4448' */
        ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
          ModeleRobo_IN_ACTION_DISTRIB_07;
        ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
          ModeleRobo_IN_ACTION_DISTRIB_07;

        /*  Ferme le servo du recolteur une fois tout terminé */
        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p43 - 1.0)]
          = ModeleRobot_P.SFunction_p44;

        /*  retourne à la position de référence */
        ModeleRobot_DWork.inhibeObstacle = 1.0;

        /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
        /* Transition: '<S1>:3697' */
        ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
        ModeleRobot_B.ConsigneX = 75.0;
        ModeleRobot_B.ConsigneY = 0.0;
        ModeleRobot_B.ConsigneTeta = 0.0;
        ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
      } else {
        /* Transition: '<S1>:4427' */
        /* Exit 'ACTION_DISTRIB_06': '<S1>:4447' */
        ModeleRobot_DWork.positionDistributeur_X =
          ModeleRobot_DWork.positionDistributeur_X - 30.0;

        /* Entry 'ACTION_DISTRIB_09': '<S1>:4438' */
        ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
          ModeleRobo_IN_ACTION_DISTRIB_09;
        ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
          ModeleRobo_IN_ACTION_DISTRIB_09;

        /* va en marche arrière jusque devant le distributeur sans l'atteindre */
        /* Graphical Function 'Mouvement_Angle': '<S1>:1354' */
        /* Transition: '<S1>:1356' */
        ModeleRobot_B.DdeMvtDistanceAngle = ModeleRobot_B.DdeMvtDistanceAngle +
          1.0;
        ModeleRobot_B.ConsigneDistance = 0.0;
        ModeleRobot_B.ConsigneTeta = (-ModeleRobot_P.SFunction_p19) / 2.0 *
          ModeleRobot_DWork.invMouv;
        ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
        ModeleRobot_DWork.TempoMot = 0.0;
      }
      break;

     case ModeleRobo_IN_ACTION_DISTRIB_07:
      /* During 'ACTION_DISTRIB_07': '<S1>:4448' */
      /* Graphical Function 'isFinMouvement': '<S1>:1282' */
      /* Transition: '<S1>:1285' */
      ModeleRobot_DWork.CompteurTimeoutMvt =
        ModeleRobot_DWork.CompteurTimeoutMvt + 1.0;

      /* Transition: '<S1>:1286' */
      /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
      if (((ModeleRobot_DWork.CompteurTimeoutMvt > 4.0 /
            ModeleRobot_P.SFunction_p49) || (ModeleRobot_B.DataTypeConversion !=
            0.0)) != 0) {
        /* Transition: '<S1>:4436' */
        /* Exit 'ACTION_DISTRIB_07': '<S1>:4448' */
        /* Entry 'ACTION_DISTRIB_08': '<S1>:4450' */
        ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
          ModeleRobo_IN_ACTION_DISTRIB_08;
        ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
          ModeleRobo_IN_ACTION_DISTRIB_08;

        /* Fin d'étape */
        ModeleRobot_DWork.Etape_recuperationDistributeurs = 0.0;
      }
      break;

     case ModeleRobo_IN_ACTION_DISTRIB_08:
      break;

     case ModeleRobo_IN_ACTION_DISTRIB_09:
      /* During 'ACTION_DISTRIB_09': '<S1>:4438' */
      /* Graphical Function 'isFinMouvement': '<S1>:1282' */
      /* Transition: '<S1>:1285' */
      ModeleRobot_DWork.CompteurTimeoutMvt =
        ModeleRobot_DWork.CompteurTimeoutMvt + 1.0;

      /* Transition: '<S1>:1286' */
      /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
      if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 /
            ModeleRobot_P.SFunction_p49) || (ModeleRobot_B.DataTypeConversion !=
            0.0)) != 0) {
        /* Transition: '<S1>:4428' */
        /* Exit 'ACTION_DISTRIB_09': '<S1>:4438' */
        /* Entry 'ACTION_DISTRIB_010': '<S1>:4439' */
        ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
          ModeleRob_IN_ACTION_DISTRIB_010;
        ModeleRobot_DWork.was_VERT_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
          ModeleRob_IN_ACTION_DISTRIB_010;

        /* va en marche arrière jusque devant le distributeur sans l'atteindre */
        /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
        /* Transition: '<S1>:3697' */
        ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
        ModeleRobot_B.ConsigneX = ModeleRobot_DWork.positionDistributeur_X;
        ModeleRobot_B.ConsigneY = 70.0 * ModeleRobot_DWork.invMouv;
        ModeleRobot_B.ConsigneTeta = (-ModeleRobot_P.SFunction_p19) / 2.0 *
          ModeleRobot_DWork.invMouv;
        ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
        ModeleRobot_DWork.TempoMot = 0.0;
      }
      break;

     default:
      enter_internal_VERT_GOTO_DISTRI();
      break;
    }
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_STRATEGIE1(void)
{
  /* During 'STRATEGIE1': '<S1>:1123' */
  if ((ModeleRobot_Y.OUT_isObstacle == 1) && (ModeleRobot_DWork.inhibeObstacle ==
       0.0)) {
    /* Transition: '<S1>:3821' */
    if (ModeleRobot_DWork.is_STRATEGIE1 == ModeleRobot_IN_DEMO) {
      if (ModeleRobot_DWork.is_DEMO == ModeleRobot_IN_ACTION_HOMOLO_2) {
        /* Exit 'ACTION_HOMOLO_2': '<S1>:4167' */
        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p37 - 1.0)]
          = ModeleRobot_P.SFunction_p41;

        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p31 - 1.0)]
          = ModeleRobot_P.SFunction_p35;
        ModeleRobot_DWork.is_DEMO = (uint8_T)ModeleRobot_IN_NO_ACTIVE_CHILD;
      } else {
        /* Exit 'ACTION_18': '<S1>:4139' */
        /* Exit 'ACTION_HOMOLO_0': '<S1>:4165' */
        /* Exit 'ACTION_HOMOLO_01': '<S1>:4181' */
        /* Exit 'ACTION_HOMOLO_02': '<S1>:4183' */
        /* Exit 'ACTION_HOMOLO_03': '<S1>:4220' */
        /* Exit 'ACTION_HOMOLO_05': '<S1>:4239' */
        /* Exit 'ACTION_HOMOLO_09': '<S1>:4280' */
        /* Exit 'ACTION_HOMOLO_10': '<S1>:4204' */
        /* Exit 'ACTION_HOMOLO_11': '<S1>:4207' */
        /* Exit 'ACTION_HOMOLO_12': '<S1>:4210' */
        /* Exit 'ACTION_HOMOLO_13': '<S1>:4213' */
        /* Exit 'ACTION_HOMOLO_14': '<S1>:4215' */
        /* Exit 'ACTION_HOMOLO_15': '<S1>:4237' */
        /* Exit 'ACTION_HOMOLO_16': '<S1>:4243' */
        /* Exit 'ACTION_HOMOLO_24': '<S1>:4279' */
        /* Exit 'ACTION_HOMOLO_25': '<S1>:4281' */
        /* Exit 'ACTION_HOMOLO_30': '<S1>:4296' */
        /* Exit 'ACTION_HOMOLO_33': '<S1>:4309' */
        /* Exit 'ACTION_HOMOLO_34': '<S1>:4311' */
        /* Exit 'ACTION_HOMOLO_35': '<S1>:4314' */
        /* Exit 'ACTION_HOMOLO_36': '<S1>:4316' */
        /* Exit 'ACTION_HOMOLO_4': '<S1>:4169' */
        /* Exit 'ACTION_HOMOLO_40': '<S1>:4338' */
        /* Exit 'ACTION_HOMOLO_41': '<S1>:4339' */
        /* Exit 'ACTION_HOMOLO_43': '<S1>:4343' */
        /* Exit 'ACTION_HOMOLO_44': '<S1>:4348' */
        /* Exit 'ACTION_HOMOLO_45': '<S1>:4350' */
        /* Exit 'ACTION_HOMOLO_46': '<S1>:4395' */
        /* Exit 'ACTION_HOMOLO_47': '<S1>:4409' */
        /* Exit 'ACTION_HOMOLO_48': '<S1>:4411' */
        /* Exit 'ACTION_HOMOLO_49': '<S1>:4413' */
        /* Exit 'ACTION_HOMOLO_50': '<S1>:4471' */
        /* Exit 'ACTION_HOMOLO_51': '<S1>:4477' */
        /* Exit 'ACTION_HOMOLO_52': '<S1>:4489' */
        /* Exit 'ACTION_HOMOLO_53': '<S1>:4490' */
        /* Exit 'ACTION_HOMOLO_54': '<S1>:4491' */
        /* Exit 'ACTION_HOMOLO_55': '<S1>:4498' */
        /* Exit 'ACTION_HOMOLO_56': '<S1>:4500' */
        /* Exit 'ACTION_HOMOLO_57': '<S1>:4502' */
        /* Exit 'ACTION_HOMOLO_58': '<S1>:4504' */
        /* Exit 'ACTION_HOMOLO_6': '<S1>:4187' */
        /* Exit 'ACTION_HOMOLO_7': '<S1>:4189' */
        /* Exit 'ACTION_HOMOLO_8': '<S1>:4192' */
        /* Exit 'ACTION_HOMOLO_9': '<S1>:4203' */
      }

      /* Exit 'DEMO': '<S1>:3463' */
      ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)ModeleRobot_IN_NO_ACTIVE_CHILD;
    } else {
      /* Exit 'INIT_STRATEGIE': '<S1>:1128' */
      /* Exit 'ACTION_DISTRIB_01': '<S1>:4365' */
      ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
        ModeleRobot_IN_NO_ACTIVE_CHILD;

      /* Exit 'ACTION_DISTRIB_010': '<S1>:4407' */
      /* Exit 'ACTION_DISTRIB_011': '<S1>:4415' */
      /* Exit 'ACTION_DISTRIB_02': '<S1>:4366' */
      /* Exit 'ACTION_DISTRIB_03': '<S1>:4368' */
      /* Exit 'ACTION_DISTRIB_04': '<S1>:4369' */
      /* Exit 'ACTION_DISTRIB_05': '<S1>:4370' */
      /* Exit 'ACTION_DISTRIB_06': '<S1>:4372' */
      /* Exit 'ACTION_DISTRIB_07': '<S1>:4373' */
      /* Exit 'ACTION_DISTRIB_08': '<S1>:4375' */
      /* Exit 'ACTION_DISTRIB_09': '<S1>:4405' */
      /* Exit 'JAUNE_GOTO_DISTRIBUTEURS_ET_RECUPERE': '<S1>:4353' */
      /* Exit 'ACTION_RETOUR_Z0_DECHARGE_01': '<S1>:4387' */
      ModeleRobot_DWork.is_JAUNE_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
        ModeleRobot_IN_NO_ACTIVE_CHILD;

      /* Exit 'ACTION_RETOUR_Z0_DECHARGE_02': '<S1>:4388' */
      /* Exit 'ACTION_RETOUR_Z0_DECHARGE_03': '<S1>:4392' */
      /* Exit 'ACTION_RETOUR_Z0_DECHARGE_04': '<S1>:4389' */
      /* Exit 'ACTION_RETOUR_Z0_DECHARGE_06': '<S1>:4390' */
      /* Exit 'ACTION_RETOUR_Z0_DECHARGE_07': '<S1>:4391' */
      /* Exit 'JAUNE_RETOUR_ZONE_DEPART_ET_DECHARGE': '<S1>:4377' */
      /* Exit 'ACTION_DISTRIB_01': '<S1>:4437' */
      ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
        ModeleRobot_IN_NO_ACTIVE_CHILD;

      /* Exit 'ACTION_DISTRIB_010': '<S1>:4439' */
      /* Exit 'ACTION_DISTRIB_011': '<S1>:4445' */
      /* Exit 'ACTION_DISTRIB_02': '<S1>:4441' */
      /* Exit 'ACTION_DISTRIB_03': '<S1>:4442' */
      /* Exit 'ACTION_DISTRIB_04': '<S1>:4443' */
      /* Exit 'ACTION_DISTRIB_05': '<S1>:4444' */
      /* Exit 'ACTION_DISTRIB_06': '<S1>:4447' */
      /* Exit 'ACTION_DISTRIB_07': '<S1>:4448' */
      /* Exit 'ACTION_DISTRIB_08': '<S1>:4450' */
      /* Exit 'ACTION_DISTRIB_09': '<S1>:4438' */
      /* Exit 'VERT_GOTO_DISTRIBUTEURS_ET_RECUPERE': '<S1>:4423' */
      /* Exit 'ACTION_RETOUR_Z0_DECHARGE_01': '<S1>:4461' */
      ModeleRobot_DWork.is_VERT_RETOUR_ZONE_DEPART_ET_D = (uint8_T)
        ModeleRobot_IN_NO_ACTIVE_CHILD;

      /* Exit 'ACTION_RETOUR_Z0_DECHARGE_02': '<S1>:4462' */
      /* Exit 'ACTION_RETOUR_Z0_DECHARGE_03': '<S1>:4466' */
      /* Exit 'ACTION_RETOUR_Z0_DECHARGE_04': '<S1>:4463' */
      /* Exit 'ACTION_RETOUR_Z0_DECHARGE_06': '<S1>:4464' */
      /* Exit 'ACTION_RETOUR_Z0_DECHARGE_07': '<S1>:4465' */
      /* Exit 'VERT_RETOUR_ZONE_DEPART_ET_DECHARGE': '<S1>:4451' */
    }

    /* Exit 'STRATEGIE1': '<S1>:1123' */
    /* Entry 'EVITEMENT': '<S1>:3814' */
    ModeleRobot_DWork.is_STRATEGIE = (uint8_T)ModeleRobot_IN_EVITEMENT;
    ModeleRobot_DWork.EvitementEnCours = 1.0;

    /* Dans le cas d'un mouvement distance on calcule la distance parcourue pour repartir
       avec une consigne adapte */
    /* Transition: '<S1>:3817' */
    /* Entry 'DETECT_OBSTACLE': '<S1>:3816' */
    ModeleRobot_DWork.is_EVITEMENT = (uint8_T)ModeleRobot_IN_DETECT_OBSTACLE;
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
      if (ModeleRobot_DWork.DureeMatch > 0.5 / ModeleRobot_P.SFunction_p49) {
        /* Transition: '<S1>:2244' */
        /* Exit 'INIT_STRATEGIE': '<S1>:1128' */
        ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)
          ModeleRobot_IN_NO_ACTIVE_CHILD;
        ModeleRobot_enter_atomic_DEMO();
        ModeleRobot_enter_internal_DEMO();
      }
      break;

     case IN_JAUNE_GOTO_DISTRIBUTEURS_ET_:
      /* During 'JAUNE_GOTO_DISTRIBUTEURS_ET_RECUPERE': '<S1>:4353' */
      if (ModeleRobot_DWork.Etape_recuperationDistributeurs == 0.0) {
        /* Transition: '<S1>:4376' */
        /* Exit 'ACTION_DISTRIB_01': '<S1>:4365' */
        ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
          ModeleRobot_IN_NO_ACTIVE_CHILD;

        /* Exit 'ACTION_DISTRIB_010': '<S1>:4407' */
        /* Exit 'ACTION_DISTRIB_011': '<S1>:4415' */
        /* Exit 'ACTION_DISTRIB_02': '<S1>:4366' */
        /* Exit 'ACTION_DISTRIB_03': '<S1>:4368' */
        /* Exit 'ACTION_DISTRIB_04': '<S1>:4369' */
        /* Exit 'ACTION_DISTRIB_05': '<S1>:4370' */
        /* Exit 'ACTION_DISTRIB_06': '<S1>:4372' */
        /* Exit 'ACTION_DISTRIB_07': '<S1>:4373' */
        /* Exit 'ACTION_DISTRIB_08': '<S1>:4375' */
        /* Exit 'ACTION_DISTRIB_09': '<S1>:4405' */
        /* Exit 'JAUNE_GOTO_DISTRIBUTEURS_ET_RECUPERE': '<S1>:4353' */
        ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)
          ModeleRobot_IN_NO_ACTIVE_CHILD;
        enter_atomic_JAUNE_RETOUR_ZONE_();
        enter_internal_JAUNE_RETOUR_ZON();
      } else {
        ModeleRobot_DWork.TempoMot = ModeleRobot_DWork.TempoMot + 1.0;
        switch (ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_) {
         case ModeleRobo_IN_ACTION_DISTRIB_01:
          /* During 'ACTION_DISTRIB_01': '<S1>:4365' */
          /* Graphical Function 'isFinMouvement': '<S1>:1282' */
          /* Transition: '<S1>:1285' */
          ModeleRobot_DWork.CompteurTimeoutMvt =
            ModeleRobot_DWork.CompteurTimeoutMvt + 1.0;

          /* Transition: '<S1>:1286' */
          /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
          if (((ModeleRobot_DWork.CompteurTimeoutMvt > 5.0 /
                ModeleRobot_P.SFunction_p49) ||
               (ModeleRobot_B.DataTypeConversion != 0.0)) != 0) {
            /* Transition: '<S1>:4357' */
            /* Exit 'ACTION_DISTRIB_01': '<S1>:4365' */
            /* Entry 'ACTION_DISTRIB_09': '<S1>:4405' */
            ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
              ModeleRobo_IN_ACTION_DISTRIB_09;
            ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET = (uint8_T)
              ModeleRobo_IN_ACTION_DISTRIB_09;

            /* va en marche arrière jusque devant le distributeur sans l'atteindre */
            /* Graphical Function 'Mouvement_Angle': '<S1>:1354' */
            /* Transition: '<S1>:1356' */
            ModeleRobot_B.DdeMvtDistanceAngle =
              ModeleRobot_B.DdeMvtDistanceAngle + 1.0;
            ModeleRobot_B.ConsigneDistance = 0.0;
            ModeleRobot_B.ConsigneTeta = (-ModeleRobot_P.SFunction_p19) / 2.0 *
              ModeleRobot_DWork.invMouv;
            ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
            ModeleRobot_DWork.TempoMot = 0.0;
          }
          break;

         case ModeleRob_IN_ACTION_DISTRIB_010:
          /* During 'ACTION_DISTRIB_010': '<S1>:4407' */
          if (fabs(ModeleRobot_U.IN_y_pos) > 50.0) {
            /* Transition: '<S1>:4408' */
            /* Exit 'ACTION_DISTRIB_010': '<S1>:4407' */
            /* Entry 'ACTION_DISTRIB_02': '<S1>:4366' */
            ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
              ModeleRobo_IN_ACTION_DISTRIB_02;
            ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET = (uint8_T)
              ModeleRobo_IN_ACTION_DISTRIB_02;
            ModeleRobot_DWork.inhibeObstacle = 1.0;
          }
          break;

         case ModeleRob_IN_ACTION_DISTRIB_011:
          /* During 'ACTION_DISTRIB_011': '<S1>:4415' */
          /* Graphical Function 'isFinMouvementRapide': '<S1>:3865' */
          /* Transition: '<S1>:3868' */
          ModeleRobot_DWork.CompteurTimeoutMvt =
            ModeleRobot_DWork.CompteurTimeoutMvt + 1.0;

          /* Transition: '<S1>:3869' */
          if (((ModeleRobot_DWork.CompteurTimeoutMvt > 2.0 /
                ModeleRobot_P.SFunction_p49) ||
               (ModeleRobot_B.DataTypeConversion_g != 0.0)) != 0) {
            /* Transition: '<S1>:4416' */
            /* Exit 'ACTION_DISTRIB_011': '<S1>:4415' */
            /* Entry 'ACTION_DISTRIB_06': '<S1>:4372' */
            ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
              ModeleRobo_IN_ACTION_DISTRIB_06;
            ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET = (uint8_T)
              ModeleRobo_IN_ACTION_DISTRIB_06;
            ModeleRobot_DWork.nbreDistributeursTraites =
              ModeleRobot_DWork.nbreDistributeursTraites + 1.0;
          }
          break;

         case ModeleRobo_IN_ACTION_DISTRIB_02:
          /* During 'ACTION_DISTRIB_02': '<S1>:4366' */
          /* Graphical Function 'isFinMouvement': '<S1>:1282' */
          /* Transition: '<S1>:1285' */
          ModeleRobot_DWork.CompteurTimeoutMvt =
            ModeleRobot_DWork.CompteurTimeoutMvt + 1.0;

          /* Transition: '<S1>:1286' */
          /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
          if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 /
                ModeleRobot_P.SFunction_p49) ||
               (ModeleRobot_B.DataTypeConversion != 0.0)) != 0) {
            /* Transition: '<S1>:4359' */
            /* Exit 'ACTION_DISTRIB_02': '<S1>:4366' */
            /* Entry 'ACTION_DISTRIB_03': '<S1>:4368' */
            ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
              ModeleRobo_IN_ACTION_DISTRIB_03;
            ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET = (uint8_T)
              ModeleRobo_IN_ACTION_DISTRIB_03;

            /*  termine en boucle ouverte pour venir buter contre la bordure */
            /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
            /* Transition: '<S1>:1301' */
            ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
            ModeleRobot_B.CommandeManuelleG = -25.0;
            ModeleRobot_B.CommandeManuelleD = -25.0;

            /*  le souffleur évacue les boules éventuellement derrière le robot qu pourraient gêner */
            /* Graphical Function 'setPWM': '<S1>:4112' */
            /* Transition: '<S1>:4114' */
            ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p18 -
              1.0)] = -100.0;

            /*  sort le tobogan et lance la souflerie */
            /* Graphical Function 'setServo': '<S1>:4141' */
            /* Transition: '<S1>:4143' */
            ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p43 -
              1.0)] = ModeleRobot_P.SFunction_p45;
            ModeleRobot_DWork.TempoMot = 0.0;
          }
          break;

         case ModeleRobo_IN_ACTION_DISTRIB_03:
          /* During 'ACTION_DISTRIB_03': '<S1>:4368' */
          if (ModeleRobot_DWork.TempoMot > 2.0 / ModeleRobot_P.SFunction_p49) {
            /* Transition: '<S1>:4360' */
            /* Exit 'ACTION_DISTRIB_03': '<S1>:4368' */
            /* Entry 'ACTION_DISTRIB_04': '<S1>:4369' */
            ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
              ModeleRobo_IN_ACTION_DISTRIB_04;
            ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET = (uint8_T)
              ModeleRobo_IN_ACTION_DISTRIB_04;

            /*  arrête de buter contre la bordure */
            /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
            /* Transition: '<S1>:1301' */
            ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
            ModeleRobot_B.CommandeManuelleG = 0.0;
            ModeleRobot_B.CommandeManuelleD = 0.0;

            /*  ATTENTION : recalage de la position du robot
               setPosition(36,77.5*invMouv, (-PI/2)*invMouv); */
            /* Graphical Function 'setPWM': '<S1>:4112' */
            /* Transition: '<S1>:4114' */
            ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p16 -
              1.0)] = 100.0;

            /*  arrête le souffleur du bas */
            /* Graphical Function 'setPWM': '<S1>:4112' */
            /* Transition: '<S1>:4114' */
            ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p18 -
              1.0)] = 0.0;
            ModeleRobot_DWork.TempoMot = 0.0;
          }
          break;

         case ModeleRobo_IN_ACTION_DISTRIB_04:
          /* During 'ACTION_DISTRIB_04': '<S1>:4369' */
          if (ModeleRobot_DWork.TempoMot > 3.0 / ModeleRobot_P.SFunction_p49) {
            /* Transition: '<S1>:4361' */
            /* Exit 'ACTION_DISTRIB_04': '<S1>:4369' */
            /* Entry 'ACTION_DISTRIB_05': '<S1>:4370' */
            ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
              ModeleRobo_IN_ACTION_DISTRIB_05;
            ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET = (uint8_T)
              ModeleRobo_IN_ACTION_DISTRIB_05;

            /*  Arrête la souflerie pour laisser les balles tomber (et attend un peu) */
            /* Graphical Function 'setPWM': '<S1>:4112' */
            /* Transition: '<S1>:4114' */
            ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p16 -
              1.0)] = 0.0;
            ModeleRobot_DWork.TempoMot = 0.0;
          }
          break;

         case ModeleRobo_IN_ACTION_DISTRIB_05:
          /* During 'ACTION_DISTRIB_05': '<S1>:4370' */
          if (ModeleRobot_DWork.TempoMot > 1.0 / ModeleRobot_P.SFunction_p49) {
            /* Transition: '<S1>:4362' */
            /* Exit 'ACTION_DISTRIB_05': '<S1>:4370' */
            /* Entry 'ACTION_DISTRIB_011': '<S1>:4415' */
            ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
              ModeleRob_IN_ACTION_DISTRIB_011;
            ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET = (uint8_T)
              ModeleRob_IN_ACTION_DISTRIB_011;

            /*  s'éloinge de la bordure */
            ModeleRobot_DWork.inhibeObstacle = 0.0;

            /* Graphical Function 'Mouvement_Distance': '<S1>:1347' */
            /* Transition: '<S1>:1349' */
            ModeleRobot_B.DdeMvtDistanceAngle =
              ModeleRobot_B.DdeMvtDistanceAngle + 1.0;
            ModeleRobot_B.ConsigneDistance = 15.0;

            /*  ConsigneTeta reste inchangé. */
            ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
          }
          break;

         case ModeleRobo_IN_ACTION_DISTRIB_06:
          /* During 'ACTION_DISTRIB_06': '<S1>:4372' */
          if (ModeleRobot_DWork.nbreDistributeursTraites >= 2.0) {
            /* Transition: '<S1>:4363' */
            /* Exit 'ACTION_DISTRIB_06': '<S1>:4372' */
            /* Entry 'ACTION_DISTRIB_07': '<S1>:4373' */
            ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
              ModeleRobo_IN_ACTION_DISTRIB_07;
            ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET = (uint8_T)
              ModeleRobo_IN_ACTION_DISTRIB_07;

            /*  Ferme le servo du recolteur une fois tout terminé */
            /* Graphical Function 'setServo': '<S1>:4141' */
            /* Transition: '<S1>:4143' */
            ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p43 -
              1.0)] = ModeleRobot_P.SFunction_p44;

            /*  retourne à la position de référence */
            ModeleRobot_DWork.inhibeObstacle = 1.0;

            /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
            /* Transition: '<S1>:3697' */
            ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
            ModeleRobot_B.ConsigneX = ModeleRobot_DWork.posXReferenceEntreEtapes
              + 20.0;
            ModeleRobot_B.ConsigneY = 0.0;
            ModeleRobot_B.ConsigneTeta = 0.0;
            ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
          } else {
            /* Transition: '<S1>:4356' */
            /* Exit 'ACTION_DISTRIB_06': '<S1>:4372' */
            ModeleRobot_DWork.positionDistributeur_X = 1.0;

            /* Entry 'ACTION_DISTRIB_09': '<S1>:4405' */
            ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
              ModeleRobo_IN_ACTION_DISTRIB_09;
            ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET = (uint8_T)
              ModeleRobo_IN_ACTION_DISTRIB_09;

            /* va en marche arrière jusque devant le distributeur sans l'atteindre */
            /* Graphical Function 'Mouvement_Angle': '<S1>:1354' */
            /* Transition: '<S1>:1356' */
            ModeleRobot_B.DdeMvtDistanceAngle =
              ModeleRobot_B.DdeMvtDistanceAngle + 1.0;
            ModeleRobot_B.ConsigneDistance = 0.0;
            ModeleRobot_B.ConsigneTeta = (-ModeleRobot_P.SFunction_p19) / 2.0 *
              ModeleRobot_DWork.invMouv;
            ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
            ModeleRobot_DWork.TempoMot = 0.0;
          }
          break;

         case ModeleRobo_IN_ACTION_DISTRIB_07:
          /* During 'ACTION_DISTRIB_07': '<S1>:4373' */
          /* Graphical Function 'isFinMouvement': '<S1>:1282' */
          /* Transition: '<S1>:1285' */
          ModeleRobot_DWork.CompteurTimeoutMvt =
            ModeleRobot_DWork.CompteurTimeoutMvt + 1.0;

          /* Transition: '<S1>:1286' */
          /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
          if (((ModeleRobot_DWork.CompteurTimeoutMvt > 4.0 /
                ModeleRobot_P.SFunction_p49) ||
               (ModeleRobot_B.DataTypeConversion != 0.0)) != 0) {
            /* Transition: '<S1>:4364' */
            /* Exit 'ACTION_DISTRIB_07': '<S1>:4373' */
            /* Entry 'ACTION_DISTRIB_08': '<S1>:4375' */
            ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
              ModeleRobo_IN_ACTION_DISTRIB_08;
            ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET = (uint8_T)
              ModeleRobo_IN_ACTION_DISTRIB_08;

            /* Fin d'étape */
            ModeleRobot_DWork.Etape_recuperationDistributeurs = 0.0;
          }
          break;

         case ModeleRobo_IN_ACTION_DISTRIB_08:
          break;

         case ModeleRobo_IN_ACTION_DISTRIB_09:
          /* During 'ACTION_DISTRIB_09': '<S1>:4405' */
          /* Graphical Function 'isFinMouvement': '<S1>:1282' */
          /* Transition: '<S1>:1285' */
          ModeleRobot_DWork.CompteurTimeoutMvt =
            ModeleRobot_DWork.CompteurTimeoutMvt + 1.0;

          /* Transition: '<S1>:1286' */
          /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
          if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 /
                ModeleRobot_P.SFunction_p49) ||
               (ModeleRobot_B.DataTypeConversion != 0.0)) != 0) {
            /* Transition: '<S1>:4406' */
            /* Exit 'ACTION_DISTRIB_09': '<S1>:4405' */
            /* Entry 'ACTION_DISTRIB_010': '<S1>:4407' */
            ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
              ModeleRob_IN_ACTION_DISTRIB_010;
            ModeleRobot_DWork.was_JAUNE_GOTO_DISTRIBUTEURS_ET = (uint8_T)
              ModeleRob_IN_ACTION_DISTRIB_010;

            /* va en marche arrière jusque devant le distributeur sans l'atteindre */
            /* Graphical Function 'Mouvement_XYTeta': '<S1>:3695' */
            /* Transition: '<S1>:3697' */
            ModeleRobot_B.DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta + 1.0;
            ModeleRobot_B.ConsigneX = ModeleRobot_DWork.positionDistributeur_X;
            ModeleRobot_B.ConsigneY = 60.0 * ModeleRobot_DWork.invMouv;
            ModeleRobot_B.ConsigneTeta = (-ModeleRobot_P.SFunction_p19) / 2.0 *
              ModeleRobot_DWork.invMouv;
            ModeleRobot_DWork.CompteurTimeoutMvt = 0.0;
            ModeleRobot_DWork.TempoMot = 0.0;
          }
          break;

         default:
          enter_internal_JAUNE_GOTO_DISTR();
          break;
        }
      }
      break;

     case IN_JAUNE_RETOUR_ZONE_DEPART_ET_:
      /* During 'JAUNE_RETOUR_ZONE_DEPART_ET_DECHARGE': '<S1>:4377' */
      ModeleRobot_DWork.TempoMot = ModeleRobot_DWork.TempoMot + 1.0;
      switch (ModeleRobot_DWork.is_JAUNE_RETOUR_ZONE_DEPART_ET_) {
       case IN_ACTION_RETOUR_Z0_DECHARGE_01:
        /* During 'ACTION_RETOUR_Z0_DECHARGE_01': '<S1>:4387' */
        /* Graphical Function 'isFinMouvement': '<S1>:1282' */
        /* Transition: '<S1>:1285' */
        ModeleRobot_DWork.CompteurTimeoutMvt =
          ModeleRobot_DWork.CompteurTimeoutMvt + 1.0;

        /* Transition: '<S1>:1286' */
        /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
        if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 /
              ModeleRobot_P.SFunction_p49) || (ModeleRobot_B.DataTypeConversion
              != 0.0)) != 0) {
          /* Transition: '<S1>:4381' */
          /* Exit 'ACTION_RETOUR_Z0_DECHARGE_01': '<S1>:4387' */
          /* Entry 'ACTION_RETOUR_Z0_DECHARGE_02': '<S1>:4388' */
          ModeleRobot_DWork.is_JAUNE_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
            IN_ACTION_RETOUR_Z0_DECHARGE_02;
          ModeleRobot_DWork.was_JAUNE_RETOUR_ZONE_DEPART_ET = (uint8_T)
            IN_ACTION_RETOUR_Z0_DECHARGE_02;

          /*  termine en boucle ouverte pour venir buter contre la bordure */
          /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
          /* Transition: '<S1>:1301' */
          ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
          ModeleRobot_B.CommandeManuelleG = -20.0;
          ModeleRobot_B.CommandeManuelleD = -20.0;
          ModeleRobot_DWork.TempoMot = 0.0;
        }
        break;

       case IN_ACTION_RETOUR_Z0_DECHARGE_02:
        /* During 'ACTION_RETOUR_Z0_DECHARGE_02': '<S1>:4388' */
        if (ModeleRobot_DWork.TempoMot > 3.0 / ModeleRobot_P.SFunction_p49) {
          /* Transition: '<S1>:4382' */
          /* Exit 'ACTION_RETOUR_Z0_DECHARGE_02': '<S1>:4388' */
          /* Entry 'ACTION_RETOUR_Z0_DECHARGE_04': '<S1>:4389' */
          ModeleRobot_DWork.is_JAUNE_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
            IN_ACTION_RETOUR_Z0_DECHARGE_04;
          ModeleRobot_DWork.was_JAUNE_RETOUR_ZONE_DEPART_ET = (uint8_T)
            IN_ACTION_RETOUR_Z0_DECHARGE_04;
          ModeleRobot_DWork.TempoMot = 0.0;

          /*  arrête de buter contre la bordure */
          /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
          /* Transition: '<S1>:1301' */
          ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
          ModeleRobot_B.CommandeManuelleG = 0.0;
          ModeleRobot_B.CommandeManuelleD = 0.0;

          /*  ouvre le clapet de déchargement */
          /* Graphical Function 'setServo': '<S1>:4141' */
          /* Transition: '<S1>:4143' */
          ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p46 -
            1.0)] = ModeleRobot_P.SFunction_p47;

          /* Graphical Function 'setPWM': '<S1>:4112' */
          /* Transition: '<S1>:4114' */
          ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p18 -
            1.0)] = 0.0;
        }
        break;

       case IN_ACTION_RETOUR_Z0_DECHARGE_03:
        break;

       case IN_ACTION_RETOUR_Z0_DECHARGE_04:
        /* During 'ACTION_RETOUR_Z0_DECHARGE_04': '<S1>:4389' */
        if (ModeleRobot_DWork.TempoMot > 0.5 / ModeleRobot_P.SFunction_p49) {
          /* Transition: '<S1>:4383' */
          /* Exit 'ACTION_RETOUR_Z0_DECHARGE_04': '<S1>:4389' */
          /* Entry 'ACTION_RETOUR_Z0_DECHARGE_06': '<S1>:4390' */
          ModeleRobot_DWork.is_JAUNE_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
            IN_ACTION_RETOUR_Z0_DECHARGE_06;
          ModeleRobot_DWork.was_JAUNE_RETOUR_ZONE_DEPART_ET = (uint8_T)
            IN_ACTION_RETOUR_Z0_DECHARGE_06;
          ModeleRobot_DWork.TempoMot = 0.0;

          /*  aide à l'évacuation */
          /* Graphical Function 'setPWM': '<S1>:4112' */
          /* Transition: '<S1>:4114' */
          ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p16 -
            1.0)] = -100.0;
        }
        break;

       case IN_ACTION_RETOUR_Z0_DECHARGE_06:
        /* During 'ACTION_RETOUR_Z0_DECHARGE_06': '<S1>:4390' */
        if (ModeleRobot_DWork.TempoMot > 1.5 / ModeleRobot_P.SFunction_p49) {
          /* Transition: '<S1>:4384' */
          /* Exit 'ACTION_RETOUR_Z0_DECHARGE_06': '<S1>:4390' */
          /* Entry 'ACTION_RETOUR_Z0_DECHARGE_07': '<S1>:4391' */
          ModeleRobot_DWork.is_JAUNE_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
            IN_ACTION_RETOUR_Z0_DECHARGE_07;
          ModeleRobot_DWork.was_JAUNE_RETOUR_ZONE_DEPART_ET = (uint8_T)
            IN_ACTION_RETOUR_Z0_DECHARGE_07;
          ModeleRobot_DWork.TempoMot = 0.0;

          /*  aide à l'évacuation */
          /* Graphical Function 'setPWM': '<S1>:4112' */
          /* Transition: '<S1>:4114' */
          ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p16 -
            1.0)] = 0.0;

          /*  remet le robot dans une position connue pour la prochaine étape */
          /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
          /* Transition: '<S1>:1301' */
          ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
          ModeleRobot_B.CommandeManuelleG = 20.0;
          ModeleRobot_B.CommandeManuelleD = 20.0;
        }
        break;

       case IN_ACTION_RETOUR_Z0_DECHARGE_07:
        /* During 'ACTION_RETOUR_Z0_DECHARGE_07': '<S1>:4391' */
        if (ModeleRobot_DWork.TempoMot > 2.0 / ModeleRobot_P.SFunction_p49) {
          /* Transition: '<S1>:4385' */
          /* Exit 'ACTION_RETOUR_Z0_DECHARGE_07': '<S1>:4391' */
          /* Entry 'ACTION_RETOUR_Z0_DECHARGE_03': '<S1>:4392' */
          ModeleRobot_DWork.is_JAUNE_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
            IN_ACTION_RETOUR_Z0_DECHARGE_03;
          ModeleRobot_DWork.was_JAUNE_RETOUR_ZONE_DEPART_ET = (uint8_T)
            IN_ACTION_RETOUR_Z0_DECHARGE_03;

          /*  fin d'étape */
          /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
          /* Transition: '<S1>:1301' */
          ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
          ModeleRobot_B.CommandeManuelleG = 0.0;
          ModeleRobot_B.CommandeManuelleD = 0.0;
        }
        break;

       default:
        enter_internal_JAUNE_RETOUR_ZON();
        break;
      }
      break;

     case IN_VERT_GOTO_DISTRIBUTEURS_ET_R:
      VERT_GOTO_DISTRIBUTEURS_ET_RECU();
      break;

     case IN_VERT_RETOUR_ZONE_DEPART_ET_D:
      /* During 'VERT_RETOUR_ZONE_DEPART_ET_DECHARGE': '<S1>:4451' */
      ModeleRobot_DWork.TempoMot = ModeleRobot_DWork.TempoMot + 1.0;
      switch (ModeleRobot_DWork.is_VERT_RETOUR_ZONE_DEPART_ET_D) {
       case IN_ACTION_RETOUR_Z0_DECHARGE_01:
        /* During 'ACTION_RETOUR_Z0_DECHARGE_01': '<S1>:4461' */
        /* Graphical Function 'isFinMouvement': '<S1>:1282' */
        /* Transition: '<S1>:1285' */
        ModeleRobot_DWork.CompteurTimeoutMvt =
          ModeleRobot_DWork.CompteurTimeoutMvt + 1.0;

        /* Transition: '<S1>:1286' */
        /* ret = (CompteurTimeoutMvt > timeout) || (isFrontMontantConvergence(ConvergenceMvt)); */
        if (((ModeleRobot_DWork.CompteurTimeoutMvt > 3.0 /
              ModeleRobot_P.SFunction_p49) || (ModeleRobot_B.DataTypeConversion
              != 0.0)) != 0) {
          /* Transition: '<S1>:4455' */
          /* Exit 'ACTION_RETOUR_Z0_DECHARGE_01': '<S1>:4461' */
          /* Entry 'ACTION_RETOUR_Z0_DECHARGE_02': '<S1>:4462' */
          ModeleRobot_DWork.is_VERT_RETOUR_ZONE_DEPART_ET_D = (uint8_T)
            IN_ACTION_RETOUR_Z0_DECHARGE_02;
          ModeleRobot_DWork.was_VERT_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
            IN_ACTION_RETOUR_Z0_DECHARGE_02;

          /*  termine en boucle ouverte pour venir buter contre la bordure */
          /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
          /* Transition: '<S1>:1301' */
          ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
          ModeleRobot_B.CommandeManuelleG = -20.0;
          ModeleRobot_B.CommandeManuelleD = -20.0;
          ModeleRobot_DWork.TempoMot = 0.0;
        }
        break;

       case IN_ACTION_RETOUR_Z0_DECHARGE_02:
        /* During 'ACTION_RETOUR_Z0_DECHARGE_02': '<S1>:4462' */
        if (ModeleRobot_DWork.TempoMot > 3.0 / ModeleRobot_P.SFunction_p49) {
          /* Transition: '<S1>:4456' */
          /* Exit 'ACTION_RETOUR_Z0_DECHARGE_02': '<S1>:4462' */
          /* Entry 'ACTION_RETOUR_Z0_DECHARGE_04': '<S1>:4463' */
          ModeleRobot_DWork.is_VERT_RETOUR_ZONE_DEPART_ET_D = (uint8_T)
            IN_ACTION_RETOUR_Z0_DECHARGE_04;
          ModeleRobot_DWork.was_VERT_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
            IN_ACTION_RETOUR_Z0_DECHARGE_04;
          ModeleRobot_DWork.TempoMot = 0.0;

          /*  arrête de buter contre la bordure */
          /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
          /* Transition: '<S1>:1301' */
          ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
          ModeleRobot_B.CommandeManuelleG = 0.0;
          ModeleRobot_B.CommandeManuelleD = 0.0;

          /*  ouvre le clapet de déchargement */
          /* Graphical Function 'setServo': '<S1>:4141' */
          /* Transition: '<S1>:4143' */
          ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p46 -
            1.0)] = ModeleRobot_P.SFunction_p47;

          /* Graphical Function 'setPWM': '<S1>:4112' */
          /* Transition: '<S1>:4114' */
          ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p18 -
            1.0)] = 0.0;
        }
        break;

       case IN_ACTION_RETOUR_Z0_DECHARGE_03:
        break;

       case IN_ACTION_RETOUR_Z0_DECHARGE_04:
        /* During 'ACTION_RETOUR_Z0_DECHARGE_04': '<S1>:4463' */
        if (ModeleRobot_DWork.TempoMot > 0.5 / ModeleRobot_P.SFunction_p49) {
          /* Transition: '<S1>:4457' */
          /* Exit 'ACTION_RETOUR_Z0_DECHARGE_04': '<S1>:4463' */
          /* Entry 'ACTION_RETOUR_Z0_DECHARGE_06': '<S1>:4464' */
          ModeleRobot_DWork.is_VERT_RETOUR_ZONE_DEPART_ET_D = (uint8_T)
            IN_ACTION_RETOUR_Z0_DECHARGE_06;
          ModeleRobot_DWork.was_VERT_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
            IN_ACTION_RETOUR_Z0_DECHARGE_06;
          ModeleRobot_DWork.TempoMot = 0.0;

          /*  aide à l'évacuation */
          /* Graphical Function 'setPWM': '<S1>:4112' */
          /* Transition: '<S1>:4114' */
          ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p16 -
            1.0)] = -100.0;
        }
        break;

       case IN_ACTION_RETOUR_Z0_DECHARGE_06:
        /* During 'ACTION_RETOUR_Z0_DECHARGE_06': '<S1>:4464' */
        if (ModeleRobot_DWork.TempoMot > 1.5 / ModeleRobot_P.SFunction_p49) {
          /* Transition: '<S1>:4458' */
          /* Exit 'ACTION_RETOUR_Z0_DECHARGE_06': '<S1>:4464' */
          /* Entry 'ACTION_RETOUR_Z0_DECHARGE_07': '<S1>:4465' */
          ModeleRobot_DWork.is_VERT_RETOUR_ZONE_DEPART_ET_D = (uint8_T)
            IN_ACTION_RETOUR_Z0_DECHARGE_07;
          ModeleRobot_DWork.was_VERT_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
            IN_ACTION_RETOUR_Z0_DECHARGE_07;
          ModeleRobot_DWork.TempoMot = 0.0;

          /*  aide à l'évacuation */
          /* Graphical Function 'setPWM': '<S1>:4112' */
          /* Transition: '<S1>:4114' */
          ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p16 -
            1.0)] = 0.0;

          /*  remet le robot dans une position connue pour la prochaine étape */
          /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
          /* Transition: '<S1>:1301' */
          ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
          ModeleRobot_B.CommandeManuelleG = 20.0;
          ModeleRobot_B.CommandeManuelleD = 20.0;
        }
        break;

       case IN_ACTION_RETOUR_Z0_DECHARGE_07:
        /* During 'ACTION_RETOUR_Z0_DECHARGE_07': '<S1>:4465' */
        if (ModeleRobot_DWork.TempoMot > 2.0 / ModeleRobot_P.SFunction_p49) {
          /* Transition: '<S1>:4459' */
          /* Exit 'ACTION_RETOUR_Z0_DECHARGE_07': '<S1>:4465' */
          /* Entry 'ACTION_RETOUR_Z0_DECHARGE_03': '<S1>:4466' */
          ModeleRobot_DWork.is_VERT_RETOUR_ZONE_DEPART_ET_D = (uint8_T)
            IN_ACTION_RETOUR_Z0_DECHARGE_03;
          ModeleRobot_DWork.was_VERT_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
            IN_ACTION_RETOUR_Z0_DECHARGE_03;

          /*  fin d'étape */
          /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
          /* Transition: '<S1>:1301' */
          ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
          ModeleRobot_B.CommandeManuelleG = 0.0;
          ModeleRobot_B.CommandeManuelleD = 0.0;
        }
        break;

       default:
        enter_internal_VERT_RETOUR_ZONE();
        break;
      }
      break;

     default:
      Model_enter_internal_STRATEGIE1();
      break;
    }
  }
}

/* Initial conditions for atomic system: '<Root>/COMPORTEMENT' */
void ModeleRobot_COMPORTEMENT_Init(void)
{
  /* InitializeConditions for Stateflow: '<Root>/COMPORTEMENT' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/isFrontMontantMvtBloque'
   */

  /* InitializeConditions for UnitDelay: '<S8>/Delay Input1' */
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
        ModeleRobot_DWork.CouleurEquipe_memo = ModeleRobot_U.IN_CouleurEquipe;
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
        ModeleRobot_DWork.posXReferenceEntreEtapes = 53.0;

        /*  sortie de la zone de départ */
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
              (ModeleRobot_DWork.TempoInit > 5.0 / ModeleRobot_P.SFunction_p49))
          {
            /* Transition: '<S1>:3688' */
            /* Exit 'APPRENTISSAGE_KMAR_01': '<S1>:1010' */
            /* Entry 'APPRENTISSAGE_KMAR_02': '<S1>:3687' */
            ModeleRobot_DWork.is_ACTIONNEURS_REPOS = (uint8_T)
              Modele_IN_APPRENTISSAGE_KMAR_02;

            /* on est en butee on arrete immediatement l'ascenseur */
            /* Graphical Function 'setPWM': '<S1>:4112' */
            /* Transition: '<S1>:4114' */
            ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p15 -
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
          if (ModeleRobot_DWork.TempoInit > 1.0 / ModeleRobot_P.SFunction_p49) {
            /* Transition: '<S1>:3691' */
            /* Exit 'APPRENTISSAGE_KMAR_02': '<S1>:3687' */
            /* Entry 'APPRENTISSAGE_KMAR_03': '<S1>:3689' */
            ModeleRobot_DWork.is_ACTIONNEURS_REPOS = (uint8_T)
              Modele_IN_APPRENTISSAGE_KMAR_03;

            /* on remonte l'ascenseur jusqu'a la position d'un feu en haut de la torche */
            /* Graphical Function 'setPWM': '<S1>:4112' */
            /* Transition: '<S1>:4114' */
            ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p15 -
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
          if ((ModeleRobot_U.IN_Ascenseur_pos >= ModeleRobot_P.SFunction_p10) ||
              (ModeleRobot_DWork.TempoInit > 4.0 / ModeleRobot_P.SFunction_p49))
          {
            /* Transition: '<S1>:3693' */
            /* Exit 'APPRENTISSAGE_KMAR_03': '<S1>:3689' */
            /* Entry 'FIN_REPOS_ACTIONNEUR': '<S1>:3692' */
            ModeleRobot_DWork.is_ACTIONNEURS_REPOS = (uint8_T)
              ModeleR_IN_FIN_REPOS_ACTIONNEUR;

            /* on arrete l'ascenseur */
            /* Graphical Function 'setPWM': '<S1>:4112' */
            /* Transition: '<S1>:4114' */
            ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p15 -
              1.0)] = 0.0;
          } else {
            ModeleRobot_DWork.TempoInit = ModeleRobot_DWork.TempoInit + 1.0;
          }
          break;

         case ModeleR_IN_FIN_REPOS_ACTIONNEUR:
          break;

         case ModeleRobot_IN_REPOS_SERVOS:
          /* During 'REPOS_SERVOS': '<S1>:1009' */
          if (ModeleRobot_DWork.TempoInit > 2.0 / ModeleRobot_P.SFunction_p49) {
            /* Transition: '<S1>:1008' */
            /* Exit 'REPOS_SERVOS': '<S1>:1009' */
            /* Entry 'APPRENTISSAGE_KMAR_01': '<S1>:1010' */
            ModeleRobot_DWork.is_ACTIONNEURS_REPOS = (uint8_T)
              Modele_IN_APPRENTISSAGE_KMAR_01;

            /* les pinces sont rangees on peut descendre l'ascenseur */
            /* Graphical Function 'setPWM': '<S1>:4112' */
            /* Transition: '<S1>:4114' */
            ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p15 -
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
          if (ModeleRobot_U.IN_CouleurEquipe == ModeleRobot_P.SFunction_p5) {
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
          if (ModeleRobot_U.IN_CouleurEquipe == ModeleRobot_P.SFunction_p6) {
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
              ModeleRobot_P.SFunction_p49) {
            /* Transition: '<S1>:1418' */
            /* Exit 'INIT1': '<S1>:3674' */
            /* Entry 'TEST_ACT_1': '<S1>:1417' */
            ModeleRobot_DWork.is_TESTS_ACTIONNEUR = (uint8_T)
              ModeleRobot_IN_TEST_ACT_1;
            ModeleRobot_DWork.TempoTestActionneurs = 0.0;

            /* Graphical Function 'setServo': '<S1>:4141' */
            /* Transition: '<S1>:4143' */
            ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p37 -
              1.0)] = ModeleRobot_P.SFunction_p39;
          }
          break;

         case ModeleRobot_IN_TEST_ACT_1:
          /* During 'TEST_ACT_1': '<S1>:1417' */
          if (ModeleRobot_DWork.TempoTestActionneurs > 2.0 /
              ModeleRobot_P.SFunction_p49) {
            /* Transition: '<S1>:1446' */
            /* Exit 'TEST_ACT_1': '<S1>:1417' */
            /* Entry 'TEST_ACT_2': '<S1>:3798' */
            ModeleRobot_DWork.is_TESTS_ACTIONNEUR = (uint8_T)
              ModeleRobot_IN_TEST_ACT_2;
            ModeleRobot_DWork.TempoTestActionneurs = 0.0;

            /* Graphical Function 'setServo': '<S1>:4141' */
            /* Transition: '<S1>:4143' */
            ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p37 -
              1.0)] = ModeleRobot_P.SFunction_p41;

            /* Graphical Function 'setServo': '<S1>:4141' */
            /* Transition: '<S1>:4143' */
            ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p31 -
              1.0)] = ModeleRobot_P.SFunction_p33;
          }
          break;

         case ModeleRobot_IN_TEST_ACT_2:
          /* During 'TEST_ACT_2': '<S1>:3798' */
          if (ModeleRobot_DWork.TempoTestActionneurs > 2.0 /
              ModeleRobot_P.SFunction_p49) {
            /* Transition: '<S1>:3803' */
            /* Exit 'TEST_ACT_2': '<S1>:3798' */
            /* Entry 'TEST_ACT_3': '<S1>:4151' */
            ModeleRobot_DWork.is_TESTS_ACTIONNEUR = (uint8_T)
              ModeleRobot_IN_TEST_ACT_3;
            ModeleRobot_DWork.TempoTestActionneurs = 0.0;

            /* Graphical Function 'setServo': '<S1>:4141' */
            /* Transition: '<S1>:4143' */
            ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p31 -
              1.0)] = ModeleRobot_P.SFunction_p35;
          }
          break;

         case ModeleRobot_IN_TEST_ACT_3:
          /* During 'TEST_ACT_3': '<S1>:4151' */
          if (ModeleRobot_DWork.TempoTestActionneurs > 2.0 /
              ModeleRobot_P.SFunction_p49) {
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
        if (ModeleRobot_DWork.TempoImage > 1.0 / ModeleRobot_P.SFunction_p49) {
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
        if (ModeleRobot_DWork.TempoImage > 1.0 / ModeleRobot_P.SFunction_p49) {
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
        if (ModeleRobot_DWork.TempoImage > 1.0 / ModeleRobot_P.SFunction_p49) {
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
        if (ModeleRobot_DWork.TempoImage > 1.0 / ModeleRobot_P.SFunction_p49) {
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
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p37 - 1.0)]
          = ModeleRobot_P.SFunction_p41;

        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p31 - 1.0)]
          = ModeleRobot_P.SFunction_p35;

        /* Graphical Function 'setPWM': '<S1>:4112' */
        /* Transition: '<S1>:4114' */
        ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p15 - 1.0)]
          = 0.0;

        /* Graphical Function 'setPWM': '<S1>:4112' */
        /* Transition: '<S1>:4114' */
        ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p16 - 1.0)]
          = 0.0;

        /* Graphical Function 'setPWM': '<S1>:4112' */
        /* Transition: '<S1>:4114' */
        ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p18 - 1.0)]
          = 0.0;

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
      if (ModeleRobot_DWork.DureeMatch > 90.0 / ModeleRobot_P.SFunction_p49) {
        /* Transition: '<S1>:1266' */
        if (ModeleRobot_DWork.is_STRATEGIE == ModeleRobot_IN_STRATEGIE1) {
          if (ModeleRobot_DWork.is_STRATEGIE1 == ModeleRobot_IN_DEMO) {
            if (ModeleRobot_DWork.is_DEMO == ModeleRobot_IN_ACTION_HOMOLO_2) {
              /* Exit 'ACTION_HOMOLO_2': '<S1>:4167' */
              /* Graphical Function 'setServo': '<S1>:4141' */
              /* Transition: '<S1>:4143' */
              ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p37
                - 1.0)] = ModeleRobot_P.SFunction_p41;

              /* Graphical Function 'setServo': '<S1>:4141' */
              /* Transition: '<S1>:4143' */
              ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p31
                - 1.0)] = ModeleRobot_P.SFunction_p35;
              ModeleRobot_DWork.is_DEMO = (uint8_T)
                ModeleRobot_IN_NO_ACTIVE_CHILD;
            } else {
              /* Exit 'ACTION_18': '<S1>:4139' */
              /* Exit 'ACTION_HOMOLO_0': '<S1>:4165' */
              /* Exit 'ACTION_HOMOLO_01': '<S1>:4181' */
              /* Exit 'ACTION_HOMOLO_02': '<S1>:4183' */
              /* Exit 'ACTION_HOMOLO_03': '<S1>:4220' */
              /* Exit 'ACTION_HOMOLO_05': '<S1>:4239' */
              /* Exit 'ACTION_HOMOLO_09': '<S1>:4280' */
              /* Exit 'ACTION_HOMOLO_10': '<S1>:4204' */
              /* Exit 'ACTION_HOMOLO_11': '<S1>:4207' */
              /* Exit 'ACTION_HOMOLO_12': '<S1>:4210' */
              /* Exit 'ACTION_HOMOLO_13': '<S1>:4213' */
              /* Exit 'ACTION_HOMOLO_14': '<S1>:4215' */
              /* Exit 'ACTION_HOMOLO_15': '<S1>:4237' */
              /* Exit 'ACTION_HOMOLO_16': '<S1>:4243' */
              /* Exit 'ACTION_HOMOLO_24': '<S1>:4279' */
              /* Exit 'ACTION_HOMOLO_25': '<S1>:4281' */
              /* Exit 'ACTION_HOMOLO_30': '<S1>:4296' */
              /* Exit 'ACTION_HOMOLO_33': '<S1>:4309' */
              /* Exit 'ACTION_HOMOLO_34': '<S1>:4311' */
              /* Exit 'ACTION_HOMOLO_35': '<S1>:4314' */
              /* Exit 'ACTION_HOMOLO_36': '<S1>:4316' */
              /* Exit 'ACTION_HOMOLO_4': '<S1>:4169' */
              /* Exit 'ACTION_HOMOLO_40': '<S1>:4338' */
              /* Exit 'ACTION_HOMOLO_41': '<S1>:4339' */
              /* Exit 'ACTION_HOMOLO_43': '<S1>:4343' */
              /* Exit 'ACTION_HOMOLO_44': '<S1>:4348' */
              /* Exit 'ACTION_HOMOLO_45': '<S1>:4350' */
              /* Exit 'ACTION_HOMOLO_46': '<S1>:4395' */
              /* Exit 'ACTION_HOMOLO_47': '<S1>:4409' */
              /* Exit 'ACTION_HOMOLO_48': '<S1>:4411' */
              /* Exit 'ACTION_HOMOLO_49': '<S1>:4413' */
              /* Exit 'ACTION_HOMOLO_50': '<S1>:4471' */
              /* Exit 'ACTION_HOMOLO_51': '<S1>:4477' */
              /* Exit 'ACTION_HOMOLO_52': '<S1>:4489' */
              /* Exit 'ACTION_HOMOLO_53': '<S1>:4490' */
              /* Exit 'ACTION_HOMOLO_54': '<S1>:4491' */
              /* Exit 'ACTION_HOMOLO_55': '<S1>:4498' */
              /* Exit 'ACTION_HOMOLO_56': '<S1>:4500' */
              /* Exit 'ACTION_HOMOLO_57': '<S1>:4502' */
              /* Exit 'ACTION_HOMOLO_58': '<S1>:4504' */
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
            /* Exit 'ACTION_DISTRIB_01': '<S1>:4365' */
            ModeleRobot_DWork.is_JAUNE_GOTO_DISTRIBUTEURS_ET_ = (uint8_T)
              ModeleRobot_IN_NO_ACTIVE_CHILD;

            /* Exit 'ACTION_DISTRIB_010': '<S1>:4407' */
            /* Exit 'ACTION_DISTRIB_011': '<S1>:4415' */
            /* Exit 'ACTION_DISTRIB_02': '<S1>:4366' */
            /* Exit 'ACTION_DISTRIB_03': '<S1>:4368' */
            /* Exit 'ACTION_DISTRIB_04': '<S1>:4369' */
            /* Exit 'ACTION_DISTRIB_05': '<S1>:4370' */
            /* Exit 'ACTION_DISTRIB_06': '<S1>:4372' */
            /* Exit 'ACTION_DISTRIB_07': '<S1>:4373' */
            /* Exit 'ACTION_DISTRIB_08': '<S1>:4375' */
            /* Exit 'ACTION_DISTRIB_09': '<S1>:4405' */
            /* Exit 'JAUNE_GOTO_DISTRIBUTEURS_ET_RECUPERE': '<S1>:4353' */
            /* Exit 'ACTION_RETOUR_Z0_DECHARGE_01': '<S1>:4387' */
            ModeleRobot_DWork.is_JAUNE_RETOUR_ZONE_DEPART_ET_ = (uint8_T)
              ModeleRobot_IN_NO_ACTIVE_CHILD;

            /* Exit 'ACTION_RETOUR_Z0_DECHARGE_02': '<S1>:4388' */
            /* Exit 'ACTION_RETOUR_Z0_DECHARGE_03': '<S1>:4392' */
            /* Exit 'ACTION_RETOUR_Z0_DECHARGE_04': '<S1>:4389' */
            /* Exit 'ACTION_RETOUR_Z0_DECHARGE_06': '<S1>:4390' */
            /* Exit 'ACTION_RETOUR_Z0_DECHARGE_07': '<S1>:4391' */
            /* Exit 'JAUNE_RETOUR_ZONE_DEPART_ET_DECHARGE': '<S1>:4377' */
            /* Exit 'ACTION_DISTRIB_01': '<S1>:4437' */
            ModeleRobot_DWork.is_VERT_GOTO_DISTRIBUTEURS_ET_R = (uint8_T)
              ModeleRobot_IN_NO_ACTIVE_CHILD;

            /* Exit 'ACTION_DISTRIB_010': '<S1>:4439' */
            /* Exit 'ACTION_DISTRIB_011': '<S1>:4445' */
            /* Exit 'ACTION_DISTRIB_02': '<S1>:4441' */
            /* Exit 'ACTION_DISTRIB_03': '<S1>:4442' */
            /* Exit 'ACTION_DISTRIB_04': '<S1>:4443' */
            /* Exit 'ACTION_DISTRIB_05': '<S1>:4444' */
            /* Exit 'ACTION_DISTRIB_06': '<S1>:4447' */
            /* Exit 'ACTION_DISTRIB_07': '<S1>:4448' */
            /* Exit 'ACTION_DISTRIB_08': '<S1>:4450' */
            /* Exit 'ACTION_DISTRIB_09': '<S1>:4438' */
            /* Exit 'VERT_GOTO_DISTRIBUTEURS_ET_RECUPERE': '<S1>:4423' */
            /* Exit 'ACTION_RETOUR_Z0_DECHARGE_01': '<S1>:4461' */
            ModeleRobot_DWork.is_VERT_RETOUR_ZONE_DEPART_ET_D = (uint8_T)
              ModeleRobot_IN_NO_ACTIVE_CHILD;

            /* Exit 'ACTION_RETOUR_Z0_DECHARGE_02': '<S1>:4462' */
            /* Exit 'ACTION_RETOUR_Z0_DECHARGE_03': '<S1>:4466' */
            /* Exit 'ACTION_RETOUR_Z0_DECHARGE_04': '<S1>:4463' */
            /* Exit 'ACTION_RETOUR_Z0_DECHARGE_06': '<S1>:4464' */
            /* Exit 'ACTION_RETOUR_Z0_DECHARGE_07': '<S1>:4465' */
            /* Exit 'VERT_RETOUR_ZONE_DEPART_ET_DECHARGE': '<S1>:4451' */
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
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p37 - 1.0)]
          = ModeleRobot_P.SFunction_p41;

        /* Graphical Function 'setServo': '<S1>:4141' */
        /* Transition: '<S1>:4143' */
        ModeleRobot_B.CommandeServo[(int32_T)(ModeleRobot_P.SFunction_p31 - 1.0)]
          = ModeleRobot_P.SFunction_p35;

        /* Graphical Function 'setPWM': '<S1>:4112' */
        /* Transition: '<S1>:4114' */
        ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p15 - 1.0)]
          = 0.0;

        /* Graphical Function 'setPWM': '<S1>:4112' */
        /* Transition: '<S1>:4114' */
        ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p16 - 1.0)]
          = 0.0;

        /* Graphical Function 'setPWM': '<S1>:4112' */
        /* Transition: '<S1>:4114' */
        ModeleRobot_B.CommandeMoteur[(int32_T)(ModeleRobot_P.SFunction_p18 - 1.0)]
          = 0.0;

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
                  ModeleRobot_P.SFunction_p49) {
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
          ModeleRobot_STRATEGIE1();
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
   *  RelationalOperator: '<S12>/Compare'
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
   *  RelationalOperator: '<S11>/Compare'
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
   *  Constant: '<S13>/Constant'
   *  Inport: '<Root>/IN_ConvergenceMvt'
   *  Logic: '<S3>/Logical Operator'
   *  RelationalOperator: '<S13>/Compare'
   *  RelationalOperator: '<S14>/FixPt Relational Operator'
   *  UnitDelay: '<S14>/Delay Input1'
   */
  ModeleRobot_B.DataTypeConversion = (real_T)(((ModeleRobot_U.IN_ConvergenceMvt
    != ModeleRobot_DWork.DelayInput1_DSTATE) != 0) &&
    ((ModeleRobot_U.IN_ConvergenceMvt == ModeleRobot_P.Constant_Value) != 0));

  /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
   *  Constant: '<S17>/Constant'
   *  Inport: '<Root>/IN_ConvergenceMvt_Rapide'
   *  Logic: '<S4>/Logical Operator'
   *  RelationalOperator: '<S17>/Compare'
   *  RelationalOperator: '<S18>/FixPt Relational Operator'
   *  UnitDelay: '<S18>/Delay Input1'
   */
  ModeleRobot_B.DataTypeConversion_g = (real_T)
    (((ModeleRobot_U.IN_ConvergenceMvt_Rapide !=
       ModeleRobot_DWork.DelayInput1_DSTATE_m) != 0) &&
     ((ModeleRobot_U.IN_ConvergenceMvt_Rapide == ModeleRobot_P.Constant_Value_g)
      != 0));

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

  /* Update for UnitDelay: '<S14>/Delay Input1' incorporates:
   *  Update for Inport: '<Root>/IN_ConvergenceMvt'
   */
  ModeleRobot_DWork.DelayInput1_DSTATE = ModeleRobot_U.IN_ConvergenceMvt;

  /* Update for UnitDelay: '<S18>/Delay Input1' incorporates:
   *  Update for Inport: '<Root>/IN_ConvergenceMvt_Rapide'
   */
  ModeleRobot_DWork.DelayInput1_DSTATE_m =
    ModeleRobot_U.IN_ConvergenceMvt_Rapide;
}

/* Model initialize function */
void ModeleRobot_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* InitializeConditions for UnitDelay: '<S14>/Delay Input1' */
  ModeleRobot_DWork.DelayInput1_DSTATE = ModeleRobot_P.DelayInput1_X0;

  /* InitializeConditions for UnitDelay: '<S18>/Delay Input1' */
  ModeleRobot_DWork.DelayInput1_DSTATE_m = ModeleRobot_P.DelayInput1_X0_m;

  /* InitializeConditions for Stateflow: '<Root>/COMPORTEMENT' */
  ModeleRobot_COMPORTEMENT_Init();
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
