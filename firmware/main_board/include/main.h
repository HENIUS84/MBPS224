/**
  ******************************************************************************
  * @file     main.h
  * @author   HENIUS (Paweł Witak)
  * @version  1.1.2
  * @date     15/11/2013
  * @brief    Main program (header file)
  ******************************************************************************
  * 
  * <h2><center>COPYRIGHT 2010 HENIUS</center></h2>
  */

#ifndef MAIN_H
#define MAIN_H

/* Include section -----------------------------------------------------------*/

// --->System files
#include <avr/io.h>

/* Macros, constants and definitions section ---------------------------------*/

// --->Constants

// Prescalers support

/*! Prescaler - 1 s */
#define SYS_PRESC_1s		(1000 / SYS_TIME)
/*! Prescaler- 10 ms */
#define SYS_PRESC_10ms		(10 / SYS_TIME)
/*! Prescaler - 5 ms */
#define SYS_PRESC_5ms		(5 / SYS_TIME)
/*! Prescaler - 100 ms */
#define SYS_PRESC_100ms		(100 / SYS_TIME)
/*! Prescaler modules communication */
#define PSM_PRESC			(20 / SYS_TIME)

/* Declaration section -------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
* @brief    Delay function
* @param  	delay : delay in ms
* @retval   None
*/
void Wait_ms(uint16_t delay);

#endif								/* MAIN_H */

/******************* (C) COPYRIGHT 2010 HENIUS *************** END OF FILE ****/
