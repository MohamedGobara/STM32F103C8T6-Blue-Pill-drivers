#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/*
 * File:   NVIC_interfacec.h
 * Author: Mohamed Hussein
 * Date:   February 13, 2024 (Date of creation)
 *
 * Description:
 * ------------
 * This header file contains the interface declarations for the Nested Vector Interrupt Controller (NVIC) module
 * on STM32 microcontrollers. It defines function prototypes for configuring interrupt priorities, enabling/disabling interrupts,
 * setting/clearing pending flags, and retrieving interrupt states.
 *
 * Usage:
 * ------
 * 1. Include this file in your project to access the NVIC interface functions.
 * 2. Ensure that the necessary NVIC configuration header file is included.
 * 3. Use the provided function prototypes to configure and manage interrupts as needed in your application.
 *
 */


#include <stdint.h>

#include "Utils.h"
#include "STDTypes.h"


#include "NVIC/inc/NVIC_private.h"
#include "NVIC/inc/NVIC_config.h"



// Enumeration defining NVIC external peripherals

typedef enum {

	WWDG_LINE,
	PVD_LINE,
	TAMPER_LINE,
	RTC_LINE,
	FLASH_LINE,
	RCC_LINE,
	EXTI0_LINE,
	EXTI1_LINE,
	EXTI2_LINE,
	EXTI3_LINE,
	EXTI4_LINE,
	DMA1_Channel1_LINE,
	DMA1_Channel2_LINE,
	DMA1_Channel3_LINE,
	DMA1_Channel4_LINE,
	DMA1_Channel5_LINE,
	DMA1_Channel6_LINE,
	DMA1_Channel7_LINE,
	ADC1_2_LINE,
	USB_HP_CAN_LINE,
	USB_LP_CAN_LINE,
	CAN_RX1_LINE,
	CAN_SCE_LINE,
	EXTI9_5_LINE,
	TIM1_BRK_LINE,
	TIM1_UP_LINE,
	TIM1_TRG_COM_LINE,
	TIM1_CC_LINE,
	TIM2_LINE,
	TIM3_LINE,
	TIM4_LINE,
	I2C1_EV_LINE,
	I2C1_ER_LINE,
	I2C2_EV_LINE,
	I2C2_ER_LINE,
	SPI1_LINE,
	SPI2_LINE,
	USART1_LINE,
	USART2_LINE,
	USART3_LINE,
	EXTI15_10_LINE,
	RTCAlarm_LINE,
	USBWakeup_LINE,
	TIM8_BRK_LINE,
	TIM8_UP_LINE,
	TIM8_TRG_COM_LINE,
	TIM8_CC_LINE,
	ADC3_LINE,
	FSMC_LINE,
	SDIO_LINE,
	TIM5_LINE,
	SPI3_LINE,
	UART4_LINE,
	UART5_LINE,
	TIM6_LINE,
	TIM7_LINE,
	DMA2_Channel1_LINE,
	DMA2_Channel2_LINE,
	DMA2_Channel3_LINE,
	DMA2_Channel4_5_LINE,

} NVIC_EXTPreprheial;


// Predefined configurations for NVIC interrupt priorities

#define 		NVIC_16GROUB_0SUB		0b011
#define 		NVIC_8GROUB_2SUB		0b100
#define 		NVIC_4GROUB_4SUB		0b101
#define 		NVIC_2GROUB_8SUB		0b110
#define 		NVIC_0GROUB_16SUB		0b111

/*FUNCTION Name: NVIC_voidSetInterruptPriority
 * Description:Changes the priority of the given Interrupt peripheral
 * I/P Parameters:
 * Copy_uint8_tInterruptNum : the number of the required peripheral
 * Copy_uint8_tGroupId    :the desired Group Id of interrupt note:if PriorityConfig= NVIC_GROUB0BITS_SUB4BITS then enter 0
 * Copy_uint8_tSubGroupId :the desired SubGroup Id of interrupt note:if PriorityConfig= NVIC_GROUB4BITS_SUB0BITS then enter 0
 *
 */
void NVIC_voidSetInterruptPriority(NVIC_EXTPreprheial Copyuint8_tInterruptNumber,
		uint8_t Copy_uint8_tGroupId, uint8_t Copy_u8SubGroupId);

/*
 *FUNCTION Name: NVIC_SetPriorityConfig
 I/P Parameters:
 * Copy_uint8_tPriority:
 *
 * NVIC_16GROUB_0SUB
 * NVIC_8GROUB_2SUB
 * NVIC_4GROUB_4SUB
 * NVIC_2GROUB_8SUB
 * NVIC_0GROUB_16SUB
 */
void NVIC_SetPriorityConfig(uint8_t Copy_uint8_tPriority);

/**
 * @brief Enables the specified interrupt in the NVIC (Nested Vector Interrupt Controller).
 * @param Copy_uint8_tInterruptNum: The interrupt number to be enabled.
 * @return None
 */
void NVIC_vEnableInterrupt(NVIC_EXTPreprheial Copy_u8InterruptNum);
/**
 * @brief Disables the specified interrupt in the NVIC (Nested Vector Interrupt Controller).
 * @param Copy_uint8_tInterruptNum: The interrupt number to be disabled.
 * @return None
 */
void NVIC_vDisableInterrupt(NVIC_EXTPreprheial Copy_u8InterruptNum);
/**
 * @brief Sets the pending flag for the specified interrupt in the NVIC (Nested Vector Interrupt Controller).
 * @param Copy_uint8_tInterruptNum: The interrupt number for which the pending flag is to be set.
 * @return None
 */
void NVIC_vSetPendingFlag(NVIC_EXTPreprheial Copy_u8InterruptNum);
/**
 * @brief Clears the pending flag for the specified interrupt in the NVIC (Nested Vector Interrupt Controller).
 * @param Copy_uint8_tInterruptNum: The interrupt number for which the pending flag is to be cleared.
 * @return None
 */
void NVIC_vClearPendingFlag(NVIC_EXTPreprheial Copy_u8InterruptNum);
/**
 * @brief Gets the state of the specified interrupt in the NVIC (Nested Vector Interrupt Controller).
 * @param Copy_uint8_tInterruptNum: The interrupt number for which the state is to be retrieved.
 * @return The state of the interrupt (active:1 or not active:0).
 */
uint8_t NVIC_uint8_tGetInterruptState(NVIC_EXTPreprheial Copy_u8InterruptNum);

#endif /* NVIC_INTERFACE_H */
