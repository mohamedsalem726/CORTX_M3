/*******************************************************/
/* Auther    : Mohamed Salem                           */
/* Date      : 24 APRIL 2021                           */ 
/* Version   : V01                                     */
/*******************************************************/

#ifndef _SCB_INTERFACE_H
#define _SCB_INTERFACE_H

/* Global Functions */

/* NVIC related global variables */

/* MNVIC_voidInit --> Initializes NVIC by Setting Bits options to control group and sub priority distribution 	*/
/* I/P:- void										 															*/
/* O/P:- void																									*/
/****************************************************************************************************************/
void MNVIC_voidInit(void);

/* MNVIC_u8ReturnConfig --> Returns a Macro corresponding to the configuration of priority grouping field in the Application interrupt and reset control register 	*/
/* I/P:- 	void 																																					*/
/* O/P:- 	return type: u8 
			Availabe return values:-
										MNVIC_GS_CONFIG_4_0
										MNVIC_GS_CONFIG_3_1
										MNVIC_GS_CONFIG_2_2
										MNVIC_GS_CONFIG_1_3
										MNVIC_GS_CONFIG_0_4
																																									*/
/********************************************************************************************************************************************************************/															
u8 MNVIC_u8ReturnConfig(void);

/*********************************/

/********************/

/* Global Macros */

/* NVIC related global macros */

# define MNVIC_GS_CONFIG_4_0	0
# define MNVIC_GS_CONFIG_3_1	1
# define MNVIC_GS_CONFIG_2_2	2
# define MNVIC_GS_CONFIG_1_3	3
# define MNVIC_GS_CONFIG_0_4	4

/******************************/

/*****************/

#endif