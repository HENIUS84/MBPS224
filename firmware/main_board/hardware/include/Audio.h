/**
 *******************************************************************************
 * @file     Audio.h
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.1
 * @date     30-03-2012
 * @brief    Implementation of sound generator (header file)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2012 HENIUS</center></h2>
 */

#ifndef AUDIO_H_
#define AUDIO_H_

/* Include section -----------------------------------------------------------*/

// --->System files

#include <avr/io.h>
#include <stdbool.h>

/* Macros, constants and definitions section ---------------------------------*/

// Sound output
#define AUDIO_PORT	   		(PORTB) /*!< Out register for AUDIO */
#define AUDIO_DDR       	(DDRB)  /*!< Direction register for AUDIO */
#define AUDIO_PIN       	(PINB)  /*!< Output register for AUDIO */
#define AUDIO				(_BV(5))/*!< Bit mask of AUDIO */

#define FREQ_REGISTER		(OCR1A)	/*!< Frequency register */

// Prescaler
#define AUDIO_PRESC_0		(0)		/*!< No signal for timer */
#define AUDIO_PRESC_1		(1)     /*!< Prescaler /1 */
#define AUDIO_PRESC_8		(2)     /*!< Prescaler /8 */
#define AUDIO_PRESC_64		(3)     /*!< Prescaler /64 */
#define AUDIO_PRESC_256		(4)     /*!< Prescaler /256 */
#define AUDIO_PRESC_1024	(5)     /*!< Prescaler /1024 */
#define AUDIO_PRESC			(64)	/*!< Frequency prescaler */
/*! CS bits value (prescaler) for Audio timer */
#define AUDIO_PRESC_CS		(AUDIO_PRESC_64)

/* Declaration section -------------------------------------------------------*/

// --->Functions

/*----------------------------------------------------------------------------*/
/**
 * @brief    Audio support initialization
 * @param    cpuFreq : CPU frequency in MHz
 * @retval   None
 */
void Audio_Init(uint32_t cpuFreq);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Sets frequency
 * @param    freq : frequency in Hz
 * @retval   None
 */
void Audio_SetFreq(uint16_t freq);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Stops audio
 * @param    None
 * @retval   None
 */
void Audio_StopSound(void);

#endif								/* AUDIO_H_ */

/******************* (C) COPYRIGHT 2012 HENIUS *************** END OF FILE ****/
