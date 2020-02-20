#ifndef SM_DATASINTERFACE_H
#define SM_DATASINTERFACE_H

class SM_DatasInterface
{
public:
    typedef enum {
        EQUIPE_COULEUR_1 = 0,
        EQUIPE_COULEUR_2,
    }tCouleurEquipe;

    SM_DatasInterface();

    void init();

    int CouleurEquipe;
    float TempsMatch;

    int choix_algo_next_mission;

    // Evitement
    bool evitementEnCours;
    bool inhibeObstacle;
    unsigned long evit_memo_cde_min;
    unsigned long  evit_memo_cde_max;
    double evit_memo_idx_sportiv;
    double evit_memo_vitesse_avance;
    double evit_memo_vitesse_angle;
    double evit_memo_force_obstacle;
    double evit_sens_avant_detection;
    unsigned long evit_nombre_tentatives;
    unsigned long evit_nombre_max_tentatives;
    unsigned long evit_detection_obstacle_bitfield;
    bool evit_strategie_evitement_en_cours;
    unsigned long evit_sgn_dist_eloigne;
    unsigned long evit_sgn_angle_pivote;
    unsigned long evit_sgn_dist_evacue;
    unsigned long evit_toggle_signe;
    unsigned long evit_debug_etape;
    unsigned long evit_choix_strategie;
    unsigned long evit_seuil_detection_obstacle;
    unsigned char evit_comportement_retour_evitement;
};

#endif // SM_DATASINTERFACE_H
