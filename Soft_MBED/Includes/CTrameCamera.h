/*! \file CTrameCamera.h
	\brief Classe qui contient la gestion d'une trame CAN
*/

#ifndef _TRAME_CAMERA_H
#define _TRAME_CAMERA_H

#define NBRE_MAX_DATA_TRAME_CAMERA_TACTILE  20

typedef struct {
	unsigned short ID;		//!< L'identifiant de la trame
	unsigned char DLC;		//!< La longueur de la trame
	unsigned char Data[NBRE_MAX_DATA_TRAME_CAMERA_TACTILE];	//!< Les donnees utiles de la trame
	unsigned char Channel;	//!< Numero de canal (CAN1 ou CAN2 par exemple)
}tStructTrameBruteCamera;

// -----------------------------
//! Classe de base pour les trames CAN
class CTrameCamera {
public :
	//!	Structure brute
	tStructTrameBruteCamera m_trame_brute;
	//! Memorise le nombre de trame recues
	unsigned int m_nombre_recue;
	//! Memorise l'arrivee d'une nouvelle trame
	bool m_new_trame;
	
	CTrameCamera();
	~CTrameCamera();

	void Decode(tStructTrameBruteCamera *trameRecue);
	tStructTrameBruteCamera* Encode(void);
	bool isNewTrame(void);
	 
	 


};


#endif


