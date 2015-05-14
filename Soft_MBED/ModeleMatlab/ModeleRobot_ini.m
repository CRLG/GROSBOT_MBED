% Fichier d'initialisation des constantes, tables, ...
% Et d'ouverture du modèle
clc;
display ('_________________________________ COMPORTEMENT ROBOT')

display ('Nettoyage du workspace');
clear all;

display ('Intialisation des données du modèle');
Te = 0.02;  % Période d'échantillonnage à 50msec
PI=pi;
%PI=3.1416;

%ID des Moteurs
MOTEUR_ROUE_GAUCHE =1; %MOTEUR_1,
MOTEUR_ROUE_DROITE=2;  % MOTEUR_2
MOTEUR_ASCENSEUR=3; 	% MOTEUR_3
MOTEUR_DISTRIBUTEUR=4; 	% MOTEUR_4
MOTEUR_NON_DEFINI=5; 	    % MOTEUR_5
MOTEUR_SOUFFLEUR=6;    % MOTEUR_6
%MOTEUR_ELECTROVANNE=7;

%ID des Servos
SERVO_BRAS=13;
SERVO_CENTREUR_G=14;
SERVO_CENTREUR_D=15;
SERVO_PINCE_D=16;
SERVO_PINCE_G=17;
SERVO_BALLE=18;
SERVO_RECOLTEURS=19;
SERVO_VOLET=20;

%SERVO BRAS
SERVO_BRAS_OUVERT = 21;
SERVO_BRAS_FERME=152;

%SERVO CENTREUR G
SERVO_CENTREUR_G_OUVERT = 134;
SERVO_CENTREUR_G_FERME=27;

%SERVO CENTREUR D
SERVO_CENTREUR_D_OUVERT = 21;
SERVO_CENTREUR_D_FERME=130;

%SERVO PINCE D
SERVO_PINCE_D_OUVERT = 1;
SERVO_PINCE_D_ENTRE_OUVERT = 81;
SERVO_PINCE_D_FERME=120;

%SERVO PINCE G
SERVO_PINCE_G_OUVERT = 205;
SERVO_PINCE_G_ENTRE_OUVERT = 161;
SERVO_PINCE_G_FERME=80;

%SERVO BALLE
SERVO_BALLE_OUVERT = 166;
SERVO_BALLE_FERME=42;

%SERVO RECOLTEURS
SERVO_RECOLTEURS_OUVERT = 191;
SERVO_RECOLTEURS_FERME=60;

%SERVO VOLET
SERVO_VOLET_OUVERT = 60;
SERVO_VOLET_FERME=129;

MAX_SPEED_SERVOS = 0;

% Couleur de l'équipe
EQUIPE_JAUNE = 0;
EQUIPE_VERTE = 1;

%Positions du kmar
KMAR_POSITION_HAUT=2476;
KMAR_POSITION_DEPART=220;
KMAR_POSITION_AU_DESSUS_SPOT_SANS_SPOT=1385;
KMAR_POSITION_AU_DESSUS_SPOT_AVEC_SPOT=1833;
KMAR_POSITION_SPOT_BAS=810;

% ---------------------------------------------------
% BITS DE CONFIGURATION
DEBUG_TORCHE=0; %pour debuguer la squence de chargement de la torche
STT=1; %1 => stratégie d'évitement basique, on s'arrête et quand il n'y a plus d'obstacle on repart
JUST_HOMOLO=1; %1 => on fait juste le programme d'homologation
MODE_XYTETA=1; %1 => on utilise le mode XYTeta (economie de mouvement)
DEBUG_ASCENSEUR=0;

display ('Ouverture du modèle');
open ModeleRobot.mdl;
display('Modèle Robot ouvert avec succès');

%option Pack and Go : génération du fichier .zip contenant tous les
%fichiers nécessaires à la compilation du modèle dans un autre
%environnement de compilation (CodeBlocks) en utilisant une structure de
%fichiers "à plat" (tous les fichiers sont dans un même répertoire, il n'y
%a aucune arborescence)
set_param(bdroot,'PostCodeGenCommand','packNGo(buildInfo);');
display('Options PackNGo OK');



display ('_________________________________ FIN ROBOT');


