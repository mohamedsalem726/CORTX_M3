/*******************************************************/
/* Auther    : Mohamed Salem                           */
/* Date      : 27 APRIL 2021                           */ 
/* Version   : V01                                     */
/*******************************************************/

#ifndef _OS_INTERFACE_H
#define _OS_INTERFACE_H

#define TASK_READY				1			/* Macro representing Task state: Ready */
#define TASK_SUSPENDED			0			/* Macro representing Task state: Suspended */

/* SOS_voidCreatTask --> Create a new task 																						*/
/* I/P: - Cpy_u8TaskID: * ID of the task (Represents its index in the array of structs: OS_Tasks)
 * 						* Type: u8
 * 		- Cpy_u16Periodicity: 	* Periodicity of the task (Represents how frequent will the task happen [Represented by number of ticks])
 * 								* Type: u16
 * 		- Cpy_u16InitialDelay: 	* InitialDelay of the task
 * 								* Type: u16
 * 		- ptr: 	* Address of the function of the task (The function that would be Called when the task occurs)
 * 				* Type: Pointer to function (Return type: void & Argument: void)
 *
* O/P: void                                                                                                                      */
void SOS_voidCreateTask(u8 Copy_u8TaskID, u16 Copy_u16Priodicity, void (*ptr)(void));
/*******************************************************************************************************************************************/

/* SOS_voidStart --> Initializes STK and Calls the Scheduler function periodically every tick 	*/
/* I/P: void																					*/
/* O/P: void                                                                                    */
void SOS_voidStart(void);
/*******************************************************************************************************************************************/

/* SOS_voidSuspendTask --> Suspends a task														*/
/*I/P: Cpy_u8TaskID: * ID of the task (Represents its index in the array of structs: OS_Tasks)
 * 					 * Type: u8
 *
 *O/P: void	                                                                                    */
void SOS_voidSuspendTask(u8 Copy_u8TaskID);
/*******************************************************************************************************************************************/

/* SOS_voidResumeTask --> Resumes a task														*/
/*I/P: Cpy_u8TaskID: * ID of the task (Represents its index in the array of structs: OS_Tasks)
 * 					 * Type: u8
 *
 *O/P: void	                                                                                    */
void SOS_voidResumeTask(u8 Copy_u8TaskID);
/********************************************************************************************************************************************/

/* SOS_voidDeleteTask --> Deletes a task														*/
/*I/P: Cpy_u8TaskID: * ID of the task (Represents its index in the array of structs: OS_Tasks)
 * 					 * Type: u8
 *
 *O/P: void	                                                                                    */
void SOS_voidDeleteTask(u8 Copy_u8TaskID);
/********************************************************************************************************************************************/

/* SOS_u8GetTaskState --> Gets State of a task													*/
/*I/P: Cpy_u8TaskID: * ID of the task (Represents its index in the array of structs: OS_Tasks)
 * 					 * Type: u8
 *
/* O/P: State of a task (Return type u8)                                                        */
u8 SOS_u8GetTaskState(u8 Copy_u8TaskID);
/********************************************************************************************************************************************/

#endif