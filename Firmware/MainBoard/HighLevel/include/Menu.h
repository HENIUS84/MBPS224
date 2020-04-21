/**
 *******************************************************************************
 * @file     Menu.h
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.2
 * @date     03-05-2013
 * @brief    Menu implementation (header file)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

#ifndef MENU_H_
#define MENU_H_

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// --->User files

#include "Hardware.h"

/* Macros, constants and definitions section ---------------------------------*/

// --->Constants

#define LCD_OFF_TIMEOUT		(6000)	/*!< LCD off timeout */
#define CURSOR_TIME			(50)	/*!< Period of blinking edition cursor
                                         (depends on button handler interval) */
#define LOW_VOLTAGE			600		/*!< Low voltage limit */
#define HIGH_VOLTAGE		24000	/*!< High voltage limit */
#define LOW_VOLTAGE_PWM		0		/*!< Low voltage PWM limit */
#define HIGH_VOLTAGE_PWM	1023	/*!< High voltage PWM limit */
#define LOW_CURRENT			(1)		/*!< Low current limit */
#define HIGH_CURRENT		(1000)	/*!< High current limit */
#define DISP_BACKL_MIN		(10)	/*!< Min. LCD backlight level*/
#define DISP_BACKL_MAX      (100)	/*!< Max. LCD backlight level */
#define DISP_BACKL_STEPS	(11)    /*!< Steps of backlight setting */
/* Backlight step size (max. 10 levels) */
#define DISP_BACKL_STEP		((DISP_BACKL_MAX - DISP_BACKL_MIN) / \
                             (DISP_BACKL_STEPS - 1))							 
#define SOFT_START_TIME_MIN	(0)		/*!< Min. time of soft-start (in sec.) */
#define SOFT_START_TIME_MAX	(60)	/*!< Max. time of soft-start (in sec.) */
#define MAX_TEMP_MAX		(800)	/*!< Max. value of max. temperature */
#define MAX_TEMP_MIN		(200)	/*!< Min. value of max. temperature */
#define TEMP_HISTERESIS_MAX	(100)	/*!< Max. value of temperature hysteresis */
#define TEMP_HISTERESIS_MIN	(10)	/*!< Min. value of temperature hysteresis */

// --->Macros

// Keys tones

#define KEY_BEEP()			Beep(500, 100)	/*!< Default key beep */
#define WRONG_BEEP()		Beep(250, 100)	/*!< Wrong operation beep */
#define EDITION_BEEP()		Beep(650, 300)	/*!< Edition enabled beep */
#define OVERLOAD_BEEP()		Beep(1000, -1)	/*!< Overload beep */

/*! Getting screen number */
#define AMOUNT_OF_SCREENS(x)	(sizeof(x) / sizeof(Screen_t))

// --->Types

/**
 * @brief Captions indexes
 */
typedef enum
{
    CI_CHANNEL1_LABEL,				/*!< Canal #1 label */
    CI_CHANNEL2_LABEL,				/*!< Canal #2 label  */
    CI_SET_VALUES,					/*!< Set values */
    CI_LEFT_NAVIGATOR,				/*!< Left navigator */
    CI_RIGHT_NAVIGATOR,				/*!< Right navigator */
    CI_RIGHTS,						/*!< Copyrights information */
    CI_FW_VERSION,					/*!< Firmware version */
    CI_FLOAT_VALUE_1,				/*!< Float value 1 */
    CI_VOLTAGE_UNIT,				/*!< Voltage unit */
    CI_LOW_RESISTANCE_UNIT,			/*!< Unit of low resistance */
    CI_LOW_POWER_UNIT,				/*!< Unit of low power */
    CI_TEMPERATURE_UNIT,			/*!< Temperature unit */
    CI_CURRENT_UNIT,				/*!< Current unit */
    CI_INT_VALUE,					/*!< Integer value */
    CI_TEMPERATURES,				/*!< Temperatures caption */
    CI_MEASURED_VALUES,				/*!< Measured values */
    CI_POWER_RESISTANCE,			/*!< Label of power/resistance */
    CI_HIGH_POWER_UNIT,				/*!< Unit of high power */
    CI_MED_RESISTANCE_UNIT,			/*!< Unit of medium resistance */
    CI_HI_RESISTANCE_UNIT,			/*!< Unit of high resistance */
    CI_MB_TEMP_LABEL,				/*!< Label of main board temperature */
    CI_INFINITY_SYMBOL,				/*!< Infinity symbol */
    CI_SETTINGS,                    /*!< Settings label */
    CI_SOUND,						/*!< Sound settings label */
    CI_DISPLAY, 					/*!< Display settings label */
    CI_LANGUAGE,					/*!< Language settings label */
    CI_MENU_LANGUAGE,				/*!< Language settings label */
    CI_SET_PWM,						/*!< PWMsettings label */
    CI_ADC_VALUES,					/*!< ADC measurements data */
    CI_VOLTAGE_PWM_UNIT,			/*!< Unit of PWM voltage */
    CI_CURRENT_PWM_UNIT,			/*!< Unit of PWM current */	
	CI_SOUND_OFF,					/*!< Info about sound off */
    CI_SOUND_ON,					/*!< Info about sound on */
    CI_FLOAT_VALUE_2,				/*!< Float value 2 */
    CI_FLOAT_VALUE_3,				/*!< Float value 3 */
    CI_OVERCURRENT,					/*!< Sign of overcurrent */
    CI_GENERAL_SETTINGS,			/*!< General settings label */
    CI_PS_SETTINGS,					/*!< Power supply settings label */	
    CI_GENERAL_SETTINGS_LABEL,		/*!< Label of general settings in top bar */
    CI_SOFT_START_1,				/*!< Canal #1 soft-start settings label */			
    CI_SOFT_START_2,				/*!< Canal #2 soft-start settings label */		
	/*! Label of power supply settings in top bar */
    CI_PS_SETTINGS_LABEL,			
    CI_SOFT_START_UNIT,				/*!< Time unit of soft-start */
    CI_ABOUT,						/*!< About screen */
    CI_COMMUNICATION,				/*!< Communication */
    CI_DATA_RATE,					/*!< Data speed */
    CI_MESSAGE_SIZE,				/*!< Message size */
    CI_RX_DATA,						/*!< RX data information */
    CI_TX_DATA,						/*!< TX data information */
    CI_FIRMWARE, 	                /*!< Firmware versions */	
	CI_FIRMWARE1, 					/*!< Firmware version of module #1 */
	CI_FIRMWARE2,					/*!< Firmware version of module #2 */
    CI_MB_VERSION,					/*!< Firmware version of main board */	
	CI_PSM_VERSION,					/*!< Information about PS module version */
    CI_FULL_BUILD_DATE,				/*!< Build data (full version) */
	CI_SHORT_BUILD_DATE,			/*!< Build data (short version) */
	CI_MAX_TEMP,					/*!< Label of max. temp. settings */
	CI_TEMP_HYSTERESIS,				/*!< Label of temp. hysteresis settings */
	CI_TEMP_PROTECTION,				/*!< Label of temp. protection settings */
	/*! Information about temp. protection activation */
	CI_TEMP_PROTECTION_ON,			
	/*! Information about temp. protection deactivation */
	CI_TEMP_PROTECTION_OFF,			
}ECaptionIndex_t;

/**
 * @brief Menu screens
 */
typedef enum
{
    MS_START,						/*!< Initial state */
    MS_SET_VALUES,					/*!< View of set voltage and current */
    MS_SCREEN_SET_VALUES,			/*!< View of name of set values screen */
    MS_TEMPERATURES,				/*!< View of temperatures */
    MS_SCREEN_TEMPERATURES,			/*!< View of name of temperature screen */    
    MS_SCREEN_MEASURED_VALUES,		/*!< View of name of measured values screen */
    MS_SCREEN_POWER_RESISTANCE,		/*!< View of name of power/resistance screen */
    MS_MEASURED_VALUES,				/*!< View of measured voltage and current */
    MS_POWER_RESISTANCE,			/*!< View of power/resistance */
    MS_SCREEN_SETTINGS,				/*!< View of name of settings screen */
    MS_SETTINGS,					/*!< View of program settings */
    MS_SCREEN_SOUND,				/*!< View of name of sound settings screen */
    MS_SOUND_SETTINGS,				/*!< View of sound settings */
    MS_SCREEN_DISPLAY,				/*!< View of name of display settings screen */
    MS_DISPLAY_SETTINGS,			/*!< View of display settings */
    MS_SCREEN_LANGUAGE,				/*!< View of name of language screen */
    MS_LANGUAGE_SETTINGS,			/*!< View of language settings */
	/*! View of name of voltage PWM set values screen */
    MS_SCREEN_SET_PWM,				
    MS_SET_PWM,						/*!< View of voltage PWM set values */
    MS_SCREEN_ADC_VALUES,			/*!< View of name of ADC values screen */
    MS_ADC_VALUES,					/*!< View of measured ADC values */
    MS_SCREEN_GENERAL_SETTINGS,		/*!< View of name of general settings screen */
    MS_GENERAL_SETTINGS,			/*!< View of general settings */
    MS_SCREEN_PS_SETTINGS,			/*!< View of name of PS module settings screen */
    MS_PS_SETTINGS,					/*!< View of PS settings */
	/*! View of name of channel #1 Soft-Start settings screen */
    MS_SCREEN_SS1_SETTINGS,		
	/*! View of channel #1 Soft-Start settings */
    MS_SS1_SETTINGS,		
	/*! View of name of channel #2 Soft-Start settings screen */
    MS_SCREEN_SS2,	
	/*! View of channel #2 Soft-Start settings */				
    MS_SS2_SETTINGS,
    MS_SCREEN_ABOUT,				/*!< View of name of about screen */	
    MS_ABOUT,						/*!< View of about screen */
	/*! View of name of communication info screen */
    MS_SCREEN_COMMUNICATION,		
    MS_COMMUNICATION,				/*!< View of communication screen */
	/*! View of name of firmware version screen */			
    MS_SCREEN_FIRMWARE,
    MS_FIRMWARE,					/*!< View of firmware version screen */
	/*! View of name of max. temp settings screen */	                
	MS_SCREEN_MAX_TEMP,						
	MS_MAX_TEMP_SETTINGS,			/*!< View of max. temp settings screen */
	/*! View of name of temp. hysteresis settings screen */
	MS_SCREEN_TEMP_HYSTERESIS,				
	MS_TEMP_HYSTERESIS_SETTINGS,	/*!< View temp. hysteresis settings screen */
	/*! View of name of temp. protection settings screen */
	MS_SCREEN_TEMP_PROTECTION,		
	/*! View of temp. protection settings screen */
	MS_TEMP_PROTECTION_SETTINGS,
	/*! View of name of module #1 firmware version screen */
	MS_SCREEN_FIRMWARE1,
	/*! View of module #1 firmware version screen */
	MS_FIRMWARE1,	
	/*! View of name of module #2 firmware version screen */
	MS_SCREEN_FIRMWARE2,
	/*! View of module #2 firmware version screen */
	MS_FIRMWARE2
}EMenuScreen_t;

/**
 * @brief Object which integrates screen and its description
 */
typedef struct
{
    EMenuScreen_t Type;				/*!< Screen type */
    ECaptionIndex_t Name;			/*!< Index of screen name */	
    bool AdvancedMode;				/*!< Flag for advanced mode */	
} Screen_t;

/**
 * @brief States of menu buttons
 */
typedef enum
{
    MKS_SCREEN_NAME,				/*!< Change of screen name */
    MKS_VALUE_EDITION,				/*!< Value edition */	
    MKS_OVERCURRENT					/*!< Exit from overcurrent state */
} MenuKeyState_t;

/**
 * @brief Menu languages
 */
typedef enum
{
    L_ENGLISH,						/*!< English*/
    L_POLISH,						/*!< Polish */
    NUMBER_OF_LANGUAGES				/*!< Number of languages */
} Language_t;

/* Declaration section -------------------------------------------------------*/

// --->Variables

extern bool IsAdvancedMode;			/*!< Advanced mode */

// --->Functions

/*----------------------------------------------------------------------------*/
/**
 * @brief    Shows splash screen.
 * @param    None
 * @retval   None
 */
void ShowSplashScreen(void);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Buttons handler menu
 * @param    None
 * @retval   None
 */
void MenuHandler(void);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Menu screen handler
 * @param    None
 * @retval   None
 */
void MenuKeysHandler(void);

#endif								/* MENU_H_ */

/******************* (C) COPYRIGHT 2013 HENIUS *************** END OF FILE ****/
