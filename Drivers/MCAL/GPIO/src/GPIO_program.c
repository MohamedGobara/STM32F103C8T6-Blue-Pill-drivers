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

#include "GPIO/inc/GPIO_interface.h"


static GPIO_r *GPIO_ArraysOfPtr[Number_OfPorts] = { GPIOA, GPIOB, GPIOC };

RETURN_t GPIO_RETURNtPinInit(GPIO_PinConfig *Localptr_PinConfig) {

	RETURN_t LocalRetState = OK_ret;
	if ((Localptr_PinConfig->Port_Name >= GPIO_PORTA
			&& Localptr_PinConfig->Port_Name <= GPIO_PORTC)
			|| (Localptr_PinConfig->PIN_Name >= GPIO_Pin0
					&& Localptr_PinConfig->PIN_Name <= GPIO_Pin0)) {

		GPIO_r *LocalGPIO_Ptr = GPIO_ArraysOfPtr[Localptr_PinConfig->Port_Name];
		/* configure mode */
		MOD_NUM_OF_BITS(LocalGPIO_Ptr->CR[(Localptr_PinConfig->PIN_Name) / 8],
				((Localptr_PinConfig->PIN_Name) % 8) * 4, 4,
				Localptr_PinConfig->PIN_MODE);



if( Localptr_PinConfig->PIN_MODE == GPIO_PinModeInput_PU)
{
	SET_BIT(LocalGPIO_Ptr->ODR ,Localptr_PinConfig->PIN_Name );


}


else if( Localptr_PinConfig->PIN_MODE == GPIO_PinModeInput_PD )
{
	CLEAR_BIT(LocalGPIO_Ptr->ODR ,Localptr_PinConfig->PIN_Name );

}

		/* configure set and reset */
		if (Localptr_PinConfig->PIN_MODE == High_O) {

			SET_BIT(LocalGPIO_Ptr->BSRR , Localptr_PinConfig->PIN_Name);

		} else if (Localptr_PinConfig->PIN_MODE == LOW_O) {

			SET_BIT(LocalGPIO_Ptr->BSRR , ((Localptr_PinConfig->PIN_Name)+GPIO_PortsOutOfRange) );

		} else {
			LocalRetState = ERROR_ret;
		}

	} else {

		LocalRetState = ERROR_ret;
	}

	return LocalRetState;

}

/**
 * @brief  Sets the output value of a GPIO pin.
 * @param  Local_PortName: The GPIO port to which the pin belongs.
 * @param  Local_PinName: The specific pin in the port.
 * @param  Local_OutVal: The output value to be set (High_O or LOW_O).
 * @retval RETURN_t: Indicates the success or failure of the operation.
 */
RETURN_t GPIO_RETURNtPinOut(GPIO_Ports Local_PortName, GPIO_Pins Local_PinName,GPIO_PinStateOut Local_OutVal) {

	RETURN_t local_RETURN_t = OK_ret;
	if (Local_PortName >= GPIO_PortsOutOfRange|| Local_PinName >= GPIO_PinsOutOfRange) {

		local_RETURN_t = ERROR_ret;

	} else {

		if (Local_OutVal == High_O) {

			SET_BIT(GPIO_ArraysOfPtr[Local_PortName]->BSRR ,Local_PinName) ;

		}

		else if (Local_OutVal == LOW_O) {

			SET_BIT(GPIO_ArraysOfPtr[Local_PortName]->BSRR ,(Local_PinName+GPIO_PinsOutOfRange) ) ;

		} else {

			local_RETURN_t = ERROR_ret;

		}

	}

	return local_RETURN_t;
}

/**
 * @brief  Reads the current state of a GPIO pin.
 * @param  Local_PortName: The GPIO port to which the pin belongs.
 * @param  Local_PinName: The specific pin in the port.
 * @retval GPIO_PinStateOut: The current state of the GPIO pin (High_O or LOW_O).
 */
GPIO_PinStateOut GPIO_u8PinRead(GPIO_Ports Local_PortName,GPIO_Pins Local_PinName){

		return READ_BIT(GPIO_ArraysOfPtr[Local_PortName]->IDR ,Local_PinName )== High_O?High_O:LOW_O ;


}

/**
 * @brief  Toggles the output value of a GPIO pin based on a given function.
 * @param  Local_PortName: The GPIO port to which the pin belongs.
 * @param  Local_PinName: The specific pin in the port.
 * @retval RETURN_t: Indicates the success or failure of the operation.
 */
RETURN_t GPIO_RETURNtPinToggle(GPIO_Ports Local_PortName,GPIO_Pins Local_PinName){

	RETURN_t local_RETURN_t = OK_ret;
	if (Local_PortName >= GPIO_PortsOutOfRange|| Local_PinName >= GPIO_PinsOutOfRange) {

		local_RETURN_t = ERROR_ret;

	} else {

		READ_BIT(GPIO_ArraysOfPtr[Local_PortName]->IDR  , Local_PinName)== High_O?
				CLEAR_BIT(GPIO_ArraysOfPtr[Local_PortName]->ODR ,Local_PinName):
				    SET_BIT(GPIO_ArraysOfPtr[Local_PortName]->ODR ,Local_PinName) ;

		}



	return local_RETURN_t;

}

