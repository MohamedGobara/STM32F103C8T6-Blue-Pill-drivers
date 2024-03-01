/*
 * File:   GPIO_interafce.c
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

#ifndef MCAL_GPIO_INC_GPIO_INTERFACE_H_
#define MCAL_GPIO_INC_GPIO_INTERFACE_H_

#include "stdint.h"
#include "Utils.h"
#include "STDTypes.h"

#include "GPIO/inc/GPIO_private.h"
#include "GPIO/inc/GPIO_config.h"

#define GPIO_PinModeOutput_PP		0b0001
#define GPIO_PinModeOutput_OD		0b0110

#define GPIO_PinModeAF_PP			0b1011

#define GPIO_PinModeAF_OD10M		0b1101
#define GPIO_PinModeAF_OD2M			0b1110
#define GPIO_PinModeAF_OD500M		0b1111

#define GPIO_PinModeInputAnalog		0b0000
#define GPIO_PinModeInputFloating	0b0100

#define GPIO_PinModeInput_PU		0b11000
#define GPIO_PinModeInput_PD		0b01000

typedef enum {
	LOW_O, High_O,
} GPIO_PinStateOut;

typedef enum {
	GPIO_PORTA, GPIO_PORTB, GPIO_PORTC, GPIO_PortsOutOfRange
} GPIO_Ports;

typedef enum {
	GPIO_Pin0,
	GPIO_Pin1,
	GPIO_Pin2,
	GPIO_Pin3,
	GPIO_Pin4,
	GPIO_Pin5,
	GPIO_Pin6,
	GPIO_Pin7,
	GPIO_Pin8,
	GPIO_Pin9,
	GPIO_Pin10,
	GPIO_Pin11,
	GPIO_Pin12,
	GPIO_Pin13,
	GPIO_Pin14,
	GPIO_Pin15,
	GPIO_PinsOutOfRange
} GPIO_Pins;



typedef struct {
	GPIO_Ports Port_Name;
	GPIO_Pins PIN_Name;
	uint8_t PIN_MODE; /* input / output  / alternate function*/
	GPIO_PinStateOut PIN_DefaultOut; /*     High  / Low  */

} GPIO_PinConfig;

#define Number_OfPorts 3



/**
 * @brief  Initializes a GPIO pin based on the given configuration.
 * @param  Localptr_PinConfig: Pointer to a structure containing pin configuration.
 * @retval RETURN_t: Indicates the success or failure of the initialization.
 */
RETURN_t GPIO_RETURNtPinInit(GPIO_PinConfig *Localptr_PinConfig);

/**
 * @brief  Sets the output value of a GPIO pin.
 * @param  Local_PortName: The GPIO port to which the pin belongs.
 * @param  Local_PinName: The specific pin in the port.
 * @param  Local_OutVal: The output value to be set (High_O or LOW_O).
 * @retval RETURN_t: Indicates the success or failure of the operation.
 */
RETURN_t GPIO_RETURNtPinOut(GPIO_Ports Local_PortName, GPIO_Pins Local_PinName,
		GPIO_PinStateOut Local_OutVal);

/**
 * @brief  Reads the current state of a GPIO pin.
 * @param  Local_PortName: The GPIO port to which the pin belongs.
 * @param  Local_PinName: The specific pin in the port.
 * @retval GPIO_PinStateOut: The current state of the GPIO pin (High_O or LOW_O).
 */
GPIO_PinStateOut GPIO_u8PinRead(GPIO_Ports Local_PortName,
		GPIO_Pins Local_PinName);

/**
 * @brief  Toggles the output value of a GPIO pin based on a given function.
 * @param  Local_PortName: The GPIO port to which the pin belongs.
 * @param  Local_PinName: The specific pin in the port.
 * @retval RETURN_t: Indicates the success or failure of the operation.
 */
RETURN_t GPIO_RETURNtPinToggle(GPIO_Ports Local_PortName,
		GPIO_Pins Local_PinName);

#endif /* MCAL_GPIO_INC_GPIO_INTERFACE_H_ */
