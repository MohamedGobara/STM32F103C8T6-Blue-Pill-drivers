#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


/********************** Macro Declarations ***************************************/
#define EXTI_BASEADDRESS  0x40010400UL

/*********************  Macro Function Declarations ****************************/

/*********************  Data Type Declarations ***********************************/
/*  Register map in structure type */
typedef struct{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RSTR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;

}EXTI_t;

/*********************  Software Interfaces Declarations "APIs" *****************/
/*  pointer to point the base address of EXT */

#define EXTI ((volatile EXTI_t*) EXTI_BASEADDRESS )



#endif /* EXTI_PRIVATE_H */
