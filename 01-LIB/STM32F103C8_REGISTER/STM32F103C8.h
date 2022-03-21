/*****************************************************************/
/****************** Name    : Karim Seif 	**********************/
/****************** Date    : 7/5/2021  	**********************/
/****************** Version : 1.0V       	**********************/
/****************** SWC     : stm32f10xx.h  **********************/
/*****************************************************************/
#ifndef STM32F103C8_H
#define STM32F103C8_H

/************************************ RCC Registers ******************************************/

#define RCC_u32_BASE_ADDRESS 0x40021000

typedef struct
{
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
} RCC_RegDef_t;

#define RCC ((RCC_RegDef_t *)0x40021000)

/*********************************************************************************************/

/************************************* GPIO Registers ****************************************/

#define GPIO_u32_GPIOA_BASE_ADDRESS 0x40010800
#define GPIO_u32_GPIOB_BASE_ADDRESS 0x40010C00
#define GPIO_u32_GPIOC_BASE_ADDRESS 0x40011000

typedef struct
{
	volatile u32 CRL;
	volatile u32 CRH;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 BRR;
	volatile u32 LCKR;
} GPIO_RegDef_t;

#define GPIOA ((GPIO_RegDef_t *)GPIO_u32_GPIOA_BASE_ADDRESS)
#define GPIOB ((GPIO_RegDef_t *)GPIO_u32_GPIOB_BASE_ADDRESS)
#define GPIOC ((GPIO_RegDef_t *)GPIO_u32_GPIOC_BASE_ADDRESS)

/*********************************************************************************************/

/************************************ NVIC Registers *****************************************/

#define NVIC_u32_BASE_ADDRESS 0xE000E100

typedef struct
{
	volatile u32 ISER[8];
	volatile u32 Reserved1[24];
	volatile u32 ICER[8];
	volatile u32 Reserved2[24];
	volatile u32 ISPR[8];
	volatile u32 Reserved3[24];
	volatile u32 ICPR[8];
	volatile u32 Reserved4[24];
	volatile u32 IABR[8];
	volatile u32 Reserved5[56];
	volatile u8 IPR[240];
} NVIC_RegDef_t;

#define NVIC ((NVIC_RegDef_t *)NVIC_u32_BASE_ADDRESS)

/*********************************************************************************************/

/*********************************** EXTI Registers ******************************************/

#define EXTI_u32_BASE_ADDRESS 0x40010400

typedef struct
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
} EXTI_RegDef_t;

#define EXTI ((EXTI_RegDef_t *)EXTI_u32_BASE_ADDRESS)

/*********************************************************************************************/

/********************************** AF Registers *********************************************/

#define AF_u32_BASE_ADDRESS 0x40010000

typedef struct
{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 MAPR2;
} AF_RegDef_t;

#define AF ((AF_RegDef_t *)AF_u32_BASE_ADDRESS)

/*********************************************************************************************/

/*********************************** SYSTICK Registers ***************************************/

#define STK_u32_BASE_ADDRESS 0xE000E010

typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
} STK_RegDef_t;

#define STK ((STK_RegDef_t *)STK_u32_BASE_ADDRESS)

/*********************************************************************************************/

/********************************** SPI1 Registers *******************************************/

#define SPI1_u32_BASE_ADDRESS 0x40013000

typedef struct
{
	u32 CR1;
	u32 CR2;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR;
} SPI1_RegDef_t;

#define SPI1 ((SPI1_RegDef_t *)SPI1_u32_BASE_ADDRESS)

/*
 * I2C peripheral register definition structure
 */
typedef struct
{
	u32 CR1;
	u32 CR2;
	u32 OAR1;
	u32 OAR2;
	u32 DR;
	u32 SR1;
	u32 SR2;
	u32 CCR;
	u32 TRISE;
} I2C_RegDef_t;

/*
 * I2Cx base addresses macros
 */
#define I2C1_BASE_ADDRESS 0x40005400
#define I2C2_BASE_ADDRESS 0x40005800

/*
 * I2Cx peripheral definition macros
 */
#define I2C1_BASE ((I2C_RegDef_t *)I2C1_BASE_ADDRESS)
#define I2C2_BASE ((I2C_RegDef_t *)I2C2_BASE_ADDRESS)

typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
} UART_RegDef_t;

/*
 * UARTx peripheral definition macros
 */
#define USART1_BASE_ADDRESS 0x40000000


#define MUSART1 ((volatile UART_RegDef_t *)USART1_BASE_ADDRESS)
/*********************************************************************************************/

/*
 * TIMERx peripheral register definition structure
 */
typedef struct{
	
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
    volatile u32 CCMR2;
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;	
	volatile u32 ARR;
	volatile u32 RESERVED;
    volatile u32 CCR1;
	volatile u32 CCR2;
	volatile u32 CCR3;
	volatile u32 CCR4;
	volatile u32 RESERVED;
	volatile u32 DCR;
	volatile u32 DMAR;
}TIMER_RegDef_t;

/*
 * TIMERx peripheral definition macros
 */
#define TIMER2_BASE_ADDRESS 0x40000000
#define TIMER3_BASE_ADDRESS 0x40000400
#define TIMER4_BASE_ADDRESS 0x40000800
#define TIMER5_BASE_ADDRESS 0x40000C00

#define TIMER2  ((volatile TIMER_RegDef_t*)TIMER1_BASE_ADDRESS)

#define TIMER3  ((volatile TIMER_RegDef_t*)TIMER2_BASE_ADDRESS)

#define TIMER4  ((volatile TIMER_RegDef_t*)TIMER3_BASE_ADDRESS)

#define TIMER5  ((volatile TIMER_RegDef_t*)TIMER4_BASE_ADDRESS)

#endif
