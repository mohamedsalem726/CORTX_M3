/*******************************************************/
/* Auther    : Mohamed Salem                           */
/* Date      : 25 APRIL 2021                           */ 
/* Version   : V01                                     */
/*******************************************************/

#ifndef _STK_PRIVATE_H_
#define _STK_PRIVATE_H_

typedef struct{

	volatile u32 CTRL ;
	volatile u32 LOAD ;
	volatile u32 VAL  ;
	volatile u32 CALIB;

}SYSTICK;


#define MSTK ((volatile SYSTICK*)0xE000E010)



void (* CallBack)(void);

#endif