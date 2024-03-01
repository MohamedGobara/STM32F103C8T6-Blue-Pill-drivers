/*
 * DMA_program.c
 *
 *  Created on: Feb 24, 2024
 *      Author: Gobara
 */

#include "DMA/inc/DMA_interface.h"

static void DMA_RETURNtSetConfig(DMA_config* Local_DMA_config_s,
		uint32_t SrcAddress_s, uint32_t DesAddress_s, uint16_t Data_length_s) {

	if (Local_DMA_config_s->DMA_n == DMA_N1) {

		/* setup configuration  */
		DMA1->DMA_CH[(Local_DMA_config_s->CHANNEL_n * DMA_NUM_OfReg)+DMA_CCR_OFFEST] =*(uint16_t*)Local_DMA_config_s;
		DMA1->DMA_CH[(Local_DMA_config_s->CHANNEL_n * DMA_NUM_OfReg) + DMA_CNDTR_OFFEST] = Data_length_s;

		if (Local_DMA_config_s->MEM2MEM_Mode == DMA_MEM2MEM_ENABLE) {

			DMA1->DMA_CH[(Local_DMA_config_s->CHANNEL_n * DMA_NUM_OfReg) + DMA_CPAR_OFFEST] = SrcAddress_s;

			DMA1->DMA_CH[(Local_DMA_config_s->CHANNEL_n * DMA_NUM_OfReg) + DMA_CMAR_OFFEST] = DesAddress_s;

		} else {

			if (Local_DMA_config_s->DIR == DMA_DIR_PERIPHERAL_TO_MEMORY) {

				DMA1->DMA_CH[(Local_DMA_config_s->CHANNEL_n * DMA_NUM_OfReg) + DMA_CPAR_OFFEST] =
						SrcAddress_s;

				DMA1->DMA_CH[(Local_DMA_config_s->CHANNEL_n * DMA_NUM_OfReg) + DMA_CMAR_OFFEST] =
						DesAddress_s;

			} else {

				DMA1->DMA_CH[(Local_DMA_config_s->CHANNEL_n * DMA_NUM_OfReg) + DMA_CPAR_OFFEST] =
						DesAddress_s;

				DMA1->DMA_CH[(Local_DMA_config_s->CHANNEL_n * DMA_NUM_OfReg) + DMA_CMAR_OFFEST] =
						SrcAddress_s;

			}

		}

	} else if (Local_DMA_config_s->DMA_n == DMA_N2) {

		/* setup configuration  */
		DMA2->DMA_CH[(Local_DMA_config_s->CHANNEL_n * DMA_NUM_OfReg)+DMA_CCR_OFFEST] =
				 *(uint16_t*)Local_DMA_config_s;

		DMA2->DMA_CH[(Local_DMA_config_s->CHANNEL_n * DMA_NUM_OfReg) + DMA_CNDTR_OFFEST] = Data_length_s;

		if (Local_DMA_config_s->MEM2MEM_Mode == DMA_MEM2MEM_ENABLE) {

			DMA2->DMA_CH[(Local_DMA_config_s->CHANNEL_n * DMA_NUM_OfReg) + DMA_CPAR_OFFEST] = SrcAddress_s;

			DMA2->DMA_CH[(Local_DMA_config_s->CHANNEL_n * DMA_NUM_OfReg) + DMA_CMAR_OFFEST] = DesAddress_s;

		}

		else {

			if (Local_DMA_config_s->DIR == DMA_DIR_PERIPHERAL_TO_MEMORY) {

				DMA1->DMA_CH[(Local_DMA_config_s->CHANNEL_n * DMA_NUM_OfReg) + DMA_CPAR_OFFEST] =
						SrcAddress_s;

				DMA1->DMA_CH[(Local_DMA_config_s->CHANNEL_n * DMA_NUM_OfReg) + DMA_CMAR_OFFEST] =
						DesAddress_s;

			} else {

				DMA1->DMA_CH[(Local_DMA_config_s->CHANNEL_n * DMA_NUM_OfReg) + DMA_CPAR_OFFEST] =
						DesAddress_s;

				DMA1->DMA_CH[(Local_DMA_config_s->CHANNEL_n * DMA_NUM_OfReg) + DMA_CMAR_OFFEST] =
						SrcAddress_s;

			}

		}

	}
}
RETURN_t DMA_RETURNtInit(DMA_config *Local_DMA_config) {

	RETURN_t Local_ReturnStatus = OK_ret ;

	if (Local_DMA_config->DMA_n == DMA_N1) {

		/* setup configuration  */

DMA1->DMA_CH[(Local_DMA_config->CHANNEL_n * DMA_NUM_OfReg)+DMA_CCR_OFFEST] =  *(uint16_t*)Local_DMA_config;

	} else if (Local_DMA_config->DMA_n == DMA_N2) {

		/* setup configuration  */
		DMA2->DMA_CH[(Local_DMA_config->CHANNEL_n * DMA_NUM_OfReg)+DMA_CCR_OFFEST] =
				 *(uint16_t*)Local_DMA_config;

	}

	return Local_ReturnStatus ;
}

RETURN_t DMA_RETURNtstart(DMA_config *Local_DMA_config, uint32_t SrcAddress,
		uint32_t DesAddress, uint16_t Data_length) {

	RETURN_t Local_ReturnStatus = OK_ret ;


	DMA_RETURNtSetConfig(Local_DMA_config, SrcAddress, DesAddress,Data_length);

	if (Local_DMA_config->DMA_n == DMA_N1) {

		/* setup configuration  */

		SET_BIT(DMA1->DMA_CH[(Local_DMA_config->CHANNEL_n * DMA_NUM_OfReg)+DMA_CCR_OFFEST], 0);

	} else if (Local_DMA_config->DMA_n == DMA_N2) {

		SET_BIT(DMA2->DMA_CH[(Local_DMA_config->CHANNEL_n * DMA_NUM_OfReg)+DMA_CCR_OFFEST], 0);

	}

	return Local_ReturnStatus ;


}

void DMA_RETURNtPollForTransfer(DMA_config *Local_DMA_config,
		uint8_t Complete_level) {

	if (Complete_level == DMA_COMPLETE_LEVEL_FULL) {

		if (Local_DMA_config->DMA_n == DMA_N1) {

			while (!READ_BIT(DMA1->DMA_CH[Local_DMA_config->CHANNEL_n*DMA_NUM_OfReg], (1 + (Local_DMA_config->CHANNEL_n * 4))));
			SET_BIT(DMA1->DMA_CH[((Local_DMA_config->CHANNEL_n*DMA_NUM_OfReg)+1)], ((Local_DMA_config->CHANNEL_n * 4)));

		} else if (Local_DMA_config->DMA_n == DMA_N2) {

			while (!READ_BIT(DMA2->DMA_CH[Local_DMA_config->CHANNEL_n*DMA_NUM_OfReg], (1 + (Local_DMA_config->CHANNEL_n * 4)))) ;
				;
		SET_BIT(DMA2->DMA_CH[((Local_DMA_config->CHANNEL_n*DMA_NUM_OfReg)+1)], ((Local_DMA_config->CHANNEL_n * 4)));
		}

	} else if (Complete_level == DMA_COMPLETE_LEVEL_HALF) {

		while (!READ_BIT(DMA1->DMA_CH[Local_DMA_config->CHANNEL_n*DMA_NUM_OfReg],(2+(Local_DMA_config->CHANNEL_n * 4))));
		SET_BIT(DMA1->DMA_CH[((Local_DMA_config->CHANNEL_n*DMA_NUM_OfReg)+1)], ((Local_DMA_config->CHANNEL_n * 4)));

	} else if (Local_DMA_config->DMA_n == DMA_N2) {

		while (!READ_BIT(DMA2->DMA_CH[Local_DMA_config->CHANNEL_n*DMA_NUM_OfReg], (2 + (Local_DMA_config->CHANNEL_n * 4))));
		SET_BIT(DMA2->DMA_CH[((Local_DMA_config->CHANNEL_n*DMA_NUM_OfReg)+1)], ((Local_DMA_config->CHANNEL_n * 4)));
	}

}


static void(*DMA1_FunPtr[7])(void)= {NULL_FPTR,NULL_FPTR,NULL_FPTR,NULL_FPTR,NULL_FPTR,NULL_FPTR,NULL_FPTR} ;


static void(*DMA2_FunPtr[7])(void)= {NULL_FPTR,NULL_FPTR,NULL_FPTR} ;


RETURN_t DMA_RETURNtRegisterCallBack(DMA_config *Local_DMA_config , void (*DMA_ptr)(void)) {

	RETURN_t Local_ReturnStatus = OK_ret ;


	if (Local_DMA_config->DMA_n == DMA_N1) {


		DMA1_FunPtr[Local_DMA_config->CHANNEL_n]= DMA_ptr ;


	} else if (Local_DMA_config->DMA_n == DMA_N2) {


		DMA2_FunPtr[Local_DMA_config->CHANNEL_n]= DMA_ptr ;

	}

	return Local_ReturnStatus ;



}

uint8_t DMA_RETURNtGetState(DMA_config *Local_DMA_config);

uint8_t DMA_RETURNtGetError(DMA_config *Local_DMA_config);



void DMA1_Channel1_IRQHandler(void){

	if(DMA1_FunPtr[0]!=NULL_FPTR){

		DMA1_FunPtr[0]() ;

		SET_BIT(DMA1->DMA_CH[((0*DMA_NUM_OfReg)+1)],0);

	}

}
void DMA1_Channel2_IRQHandler(void){


	if(DMA1_FunPtr[1]!=NULL_FPTR){

		DMA1_FunPtr[1]() ;
		SET_BIT(DMA1->DMA_CH[((0*DMA_NUM_OfReg)+1)],4);


	}

}
void DMA1_Channel3_IRQHandler(void){


	if(DMA1_FunPtr[2]!=NULL_FPTR){

		DMA1_FunPtr[2]() ;
		SET_BIT(DMA1->DMA_CH[((0*DMA_NUM_OfReg)+1)],8);


	}

}
void DMA1_Channel4_IRQHandler(void){

	if(DMA1_FunPtr[3]!=NULL_FPTR){

		DMA1_FunPtr[3]() ;
		SET_BIT(DMA1->DMA_CH[((0*DMA_NUM_OfReg)+1)],12);


	}}
void DMA1_Channel5_IRQHandler(void){


	if(DMA1_FunPtr[4]!=NULL_FPTR){

		DMA1_FunPtr[4]() ;
		SET_BIT(DMA1->DMA_CH[((0*DMA_NUM_OfReg)+1)],16);


	}


}
void DMA1_Channel6_IRQHandler(void){


	if(DMA1_FunPtr[5]!=NULL_FPTR){

		DMA1_FunPtr[5]() ;
		SET_BIT(DMA1->DMA_CH[((0*DMA_NUM_OfReg)+1)],20);

	}

}
void DMA1_Channel7_IRQHandler(void){



	if(DMA1_FunPtr[6]!=NULL_FPTR){

		DMA1_FunPtr[6]() ;

		SET_BIT(DMA1->DMA_CH[((0*DMA_NUM_OfReg)+1)],24);

	}


}



void DMA2_Channel1_IRQHandler(void){


	if(DMA2_FunPtr[0]!=NULL_FPTR){

		DMA2_FunPtr[0]() ;

		SET_BIT(DMA1->DMA_CH[((0*DMA_NUM_OfReg)+1)],0);


	}

}
void DMA2_Channel2_IRQHandler(void){



	if(DMA2_FunPtr[1]!=NULL_FPTR){

		DMA2_FunPtr[1]() ;

		SET_BIT(DMA1->DMA_CH[((0*DMA_NUM_OfReg)+1)],4);


	}

}
void DMA2_Channel3_IRQHandler(void){


	if(DMA2_FunPtr[2]!=NULL_FPTR){

		DMA2_FunPtr[2]() ;

		SET_BIT(DMA1->DMA_CH[((0*DMA_NUM_OfReg)+1)],8);


	}

}
void DMA2_Channel4_5_IRQHandler(void){}
