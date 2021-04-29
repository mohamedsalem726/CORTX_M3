/*******************************************************/
/* Auther    : Mohamed Salem                           */
/* Date      : 25 APRIL 2021                           */ 
/* Version   : V01                                     */
/*******************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

void (* CallBack)(void);

void MSTK_voidInit(void)
{
	//MSTK -> CTRL &= ~(0x01 << MSTK_COUNTFLAG_BIT);

	CLR_BIT(MSTK -> CTRL, MSTK_COUNTFLAG_BIT);

	MSTK -> CTRL &= ~(0x01 << MSTK_CLKSOURCE_BIT);
	MSTK -> CTRL |=  (MSTK_CLKSOURCE  << MSTK_CLKSOURCE_BIT);
	
	#if   (MSTK_CLKSOURCE == MSTK_CLKSOURCE_AHB_8)
		#define MSTK_CLK   (MSTK_AHB_CLK/8)
	#elif (MSTK_CLKSOURCE == MSTK_CLKSOURCE_AHB)
		#define MSTK_CLK   (MSTK_AHB_CLK)
	#endif
}

void MSTK_voidTICKInterrupt(u8 Copy_u8InterruptEnOrDis)
{
	MSTK -> CTRL &= ~(0x01 << MSTK_TICKINT_BIT);
	MSTK -> CTRL |=  (Copy_u8InterruptEnOrDis << MSTK_TICKINT_BIT);
}

void MSTK_voidLoadVal(u32 Copy_u32LoadVal)
{
	MSTK -> LOAD = Copy_u32LoadVal ;
}

u32 MSTK_u32CurrentVal(void)
{
	return ((u32)(MSTK->VAL));
}

void MSTK_voidCounterEnDis(u8 Copy_u8CounterEnOrDis)
{
	MSTK -> CTRL &= ~(0x01 << MSTK_COUNTER_EN_BIT);
	MSTK -> CTRL |= (Copy_u8CounterEnOrDis << MSTK_COUNTER_EN_BIT);
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks , u8 Copy_u8ValueType)
{
	switch(Copy_u8ValueType)
	{
		case MSTK_TICKS   :                                                      break;
		case MSTK_MILLIS  : Copy_u32Ticks *= (MSTK_CLK/MSTK_MILLIS_DIVIDER);  break;
		case MSTK_MICROS  : Copy_u32Ticks *= (MSTK_CLK/MSTK_MICROS_DIVIDER);  break;
		case MSTK_SECONDS : Copy_u32Ticks *= (MSTK_CLK);                         break;
	}
	MSTK_voidTICKInterrupt(MSTK_TICKINT_DIS);
	MSTK -> VAL = 0x00;
	MSTK_voidLoadVal(Copy_u32Ticks);
	MSTK_voidCounterEnDis(MSTK_COUNTER_EN);
	while((GET_BIT(MSTK->CTRL, MSTK_COUNTFLAG_BIT)) == 0);
	MSTK_voidCounterEnDis(MSTK_COUNTER_DIS);
}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , u8 Copy_u8ValueType , void (*Copy_ptr)(void))
{
	
	switch(Copy_u8ValueType)
	{
		case MSTK_TICKS   :                                                      break;
		case MSTK_MILLIS  : Copy_u32Ticks *= (MSTK_CLK/MSTK_MILLIS_DIVIDER);  break;
		case MSTK_MICROS  : Copy_u32Ticks *= (MSTK_CLK/MSTK_MICROS_DIVIDER);  break;
		case MSTK_SECONDS : Copy_u32Ticks *= (MSTK_CLK);                         break;
	}
	MSTK_voidTICKInterrupt(MSTK_TICKINT_EN);
	MSTK -> VAL = 0x00;
	MSTK_voidLoadVal(Copy_u32Ticks);
	MSTK_voidCounterEnDis(MSTK_COUNTER_EN);
	
	CallBack = Copy_ptr;
}
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , u8 Copy_u8ValueType , void (*Copy_ptr)(void))
{
	CallBack = Copy_ptr;
	
	switch(Copy_u8ValueType)
	{
		case MSTK_TICKS   :                                                      break;
		case MSTK_MILLIS  : Copy_u32Ticks *= (MSTK_CLK/MSTK_MILLIS_DIVIDER);  break;
		case MSTK_MICROS  : Copy_u32Ticks *= (MSTK_CLK/MSTK_MICROS_DIVIDER);  break;
		case MSTK_SECONDS : Copy_u32Ticks *= (MSTK_CLK);                         break;
	}
	MSTK_voidLoadVal(Copy_u32Ticks-1);
	MSTK -> VAL = 0x00;
	MSTK_voidCounterEnDis(MSTK_COUNTER_EN);

	MSTK_voidTICKInterrupt(MSTK_TICKINT_EN);


}

u32 MSTK_u32GetReminingTime(u8 Copy_u8ValueType)
{
	switch(Copy_u8ValueType)
	{
		case MSTK_TICKS   : return  (MSTK -> VAL);                                       break;
		case MSTK_MILLIS  : return ((MSTK -> VAL)/(MSTK_CLK/MSTK_MILLIS_DIVIDER));    break;
		case MSTK_MICROS  : return ((MSTK -> VAL)/(MSTK_CLK/MSTK_MICROS_DIVIDER));    break;
		case MSTK_SECONDS : return ((MSTK -> VAL)/(MSTK_CLK));                           break;
		default:	return 0;		break;
	}
}

u32 MSTK_u32GetElapsedTime(u8 Copy_u8ValueType)
{
	switch(Copy_u8ValueType){
		case MSTK_TICKS  : return  ((MSTK->LOAD) - (MSTK->VAL));											break;
		case MSTK_MICROS : return (((MSTK->LOAD) - (MSTK->VAL)) / (MSTK_CLK/MSTK_MICROS_DIVIDER));	break;
		case MSTK_MILLIS : return (((MSTK->LOAD) - (MSTK->VAL)) / (MSTK_CLK/MSTK_MILLIS_DIVIDER));	break;
		case MSTK_SECONDS: return (((MSTK->LOAD) - (MSTK->VAL)) / (MSTK_CLK));						    break;
		default:	return 0;		break;

	}
}

void MSTK_voidStopInterval(void)
{
	MSTK_voidCounterEnDis(MSTK_COUNTER_DIS);
}

void SysTick_Handler(void)
{
	CallBack();
	
}
