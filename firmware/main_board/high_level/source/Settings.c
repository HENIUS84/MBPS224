/**
 *******************************************************************************
 * @file     Settings.c
 * @author   HENIUS (Pawe³ Witak)
 * @version  1.1.1
 * @date     12-11-2012
 * @brief    Program settings
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2012 HENIUS</center></h2>
 */

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdint.h>
#include <avr/io.h>
#include <string.h>

// --->User files

#include "Settings.h"
#include "TDA8551.h"
#include "SettingsController.h"
#include "Peripherals.h"

/* Variable section ----------------------------------------------------------*/

Settings_t Settings;
/*! Default settings */
static Settings_t DefaultSettings = {
	.SetVoltage              = { 1000, 1000 },
	.SetCurrent              = { 1000, 1000 },
	.Language                = L_ENGLISH,
	.IsSymModeEnabled        = false,
	.AudioMute               = false,
	.SoftStartTime           = { 0, 0 },
	.LcdBrightness           = 100,
	.MaxTemperature          = 300,
	.TempHisteresis          = 40,
	.IsTempProtectionEnabled = true
};			

/* Function section ----------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
void LoadSettings(void)
{
	SettingsCtrl_Init((uint8_t *)&Settings, sizeof(Settings_t));
	SettingsCtrl_LoadAll();	
	
	// If EEPROM memory is empty?
	if (Settings.Language >= NUMBER_OF_LANGUAGES)
	{		
		LoadDefaults();
	}
				
	// Applying changes
	
	SetLcdBacklight(Settings.LcdBrightness);
	
	if (Settings.IsSymModeEnabled) SYM_MODE_ON(); else SYM_MODE_OFF();
	if (Settings.AudioMute) TDA8551_SetVolume(0); else TDA8551_Init();
	PSMData[0].Set.Data.SoftStartTime = Settings.SoftStartTime[0];
	PSMData[1].Set.Data.SoftStartTime = Settings.SoftStartTime[1];
}

/*----------------------------------------------------------------------------*/
void SaveSettings(void)
{
	SettingsCtrl_SaveAll();
}

/*----------------------------------------------------------------------------*/
void LoadDefaults(void)
{
	Settings = DefaultSettings;	
	SettingsCtrl_SaveAll();
}

/******************* (C) COPYRIGHT 2012 HENIUS *************** END OF FILE ****/
