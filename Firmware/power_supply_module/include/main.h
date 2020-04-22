/**
 *******************************************************************************
 * @file     main.h                                                   
 * @author   HENIUS (Paweł Witak)                                      
 * @version  1.1.1                                                         
 * @date     04-04-2011                                                       
 * @brief    Program of supporting power supply module (header file)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2011 HENIUS</center></h2>
 */

#ifndef MAIN_H_
#define MAIN_H_

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdint.h>

// --->User files

#include "Peripherals.h"

/* Macros, constants and definitions section ---------------------------------*/

// --->Constants

// Prescalers

/*! Prescaler 1 s */
#define SYS_PRESC_1s		(1000 / SYS_TIME)	
/*! Prescaler 10 ms */
#define SYS_PRESC_10ms		(10 / SYS_TIME)
/*! Prescaler of multimeter */
#define MULTIMETER_PRESC	(5 / SYS_TIME)

#define START_DELAY			(1000)			/*!< System start delay (in ms) */

/* Declaration section -------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
* @brief    Delay function
* @param  	delay : delay in ms
* @retval   None
*/
void Wait_ms(uint16_t delay);

#endif 										/* MAIN_H_ */

/******************* (C) COPYRIGHT 2011 HENIUS *************** END OF FILE ****/
