/*! \file CMatch.cpp
	\brief Classe qui contient toute l'application
*/
#include "CMatch.h"
#include "mbed.h"
#include "RessourcesHardware.h"

#include "CGlobale.h"
#include "ConfigSpecifiqueCoupe.h"

#include "../ModeleSCT/src-gen/IA.h"

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
    //Initialise();
    m_ia = new IA();
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
   \brief Initialise toutes les structures de donnéess du match à  jouer

   \param --
   \return --
*/
void CMatch::Initialise(void)
{
//     _led1 = true;_led2 = false;_led3 = false;_led4 = false;wait(1);
// _led1 = false;_led2 = true;_led3 = false;_led4 = false;wait(1);
//  _led1 = false;_led2 = false;_led3 = true;_led4 = false;wait(1);
//   _led1 = false;_led2 = false;_led3 = false;_led4 = true;wait(1);
//   _led1 = false;_led2 = false;_led3 = false;_led4 = false;wait(1);
	
    //m_iaSCI=m_ia->getDefaultSCI();
    //m_iaSCI_Chariot=m_ia->getSCI_Chariot();
    m_ia->setTimer(&m_timer_sct);
    m_ia->init();


    m_distance_mem=0;
    m_teta_mem=0;

    m_x_pos_hold=0;
    m_y_pos_hold=0;
    m_teta_pos_hold=0;

    m_duree = 0;
    m_couleur_equipe = 1;
    m_dde_test_actionneurs = 0;
    m_choix_strategie = 0;
    m_convergence_old=0;
    m_convergence_rapide_old=0;
    m_tirette_old=0;
    m_convergence_rack_old=0;
    m_convergence_rack_conf=0;

    m_obstacleDetecte=0;
    m_obstacle_AVG=Application.m_capteurs.m_telemetres.m_distance[0];
    m_obstacle_ARD=Application.m_capteurs.m_telemetres.m_distance[1];
    m_obstacle_ARG=Application.m_capteurs.m_telemetres.m_distance[2];
    m_obstacle_AVD=Application.m_capteurs.m_telemetres.m_distance[3];

   // _led1 = 0;
    _led2 = 0;
    _led3 = 0;
    _led4 = 0;
    m_ia->enter();
}
	
//___________________________________________________________________________
 /*!
   \brief Inidique si le match est en cours

   \param --
   \return --
*/
bool CMatch::isMatchEnCours()
{
    return (m_duree >=0.02) && (m_duree < 89.92);
}

//___________________________________________________________________________
 /*!
   \brief Inidique si le match est terminé

   \param --
   \return --
*/
bool CMatch::isMatchTermine()
{
    return (m_duree >= 89.92);
}


//___________________________________________________________________________
 /*!
   \brief Execute un pas de calcul du match

   \param --
   \return --
*/
void CMatch::step(void)
{
    IA::DefaultSCI *m_iaSCI = m_ia->getDefaultSCI();
    IA::SCI_Chariot *m_iaSCI_Chariot = m_ia->getSCI_Chariot();
    // ___________________________
    // Recopie les valeurs de l'environnement vers les entrées du modèle
	//Pour binariser le capteur de depression
		if (Application.m_capteurs.m_b_Eana1>=0.55)
            m_iaSCI->set_iN_Depression(true);
		else
            m_iaSCI->set_iN_Depression(false);
	//m_iaSCI->set_iN_Depression(Application.m_capteurs.m_b_Eana1);
	
    //____________________________
    //Variables de l'Ecran ou du switch

    if(Application.m_capteurs.m_b_Etor5==1)//jaune
    	m_couleur_equipe=1;
    else //bleu
		m_couleur_equipe=0;
    m_iaSCI->set_iN_Couleur(m_couleur_equipe);

    //____________________________
    //capteurs US
	//pour les obstacles on ne passe plus un booleen a la strategie mais la distance
    m_obstacle_AVG=Application.m_capteurs.m_telemetres.m_distance[0];
    m_obstacle_ARD=Application.m_capteurs.m_telemetres.m_distance[1];
    m_obstacle_ARG=Application.m_capteurs.m_telemetres.m_distance[2];
    m_obstacle_AVD=Application.m_capteurs.m_telemetres.m_distance[3];

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
	//Capteurs TOR
    //m_b_Etor1==1 => tirette enlevee

    if((Application.m_capteurs.m_b_Etor1==1)&&(m_tirette_old==0))
    {
        m_iaSCI->raise_eV_Tirette();
        m_tirette_old=1;
    }


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

    m_convergence_rack_conf=((Application.m_asservissement_chariot.etat_asser_chariot==2)? 1:0);
    if (frontMontant(m_convergence_rack_old,m_convergence_rack_conf))
            m_iaSCI->raise_eV_ConvergenceChariot();
    m_convergence_rack_old=m_convergence_rack_conf;
	
	//Variables de l'asservissement chariot
	m_iaSCI_Chariot->set_isReady(((Application.m_asservissement_chariot.etat_recalage_butee==3)? true:false));
	m_iaSCI_Chariot->set_isConv(((Application.m_asservissement_chariot.etat_asser_chariot==2)? true:false));

	//TODO:
	//diag de blocage, pour l'instant on claque les tempo

	// ___________________________ 
    //Appel de la strategie du modele
    m_timer_sct.updateActiveTimer(m_ia, MODEL_REFRESH_PERIOD);   // Pour la gestion du temps dans le modèle (instructions "after" et "every")
    m_ia->runCycle();

	
	//SORTIES de MODELE
    //m_obstacleDetecte=ModeleRobot_Y.OUT_isObstacle;

	// ___________________________ 
	// Divers
    m_duree = m_iaSCI->get_tempsMatch() * 0.02;    // m_match.m_duree est en nombre de passage dans la boucle de 20msec
	
	// Asservissement
	//Application.m_asservissement.CalculsMouvementsRobots();
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

/*!
 * \brief CMatch::frontMontant fonction statique de détection de front montant
 * \param prec_value
 * \param value
 * \return
 */
bool CMatch::frontMontant(float prec_value, float value)
{
    bool b_Up=false;
    if(value>prec_value) b_Up=true;
    return b_Up;
}

/*!
 * \brief CMatch::isObstacle Stratégie de détection d'obstacle. Si la distance séparant le robot de l'objet détecté
 * est inférieure à  un seuil un flag est levé. TODO: rendre le seuil dépendant de la vitesse
 * \param x
 * \param y
 * \param teta
 * \param speed
 * \param sens
 * \return
 */
int CMatch::isObstacle(float x, float y, float teta, float speed, float sens)
{
    //calibration
    //TODO: a remplacer par une carto
    float seuilDistance=14.5; //en cm
    int detection=0;

    if (sens>0) //marche avant
        ((m_obstacle_AVD<=seuilDistance)||(m_obstacle_AVG<=seuilDistance))? detection=1:detection=0;
    else //marche arrière
        ((m_obstacle_ARD<=seuilDistance)||(m_obstacle_ARG<=seuilDistance))? detection=1:detection=0;
    //on retire les alertes si détection trop proche de la bordure
    /*if ((((x>100)||(x<-100))||((y>300)||(y<-30)))&&(detection==1))
        detection=0;*/

    return detection;
}

/*!
 * \brief IA::SCI_Asser_OCB::Manuel implémentation du callback du modèle pour le mouvement manuel
 * \param mot_gauche
 * \param mot_droit
 */
void IA::SCI_Asser_OCB::Manuel(sc_real mot_gauche, sc_real mot_droit){
    Application.m_match.m_ia->getDefaultSCI()->set_countTimeMvt(0);
    Application.m_asservissement.CommandeManuelle(mot_gauche, mot_droit);
}

/*!
 * \brief IA::SCI_Asser_OCB::XYTeta implémentation du callback du modèle pour le mouvement XYTeta
 * \param x
 * \param y
 * \param teta
 */
void IA::SCI_Asser_OCB::XYTeta(sc_real x, sc_real y, sc_real teta){
    Application.m_match.m_ia->getDefaultSCI()->set_countTimeMvt(0);
    Application.m_asservissement.CommandeMouvementXY_TETA(x,y,teta);
    Application.m_x_debug=x;
    Application.m_y_debug=y;
    Application.m_teta_debug=teta;
}

/*!
 * \brief IA::SCI_Asser_OCB::DistanceAngle implémentation du callback du modèle pour le mouvement distance-angle
 * \param distance
 * \param angle
 */
void IA::SCI_Asser_OCB::DistanceAngle(sc_real distance, sc_real angle){
    //si on donne exactement le même ordre successivement c'est a priori un historique réentrant
    //on parcourt dnc la distance restante (l'angle n'est pas cumulatif)
    float distance_restante=distance;
    if ((Application.m_match.m_distance_mem==distance)&&(Application.m_match.m_teta_mem==angle))
    {
        //calcul de la distance restante
        distance_restante=sqrt(SQUARE(Application.m_match.m_x_pos_hold-Application.m_asservissement.X_robot)
                               +SQUARE(Application.m_match.m_y_pos_hold-Application.m_asservissement.Y_robot));
        Application.m_match.m_ia->getDefaultSCI()->set_countTimeMvt(0);
        Application.m_asservissement.CommandeMouvementDistanceAngle(distance_restante, angle);
        //on ne rememorise pas les ordres
    }
    else
    {
        Application.m_match.m_ia->getDefaultSCI()->set_countTimeMvt(0);
        Application.m_asservissement.CommandeMouvementDistanceAngle(distance, angle);
        Application.m_match.m_distance_mem=distance;
        Application.m_match.m_teta_mem=angle;
    }
}

/*!
 * \brief IA::SCI_Asser_OCB::XY implémentation du callback du modèle pour le mouvement XY
 * \param x
 * \param y
 */
void IA::SCI_Asser_OCB::XY(sc_real x, sc_real y){
    Application.m_match.m_ia->getDefaultSCI()->set_countTimeMvt(0);
    Application.m_asservissement.CommandeMouvementXY(x, y);
    Application.m_x_debug=x;
    Application.m_y_debug=y;

}

/*!
 * \brief IA::SCI_Asser_OCB::Vitesse implémentation du callback du modèle pour régler la vitesse de déplacement
 * \param speedDist
 * \param speedRot
 */
void IA::SCI_Asser_OCB::Vitesse(sc_real speedDist, sc_real speedRot){
    Application.m_asservissement.CommandeVitesseMouvement(speedDist,speedRot);
}

/*!
 * \brief IA::SCI_Asser_OCB::setPosition implémentation du callback du modèle pour recaler les coordonnées du robot
 * \param x
 * \param y
 * \param teta
 */
void IA::SCI_Asser_OCB::setPosition(sc_real x, sc_real y, sc_real teta){
    Application.m_asservissement.setPosition_XYTeta(x, y, teta);
}

void IA::SCI_Asser_OCB::setSportivite(sc_real idx){
    Application.m_asservissement.setIndiceSportivite(idx);
}

/*!
 * \brief IA::SCI_Servo_OCB::setPos implémentation du callback du modèle pour contrà´ler les servos
 * \param idServo
 * \param value
 */
void IA::SCI_Servo_OCB::setPos(sc_integer idServo, sc_integer value){
    Application.m_servos_sd20.CommandePositionVitesse(idServo, value,0);
}

/*!
 * \brief IA::SCI_Servo_OCB::setPos implémentation du callback du modèle pour contrà´ler les servos
 * \param idServo
 * \param value
 */
void IA::SCI_Ax_OCB::setPos(sc_integer idServo, sc_integer value){
    Application.m_servos_ax.setPosition(idServo, value);
}

void IA::SCI_Ax_OCB::setSpd(sc_integer idServo, sc_integer spd){
    Application.m_servos_ax.setSpeed(idServo,spd);
}

/*!
 * \brief IA::SCI_Servo_OCB::setRelache implémentation du callback du modèle pour le temps de maintient des servos
 * \param idServo
 * \param time_ms
 */
void IA::SCI_Servo_OCB::setRelache(sc_integer idServo, sc_real time_ms){
    if (time_ms==0)
        Application.m_servos_sd20.setDureeAvantRelache(idServo, RELACHE_SERVO_OFF);
    else
        Application.m_servos_sd20.setDureeAvantRelache(idServo,time_ms);
}

/*!
 * \brief IA::SCI_Moteur_OCB::setPWM implémentation du callback du modèle pour la vitesse des moteurs
 * WARNING: à  appeler en oncycle, sinon on ne verra pas le capteur de fin de course de l'ascenseur
 * \param idMot
 * \param pwm
 */
void IA::SCI_Moteur_OCB::setPWM(sc_integer idMot, sc_real pwm){
    //ALERTE: codé en dur
    //si l'ascenseur atteint son capteur de fin de course et que la consigne est négative
    //on coupe la commande (valeur écrasée)
    /*if (idMot==Application.m_match.m_iaSCI->get_mOTEUR_ASCENSEUR())
        if ((Application.m_capteurs.m_b_Etor2<=0)&& (pwm<0))
            Application.m_moteurs.CommandeVitesse(idMot, 0);
        else
            Application.m_moteurs.CommandeVitesse(idMot, pwm);
    else*/
        Application.m_moteurs.CommandeVitesse(idMot, pwm);
}

/*!
 * \brief IA::SCI_Capteur_OCB::resetCodeur implémentation du callback du modèle pour remettre à  zero les compteurs des codeurs
 * \param idCodeur
 * \param value
 */
void IA::SCI_Capteur_OCB::resetCodeur(sc_integer idCodeur, sc_integer value){
    Application.m_capteurs.RAZ_PositionCodeur(idCodeur,0);
}

/*!
 * \brief IA::SCI_Ihm_OCB::setLed implémentation du callback du modèle pour contrà´ler les led
 * \param idLed
 * \param onoff
 */
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

/*!
 * \brief IA::SCI_Chariot_OCB::init implémentation du callback du modèle pour l'init de l'ascenseur
 * WARNING: à  appeler en oncycle, sinon on ne verra pas le capteur de fin de course de l'ascenseur
 */
void IA::SCI_Chariot_OCB::init()
{
    /*//on atteint le point bas on coupe tout de suite le moteur et on prévient la stratégie, via l'état ascenseur
    int idMot=Application.m_match.m_iaSCI->get_mOTEUR_ASCENSEUR();

    if (Application.m_capteurs.m_b_Etor2<=0)
    {
        Application.m_moteurs.CommandeVitesse(idMot, 0);
        Application.m_capteurs.RAZ_PositionCodeur(Application.m_match.m_iaSCI->get_cODEUR_ASCENSEUR(),0);
        Application.m_match.m_iaSCI_Chariot->set_isReady(true);
    }
    else
    {
        Application.m_moteurs.CommandeVitesse(idMot, -60.0);
        Application.m_match.m_iaSCI_Chariot->set_isReady(false);
    }*/
    //Application.m_match.m_iaSCI_Chariot->set_isReady(true);
	Application.m_asservissement_chariot.Recal_Chariot();
}

/*!
 * \brief IA::SCI_Chariot_OCB::goTo_ID implémentation du callback du modèle pour le déplacement de l'ascenseur
 * WARNING: à  appeler en oncycle, sinon on ne verra pas le capteur de fin de course de l'ascenseur
 * \param position
 */
void IA::SCI_Chariot_OCB::setPos(sc_integer position)
{
	Application.m_asservissement_chariot.setConsigne(position);
	/*//on atteint le point bas on coupe tout de suite le moteur et on prévient la stratégie, via l'état ascenseur
    int idMot=Application.m_match.m_iaSCI->get_mOTEUR_ASCENSEUR();
    int idCodeur=Application.m_match.m_iaSCI->get_cODEUR_ASCENSEUR();
    float positionActuelle=Application.m_capteurs.m_CumulCodeurPosition1;
    int delta=15;

    //pour rester générique choix du codeur ascenseur
    switch(idCodeur){
        case CODEUR_1:
            positionActuelle=Application.m_capteurs.m_CumulCodeurPosition1;
            break;
        case CODEUR_2:
            positionActuelle=Application.m_capteurs.m_CumulCodeurPosition2;
            break;
        case CODEUR_3:
            positionActuelle=Application.m_capteurs.m_CumulCodeurPosition3;
            break;
        case CODEUR_4:
            positionActuelle=Application.m_capteurs.m_CumulCodeurPosition4;
            break;
        default:
            positionActuelle=Application.m_capteurs.m_CumulCodeurPosition1;
            break;
    }

    if (Application.m_capteurs.m_b_Etor2<=0)//TODO rajouter la butée haute
    {
        //butée atteinte, ce n'est pas normal on coupe tout
        Application.m_moteurs.CommandeVitesse(idMot, 0);
        Application.m_capteurs.RAZ_PositionCodeur(Application.m_match.m_iaSCI->get_cODEUR_ASCENSEUR(),0);
        Application.m_match.m_iaSCI_Chariot->set_isReady(true);
    }
    else
    {
        if(positionActuelle<(position-delta))
        {
            Application.m_moteurs.CommandeVitesse(idMot, 80.0);
            Application.m_match.m_iaSCI_Chariot->set_isReady(false);
        }
        else if(positionActuelle>(position+delta))
        {
            Application.m_moteurs.CommandeVitesse(idMot, -80.0);
            Application.m_match.m_iaSCI_Chariot->set_isReady(false);
        }
        else if((positionActuelle>(position-delta))&&(positionActuelle<(position+delta)))
        {
            Application.m_moteurs.CommandeVitesse(idMot,0);
            Application.m_match.m_iaSCI_Chariot->set_isReady(true);
        }
    }*/
    Application.m_match.m_ia->getSCI_Chariot()->set_isReady(true);
}

