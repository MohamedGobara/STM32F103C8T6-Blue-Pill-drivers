/*
 * DMA_private.h
 *
 *  Created on: Feb 25, 2024
 *      Author: Gobara
 */

#ifndef MCAL_DMA_INC_DMA_PRIVATE_H_
#define MCAL_DMA_INC_DMA_PRIVATE_H_






#define DMA1_BASE_ADDRESS  0x40020000
#define DMA2_BASE_ADDRESS  0x40020400



#define DMA_NUM_OfReg   0x08

#define DMA_ISR_OFFEST   0x0
#define DMA_IFCR_OFFEST  0x01
#define DMA_CCR_OFFEST   0x02
#define DMA_CNDTR_OFFEST 0x03
#define DMA_CPAR_OFFEST  0x04
#define DMA_CMAR_OFFEST  0x05


typedef struct {

	/*volatile uint32_t ISR  ;
	volatile uint32_t IFSR ;*/

	/*
	 *
	 * Assume each channel has 6 parts
	 *
	 * 4 are already allocated to essential registers and 2 parts for reserved parts every part has 4 bytes
	 *
	 *
	 *
	 *
	 */
	volatile uint32_t DMA_CH[42] ; /* 4*7  + ( 6 reserved * 2  )*/






	/******* channel 1 ********/
	/*volatile uint32_t CCR1 ;
	volatile uint32_t CNDTR1 ;
	volatile uint32_t CPAR1 ;
	volatile uint32_t CMAR1 ;*/
	/******* channel 2 ********/
	/*volatile uint32_t CCR2 ;
	volatile uint32_t CNDTR2 ;
	volatile uint32_t CPAR2 ;
	volatile uint32_t CMAR2 ;*/
	/******* channel 3 ********/
/*	volatile uint32_t CCR3 ;
	volatile uint32_t CNDTR3 ;
	volatile uint32_t CPAR3 ;
	volatile uint32_t CMAR3 ;*/
	/******* channel 4 ********/
	/*volatile uint32_t CCR4 ;
	volatile uint32_t CNDTR ;
	volatile uint32_t CPAR1 ;
	volatile uint32_t CMAR1 ;*/
	/******* channel 5 *********/
	/*volatile uint32_t CCR1 ;
	volatile uint32_t CNDTR1 ;
	volatile uint32_t CPAR1 ;
	volatile uint32_t CMAR1 ;*/
	/******* channel 6 *********/
	/*volatile uint32_t CCR1 ;
	volatile uint32_t CNDTR1 ;
	volatile uint32_t CPAR1 ;
	volatile uint32_t CMAR1 ;*/
	/******* channel 7 ********/
/*	volatile uint32_t CCR1 ;
	volatile uint32_t CNDTR1 ;
	volatile uint32_t CPAR1 ;
	volatile uint32_t CMAR1 ;*/


}DMA_Registers ;


#define DMA1 ((DMA_Registers*)DMA1_BASE_ADDRESS)
#define DMA2 ((DMA_Registers*)DMA2_BASE_ADDRESS)


#endif /* MCAL_DMA_INC_DMA_PRIVATE_H_ */
