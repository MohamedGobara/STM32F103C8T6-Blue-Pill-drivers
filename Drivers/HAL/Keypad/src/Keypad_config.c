/*
 * Keypad_config.c
 *
 *  Created on: Feb 14, 2024
 *      Author: Gobara
 */
#include "Keypad/inc/Keypad_interface.h"

GPIO_PinConfig row1_config = { GPIO_PORTA, GPIO_Pin4, GPIO_PinModeOutput_PP,High_O };
GPIO_PinConfig row2_config = { GPIO_PORTA, GPIO_Pin5, GPIO_PinModeOutput_PP,High_O };
GPIO_PinConfig row3_config = { GPIO_PORTA, GPIO_Pin6, GPIO_PinModeOutput_PP,High_O };
GPIO_PinConfig row4_config = { GPIO_PORTA, GPIO_Pin7, GPIO_PinModeOutput_PP,High_O };

// Initialize GPIO pins for keypad columns as inputs
GPIO_PinConfig col1_config = { GPIO_PORTB, GPIO_Pin11,GPIO_PinModeInputFloating, High_O };
GPIO_PinConfig col2_config = { GPIO_PORTB, GPIO_Pin10,GPIO_PinModeInputFloating, High_O };
GPIO_PinConfig col3_config = { GPIO_PORTB, GPIO_Pin1, GPIO_PinModeInputFloating,High_O };
GPIO_PinConfig col4_config = { GPIO_PORTB, GPIO_Pin0, GPIO_PinModeInputFloating,High_O };

uint8_t KeyPad_KeysConfgArr[KEYPAD_RWOS][KEYPAD_COLUMNS] = {

{ '7', '8', '9', 'A' },
{ '4', '5', '6', 'B' },
{ '1', '2', '3', 'C' },
{ '=', '0', 'E', 'D' },

};

/*

 GPIO_Pins Keaypad_RowsArr[4] = {row1_config.PIN_Name , row2_config.PIN_Name , row3_config.PIN_Name , row4_config.PIN_Name} ;


 GPIO_Pins Keaypad_ColuArr[4] = {col1_config.PIN_Name , col2_config.PIN_Name , col3_config.PIN_Name , col4_config.PIN_Name} ;
*/

// Arrays to hold GPIO pins for rows and columns
GPIO_Pins Keypad_RowsArr[4];
GPIO_Pins Keypad_ColuArr[4];
