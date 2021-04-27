/*******************************************************/
/* Auther    : Mohamed Salem                           */
/* Date      : 25 APRIL 2021                           */ 
/* Version   : V01                                     */
/*******************************************************/

#ifndef _STK_INTERFACE_H
#define _STK_INTERFACE_H

#define MSTK_COUNTFLAG_BIT 			16		/* Returns 1 if timer counted to 0 since last time this was read */
#define MSTK_CLKSOURCE_BIT			2		/* Clock source selection */
#define MSTK_TICKINT_BIT			1		/* STK exception request enable */
#define MSTK_COUNTER_EN_BIT			0		/* Counter enable */
	
#define MSTK_CLKSOURCE_AHB_8		0		/* Selects the clock source as AHB/8 					*/
#define MSTK_CLKSOURCE_AHB			1		/* Selects the clock source as AHB (Processor clock) 	*/
	
#define MSTK_TICKINT_DIS			0		/* Counting down to zero does not assert the STK exception request 	*/
#define MSTK_TICKINT_EN				1		/* Counting down to zero to asserts the STK exception request 		*/
	
#define MSTK_COUNTER_DIS			0		/* Counter disabled */
#define MSTK_COUNTER_EN				1		/* Counter enabled  */
	
#define MSTK_TICKS 					0		
#define MSTK_MILLIS 				1
#define MSTK_MICROS 				2
#define MSTK_SECONDS 			    3
	
#define MSTK_MILLIS_DIVIDER			1000	
#define MSTK_MICROS_DIVIDER			1000000
	
#define MSTK_SINGLE_INTERVAL		0
#define MSTK_PERIODIC_INTERVAL		1



void MSTK_voidInit               ( void                                                           );

void MSTK_voidTICKInterrupt      ( u8 Copy_u8InterruptEnOrDis                                     );
 
void MSTK_voidLoadVal            ( u32 Copy_u32LoadVal                                            );
 
u32 MSTK_u32CurrentVal           ( void                                                           );
 
void MSTK_voidCounterEnDis       ( u8 Copy_u8CounterEnOrDis                                       );

void MSTK_voidSetBusyWait        ( u32 Copy_u32Ticks , u8 Copy_u8ValueType                        );

void MSTK_voidSetIntervalSingle  (u32 Copy_u32Ticks , u8 Copy_u8ValueType , void (*Copy_ptr)(void));

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , u8 Copy_u8ValueType , void (*Copy_ptr)(void));

void MSTK_voidStopInterval       ( void                                                           );
 
u32 MSTK_u32GetElapsedTime       ( u8 Copy_u8ValueType                                            );
 
u32 MSTK_u32GetReminingTime      ( u8 Copy_u8ValueType                                            );


#endif