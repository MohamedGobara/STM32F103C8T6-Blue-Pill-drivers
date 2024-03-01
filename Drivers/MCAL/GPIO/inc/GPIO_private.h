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
	volatile uint32_t CR[2];
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;

} GPIO_r;

typedef struct {

	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t RESERVED[2];
	volatile uint32_t MAPR2;

} AFIO_r;

#define GPIOA ((GPIO_r*)GPIOA_BASE_ADDRESS)
#define GPIOB ((GPIO_r*)GPIOB_BASE_ADDRESS)
#define GPIOC ((GPIO_r*)GPIOC_BASE_ADDRESS)

#define AFIO  ((AFIO_r*)AFIO_BASE_ADDRESS)


#endif /* MCAL_GPIO_INC_GPIO_PRIVATE_H_ */
