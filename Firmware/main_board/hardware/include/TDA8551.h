/**
 *******************************************************************************
 * @file     TDA8551.h
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.1
 * @date     30-03-2012
 * @brief    Driver of audio amplifier TDA8551 (header file)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2012 HENIUS</center></h2>
 */

#ifndef TDA8551_H_
#define TDA8551_H_

/* Include section -----------------------------------------------------------*/

// --->System files

#include <avr/io.h>
#include <stdbool.h>

/* Macros, constants and definitions section ---------------------------------*/

// Pins

// Volume pin
#define VOLUME_PORT	   		(PORTA) /*!< Output register of VOLUME pin */
#define VOLUME_DDR       	(DDRA)  /*!< Direction register of VOLUME pin */
#define VOLUME_PIN       	(PINA)  /*!< Input register of VOLUME pin */
#define VOLUME				(_BV(3))/*!< Bit mask of VOLUME pin */

// Work mode pin
#define AUDIO_MODE_PORT	   	(PORTA) /*!< Output register of AUDIO_MODE pin */
#define AUDIO_MODE_DDR      (DDRA)  /*!< Direction register of AUDIO_MODE pin */
#define AUDIO_MODE_PIN      (PINA)  /*!< Input register of AUDIO_MODE pin */
#define AUDIO_MODE			(_BV(4))/*!< Bit mask of AUDIO_MODE pin */

// Macros

// Pin VOLUME
/*! HIZ state */
#define VOLUME_HIZ()		VOLUME_DDR &= ~VOLUME;  VOLUME_PORT &= ~VOLUME
/*! High state */
#define VOLUME_HIGH()		VOLUME_DDR |= VOLUME;  VOLUME_PORT |= VOLUME
/*! Low state */
#define VOLUME_LOW()		VOLUME_DDR |= VOLUME;  VOLUME_PORT &=  ~VOLUME
							 
// AUDIO_MODE pin
/*! HIZ state */
#define AUDIO_MODE_HIZ()	AUDIO_MODE_DDR &= ~AUDIO_MODE; \
                            AUDIO_MODE_PORT &= ~AUDIO_MODE
/*! High state */
#define AUDIO_MODE_HIGH()	AUDIO_MODE_DDR |= AUDIO_MODE;  \
                            AUDIO_MODE_PORT |= AUDIO_MODE
/*! Low state */
#define AUDIO_MODE_LOW()	AUDIO_MODE_DDR |= AUDIO_MODE; \
                            AUDIO_MODE_PORT &=  ~AUDIO_MODE
/*! MUTE mode */
#define TDA8551_MUTE()		AUDIO_MODE_HIZ()
/*! STANDBY mode */
#define TDA8551_STANDBY()	AUDIO_MODE_HIGH()
/*! OPERATING mode */
#define TDA8551_OPERATING()	AUDIO_MODE_LOW()
							 
// Constants
#define TDA8551_STEPS_COUNT	(64)	/*!< Volume regulation steps */
#define TDA8551_DEF_VOLUME	(6)		/*!< Default volume level in w % */

/* Declaration section -------------------------------------------------------*/

// --->Functions

/*----------------------------------------------------------------------------*/
/**
 * @brief    Initializes drive of audio amplifier
 * @param    None
 * @retval   None
 */
void TDA8551_Init(void);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Sets the volume
 * @param    volume : volume level
 * @retval   None
 */
void TDA8551_SetVolume(uint8_t volume);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Gets the current volume level
 * @param    None
 * @retval   Current volume level
 */
uint8_t TDA8551_GetVolume(void);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Increasing/decreasing volume level
 * @param    isUp : true - increasing, otherwise false
 * @retval   None
 */
void TDA8551_VolumeUpDown(bool isUp);

#endif								/* TDA8551_H_ */

/******************* (C) COPYRIGHT 2012 HENIUS *************** END OF FILE ****/
