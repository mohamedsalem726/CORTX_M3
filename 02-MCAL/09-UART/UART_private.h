/*******************************************************/
/* Auther    : Mohamed Salem                           */
/* Date      : 01 MAY 2021                             */ 
/* Version   : V01                                     */
/*******************************************************/

#ifndef _UART_PRIVATE_H
#define _UART_PRIVATE_H

typedef struct{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}UART_Register;

#define MUSART    ((volatile UART_Register*)0x40013800)


#endif