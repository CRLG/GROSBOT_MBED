/*! \file CTrameEcranTactile.h
	\brief Classe qui contient la gestion d'une trame CAN
*/

#ifndef _TRAME_ECRAN_TACTILE_H_
#define _TRAME_ECRAN_TACTILE_H_

#define NBRE_MAX_DATA_TRAME_ECRAN_TACTILE  20

typedef struct {
	unsigned short ID;		//!< L'identifiant de la trame
	unsigned char DLC;		//!< La longueur de la trame
	unsigned char Data[NBRE_MAX_DATA_TRAME_ECRAN_TACTILE];	//!< Les donnees utiles de la trame
	unsigned char Channel;	//!< Numero de canal (CAN1 ou CAN2 par exemple)
}tStructTrameBruteEcran;

// -----------------------------
//! Classe de base pour les trames CAN
class CTrameEcranTactile {
public :
	//!	Structure brute
	tStructTrameBruteEcran m_trame_brute;
	//! Memorise le nombre de trame recues
	unsigned int m_nombre_recue;
	//! Memorise l'arrivee d'une nouvelle trame
	bool m_new_trame;
	
	CTrameEcranTactile();
	~CTrameEcranTactile();

	void Decode(tStructTrameBruteEcran *trameRecue);
	tStructTrameBruteEcran* Encode(void);
	bool isNewTrame(void);
	 
	 


};


#endif

