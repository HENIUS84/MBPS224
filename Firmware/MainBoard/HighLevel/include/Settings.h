/**
 *******************************************************************************
 * @file     SettingsController.h
 * @author   HENIUS (Pawe� Witak)
 * @version  1.1.1
 * @date     11-11-2012
 * @brief    Ustawienia programu (plik nag��wkowy)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2012 HENIUS</center></h2>
 */

#ifndef  SETTINGS_H_
#define  SETTINGS_H_

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <stdbool.h>

// --->Pliki u�ytkownika

#include "Hardware.h"
#include "Menu.h"

/* Sekcja sta�ych, makr i definicji ------------------------------------------*/

// --->Typy

/**
 * @brief Ustawienia programu
 */
typedef struct
{
	/*! Zadane napi�cie */
	uint16_t SetVoltage[PS_MODULES_COUNT];
	/*! Zadane nat�enie pr�du */
	uint16_t SetCurrent[PS_MODULES_COUNT];	
	/*! Zadane warto�ci PWM kana��w */
	uint16_t SetPWM[PS_MODULES_COUNT];	
	/*! Czasy �agodnego startu (w sekundach) */
	uint16_t SoftStartTime[PS_MODULES_COUNT];	
	uint8_t LcdBrightness;			/*!< Pod�wietlenie wy�wietlacza */
	Language_t Language;			/*!< J�zyk menu */
	/*! Flaga oznaczaj�ca w��czony tryb symetryczny zasilania */
	bool IsSymModeEnabled;			
	bool AudioMute;					/*!< Wyciszanie g�o�no�ci */
	int16_t MaxTemperature;			/*!< Progowa temp. uk�adu ch�odzenia */	
	int16_t TempHisteresis;			/*!< Histereza temp. uk�adu ch�odzenia */
	/*! Flaga aktywacji uk�adu zabezpieczenia temperaturowego */
	bool IsTempProtectionEnabled;	
}Settings_t;

/* Sekcja deklaracji ---------------------------------------------------------*/

// --->Zmienne

extern Settings_t Settings;			// Ustawienia programu

// --->Funkcje

void LoadSettings(void);			// �adowanie ustawie� programu
void SaveSettings(void);			// Zapis ustawie� programu
void LoadDefaults(void);			// �adowanie ustawie� domy�lnych

#endif								/* SETTINGS_H_ */

/******************* (C) COPYRIGHT 2011 HENIUS ************** KONIEC PLIKU ****/
