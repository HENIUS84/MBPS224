/**
 *******************************************************************************
 * @file     Tasks.c
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.1
 * @date     04-04-2011
 * @brief    Zestaw zadań obsługiwanych przez moduł zasilacza
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2011 HENIUS</center></h2>
 */

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <stdint.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <stdbool.h>

// --->Pliki użytkownika

#include "Tasks.h"
#include "Hardware.h"
#include "I2CSlave.h"
#include "SerialPort.h"
#include "MBController.h"
#include "Multimeter.h"
#include "Regulator.h"
#include "OWIMaster.h"
#include "OWIThermometer.h"
#include "Debug.h"
#include "Peripherals.h"

/* Sekcja funkcji ------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
 * @brief    Główne zadanie systemowe 1 ms
 * @param    Brak
 * @retval   Brak
 */
void MainSystemTask(void)
{
	StatLedHandler();			// Obsługa migania diodą
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Zadanie obsługi pomiarów napięcia i natężenia prądu
 * @param    Brak
 * @retval   Brak
 */
void MultimeterTask(void)
{
	// Timer zadania
	static uint8_t timer = MULTIMETER_TASK_TIME;
	
	if (!(--timer))
	{
		timer = MULTIMETER_TASK_TIME;
		
		Multimeter_ConvReq();
		Multimeter.IsPowerOn = MBCommController.MBData.Set.Data.IsPowerOn;
		MBCommController.MBData.Set.Data.Voltage = Multimeter.Filtered.Voltage;		
		MBCommController.MBData.Set.Data.UnfilteredVoltage =
			Multimeter.Unfiltered.Voltage;
		MBCommController.MBData.Set.Data.VoltageADC =
			Multimeter.Filtered.VoltageADC;
		MBCommController.MBData.Set.Data.Current = Multimeter.Filtered.Current;
		MBCommController.MBData.Set.Data.UnfilteredCurrent =
			Multimeter.Unfiltered.Current;
		MBCommController.MBData.Set.Data.CurrentADC =
			Multimeter.Filtered.CurrentADC;
	}	
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Zadanie obsługi pomiaru temperatury stabilizatora
 * @param    Brak
 * @retval   Brak
 */
void TemperatureTask(void)
{
	// Timer zadania
	static uint8_t timer = TEMP_TASK_TIME;
	
	if (!(--timer))
	{
		timer = TEMP_TASK_TIME;
		
		// Odczyt temperatury i jej znaku wprost z czujnika
		OWIThermo_Handler();
	
		// Konwersja temperatury
		MBCommController.MBData.Set.Data.Temperature = 
			ThermometerController.Temperatures[0] * 10 / 16;
	}	
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Zadanie obsługi regulatora napięcia i natężenia prądu
 * @param    Brak
 * @retval   Brak
 */
void RegulatorTask(void)
{
	// Timer zadania
	static uint8_t timer = REGULATOR_TASK_TIME;
	
	if (!(--timer))
	{
		timer = REGULATOR_TASK_TIME;
		
		// Pobieranie niezbędnych danych dla regulatora
		PSMReg.ManualMode = MBCommController.MBData.Get.Data.ManualMode;
		PSMReg.SetCurrent = MBCommController.MBData.Get.Data.Current;
		PSMReg.SetVoltage = MBCommController.MBData.Get.Data.Voltage;
		PSMReg.Current = MBCommController.MBData.Set.Data.Current;
		PSMReg.SoftStartTime = 
			(uint32_t)MBCommController.MBData.Get.Data.SoftStartTime * 1000;
		PSMReg.IsTempProtectionEnabled = 
			MBCommController.MBData.Get.Data.TempProtection;
		PSMReg.MaxTemperature = MBCommController.MBData.Get.Data.MaxTemperature;
		PSMReg.TempHisteresis = MBCommController.MBData.Get.Data.TempHisteresis;
		PSMReg.Temperature = MBCommController.MBData.Set.Data.Temperature;
		MBCommController.MBData.Set.Data.IsPowerOn = PSMReg.IsPowerOn;

		// Zarządzanie włączaniem stabilizatora
		if (MBCommController.MBData.Get.Data.PowerState != PSMS_IDLE)
		{
			// Zmiana stanu zasilania
			if (MBCommController.MBData.Get.Data.PowerState == PSMS_OFF)
			{
				//Regulator_TurnOn(false);
				MBCommController.MBData.Set.Data.IsPowerOn = false;
			}
			else
			{
				MBCommController.MBData.Set.Data.IsOvercurrent = false;		
				MBCommController.MBData.Set.Data.IsPowerOn = true;	
				Regulator_TurnOnOff(true); 
			}

			MBCommController.MBData.Get.Data.PowerState = PSMS_IDLE;
		}
	
		// Regulacja napięcia i natężenia prądu
		Regulator_Handler();
		MBCommController.MBData.Set.Data.IsOvercurrent = PSMReg.IsOvercurrent;
		MBCommController.MBData.Set.Data.IsOverheat = PSMReg.IsOverheat;
	}	
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Zadanie wymiany danych z płytą główną
 * @param    Brak
 * @retval   Brak
 */
void CtrlTask(void)
{
	// Timer zadania
	static uint8_t timer = MB_TASK_TIME;
	
	if (!(--timer))
	{
		timer = MB_TASK_TIME;
	
		MBController_Handler();		
	}	
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Inicjalizacja zadań
 * @param    Brak
 * @retval   Brak
 */
void InitTasks(void)
{
	Regulator_TurnOnOff(false);				// Domyślne wyłączanie stabilizatora
}

/******************* (C) COPYRIGHT 2010 HENIUS *************** KONIEC PLIKU ***/
