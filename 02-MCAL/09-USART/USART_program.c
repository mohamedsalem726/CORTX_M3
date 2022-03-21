

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"



void MUSART1_voidInit(void)
{
	/* Baud Rate = 9600 */
	MUSART1 ->BRR = 0x341;

	SET_BIT((MUSART1-> CR[0]), 3);			/* Enabling Transmitter */
	SET_BIT((MUSART1-> CR[0]), 2);			/* Enabling Receiver */
	SET_BIT((MUSART1-> CR[0]), 13);			/* Enabling USART */

	MUSART1 -> SR = 0;						/* Clearing status register */
}

void MUSART1_voidTransmit(u8 arr[])
{
	u8 i = 0;
		while(arr[i] != '\0'){
			MUSART1 -> DR = arr[i];
			while((GET_BIT((MUSART1 -> SR), 6)) == 0);
			i++;
		}
}

u8 MUSART1_u8Receive(u8* Copy_u8Data)
{
	u8 Local_u8Result = 1;

	if ( (GET_BIT((MUSART1 -> SR), 5)) == 1 )
	{
		*Copy_u8Data = MUSART1 -> DR;
	}
	else
	{
		Local_u8Result = 0;
	}

	return (Local_u8Result);
}
