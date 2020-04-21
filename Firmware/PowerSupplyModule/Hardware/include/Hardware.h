/**
 *******************************************************************************
 * @file     PSMHardware.h
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.1
 * @date     19/11/2010
 * @brief    Functions of PS module hardware (header file)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2010 HENIUS</center></h2>
 */

#ifndef  HARDWARE_H
#define  HARDWARE_H

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdint.h>
#include <stdio.h>

// --->User files

#include "MBController.h"
#include "Multimeter.h"
#include "Regulator.h"
#include "OWIThermometer.h"

/* Macros, constants and definitions section ---------------------------------*/

#define PSM_ID_BASE			(0x10)	/*!< Base hardware address of module */

// Dipswitch
#define DIPSW_PORT	   		(PORTB) /*!< Output register of dipswitch */
#define DIPSW_DDR       	(DDRB)  /*!< Direction register of dipswitch */
#define DIPSW_PIN       	(PINB)  /*!< Input register of dipswitch */
#define DIPSW1 				(_BV(1))/*!< Mask of DIPS1 */
#define DIPSW2 				(_BV(2))/*!< Mask of DIPS2 */
#define DIPSW3 				(_BV(3))/*!< Mask of DIPS3 */
/*! Macro to get pin state of dipswitch */
#define GET_DIPSW(number)	(!(DIPSW_PIN & number))
/*! Macro to get module address selected in dipswitch */
#define GET_MODULE_ADDR()	(GET_DIPSW(DIPSW2) ? 1 : 0)

// Status LED
#define STAT_LED_PORT	   	(PORTC) /*!< Output register of status LED */
#define STAT_LED_DDR       	(DDRC)  /*!< Direction register of status LED */
#define STAT_LED_PIN       	(PINC)  /*!< Input register of status LED */
#define STAT_LED 	        (_BV(6))/*!< Bit mask of status LED */
/*! Macro activating status LED */
#define STAT_LED_ON()		(STAT_LED_PORT &= ~STAT_LED)
/*! Macro deactivating status LED */
#define STAT_LED_OFF()		(STAT_LED_PORT |= STAT_LED)
/*! Macro toggling status LED */
#define STAT_LED_TOGGLE()	(STAT_LED_PORT ^= STAT_LED)
#define STAT_LED_ON_TIME	(100)	/*!< On time of status LED in ms */
#define STAT_LED_OFF_TIME	(600)	/*!< Off time of status LED in ms */

// Buzzer
#define BUZZER_PORT			(PORTB)	/*!< Output register of buzzer */
#define BUZZER_DDR			(DDRB)	/*!< Direction register of buzzer */
#define BUZZER_PIN			(PINB)	/*!< Input register of buzzer */
#define BUZZER				(_BV(0))/*!< Bit mask of buzzer */
/*! Macro activating buzzer */
#define BUZZER_ON()			(BUZZER_PORT &= ~BUZZER)
/*! Macro deactivating buzzer */
#define BUZZER_OFF()		(BUZZER_PORT |= BUZZER)
/*! Macro toggling buzzer */
#define BUZZER_TOGGLE()		(BUZZER_PORT ^= BUZZER)

// System timer
// Prescaler
#define TIMS_PRESC_0		(0)		/*!< No timer signal */
#define TIMS_PRESC_1		(1)     /*!< Prescaler /1 */
#define TIMS_PRESC_8		(2)     /*!< Prescaler /8 */
#define TIMS_PRESC_64		(3)     /*!< Prescaler /64 */
#define TIMS_PRESC_256		(4)     /*!< Prescaler /256 */
#define TIMS_PRESC_1024		(5)     /*!< Prescaler /1024 */

/*! System timer prescaler */
#define SYS_TIMER_PRESC		(256)
/*! CS bits value (prescaler) of system timer */
#define SYS_TIMER_CS	    (TIMS_PRESC_256)
/*! Calculating of OCR register for time support */
#define SET_SYS_TIME()     	(F_CPU / SYS_TIMER_PRESC * SYS_TIME / 1000 - 1)

// Timer for delay functionality support
// Prescaler
#define TIMD_PRESC_0		(0)		/*!< No timer signal */
#define TIMD_PRESC_1		(1)     /*!< Prescaler /1 */
#define TIMD_PRESC_8		(2)     /*!< Prescaler /8 */
#define TIMD_PRESC_32		(3)     /*!< Prescaler /32 */
#define TIMD_PRESC_64		(4)     /*!< Prescaler /64 */
#define TIMD_PRESC_128		(5)     /*!< Prescaler /128 */
#define TIMD_PRESC_256		(6)     /*!< Prescaler /256*/
#define TIMD_PRESC_1024		(7)     /*!< Prescaler /1024 */

/*! Interrupt time of delay timer in ms */
#define DEL_TIME			(1)
/*! Prescaler of delay timer */
#define DEL_TIMER_PRESC		(256)
/*! CS bits value (prescaler) of delay timer */
#define DEL_TIMER_CS	    (TIMD_PRESC_256)
/*! Calculation of OCR register value for time support*/
#define SET_DEL_TIME()     	(F_CPU / DEL_TIMER_PRESC * DEL_TIME / 1000 - 1)

// Multimeter
#define CURRENT_AMP_LOW		(1)		/*!< Low current amplification */
#define CURRENT_AMP_HIGH	(2)		/*!< High current amplification */

/* Declaration section -------------------------------------------------------*/

// --->Functions

/*----------------------------------------------------------------------------*/
/**
 * @brief    Initializes the hardware of PS module
 * @param    None
 * @retval   None
 */
void InitHardware(void);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Status LED blinking handler
 * @param    None
 * @retval   None
 */
void StatLedHandler();

/*----------------------------------------------------------------------------*/
/**
 * @brief    Function setting blinking times for status LED
 * @param    onTime: time when the LED is on (in ms)
 * @param    offTime: time when the LED is off (in ms)
 * @retval   None
 */
void SetStatLedBlinking(uint16_t onTime, uint16_t offTime);   

#endif								/* HARDWARE_H */

/******************* (C) COPYRIGHT 2010 HENIUS *************** END OF FILE ****/
