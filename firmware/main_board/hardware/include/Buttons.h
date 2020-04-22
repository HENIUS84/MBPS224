/**
 *******************************************************************************
 * @file     Buttons.c
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.1
 * @date     04-02-2012
 * @brief    Buttons handler (header file)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2012 HENIUS</center></h2>
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

/* Include section -----------------------------------------------------------*/

// --->System files

#include <avr/io.h>

/* Macros, constants and definitions section ---------------------------------*/

// Button pins

// Button 1
#define KBD1_PORT	   		(PORTE) /*!< Output register of KBD1 */
#define KBD1_DDR       		(DDRE)  /*!< Direction register of KBD1 */
#define KBD1_PIN       		(PINE)  /*!< Input register of KBD1 */
#define KBD1				(_BV(7))/*!< Bit mask of KBD1 */
// Button 2
#define KBD2_PORT	   		(PORTE) /*!< Output register of KBD2 */
#define KBD2_DDR       		(DDRE)  /*!< Direction register of KBD2 */
#define KBD2_PIN       		(PINE)  /*!< Input register of KBD2 */
#define KBD2				(_BV(6))/*!< Bit mask of KBD2 */
// Button 3
#define KBD3_PORT	   		(PORTE) /*!< Output register of KBD3 */
#define KBD3_DDR       		(DDRE)  /*!< Direction register of KBD3 */
#define KBD3_PIN       		(PINE)  /*!< Input register of KBD3 */
#define KBD3				(_BV(5))/*!< Bit mask of KBD3 */
// Button 4
#define KBD4_PORT	   		(PORTE) /*!< Output register of KBD4 */
#define KBD4_DDR       		(DDRE)  /*!< Direction register of KBD4 */
#define KBD4_PIN       		(PINE)  /*!< Input register of KBD4 */
#define KBD4				(_BV(4))/*!< Bit mask of KBD4 */

/* Declaration section -------------------------------------------------------*/		

// --->Functions

/*----------------------------------------------------------------------------*/
/**
 * @brief    Button handler initialization
 * @param    None
 * @retval   None
 */
void Buttons_Init(void);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Buttons handler
 * @param    None
 * @retval   Button mask
 */
uint16_t Buttons_Handler(void);

#endif								/* BUTTONS_H_ */

/******************* (C) COPYRIGHT 2012 HENIUS *************** END OF FILE ****/
