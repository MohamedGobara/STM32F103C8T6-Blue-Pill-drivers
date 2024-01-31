/*
 * File:   RCC_interface.h
 * Author: Mohamed Hussein
 * Date:   December 16 , 2023 (Date of creation)
 *
 * Description:
 * ------------
 * Briefly describe the purpose and functionality of this code file.
 * Include any relevant information about the code's usage, algorithms used, or notable features.
 *
 * Usage:
 * ------
 * Explain how to use or integrate this code, including function calls, inputs, and outputs.
 * If this file is part of a larger project, mention its role in the project's architecture.
 *
 */

#ifndef MCAL_RCC_INC_RCC_INTERFACE_H_
#define MCAL_RCC_INC_RCC_INTERFACE_H_



/**
  * @brief  Initializes the Reset and Clock Control (RCC) settings.
  * @param  None
  * @retval Return status indicating success or failure of initialization.
  */
RETURN_t RCC_RETURNtInit(void) ;




/**************** Peripherals Names and Selection **********************
 * This section provides a categorized list of peripherals available
 * for configuration within the STM32F103XX microcontroller system.
 * It aids in enabling/disabling peripherals on specific buses (AHB, APB1, APB2).
 * Choose from the provided lists when configuring peripheral usage on buses.
 *
 * AHB_peripherals:
 * - DMA1_AHB_peripherals
 * - DMA2_AHB_peripherals
 * - SRAM_AHB_peripherals
 * - FLITF_AHB_peripherals
 * - CRC_AHB_peripherals
 * - FSMC_AHB_peripherals
 * - SDIO_AHB_peripherals
 *
 * APB2_peripherals:
 * - AFIO_APB2_peripherals
 * - PORTA_APB2_peripherals
 * - PORTB_APB2_peripherals
 * - PORTC_APB2_peripherals
 * - ADC1_APB2_peripherals
 * - ADC2_APB2_peripherals
 * - TIM1_APB2_peripherals
 * - SPI1_APB2_peripherals
 * - TIM8_APB2_peripherals
 * - USART1_APB2_peripherals
 * - ADC3_APB2_peripherals
 * - TIM9_APB2_peripherals
 * - TIM10_APB2_peripherals
 * - TIM11_APB2_peripherals
 *
 * APB1_peripherals:
 * - TIM2_APB1_peripherals
 * - TIM3_APB1_peripherals
 * - TIM4_APB1_peripherals
 * - TIM5_APB1_peripherals
 * - TIM6_APB1_peripherals
 * - TIM7_APB1_peripherals
 * - TIM12_APB1_peripherals
 * - TIM13_APB1_peripherals
 * - TIM14_APB1_peripherals
 * - WWDG_APB1_peripherals
 * - SPI2_APB1_peripherals
 * - SPI3_APB1_peripherals
 * - USART2_APB1_peripherals
 * - USART3_APB1_peripherals
 * - UART4_APB1_peripherals
 * - I2C1_APB1_peripherals
 * - USB_APB1_peripherals
 * - CAN_APB1_peripherals
 * - BKP_APB1_peripherals
 * - PWR_APB1_peripherals
 *
 * This guide helps in selecting and configuring peripherals while working
 * with the STM32F103XX microcontroller.
 **********************************************************************/


/**
  * @brief  Enable a specific peripheral on Bus (AHB, APB1, APB2).
  * @param  PeripheralName: Name/ID of the peripheral to be enabled.
  * @retval Return status indicating success or failure of the operation.
  */

RETURN_t RCC_RETURNtPeripheralEn(uint8_t BusType, uint8_t PeripheralName) ;


/**
  * @brief  Disable a specific peripheral on Bus (AHB, APB1, APB2).
  * @param  PeripheralName: Name/ID of the peripheral to be enabled.
  * @retval Return status indicating success or failure of the operation.
  */

RETURN_t RCC_RETURNtPeripheralDis(uint8_t BusType, uint8_t PeripheralName) ;


#endif /* MCAL_RCC_INC_RCC_INTERFACE_H_ */
