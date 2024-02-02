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



/**
  * @brief  Initializes a GPIO pin based on the given configuration.
  * @param  Localptr_PinConfig: Pointer to a structure containing pin configuration.
  * @retval RETURN_t: Indicates the success or failure of the initialization.
  */
RETURN_t GPIO_RETURNtPinInit(GPIO_PinConfig* Localptr_PinConfig);

/**
  * @brief  Sets the output value of a GPIO pin.
  * @param  Local_PortName: The GPIO port to which the pin belongs.
  * @param  Local_PinName: The specific pin in the port.
  * @param  Local_OutVal: The output value to be set (High_O or LOW_O).
  * @retval RETURN_t: Indicates the success or failure of the operation.
  */
RETURN_t GPIO_RETURNtPinOut(GPIO_Ports Local_PortName, GPIO_Pins Local_PinName, GPIO_PinStateOut Local_OutVal);

/**
  * @brief  Reads the current state of a GPIO pin.
  * @param  Local_PortName: The GPIO port to which the pin belongs.
  * @param  Local_PinName: The specific pin in the port.
  * @retval GPIO_PinStateOut: The current state of the GPIO pin (High_O or LOW_O).
  */
GPIO_PinStateOut GPIO_u8PinRead(GPIO_Ports Local_PortName, GPIO_Pins Local_PinName);

/**
  * @brief  Toggles the output value of a GPIO pin based on a given function.
  * @param  Local_PortName: The GPIO port to which the pin belongs.
  * @param  Local_PinName: The specific pin in the port.
  * @retval RETURN_t: Indicates the success or failure of the operation.
  */
RETURN_t GPIO_RETURNtPinToggle(GPIO_Ports Local_PortName, GPIO_Pins Local_PinName);


#endif /* MCAL_GPIO_INC_GPIO_INTERFACE_H_ */
