/**
 *******************************************************************************
 * @file     Peripherals.c
 * @author   HENIUS (Pawe³ Witak)
 * @version  1.1.2
 * @date     09-01-2014
 * @brief    Obs³uga peryferiów
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe
#include <stdint.h>
#include <avr/io.h>

// --->Pliki u¿ytkownika
#include "main.h"
#include "Peripherals.h"
#include "SoundLib.h"
#include "I2CMaster.h"
#include "Settings.h"
#include "KeyboardLib.h"
#include "TDA8551.h"
#include "PSDataService.h"

/* Sekcja zmiennych ----------------------------------------------------------*/

int16_t MainBoardTemp;				/*!< Temperatura p³ytki */	
/*! Kontroler portu szeregowego */
SPController_t SerialPortController =
{
	.Delay           = Wait_ms,
	.CpuFrequency    = F_CPU,
	.IsPrintfEnabled = true,
	.PrintfPort      = SPN_USART0
};
/*! Konfiguracja portu szeregowego */
SPDescriptor_t SerialPortConfig =
{
	.BaudRate     = SPBR_115200,
	.DataLength   = 8,
	.StopBits     = 1,
	.Parity       = SPP_NO_PARITY,
	.Edge         = SPE_TRRF,
	.SyncMode     = SPSM_ASYNCHRONOUS,
	.SpeedMode    = SPSM_NORMAL,
	.IsIrqEnabled = true
};
/*! Dane pomiarowe modu³ów zasilacza */
PSMCData_t PSMData[PSM_TABLE_SIZE];
CommSpeed_t CommunicationSpeed;		/*!< Prêdkoœci komunikacji z modu³ami */
/*! Lista temperatur z 1-Wire */
int16_t Temperature[AMOUNT_OF_THERMOMETERS];
/*! Informacje o czujniku 1-Wire */
OWIDevice_t Info[AMOUNT_OF_THERMOMETERS];
/*! Kontroler obs³ugi termometrów na 1-Wire */
OWIThermoCtrl_t ThermometerController =
{
	.MaxAmountOfDevices = AMOUNT_OF_THERMOMETERS,
	.TaskTime           = TEMP_TASK_TIME,
	.Delay_ms           = Wait_ms,
	.RepetitionTime     = 800,
	.Resolution         = OWITR_12BIT,
	.Devices            = Info,
	.Temperatures       = Temperature
};
/*! Dane kontrolera temperatury */
ThermalData_t ThermalData = 
{
	.BoardTemperature    = &MainBoardTemp,
	.MaxTemperature		 = &Settings.MaxTemperature,
	.TempHisteresis		 = &Settings.TempHisteresis,
	.IsTempProtEnabled	 = &Settings.IsTempProtectionEnabled,  
	.EnableRegulator     = SetRegulator,
	.SetCooler           = SetCoolerPower
};	
/*! Dane kontrolera komunikacji z modu³ami */
PSMController_t PSMController =
{
	.ModData         = PSMData,
	.SpeedData       = &CommunicationSpeed,
	.AmountOfModules = PS_MODULES_COUNT,
	.TaskTime         = PSM_TASK_TIME
};	
/*! Kontroler klawiatury */
Keyboard_t Keyboard =
{
	.AmountOfButtons = 4,
	.Handler         = Buttons_Handler,
	.HandlerTime     = KBD_TASK_TIME,
	.ButtonMap       =
	{
		// Góra
		{
			.Mask = 1 << 7,
			.Code = 'U'
		},
		// Prawo
		{
			.Mask = 1 << 6,
			.Code = 'R'
		},
		// Lewo
		{
			.Mask = 1 << 5,
			.Code = 'L'
		},
		// Dó³
		{
			.Mask = 1 << 4,
			.Code = 'D'
		}
	}
};
/*! Kontroler obs³ugi dŸwiêku */
SoundController_t SoundController =
{
	.SetFreq   = Audio_SetFreq,
	.StopSound = Audio_StopSound
};

/* Sekcja funkcji ------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
* @brief    Inicjalizacja peryferiów
* @param    *peripherals : wskaŸnik do struktury peryferiów
* @retval   Brak
*/
void InitPeripherals(void)
{
	uint8_t index;
	
	// Inicjalizacja tablicy pomiarów
	for (index = 0; index < PS_MODULES_COUNT; index++)
	{
		PSMData[index].Set.Header.DeviceId =
			(PSM_BASE_ID + index) << I2C_ADDR_BITS;
		PSMData[index].Set.Data.Current = DEFAULT_SET_CURRENT;
		PSMData[index].Set.Data.PowerState = PSMS_ON;
	}
		
	//InitHardware();					// Inicjalizacja g³ównych podzespo³ów
	
	// --->Port szeregowy
	SerialPort_Init(&SerialPortController);
	SerialPort_Open(SPN_USART0,
	                &SerialPortConfig);
					
	// -->Wyœwietlacz				
	//KS0108LCD_Init();				// Inicjalizacja wyœwietlacza	
	
	// --->Kontroler komunikacji z modu³em zasilacza	
	PSMController_Init(&PSMController);
	
	// --->Komunikcja z PC
	PSDataService_Init();
	
	// --->Klawiatura
	Buttons_Init();
	InitKeyboard(&Keyboard);
	
	// --->Pomiar temperatury stabilizatora
	OWIThermo_Init(&ThermometerController);
	
	// --->Obs³uga audio
	TDA8551_Init();					// Inicjalizacja wzmacniacza
	Audio_Init(F_CPU);				// Inicjalizacja obs³ugi audio
	// Inicjalizacja biblioteki dŸwiêkowej
	InitSoundLib(&SoundController);	
	
	// --->Kontrola temperaturowa
	ThermalCtrl_Init(&ThermalData);
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Pobieranie liczby pod³¹czonych modu³ów
 * @param    Brak
 * @retval   Liczba pod³¹czonych modu³ów
 */
uint8_t GetPSModulesNumber(void)
{
	uint8_t index;					// Indeks pomocniczy
	uint8_t result = 0;				// Liczba pod³¹czonych modu³ów												
	
	for (index = 0; index < PS_MODULES_COUNT; index++)
	{
		if (PSMData[index].ConnReg.IsConnected)
		{
			result++;
		}
	}
	
	return result;
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Aktywacja/dezaktywacja modu³u zasilacza
 * @param    isEnabled : flaga w³¹czania modu³u
 * @param    moduleNumber : numer modu³u
 * @retval   Brak
 */
void SetRegulator(bool isEnabled, uint8_t moduleNumber)
{
	PSMData[moduleNumber].Set.Data.PowerState = isEnabled ? PSMS_ON : PSMS_OFF; 
}

/******************* (C) COPYRIGHT 2013 HENIUS *************** KONIEC PLIKU ***/