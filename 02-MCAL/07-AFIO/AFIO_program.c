/*******************************************************/
/* Auther    : Mohamed Salem                           */
/* Date      : 25 APRIL 2021                           */ 
/* Version   : V01                                     */
/*******************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

void MAFIO_voidSetEXTIConfig(u8 Copy_u8Line, u8 Copy_u8Port)
{
	u8 LOC_u8RegNo = (Copy_u8Line / 4);
	u8 LOC_u8RegIndex = (Copy_u8Line % 4);
	
	MAFIO -> EXTICR[LOC_u8RegNo] &= ~( 15 << (LOC_u8RegIndex*4) );
	MAFIO -> EXTICR[LOC_u8RegNo] |=  ( Copy_u8Port << (LOC_u8RegIndex*4) );
}