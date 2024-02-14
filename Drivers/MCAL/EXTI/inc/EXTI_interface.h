/*
 * Author: Mohamed Hussein
 * File: EXTI_interface.h
 * Description: This file contains declarations for managing external interrupts (EXTI) in microcontroller systems.
 *              It provides functions for configuring interrupt and event status, setting interrupt trigger edge,
 *              setting software interrupt, clearing pending flags, and setting callback functions for EXTI lines.
 */

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include "stdint.h"
#include "Utils.h"
#include "STDTypes.h"
#include "EXTI/inc/EXTI_private.h"
#include "EXTI/inc/EXTI_config.h"

/********************** Macro Declarations ***************************************/

#define EXTIMasked    0
#define EXTINonMasked 1

#define EventMasked    0
#define EventNonMasked 1

/*********************  Macro Function Declarations ****************************/

/*********************  Data Type Declarations ***********************************/

/*  status of External interrupt input  */
typedef enum
{
	RISING_EDGE=0,
	FALLING_EDGE,
	ON_CHANGE
}EXTI_SelectTrigger_typ;

typedef enum {
	EXTI_LINE0,
	EXTI_LINE1,
	EXTI_LINE2,
	EXTI_LINE3,
	EXTI_LINE4,
	EXTI_LINE5,
	EXTI_LINE6,
	EXTI_LINE7,
	EXTI_LINE8,
	EXTI_LINE9,
	EXTI_LINE10,
	EXTI_LINE11,
	EXTI_LINE12,
	EXTI_LINE13,
	EXTI_LINE14,
	EXTI_LINE15,
	EXTI_LINE16,
	EXTI_LINE17,
	EXTI_LINE18,
	EXTI_LINE19
} EXTI_Numbers;

/*
 * Function: EXTI_RETURNtSetInterruptStatus
 * Description: Sets the interrupt status for a specific EXTI line.
 * Parameters:
 *   - Copy_u8EXTINumber: EXTI line number to configure
 *   - Copy_u8EXTIStatus: Interrupt status (EXTIMasked or EXTINonMasked)
 * Return:
 *   - RETURN_OK if successful, error code otherwise
 */
RETURN_t EXTI_RETURNtSetInterruptStatus(EXTI_Numbers Copy_u8EXTINumber, uint8_t Copy_u8EXTIStatus);


/*
 * Function: EXTI_RETURNtSetEventStatus
 * Description: Sets the event status for a specific EXTI line.
 * Parameters:
 *   - Copy_u8EXTINumber: EXTI line number to configure
 *   - Copy_u8EXTIStatus: Event status (EventMasked or EventNonMasked)
 * Return:
 *   - RETURN_OK if successful, error code otherwise
 */
RETURN_t EXTI_RETURNtSetEventStatus(EXTI_Numbers Copy_u8EXTINumber, uint8_t Copy_u8EXTIStatus);

/*
 * Function: EXTI_RETURNtSetInterruptEdge
 * Description: Sets the interrupt trigger edge for a specific EXTI line.
 * Parameters:
 *   - Copy_u8EXTINumber: EXTI line number to configure
 *   - Copy_u8EXTIEdge: Trigger edge (RISING_EDGE, FALLING_EDGE, or ON_CHANGE)
 * Return:
 *   - RETURN_OK if successful, error code otherwise
 */
RETURN_t EXTI_RETURNtSetInterruptEdge(EXTI_Numbers Copy_u8EXTINumber, uint8_t Copy_u8EXTIEdge);

/*
 * Function: EXTI_vSetSoftwareInterrupt
 * Description: Sets a software interrupt for a specific EXTI line.
 * Parameters:
 *   - Copy_u8EXTINumber: EXTI line number to trigger software interrupt
 */
void EXTI_vSetSoftwareInterrupt(uint8_t Copy_u8EXTINumber);

/*
 * Function: EXTI_vClearPendingFlag
 * Description: Clears the pending flag for a specific EXTI line.
 * Parameters:
 *   - Copy_u8EXTINumber: EXTI line number to clear pending flag
 */
void EXTI_vClearPendingFlag(EXTI_Numbers Copy_u8EXTINumber);

/*
 * Function: EXTI_RETURNtSetCalbackFunction
 * Description: Sets a callback function for a specific EXTI line.
 * Parameters:
 *   - Copy_u8EXTINumber: EXTI line number to set callback function
 *   - Ptrfunction: Pointer to the callback function
 * Return:
 *   - RETURN_OK if successful, error code otherwise
 */
RETURN_t EXTI_RETURNtSetCalbackFunction(EXTI_Numbers Copy_u8EXTINumber, void (*Ptrfunction)(void));

#endif /* EXTI_INTERFACE_H */
