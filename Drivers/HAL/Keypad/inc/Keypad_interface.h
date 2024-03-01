/*
 * Keypad_interface.h
 *
 *  Created on: Feb 14, 2024
 *      Author: Gobara
 */

#ifndef HAL_KEYPAD_INC_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_INC_KEYPAD_INTERFACE_H_

#include <Keypad/inc/Keypad_config.h>
#include "stdint.h"
#include "Utils.h"
#include "STDTypes.h"

#include "GPIO/inc/GPIO_interface.h"

#define NO_KEY '#'
#define KEYPAD_RWOS    4
#define KEYPAD_COLUMNS 4


void KeyPad_vInit(void)  ;

uint8_t KeyPad_u8GetKey(void)  ;

#endif /* HAL_KEYPAD_INC_KEYPAD_INTERFACE_H_ */
