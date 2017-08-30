/*! \file CTrameLaBotBox.h
	\brief Classe qui contient la gestion d'une trame CAN
*/

#ifndef _TRAME_LABOTBOX_H_
#define _TRAME_LABOTBOX_H_

typedef struct {
	unsigned int ID;		//!< L'identifiant de la trame
	unsigned char DLC;		//!< La longueur de la trame
	unsigned char Data[8];	//!< Les donnees utiles de la trame
}tStructTrameLaBotBox;

// -----------------------------
//! Classe de base pour les trames CAN
class CTrameLaBotBox {
public :
    static const int NO_PERIODIC = -1;  // Indique que la trame n'est pas p�riodique

    //!	Structure brute
	tStructTrameLaBotBox m_trame_brute;
	//! Memorise le nombre de trame recues
	unsigned int m_nombre_recue;
	//! Memorise l'arrivee d'une nouvelle trame
	bool m_new_trame;
	
	CTrameLaBotBox();
	~CTrameLaBotBox();

    virtual void Decode(tStructTrameLaBotBox *trameRecue);
    virtual tStructTrameLaBotBox* Encode(void);

    bool isNewTrame(void);
    bool isTimeToSend();
    void setTransmitPeriod(int period_msec);

protected:
    //! P�riode d'�mission souhait�e [msec]
    unsigned short m_tx_periode;
    //! Instant de la derni�re �mission
    int m_last_time_tx;
};


#endif


