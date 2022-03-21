/*
 * PWM.h
 *
 *  Created on: Dec 29, 2021
 *      Author: Mohamed Salem
 */

#ifndef PWM_H_
#define PWM_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATUS.h"
#include "STM32F103C8.h"
#include "PWM_Cfg.h"


/* Clock Division */
#define CLK_INT      0
#define CLK_INT_*_2  1
#define CLK_INT_*_4  2
/*****************************************************************************/

/* Center-aligned mode selection */
#define Edge_aligned_mode      0
#define Center_aligned_mode_1  1
#define Center_aligned_mode_2  2
#define Center_aligned_mode_3  3
/****************************************************************************/

/* Direction */
#define upcounter    0
#define downcounter  1
/***************************************************************************/

/* Mode */
#define Mode1  0
#define Mode2  1
/***************************************************************************/

/* Number Of Channel */
#define  PWM_Channel_1  1
#define  PWM_Channel_2  2
#define  PWM_Channel_3  3
#define  PWM_Channel_4  4
/***************************************************************************/

/* Prescaler Value */
#define Prescaler_15   0x003F


// Numeric identifier of a PWM channel.
typedef u32 PWM_ChannelType;
/*********************************************************************/

// Definition of the period of a PWM channel.
typedef u32 PWM_PeriodType;
/*********************************************************************/

// Output state of a PWM channel.
typedef enum OutputStateType
{
	PWM_HIGH = 1,  // The PWM channel is in high state.
	PWM_LOW  = 0   // The PWM channel is in low state.
}PWM_OutputStateType;
/*********************************************************************/

/* This is the type of data structure containing the initialization data for the PWM driver. */
typedef struct ConfigType
{
	PWM_ChannelType Channel;
	PWM_PeriodType  Period;
	u16             Duty_Cycle;
	PWM_OutputStateType Idle_State;
}PWM_ConfigType;
/*********************************************************************/

// Defines the class of a PWM channel.
typedef enum ChannelClassType
{
	PWM_VARIABLE_PERIOD,     /* The PWM channel has a variable period. The duty
                                cycle and the period can be changed. */
	PWM_FIXED_PERIOD,        /* The PWM channel has a fixed period. Only the
                                duty cycle can be changed. */
	PWM_FIXED_PERIOD_SHIFTED /* The PWM channel has a fixed shifted period.
                                Impossible to change it ( only if supported by
                                hardware). */
}Pwm_ChannelClassType;
/*********************************************************************/



/* Definition of the type of edge notification of a PWM channel */
typedef enum EdgeNotificationType
{
	PWM_RISING_EDGE  ,

	PWM_FALLING_EDGE ,

	PWM_BOTH_EDGES

}PWM_EdgeNotificationType;
/*********************************************************************/

/* Service name      : PWM_Init
   Syntax            : void Pwm_Init(const PWM_ConfigType* ConfigPtr).
   Sync/Async        : Synchronous.
   Reentrancy        : Non Reentrant.
   Parameters (in)   : ConfigPtr Pointer to configuration set.
   Parameters(inout) : None.
   Parameters (out)  : None.
   Return value      : None.
   Description       : Service for PWM initialization. */
/*********************************************************************/
void PWM_Init(const PWM_ConfigType* ConfigPtr);

/* Service name      : PWM_SetDutyCycle
   Syntax            : void Pwm_SetDutyCycle(PWM_ChannelType ChannelNumber,u16 DutyCycle).
   Sync/Async        : Synchronous.
   Reentrancy        : Reentrant for different channel numbers.
   Parameters (in)   : ChannelNumber ------> Numeric identifier of the PWM.
                       DutyCycle     ------> Min=0x0000 Max=0x8000.
   Parameters(inout) : None.
   Parameters (out)  : None.
   Return value      : None.
   Description       : Service sets the duty cycle of the PWM channel. */
/****************************************************************************/
void PWM_SetDutyCycle(PWM_ChannelType ChannelNumber,u16 DutyCycle);

/* Service name      : PWM_SetPeriodAndDuty
   Syntax            : void Pwm_SetPeriodAndDuty(PWM_ChannelType ChannelNumber,PWM_PeriodType Period,u16 DutyCycle).
   Sync/Async        : Synchronous.
   Reentrancy        : Reentrant for different channel numbers.
   Parameters (in)   : ChannelNumber ------> Numeric identifier of the PWM.
                       Period        ------> Period of the PWM signal.
                       DutyCycle     ------> Min=0x0000 Max=0x8000.
   Parameters(inout) : None.
   Parameters (out)  : None.
   Return value      : None.
   Description       : Service sets the period and the duty cycle of a PWM channel. */
/**********************************************************************************************/
void PWM_SetPeriodAndDuty(PWM_ChannelType ChannelNumber,PWM_PeriodType Period,u16 DutyCycle);

/* Service name      : PWM_SetOutputToIdle
   Syntax            : void Pwm_SetOutputToIdle(PWM_ChannelType ChannelNumber).
   Sync/Async        : Synchronous.
   Reentrancy        : Reentrant for different channel numbers.
   Parameters (in)   : ChannelNumber ------> Numeric identifier of the PWM.
   Parameters(inout) : None.
   Parameters (out)  : None.
   Return value      : None.
   Description       : Service sets the PWM output to the configured Idle state. */
/**********************************************************************************************/
void PWM_SetOutputToIdle(PWM_ChannelType ChannelNumber);

/* Service name      : Pwm_GetOutputState
   Syntax            : Pwm_OutputStateType Pwm_GetOutputState(PWM_ChannelType ChannelNumber).
   Sync/Async        : Synchronous.
   Reentrancy        : Reentrant for different channel numbers.
   Parameters (in)   : ChannelNumber ------> Numeric identifier of the PWM.
   Parameters(inout) : None.
   Parameters (out)  : Pwm_OutputStateType  -----> PWM_HIGH The PWM output state is high.
                                            -----> PWM_LOW The PWM output state is low.
   Return value      : None.
   Description       : Service to read the internal state of the PWM output signal. */
/**********************************************************************************************/
PWM_OutputStateType PWM_GetOutputState(PWM_ChannelType ChannelNumber);




#endif /* PWM_H_ */
