// Codes
#include "math.h"
#include "CAsservissementChariot.h"
#include "CGlobale.h"
#include <algorithm>

/*
//etat_recalage_butee
#define NON_FAIT 0
#define EN_COURS 1
#define FAIT 2
#define ECHEC 3
//etat_asser_chariot
#define STOP 0
#define DEPLACEMENT 1
#define CONVERGE 2
*/

//! Constructeur / destructeur
	CAsservissementChariot::CAsservissementChariot(){};
	CAsservissementChariot::~CAsservissementChariot(){};

void CAsservissementChariot::Init(void)
{
	//Input
	codeur_position_chariot=0;		// Registre du codeur en Pas
	position_consigne=0;			// Consigne en Pas pour le moment
	demande_recalage_butee=0;
	demande_stop_chariot=0;

	//Output
	commande_moteur_chariot=0;
    etat_recalage_butee=FAIT; 		// 0 non fait, 1 en cours, 2 fait et OK, 3 Raté(timeout)
	etat_asser_chariot=STOP; //0 stopped, 1 deplacement, 2 converge

	// Variables internes
    butee_haute=0;
    butee_basse=0;
	erreur_position=0;
	vitesse_consigne=0;
	erreur_vitesse=0;
	tempo_conf = 0;
	tempo_time_out = 0;
	codeur_position_chariot_prev = 0;
	saturation = 0;
	terme_integral_prev=0;
	vitesse_chariot=0;
	demande_stop_chariot_prev=0;
	position_consigne_prev=0;

	// Calibrations
	pas_C=70.0; 						//pas par cm
    apprentissage_auto_C = 0;			// Si l'apprentissage n'est pas fait, il se réalise sans demande externe
    vitesse_consigne_recalage_C = 50; 	// Pas par seconde
    seuil_min_blocage_C = 5;			// vitesse de détection blocage
    seuil_tempo_conf_C = 0;				// Nb de Te pour confirmer la mise en butée
	seuil_tempo_time_out_C = 30000;		// Nb de Te pour considerer un echec d'apprentissage
    offset_vitesse_max_C = 0.4;			// gradient de consigne de vitesse / Te

	//Pour l'instant c'est initialise par l'EEPROM
    compensation_zone_morte_dw_C = 30;	// New
    compensation_zone_morte_up_C = 50;	// New
    commande_chariot_max_C = 65;		// Saturation pour la securite ou limiter
    gain_position_vitesse_C = 6.0;		// une Carto serait un must mais pas utile (systeme tres amorti)
	gain_int_C = 0.0;
	gain_prop_C = 0.01;
	seuil_conv_C=35;

}

void CAsservissementChariot::Asser_chariot(void)
{
	//position
	codeur_position_chariot=Application.m_capteurs.m_CumulCodeurPosition3;
	//calcul de vitesse dX/dt
	vitesse_chariot = float(codeur_position_chariot - codeur_position_chariot_prev)/0.02;
	//(1/z) de la position
	codeur_position_chariot_prev = codeur_position_chariot;
	
	// si etat asser a  STOP
	if(	etat_asser_chariot==STOP)
	{
		if(commande_moteur_chariot!=0.0)
		{
		commande_moteur_chariot=0.0;
		Application.m_moteurs.CommandeVitesse(MOTEUR_6, commande_moteur_chariot);
		}
	}
	//dans tous les autres cas
	else
	{
		switch(etat_recalage_butee)
		{
			case NON_FAIT: // Apprentissage pas fait, ne rien faire
				if(commande_moteur_chariot!=0.0)
				{
					commande_moteur_chariot=0.0;
					Application.m_moteurs.CommandeVitesse(MOTEUR_6, commande_moteur_chariot);
				}
			break;
				
            case EN_COURS: // Apprentissage demandee, on demande un déplacement doucement jusqu'à  vitesse nulle avec tempo de confirmation
				tempo_time_out++;

                //on commence par la butee droite (valeur négative) butee haute
                if(butee_haute==0)
				{
                    vitesse_consigne = vitesse_consigne_recalage_C;
					//regulation sur la vitesse
                    //Regul_chariot();
                    //manuel
                    commande_moteur_chariot=55.0;
                    Application.m_moteurs.CommandeVitesse(MOTEUR_6, commande_moteur_chariot);
				}
                else if (butee_basse==0) //butee basse
				{
                    vitesse_consigne = -vitesse_consigne_recalage_C;
					//regulation sur la vitesse
                    //Regul_chariot();
                    //manuel
                    commande_moteur_chariot=-35.0;
                    Application.m_moteurs.CommandeVitesse(MOTEUR_6, commande_moteur_chariot);
				}
				else
				{
					if(commande_moteur_chariot!=0.0)
					{
						commande_moteur_chariot=0.0;
						Application.m_moteurs.CommandeVitesse(MOTEUR_6, commande_moteur_chariot);
					}
					etat_recalage_butee = FAIT;
                    int half_range_rack=floorf(fabsf((butee_haute-butee_basse)/2.0f));

                    butee_haute=-half_range_rack;
                    butee_basse=half_range_rack;
                    Application.m_capteurs.RAZ_PositionCodeur(CODEUR_3,butee_basse);

					setConsigne(0);
				}

                if((Application.m_capteurs.m_b_Etor4==false)&&(vitesse_consigne<0))
				{
					if(commande_moteur_chariot!=0.0)
					{
						commande_moteur_chariot=0.0;
						Application.m_moteurs.CommandeVitesse(MOTEUR_6, commande_moteur_chariot);
					}

                    butee_basse=codeur_position_chariot;

				}
                if((Application.m_capteurs.m_b_Etor2==false)&&(vitesse_consigne>0))
				{
					if(commande_moteur_chariot!=0.0)
					{
						commande_moteur_chariot=0.0;
						Application.m_moteurs.CommandeVitesse(MOTEUR_6, commande_moteur_chariot);
					}

                    butee_haute=codeur_position_chariot;
				}
				if (tempo_time_out > seuil_tempo_time_out_C)
				{
					etat_recalage_butee = ECHEC; // Time out apprentissage :o(
				}
			break;
			
            case FAIT: // Cas nominal, on calcul l'erreur de boucle et la consigne de vitesse pour le régulateur que l'on appel
				erreur_position = position_consigne - codeur_position_chariot;
				vitesse_consigne = gain_position_vitesse_C*erreur_position;
                // New gradient max consigne de vitesse pour décollage en douceur sur changement de consigne
                               /* if (vitesse_consigne >= 0)
                                    {
                                    if (vitesse_consigne_filt < vitesse_consigne)
                                        {
                                        vitesse_consigne_filt += offset_vitesse_max_C;
                                        vitesse_consigne_filt = std::min(vitesse_consigne_filt, vitesse_consigne);
                                        }
                                    else
                                        {
                                        vitesse_consigne_filt = vitesse_consigne;
                                        }
                                    }

                                else if (vitesse_consigne < 0)
                                    {
                                    if (vitesse_consigne_filt > vitesse_consigne)
                                        {
                                        vitesse_consigne_filt -= offset_vitesse_max_C;
                                        vitesse_consigne_filt = std::max(vitesse_consigne_filt, vitesse_consigne);
                                        }
                                    else
                                        {
                                        vitesse_consigne_filt = vitesse_consigne;
                                        }
                                    }*/
				if(fabs(erreur_position)<=seuil_conv_C)
				{
					// On ne coupe pas la commande en mode ascensseur car on en a besoin pour vaincre le poids des éléments, on reste en boucle fermée à moins que le système soit très irréversible
					// Sinon on peut essayer de mettre une commande de maintient en boucle ouverte mais ça sera moins bon qu'une boucle fermée bien stable
					etat_asser_chariot=CONVERGE;
                    //Regul_chariot();

                    if(commande_moteur_chariot!=0.0)
                    {
                        commande_moteur_chariot=0.0;
                        Application.m_moteurs.CommandeVitesse(MOTEUR_6, commande_moteur_chariot);
                    }
				}
				else
				{
				etat_asser_chariot=DEPLACEMENT; // New, si une perturbation ou un changement de consigne on n'a plus l'état convergé
				}

				if(etat_asser_chariot==DEPLACEMENT)
					Regul_chariot();
			break;
			
            case ECHEC: // Pas de mise en butée après 3 plombes, on coupe la commande
				commande_moteur_chariot = 0;
			break;
		}
	}
	
}

void CAsservissementChariot::Regul_chariot(void) // Régulateutr de vitesse PI
{
    //erreur_vitesse = vitesse_consigne_filt-vitesse_chariot;
    erreur_vitesse = vitesse_consigne-vitesse_chariot;
	
	float terme_integral=0;
	
	if (saturation == 0)
		{
		terme_integral = gain_int_C*erreur_vitesse*0.02 + terme_integral_prev;
		terme_integral_prev = terme_integral;
		}


	float commande_unlim = -(gain_prop_C*erreur_vitesse + terme_integral);
	if(commande_unlim>0)
        commande_unlim=(commande_unlim+compensation_zone_morte_up_C);	// New, attention la commande positive doit aller dans le sens montée
	else
        commande_unlim=(commande_unlim-compensation_zone_morte_dw_C);	// New, attention la commande négative doit aller dans le sens descente
	
	// Saturation commande
	float commande_lim = commande_unlim;
	if (commande_unlim > commande_chariot_max_C)
		{
		commande_lim = commande_chariot_max_C;
		}
	if (commande_unlim < -commande_chariot_max_C)
		{
		commande_lim = -commande_chariot_max_C;
		}
	
    // détection de saturation
	if (commande_unlim != commande_lim)
		{
		saturation = 1;
		}
	else
		{
		saturation = 0;
		}
	commande_moteur_chariot = commande_lim;

	Application.m_moteurs.CommandeVitesse(MOTEUR_6, commande_moteur_chariot);
}

void CAsservissementChariot::setConsigne(int pos)
{
	int pos_seuil=pos;
    if(pos_seuil<=butee_haute)
        pos_seuil=butee_haute+5;
    if(pos_seuil>=butee_basse)
        pos_seuil=butee_basse-5;
	position_consigne=(float)pos_seuil;
	etat_asser_chariot=DEPLACEMENT;
}

void CAsservissementChariot::Stop_Chariot(void)
{
	etat_asser_chariot=STOP;
}

void CAsservissementChariot::Recal_Chariot(void)
{
	etat_asser_chariot=DEPLACEMENT;
	etat_recalage_butee=EN_COURS;
	tempo_time_out=0;
    butee_haute=0;
        butee_basse=0;
}

void CAsservissementChariot::setCommandeMax(float calib){commande_chariot_max_C=calib;}
void CAsservissementChariot::setGainPosVit(float calib){gain_position_vitesse_C=calib;}
void CAsservissementChariot::setGainP(float calib){gain_prop_C=calib;}
void CAsservissementChariot::setGainI(float calib){gain_int_C=calib;}
void CAsservissementChariot::setSeuilConv(float calib){seuil_conv_C=calib;} //seuil cm ramene en pas codeur
