/*******************************************************/
/* Auther    : Mohamed Salem                           */
/* Date      : 24 APRIL 2021                           */ 
/* Version   : V01                                     */
/*******************************************************/
#ifndef _EXTI_PRIVATE_H
#define _EXTI_PRIVATE_H


typedef struct{
    volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
	
}EXTI_t;


#define MEXTI                ((volatile EXTI_t*)0x40010400)



void (*CallBack[16])(void) = NULL;

#endif