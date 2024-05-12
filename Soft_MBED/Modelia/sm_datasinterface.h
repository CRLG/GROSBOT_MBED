#ifndef SM_DATASINTERFACE_H
#define SM_DATASINTERFACE_H

class SM_DatasInterface
{
public:
    typedef enum {
        EQUIPE_COULEUR_1 = 0,
        EQUIPE_COULEUR_2,
    }tCouleurEquipe;

    typedef enum {
        STRATEGIE_EVITEMENT_ATTENDRE = 0,
        STRATEGIE_EVITEMENT_CONTOURNER
    }tChoixStrategieEvitement;

    SM_DatasInterface();

    void init();

    int couleur_equipe;
    bool inverse_consignes_XYTeta;          // Inverse les commandes  XYTeta de mouvements envoyés à l'asserv en fonction de la couleur de l'équipe
    float TempsMatch;
    unsigned char ChoixStrategieMatch;

    int choix_algo_next_mission;

    // Detection d'obstacle
    unsigned char nombre_obstacles_presents;
    signed short angle_premier_obstacle_detecte;
    unsigned short distance_premier_obstacle_detecte;
    unsigned int cpt_filtrage_obstacle_detecte;

    // Stratégie d'évitement d'obstacles
    bool evitementEnCours;
    bool evit_inhibe_obstacle;
    bool evit_force_obstacle;
    unsigned long evit_memo_cde_min;
    unsigned long  evit_memo_cde_max;
    float evit_memo_idx_sportiv;
    float evit_memo_vitesse_avance;
    float evit_memo_vitesse_angle;
    bool evit_memo_force_obstacle;
    int evit_memo_choix_strategie;
    float evit_sens_avant_detection;
    unsigned char evit_nombre_tentatives;
    unsigned char evit_nombre_max_tentatives;
    unsigned short evit_detection_obstacle_bitfield;
    bool evit_strategie_evitement_en_cours;
    signed char evit_sgn_dist_eloigne;
    signed char evit_sgn_angle_pivote;
    signed char evit_sgn_dist_evacue;
    signed char evit_toggle_signe;
    unsigned long evit_debug_etape;
    unsigned char evit_choix_strategie;
    unsigned short evit_seuil_detection_obstacle;
    unsigned char evit_comportement_retour_evitement;

    // Pour l'inhibition de détection des obstacles
    bool proximite_bordure_Xdroite;
    bool proximite_bordure_Xgauche;
    bool proximite_bordure_Ybasse;
    bool proximite_bordure_Yhaute;
    bool inhibe_detection_AV;
    bool inhibe_detection_AR;

    //pour la messagerie générique (utilisé par la caméra entre autre)
    short m_tx_value_01;
    short m_tx_value_02;
    unsigned char m_tx_value_03;
    unsigned char m_tx_value_04;
    unsigned m_tx_code_cmd;

    short m_rx_value_01;
    short m_rx_value_02;
    unsigned char m_rx_value_03;
    unsigned char m_rx_value_04;
    unsigned m_rx_code_cmd;
};

#endif // SM_DATASINTERFACE_H
