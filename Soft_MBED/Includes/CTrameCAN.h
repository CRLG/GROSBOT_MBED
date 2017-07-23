/*! \file CTrameCAN.h
	\brief Classe qui contient la gestion d'une trame CAN
*/

#ifndef _TRAME_CAN_H_
#define _TRAME_CAN_H_

typedef struct {
	unsigned int ID;		//!< L'identifiant de la trame
	unsigned char DLC;		//!< La longueur de la trame
	unsigned char Data[8];	//!< Les donnees utiles de la trame
}tStructTrameBrute;

// -----------------------------
//! Classe de base pour les trames CAN
class CTrameCAN {
public :
	//!	Structure brute
	tStructTrameBrute m_trame_brute;
	//! Memorise le nombre de trame recues
	unsigned int m_nombre_recue;
	//! Memorise l'arrivee d'une nouvelle trame
	bool m_new_trame;
	
	CTrameCAN();
	~CTrameCAN();

	void Decode(tStructTrameBrute *trameRecue);
	tStructTrameBrute* Encode(void);
	bool isNewTrame(void);
	 
	 


};


#endif


