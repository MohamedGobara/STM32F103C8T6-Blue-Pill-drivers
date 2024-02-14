/*
 * LCD_config.c
 *
 *  Created on: Feb 15, 2024
 *      Author: Gobara
 */
#include "GPIO/inc/GPIO_interface.h"
#include "LCD/inc/LCD_interface.h"

GPIO_PinConfig D7_PIN = { GPIO_PORTB, GPIO_Pin12,
GPIO_PinModeOutput_PP, LOW_O

};
GPIO_PinConfig D6_PIN = { GPIO_PORTB, GPIO_Pin13,
GPIO_PinModeOutput_PP, LOW_O

};
GPIO_PinConfig D5_PIN = { GPIO_PORTB, GPIO_Pin14,
GPIO_PinModeOutput_PP, LOW_O

};
GPIO_PinConfig D4_PIN = { GPIO_PORTB, GPIO_Pin15,
GPIO_PinModeOutput_PP, LOW_O

};
GPIO_PinConfig EN_PIN = { GPIO_PORTA, GPIO_Pin8,
GPIO_PinModeOutput_PP, LOW_O

};
GPIO_PinConfig RS_PIN = { GPIO_PORTA, GPIO_Pin11,
GPIO_PinModeOutput_PP, LOW_O

};

