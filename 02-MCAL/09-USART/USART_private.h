
#ifndef _USART_PRIVATE_H
#define _USART_PRIVATE_H

typedef struct{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR[3];
	volatile u32 GTPR;
}USART_Register;


#define 	MUSART1 		((USART_Register *) 0x40013800)

#endif