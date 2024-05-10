/**
 * Generated 10_05_2024 at 08_10
 */

#ifndef SM_SAUVEGARDEPLANTES_H
#define SM_SAUVEGARDEPLANTES_H

#include "sm_statemachinebase.h"

class SM_SauvegardePlantes : public SM_StateMachineBase
{
public:
	SM_SauvegardePlantes();
	void step();
	const char* getName();
	const char* stateToName(unsigned short state);

	typedef enum {
	STATE_1 = SM_StateMachineBase::SM_FIRST_STATE,
	STATE_2,
	STATE_3,
	STATE_4,
	STATE_5,
	STATE_6,
	STATE_7,
	STATE_8,
	STATE_9,
	STATE_10,
	STATE_11,
	STATE_12,
	STATE_13,
	STATE_14,
	STATE_15,
	STATE_16,
	STATE_17,
	STATE_18,
	STATE_19,
	STATE_20,
	STATE_21,
	STATE_22,
	STATE_23,
	STATE_24,
	STATE_25,
	STATE_26,
	STATE_27,
	STATE_28,
	STATE_29,
	STATE_30,
	STATE_31,
	STATE_32,
	STATE_33,
	STATE_34,
	STATE_35,
	FIN_MISSION
	}tState;
};

#endif // SM_SAUVEGARDEPLANTES_H