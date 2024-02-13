/*
 * File:   NVIC_program.c
 * Author: Mohamed Hussein
 * Date:   February 13, 2024 (Date of creation)
 *
 * Description:
 * ------------
 * This file contains the implementation of functions related to the Nested Vector Interrupt Controller (NVIC) module
 * on STM32 microcontrollers. It provides functions to configure interrupt priorities, enable/disable interrupts,
 * set/clear pending flags, and retrieve interrupt states.
 *
 * Usage:
 * ------
 * 1. Include this file in your project to utilize the NVIC functions.
 * 2. Ensure that the necessary NVIC configuration header file is included.
 * 3. Use the provided functions to configure and manage interrupts as needed in your application.
 *
 */


#include "NVIC/inc/NVIC_interface.h"


static uint8_t StaticGlobal_u8PriorityConfig ;


void NVIC_SetPriorityConfig(uint8_t Copy_u8Priority) {

	 StaticGlobal_u8PriorityConfig=Copy_u8Priority;
	 uint32_t LocalTempRegValue=(VECT_KEY<<16)|(Copy_u8Priority<<8)|(SCB_AIRCR&0b111) ;
	 SCB_AIRCR =LocalTempRegValue ;

}


/*FUNCTION Name: NVIC_voidSetInterruptPriority
 * Description:Changes the priority of the given Interrupt peripheral
 * I/P Parameters:
 * Copy_u8InterruptNum : the number of the required peripheral
 * Copy_u8GroupId    :the desired Group Id of interrupt note:if PriorityConfig= NVIC_GROUB0BITS_SUB4BITS then enter 0
 * Copy_u8SubGroupId :the desired SubGroup Id of interrupt note:if PriorityConfig= NVIC_GROUB4BITS_SUB0BITS then enter 0
 *
 */
void NVIC_voidSetInterruptPriority(NVIC_EXTPreprheial Copyu8InterruptNumber,
		uint8_t Copy_u8GroupId, uint8_t Copy_u8SubGroupId) {



	switch (StaticGlobal_u8PriorityConfig) {
		case NVIC_16GROUB_0SUB:
			NVIC->IPR[Copyu8InterruptNumber]=(Copy_u8GroupId<<4);
			break;
		case NVIC_8GROUB_2SUB:
			NVIC->IPR[Copyu8InterruptNumber]=((Copy_u8GroupId&0b111)<<5)|((Copy_u8SubGroupId & 0b1)<<4);
		break;
		case NVIC_4GROUB_4SUB:
			NVIC->IPR[Copyu8InterruptNumber]=((Copy_u8GroupId&0b11)<<6)|((Copy_u8SubGroupId & 0b11)<<4);

		break;
		case NVIC_2GROUB_8SUB:
			NVIC->IPR[Copyu8InterruptNumber]=((Copy_u8GroupId&0b11)<<7)|((Copy_u8SubGroupId & 0b111)<<4);

		break;
		case NVIC_0GROUB_16SUB:
			NVIC->IPR[Copyu8InterruptNumber]=((Copy_u8SubGroupId & 0b1111)<<4);

		break;
		default:
			break;
	}



}

/**
 * @brief Enables the specified interrupt in the NVIC (Nested Vector Interrupt Controller).
 * @param Copy_u8InterruptNum: The interrupt number to be enabled.
 * @return None
 */
void NVIC_vEnableInterrupt(NVIC_EXTPreprheial Copy_u8InterruptNum){


	SET_BIT(NVIC->ISER[Copy_u8InterruptNum/32],Copy_u8InterruptNum%32);

}
/**
 * @brief Disables the specified interrupt in the NVIC (Nested Vector Interrupt Controller).
 * @param Copy_u8InterruptNum: The interrupt number to be disabled.
 * @return None
 */
void NVIC_vDisableInterrupt(NVIC_EXTPreprheial Copy_u8InterruptNum){

	SET_BIT( NVIC->ICER[Copy_u8InterruptNum/32],(Copy_u8InterruptNum%32));

}
/**
 * @brief Sets the pending flag for the specified interrupt in the NVIC (Nested Vector Interrupt Controller).
 * @param Copy_u8InterruptNum: The interrupt number for which the pending flag is to be set.
 * @return None
 */
void NVIC_vSetPendingFlag(NVIC_EXTPreprheial Copy_u8InterruptNum){

	SET_BIT( NVIC->ISPR[Copy_u8InterruptNum/32],(Copy_u8InterruptNum%32));


}
/**
 * @brief Clears the pending flag for the specified interrupt in the NVIC (Nested Vector Interrupt Controller).
 * @param Copy_u8InterruptNum: The interrupt number for which the pending flag is to be cleared.
 * @return None
 */
void NVIC_vClearPendingFlag(NVIC_EXTPreprheial Copy_u8InterruptNum){

	SET_BIT( NVIC->ICPR[Copy_u8InterruptNum/32],(Copy_u8InterruptNum%32));


}
/**
 * @brief Gets the state of the specified interrupt in the NVIC (Nested Vector Interrupt Controller).
 * @param Copy_u8InterruptNum: The interrupt number for which the state is to be retrieved.
 * @return The state of the interrupt (active:1 or not active:0).
 */
uint8_t NVIC_u8GetInterruptState(NVIC_EXTPreprheial Copy_u8InterruptNum){

	uint8_t Local_u8IntState=READ_BIT( NVIC->IABR[Copy_u8InterruptNum/32],(Copy_u8InterruptNum%32));

	return Local_u8IntState;

}

