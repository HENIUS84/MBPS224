/**
 ******************************************************************************
 * @file     Tasks.c
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.1
 * @date     19/11/2010
 * @brief    Zestaw zadań obsługiwanych przez płytę główną
 ******************************************************************************
 *
 * <h2><center>COPYRIGHT 2010 HENIUS</center></h2>
 */

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <avr/pgmspace.h>
#include <avr/wdt.h>

// --->Pliki użytkownika

#include "Hardware.h"
#include "I2CMaster.h"
#include "SerialPort.h"
#include "PSMController.h"
#include "Debug.h"
#include "KeyboardLib.h"
#include "Tasks.h"
#include "SoundLib.h"
#include "OWIThermometer.h"
#include "Menu.h"
#include "Peripherals.h"
#include "Settings.h"
#include "PSDataService.h"

/* Sekcja funkcji ------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
 * @brief    Główne zadanie systemowe 1 ms
 * @param    Brak
 * @retval   Brak
 */
void MainSystemTask(void) 
{		
	StatLedHandler();				// Obsługa migania diodą
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Zadanie obsługi generowania dźwięku
 * @param    Brak
 * @retval   Brak
 */
void SoundTask(void) 
{
	// Timer zadania
	static uint16_t timer = SOUND_TASK_TIME;
	
	if (!(--timer)) 
	{
		timer = SOUND_TASK_TIME;
				
		SoundLibHandler();
	}	
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Zadanie obsługi pomiaru temperatury
 * @param    Brak
 * @retval   Brak
 */
void TemperatureTask(void) 
{
	// Timer zadania
	static uint16_t timer = TEMP_TASK_TIME;
	
	if (!(--timer)) 
	{
		timer = TEMP_TASK_TIME;
		
		// Odczyt temperatury i jej znaku wprost z czujnika
		OWIThermo_Handler();
	
		// Konwersja temperatury
		MainBoardTemp = ThermometerController.Temperatures[0] * 10 / 16;
	}	
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Zadanie wymiany danych z modułami zasilacza
 * @param    Brak
 * @retval   Brak
 */
void PSMCtrlTask(void)
{
	// Timer zadania
	static uint16_t timer = PSM_TASK_TIME;
	
	if (!(--timer)) 
	{
		timer = PSM_TASK_TIME;
		
		wdt_reset();
		PSMController_Handler();
	}	
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Zadanie obsługi przycisków menu
 * @param    Brak
 * @retval   Brak
 */
void MenuKeysTask(void) 
{
	// Timer zadania
	static uint16_t timer = MENU_TASK_TIME;
	
	if (!(--timer)) 
	{
		timer = MENU_TASK_TIME;
		
		MenuKeysHandler();			// Obsługa przycisków menu
	}	
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Zadanie obsługi wyświetlania
 * @param    Brak
 * @retval   Brak
 */
void PSMLcdTask(void) 
{
	// Timer zadania
	static uint16_t timer = LCD_TASK_TIME;
	
	if (!(--timer)) 
	{
		timer = LCD_TASK_TIME;
		
		KS0108LCD_MemoryHandler();
	}	
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Zadanie obsługi klawiatury
 * @param    Brak
 * @retval   Brak
 */
void KeyboardTask(void) 
{
	// Timer zadania
	static uint16_t timer = KBD_TASK_TIME;
	
	if (!(--timer)) 
	{
		timer = KBD_TASK_TIME;
		
		KeyboardHandler();
	}	
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Zadanie zarządzania temperaturą
 * @param    Brak
 * @retval   Brak
 */
void ThermalControlTask(void)
{
	// Timer zadania
	static uint16_t timer = TEMP_CTRL_TASK_TIME;
	
	if (!(--timer))
	{
		timer = TEMP_CTRL_TASK_TIME;
		
		PSMData[0].Set.Data.MaxTemperature = 
			PSMData[1].Set.Data.MaxTemperature = Settings.MaxTemperature;
		PSMData[0].Set.Data.TempHisteresis =
			PSMData[1].Set.Data.TempHisteresis = Settings.TempHisteresis;
		PSMData[0].Set.Data.TempProtection = 
			PSMData[1].Set.Data.TempProtection = 
				Settings.IsTempProtectionEnabled;
		ThermalData.IsOverheat[0] = PSMData[0].Get.Data.IsOverheat;
		ThermalData.IsOverheat[1] = PSMData[1].Get.Data.IsOverheat;
		ThermalCtrl_Handler();
	}
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Zadanie komunikacji z PC
 * @param    Brak
 * @retval   Brak
 */
void PCCommunicationTask()
{
	// Timer zadania
	static uint16_t timer = PC_COMM_TASK_TIME;
	
	if (!(--timer))
	{
		timer = PC_COMM_TASK_TIME;
		
		PSDataService_Handler();
	}
}

/******************* (C) COPYRIGHT 2010 HENIUS *************** KONIEC PLIKU ***/
