/**
 * Generated 27_10_2020 at 22_21
 */

#ifndef SM_ACTIVERPHARE_H
#define SM_ACTIVERPHARE_H

#include "sm_statemachinebase.h"

class SM_ActiverPhare : public SM_StateMachineBase
{
public:
	SM_ActiverPhare();
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
	FIN_MISSION
	}tState;
};

#endif // SM_ACTIVERPHARE_H