/*******************************************************/
/* Auther    : Mohamed Salem                           */
/* Date      : 22 APRIL 2021                           */ 
/* Version   : V01                                     */
/*******************************************************/

#ifndef _NVIC_INTERFACE_H
#define _NVIC_INTERFACE_H

/* Global Macros */
#define MNVIC_U8_ENABLE			1
#define MNVIC_U8_DISABLE		0
/*****************/

/* Global Functions */

/* MNVIC_voidEnableInterrupt --> Enables a specific external interrupt 	*/
/* I/P:- Cpy_u8IntNumber / Available options: 1 : 59 					*/
/* O/P:- void															*/
/************************************************************************/
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber);

/* MNVIC_voidDisableInterrupt --> Disables a specific external interrupt 	*/
/* I/P:- Cpy_u8IntNumber / Available options: 1 : 59 						*/
/* O/P:- void																*/
/****************************************************************************/
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber);

/* MNVIC_voidSetPendingInterrupt --> Sets pending interrupt for a specific external interrupt 	*/
/* I/P:- Cpy_u8IntNumber / Available options: 1 : 59 											*/
/* O/P:- void																					*/
/************************************************************************************************/
void MNVIC_voidSetPendingInterrupt(u8 Copy_u8IntNumber);

/* MNVIC_voidClearPendingInterrupt --> Resets pending interrupt for a specific external interrupt 	*/
/* I/P:- Cpy_u8IntNumber / Available options: 1 : 59 												*/
/* O/P:- void																						*/
/****************************************************************************************************/
void MNVIC_voidClearPendingInterrupt(u8 Copy_u8IntNumber);

/* MNVIC_u8ActiveInterrupt --> Returns active interrupt state for a specific external interrupt 	*/
/* I/P:- Cpy_u8IntNumber / Available options: 1 : 59 												*/
/* O/P:- Loc_u8InterruptState (State of active interrupt)																						*/
/****************************************************************************************************/
u8 MNVIC_u8ActiveInterrupt(u8 Copy_u8IntNumber);

/* MNVIC_voidSetPriorityValue --> Sets interrupt group & sub priorities	*/
/* I/P:- MNVIC_voidSetPriorityValue / Available options: 1 : 59 		*/
/* O/P:- Cpy_u8GrpPrVal (Group priority):- 1:16							*/
/* O/P:- Cpy_u8SubPrVal (Sub priority):- 1:16							*/
/************************************************************************/
void MNVIC_voidSetPriorityValue(u8 Copy_u8IntNumber, u8 Copy_u8GrpPrVal, u8 Copy_u8SubPrVal);

/* MNVIC_voidEXTIEnControl --> Enables or disables External interrupt for EXTI 	*/
/* I/P: 
		Cpy_u8EnorDis: 	* Value to enable or disable External interrupt for EXTI
						* Type: u8
						* Available options:	- MNVIC_U8_ENABLE
												- MNVIC_U8_DISABLE
                                                                             	*/
/* O/P: void 																	*/
void MNVIC_voidEXTIEnControl(u8 Copy_u8Line, u8 Copy_u8EnorDis);
/********************************************************************************/






#endif