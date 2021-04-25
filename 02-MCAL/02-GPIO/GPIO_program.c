/*****************************************************/
/* Auther    : Mohamed Salem                         */
/* Date      : 12 FEB 2021                           */ 
/* Version   : V01                                   */
/*****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"


void MGPIO_voidSetPinDirection(u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Mode)
{
	switch(copy_u8Port){
	case GPIOA :
	
	    if(copy_u8Pin <= 7){//Low
		
		    MGPIOA->CRL &= ~ ((0b1111) << (copy_u8Pin * 4));
		    MGPIOA->CRL |=   ((copy_u8Mode) << (copy_u8Pin * 4));
			
		}else if(copy_u8Pin <= 15){//High
			
			copy_u8Pin = copy_u8Pin - 8;
			MGPIOA->CRH &= ~ ((0b1111) << (copy_u8Pin * 4)); 
			MGPIOA->CRH |=   ((copy_u8Mode) << (copy_u8Pin * 4));
			
	    }
		
		break;
		
	case GPIOB :
	
	    if(copy_u8Pin <= 7){//Low
		
		    MGPIOB->CRL &= ~ ((0b1111) << (copy_u8Pin * 4));
		    MGPIOB->CRL |=   ((copy_u8Mode) << (copy_u8Pin * 4));
			
		}else if(copy_u8Pin <= 15){//High
			
			copy_u8Pin = copy_u8Pin - 8;
			MGPIOB->CRH &= ~ ((0b1111) << (copy_u8Pin * 4)); 
			MGPIOB->CRH |=   ((copy_u8Mode) << (copy_u8Pin * 4));
			
	    }
		
		break;
		
	case GPIOC :
	
		if(copy_u8Pin <= 7){//Low
		
			MGPIOC->CRL &= ~ ((0b1111) << (copy_u8Pin * 4));
			MGPIOC->CRL |=   ((copy_u8Mode) << (copy_u8Pin * 4));
			
		}else if(copy_u8Pin <= 15){//High
		
			copy_u8Pin = copy_u8Pin - 8;
			MGPIOC->CRH &= ~ ((0b1111) << (copy_u8Pin * 4)); 
		    MGPIOC->CRH |=   ((copy_u8Mode) << (copy_u8Pin * 4));
			
		}
		
		break;
		
	default : break;
	}
}

void MGPIO_voidSetPinValue(u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Value)
{
	switch(copy_u8Port){
	case GPIOA :
	
	    if(copy_u8Value == GPIO_HIGH){
			
			SET_BIT(MGPIOA->ODR , copy_u8Pin);
			
		}else if(copy_u8Value == GPIO_LOW){
			
			CLR_BIT(MGPIOA->ODR , copy_u8Pin);
			
		}
		
		break;
		
	case GPIOB :
	    
		if(copy_u8Value == GPIO_HIGH){
	    	
	    	SET_BIT(MGPIOB->ODR , copy_u8Pin);
	    	
	    }else if(copy_u8Value == GPIO_LOW){
	    	
	    	CLR_BIT(MGPIOB->ODR , copy_u8Pin);
	    	
	    }
       
        break;
		
	case GPIOC :
	    
		if(copy_u8Value == GPIO_HIGH){
			
			SET_BIT(MGPIOC->ODR , copy_u8Pin);
			
		}else if(copy_u8Value == GPIO_LOW){
			
			CLR_BIT(MGPIOC->ODR , copy_u8Pin);
			
		}
		
		break;
		
	default : break;
	}
u8 MGPIO_u8GetPinValue(u8 copy_u8Port , u8 copy_u8Pin)
{
	u8  LOC_u8Result = 0;
	
	switch(copy_u8Port){
	case GPIOA :
		
		LOC_u8Result = GET_BIT(MGPIOA->IDR , Copy_u8Pin);
		
		break;
		
	case GPIOB :
	    
		LOC_u8Result = GET_BIT(MGPIOB->IDR , Copy_u8Pin);
		
        break;	
		
	case GPIOC :
	
	    LOC_u8Result = GET_BIT(MGPIOC->IDR , Copy_u8Pin);
		
		break;
		
	default : break;
	}
	
	return LOC_u8Result ;
	
}
void MGPIO_voidLockPin(u8 copy_u8Port , u8 copy_u8Pin)
{
	switch(copy_u8Port){
	case GPIOA :
	
	    /* Lock Sequence */
	    SET_BIT(MGPIOA->LCKR,15);
		CLR_BIT(MGPIOA->LCKR,15);
		SET_BIT(MGPIOA->LCKR,15);
		CLR_BIT(MGPIOA->LCKR,15);
		GET_BIT(MGPIOA->LCKR,15);
		SET_BIT(MGPIOA->LCKR,15);
		GET_BIT(MGPIOA->LCKR,15);
		
		/* Pin Locked */
		MGPIOA->LCKR = (1 << copy_u8Pin);
		
		break;
		
	case GPIOB :
	
	    /* Lock Sequence */
	    SET_BIT(MGPIOB->LCKR,15);
		CLR_BIT(MGPIOB->LCKR,15);
		SET_BIT(MGPIOB->LCKR,15);
		CLR_BIT(MGPIOB->LCKR,15);
		GET_BIT(MGPIOB->LCKR,15);
		SET_BIT(MGPIOB->LCKR,15);
		GET_BIT(MGPIOB->LCKR,15);
		
		/* Pin Locked */
		MGPIOB->LCKR = (1 << copy_u8Pin);
		
		break;
		
	case GPIOC :
		
	    /* Lock Sequence */}
        SET_BIT(MGPIOC->LCKR,15);
    	CLR_BIT(MGPIOC->LCKR,15);
    	SET_BIT(MGPIOC->LCKR,15);
    	CLR_BIT(MGPIOC->LCKR,15);
    	GET_BIT(MGPIOC->LCKR,15);
    	SET_BIT(MGPIOC->LCKR,15);
    	GET_BIT(MGPIOC->LCKR,15);
    	
    	/* Pin Locked */
    	MGPIOC->LCKR = (1 << copy_u8Pin);
    	
    	break;
		
	default : break;
    }
}