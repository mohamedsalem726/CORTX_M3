/*******************************************************/
/* Auther    : Mohamed Salem                           */
/* Date      : 26 APRIL 2021                           */ 
/* Version   : V01                                     */
/*******************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h

#include "LEDMRX_config.h"
#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"

/* Array for the word */
u8 HLEDMRX_Char_A[8]={0, 124, 18, 18, 18, 124, 0, 0};
u8 HLEDMRX_Char_B[8]={0, 126, 82, 82, 82, 44, 0, 0};
u8 HLEDMRX_Char_C[8]={0, 60, 66, 66, 66, 66, 0, 0};
u8 HLEDMRX_Char_D[8]={0, 126, 66, 66, 66, 60, 0, 0};
u8 HLEDMRX_Char_E[8]={0, 126, 82, 82, 82, 66, 0, 0};
u8 HLEDMRX_Char_F[8]={0, 126, 18, 18, 18, 2, 0, 0};
u8 HLEDMRX_Char_G[8]={0, 60, 66, 66, 82, 48, 0, 0};
u8 HLEDMRX_Char_H[8]={0, 126, 16, 16, 16, 126, 0, 0};
u8 HLEDMRX_Char_I[8]={0, 66, 66, 126, 66, 66, 0, 0};
u8 HLEDMRX_Char_J[8]={0, 50, 66, 66, 62, 2, 0, 0};
u8 HLEDMRX_Char_K[8]={0, 126, 8, 8, 20, 98, 0, 0};
u8 HLEDMRX_Char_L[8]={0, 126, 64, 64, 64, 0, 0, 0};
u8 HLEDMRX_Char_M[8]={0, 126, 4, 8, 4, 126, 0, 0};
u8 HLEDMRX_Char_N[8]={0, 126, 4, 8, 16, 126, 0, 0};
u8 HLEDMRX_Char_O[8]={0, 60, 66, 66, 66, 66, 60, 0};
u8 HLEDMRX_Char_P[8]={0, 126, 18, 18, 18, 12, 0, 0};
u8 HLEDMRX_Char_Q[8]={0, 60, 66, 82, 98, 60, 0, 0};
u8 HLEDMRX_Char_R[8]={0, 126, 18, 18, 50, 76, 0, 0};
u8 HLEDMRX_Char_S[8]={0, 76, 82, 82, 82, 34, 0, 0};
u8 HLEDMRX_Char_T[8]={0, 2, 2, 126, 2, 2, 0, 0};
u8 HLEDMRX_Char_U[8]={0, 62, 64, 64, 64, 62, 0, 0};
u8 HLEDMRX_Char_V[8]={0, 30, 32, 64, 32, 30, 0, 0};
u8 HLEDMRX_Char_W[8]={0, 126, 32, 16, 32, 126, 0, 0};
u8 HLEDMRX_Char_X[8]={0, 70, 40, 16, 40, 70, 0, 0};
u8 HLEDMRX_Char_Y[8]={0, 6, 8, 112, 8, 6, 0, 0};
u8 HLEDMRX_Char_Z[8]={0, 98, 114, 90, 78, 70, 0, 0};


void HLEDMRX_voidInit(void)
{
	MGPIO_voidSetPinDirection(LEDMRX_ROW0_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW1_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW2_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW3_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW4_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW5_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW6_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW7_PIN,OUTPUT_SPEED_2MHZ_PP);
	
	MGPIO_voidSetPinDirection(LEDMRX_COL0_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL1_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL2_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL3_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL4_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL5_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL6_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL7_PIN,OUTPUT_SPEED_2MHZ_PP);
}

void HLEDMRX_voidCharDisplay (u8 Copy_u8Data , u32 Copy_u32Time)
{
	u8 LOC_u8Char[8];
	#if(Copy_u8Data == 'A')
	{
		for(u8 i =0 ; i<8 ; i++)
		{
			LOC_u8Char[i] = HLEDMRX_Char_A[i];
		}
		u32 LOC_u32TimesOfDisplay = 8*2500;
		LOC_u32TimesOfDisplay = Copy_u32Time/LOC_u32TimesOfDisplay;
		for(u32 i = 0 ; i<LOC_u32TimesOfDisplay ; i++)
		{
			for(u8 i = 0 ; i <8 ; i++)
			{
				/* Disable All Columns */
				HLEDMRX_voidDisableAllCols();
				/* Writting Value of Rows */
				HLEDMRX_voidSetRowValue(LOC_u8Char[i]);
				/* Enable Column i */
				HLEDMRX_voidSetLineValue(COLS,i,GPIO_LOW);
				/*******************************************/
				MSTK_voidSetBusyWait(2500,MSTK_U8_MICROS);  /* Busy wait for 2.5ms */
			}
		}
	}
}

void HLEDMRX_voidWordDisplay (u8 *Copy_u8Word , u32 Copy_u32Time)
{
	u8 LOC_u8Word[HLEDMRX_U8_MAX_NO_OF_CHARS_IN_WORD][8];
	u8 NumberOfChar = 0;
	while(Copy_u8Word[NumberOfChar] != '\0')
	{
		switch(Cpy_u8Word[NumberOfChar]){
		case 'A':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_A[i];
			}break;
		case 'B':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_B[i];
			}break;
		case 'C':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_C[i];
			}break;
		case 'D':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_D[i];
			}break;
		case 'E':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_E[i];
			}break;
		case 'F':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_F[i];
			}break;
		case 'G':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_G[i];
			}break;
		case 'H':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_H[i];
			}break;
		case 'I':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_I[i];
			}break;
		case 'J':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_J[i];
			}break;
		case 'K':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_K[i];
			}break;
		case 'L':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_L[i];
			}break;
		case 'M':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_M[i];
			}break;
		case 'N':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_N[i];
			}break;
		case 'O':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_O[i];
			}break;
		case 'P':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_P[i];
			}break;
		case 'Q':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_Q[i];
			}break;
		case 'R':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_R[i];
			}break;
		case 'S':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_S[i];
			}break;
		case 'T':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_T[i];
			}break;
		case 'U':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_U[i];
			}break;
		case 'V':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_V[i];
			}break;
		case 'W':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_W[i];
			}break;
		case 'X':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_X[i];
			}break;
		case 'Y':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_Y[i];
			}break;
		case 'Z':
			for(u8 i = 0; i<8; i++){
				LOC_u8Word[NumberOfChar][i]= HLEDMRX_Char_Z[i];
			}break;
		}
		NumberOfChar++;
	}
	u8 LOC_u8CurrentChar[8];
	u8 LOC_u8TempIndex = 0;
	u8 LOC_u8CharIndex = 0;
	u32 LOC_u32TimesOfDisplay = 8*2500;
	LOC_u32TimesOfDisplay = Copy_u32Time / LOC_u32TimesOfDisplay;
	for(u8 CurrentStart = 0 ; CurrentStart < ((NumberOfChar)*8) ; CurrentStart++)
	{
		for(u8 CurrentCharIndex = 0 ; CurrentCharIndex < 8 ; CurrentCharIndex++)
		{
			LOC_u8TempIndex = CurrentStart + CurrentCharIndex;
			if(	LOC_u8TempIndex < ((NumberOfChar)*8))
			{
				LOC_u8CharIndex = LOC_u8TempIndex / 8;
				LOC_u8TempIndex %= 8;
				LOC_u8CurrentChar[CurrentCharIndex] = LOC_u8Word[LOC_u8CharIndex][LOC_u8TempIndex];
			}
			else
			{
				LOC_u8TempIndex %= 8;
				LOC_u8CurrentChar[CurrentCharIndex] = LOC_u8Word[0][LOC_u8TempIndex];
			}
		}
		for(u8 Hold = 0 ; Hold < (LOC_u32TimesOfDisplay) ; Hold++)
		{
			for(u8 i = 0 ; i <8 ; i++)
			{
				/* Disable All Columns */
				HLEDMRX_voidDisableAllCols();
				/* Writting Value of Rows */
				HLEDMRX_voidSetRowValue(LOC_u8Char[i]);
				/* Enable Column i */
				HLEDMRX_voidSetLineValue(COLS,i,GPIO_LOW);
				/*******************************************/
				MSTK_voidSetBusyWait(2500,MSTK_U8_MICROS);  /* Busy wait for 2.5ms */
			}
		}
	}
	}


static void HLEDMRX_voidDisableAllCols(void)
{
	for(u8 i = 0 ; i<8 ; i++)
	{
		HLEDMRX_voidSetLineValue(COLS,i,GPIO_HIGH);
	}
}

static void HLEDMRX_voidSetRowValue(u8 Copy_u8Value)
{
	for(u8 i = 0 ; i<8 ; i++)
	{
		HLEDMRX_voidSetLineValue(ROWS,i,GET_BIT(Copy_u8Value,i));
	}
}

static void HLEDMRX_voidSetLineValue(u8 Copy_u8LineType , u8 Copy_u8LineNumber , u8 Copy_u8LineValue)
{
	switch (Copy_u8LineType)
	{
	case ROWS:
		switch(Copy_u8LineNumber)
		{
		case 0:	MGPIO_voidSetPinValue(LEDMRX_ROW0_PIN,Copy_u8LineValue);			break;
		case 1:	MGPIO_voidSetPinValue(LEDMRX_ROW1_PIN,Copy_u8LineValue);			break;
		case 2:	MGPIO_voidSetPinValue(LEDMRX_ROW2_PIN,Copy_u8LineValue);			break;
		case 3:	MGPIO_voidSetPinValue(LEDMRX_ROW3_PIN,Copy_u8LineValue);			break;
		case 4:	MGPIO_voidSetPinValue(LEDMRX_ROW4_PIN,Copy_u8LineValue);			break;
		case 5:	MGPIO_voidSetPinValue(LEDMRX_ROW5_PIN,Copy_u8LineValue);			break;
		case 6:	MGPIO_voidSetPinValue(LEDMRX_ROW6_PIN,Copy_u8LineValue);			break;
		case 7:	MGPIO_voidSetPinValue(LEDMRX_ROW7_PIN,Copy_u8LineValue);			break;
		}
		break;

	case COLS:
		switch(Copy_u8LineNumber)
		{
		case 0:	MGPIO_voidSetPinValue(LEDMRX_COL0_PIN,Copy_u8LineValue);			break;
		case 1:	MGPIO_voidSetPinValue(LEDMRX_COL1_PIN,Copy_u8LineValue);			break;
		case 2:	MGPIO_voidSetPinValue(LEDMRX_COL2_PIN,Copy_u8LineValue);			break;
		case 3:	MGPIO_voidSetPinValue(LEDMRX_COL3_PIN,Copy_u8LineValue);			break;
		case 4:	MGPIO_voidSetPinValue(LEDMRX_COL4_PIN,Copy_u8LineValue);			break;
		case 5:	MGPIO_voidSetPinValue(LEDMRX_COL5_PIN,Copy_u8LineValue);			break;
		case 6:	MGPIO_voidSetPinValue(LEDMRX_COL6_PIN,Copy_u8LineValue);			break;
		case 7:	MGPIO_voidSetPinValue(LEDMRX_COL7_PIN,Copy_u8LineValue);			break;
		}
		break;
	}
}