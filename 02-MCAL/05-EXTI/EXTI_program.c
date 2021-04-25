/*******************************************************/
/* Auther    : Mohamed Salem                           */
/* Date      : 24 APRIL 2021                           */ 
/* Version   : V01                                     */
/*******************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "AFIO_interface.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void MEXTI_voidInit(u8 Copy_u8Port, u8 Copy_u8Line, u8 Copy_u8TriggerSel)
{
	MNVIC_voidEXTIEnControl(Copy_u8Line, MNVIC_U8_ENABLE);	    /* Enables External interrupt for EXTI */
	MEXTI_voidLineEnorDis(Copy_u8Line, MEXTI_U8_ENABLE);		/* Unmask Interrupt request from selected EXTI line(Cpy_u8Line) */
	MEXTI_voidTriggerSel(Copy_u8Line, Copy_u8TriggerSel);		/* Selects triggering type */
	MAFIO_voidSetEXTIConfig(Copy_u8Line, Copy_u8Port); 		    /* Selects the source input for EXTI Line */
}

void MEXTI_voidLineEnorDis(u8 Copy_u8Line, u8 Copy_u8EnorDis)
{
	switch(Copy_u8EnorDis)
	{
		case MEXTI_U8_ENABLE:
			SET_BIT((MEXTI -> IMR) , Copy_u8Line);			
		break;
		
		case MEXTI_U8_DISABLE:
			CLR_BIT((MEXTI -> IMR) , Copy_u8Line);
		break;
	}
}

void MEXTI_voidTriggerSel(u8 Copy_u8Line, u8 Copy_u8TriggerSel)
{
	switch (Copy_u8TriggerSel)
	{
		case MEXTI_U8_RISING_EDGE_TRIGGER:
			SET_BIT((MEXTI -> RTSR) , Copy_u8Line);
			CLR_BIT((MEXTI -> FTSR) , Copy_u8Line);
		break;
		
		case MEXTI_U8_FALLING_EDGE_TRIGGER:
			CLR_BIT((MEXTI -> RTSR) , Copy_u8Line);
			SET_BIT((MEXTI -> FTSR) , Copy_u8Line);
		break;
		
		case MEXTI_U8_BOTH_EDGES_TRIGGER:
			SET_BIT((MEXTI -> RTSR) , Copy_u8Line);
			SET_BIT((MEXTI -> FTSR) , Copy_u8Line);
		break;
	}
}

void MEXTI_voidSetSWInt(u8 Copy_u8Line)
{
	SET_BIT((MEXTI -> SWIER) , Copy_u8Line);
}

u8 MEXTI_u8GetPR(u8 Cpy_u8Line)
{
	return (GET_BIT((MEXTI -> PR) , Copy_u8Line));
}

void MEXTI_voidClrPR(u8 Cpy_u8Line)
{
	SET_BIT((MEXTI -> PR) , Copy_u8Line);
}

void MEXTI_voidSetCallBack(void (*ptr_Func)(void), u8 Copy_u8Line){
	CallBack[Copy_u8Line] = ptr_Func;
}

void EXTI0_IRQHandler(void){
	CallBack[0]();
	MEXTI_voidClrPR(0);
}