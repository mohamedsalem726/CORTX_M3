/*******************************************************/
/* Auther    : Mohamed Salem                           */
/* Date      : 24 APRIL 2021                           */ 
/* Version   : V01                                     */
/*******************************************************/

/* Library layer includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Mcal layer Includes */
#include "SCB_interface.h"
#include "SCB_private.h"
#include "SCB_config.h"

void MNVIC_voidInit(void) {
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIB;
}

u8 MNVIC_u8ReturnConfig(void){
		
	if(SCB_AIRCR == MNVIC_4_GROUPS_0_SUB_READ){
			return MNVIC_GS_CONFIG_4_0;
	}else if(SCB_AIRCR == MNVIC_3_GROUPS_1_SUB_READ){
			return MNVIC_GS_CONFIG_3_1;
	}else if(SCB_AIRCR == MNVIC_2_GROUPS_2_SUB_READ){
			return MNVIC_GS_CONFIG_2_2;
	}else if(SCB_AIRCR == MNVIC_1_GROUPS_3_SUB_READ){
			return MNVIC_GS_CONFIG_1_3;
	}else if(SCB_AIRCR == MNVIC_0_GROUPS_4_SUB_READ){
			return MNVIC_GS_CONFIG_0_4;
	}else{
			/* Report error */
	}
	
}