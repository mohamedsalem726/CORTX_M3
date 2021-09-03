/*****************************************************/
/* Auther    : Mohamed Salem                         */
/* Date      : 03 MAY 2021                           */ 
/* Version   : V01                                   */
/*****************************************************/

/* Library Include */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Include */
#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"

/* Driver Include */
#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

void HTFT_voidInit(void)
{
	/* Reset Pulse */
	MGPIO_voidSetPinValue(HTFT_RESET_PIN,GPIO_HIGH);
	MSTK_voidSetBusyWait(100,MSTK_MICROS);
	MGPIO_voidSetPinValue(HTFT_RESET_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(1,MSTK_MICROS);
	MGPIO_voidSetPinValue(HTFT_RESET_PIN,GPIO_HIGH);
	MSTK_voidSetBusyWait(100,MSTK_MICROS);
	MGPIO_voidSetPinValue(HTFT_RESET_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(100,MSTK_MICROS);
	MGPIO_voidSetPinValue(HTFT_RESET_PIN,GPIO_HIGH);
	MSTK_voidSetBusyWait(120,MSTK_MILLIS);

	/* Sleep Out Command */
	HTFT_voidWriteCommand(0x11);

	/* Wait 150 ms */
	MSTK_voidSetBusyWait(150,MSTK_MILLIS);

	/* Color Mode Command */
	HTFT_voidWriteCommand(0x3A);
	HTFT_voidWriteData(0x05); /* Parameter  For Color Mode Command */

	/* Display On Command */
	HTFT_voidWriteCommand(0x29);
}

void HTFT_voidDisplayImage(const u16 * Copy_u16Image)
{
	u16 LOC_u16Counter;

	/* Set X Address Command */
	HTFT_voidWriteCommand(0x2A);
	
	/* Parameter For Set X Address Command */
	/* Start */
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);
	/* End */
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(127);

	/* Set Y Address Command */
	HTFT_voidWriteCommand(0x2B);

	/* Parameter For Set Y Address Command */
	/* Start */
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);
	/* End */
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(159);

	/* RAM Write Command */
	HTFT_voidWriteCommand(0x2C);

	for(LOC_u16Counter = 0; LOC_u16Counter < 20480; LOC_u16Counter++)
	{
		/* Write The High Byte */
		HTFT_voidWriteData(Copy_u16Image[LOC_u16Counter] >> 8);

		/* Write The Low Byte */
		HTFT_voidWriteData(Copy_u16Image[LOC_u16Counter] & 0x00FF);
	}
}

static void HTFT_voidWriteCommand(u8 Copy_u8Command)
{
	u8 LOC_u8Temp;
	/* Set A0 Pin to Low */
	MGPIO_voidSetPinValue(HTFT_A0_PIN,GPIO_LOW);

	/* Send Command Over SPI */
	MSPI1_voidSendReceiveSynch(Copy_u8Command , &LOC_u8Temp);
}

static void HTFT_voidWriteData(u8 Copy_u8Data)
{
	u8 LOC_u8Temp;
	/* Set A0 Pin to High */
	MGPIO_voidSetPinValue(HTFT_A0_PIN,GPIO_HIGH);

	/* Send Data Over SPI */
	MSPI1_voidSendReceiveSynch(Copy_u8Data , &LOC_u8Temp);
}
