/**
 *******************************************************************************
 * @file     Peripherals.c
 * @author   HENIUS (Pawe³ Witak)
 * @version  1.1.1
 * @date     25-01-2013
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
#include "Tasks.h"
#include "Peripherals.h"
#include "Hardware.h"
#include "SerialPort.h"
#include "Version.h"
#include "MBController.h"

/* Sekcja zmiennych ----------------------------------------------------------*/

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
	.BaudRate   = SPBR_38400,
	.DataLength = 8,
	.StopBits   = 1,
	.Parity     = SPP_NO_PARITY,
	.Edge       = SPE_TRRF,
	.SyncMode   = SPSM_ASYNCHRONOUS,
	.SpeedMode  = SPSM_NORMAL
};
/*!< Kontroler komunikacji z p³yt¹ g³ówn¹ */
MBController_t MBCommController =
{
	.MBData  =
	{
		.Get.Data.Current = 1000
	},
	.SysTime = SYS_TIME
};
PSMreg_t PSMReg;					/*! Rejestr regulatora */
/*! Lista temperatur z 1-Wire */
int16_t Temperature[AMOUNT_OF_THERMOMETERS];
/*! Informacje o czujniku 1-Wire */
OWIDevice_t Info[AMOUNT_OF_THERMOMETERS];
/*! Kontroler obs³ugi termometrów */
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
/*! Struktura ze wskaŸnikami dla multimetru */
Multimeter_t Multimeter;

/* Sekcja funkcji ------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
* @brief    Inicjalizacja peryferiów
* @param    Brak
* @retval   Brak
*/
void InitPeripherals_(void)
{
	InitHardware();					// Inicjalizacja g³ównych podzespo³ów
	
	// --->Port szeregowy
	SerialPort_Init(&SerialPortController);
	SerialPort_Open(SPN_USART0, &SerialPortConfig);

	// --->Komunikacja z p³yt¹ g³ówn¹	
	// Pobieranie adresu modu³u (adres bazowy + adres ustawiony na dipswitch'u)
	MBCommController.MBData.DeviceId = PSM_ID_BASE + GET_MODULE_ADDR();
	// Pobieranie wersji oprogramowania i daty kompilacji
	GetFirmwareVersion(&MBCommController.MBData.Set.Firmware.Info, 
	                   FIRMWARE_VERSION);
	MBController_Init(&MBCommController);

	// --->Multimetr (pomiar napiêcia i natê¿enia pr¹du)
	Multimeter_Init(&Multimeter);

	// --->Regulator napiêcia i natê¿enia pr¹du
	MBCommController.MBData.Set.Data.IsPowerOn = true;
	Regulator_Init(&PSMReg);
	
	// --->Pomiar temperatury stabilizatora
	OWIThermo_Init(&ThermometerController);
}

/******************* (C) COPYRIGHT 2013 HENIUS *************** KONIEC PLIKU ***/