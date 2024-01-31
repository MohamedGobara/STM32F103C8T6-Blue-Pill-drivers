/*
 * File:   RCC_program.c
 * Author: Mohamed Hussein
 * Date:   December 16, 2023 (Date of creation)
 *
 * Description:
 * ------------
 * This file contains functions related to the configuration and control of the Reset and Clock Control (RCC) peripheral
 * on a microcontroller. The RCC is responsible for managing system clocks and various peripheral clocks.
 * The code sets specific prescalers and configurations for different clock sources and peripherals.
 *
 * Usage:
 * ------
 * The main function here is `RCC_RETURNtInit()`, which initializes the RCC settings based on predefined configurations.
 * To use this code, include the necessary header files and call `RCC_RETURNtInit()` to configure the RCC.
 * There are also placeholder functions for enabling/disabling specific peripherals on the AHB, APB1, and APB2 buses.
 * These functions can be used to control the clock supply to individual peripherals.
 * This file is likely part of a larger project, responsible for configuring the system's clocking infrastructure.
 *
 */


#include "stdint.h"
#include "Utils.h"
#include "STDTypes.h"

#include "RCC/inc/RCC_interface.h"
#include "RCC/inc/RCC_config.h"
#include "RCC/inc/RCC_private.h"



RETURN_t RCC_RETURNtInit(void) {

    RETURN_t Local_error_state = OK_ret ;

    /* Configuring ADC prescaler */
    MOD_NUM_OF_BITS(RCC->CFGR, 14, 2, ADC_PRESCALER);

    /* Configuring APB2 high-speed prescaler */
    MOD_NUM_OF_BITS(RCC->CFGR, 11, 3, APB2_prescaler);

    /* Configuring APB1 low-speed prescaler */
    MOD_NUM_OF_BITS(RCC->CFGR, 8, 3, APB1_prescaler);

    /* Configuring AHB prescaler */
    MOD_NUM_OF_BITS(RCC->CFGR, 4, 4, AHP_prescaler);

    /* Configuring Microcontroller clock output */
    MOD_NUM_OF_BITS(RCC->CFGR, 24, 3, MCO_clk);

    /* Configuring clock security system */
    MOD_NUM_OF_BITS(RCC->CR, 19, 0, Clock_security);

    /* Configuring main clock source */
    #if MAIN_CLK == HSI
        SET_BIT(RCC->CR, 0);
        while(!READ_BIT(RCC->CR, 1));
        MOD_NUM_OF_BITS(RCC->CFGR, 0, 2, 0);
    #elif MAIN_CLK == HSE
        /* Configuring HSE mode (Bypass or Crystal) */
        #if(RCC_HSE_MODE == RCC_HSE_BYBASS)
            SET_BIT(RCC->CR, 18);
        #elif(RCC_HSE_MODE == RCC_HSE_CRYSTAL)
            CLEAR_BIT(RCC->CR, 18);
        #else
            Local_error_state = ERROR_ret;
        #endif

        SET_BIT(RCC->CR, 16);
        while(!READ_BIT(RCC->CR, 17));
        MOD_NUM_OF_BITS(RCC->CFGR, 0, 2, 1);
    #elif MAIN_CLK == PLL
        /* Configuring PLL source */
        /* Options: PLL_HSI_2, PLL_HSE, PLL_HSE_2 */
        #if HSE_PLLEnterSource == PLL_HSI_2
            CLEAR_BIT(RCC->CFGR, 16);
        #elif HSE_PLLEnterSource == PLL_HSE
            CLEAR_BIT(RCC->CFGR, 17);
            SET_BIT(RCC->CFGR, 16);
        #elif HSE_PLLEnterSource == PLL_HSE_2
            SET_BIT(RCC->CFGR, 17);
            SET_BIT(RCC->CFGR, 16);
        #else
            Local_error_state = ERROR_ret;
        #endif

        /* Configuring PLL factor */
        MOD_NUM_OF_BITS(RCC->CFGR, 18, 4, PLL_FACTOR);

        /* Enabling PLL */
        SET_BIT(RCC->CR, 24);
        MOD_NUM_OF_BITS(RCC->CFGR, 0, 2, 2);
        /* Turning off HSI */
        CLEAR_BIT(RCC->CR, 0);
    #endif

    return Local_error_state;
}

/*  functions for enabling various peripherals */


RETURN_t RCC_RETURNtPeripheralEn(uint8_t BusType, uint8_t PeripheralName) {
    RETURN_t Local_error_state = OK_ret ;


	switch(BusType){

	case AHB :

		SET_BIT(RCC->AHBENR ,PeripheralName ) ;

		break ;
	case APB1 :
		SET_BIT(RCC->APB1ENR ,PeripheralName ) ;

		break ;

	case APB2 :
		SET_BIT(RCC->APB2ENR ,PeripheralName ) ;
		break  ;

	default :
		Local_error_state = ERROR_ret ;
		break ;

	}
	return  Local_error_state  ;
}
/*  functions for enabling various peripherals */


RETURN_t RCC_RETURNtPeripheralDis(uint8_t BusType, uint8_t PeripheralName) {

	  RETURN_t Local_error_state = OK_ret ;


		switch(BusType){

		case AHB :

			CLEAR_BIT(RCC->AHBENR ,PeripheralName ) ;

			break ;
		case APB1 :
			CLEAR_BIT(RCC->APB1ENR ,PeripheralName ) ;

			break ;

		case APB2 :
			CLEAR_BIT(RCC->APB2ENR ,PeripheralName ) ;
			break  ;

		default :
			Local_error_state = ERROR_ret ;
			break ;

		}
		return  Local_error_state  ;
}
