/* (c) Peter Mueller, 2012 - All rights reserved. Reproduction, modification,
   use or disclosure to third parties without express
   authority is forbidden. Generator running in demo mode!
   Please purchase a license if you want to use this software in projects.
 */

/* Command line options: -l cx -p EA -o Easy_RxFsm -t Model:SM:Easy_RxFsm Easy_RxFsm.xml   */
/* This file is generated from Easy_RxFsm.xml - do not edit manually*/
/* Generated on: Sat Nov 05 22:28:28 CET 2016 / version 3.7 */


#ifndef __EASY_RXFSM_H__
#define __EASY_RXFSM_H__


/* Header to define simple data types */
#include "avr/io.h"

/* State definitions */
typedef enum{
	Easy_RxReceiveState,
	Easy_RxPreStartState,
	Easy_RxNoIndicationState,
	Easy_RxFinishedState,
	__EASY_RXFSM_LAST_STATE__} EASY_RXFSM_STATES_T;






/* Predefined types required by the codegen. You can provide your own  */
/* definitions by setting the following define somewhere in your built env. */
#ifndef __PROVIDE_OWN_EASY_RXFSM_STATEMACHINE_TYPES__
	typedef uint8_t EASY_RXFSM_ENTRY_FLAG_T;
	typedef EASY_RXFSM_STATES_T EASY_RXFSM_STATEVAR_T;
	typedef uint8_t EASY_RXFSM_INST_ID_T;
	typedef uint8_t EASY_RXFSM_EV_CONSUMED_FLAG_T ;
#endif




/* Instance data definition of state machine */
typedef struct{
	EASY_RXFSM_ENTRY_FLAG_T easy_rxnoindicationstateEntry;
	EASY_RXFSM_STATEVAR_T stateVar;
		EASY_RXFSM_INST_ID_T inst_id;
} EASY_RXFSM_INSTANCEDATA_T;

/* Helper to initialize the machine's instance data */
#define EASY_RXFSM_INSTANCEDATA_INIT {\
	1,\
	(EASY_RXFSM_STATEVAR_T) Easy_RxNoIndicationState /* set init state of top state */,\
	0 /* instance id */ } 

/* Region handler prototypes  */

/*Prototype of the state machine function */
void  Easy_RxFsm(EASY_RXFSM_INSTANCEDATA_T *instanceVar);


/*Prototoye of the reset machine function */
void Easy_RxFsmResetMachine(EASY_RXFSM_INSTANCEDATA_T *instanceVar);

// Helper(s) to find out if the machine is in a certain state
uint8_t Easy_RxFsmIsInEasy_RxReceiveState(EASY_RXFSM_INSTANCEDATA_T *instanceVar);
uint8_t Easy_RxFsmIsInEasy_RxPreStartState(EASY_RXFSM_INSTANCEDATA_T *instanceVar);
uint8_t Easy_RxFsmIsInEasy_RxNoIndicationState(EASY_RXFSM_INSTANCEDATA_T *instanceVar);
uint8_t Easy_RxFsmIsInEasy_RxFinishedState(EASY_RXFSM_INSTANCEDATA_T *instanceVar);


/* Macros to test if the machine is in a certain state. */
#define EASY_RXFSM_IS_IN_EASY_RXRECEIVESTATE(instance)((((&instance)->stateVar==Easy_RxReceiveState)) ? (1U) : (0U))
#define EASY_RXFSM_IS_IN_EASY_RXPRESTARTSTATE(instance)((((&instance)->stateVar==Easy_RxPreStartState)) ? (1U) : (0U))
#define EASY_RXFSM_IS_IN_EASY_RXNOINDICATIONSTATE(instance)((((&instance)->stateVar==Easy_RxNoIndicationState)) ? (1U) : (0U))
#define EASY_RXFSM_IS_IN_EASY_RXFINISHEDSTATE(instance)((((&instance)->stateVar==Easy_RxFinishedState)) ? (1U) : (0U))


/* Helper returning the innermost active state.*/
EASY_RXFSM_STATES_T Easy_RxFsmGetInnermostActiveState(EASY_RXFSM_INSTANCEDATA_T *instanceVar);

#endif
