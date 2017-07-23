//			Asservissement 2014
//
//	Modifications à valider ou calibrer :
//
//	Diag de blocage à calibrer
//	Calcul du coeff facteur_correction_avance_angle ne fonctionne pas correctement en passant pas la carto ?
//	Correction batterie à valider
//	Mouvement XY_TETA à valider
//	Initialisation des zones mortes suppr (en commentaire)
//	Flag de convergence rapide à valider
//	Todo : Diag de blocage par écart de boucle ?

/*! \file CAsservissementSulfateuse.cpp
	\brief Classe qui contient toute l'application
*/
#include "math.h"
#include "CAsservissementSulfateuse.h"
#include "CGlobale.h"


//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CAsservissementSulfateuse::CAsservissementSulfateuse() 
{
  Init();
}


//___________________________________________________________________________
 /*!
   \brief Destructeur

   \param --
   \return --
*/
CAsservissementSulfateuse::~CAsservissementSulfateuse() 
{

}


//___________________________________________________________________________
 /*!
   \brief Initialisation

   \param --
   \return --
*/
void CAsservissementSulfateuse::Init(void) 
{
 

}



// ************************************************************************************
// Fonctions externes de calcul 
// ************************************************************************************

float CAsservissementSulfateuse::max(float Inp1, float Inp2)
{
	float Outp;

	if (Inp1 >= Inp2)		Outp=Inp1;
	else		Outp=Inp2;

	return Outp;
}

float CAsservissementSulfateuse::min(float Inp1, float Inp2)
{
	float Outp;

	if (Inp1 <= Inp2)		Outp=Inp1;
	else		Outp=Inp2;

	return Outp;
}

float CAsservissementSulfateuse::SAT(float Inp_max, float Inp_min, float Inp)
{
	return 	min(Inp_max,max(Inp,Inp_min));
}







