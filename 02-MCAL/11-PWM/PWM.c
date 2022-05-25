/*
 * PWM.c
 *
 *  Created on: Dec 29, 2021
 *      Author: Mohamed Salem
 */

#include "../include/PWM.h"

void PWM_Init(const PWM_ConfigType *ConfigPtr)
{


/* Clock Input */
#if PWM_Clock == CLK_INT
	CLR_BIT(TIMER3->CR1, 8);
	CLR_BIT(TIMER3->CR1, 9);
#elif PWM_Clock == CLK_INT_ * _2
	SET_BIT(TIMER3->CR1, 8);
	CLR_BIT(TIMER3->CR1, 9);
#elif PWM_Clock == CLK_INT_ * _4
	CLR_BIT(TIMER3->CR1, 8);
	SET_BIT(TIMER3->CR1, 9);
#endif

	/* Auto-reload preload enable */
	SET_BIT(TIMER3->CR1, 7);

/* Center-aligned mode selection */
#if PWM_Aligned_Mode == Edge_aligned_mode
	CLR_BIT(TIMER3->CR1, 5);
	CLR_BIT(TIMER3->CR1, 6);
#elif PWM_Aligned_Mode == Center_aligned_mode_1
	SET_BIT(TIMER3->CR1, 5);
	CLR_BIT(TIMER3->CR1, 6);
#elif PWM_Aligned_Mode == Center_aligned_mode_2
	CLR_BIT(TIMER3->CR1, 5);
	SET_BIT(TIMER3->CR1, 6);
#elif PWM_Aligned_Mode == Center_aligned_mode_3
	SET_BIT(TIMER3->CR1, 5);
	SET_BET(TIMER3->CR1, 6);
#endif

/* Direction */
#if PWM_Aligned_Mode == Edge_aligned_mode
#if PWM_Counter_Direction == upcounter
	CLR_BIT(TIMER3->CR1, 4);
#elif PWM_Counter_Direction == downcounter
	SET_BIT(TIMER3->CR1, 4);
#endif
#endif

	/* Perload Value */

	TIMER3->ARR = ConfigPtr->Period;

	if (ConfigPtr->Channel == PWM_Channel_1)
	{
/* PWM Mode Selection */
#if PWM_Mode == Mode1
		CLR_BIT(TIMER3->CCMR1, 4);
		SET_BIT(TIMER3->CCMR1, 5);
		SET_BIT(TIMER3->CCMR1, 6);
#elif PWM_Mode == Mode2
		SET_BIT(TIMER3->CCMR1, 4);
		SET_BIT(TIMER3->CCMR1, 5);
		SET_BIT(TIMER3->CCMR1, 6);
#endif

		/* Output Compare 1 Preload Enable */
		SET_BIT(TIMER3->CCMR1, 3);

		/* Output compare 1 fast enable */
		SET_BIT(TIMER3->CCMR1, 2);

		/* Channel Configuration As OutPut */
		CLR_BIT(TIMER3->CCMR1, 0);
		CLR_BIT(TIMER3->CCMR1, 1);

		/* Capture/compare 1 generation */
		SET_BIT(TIMER3->EGR, 1);

		/*  Capture/Compare 1 output enable */
		SET_BIT(TIMER3->CCER, 0);

		if (ConfigPtr->Idle_State == PWM_HIGH)
		{
			CLR_BIT(TIMER3->CCER, 1);
		}
		else if (ConfigPtr->Idle_State == PWM_LOW)
		{
			SET_BIT(TIMER3->CCER, 1);
		}

		/* Duty Cycle */
		TIMER3->CCR1 = ConfigPtr->Duty_Cycle;
	}
	else if (ConfigPtr->Channel == PWM_Channel_2)
	{
/* PWM Mode Selection */
#if PWM_Mode == Mode1
		CLR_BIT(TIMER3->CCMR1, 12);
		SET_BIT(TIMER3->CCMR1, 13);
		SET_BIT(TIMER3->CCMR1, 14);
#elif PWM_Mode == Mode2
		SET_BIT(TIMER3->CCMR1, 12);
		SET_BIT(TIMER3->CCMR1, 13);
		SET_BIT(TIMER3->CCMR1, 14);
#endif

		/* Output Compare 2 Preload Enable */
		SET_BIT(TIMER3->CCMR1, 11);

		/* Output compare 2 fast enable */
		SET_BIT(TIMER3->CCMR1, 10);

		/* Channel Configuration As OutPut */
		CLR_BIT(TIMER3->CCMR1, 8);
		CLR_BIT(TIMER3->CCMR1, 9);

		/* Capture/compare 2 generation */
		SET_BIT(TIMER3->EGR, 2);

		/*  Capture/Compare 2 output enable */
		SET_BIT(TIMER3->CCER, 4);

		if (ConfigPtr->Idle_State == PWM_HIGH)
		{
			CLR_BIT(TIMER3->CCER, 5);
		}
		else if (ConfigPtr->Idle_State == PWM_LOW)
		{
			SET_BIT(TIMER3->CCER, 5);
		}

		/* Duty Cycle */
		TIMER3->CCR2 = ConfigPtr->Duty_Cycle;
	}
	else if (ConfigPtr->Channel == PWM_Channel_3)
	{
/* PWM Mode Selection */
#if PWM_Mode == Mode1
		CLR_BIT(TIMER3->CCMR2, 4);
		SET_BIT(TIMER3->CCMR2, 5);
		SET_BIT(TIMER3->CCMR2, 6);
#elif PWM_Mode == Mode2
		SET_BIT(TIMER3->CCMR2, 4);
		SET_BIT(TIMER3->CCMR2, 5);
		SET_BIT(TIMER3->CCMR2, 6);
#endif

		/* Output Compare 3 Preload Enable */
		SET_BIT(TIMER3->CCMR2, 3);

		/* Output compare 3 fast enable */
		SET_BIT(TIMER3->CCMR2, 2);

		/* Channel Configuration As OutPut */
		CLR_BIT(TIMER3->CCMR2, 0);
		CLR_BIT(TIMER3->CCMR2, 1);

		/* Capture/compare 3 generation */
		SET_BIT(TIMER3->EGR, 3);

		/*  Capture/Compare 3 output enable */
		SET_BIT(TIMER3->CCER, 8);

		if (ConfigPtr->Idle_State == PWM_HIGH)
		{
			CLR_BIT(TIMER3->CCER, 9);
		}
		else if (ConfigPtr->Idle_State == PWM_LOW)
		{
			SET_BIT(TIMER3->CCER, 9);
		}

		/* Duty Cycle */
		TIMER3->CCR3 = ConfigPtr->Duty_Cycle;
	}
	else if (ConfigPtr->Channel == PWM_Channel_4)
	{
/* PWM Mode Selection */
#if PWM_Mode == Mode1
		CLR_BIT(TIMER3->CCMR2, 12);
		SET_BIT(TIMER3->CCMR2, 13);
		SET_BIT(TIMER3->CCMR2, 14);
#elif PWM_Mode == Mode2
		SET_BIT(TIMER3->CCMR2, 12);
		SET_BIT(TIMER3->CCMR2, 13);
		SET_BIT(TIMER3->CCMR2, 14);
#endif

		/* Output Compare 4 Preload Enable */
		SET_BIT(TIMER3->CCMR2, 11);

		/* Output compare 4 fast enable */
		SET_BIT(TIMER3->CCMR2, 10);

		/* Channel Configuration As OutPut */
		CLR_BIT(TIMER3->CCMR2, 8);
		CLR_BIT(TIMER3->CCMR2, 9);

		/* Capture/compare 4 generation */
		SET_BIT(TIMER3->EGR, 4);

		/*  Capture/Compare 4 output enable */
		SET_BIT(TIMER3->CCER, 12);

		if (ConfigPtr->Idle_State == PWM_HIGH)
		{
			CLR_BIT(TIMER3->CCER, 13);
		}
		else if (ConfigPtr->Idle_State == PWM_LOW)
		{
			SET_BIT(TIMER3->CCER, 13);
		}

		/* Duty Cycle */
		TIMER3->CCR4 = ConfigPtr->Duty_Cycle;
	}

	/* Update disable */
	SET_BIT(TIMER3->CR1, 1);

	/* Prescaler Value */
	TIMER3->PSC = Prescaler_Value;

	/* Counter Enable */
	SET_BIT(TIMER3->CR1, 0);
}

void PWM_SetDutyCycle(PWM_ChannelType ChannelNumber, u16 DutyCycle)
{
	/* Check Channel Number */
	switch (ChannelNumber)
	{
	case PWM_Channel_1:
		/* Duty Cycle */
		TIMER3->CCR1 = DutyCycle;
		break;

	case PWM_Channel_2:
		/* Duty Cycle */
		TIMER3->CCR2 = DutyCycle;
		break;

	case PWM_Channel_3:
		/* Duty Cycle */
		TIMER3->CCR3 = DutyCycle;
		break;

	case PWM_Channel_4:
		/* Duty Cycle */
		TIMER3->CCR4 = DutyCycle;
		break;

	default:
		break;
	}
}

void PWM_SetPeriodAndDuty(PWM_ChannelType ChannelNumber, PWM_PeriodType Period, u16 DutyCycle)
{

	/* Perload Value */

	TIMER3->ARR = Period;

	/* Check Channel Number */
	switch (ChannelNumber)
	{
	case PWM_Channel_1:
		/* Duty Cycle */
		TIMER3->CCR1 = DutyCycle;
		break;

	case PWM_Channel_2:
		/* Duty Cycle */
		TIMER3->CCR2 = DutyCycle;
		break;

	case PWM_Channel_3:
		/* Duty Cycle */
		TIMER3->CCR3 = DutyCycle;
		break;

	case PWM_Channel_4:
		/* Duty Cycle */
		TIMER3->CCR4 = DutyCycle;
		break;

	default:
		break;
	}
}

void PWM_SetOutputToIdle(PWM_ChannelType ChannelNumber)
{
	/* Counter Disable */
	CLR_BIT(TIMER3->CR1, 0);

	switch (ChannelNumber)
	{
	case PWM_Channel_1:
		/*  Capture/Compare 1 output Disable */
		SET_BIT(TIMER3->CCER, 0);
		/* Capture/Compare 1 output polarity LOW */
		SET_BIT(TIMER3->CCER, 1);
		break;

	case PWM_Channel_2:
		/*  Capture/Compare 2 output Disable */
		SET_BIT(TIMER3->CCER, 4);
		/* Capture/Compare 2 output polarity LOW */
		SET_BIT(TIMER3->CCER, 5);
		break;

	case PWM_Channel_3:
		/*  Capture/Compare 3 output Disable */
		SET_BIT(TIMER3->CCER, 8);
		/* Capture/Compare 3 output polarity LOW */
		SET_BIT(TIMER3->CCER, 9);
		break;

	case PWM_Channel_4:
		/*  Capture/Compare 4 output Disable */
		SET_BIT(TIMER3->CCER, 12);
		/* Capture/Compare 4 output polarity LOW */
		SET_BIT(TIMER3->CCER, 13);
		break;

	default:
		break;
	}
}

PWM_OutputStateType PWM_GetOutputState(PWM_ChannelType ChannelNumber)
{
	PWM_OutputStateType LOC_State;
	u16 LOC_u16Counter = 0;
	u16 LOC_u16DutyCycle = 0;

	/* Counter Value */
	LOC_u16Counter = TIMER3->CNT;

	switch (ChannelNumber)
	{
	case PWM_Channel_1:
		/* Duty Cycle Value */
		LOC_u16DutyCycle = TIMER3->CCR1;
		break;

	case PWM_Channel_2:
		/* Duty Cycle Value */
		LOC_u16DutyCycle = TIMER3->CCR2;
		break;

	case PWM_Channel_3:
		/* Duty Cycle Value */
		LOC_u16DutyCycle = TIMER3->CCR3;
		break;

	case PWM_Channel_4:
		/* Duty Cycle Value */
		LOC_u16DutyCycle = TIMER3->CCR4;
		break;

	default:
		break;
	}

	if (LOC_u16Counter < LOC_u16DutyCycle)
	{
		LOC_State = PWM_HIGH;
	}
	else
	{
		LOC_State = PWM_LOW;
	}

	return LOC_State;
}

u16 PWM_u16GetDutyCycle(void)
{
	u16 LOC_u16DutyCycle = TIMER3->CCR1;

	return LOC_u16DutyCycle;
}
