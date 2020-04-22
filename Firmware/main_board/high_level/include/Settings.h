/**
 *******************************************************************************
 * @file     Settings.h
 * @author   HENIUS (Pawe³ Witak)
 * @version  1.1.1
 * @date     11-11-2012
 * @brief    Program settings (header file)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2012 HENIUS</center></h2>
 */

#ifndef  SETTINGS_H_
#define  SETTINGS_H_

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdbool.h>

// --->User files

#include "Hardware.h"
#include "Menu.h"

/* Macros, constants and definitions section ---------------------------------*/

// --->Types

/**
 * @brief Program settings
 */
typedef struct
{
	/*! Set voltage in mV */
	uint16_t SetVoltage[PS_MODULES_COUNT];
	/*! Set current in mA */
	uint16_t SetCurrent[PS_MODULES_COUNT];	
	/*! Set PWM values of channels */
	uint16_t SetPWM[PS_MODULES_COUNT];	
	/*! Soft-starts times (in seconds) */
	uint16_t SoftStartTime[PS_MODULES_COUNT];	
	uint8_t LcdBrightness;			/*!< Display backlight */
	Language_t Language;			/*!< Menu language */
	/*! Symmetric mode activation flag */
	bool IsSymModeEnabled;			
	bool AudioMute;					/*!< Sound mute */
	int16_t MaxTemperature;			/*!< Max. temperature of cooling system */	
	int16_t TempHisteresis;			/*!< Temp. hysteresis of cooling system */
	/*! Activation flag of thermal protection system */
	bool IsTempProtectionEnabled;	
}Settings_t;

/* Declaration section -------------------------------------------------------*/

// --->Variables

extern Settings_t Settings;			/*!< Program settings */

// --->Functions

/*----------------------------------------------------------------------------*/
/**
* @brief    Loads the program settings
* @param    None
* @retval   None
*/
void LoadSettings(void);

/*----------------------------------------------------------------------------*/
/**
* @brief    Saves program settings
* @param    None
* @retval   None
*/
void SaveSettings(void);

/*----------------------------------------------------------------------------*/
/**
* @brief    Loads default settings
* @param    None
* @retval   None
*/
void LoadDefaults(void);

#endif								/* SETTINGS_H_ */

/******************* (C) COPYRIGHT 2011 HENIUS *************** END OF FILE ****/
