/*******************************************************/
/* Auther    : Mohamed Salem                           */
/* Date      : 29 APRIL 2021                           */ 
/* Version   : V01                                     */
/*******************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"
#include "STP_config.h"
#include "STP_private.h"


void HSTP_voidSendSynchronus(u8 Copy_u8DataToSend)
{
	s8 LOC_s8Counter;
	u8 LOC_u8BIT;
	for(LOC_s8Counter = 7 ; LOC_s8Counter >= 0 ; LOC_s8Counter++)
	{
		/* Send bit by bit starting from MSB */
		LOC_u8BIT = GET_BIT(Copy_u8DataToSend,LOC_s8Counter);
		
		
		MGPIO_voidSetPinValue(HSTP_SREIAL_DATA,LOC_u8BIT);
		
		/* Send Pulse To Shift Clock */
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,GPIO_HIGH);
		MSTK_voidSetBusyWait(1,MSTK_MICROS);
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,GPIO_LOW);
		MSTK_voidSetBusyWait(1,MSTK_MICROS);
		
	}
	/* Send Pulse TO Store Clock */
	MGPIO_voidSetPinValue(HSTP_STORE_CLOCK,GPIO_HIGH);
	MSTK_voidSetBusyWait(1,MSTK_MICROS);
	MGPIO_voidSetPinValue(HSTP_STORE_CLOCK,GPIO_LOW);
	MSTK_voidSetBusyWait(1,MSTK_MICROS);

}