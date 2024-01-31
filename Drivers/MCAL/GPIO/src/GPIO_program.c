/*
 * File:   GPIO_program.c
 * Author: Mohamed Hussein
 * Date:   December 20, 2023 (Date of creation)
 *
 * Description:
 * ------------

 *
 * Usage:
 * ------

 *
 */


#include "stdint.h"
#include "Utils.h"
#include "STDTypes.h"

#include "GPIO/inc/GPIO_private.h"
#include "GPIO/inc/GPIO_config.h"
#include "GPIO/inc/GPIO_interface.h"



static GPIO_r* GPIO_ArraysOfPtr[Number_OfPorts] = {GPIOA , GPIOB, GPIOC} ;

RETURN_t GPIO_RETURNtPinInit(GPIO_PinConfig* Localptr_PinConfig) {

	RETURN_t  LocalRetState  =  OK_ret ;
	if((Localptr_PinConfig->Port_Name>=GPIO_PORTA&&Localptr_PinConfig->Port_Name<=GPIO_PORTC ) ||
			(Localptr_PinConfig->PIN_Name>=GPIO_Pin0&&Localptr_PinConfig->PIN_Name<=GPIO_Pin0 ) ){


		GPIO_r* LocalGPIO_Ptr = GPIO_ArraysOfPtr[Localptr_PinConfig->Port_Name] ;
		/* configure mode */
		MOD_NUM_OF_BITS(LocalGPIO_Ptr->CR[(Localptr_PinConfig->PIN_Name)/8] , ((Localptr_PinConfig->PIN_Name)%8)*4 , 4 , Localptr_PinConfig->PIN_MODE) ;
		/* configure set and reset */
		if(Localptr_PinConfig->PIN_Name==High_O){

			SET_BIT(LocalGPIO_Ptr->BSRR , Localptr_PinConfig->PIN_Name) ;

		}
		else if (Localptr_PinConfig->PIN_Name==LOW_O){

			SET_BIT(LocalGPIO_Ptr->BSRR , (Localptr_PinConfig->PIN_Name)+16 ) ;

		}
		else {
			LocalRetState =  ERROR_ret ;
		}

	}
	else {

		LocalRetState =  ERROR_ret ;
	}

	return LocalRetState  ;


}

RETURN_t GPIO_RETURNtPinOut(uint8_t Local_Portval , uint8_t Local_Pinval  , uint8_t Local_OutVal);

RETURN_t GPIO_RETURNtPinOut(uint8_t Local_Portval , uint8_t Local_Pinval  , uint8_t Local_OutVal);

uint8_t GPIO_u8PinRead(uint8_t Local_Portval ,  uint8_t Local_Pinval);

RETURN_t GPIO_RETURNtPinOut(uint8_t Local_Portval ,  uint8_t Local_Pinval  , uint8_t FuncationVal);
