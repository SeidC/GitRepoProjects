/* (c) Peter Mueller, 2012 - All rights reserved. Reproduction, modification,
   use or disclosure to third parties without express
   authority is forbidden. Generator running in demo mode!
   Please purchase a license if you want to use this software in projects.
 */

/* Command line options: -l cx -p EA -o Easy_RxFsm -t Model:SM:Easy_RxFsm Easy_RxFsm.xml   */
/* This file is generated from Easy_RxFsm.xml - do not edit manually  */
/* Generated on: Sat Nov 05 22:28:28 CET 2016 / version 3.7 */


/* Inlcude default headers (no header definition in UML state-chart provided) */
/* Define a header comment in your statediagram.model to define own includes here. */
#include "Easy.h"
#include "Easy_RxFsm.h"

/* Refere to external var (no header definition in UML state-chart provided) */
/* Define a header comment in your statediagram.model to define own definitions here. */
extern EASY_VOL EASY_RXFSM_EVENT_T msg;

void  Easy_RxFsm(EASY_RXFSM_INSTANCEDATA_T *instanceVar){
	

	switch (instanceVar->stateVar) {

		case Easy_RxFinishedState:
			/* action code  */
			Easy_RxFinished();


			if(msg==(EASY_RXFSM_EVENT_T)EASY_RX_NO_INDICATION){
				/* Transition from Easy_RxFinishedState to Easy_RxNoIndicationState */


				/* adjust state variables  */
				instanceVar->stateVar = Easy_RxNoIndicationState;
			}else{
				/* Intentionally left blank */
			} /*end of event selection */
		break; /* end of case Easy_RxFinishedState  */

		case Easy_RxNoIndicationState:
			/* action code  */
			Easy_RxNoIndication();


			if(msg==(EASY_RXFSM_EVENT_T)EASY_RX_PRE_START){
				/* Transition from Easy_RxNoIndicationState to Easy_RxPreStartState */


				/* adjust state variables  */
				instanceVar->stateVar = Easy_RxPreStartState;
			}else{
				/* Intentionally left blank */
			} /*end of event selection */
		break; /* end of case Easy_RxNoIndicationState  */

		case Easy_RxPreStartState:
			/* action code  */
			Easy_RxPreStart();


			if(msg==(EASY_RXFSM_EVENT_T)EASY_RX_ERROR){
				/* Transition from Easy_RxPreStartState to Easy_RxNoIndicationState */

				/* Action code for transition  */
				Easy_RxReceiveError();



				/* adjust state variables  */
				instanceVar->stateVar = Easy_RxNoIndicationState;
			}else if(msg==(EASY_RXFSM_EVENT_T)EASY_RX_NO_INDICATION){
				/* Transition from Easy_RxPreStartState to Easy_RxNoIndicationState */


				/* adjust state variables  */
				instanceVar->stateVar = Easy_RxNoIndicationState;
			}else if(msg==(EASY_RXFSM_EVENT_T)EASY_RX_RECEIVE){
				/* Transition from Easy_RxPreStartState to Easy_RxReceiveState */


				/* adjust state variables  */
				instanceVar->stateVar = Easy_RxReceiveState;
			}else{
				/* Intentionally left blank */
			} /*end of event selection */
		break; /* end of case Easy_RxPreStartState  */

		case Easy_RxReceiveState:
			/* action code  */
			Easy_RxReceive();


			if(msg==(EASY_RXFSM_EVENT_T)EASY_RX_ERROR){
				/* Transition from Easy_RxReceiveState to Easy_RxNoIndicationState */

				/* Action code for transition  */
				Easy_RxReceiveError();



				/* adjust state variables  */
				instanceVar->stateVar = Easy_RxNoIndicationState;
			}else if(msg==(EASY_RXFSM_EVENT_T)EASY_RX_FINISHED){
				/* Transition from Easy_RxReceiveState to Easy_RxFinishedState */


				/* adjust state variables  */
				instanceVar->stateVar = Easy_RxFinishedState;
			}else{
				/* Intentionally left blank */
			} /*end of event selection */
		break; /* end of case Easy_RxReceiveState  */

		default:
			/* Intentionally left blank */
		break;
	} /* end switch stateVar_root */
}

/* Implementation of the reset machine function */
void Easy_RxFsmResetMachine(EASY_RXFSM_INSTANCEDATA_T *instanceVar){
	instanceVar->easy_rxnoindicationstateEntry = 1U;
	instanceVar->stateVar = Easy_RxNoIndicationState;
	
}

// Helper(s) to find out if the machine is in a certain state

uint8_t Easy_RxFsmIsInEasy_RxReceiveState(EASY_RXFSM_INSTANCEDATA_T *instanceVar){
	return(((instanceVar->stateVar== Easy_RxReceiveState)) ? (1U) : (0U));
}

uint8_t Easy_RxFsmIsInEasy_RxPreStartState(EASY_RXFSM_INSTANCEDATA_T *instanceVar){
	return(((instanceVar->stateVar== Easy_RxPreStartState)) ? (1U) : (0U));
}

uint8_t Easy_RxFsmIsInEasy_RxNoIndicationState(EASY_RXFSM_INSTANCEDATA_T *instanceVar){
	return(((instanceVar->stateVar== Easy_RxNoIndicationState)) ? (1U) : (0U));
}

uint8_t Easy_RxFsmIsInEasy_RxFinishedState(EASY_RXFSM_INSTANCEDATA_T *instanceVar){
	return(((instanceVar->stateVar== Easy_RxFinishedState)) ? (1U) : (0U));
}


// Helper to get id of innermost active state
EASY_RXFSM_STATES_T Easy_RxFsmGetInnermostActiveState(EASY_RXFSM_INSTANCEDATA_T *instanceVar){
	if(Easy_RxFsmIsInEasy_RxFinishedState(instanceVar)){
		return Easy_RxFinishedState;
	}else if(Easy_RxFsmIsInEasy_RxNoIndicationState(instanceVar)){
		return Easy_RxNoIndicationState;
	}else if(Easy_RxFsmIsInEasy_RxPreStartState(instanceVar)){
		return Easy_RxPreStartState;
	}else if(Easy_RxFsmIsInEasy_RxReceiveState(instanceVar)){
		return Easy_RxReceiveState;
	}else{
		return __EASY_RXFSM_LAST_STATE__;
	}
}

