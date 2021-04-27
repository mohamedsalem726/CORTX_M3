/*******************************************************/
/* Auther    : Mohamed Salem                           */
/* Date      : 27 APRIL 2021                           */ 
/* Version   : V01                                     */
/*******************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL include */
#include "STK_interface"
/***********************/

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

/* Array of tasks           "Array of structure" */
static Task OS_Tasks[OS_NUMBER_OF_TASKS] = {NULL};



void Scheduler(void)
{
	for(u8 i = 0 ; i < OS_NUMBER_OF_TASKS ; i++)
	{
		if((OS_Tasks[i].state == TASK_READY) && (OS_Tasks[i].Fptr != NULL))
		{
			if(OS_Tasks[i].InitialDelay == 0)
			{
				OS_Tasks[i].InitialDelay = (OS_Tasks[i].priodicity - 1);
				OS_Tasks[i].Fptr();
			}
			else
			{
				OS_Tasks[i].InitialDelay--;
			}
		}
	}
	
}

void SOS_voidCreateTask(u8 Copy_u8TaskID, u16 Copy_u16Priodicity, u16 Copy_u16InitialDelay, void (*ptr)(void))
{
	OS_Tasks[Copy_u8TaskID].priodicity = Copy_u16Priodicity;
	OS_Tasks[Copy_u8TaskID].Fptr = ptr;
	OS_Tasks[Copy_u8TaskID].State = TASK_READY;
	OS_Tasks[Copy_u8TaskID].InitialDelay = Copy_u16InitialDelay;
}

void SOS_voidStart(void)
{
	/* Initialization */
	MSTK_voidInit();
	/* Tick Each 1msec */
	/* HSE/8 */
	MSTK_voidSetIntervalPeriodic(1,MSTK_MILLIS,Scheduler);
}

void SOS_voidSuspendTask(u8 Copy_u8TaskID)
{
	OS_Tasks[Copy_u8TaskID].State = TASK_SUSPENDED;
}

void SOS_voidResumeTask(u8 Copy_u8TaskID) 
{
	OS_Tasks[Copy_u8TaskID].State = TASK_READY;
}

void SOS_voidDeleteTask(u8 Copy_u8TaskID)
{
	for(u8 i = Copy_u8TaskID ; i < OS_NUMBER_OF_TASKS ; i++)
	{
		OS_Tasks[i] = OS_Tasks[i+1];  
	}
	OS_Tasks[OS_NUMBER_OF_TASKS - 1].Fptr = NULL;
}

u8 SOS_u8GetTaskState(u8 Copy_u8TaskID)
{
	return (OS_Tasks[Copy_u8TaskID].state);
}