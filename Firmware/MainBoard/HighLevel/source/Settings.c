/**
 *******************************************************************************
 * @file     Settings.c
 * @author   HENIUS (Pawe³ Witak)
 * @version  1.1.1
 * @date     12-11-2012
 * @brief    Obs³uga ustawieñ programu
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2012 HENIUS</center></h2>
 */

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <stdint.h>
#include <avr/io.h>
#include <string.h>

// --->Pliki u¿ytkownika

#include "Settings.h"
#include "TDA8551.h"
#include "SettingsController.h"
#include "Peripherals.h"

/* Sekcja zmiennych ----------------------------------------------------------*/

Settings_t Settings;				/*!< Ustawienia programu */
/*! Domyœlne ustawienia */
Settings_t DefaultSettings = {
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

/* Sekcja funkcji ------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
* @brief    £adowanie ustawieñ programu
* @param    Brak
* @retval   Brak
*/
void LoadSettings(void)
{
	// Inicjalizacja modu³u ustawieñ
	SettingsCtrl_Init((uint8_t *)&Settings, sizeof(Settings_t));
	SettingsCtrl_LoadAll();	
	
	// Czy pamiêæ EEPROM jest pusta?
	if (Settings.Language >= NUMBER_OF_LANGUAGES)
	{		
		LoadDefaults();				// Przywracanie ustawieñ domyœlnych
	}
				
	// --->Zatwierdzanie zmian
	
	// Podœwietlenie
	SetLcdBacklight(Settings.LcdBrightness);
	
	// Tryb symetryczny
	if (Settings.IsSymModeEnabled)
	{
		SYM_MODE_ON();
	}
	else
	{
		SYM_MODE_OFF();
	}
		
	// G³oœnoœæ
	if (Settings.AudioMute)
	{
		TDA8551_SetVolume(0);
	}
	else
	{
		TDA8551_Init();
	}
		
	// Czas ³agodnego startu
	PSMData[0].Set.Data.SoftStartTime = Settings.SoftStartTime[0];
	PSMData[1].Set.Data.SoftStartTime = Settings.SoftStartTime[1];
}

/*----------------------------------------------------------------------------*/
/**
* @brief    Zapis ustawieñ programu
* @param    Brak
* @retval   Brak
*/
void SaveSettings(void)
{
	SettingsCtrl_SaveAll();			// Zapis ustawieñ
}

/*----------------------------------------------------------------------------*/
/**
* @brief    £adowanie ustawieñ domyœlnych
* @param    Brak
* @retval   Brak
*/
void LoadDefaults(void)
{
	// Przywracanie ustawieñ domyœlnych
	Settings = DefaultSettings;	
	SettingsCtrl_SaveAll();
}

/******************* (C) COPYRIGHT 2012 HENIUS *************** KONIEC PLIKU ***/