/*******************************************************/
/* Auther    : Mohamed Salem                           */
/* Date      : 01 MAY 2021                             */ 
/* Version   : V01                                     */
/*******************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

#define THRESHOLD_VALUE  9000000UL
#define MUSART1_BAUD_RATE         (u32)9600

void MUSART1_voidInit(void)
{
	u32 LOC_u64Mantissa = ( F_CPU ) / ( 16 * MUSART1_BAUD_RATE) ;

	u32 LOC_u64Fraction = ( ( ( F_CPU * 100 ) / ( 16 * MUSART1_BAUD_RATE )  ) % 100 ) * 16 ;

	if( LOC_u64Fraction > 1500 ){ LOC_u64Mantissa += 1 ; LOC_u64Fraction  = 0 ; }
		#if MUSART1_STATUS == USART1_ENABLE

		MUSART1 -> SR = 0 ;

		#if   MUSART1_WORD_LENGTH == _8BIT_WORD_LENGTH

					CLR_BIT( MUSART1 -> CR1 , 12 );

		#elif MUSART1_WORD_LENGTH == _9BIT_WORD_LENGTH

					SET_BIT( MUSART1 -> CR1 , 12 );

		#endif

		#if   MUSART1_PARITY == PARITY_DISABLE

					CLR_BIT( MUSART1 -> CR1 , 10 );

		#elif MUSART1_PARITY == EVEN_PARITY

					SET_BIT( MUSART1 -> CR1 , 10 );
					CLR_BIT( MUSART1 -> CR1 , 11 );

		#elif MUSART1_PARITY == ODD_PARITY

					SET_BIT( MUSART1 -> CR1 , 10 );
					SET_BIT( MUSART1 -> CR1 , 11 );

		#endif

		#if  MUSART1_INTERRUPT == INT_DISABLE

					CLR_BIT( MUSART1 -> CR1 , 5 );
					CLR_BIT( MUSART1 -> CR1 , 6 );
					CLR_BIT( MUSART1 -> CR1 , 7 );

		#elif MUSART1_INTERRUPT == TXE_INT_ENABLE

					SET_BIT( MUSART1 -> CR1 , 7 );

		#elif MUSART1_INTERRUPT == TCE_INT_ENABLE

					SET_BIT( MUSART1 -> CR1 , 6 );

		#elif MUSART1_INTERRUPT == RXNE_INT_ENABLE

					SET_BIT( MUSART1 -> CR1 , 5 );

		#endif

		#if   MUSART1_TRANSMITTER == TRANSMITTER_ENABLE

					SET_BIT( MUSART1 -> CR1 , 3 );

		#elif MUSART1_TRANSMITTER == TRANSMITTER_DISABLE

					CLR_BIT( MUSART1 -> CR1 , 3 );

		#endif

		#if   MUSART1_RECEIVER == RECEIVER_ENABLE

					SET_BIT( MUSART1 -> CR1 , 2 );

		#elif MUSART1_RECEIVER == RECEIVER_DISBLE

					CLR_BIT( MUSART1 -> CR1 , 2 );

		#endif

		#if   MUSART1_STOP_BITS == ONE_STOP_BIT

					CLR_BIT( MUSART1 -> CR2 , 12 ); CLR_BIT( MUSART1 -> CR2 , 13 );

		#elif MUSART1_STOP_BITS == HALF_STOP_BIT

					SET_BIT( MUSART1 -> CR2 , 12 ); CLR_BIT( MUSART1 -> CR2 , 13 );

		#elif MUSART1_STOP_BITS == TWO_STOP_BIT

					CLR_BIT( MUSART1 -> CR2 , 12 ); SET_BIT( MUSART1 -> CR2 , 13 );

		#elif MUSART1_STOP_BITS == ONE_AND_HALF_STOP_BIT

					SET_BIT( MUSART1 -> CR2 , 12 ); SET_BIT( MUSART1 -> CR2 , 13 );


		#endif

		MUSART1 -> BRR = ( LOC_u64Mantissa << 4  ) | ( LOC_u64Fraction / 100 ) ;
		SET_BIT( MUSART1 -> CR1 , 13 );

	#elif MUSART1_STATUS == USART1_DISABLE
		CLR_BIT( MUSART1 -> CR1 , 0 );

	#endif
}

void MUSART1_voidSendChar(u8 Copy_u8Char)
{

	MUSART1 -> DR = Copy_u8Char ;

	while( GET_BIT( MUSART1 -> SR , 6 ) == 0 );

	CLR_BIT( MUSART1 -> SR , 6 );

}


void MUSART1_voidSendString(u8 *Copy_ptrString)
{

	u8 LOC_u8Iterator = 0 ;

	while ( Copy_ptrString[ LOC_u8Iterator ] != '\0' ){

		MUSART1_voidSendChar(Copy_ptrString[ LOC_u8Iterator ]);
		LOC_u8Iterator++ ;

	}

}

u8 MUSART1_u8ReceiveChar(void)
{

	u8  LOC_u8Data  = 0 ;
	u32 LOC_u8TimeOut = 0 ;

	CLR_BIT(MUSART1 -> SR, 5);

	while( ( GET_BIT(MUSART1 -> SR, 5) == 0 ) && (LOC_u8TimeOut < THRESHOLD_VALUE) )
	{
		LOC_u8TimeOut++;
	}

	if( LOC_u8TimeOut == THRESHOLD_VALUE )
	{
		LOC_u8Data = 255;
	}
	else
	{

		LOC_u8Data = MUSART1 -> DR;
	}

	return LOC_u8Data;

}


