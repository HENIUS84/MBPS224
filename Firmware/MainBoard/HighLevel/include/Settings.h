/**
 *******************************************************************************
 * @file     SettingsController.h
 * @author   HENIUS (Pawe³ Witak)
 * @version  1.1.1
 * @date     11-11-2012
 * @brief    Ustawienia programu (plik nag³ówkowy)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2012 HENIUS</center></h2>
 */

#ifndef  SETTINGS_H_
#define  SETTINGS_H_

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <stdbool.h>

// --->Pliki u¿ytkownika

#include "Hardware.h"
#include "Menu.h"

/* Sekcja sta³ych, makr i definicji ------------------------------------------*/

// --->Typy

/**
 * @brief Ustawienia programu
 */
typedef struct
{
	/*! Zadane napiêcie */
	uint16_t SetVoltage[PS_MODULES_COUNT];
	/*! Zadane natê¿enie pr¹du */
	uint16_t SetCurrent[PS_MODULES_COUNT];	
	/*! Zadane wartoœci PWM kana³ów */
	uint16_t SetPWM[PS_MODULES_COUNT];	
	/*! Czasy ³agodnego startu (w sekundach) */
	uint16_t SoftStartTime[PS_MODULES_COUNT];	
	uint8_t LcdBrightness;			/*!< Podœwietlenie wyœwietlacza */
	Language_t Language;			/*!< Jêzyk menu */
	/*! Flaga oznaczaj¹ca w³¹czony tryb symetryczny zasilania */
	bool IsSymModeEnabled;			
	bool AudioMute;					/*!< Wyciszanie g³oœnoœci */
	int16_t MaxTemperature;			/*!< Progowa temp. uk³adu ch³odzenia */	
	int16_t TempHisteresis;			/*!< Histereza temp. uk³adu ch³odzenia */
	/*! Flaga aktywacji uk³adu zabezpieczenia temperaturowego */
	bool IsTempProtectionEnabled;	
}Settings_t;

/* Sekcja deklaracji ---------------------------------------------------------*/

// --->Zmienne

extern Settings_t Settings;			// Ustawienia programu

// --->Funkcje

void LoadSettings(void);			// £adowanie ustawieñ programu
void SaveSettings(void);			// Zapis ustawieñ programu
void LoadDefaults(void);			// £adowanie ustawieñ domyœlnych

#endif								/* SETTINGS_H_ */

/******************* (C) COPYRIGHT 2011 HENIUS ************** KONIEC PLIKU ****/
