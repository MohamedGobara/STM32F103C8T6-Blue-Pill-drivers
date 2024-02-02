#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H




#include "stdint.h"
#include "Utils.h"
#include "STDTypes.h"

#include "MCAL/GPIO/inc/GPIO_interface.h"


#include "LCD/inc/LCD_config.h"
#include "LCD/inc/LCD_private.h"




void LCD_Init(void) ;

void LCD_WriteNumber(int32_t num) ;

void LCD_WriteChar(uint8_t ch) ;

void LCD_WriteString(uint8_t* str ) ;

void LCD_Clear(void) ;


void LCD_WriteBinary(uint8_t num) ;

void LCD_WriteHex(uint8_t num) ;

void LCD_ReturnHome(void) ;

void LCD_GoTo(uint8_t line , uint8_t cell) ;

void LCD_WriteNumber4D(uint32_t num) ;

void LCD_GoToClear(uint8_t line , uint8_t cell , uint8_t numOfCells) ;

void LCD_CreateCharacter(uint8_t* pattern , uint8_t location) ;


#endif /* LCD_INTERFACE_H */
