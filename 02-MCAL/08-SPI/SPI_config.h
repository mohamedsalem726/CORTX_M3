/**********************************************/
/* Auther   : Mohamed Salem                   */
/* Date     : 30 APRIL 2021                   */
/* Version  : V01                             */
/**********************************************/

#ifndef _SPI_CONFIG_H
#define _SPI_CONFIG_H

/* Options :
 *           MSPI_ENABLE
 *           MSPI_DISABLE
                                             */
#define MSPI1_STATUS           MSPI_ENABLE

/* Options :
 *            MSPI_MODE0
 *            MSPI_MODE1
 *            MSPI_MODE2
 *            MSPI_MODE3
                                             */
#define MSPI1_CLOCK_MODE      MSPI_MODE3

/* Options :
 *           MSPI_MASTER
 *           MSPI_SLAVE
                                             */
#define MSPI1_MASTER_SLAVE    MSPI_MASTER

/* Options :
 *           MSPI_MSB_FIRST
 *           MSPI_LSB_FIRST
                                            */
#define MSPI1_DATA_ORDER      MSPI_MSB_FIRST

/* Options :
 *           HW_SLAVE_MANAGEMENT
 *           SW_SLAVE_MANAGEMENT
                                            */
#define MSPI1_SS_MANAGE      HW_SLAVE_MANAGEMENT

/* Options :
 *           MSPI_8BIT_DATA
 *           MSPI_16BIT_DATA
                                            */
#define MSPI1_DATA_SIZE      MSPI_8BIT_DATA

/* Options :
 *           MSPI_INT_DISABLE
 *           MSPI_TXE_INT_ENABLE
 *           MSPI_RXNE_INT_ENABLE
                                            */
#define MSPI1_INT_STATUS     MSPI_INT_DISABLE

/* Options :
 *           MSPI_FPCLK_DIVIDED_BY_2
 *			 MSPI_FPCLK_DIVIDED_BY_4
 *			 MSPI_FPCLK_DIVIDED_BY_8
 *			 MSPI_FPCLK_DIVIDED_BY_16
 *			 MSPI_FPCLK_DIVIDED_BY_32
 *			 MSPI_FPCLK_DIVIDED_BY_64
 *			 MSPI_FPCLK_DIVIDED_BY_128
 *			 MSPI_FPCLK_DIVIDED_BY_265

                                            */
#define MSPI1_PRESCALLER     MSPI_FPCLK_DIVIDED_BY_4

/* Write It In A Pair Port,Pin */
#define MSPI_SLAVE_PIN    GPIOA,0



#endif
