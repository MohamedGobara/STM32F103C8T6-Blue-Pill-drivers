/*
 * File:   RCC_config.h
 * Author: Mohamed Hussein
 * Date:   December 16, 2023 (Date of creation)
 *
 * Description:
 * ------------
 * This header file contains configuration options for the Reset and Clock Control (RCC) module
 * in the STM32F103XX microcontroller.
 * It defines settings related to clock sources, prescalers, and PLL configurations.
 *
 * Usage:
 * ------
 * Users can tailor the RCC configurations by choosing options for Clock security, the main clock source,
 * PLL multiplication factor, Microcontroller Clock Output (MCO), USB prescaler, HSE divider for PLL entry,
 * as well as various bus clock prescalers (APB2, APB1, AHP).
 * These configurations play a vital role in determining system clock behavior and peripheral timings.
 * Integrate this file into the project to customize clock and peripheral settings based on system requirements.
 * It's an essential part of the RCC module and contributes to overall system clock management.
 *
 */

#ifndef MCAL_RCC_INC_RCC_CONFIG_H_
#define MCAL_RCC_INC_RCC_CONFIG_H_

/* Choose Clock security system */
#define Clock_security  CLOCK_DETECTOR_EN  // Options: CLOCK_DETECTOR_EN, CLOCK_DETECTOR_DIS

/* Choose main clock source among HSI, HSE, or PLL */
#define MAIN_CLK     HSI

/* Choose High speed external clock source among RCC_HSE_BYBASS , RCC_HSE_CRYSTAL */
#define RCC_HSE_MODE RCC_HSE_CRYSTAL

/* Configure PLL settings if used
 * PLL multiplication factor: Options listed in below
 *  PLLx2=0 ,
 *  PLLx3 ,
 *  PLLx4 ,
 *  PLLx5 ,
 *  PLLx6 ,
 *  PLLx7 ,
 *  PLLx8 ,
 *  PLLx9 ,
 *  PLLx10 ,
 *  PLLx11 ,
 *  PLLx12 ,
 *  PLLx13 ,
 *  PLLx14 ,
 *  PLLx16 ,
 *  PLLx16_2 ,
 *
 */
#define PLL_FACTOR PLLx10

/* Configure Microcontroller Clock Output (MCO) */
#define MCO_clk MCO_SYSCLK  // Options: MCO_NoCLK, MCO_SYSCLK, MCO_HSI, MCO_HSE, MCO_PLL_2

/* Configure USB peripheral clock prescaler */
#define USB_prescaler USB_PLL  // Options: USB_PLL/1_5, USB_PLL

/* HSE divider for PLL entry */
#define  HSE_PLLEnterSource  PLL_HSE_2  // Options: PLL_HSI_2 , PLL_HSE ,  PLL_HSE_2

/* Configure ADC  clock prescaler */
#define ADC_PRESCALER  PCLK2_8     // Options: PCLK2_2, PCLK2_4, PCLK2_6 , PCLK2_8

/* Configure APB2 bus clock prescaler */
#define APB2_prescaler APB2_HCLK_16  // Options: APB2_HCLK, APB2_HCLK_2, APB2_HCLK_4, APB2_HCLK_8, APB2_HCLK_16

/* Configure APB1 bus clock prescaler */
#define APB1_prescaler APB1_HCLK_4  // Options: APB1_HCLK, APB1_HCLK_2, APB1_HCLK_4, APB1_HCLK_8, APB1_HCLK_16

/* Configure AHB bus clock prescaler */
#define AHP_prescaler AHP_HCLK  // Options: AHP_HCLK, AHP_HCLK_2, AHP_HCLK_4, AHP_HCLK_8, AHP_HCLK_16, AHP_HCLK_64, AHP_HCLK_128, AHP_HCLK_256, AHP_HCLK_512


#endif /* MCAL_RCC_INC_RCC_CONFIG_H_ */
