/*
 * DMA_interface.h
 *
 *  Created on: Feb 24, 2024
 *      Author: Gobara
 */

#ifndef MCAL_DMA_INC_DMA_INTERFACE_H_
#define MCAL_DMA_INC_DMA_INTERFACE_H_

#include <stdint.h>
#include "STDTypes.h"
#include "Utils.h"

#include "DMA_private.h"
#include "DMA_config.h"
#define DMA_TCIE_DISABLE  0b00  // Transfer complete interrupt disabled
#define DMA_TCIE_ENABLE   0b10  // Transfer complete interrupt enabled

#define DMA_HTIE_DISABLE  0     // Half transfer interrupt disabled
#define DMA_HTIE_ENABLE   1     // Half transfer interrupt enabled

#define DMA_TEIE_DISABLE  0     // Transfer error interrupt disabled
#define DMA_TEIE_ENABLE   1     // Transfer error interrupt enabled

#define DMA_DIR_PERIPHERAL_TO_MEMORY  0  // Data transfer direction: Read from peripheral
#define DMA_DIR_MEMORY_TO_PERIPHERAL  1  // Data transfer direction: Read from memory

#define DMA_CIRC_DISABLE  0     // Circular mode disabled
#define DMA_CIRC_ENABLE   1     // Circular mode enabled

#define DMA_PINC_DISABLE  0     // Peripheral increment mode disabled
#define DMA_PINC_ENABLE   1     // Peripheral increment mode enabled

#define DMA_MINC_DISABLE  0     // Memory increment mode disabled
#define DMA_MINC_ENABLE   1     // Memory increment mode enabled

#define DMA_PSIZE_8BITS    0b00  // Peripheral size: 8-bits
#define DMA_PSIZE_16BITS   0b01  // Peripheral size: 16-bits
#define DMA_PSIZE_32BITS   0b10  // Peripheral size: 32-bits

#define DMA_MSIZE_8BITS    0b00  // Memory size: 8-bits
#define DMA_MSIZE_16BITS   0b01  // Memory size: 16-bits
#define DMA_MSIZE_32BITS   0b10  // Memory size: 32-bits

#define DMA_PL_LOW         0b00  // Channel priority level: Low
#define DMA_PL_MEDIUM      0b01  // Channel priority level: Medium
#define DMA_PL_HIGH        0b10  // Channel priority level: High
#define DMA_PL_VERY_HIGH   0b11  // Channel priority level: Very high

#define DMA_MEM2MEM_DISABLE  0  // Memory to memory mode disabled
#define DMA_MEM2MEM_ENABLE   1  // Memory to memory mode enabled


#define DMA_COMPLETE_LEVEL_FULL 0
#define DMA_COMPLETE_LEVEL_HALF 1


#define DMA_CHANNEL0 0b000
#define DMA_CHANNEL1 0b001
#define DMA_CHANNEL2 0b010
#define DMA_CHANNEL3 0b011
#define DMA_CHANNEL4 0b100
#define DMA_CHANNEL5 0b101
#define DMA_CHANNEL6 0b110


#define DMA_N1 0b0
#define DMA_N2 0b1


typedef struct {


	/* Transfer complete interrupt enable */
	uint16_t TCIE :2; // Bit field for transfer complete interrupt enable

	/* Half transfer interrupt enable */
	uint16_t HTIE :1; // Bit field for half transfer interrupt enable

	/* Transfer error interrupt enable */
	uint16_t TEIE :1; // Bit field for transfer error interrupt enable

	/* Data transfer direction */
	uint16_t DIR :1; // Bit field for data transfer direction

	/* Circular mode */
	uint16_t CIRC :1; // Bit field for circular mode

	/* Peripheral increment mode */
	uint16_t PINC :1; // Bit field for peripheral increment mode

	/* Memory increment mode */
	uint16_t MINC :1; // Bit field for memory increment mode

	/* Peripheral size */
	uint16_t PSIZE :2; // Bit field for peripheral size

	/* Memory size */
	uint16_t MSIZE :2; // Bit field for memory size

	/* Channel priority level */
	uint16_t PL :2; // Bit field for channel priority level

	/* Memory to memory mode */
	uint16_t MEM2MEM_Mode :1; // Bit field for memory to memory mode

	/* which DMA you need to select */
	uint8_t DMA_n :1; // Bit field for selecting DMA

	/* which channel you need to select */
	uint8_t CHANNEL_n :3; // Bit field for selecting the channel


} DMA_config;

RETURN_t DMA_RETURNtInit(DMA_config *Local_DMA_config)  ;
RETURN_t DMA_RETURNtstart(DMA_config *Local_DMA_config, uint32_t SrcAddress,
		uint32_t DesAddress, uint16_t Data_length)  ;

void DMA_RETURNtPollForTransfer(DMA_config *Local_DMA_config,
		uint8_t Complete_level)  ;


RETURN_t DMA_RETURNtRegisterCallBack(DMA_config *Local_DMA_config , void (*DMA_ptr)(void))  ;

uint8_t DMA_RETURNtGetState(DMA_config *Local_DMA_config);

uint8_t DMA_RETURNtGetError(DMA_config *Local_DMA_config);



void DMA1_Channel1_IRQHandler(void) ;
void DMA1_Channel2_IRQHandler(void) ;
void DMA1_Channel3_IRQHandler(void) ;
void DMA1_Channel4_IRQHandler(void) ;
void DMA1_Channel5_IRQHandler(void) ;
void DMA1_Channel6_IRQHandler(void) ;
void DMA1_Channel7_IRQHandler(void) ;


void DMA2_Channel1_IRQHandler(void) ;
void DMA2_Channel2_IRQHandler(void) ;
void DMA2_Channel3_IRQHandler(void) ;
void DMA2_Channel4_5_IRQHandler(void) ;


#endif /* MCAL_DMA_INC_DMA_INTERFACE_H_ */
