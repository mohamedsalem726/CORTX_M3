/*******************************************************/
/* Auther    : Mohamed Salem                           */
/* Date      : 25 APRIL 2021                           */ 
/* Version   : V01                                     */
/*******************************************************/

#ifndef _AFIO_PRIVATE_H
#define _AFIO_PRIVATE_H


typedef struct
{
	volatile u32 EVCR;
	volatile u32 MAPR;
    volatile u32 EXTICR[4];
	volatile u32 MAPR2;
}AFIO_RE;

#define MAFIO      ((volatil AFIO_RE *)0x40010000)


#endif