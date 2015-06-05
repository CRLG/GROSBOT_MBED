/*! \file CMatch.cpp
	\brief Classe qui contient toute l'application
*/
#include "CMatch.h"
#include "mbed.h"
#include "RessourcesHardware.h"

#include "CGlobale.h"
#include "ConfigSpecifiqueCoupe.h"

//extern "C" {
// #include "ModeleRobot.h"  		// Le code généré par Matlab Simulink est en "C" et pas en "C++"
//}

//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CMatch::CMatch() 
{
   // m_ia=new IA();
    Initialise();
}

//___________________________________________________________________________
 /*!
   \brief Destructeur

   \param --
   \return --
*/
CMatch::~CMatch() 
{

}


//___________________________________________________________________________
 /*!
   \brief Initialise toutes les structures de donnéess du match à jouer

   \param --
   \return --
*/
void CMatch::Initialise(void)
{
    //m_iaSCI=new IA::DefaultSCI();
    m_iaSCI=m_ia.getDefaultSCI();
    m_ia.init();

    m_duree = 0;
    m_couleur_equipe = 0;
    m_dde_test_actionneurs = 0;
    m_choix_strategie = 0;
    m_convergence_old=0;
    m_convergence_rapide_old=0;

    m_obstacleDetecte=0;
    m_obstacle_AVG=Application.m_capteurs.m_telemetres.m_distance[0];
    m_obstacle_ARD=Application.m_capteurs.m_telemetres.m_distance[1];
    m_obstacle_ARG=Application.m_capteurs.m_telemetres.m_distance[2];
    m_obstacle_AVD=Application.m_capteurs.m_telemetres.m_distance[3];

    _led1 = 0;
    _led2 = 0;
    _led3 = 0;
    _led4 = 0;
    m_ia.enter();
}
	

//___________________________________________________________________________
 /*!
   \brief Execute un pas de calcul du match

   \param --
   \return --
*/
void CMatch::step(void)
{
    // ___________________________
    // Recopie les valeurs de l'environnement vers les entrées du modèle
	
    //____________________________
    //Variables calculées
    //sens de deplacement: en fonction du signe si + alors marche avant
    float sens=copysignf(1.0,Application.m_asservissement.erreur_distance);
    m_obstacleDetecte=isObstacle(Application.m_asservissement.X_robot,
                                Application.m_asservissement.Y_robot,
                                Application.m_asservissement.angle_robot,
                                Application.m_asservissement.vitesse_avance_robot,
                                sens);
    m_iaSCI->set_iN_Obstacle(m_obstacleDetecte);

    //____________________________
    //Variables de l'Ecran
    m_iaSCI->set_iN_Couleur(m_couleur_equipe);

    //____________________________
    //capteurs US
	//pour les obstacles on ne passe plus un booleen a la strategie mais la distance
    m_obstacle_AVG=Application.m_capteurs.m_telemetres.m_distance[0];
    m_obstacle_ARD=Application.m_capteurs.m_telemetres.m_distance[1];
    m_obstacle_ARG=Application.m_capteurs.m_telemetres.m_distance[2];
    m_obstacle_AVD=Application.m_capteurs.m_telemetres.m_distance[3];

    //____________________________
	//Capteurs TOR
    //m_b_Etor1==1 => tirette enlevee
    if(Application.m_capteurs.m_b_Etor1==1) m_iaSCI->raise_eV_Tirette();
    _led4=!_led4;

    //____________________________
	//Variables de l'aservissement
    m_iaSCI->set_iN_x_pos(Application.m_asservissement.X_robot);
    m_iaSCI->set_iN_y_pos(Application.m_asservissement.Y_robot);
    m_iaSCI->set_iN_teta_pos(Application.m_asservissement.angle_robot);
    m_iaSCI->set_iN_vitesse(Application.m_asservissement.vitesse_avance_robot); //vitesse de deplacement: a verifier avec guigui
    m_iaSCI->set_iN_sens_deplacement(sens);

    if (frontMontant(m_convergence_old,Application.m_asservissement.convergence_conf))
        m_iaSCI->raise_eV_ConvergenceMvt();
    m_convergence_old=Application.m_asservissement.convergence_conf;


    if (frontMontant(m_convergence_rapide_old,Application.m_asservissement.convergence_rapide))
        m_iaSCI->raise_eV_ConvergenceMvt_Rapide();
    m_convergence_rapide_old=Application.m_asservissement.convergence_rapide;



	//TODO:
	//diag de blocage, pour l'instant on claque les tempo
	
	// ___________________________ 
    //Appel de la strategie du modele
    m_ia.runCycle();
	
	//SORTIES de MODELE
    //m_obstacleDetecte=ModeleRobot_Y.OUT_isObstacle;

	// ___________________________ 
	// Divers
    m_duree = m_iaSCI->get_tempsMatch() * 0.02;    // m_match.m_duree est en nombre de passage dans la boucle de 20msec
	
	// Asservissement
	Application.m_asservissement.CalculsMouvementsRobots();
}




//___________________________________________________________________________
 /*!
   \brief Envoie les infos sur la  RS232

   \param --
   \return --
*/
void CMatch::debug(void)
{
   _rs232_pc_tx.putc(0xC);	// Saut de page pour que toutes les infos soient affichées toujours au meme endroit sur la page (avec hyperterminal)
//   _rs232_pc_tx.printf("DureeMatch=%f\r\n", m_duree);
//   _rs232_pc_tx.printf("MvtManuel=%f(%f, %f)\n\r", ModeleRobot_Y.OUT_DdeMvtManuel, ModeleRobot_Y.OUT_CommandeManuelleG, ModeleRobot_Y.OUT_CommandeManuelleD);
//   _rs232_pc_tx.printf("MvtDistAngle=%f(%f, %f)\n\r", ModeleRobot_Y.OUT_DdeMvtDistanceAngle, ModeleRobot_Y.OUT_ConsigneDistance, ModeleRobot_Y.OUT_ConsigneTeta);
//   _rs232_pc_tx.printf("MvtXY=%f(%f, %f)\n\r", ModeleRobot_Y.OUT_DdeMvtXY, ModeleRobot_Y.OUT_ConsigneX, ModeleRobot_Y.OUT_ConsigneY);
   _rs232_pc_tx.printf("CdeMotG=%f - CdeMotD=%f\n\r", Application.m_asservissement.cde_moteur_G, Application.m_asservissement.cde_moteur_D);
}

bool CMatch::frontMontant(float prec_value, float value)
{
    bool b_Up=false;
    if(value>prec_value) b_Up=true;
    return b_Up;
}

int CMatch::isObstacle(float x, float y, float teta, float speed, float sens)
{
    //calibration
    //TODO: a remplacer par une carto
    float seuilDistance=15; //en cm
    int detection=0;

    if (sens>0) //marche avant
        ((m_obstacle_AVD<=seuilDistance)||(m_obstacle_AVG<=seuilDistance))? detection=1:detection=0;
    else //marche arrière
        ((m_obstacle_ARD<=seuilDistance)||(m_obstacle_ARG<=seuilDistance))? detection=1:detection=0;

    return detection;
}


void IA::SCI_Asser_OCB::Manuel(sc_real mot_gauche, sc_real mot_droit){
    Application.m_match.m_iaSCI->set_countTimeMvt(0);
    Application.m_asservissement.CommandeManuelle(mot_gauche, mot_droit);
}

void IA::SCI_Asser_OCB::XYTeta(sc_real x, sc_real y, sc_real teta){
    Application.m_match.m_iaSCI->set_countTimeMvt(0);
    Application.m_asservissement.CommandeMouvementXY_TETA(x,y,teta);
}

void IA::SCI_Asser_OCB::DistanceAngle(sc_real distance, sc_real angle){
    Application.m_match.m_iaSCI->set_countTimeMvt(0);
    Application.m_asservissement.CommandeMouvementDistanceAngle(distance, angle);
}

void IA::SCI_Asser_OCB::XY(sc_real x, sc_real y){
    Application.m_match.m_iaSCI->set_countTimeMvt(0);
    Application.m_asservissement.CommandeMouvementXY(x, y);
}

void IA::SCI_Asser_OCB::Vitesse(sc_real speedDist, sc_real speedRot){
    Application.m_asservissement.CommandeVitesseMouvement(speedDist,speedRot);
}

void IA::SCI_Asser_OCB::setPosition(sc_real x, sc_real y, sc_real teta){
    Application.m_asservissement.setPosition_XYTeta(x, y, teta);
}


void IA::SCI_Servo_OCB::setPos(sc_integer idServo, sc_integer value){
    Application.m_servos_sd20.CommandePositionVitesse(idServo, value,0);
}

void IA::SCI_Servo_OCB::setRelache(sc_integer idServo, sc_real time_ms){
    if (time_ms==0)
        Application.m_servos_sd20.setDureeAvantRelache(idServo, RELACHE_SERVO_OFF);
    else
        Application.m_servos_sd20.setDureeAvantRelache(idServo,time_ms);
}

void IA::SCI_Moteur_OCB::setPWM(sc_integer idMot, sc_real pwm){
    //ALERTE: codé en dur
    //si l'ascenseur atteint son capteur de fin de course et que la consigne est négative
    //on coupe la commande (valeur écrasée)
    if (idMot==Application.m_match.m_iaSCI->get_mOTEUR_ASCENSEUR())
        if ((Application.m_capteurs.m_b_Etor2<=0)&& (pwm<0))
            Application.m_moteurs.CommandeVitesse(idMot, 0);
        else
            Application.m_moteurs.CommandeVitesse(idMot, pwm);
    else
        Application.m_moteurs.CommandeVitesse(idMot, pwm);
}

void IA::SCI_Capteur_OCB::resetCodeur(sc_integer idCodeur, sc_integer value){
    Application.m_capteurs.RAZ_PositionCodeur(idCodeur,0);
}

void IA::SCI_Ihm_OCB::setLed(sc_integer idLed, sc_boolean onoff){
    switch(idLed){
//        case 1:
//            _led1 = onoff; break;
        case 2:
            _led2 = onoff; break;
        case 3:
            _led3 = onoff; break;
        case 4:
            _led4 = onoff; break;
        default:
            _led4=onoff;break;
    }
}

void IA::SCI_Ascenseur_OCB::init()
{
    int j=0;
}
