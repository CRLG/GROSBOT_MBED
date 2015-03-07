% Fichier d'initialisation des constantes, tables, ...
% Et d'ouverture du mod�le
clc;
display ('_________________________________ COMPORTEMENT ROBOT')

display ('Nettoyage du workspace');
clear all;

display ('Intialisation des donn�es du mod�le');
Te = 0.02;  % P�riode d'�chantillonnage � 50msec
PI=pi;
%PI=3.1416;

%SERVO Kmar
SERVO_KMAR_STOCK = 210;
SERVO_KMAR_RETOURNE = 20;
SERVO_KMAR_DEPOSE_G = 150;
SERVO_KMAR_DEPOSE_D =50;
SERVO_KMAR_MILIEU = 120;

%SERVO actionnant le "retourne feu"
SERVO_FEU_RANGE = 25;
SERVO_FEU_VERTICAL = 120;
SERVO_FEU_SORTI = 160;

%SERVO actionnant le crochet arriere
SERVO_CROCHET_RANGE = 73;
SERVO_CROCHET_SORTI = 180; %185 ca passe tout juste

%SERVO actionnant le Nerf
SERVO_NERF_ARME = 10;
SERVO_NERF_TIR = 100;

%SERVO actionnant l'ancre qui retient le filet
SERVO_FILET_RETIENT = 254;
SERVO_FILET_LIBERE = 5;

MAX_SPEED_SERVOS = 0;

% Couleur de l'�quipe
EQUIPE_JAUNE = 0;
EQUIPE_ROUGE = 1;

%Positions du kmar
KMAR_POSITION_HAUT=2400;
KMAR_POSITION_TORCHE_HAUT=2100;
KMAR_POSITION_TORCHE_MILIEU=1440;
KMAR_POSITION_TORCHE_BAS=810;
KMAR_POSITION_FEU_TERRAIN=110;
KMAR_POSITION_RETOURNEMENT=2186;
KMAR_POSITION_STOCKAGE=1177;

% ---------------------------------------------------
% BITS DE CONFIGURATION
DEBUG_TORCHE=0; %pour debuguer la squence de chargement de la torche
STT=1; %1 => strat�gie d'�vitement basique, on s'arr�te et quand il n'y a plus d'obstacle on repart
JUST_HOMOLO=1; %1 => on fait juste le programme d'homologation
MODE_XYTETA=1; %1 => on utilise le mode XYTeta (economie de mouvement)

display ('Ouverture du mod�le');
open ModeleRobot.mdl;
display('Mod�le Robot ouvert avec succ�s');

%option Pack and Go : g�n�ration du fichier .zip contenant tous les
%fichiers n�cessaires � la compilation du mod�le dans un autre
%environnement de compilation (CodeBlocks) en utilisant une structure de
%fichiers "� plat" (tous les fichiers sont dans un m�me r�pertoire, il n'y
%a aucune arborescence)
set_param(bdroot,'PostCodeGenCommand','packNGo(buildInfo);');
display('Options PackNGo OK');



display ('_________________________________ FIN ROBOT');


