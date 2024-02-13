/*
 * File:   RCC_private.h
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

#ifndef MCAL_RCC_INC_RCC_PRIVATE_H_
#define MCAL_RCC_INC_RCC_PRIVATE_H_

// Constants defining clock detector enable/disable

#define CLOCK_DETECTOR_EN  1
#define CLOCK_DETECTOR_DIS 0



// Constants representing different clock sources

#define HSI 0
#define HSE 1
#define PLL 2


#define RCC_HSE_CRYSTAL  0
#define RCC_HSE_BYBASS   1


// Enumeration defining PLL multiplication factors

typedef enum {

	PLLx2=0 ,
	PLLx3 ,
	PLLx4 ,
	PLLx5 ,
	PLLx6 ,
	PLLx7 ,
	PLLx8 ,
	PLLx9 ,
	PLLx10 ,
	PLLx11 ,
	PLLx12 ,
	PLLx13 ,
	PLLx14 ,
	PLLx16 ,
	PLLx16_2 ,



}PLL_factor_t ;

// Constants representing MCO (Microcontroller Clock Output) settings

#define MCO_NoCLK   0b0
#define MCO_SYSCLK  0b100
#define MCO_HSI     0b101
#define MCO_HSE		0b110
#define MCO_PLL_2	0b111

// Constants defining USB PLL configurations


#define USB_PLL_1_5 0

#define USB_PLL    1


// Constants defining PLL HSE configurations

#define PLL_HSI_2    0
#define PLL_HSE      1
#define PLL_HSE_2    2


/* defining ADC if YOU NEED DIVISTION ON FACTOR  */


#define PCLK2_2  0
#define PCLK2_4  1
#define PCLK2_6  2
#define PCLK2_8  3

/* defining APB2  IF YOU NEED DIVISTION ON FACTOR  */

#define APB2_HCLK     0b0
#define APB2_HCLK_2   0b100
#define APB2_HCLK_4   0b101
#define APB2_HCLK_8   0b110
#define APB2_HCLK_16  0b111


/* defining APB1  IF YOU NEED DIVISTION ON FACTOR  */

#define APB1_HCLK     0b0
#define APB1_HCLK_2   0b100
#define APB1_HCLK_4   0b101
#define APB1_HCLK_8   0b110
#define APB1_HCLK_16  0b111


/* defining AHB  IF YOU NEED DIVISTION ON FACTOR  */
#define AHP_HCLK      0b0
#define AHP_HCLK_2    0b1000
#define AHP_HCLK_4    0b1001
#define AHP_HCLK_8    0b1010
#define AHP_HCLK_16   0b1011
#define AHP_HCLK_64   0b1100
#define AHP_HCLK_128  0b1101
#define AHP_HCLK_256  0b1110
#define AHP_HCLK_512  0b1111

// Enum defining name of buses

typedef enum {
AHB,
APB1,
APB2
}Buses_t ;

// Enum defining AHB peripherals and their bit positions
typedef enum {

	DMA1_AHB_peripherals ,
	DMA2_AHB_peripherals  ,
	SRAM_AHB_peripherals  ,
	FLITF_AHB_peripherals=4  ,
	CRC_AHB_peripherals=6  ,
	FSMC_AHB_peripherals=8   ,
	SDIO_AHB_peripherals=10 ,

} AHB_peripherals;

// Enum defining APB2 peripherals and their bit positions


typedef enum {

	AFIO_APB2_peripherals ,
	PORTA_APB2_peripherals=2 ,
	PORTB_APB2_peripherals ,
	PORTC_APB2_peripherals,
	ADC1_APB2_peripherals=9 ,
	ADC2_APB2_peripherals ,
	TIM1_APB2_peripherals ,
	SPI1_APB2_peripherals ,
	TIM8_APB2_peripherals ,
	USART1_APB2_peripherals ,
	ADC3_APB2_peripherals ,
	TIM9_APB2_peripherals=19 ,
	TIM10_APB2_peripherals ,
	TIM11_APB2_peripherals ,




} APB2_peripherals;

// Enum defining APB1 peripherals and their bit positions


typedef enum {

	TIM2_APB1_peripherals ,
	TIM3_APB1_peripherals ,
	TIM4_APB1_peripherals ,
	TIM5_APB1_peripherals ,
	TIM6_APB1_peripherals ,
	TIM7_APB1_peripherals ,
	TIM12_APB1_peripherals ,
	TIM13_APB1_peripherals ,
	TIM14_APB1_peripherals ,
	WWDG_APB1_peripherals=11 ,
	SPI2_APB1_peripherals=14,
	SPI3_APB1_peripherals ,
	USART2_APB1_peripherals=17 ,
	USART3_APB1_peripherals ,
	UART4_APB1_peripherals ,
	I2C1_APB1_peripherals ,
	USB_APB1_peripherals ,
	CAN_APB1_peripherals=25 ,
	BKP_APB1_peripherals=27 ,
	PWR_APB1_peripherals ,

} APB1_peripherals;



#define RCC_BASE_ADDRESS	0x40021000UL


typedef struct{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_REG;

#define RCC  ((RCC_REG*)RCC_BASE_ADDRESS)





#endif /* MCAL_RCC_INC_RCC_PRIVATE_H_ */
