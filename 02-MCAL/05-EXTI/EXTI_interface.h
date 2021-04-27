/*******************************************************/
/* Auther    : Mohamed Salem                           */
/* Date      : 24 APRIL 2021                           */ 
/* Version   : V01                                     */
/*******************************************************/

#ifndef _EXTI_INTERFACE_H
#define _EXTI_INTERFACE_H

/* Global Macros definition*/

/* Triggering type related Macros */
#define MEXTI_RISING_EDGE_TRIGGER		0
#define MEXTI_FALLING_EDGE_TRIGGER		1
#define MEXTI_BOTH_EDGES_TRIGGER			2
/**********************************/

/* Enabling and disabling Macros */
#define MEXTI_ENABLE						1
#define MEXTI_DISABLE					0
/*********************************/

/***************************/

/* Global functions */

/* MEXTI_voidInit:	- Enables External interrupt for EXTI
					- Unmask Interrupt request from selected EXTI line(Cpy_u8Line) 
					- Selects triggering type 
					- Selects the source input for EXTI Line								*/
/* I/P:	- 	Cpy_u8Port: * Port of which source input for EXTI Line is to be selected
						* Type: u8
						* Available options: 	- GPIO_U8_PORTA
												- GPIO_U8_PORTB
												- GPIO_U8_PORTC
			Cpy_u8Line:	* EXTI line for which the configuration is to be done(line to be initialized)
						* Type: u8
						* Available options: 0 : 15
			Cpy_u8TriggerSel: 	* Triggering type needed to be selected
								* Type: u8
								*Available options:	- MEXTI_U8_RISING_EDGE_TRIGGER
													- MEXTI_U8_FALLING_EDGE_TRIGGER
													- MEXTI_U8_BOTH_EDGES_TRIGGER
																							*/
/* O/P: void 																				*/
void MEXTI_voidInit(u8 Copy_u8Port, u8 Copy_u8Line, u8 Copy_u8TriggerSel);

/********************************************************************************************/

/* MEXTI_voidLineEnorDis:	- Masks or unmasks Interrupt request from selected EXTI line(Cpy_u8Line) 
																							*/
/* I/P:	- 	Cpy_u8Line:	* EXTI line for which the configuration is to be done(line to be initialized)
						* Type: u8
						* Available options: 0 : 15
			Cpy_u8EnorDis: 	* Wanted state of EXTI line (Enable or disable)
							* type: u8
							* Available options:	- MEXTI_U8_ENABLE
													- MEXTI_U8_DISABLE
																							*/
/* O/P: void 																				*/
void MEXTI_voidLineEnorDis(u8 Copy_u8Line, u8 Copy_u8EnorDis);
/********************************************************************************************/

/* MEXTI_voidTriggerSel:	- Selects triggering type 
																							*/
/* I/P:	-	Cpy_u8Line:	* EXTI line for which the configuration is to be done(line to be initialized)
						* Type: u8
						* Available options: 0 : 15
			Cpy_u8TriggerSel: 	* Triggering type needed to be selected
								* Type: u8
								*Available options:	- MEXTI_U8_RISING_EDGE_TRIGGER
													- MEXTI_U8_FALLING_EDGE_TRIGGER
													- MEXTI_U8_BOTH_EDGES_TRIGGER
																							*/
/* O/P: void 																				*/
void MEXTI_voidTriggerSel(u8 Copy_u8Line, u8 Copy_u8TriggerSel);
/********************************************************************************************/

/* MEXTI_voidSetSWInt:	- Sets the corresponding pending bit in EXTI_PR resulting in an interrupt request 
																							*/
/* I/P:	- 	Cpy_u8Line:	* EXTI line for which the configuration is to be done(line to be initialized)
						* Type: u8
						* Available options: 0 : 15
																							*/
/* O/P: void 																				*/
void MEXTI_voidSetSWInt(u8 Copy_u8Line);
/********************************************************************************************/

/* MEXTI_u8GetPR:	Returns	the State of corresponding pending bit in EXTI_PR				*/
/* I/P:	- 	Cpy_u8Line:	* EXTI line for which the configuration is to be done(line to be initialized)
						* Type: u8
						* Available options: 0 : 15
																							*/
/* O/P: 	* State of corresponding pending bit in EXTI_PR
			* Type: u8
			* Available options: 0 or 1
																							*/
u8 MEXTI_u8GetPR(u8 Copy_u8Line);
/********************************************************************************************/

/* MEXTI_voidInit:	Clears corresponding pending bit in EXTI_PR								*/
/* I/P:	- 	Cpy_u8Line:	* EXTI line for which the configuration is to be done(line to be initialized)
						* Type: u8
						* Available options: 0 : 15
																							*/
/* O/P: void 																				*/
void MEXTI_voidClrPR(u8 Copy_u8Line);
/********************************************************************************************/

/* MEXTI_voidSetCallBack: Clears corresponding pending bit in EXTI_PR								*/
/* I/P:	- 	ptr_Func:	* Pointer to function needed to be set fr callback in the EXTI ISR
						* Type: pointer to function (void return type, void arguments)
						
			Cpy_u8Line:	* EXTI line for which the configuration is to be done(line to be initialized)
						* Type: u8
						* Available options: 0 : 15
																							*/
/* O/P: void 																				*/
void MEXTI_voidSetCallBack(void (*ptr_Func)(void), u8 Copy_u8Line);

/********************/         



#endif 