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

#include <stdint.h>

#include<string.h>

#include "Utils.h"
#include "STDTypes.h"

#include "RCC/inc/RCC_interface.h"
#include "SysTick/inc/SysTick_interface.h"
#include "GPIO/inc/GPIO_interface.h"
#include "NVIC/inc/NVIC_interface.h"
#include "EXTI/inc/EXTI_interface.h"

#include "LCD/inc/LCD_interface.h"
#include "Keypad/inc/Keypad_interface.h"

void SwitchAccessToUnPreleivage(void) {

	/***************************
	 * this is control register you can't use simple assemble
	 * here you ,must use MRS \  MSR
	 * MRS -> mov register special
	 * MSR -  mov special register
	 */

	/* Read control register */
	__asm volatile ("MRS R0 , CONTROL");

	/* modify to one  */

	__asm volatile ("ORR R0 ,#0x01");

	/* write new value into control */

	__asm volatile ("MSR CONTROL , R0");

}

void GenerateInterrupt(void) {

	uint32_t *pSTIR = (uint32_t*) 0xE000EF00;
	uint32_t *pISER0 = (uint32_t*) 0xE000E100;

	//Enable IRQ3 Interrupt
	*pISER0 |= 1 << 3;

	//Generate Software interrupt for IRQ3
	*pSTIR = (3 & 0x1FF);
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

GPIO_PinConfig Pina2 = {

GPIO_PORTA, GPIO_Pin2,
GPIO_PinModeOutput_PP, LOW_O

};

void TogglePinB0(void) {

	LCD_Clear();
	LCD_WriteString("ISR now..");
	SysTick_vDelayms(1000);
	LCD_WriteString("1");
	SysTick_vDelayms(500);
	LCD_WriteString("2");
	SysTick_vDelayms(500);
	LCD_WriteString("3");
	SysTick_vDelayms(500);
	// GPIO_RETURNtPinToggle(GPIO_PORTA, GPIO_Pin2) ;
//SysTick_vDelayms(1000) ;

}

int main() {

	NVIC_SetPriorityConfig(NVIC_0GROUB_16SUB);

	NVIC_voidSetInterruptPriority(EXTI0_LINE, 0, 0);

	NVIC_vEnableInterrupt(EXTI0_LINE);


	RCC_RETURNtInit();

	RCC_RETURNtPeripheralEn(APB2, AFIO_APB2_peripherals);

	RCC_RETURNtPeripheralEn(APB2, PORTA_APB2_peripherals);
	RCC_RETURNtPeripheralEn(APB2, PORTB_APB2_peripherals);

	/* alternate EXT0 -> PORTB0 */
	//*(uint32_t*) 0x40010008 = 1;

	GPIO_RETURNtPinInit(&Pina2);


	//GPIO_RETURNtPinInit(&Pinb0);


	GPIO_PinConfig Pinb0 = { GPIO_PORTB, GPIO_Pin0,
		GPIO_PinModeInput_PU, High_O

		};
	SysTick_vInit();

	LCD_Init();
	KeyPad_vInit();

	/*EXTI_RETURNtSetInterruptEdge(EXTI_LINE0, FALLING_EDGE) ;
	 EXTI_RETURNtSetInterruptStatus(EXTI_LINE0 ,EXTINonMasked) ;
	 EXTI_RETURNtSetCalbackFunction(EXTI_LINE0, TogglePinB0)  ;*/
	uint8_t result = NO_KEY;
	while (1) {

		result = KeyPad_u8GetKey();

		if (result != NO_KEY) {

			LCD_WriteChar(result);

		}

		/*
		 LCD_GoTo(0, 0) ;
		 LCD_WriteNumber(x++) ;
		 LCD_WriteString("               ") ;
		 SysTick_vDelayms(1500) ;
		 if(x==65000) {

		 x= 0 ;
		 }

		 */

	}

	/*

	 GPIO_RETURNtPinOut(GPIO_PORTA, GPIO_Pin2, High_O) ;

	 GPIO_RETURNtPinOut(GPIO_PORTA, GPIO_Pin2, LOW_O) ;

	 if(GPIO_u8PinRead(GPIO_PORTA, GPIO_Pin2)==LOW_O){

	 GPIO_RETURNtPinOut(GPIO_PORTA, GPIO_Pin2, High_O) ;

	 }
	 GPIO_RETURNtPinToggle(GPIO_PORTA, GPIO_Pin2) ;

	 GPIO_RETURNtPinToggle(GPIO_PORTA, GPIO_Pin2) ;

	 GPIO_RETURNtPinToggle(GPIO_PORTA, GPIO_Pin2) ;

	 GPIO_RETURNtPinToggle(GPIO_PORTA, GPIO_Pin2) ;

	 */

	return 0;
}

void WWDG_IRQHandler(void) {

	printf("Hello ");

}

