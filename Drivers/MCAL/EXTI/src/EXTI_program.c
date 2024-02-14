
/********************** includes ***********************************************/


#include "EXTI/inc/EXTI_Interface.h"


/********************** Helper Functions Declaration "prototype" ************/

/*********************  Data Type Declarations ***********************************/



/*********************  static Variable Definition ****************************/

/*  Array of pointer to function to pint for each EXT in IRS */

static void (*PtrfuncArray[20]) (void) ={NULL_FPTR , NULL_FPTR ,NULL_FPTR ,NULL_FPTR ,NULL_FPTR ,
		NULL_FPTR ,NULL_FPTR ,NULL_FPTR ,NULL_FPTR ,NULL_FPTR ,NULL_FPTR ,NULL_FPTR ,NULL_FPTR ,
		NULL_FPTR ,NULL_FPTR ,NULL_FPTR ,NULL_FPTR ,NULL_FPTR ,NULL_FPTR ,NULL_FPTR
};

/*********************  Global Variable Definition ****************************/


/*********************  APIs Definition ***************************************/

RETURN_t EXTI_RETURNtSetInterruptStatus(EXTI_Numbers Copy_u8EXTINumber, uint8_t Copy_u8EXTIStatus){

	RETURN_t local_returnState = OK_ret ;

	if (Copy_u8EXTINumber<EXTI_LINE0 || Copy_u8EXTINumber>EXTI_LINE19)
	{
		local_returnState =  ERROR_ret ;


	}
	else
	{

		if (Copy_u8EXTIStatus== EXTIMasked )
		{

			CLEAR_BIT(EXTI->IMR,Copy_u8EXTINumber);
		}
		else if (Copy_u8EXTIStatus== EXTINonMasked)
		{
			 SET_BIT(EXTI->IMR,Copy_u8EXTINumber);
		}
	}
	return local_returnState ;
}



RETURN_t EXTI_RETURNtSetEventStatus(EXTI_Numbers Copy_u8EXTINumber, uint8_t Copy_u8EXTIStatus){
	RETURN_t local_returnState = OK_ret ;

	if (Copy_u8EXTINumber<EXTI_LINE0 || Copy_u8EXTINumber>EXTI_LINE19)
	{
		local_returnState =  ERROR_ret ;
	}
	else
	{
		if (Copy_u8EXTIStatus== EventMasked )
		{
			CLEAR_BIT(EXTI->EMR,Copy_u8EXTINumber);
		}
		else if (Copy_u8EXTIStatus== EventNonMasked)
		{
			 SET_BIT(EXTI->EMR,Copy_u8EXTINumber);
		}
	}

	return local_returnState ;


}



RETURN_t EXTI_RETURNtSetInterruptEdge(EXTI_Numbers Copy_u8EXTINumber, uint8_t Copy_u8EXTIEdge){
	RETURN_t local_returnState = OK_ret ;

	if (Copy_u8EXTINumber<EXTI_LINE0 || Copy_u8EXTINumber>EXTI_LINE19)
	{
		local_returnState =  ERROR_ret ;
	}
	else {
			if (Copy_u8EXTIEdge== RISING_EDGE )
			{
				 SET_BIT(EXTI->RSTR,Copy_u8EXTINumber);
				 CLEAR_BIT(EXTI->FTSR,Copy_u8EXTINumber);
			}
			else if (Copy_u8EXTIEdge== FALLING_EDGE )
			{

				CLEAR_BIT(EXTI->RSTR,Copy_u8EXTINumber);
				SET_BIT(EXTI->FTSR,Copy_u8EXTINumber);
			}
			else if (Copy_u8EXTIEdge== ON_CHANGE)
			{
				SET_BIT(EXTI->FTSR,Copy_u8EXTINumber);
				SET_BIT(EXTI->RSTR,Copy_u8EXTINumber);
			}
	     }

	return local_returnState ;

}

void EXTI_vSetSoftwareInterrupt(uint8_t Copy_u8EXTINumber)
{

	if (Copy_u8EXTINumber<EXTI_LINE0 || Copy_u8EXTINumber>EXTI_LINE19)
	{
	}
	else
	{
		SET_BIT(EXTI->SWIER,Copy_u8EXTINumber);
	}


}


void EXTI_vClearPendingFlag (EXTI_Numbers Copy_u8EXTINumber)
{


	if (Copy_u8EXTINumber<EXTI_LINE0 || Copy_u8EXTINumber>EXTI_LINE19)
	{

	}
	else
	{
		SET_BIT(EXTI->PR,Copy_u8EXTINumber);
	}

}




RETURN_t EXTI_RETURNtSetCalbackFunction(EXTI_Numbers Copy_u8EXTINumber,void(*Ptrfunction)(void))
{
	RETURN_t local_returnState = OK_ret ;

     if (Copy_u8EXTINumber<EXTI_LINE0 || Copy_u8EXTINumber>EXTI_LINE19)
	{
 		local_returnState =  ERROR_ret ;
	}
	else
	{
		PtrfuncArray[Copy_u8EXTINumber]=Ptrfunction;
	}

		return local_returnState ;



}




/*********************  ISRs Definition **************************************/


/**********************ISR EXTI*************************************************/


void EXTI0_IRQHandler (void)
{
	EXTI_vClearPendingFlag(EXTI_LINE0);
	if(PtrfuncArray[EXTI_LINE0]!=NULL_FPTR)
	{
	PtrfuncArray[EXTI_LINE0]();
	}

}

void EXTI1_IRQHandler (void)
{
	EXTI_vClearPendingFlag(EXTI_LINE1);
	if(PtrfuncArray[EXTI_LINE1]!=NULL_FPTR)
	{
	PtrfuncArray[EXTI_LINE1]();
	}


}
void EXTI2_IRQHandler (void)
{
	EXTI_vClearPendingFlag(EXTI_LINE2);
	if(PtrfuncArray[EXTI_LINE2]!=NULL_FPTR)
	{
	PtrfuncArray[EXTI_LINE2]();
	}

}
void EXTI3_IRQHandler (void)
{

	EXTI_vClearPendingFlag(EXTI_LINE3);
	if(PtrfuncArray[EXTI_LINE3]!=NULL_FPTR)
	{
	PtrfuncArray[EXTI_LINE3]();
	}

}
void EXTI4_IRQHandler (void)
{

	EXTI_vClearPendingFlag(EXTI_LINE4);
	if(PtrfuncArray[EXTI_LINE4]!=NULL_FPTR)
	{
	PtrfuncArray[EXTI_LINE4]();
	}

}
void EXTI5_9_IRQHandler (void)
{
	if (GET_BIT (EXTI->PR,EXTI_LINE5))
	{
		EXTI_vClearPendingFlag(EXTI_LINE5);
		PtrfuncArray[EXTI_LINE5]();
	}
	if (GET_BIT (EXTI->PR,EXTI_LINE6))
	{
		EXTI_vClearPendingFlag(EXTI_LINE6);
		PtrfuncArray[EXTI_LINE6]();
	}
	if (GET_BIT (EXTI->PR,EXTI_LINE7))
	{
		EXTI_vClearPendingFlag(EXTI_LINE7);
		PtrfuncArray[EXTI_LINE7]();
	}
	if (GET_BIT (EXTI->PR,EXTI_LINE8))
	{
		EXTI_vClearPendingFlag(EXTI_LINE8);
		PtrfuncArray[EXTI_LINE8]();
	}
	if (GET_BIT (EXTI->PR,EXTI_LINE9))
	{
		EXTI_vClearPendingFlag(EXTI_LINE9);
		PtrfuncArray[EXTI_LINE9]();
	}

}
void EXTI10_15_IRQHandler (void)
{

	if (GET_BIT (EXTI->PR,EXTI_LINE10))
	{
		EXTI_vClearPendingFlag(EXTI_LINE10);
		PtrfuncArray[EXTI_LINE10]();
	}
	if (GET_BIT (EXTI->PR,EXTI_LINE11))
	{
		EXTI_vClearPendingFlag(EXTI_LINE11);
		PtrfuncArray[EXTI_LINE11]();
	}
	if (GET_BIT (EXTI->PR,EXTI_LINE12))
	{
		EXTI_vClearPendingFlag(EXTI_LINE12);
		PtrfuncArray[EXTI_LINE12]();
	}
	if (GET_BIT (EXTI->PR,EXTI_LINE12))
	{
		EXTI_vClearPendingFlag(EXTI_LINE12);
		PtrfuncArray[EXTI_LINE12]();
	}
    if (GET_BIT (EXTI->PR,EXTI_LINE13))
	{
		EXTI_vClearPendingFlag(EXTI_LINE13);
		PtrfuncArray[EXTI_LINE13]();
	}
	if (GET_BIT (EXTI->PR,EXTI_LINE14))
	{
		EXTI_vClearPendingFlag(EXTI_LINE14);
		PtrfuncArray[EXTI_LINE14]();
	}
    if (GET_BIT (EXTI->PR,EXTI_LINE15))
	{
		EXTI_vClearPendingFlag(EXTI_LINE15);
		PtrfuncArray[EXTI_LINE15]();
	}
}
/*********************  Helper Function Definition **************************/


