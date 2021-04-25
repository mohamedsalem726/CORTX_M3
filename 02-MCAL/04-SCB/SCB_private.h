/*******************************************************/
/* Auther    : Mohamed Salem                           */
/* Date      : 24 APRIL 2021                           */ 
/* Version   : V01                                     */
/*******************************************************/

#ifndef _SCB_PRIVATE_H
#define _SCB_PRIVATE_H

/* Defining SCB Register Macros */

#define SCB_AIRCR				*((volatile u32 *)(0xE000ED00+0x0C))

/********************************/

/* NVIC related private macros */

#define MNVIC_4_GROUPS_0_SUB			0x05FA0300
#define MNVIC_3_GROUPS_1_SUB			0x05FA0400
#define MNVIC_2_GROUPS_2_SUB			0x05FA0500
#define MNVIC_1_GROUPS_3_SUB			0x05FA0600
#define MNVIC_0_GROUPS_4_SUB			0x05FA0700

#define MNVIC_4_GROUPS_0_SUB_READ		0xFA050300
#define MNVIC_3_GROUPS_1_SUB_READ		0xFA050400
#define MNVIC_2_GROUPS_2_SUB_READ		0xFA050500
#define MNVIC_1_GROUPS_3_SUB_READ		0xFA050600
#define MNVIC_0_GROUPS_4_SUB_READ		0xFA050700

/*******************************/

#endif