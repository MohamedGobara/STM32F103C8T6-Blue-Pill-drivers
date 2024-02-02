#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H



#define _4_BIT  1
#define _8_BIT  2

#define LCD_MODE  _4_BIT

/* main pins in any mode */


#define LCD_RS_PORT      GPIO_PORTA
#define LCD_E_PORT       GPIO_PORTA

#define LCD_RS_PIN       GPIO_Pin11
#define LCD_E_PIN        GPIO_Pin8

/* is use 4 BIT MODE */


#define D7_PORT  GPIO_PORTB
#define D6_PORT  GPIO_PORTB
#define D5_PORT  GPIO_PORTB
#define D4_PORT  GPIO_PORTB

#define D7  GPIO_Pin12
#define D6  GPIO_Pin13
#define D5  GPIO_Pin14
#define D4  GPIO_Pin15

/* is use 8 BIT MODE */

#define LCD_PORT    PD

#endif /* LCD_CONFIG_H */
