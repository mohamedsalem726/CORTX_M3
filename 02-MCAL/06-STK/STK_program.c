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

void MSTK_voidInit(void)
{
	MSTK -> CTRL &= ~(0x01 << MSTK_U8_COUNTFLAG_BIT);
	MSTK -> CTRL |=  (MSTK_U8_CLKSOURCE  << MSTK_U8_CLKSOURCE_BIT);
	
	#if   (MSTK_U8_CLKSOURCE == MSTK_U8_CLKSOURCE_AHB_8)
		#define MSTK_CLK   (MSTK_AHB_CLK/8)
	#elif (MSTK_U8_CLKSOURCE == MSTK_U8_CLKSOURCE_AHB)
		#define MSTK_CLK   (MSTK_AHB_CLK)
	#endif
}

void MSTK_voidTICKInterrupt(u8 Copy_u8InterruptEnOrDis)
{
	STK -> CTRL &= ~(0x01 << MSTK_U8_TICKINT_BIT);
	STK -> CTRL |=  (Copy_u8InterruptEnOrDis << MSTK_U8_TICKINT_BIT);
}

void MSTK_voidLoadVal(u32 Copy_u32LoadVal)
{
	STK -> LOAD = Copy_u32LoadVal ;
}

u32 MSTK_u32CurrentVal(void)
{
	return ((u32)(STK->VAL));
}

void MSTK_voidCounterEnDis(u8 Copy_u8CounterEnOrDis)
{
	STK -> CTRL &= ~(0x01 << MSTK_U8_COUNTER_EN_BIT);
	STK -> CTRL |= (Copy_u8CounterEnOrDis << MSTK_U8_COUNTER_EN_BIT);
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks , u8 Copy_u8ValueType)
{
	switch(Copy_u8ValueType)
	{
		case MSTK_U8_TICKS   :                                                      break;
		case MSTK_U8_MILLIS  : Copy_u32Ticks *= (MSTK_CLK/MSTK_U8_MILLIS_DIVIDER);  break;
		case MSTK_U8_MICROS  : Copy_u32Ticks *= (MSTK_CLK/MSTK_U8_MICROS_DIVIDER);  break;
		case MSTK_U8_SECONDS : Copy_u32Ticks *= (MSTK_CLK);                         break;
	}
	MSTK_voidTICKInterrupt(MSTK_U8_TICKINT_DIS);
	MSTK -> VAL = 0x00;
	MSTK_voidLoadVal(Copy_u32Ticks);
	MSTK_voidCounterEnDis(STK_U8_COUNTER_EN);
	while((GET_BIT(STK->CTRL, STK_U8_COUNTFLAG_BIT)) == 0);
	MSTK_voidCounterEnDis(STK_U8_COUNTER_DIS);
}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , u8 Copy_u8ValueType , void (*Copy_ptr)(void))
{
	
	switch(Copy_u8ValueType)
	{
		case MSTK_U8_TICKS   :                                                      break;
		case MSTK_U8_MILLIS  : Copy_u32Ticks *= (MSTK_CLK/MSTK_U8_MILLIS_DIVIDER);  break;
		case MSTK_U8_MICROS  : Copy_u32Ticks *= (MSTK_CLK/MSTK_U8_MICROS_DIVIDER);  break;
		case MSTK_U8_SECONDS : Copy_u32Ticks *= (MSTK_CLK);                         break;
	}
	MSTK_voidTICKInterrupt(MSTK_U8_TICKINT_EN);
	MSTK -> VAL = 0x00;
	MSTK_voidLoadVal(Copy_u32Ticks);
	MSTK_voidCounterEnDis(STK_U8_COUNTER_EN);
	
	CallBack = Copy_ptr;
}
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , u8 Copy_u8ValueType , void (*Copy_ptr)(void))
{
	
	switch(Copy_u8ValueType)
	{
		case MSTK_U8_TICKS   :                                                      break;
		case MSTK_U8_MILLIS  : Copy_u32Ticks *= (MSTK_CLK/MSTK_U8_MILLIS_DIVIDER);  break;
		case MSTK_U8_MICROS  : Copy_u32Ticks *= (MSTK_CLK/MSTK_U8_MICROS_DIVIDER);  break;
		case MSTK_U8_SECONDS : Copy_u32Ticks *= (MSTK_CLK);                         break;
	}
	MSTK_voidTICKInterrupt(MSTK_U8_TICKINT_EN);
	MSTK -> VAL = 0x00;
	MSTK_voidLoadVal(Copy_u32Ticks);
	MSTK_voidCounterEnDis(STK_U8_COUNTER_EN);
	
	CallBack = Copy_ptr;
}

u32 MSTK_u32GetReminingTime(u8 Copy_u8ValueType)
{
	switch(Copy_u8ValueType)
	{
		case MSTK_U8_TICKS   : return  (MSTK -> VAL);                                       break;
		case MSTK_U8_MILLIS  : return ((MSTK -> VAL)/(MSTK_CLK/MSTK_U8_MILLIS_DIVIDER));    break;
		case MSTK_U8_MICROS  : return ((MSTK -> VAL)/(MSTK_CLK/MSTK_U8_MICROS_DIVIDER));    break;
		case MSTK_U8_SECONDS : return ((MSTK -> VAL)/(MSTK_CLK));                           break;
	}
}

u32 MSTK_u32GetElapsedTime(u8 Copy_u8ValueType)
{
	witch(Cpy_u8TimeType){
		case MSTK_U8_TICKS  : return  ((MSTK->LOAD) - (MSTK->VAL));											break;
		case MSTK_U8_MICROS : return (((MSTK->LOAD) - (MSTK->VAL)) / (MSTK_CLK/MSTK_U8_MICROS_DIVIDER));	break;
		case MSTK_U8_MILLIS : return (((MSTK->LOAD) - (MSTK->VAL)) / (MSTK_CLK/MSTK_U8_MILLIS_DIVIDER));	break;
		case MSTK_U8_SECONDS: return (((MSTK->LOAD) - (MSTK->VAL)) / (MSTK_CLK));						    break;
	}
}

void MSTK_voidStopInterval(void)
{
	MSTK_voidCounterEnDis(MSTK_U8_COUNTER_DIS);
}

void SysTik_Handler(void)
{
	CallBack();
	
}