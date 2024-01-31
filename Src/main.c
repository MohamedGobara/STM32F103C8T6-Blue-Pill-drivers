/*
 * File:   main.c
 * Author: Mohamed Hussein
 * Date:   December 12 , 2023 (Date of creation)
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

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdint.h>

#include "Utils.h"
#include "STDTypes.h"

#include "RCC/inc/RCC_private.h"
#include "RCC/inc/RCC_config.h"
#include "RCC/inc/RCC_interface.h"


#include "GPIO/inc/GPIO_private.h"
#include "GPIO/inc/GPIO_config.h"
#include "GPIO/inc/GPIO_interface.h"


void SwitchAccessToUnPreleivage(void) {

	/***************************
	 * this is control register you can't use simple assemble
	 * here you ,must use MRS \  MSR
	 * MRS -> mov register special
	 * MSR -  mov special register
	 */

	/* Read control register */
	__asm volatile ("MRS R0 , CONTROL") ;

	/* modify to one  */

	__asm volatile ("ORR R0 ,#0x01") ;

	/* write new value into control */

	__asm volatile ("MSR CONTROL , R0") ;

}



void GenerateInterrupt(void)
{

	uint32_t* pSTIR= (uint32_t*)0xE000EF00;
	uint32_t* pISER0= (uint32_t*)0xE000E100;

	//Enable IRQ3 Interrupt
	*pISER0 |= 1<<3;

	//Generate Software interrupt for IRQ3
	*pSTIR = (3 &0x1FF);
}



/*
 *
 * here the test for test :
 *
 * second test
 *
 *
 * test all the compenents and check if any compnent fiekd
 *
 *
 */

int main()
{


	GPIO_PinConfig Pina2 = {

			GPIO_PORTA ,
			GPIO_Pin2 ,
			GPIO_PinModeOutput_PP ,
			LOW_O

	} ;


	RCC_RETURNtInit() ;

	RCC_RETURNtPeripheralEn(APB2, PORTA_APB2_peripherals) ;


	GPIO_RETURNtPinInit(&Pina2) ;

	Pina2.PIN_DefaultOut = High_O ;

	GPIO_RETURNtPinInit(&Pina2) ;


	return 0;
}



