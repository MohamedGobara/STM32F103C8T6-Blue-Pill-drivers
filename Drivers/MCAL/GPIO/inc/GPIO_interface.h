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



RETURN_t GPIO_RETURNtPinInit(GPIO_PinConfig* Localptr_PinConfig);

RETURN_t GPIO_RETURNtPinOut(uint8_t Local_Portval ,  uint8_t Local_Pinval  , uint8_t Local_OutVal);

RETURN_t GPIO_RETURNtPinOut(uint8_t Local_Portval ,  uint8_t Local_Pinval  , uint8_t Local_OutVal);

uint8_t GPIO_u8PinRead(uint8_t Local_Portval ,  uint8_t Local_Pinval);

RETURN_t GPIO_RETURNtPinOut(uint8_t Local_Portval ,  uint8_t Local_Pinval  , uint8_t FuncationVal);


#endif /* MCAL_GPIO_INC_GPIO_INTERFACE_H_ */
