/*******************************************************/
/* Auther    : Mohamed Salem                           */
/* Date      : 27 APRIL 2021                           */ 
/* Version   : V01                                     */
/*******************************************************/

#ifndef _OS_PRIVATE_H
#define _OS_PRIVATE_H

typedef struct{
	u16 Priodicity;
	void (*Fptr)(void);
	u8 State;
	u16 InitialDelay;
}Task;

#define NULL   ((void *)(0))

#endif