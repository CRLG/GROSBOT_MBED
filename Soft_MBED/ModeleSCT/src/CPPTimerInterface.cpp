#include "CPPTimerInterface.h"
#include "TimedStatemachineInterface.h"

/*!
	This function will be called for each time event that is relevant for a state when a state will be entered.
	\param evid An unique identifier of the event.
	\time_ms The time in milli seconds
	\periodic Indicates the the time event must be raised periodically until the timer is unset
*/
void CPPTimerInterface::setTimer( TimedStatemachineInterface* statemachine,
		sc_eventid event,
		sc_integer time,
		sc_boolean isPeriodic )
{

	/* create new task and go through all timers ... */
	TimerTask* task = new TimerTask(statemachine, event, time, isPeriodic);
	for (int i = 0; i < MAX_TIMER; i++)
	{

		/* ... and find an unused one. */
		if(this->tasks[i] == null)
		{

			/* set timer properties */
			this->tasks[i] = task;
			break;
		}
	}
}

/*!
	This function will be called for each time event that is relevant for a state when a state will be left.
	\param evid An unique identifier of the event.
*/
void CPPTimerInterface::unsetTimer(TimedStatemachineInterface* statemachine,
		sc_eventid event)
{

	/* go through all timers ... */
	for(int i = 0; i < MAX_TIMER; i++)
	{

		TimerTask *task = this->tasks[i];
		/* ... and find the used timer */
		if((task != null) && (task->getPtEvid() == event))
		{

			/* reset the timer */
			delete this->tasks[i];
			this->tasks[i] = null;
		}
	}
}


/*!
	This function must be called by the user. The elapsed time must be calculated every time, the function gets
	gets called.
 */
void CPPTimerInterface::updateActiveTimer(TimedStatemachineInterface* statemachine,
		long elapsed_ms)
{

	/* go through all timers ... */
	for (int i = 0; i < MAX_TIMER; i++)
	{

		/* ... and process all used */
		TimerTask *task = this->tasks[i];
		if (task != null)
		{
			task->updateElapsedTimeMs(elapsed_ms);

			/* raise Time Event if the timer has proceed */
			if (task->getElapsedTimeMs() >= task->getTimeMs())
			{

				/* raise time event */
				statemachine->raiseTimeEvent(task->getPtEvid());

				/* update periodic timer */
				if (task->isPeriodic())
				{
					task->setElapsedTimeMs(task->getElapsedTimeMs()-task->getTimeMs());
				}
			}
		}
	}
}

/* ! Cancel timer service. */
void CPPTimerInterface::cancel()
{

	/* delete all timers */
	for (int i = 0; i < MAX_TIMER; i++)
	{
		delete tasks[i];
		this->tasks[i] = null;
	}
}
