// ________________________________________________
// !! ATTENTION !!
// Ce code est commun aux projets du robot réel et simulation
// Il ne doit pas y avoir de code spécifique MBED
//  ou d'appel à une classe non gérée par une couche d'abstraction
//  au risque de ne plus pouvoir tourner en simulation

#include "ia.h"
#include "CGlobale.h"
#include "ConfigSpecifiqueCoupe.h"
#include "math.h"

IA::IA()
    : IABase()
{
    m_sm_liste[m_state_machine_count++] = &m_sm_autotest;
    m_sm_liste[m_state_machine_count++] = &m_sm_chasse_neige;
    m_sm_liste[m_state_machine_count++] = &m_sm_prendre_plantes_pres_zone_depart;
    m_sm_liste[m_state_machine_count++] = &m_sm_prendre_pots_pres_zone_depart;
    m_sm_liste[m_state_machine_count++] = &m_sm_ramener_pot_zone_pami;
    m_sm_liste[m_state_machine_count++] = &m_sm_tourner_panneaux_solaires;
    m_sm_liste[m_state_machine_count++] = &m_sauvegarde_plantes;
    m_sm_liste[m_state_machine_count++] = &m_sm_retour_zone_depart;
}

// ________________________________________________
void IA::init()
{
    m_inputs_interface.TE_Modele = PERIODE_APPEL_MODELIA;
    m_datas_interface.init();
    m_inputs_interface.init();
    m_outputs_interface.init();
    for (int i=0; i<m_state_machine_count; i++) {
        if (m_sm_liste[i]) {
            m_sm_liste[i]->init(this);
        }
    }
    setMaxScores();
    //Valeur par défaut au démarrage de la cmde de la trame générique
    //utile par exemple si on veut faire de la reconnaissance vidéo pendant l'installation du robot
    //avant le début du match
    m_datas_interface.m_tx_code_cmd=DMDE_DISTANCE_BALISE;
    m_sm_main.start();
}

// ________________________________________________
void IA::match_started()
{
    Application.m_power_electrobot.setOutput((dsPicPowerElectrobotBase::tSwitchOutput)DECO_LED_CRLG, true);
    m_outputs_interface.setPosition_XYTeta_sym(0, 0, 0);
}

// ________________________________________________
void IA::match_finished()
{
    Application.m_power_electrobot.setOutput((dsPicPowerElectrobotBase::tSwitchOutput)DECO_LED_CRLG, false);
}

// ________________________________________________
// Définit l'ordre d'exécution des "main missions"
// sm_xxxx.setPrioriteExecution(ordre++);
//      Active la mission xxx
//      Lui fixe une priorité d'exécution (0 étant la priorité la plus haute)
void IA::setStrategie(unsigned char strategie)
{
    int ordre = 0;
    resetAllSMPriority();
    disableAllSM(); // Désactive toutes les SM par défaut (elles seront activées une par une avec la priorité associée en fonction de la stratégie)
    switch (strategie) {
    // ________________________
    case STRATEGIE_HOMOLO1:
        m_datas_interface.choix_algo_next_mission = ALGO_PERTINENT_MISSION_CHOIX_PRIORITE;
        m_datas_interface.evit_inhibe_obstacle=false;
        m_datas_interface.evit_choix_strategie= SM_DatasInterface::STRATEGIE_EVITEMENT_ATTENDRE;
        Application.m_detection_obstacles.setSeuilDetectionObstacle(SEUIL_DETECTION_US); //par défaut seuil de détection avec les capteurs US en backup
        m_datas_interface.evit_nombre_max_tentatives=1;

        m_sm_chasse_neige.setEnabled(false);
        m_sm_retour_zone_depart.setEnabled(false);
        m_sm_prendre_plantes_pres_zone_depart.setEnabled(true);
        m_sm_prendre_pots_pres_zone_depart.setEnabled(true);
        m_sm_ramener_pot_zone_pami.setEnabled(false);
        m_sm_tourner_panneaux_solaires.setEnabled(false);
        m_sauvegarde_plantes.setEnabled(false);

        m_sm_prendre_plantes_pres_zone_depart.setPrioriteExecution(ordre++);
        m_sm_prendre_pots_pres_zone_depart.setPrioriteExecution(ordre++);
        //m_sm_retour_zone_depart.setPrioriteExecution(ordre++);

        break;
    // ________________________
    case STRATEGIE_HOMOLO2:
        m_datas_interface.choix_algo_next_mission = ALGO_PERTINENT_MISSION_CHOIX_PRIORITE;
        m_datas_interface.evit_choix_strategie= SM_DatasInterface::STRATEGIE_EVITEMENT_ATTENDRE;
        Application.m_detection_obstacles.setSeuilDetectionObstacle(SEUIL_DETECTION_US); //par défaut seuil de détection avec les capteurs US en backup
        m_datas_interface.evit_nombre_max_tentatives=1;

        m_sm_prendre_plantes_pres_zone_depart.setEnabled(false);
        m_sm_prendre_pots_pres_zone_depart.setEnabled(false);
        m_sm_ramener_pot_zone_pami.setEnabled(false);
        m_sm_tourner_panneaux_solaires.setEnabled(false);
        m_sauvegarde_plantes.setEnabled(false);

        m_sm_chasse_neige.setPrioriteExecution(ordre++);
        m_sm_retour_zone_depart.setPrioriteExecution(ordre++);

        break;
    // ________________________  A VERIFIER
    case STRATEGIE_PAR_DEFAUT:
    default:
        m_datas_interface.choix_algo_next_mission = ALGO_PERTINENT_MISSION_CHOIX_PRIORITE;
        m_datas_interface.evit_choix_strategie= SM_DatasInterface::STRATEGIE_EVITEMENT_ATTENDRE;
        Application.m_detection_obstacles.setSeuilDetectionObstacle(SEUIL_DETECTION_US); //par défaut seuil de détection avec les capteurs US en backup
        m_datas_interface.evit_nombre_max_tentatives=1;

        m_sm_prendre_plantes_pres_zone_depart.setEnabled(false);
        m_sm_prendre_pots_pres_zone_depart.setEnabled(false);
        m_sm_ramener_pot_zone_pami.setEnabled(false);
        m_sm_tourner_panneaux_solaires.setEnabled(false);
        m_sauvegarde_plantes.setEnabled(false);

        m_sm_chasse_neige.setPrioriteExecution(ordre++);
        m_sm_retour_zone_depart.setPrioriteExecution(ordre++);
        break;
    }
    m_datas_interface.ChoixStrategieMatch = strategie;
}

// ________________________________________________
void IA::setMaxScores()
{
    // TODO : valeurs des scores max fixées au pif.
    // Mettre les vraies valeurs
    m_sm_prendre_plantes_pres_zone_depart.setScoreMax(5);
    m_sm_prendre_pots_pres_zone_depart.setScoreMax(5);
    m_sm_ramener_pot_zone_pami.setScoreMax(5);
    m_sm_tourner_panneaux_solaires.setScoreMax(5);
    m_sauvegarde_plantes.setScoreMax(5);
    m_sm_chasse_neige.setScoreMax(5);
    m_sm_retour_zone_depart.setScoreMax(5);
}

// ________________________________________________
// TODO : à voir sur le long terme si la couche de recopie des donées
// externes dans m_inputs_interface.xxxx est toujours nécessaire
// ou si le modèle ne peut pas utiliser directement Application.m_xxxxx.yyyy
void IA::step()
{
    m_inputs_interface.Tirette             = Application.m_capteurs.getTirette();

    //commandes ou traitements venant de LABOTBOX via la trame générique
    switch(m_datas_interface.m_rx_code_cmd)
    {
        case CMDE_DISTANCE_BALISE:
            m_inputs_interface.m_distance_balise1=m_datas_interface.m_rx_value_01;
            m_inputs_interface.m_distance_balise2=m_datas_interface.m_rx_value_02;
            break;
        case CMDE_VIDEO_NORD_SUD:
            m_inputs_interface.m_nord=m_datas_interface.m_rx_value_03;
            m_inputs_interface.m_sud=m_datas_interface.m_rx_value_04;
            break;
        default: break;
    }

    m_inputs_interface.Convergence         = Application.m_asservissement.convergence_conf;
    m_inputs_interface.Convergence_rapide  = Application.m_asservissement.convergence_rapide;
    m_inputs_interface.ConvergenceRack     = Application.m_asservissement_chariot.isConverged();
    m_inputs_interface.X_robot             = Application.m_asservissement.X_robot;
    m_inputs_interface.Y_robot             = Application.m_asservissement.Y_robot;
    m_inputs_interface.angle_robot         = Application.m_asservissement.angle_robot;
    m_inputs_interface.ConvergenceKmar     = Application.m_kmar.isFinished();

    // Coordonnées du robot dans le repère absolue terrain (pour que ce soit valable pour les 2 couleurs d'équipe)
    if (m_datas_interface.couleur_equipe == SM_DatasInterface::EQUIPE_COULEUR_1) {
        m_inputs_interface.X_robot_terrain     = X_ROBOT_TERRAIN_INIT_COULEUR_1 + Application.m_asservissement.X_robot;
        m_inputs_interface.Y_robot_terrain     = Y_ROBOT_TERRAIN_INIT_COULEUR_1 + Application.m_asservissement.Y_robot;
        m_inputs_interface.angle_robot_terrain = Application.m_asservissement.angle_robot - ANGLE_ROBOT_TERRAIN_INIT_COULEUR_1;
    }
    else {
        m_inputs_interface.X_robot_terrain     = X_ROBOT_TERRAIN_INIT_COULEUR_2 - Application.m_asservissement.X_robot;
        m_inputs_interface.Y_robot_terrain     = Y_ROBOT_TERRAIN_INIT_COULEUR_2 - Application.m_asservissement.Y_robot;
        m_inputs_interface.angle_robot_terrain = Application.m_asservissement.angle_robot - ANGLE_ROBOT_TERRAIN_INIT_COULEUR_2;
        // Ramène l'angle entre [-Pi;Pi]
        if (m_inputs_interface.angle_robot_terrain > 3.14)   m_inputs_interface.angle_robot_terrain = m_inputs_interface.angle_robot_terrain - 6.28;
        if (m_inputs_interface.angle_robot_terrain <= -3.14) m_inputs_interface.angle_robot_terrain = m_inputs_interface.angle_robot_terrain + 6.28;
    }

    // Télémètres et obstacles
    m_inputs_interface.Telemetre_AVG       = Application.m_telemetres.getDistanceAVG();
    m_inputs_interface.Telemetre_AVD       = Application.m_telemetres.getDistanceAVD();
    m_inputs_interface.Telemetre_ARG       = Application.m_telemetres.getDistanceARG();
    m_inputs_interface.Telemetre_ARD       = Application.m_telemetres.getDistanceARD();
    m_inputs_interface.Telemetre_ARGCentre = Application.m_telemetres.getDistanceARGCentre();
    m_inputs_interface.Telemetre_ARDCentre = Application.m_telemetres.getDistanceARDCentre();

	//ajouter un watchdog sur l'état du LIDAR pour assurer le backup sur les capteurs US afin d'avoir toujours
	//une solution d'évitement, idéalement l'intégrité des données est vérifiée au niveau raspbberry
    if(m_inputs_interface.m_lidar_status==LidarUtils::LIDAR_OK)
	{
		//TODO:
		//vérifier le rafraichissement des données
		//vérifier l'intégrité des données
    }
    m_datas_interface.nombre_obstacles_presents = 0;
    m_datas_interface.angle_premier_obstacle_detecte = 0;
    m_datas_interface.distance_premier_obstacle_detecte = LidarUtils::NO_OBSTACLE;

	//Traitements Lidar pour évitement
    if(m_inputs_interface.m_lidar_status==LidarUtils::LIDAR_OK)
	{
        Application.m_detection_obstacles.setSeuilDetectionObstacle(SEUIL_DETECTION_LIDAR);

        //récupération de données utiles pour l'évitement
		m_inputs_interface.obstacleDetecte=false;
        bool isOutOfField=false;
		float X_detected=0.;
		float Y_detected=0.;
        float _teta=0.;

        //Reconstitution d'un lidar 360 avec les capteurs US
        double NeoLidar[2][LidarUtils::NBRE_MAX_OBSTACLES+4];
        for(int i=0;i<LidarUtils::NBRE_MAX_OBSTACLES;i++)
        {
            NeoLidar[0][i]=m_inputs_interface.m_lidar_obstacles[i].distance;
            NeoLidar[1][i]=m_inputs_interface.m_lidar_obstacles[i].angle-90;
        }
        NeoLidar[0][LidarUtils::NBRE_MAX_OBSTACLES]=m_inputs_interface.Telemetre_ARD*10;
        NeoLidar[1][LidarUtils::NBRE_MAX_OBSTACLES]=-153;
        /*NeoLidar[0][LidarUtils::NBRE_MAX_OBSTACLES+1]=m_inputs_interface.Telemetre_ARDCentre*10;
        NeoLidar[1][LidarUtils::NBRE_MAX_OBSTACLES+1]=-171;
        NeoLidar[0][LidarUtils::NBRE_MAX_OBSTACLES+2]=m_inputs_interface.Telemetre_ARGCentre*10;
        NeoLidar[1][LidarUtils::NBRE_MAX_OBSTACLES+2]=171;*/
        NeoLidar[0][LidarUtils::NBRE_MAX_OBSTACLES+1]=LidarUtils::NO_OBSTACLE;
        NeoLidar[1][LidarUtils::NBRE_MAX_OBSTACLES+1]=-171;
        NeoLidar[0][LidarUtils::NBRE_MAX_OBSTACLES+2]=LidarUtils::NO_OBSTACLE;
        NeoLidar[1][LidarUtils::NBRE_MAX_OBSTACLES+2]=171;
        NeoLidar[0][LidarUtils::NBRE_MAX_OBSTACLES+3]=m_inputs_interface.Telemetre_ARG*10;
        NeoLidar[1][LidarUtils::NBRE_MAX_OBSTACLES+3]=153;

        //on parcourt l'ensemble des points du Lidar 360
        for(int i=0;i<(LidarUtils::NBRE_MAX_OBSTACLES+4);i++)
		{
            //Si le point est trop lointain on ne traite pas
            if(NeoLidar[0][i]!=LidarUtils::NO_OBSTACLE)
            {
                //angle de l'obstacle par rapport à l'axe du robot (converti en radian)
                float _Phi=CDetectionObstaclesBase::modulo_pi(M_PI*NeoLidar[1][i]/180);	// [degres signe / -180;+180]

                //distance de l'obstacle
                int _D=(NeoLidar[0][i])/10;	// [mm] converti en [cm]
                //angle du robot
                _teta=m_inputs_interface.angle_robot ;

                //#	coordonnées en X,Y des points détectés
                if (m_datas_interface.couleur_equipe == SM_DatasInterface::EQUIPE_COULEUR_1)
                {
                    X_detected = m_inputs_interface.X_robot_terrain+ _D*cos(_teta+_Phi);
                    Y_detected = m_inputs_interface.Y_robot_terrain+ _D*sin(_teta+_Phi);
                }
                else
                {
                    X_detected = m_inputs_interface.X_robot_terrain+ _D*cos(_teta+_Phi+M_PI);
                    Y_detected = m_inputs_interface.Y_robot_terrain+ _D*sin(_teta+_Phi+M_PI);
                }


                //est-ce que le point détecté par le lidar est hors du terrain
                isOutOfField=((X_detected<=10.) || (X_detected>=290.) || (Y_detected<=10.) || (Y_detected>=190.));

                //# D et Phi sur la trajectoire du robot en excluant les points détectés hors du terrain (plus besoin d'inhiber la détection)
                if((!isOutOfField) && (_D>0) && (_D<50))
                {
                    if (Application.m_detection_obstacles.isObstacleLIDAR(_D, _Phi,35))
                    {
                        m_inputs_interface.obstacleDetecte=true;
                        m_datas_interface.nombre_obstacles_presents++;
                        m_inputs_interface.obstacle_AVG= ((_Phi<=(M_PI/2)) && (_Phi>=0));
                        m_inputs_interface.obstacle_AVD= ((_Phi>=(-M_PI/2)) && (_Phi<0));
                        m_inputs_interface.obstacle_ARG= ((_Phi>(M_PI/2))&&(_Phi<=(M_PI)));
                        m_inputs_interface.obstacle_ARD= ((_Phi<(-M_PI/2))&&(_Phi>(-M_PI)));

                        //afin de réutiliser l'évitement existant
                        // Permet de reconstituer une valeur entre 0 et 15 représentant toutes les situations de blocage
                        m_datas_interface.evit_detection_obstacle_bitfield =
                                (m_inputs_interface.obstacle_ARG << 3) |
                                (m_inputs_interface.obstacle_ARD << 2) |
                                (m_inputs_interface.obstacle_AVG << 1) |
                                (m_inputs_interface.obstacle_AVD << 0);
                    }
                }
            }
			isOutOfField=false;
		}
        m_datas_interface.angle_premier_obstacle_detecte = NeoLidar[1][0];
        m_datas_interface.distance_premier_obstacle_detecte = m_inputs_interface.m_lidar_obstacles[0].distance;//NeoLidar[0][0];
		//must have récupérer la position des balises fixes et vérifier le besoin ou non d'un recalage ;-)
    }//fin Traitement LIDAR pour évitement
	//Traitements capteurs US pour évitement
	else
	{
        Application.m_detection_obstacles.setSeuilDetectionObstacle(SEUIL_DETECTION_US);

        //    inhibition forcée de la détection d'obstacle
		if (m_datas_interface.evit_inhibe_obstacle) {
			Application.m_detection_obstacles.inhibeDetection(true);
		}
		//    Tient compte de la position du robot sur le terrain pour inhiber les obstacles
		//      -> Trop proche des bordures -> inhibe la détection
		//      Inhibe soit les capteurs AV soit les capteurs AR en fonction de l'angle robot et de la proximité bordure si l'obstacle est détecté en dehors du terrain
		else if (m_datas_interface.evit_force_obstacle == false) {
			m_datas_interface.proximite_bordure_Xdroite = m_inputs_interface.X_robot_terrain > X_MAX_INTERDIT_DETECTION;
			m_datas_interface.proximite_bordure_Xgauche = m_inputs_interface.X_robot_terrain < X_MIN_INTERDIT_DETECTION;
			m_datas_interface.proximite_bordure_Ybasse = m_inputs_interface.Y_robot_terrain < Y_MIN_INTERDIT_DETECTION;
			m_datas_interface.proximite_bordure_Yhaute = m_inputs_interface.Y_robot_terrain > Y_MAX_INTERDIT_DETECTION;
			m_datas_interface.inhibe_detection_AV = false;
			m_datas_interface.inhibe_detection_AR = false;

			if (m_datas_interface.proximite_bordure_Ybasse) {
				if ( (m_inputs_interface.angle_robot_terrain >= -3.14) && (m_inputs_interface.angle_robot_terrain <= 0) ) {
				   m_datas_interface.inhibe_detection_AV = true;
				}
				if ( (m_inputs_interface.angle_robot_terrain >= 0.) && (m_inputs_interface.angle_robot_terrain <= 3.14) ) {
				   m_datas_interface.inhibe_detection_AR = true;
				}
			}
			if (m_datas_interface.proximite_bordure_Yhaute) {
				if ( (m_inputs_interface.angle_robot_terrain >= -3.14) && (m_inputs_interface.angle_robot_terrain <= 0) ) {
				   m_datas_interface.inhibe_detection_AR = true;
				}
				if ( (m_inputs_interface.angle_robot_terrain >= 0.) && (m_inputs_interface.angle_robot_terrain <= 3.14) ) {
				   m_datas_interface.inhibe_detection_AV = true;
				}
			}
			if (m_datas_interface.proximite_bordure_Xgauche) {
				if (    ((m_inputs_interface.angle_robot_terrain >= 1.57) && (m_inputs_interface.angle_robot_terrain <= 3.14) )
					 || ((m_inputs_interface.angle_robot_terrain <= -1.57) && (m_inputs_interface.angle_robot_terrain >= -3.14))
				   ) {
				   m_datas_interface.inhibe_detection_AV = true;
				}
				if (    ((m_inputs_interface.angle_robot_terrain >= 0) && (m_inputs_interface.angle_robot_terrain <= 1.57) )
					 || ((m_inputs_interface.angle_robot_terrain >= -1.57) && (m_inputs_interface.angle_robot_terrain <= 0.))
				   ) {
				   m_datas_interface.inhibe_detection_AR = true;
				}
			}
			if (m_datas_interface.proximite_bordure_Xdroite) {
				if (    ((m_inputs_interface.angle_robot_terrain >= 1.57) && (m_inputs_interface.angle_robot_terrain <= 3.14) )
					 || ((m_inputs_interface.angle_robot_terrain <= -1.57) && (m_inputs_interface.angle_robot_terrain >= -3.14))
				   ) {
				   m_datas_interface.inhibe_detection_AR = true;
				}
				if (    ((m_inputs_interface.angle_robot_terrain >= 0) && (m_inputs_interface.angle_robot_terrain <= 1.57) )
					 || ((m_inputs_interface.angle_robot_terrain >= -1.57) && (m_inputs_interface.angle_robot_terrain <= 0.))
				   ) {
				   m_datas_interface.inhibe_detection_AV = true;
				}
			}
			Application.m_detection_obstacles.inhibeDetectionAV(m_datas_interface.inhibe_detection_AV);
			Application.m_detection_obstacles.inhibeDetectionAR(m_datas_interface.inhibe_detection_AR);
		}
		else {
			Application.m_detection_obstacles.inhibeDetection(false);
		}

		m_inputs_interface.obstacle_AVG        = Application.m_detection_obstacles.isObstacleAVG();
		m_inputs_interface.obstacle_AVD        = Application.m_detection_obstacles.isObstacleAVD();
        m_inputs_interface.obstacle_ARG        = Application.m_detection_obstacles.isObstacleARG() || Application.m_detection_obstacles.isObstacleARGCentre();
        m_inputs_interface.obstacle_ARD        = Application.m_detection_obstacles.isObstacleARD() || Application.m_detection_obstacles.isObstacleARDCentre();
		m_inputs_interface.obstacleDetecte     = Application.m_detection_obstacles.isObstacle();

		// Permet de reconstituer une valeur entre 0 et 15 représentant toutes les situations de blocage
		m_datas_interface.evit_detection_obstacle_bitfield =
				(m_inputs_interface.obstacle_ARG << 3) |
				(m_inputs_interface.obstacle_ARD << 2) |
				(m_inputs_interface.obstacle_AVG << 1) |
				(m_inputs_interface.obstacle_AVD << 0);
	}//fin Traitements capteurs US pour évitement

    // Mise en forme de données pour le modèle
    m_inputs_interface.FrontM_Convergence = m_inputs_interface.Convergence && !m_inputs_interface.Convergence_old;
    m_inputs_interface.Convergence_old = m_inputs_interface.Convergence;

    m_inputs_interface.FrontM_Convergence_rapide = m_inputs_interface.Convergence_rapide && !m_inputs_interface.Convergence_rapide_old;
    m_inputs_interface.Convergence_rapide_old = m_inputs_interface.Convergence_rapide;

    m_inputs_interface.FrontM_ConvergenceRack = m_inputs_interface.ConvergenceRack && !m_inputs_interface.ConvergenceRack_old;
    m_inputs_interface.ConvergenceRack_old = m_inputs_interface.ConvergenceRack;

    stepAllStateMachines();
}



