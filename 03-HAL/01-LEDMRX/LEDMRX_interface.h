/*******************************************************/
/* Auther    : Mohamed Salem                           */
/* Date      : 26 APRIL 2021                           */ 
/* Version   : V01                                     */
/*******************************************************/

#ifndef _LEDMRX_INTERFACE_H
#define _LEDMRX_INTERFACE_H

#define ROWS						0
#define COLS 						1

void HLEDMRX_voidInit    (void);
void HLEDMRX_voidCharDisplay (u8  Copy_u8Data , u32 Copy_u32Time);
void HLEDMRX_voidWordDisplay (u8 *Copy_u8Word , u32 Copy_u32Time);


#endif