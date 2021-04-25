/*****************************************************/
/* Auther    : Mohamed Salem                         */
/* Date      : 12 FEB 2021                           */ 
/* Version   : V01                                   */
/*****************************************************/
#ifndef _GPIO_PRIVAT_H
#define _GPIO_PRIVAT_H


typedef struct{
	volatile u32 CRL  ;//0x00
	volatile u32 CRH  ;//0x04
    volatile u32 IDR  ;//0x08
    volatile u32 ODR  ;//0x0C
    volatile u32 BSRR ;//0x10
    volatile u32 BRR  ;//0x14
    volatile u32 LCKR ;//0x18
}GPIO;

#define MGPIOA ((volatile GPIO*)0x40010800) 	 
#define MGPIOB ((volatile GPIO*)0x40010C00)
#define MGPIOC ((volatile GPIO*)0x40011000)


//
///* Port A Registers Address */
//#define GPIOA_CRL  *((u32*)0x40010800)
//#define GPIOA_CRH  *((u32*)0x40010804)
//#define GPIOA_IDR  *((u32*)0x40010808)
//#define GPIOA_ODR  *((u32*)0x4001080C)
//#define GPIOA_BSRR *((u32*)0x40010810)
//#define GPIOA_BRR  *((u32*)0x40010814)
//#define GPIOA_LCKR *((u32*)0x40010818)
//
///* Port B Registers Address */
//#define GPIOB_CRL  *((u32*)0x40010C00)
//#define GPIOB_CRH  *((u32*)0x40010C04)
//#define GPIOB_IDR  *((u32*)0x40010C08) 
//#define GPIOB_ODR  *((u32*)0x40010C0C)
//#define GPIOB_BSRR *((u32*)0x40010C10)
//#define GPIOB_BRR  *((u32*)0x40010C14)
//#define GPIOB_LCKR *((u32*)0x40010C18)
//
///* Port C Registers Address */
//#define GPIOC_CRL  *((u32*)0x40011000)
//#define GPIOC_CRH  *((u32*)0x40011004)
//#define GPIOC_IDR  *((u32*)0x40011008)
//#define GPIOC_ODR  *((u32*)0x4001100C)
//#define GPIOC_BSRR *((u32*)0x40011010)
//#define GPIOC_BRR  *((u32*)0x40011014)
//#define GPIOC_LCKR *((u32*)0x40011018)
//


#endif