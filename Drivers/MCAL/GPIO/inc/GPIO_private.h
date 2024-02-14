/*
 * File:   GPIO_private.c
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

#ifndef MCAL_GPIO_INC_GPIO_PRIVATE_H_
#define MCAL_GPIO_INC_GPIO_PRIVATE_H_





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
	LOW_O ,
	High_O,
}GPIO_PinStateOut ;


typedef enum {
	GPIO_PORTA,
	GPIO_PORTB ,
	GPIO_PORTC ,
	GPIO_PortsOutOfRange
}GPIO_Ports ;


typedef enum {
	GPIO_Pin0,
	GPIO_Pin1 ,
	GPIO_Pin2 ,
	GPIO_Pin3 ,
	GPIO_Pin4 ,
	GPIO_Pin5 ,
	GPIO_Pin6 ,
	GPIO_Pin7 ,
	GPIO_Pin8 ,
	GPIO_Pin9 ,
	GPIO_Pin10,
	GPIO_Pin11,
	GPIO_Pin12,
	GPIO_Pin13,
	GPIO_Pin14,
	GPIO_Pin15,
	GPIO_PinsOutOfRange
}GPIO_Pins  ;

#define GPIOA_BASE_ADDRESS   0x40010800UL
#define GPIOB_BASE_ADDRESS   0x40010C00UL
#define GPIOC_BASE_ADDRESS   0x40011000UL
#define AFIO_BASE_ADDRESS    0x40010000UL

/*
 * port 0 : 2
 *
 *
 * pin 0 : 15
 *
 */

typedef struct {

	//volatile uint32_t CRL ;
	//volatile uint32_t CRH ;
	volatile uint32_t CR[2] ;
	volatile uint32_t IDR ;
	volatile uint32_t ODR ;
	volatile uint32_t BSRR ;
	volatile uint32_t BRR ;
	volatile uint32_t LCKR ;

}GPIO_r ;

typedef struct {

	volatile uint32_t EVCR ;
	volatile uint32_t MAPR ;
	volatile uint32_t EXTICR1 ;
	volatile uint32_t EXTICR2 ;
	volatile uint32_t EXTICR3 ;
	volatile uint32_t EXTICR4 ;
	volatile uint32_t RESERVED[2] ;
	volatile uint32_t MAPR2 ;

}AFIO_r ;


#define GPIOA ((GPIO_r*)GPIOA_BASE_ADDRESS)
#define GPIOB ((GPIO_r*)GPIOB_BASE_ADDRESS)
#define GPIOC ((GPIO_r*)GPIOC_BASE_ADDRESS)

#define AFIO  ((*AFIO_r)AFIO_BASE_ADDRESS)


typedef struct {
	GPIO_Ports Port_Name   ;
	GPIO_Pins  PIN_Name      ;
	uint8_t    PIN_MODE       ; /* input / output  / alternate function*/
	GPIO_PinStateOut    PIN_DefaultOut ; /*     High  / Low  */
	/*
	 * pullup \ pulldown
	 * speed
	 *
	 */
}GPIO_PinConfig ;




#define Number_OfPorts 3



#endif /* MCAL_GPIO_INC_GPIO_PRIVATE_H_ */
