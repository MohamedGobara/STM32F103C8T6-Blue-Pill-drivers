#include "stdint.h"
#include "Utils.h"
#include "STDTypes.h"

#include "SysTick/inc/SysTick_private.h"
#include "SysTick/inc/SysTick_interface.h"
#include "SysTick/inc/SysTick_config.h"

void SysTick_vInit(void) {

	/* disable SysTick exception */
	CLEAR_BIT(SysTick->CTRL, 1);
#if SysTick_ClkSource==SysTick_AHB_8
	CLEAR_BIT(SysTick->CTRL, 2);
#elif SysTick_ClkSource==SysTick_AHB
	SET_BIT(SysTick->CTRL  , 2 ) ;

#endif

}

void SysTick_vDelayus(const uint32_t local_time) {

	if (local_time < (1 << 25)) {

		SysTick->LOAD = local_time;

		SET_BIT(SysTick->CTRL, 0);

		while (!READ_BIT(SysTick->CTRL, 16))
			;

		CLEAR_BIT(SysTick->CTRL, 0);
	}

	else if (local_time > (1 << 25)) {

		uint32_t overfolow = local_time / 0xffffff;
		uint32_t rem = local_time / 0xffffff;

		SysTick->LOAD = rem;

		SET_BIT(SysTick->CTRL, 0);

		while (!READ_BIT(SysTick->CTRL, 16))
			;

		CLEAR_BIT(SysTick->CTRL, 0);

		for (uint32_t i = 0; i < overfolow; i++) {

			SysTick->LOAD = 0xffffff;

			SET_BIT(SysTick->CTRL, 0);

			while (!READ_BIT(SysTick->CTRL, 16))
				;

			CLEAR_BIT(SysTick->CTRL, 0);

		}

	}

}

void SysTick_vDelayms(uint32_t local_time) {

	local_time *= 1000;

	if (local_time < (1 << 25)) {

		SysTick->LOAD = local_time;

		SET_BIT(SysTick->CTRL, 0);

		while (!READ_BIT(SysTick->CTRL, 16))
			;

		CLEAR_BIT(SysTick->CTRL, 0);
	}

	else if (local_time > (1 << 25)) {

		uint32_t overfolow = local_time / 0xffffff;
		uint32_t rem = local_time / 0xffffff;

		SysTick->LOAD = rem;

		SET_BIT(SysTick->CTRL, 0);

		while (!READ_BIT(SysTick->CTRL, 16))
			;

		CLEAR_BIT(SysTick->CTRL, 0);

		for (uint32_t i = 0; i < overfolow; i++) {

			SysTick->LOAD = 0xffffff;

			SET_BIT(SysTick->CTRL, 0);

			while (!READ_BIT(SysTick->CTRL, 16))
				;

			CLEAR_BIT(SysTick->CTRL, 0);

		}

	}

}
static uint8_t Overflow_needFlag = 0;

static uint32_t overflowInterrupt = 0;

void (*SysTickHandler_ptr)(void) = NULL_FPTR;

void SysTick_vFunUS(const uint32_t local_time, void (*local_ptrFun)(void)) {

	SysTickHandler_ptr = local_ptrFun;

	/* enable SysTick exception */
	CLEAR_BIT(SysTick->CTRL, 0);

	if (local_time < (1 << 25)) {

		Overflow_needFlag = 0;

		SysTick->LOAD = local_time;

		SET_BIT(SysTick->CTRL, 0);

	}

	else if (local_time > (1 << 25)) {

		Overflow_needFlag = 1;

		overflowInterrupt = local_time / 0xffffff;
		uint32_t rem = local_time / 0xffffff;

		SysTick->LOAD = rem;

		SET_BIT(SysTick->CTRL, 0);

	}

}

void SysTick_Handler(void) {

	if (Overflow_needFlag == 0) {

		/* stop timer */
		SET_BIT(SysTick->CTRL, 0);

		if (SysTickHandler_ptr != NULL) {
			SysTickHandler_ptr();
		}

	} else if (Overflow_needFlag == 1) {
		static uint32_t i ;
		/* stop timer */
		CLEAR_BIT(SysTick->CTRL, 0);
		for ( i= 0; i < overflowInterrupt; i++) {

			SysTick->LOAD = 0xffffff;

			SET_BIT(SysTick->CTRL, 0);

		}
		if(i==(overflowInterrupt-1)){

			if (SysTickHandler_ptr != NULL) {
						SysTickHandler_ptr();
}
			i=0 ;

		}

	}

}

