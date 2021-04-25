/************************************************/
/* Auther   : Mohamed Salem                     */
/* Date     : 17 APRIL 2021                     */ 
/* Version  : V01                               */
/************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
	#if    RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
	    RCC_CR   = 0x00010000; /* Enable HEE WITH NO BYPASS */
		RCC_CFGR = 0x00000001;  
		
	#elif  RCC_CLOCK_TYPE == RCC_HSE_RC
        RCC_CR   = 0x00050000; /* Enable HEE WITH BYPASS */
		RCC_CFGR = 0x00000001;
	  
	#elif  RCC_CLOCK_TYPE == RCC_HSI
	    RCC_CR   = 0x00000081; /* Enable HSI */
		RCC_CFGR = 0x00000000;
		
	#elif  RCC_CLOCK_TYPE == RCC_PLL
       #if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
	      #if   RCC_PLL_MUL_val == 2
		     RCC_CFGR = 0x00000002;
		  #elif RCC_PLL_MUL_val == 3
		     RCC_CFGR = 0x00040002;
		  #elif RCC_PLL_MUL_val == 4
		     RCC_CFGR = 0x00080002;
		  #elif RCC_PLL_MUL_val == 5
		     RCC_CFGR = 0x000C0002;
		  #elif RCC_PLL_MUL_val == 6
		     RCC_CFGR = 0x00100002;
		  #elif RCC_PLL_MUL_val == 7
		     RCC_CFGR = 0x00140002;
		  #elif RCC_PLL_MUL_val == 8
		     RCC_CFGR = 0x00180002;
		  #elif RCC_PLL_MUL_val == 9
		     RCC_CFGR = 0x001C0002;
		  #elif RCC_PLL_MUL_val == 10
		     RCC_CFGR = 0x00200002;
		  #elif RCC_PLL_MUL_val == 11
		     RCC_CFGR = 0x00240002;
		  #elif RCC_PLL_MUL_val == 12
		     RCC_CFGR = 0x00280002;
		  #elif RCC_PLL_MUL_val == 13
		     RCC_CFGR = 0x002C0002;
		  #elif RCC_PLL_MUL_val == 14
		     RCC_CFGR = 0x00300002;
		  #elif RCC_PLL_MUL_val == 15
		     RCC_CFGR = 0x00340002;
		  #elif RCC_PLL_MUL_val == 16
		     RCC_CFGR = 0x00380002 || 0x003C0002;
		  #else
		   #error("Your Chosed Wrong MUL INPUT")
		  #endif
	   
	   #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
	      #if   RCC_PLL_MUL_val == 2
		     RCC_CFGR = 0x00030002;
		  #elif RCC_PLL_MUL_val == 3
		     RCC_CFGR = 0x00070002;
		  #elif RCC_PLL_MUL_val == 4
		     RCC_CFGR = 0x000B0002;
		  #elif RCC_PLL_MUL_val == 5
		     RCC_CFGR = 0x000F0002;
		  #elif RCC_PLL_MUL_val == 6
		     RCC_CFGR = 0x00130002;
		  #elif RCC_PLL_MUL_val == 7
		     RCC_CFGR = 0x00170002;
		  #elif RCC_PLL_MUL_val == 8
		     RCC_CFGR = 0x001B0002;
		  #elif RCC_PLL_MUL_val == 9
		     RCC_CFGR = 0x001F0002;
		  #elif RCC_PLL_MUL_val == 10
		     RCC_CFGR = 0x00230002;
		  #elif RCC_PLL_MUL_val == 11
		     RCC_CFGR = 0x00270002;
		  #elif RCC_PLL_MUL_val == 12
		     RCC_CFGR = 0x002B0002;
		  #elif RCC_PLL_MUL_val == 13
		     RCC_CFGR = 0x002F0002;
		  #elif RCC_PLL_MUL_val == 14
		     RCC_CFGR = 0x00330002;
		  #elif RCC_PLL_MUL_val == 15
		     RCC_CFGR = 0x00370002;
		  #elif RCC_PLL_MUL_val == 16
		     RCC_CFGR = 0x003B0002 || 0x003F0002;
		  #else
		   #error("Your Chosed Wrong MUL INPUT")
		  #endif
	   
	   #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
          #if   RCC_PLL_MUL_val == 2
		     RCC_CFGR = 0x00010002;
		  #elif RCC_PLL_MUL_val == 3
		     RCC_CFGR = 0x00050002;
		  #elif RCC_PLL_MUL_val == 4
		     RCC_CFGR = 0x00090002;
		  #elif RCC_PLL_MUL_val == 5
		     RCC_CFGR = 0x000D0002;
		  #elif RCC_PLL_MUL_val == 6
		     RCC_CFGR = 0x00110002;
		  #elif RCC_PLL_MUL_val == 7
		     RCC_CFGR = 0x00150002;
		  #elif RCC_PLL_MUL_val == 8
		     RCC_CFGR = 0x00190002;
		  #elif RCC_PLL_MUL_val == 9
		     RCC_CFGR = 0x001D0002;
		  #elif RCC_PLL_MUL_val == 10
		     RCC_CFGR = 0x00210002;
		  #elif RCC_PLL_MUL_val == 11
		     RCC_CFGR = 0x00250002;
		  #elif RCC_PLL_MUL_val == 12
		     RCC_CFGR = 0x00290002;
		  #elif RCC_PLL_MUL_val == 13
		     RCC_CFGR = 0x002D0002;
		  #elif RCC_PLL_MUL_val == 14
		     RCC_CFGR = 0x00310002;
		  #elif RCC_PLL_MUL_val == 15
		     RCC_CFGR = 0x00350002;
		  #elif RCC_PLL_MUL_val == 16
		     RCC_CFGR = 0x00390002 || 0x003D0002;
		  #else
		   #error("Your Chosed Wrong MUL INPUT")
		  #endif
	   
	   #else
		   #error("Your Chosed Wrong PLL Input")
	   #endif
	
	#else
		#error("Your Chosed Wrong Clock Type")
	#endif
}



void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR  ,Copy_u8PerId);    break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR ,Copy_u8PerId);    break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR ,Copy_u8PerId);    break;
		}
	}
	
	else
	{
		/* Return Error */
	}
	
}


void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR  ,Copy_u8PerId);    break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR ,Copy_u8PerId);    break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR ,Copy_u8PerId);    break;
		}
	}
	
	else
	{
		/* Return Error */
	}
	
}




