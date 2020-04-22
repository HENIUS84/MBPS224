/**
 *******************************************************************************
 * @file     Peripherals.c
 * @author   HENIUS (Pawe³ Witak)
 * @version  1.1.2
 * @date     09-01-2014
 * @brief    Peripherals driver
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdint.h>
#include <avr/io.h>

// --->User files

#include "main.h"
#include "Peripherals.h"
#include "SoundLib.h"
#include "I2CMaster.h"
#include "Settings.h"
#include "KeyboardLib.h"
#include "TDA8551.h"
#include "PSDataService.h"

/* Variable section ----------------------------------------------------------*/

int16_t MainBoardTemp;	
SPController_t SerialPortController =
{
	.Delay           = Wait_ms,
	.CpuFrequency    = F_CPU,
	.IsPrintfEnabled = true,
	.PrintfPort      = SPN_USART0
};
/*! Serial port configuration */
static SPDescriptor_t SerialPortConfig =
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
PSMCData_t PSMData[PSM_TABLE_SIZE];
CommSpeed_t CommunicationSpeed;
/*! 1-Wire temperatures */
static int16_t Temperature[AMOUNT_OF_THERMOMETERS];
/*! 1-Wire sensors info */
static OWIDevice_t Info[AMOUNT_OF_THERMOMETERS];
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
ThermalData_t ThermalData = 
{
	.BoardTemperature    = &MainBoardTemp,
	.MaxTemperature		 = &Settings.MaxTemperature,
	.TempHisteresis		 = &Settings.TempHisteresis,
	.IsTempProtEnabled	 = &Settings.IsTempProtectionEnabled,  
	.EnableRegulator     = SetRegulator,
	.SetCooler           = SetCoolerPower
};	
/*! Module communication controller */
static PSMController_t PSMController =
{
	.ModData         = PSMData,
	.SpeedData       = &CommunicationSpeed,
	.AmountOfModules = PS_MODULES_COUNT,
	.TaskTime         = PSM_TASK_TIME
};	
/*! Keyboard controller */
static Keyboard_t Keyboard =
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
/*! Sound controller */
SoundController_t SoundController =
{
	.SetFreq   = Audio_SetFreq,
	.StopSound = Audio_StopSound
};

/* Function section ----------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
void InitPeripherals(void)
{
	uint8_t index;
	
	// Initialization of measurement table
	for (index = 0; index < PS_MODULES_COUNT; index++)
	{
		PSMData[index].Set.Header.DeviceId =
			(PSM_BASE_ID + index) << I2C_ADDR_BITS;
		PSMData[index].Set.Data.Current = DEFAULT_SET_CURRENT;
		PSMData[index].Set.Data.PowerState = PSMS_ON;
	}
		
	//InitHardware();	
	SerialPort_Init(&SerialPortController);
	SerialPort_Open(SPN_USART0,
	                &SerialPortConfig);
	//KS0108LCD_Init();	
	PSMController_Init(&PSMController);
	PSDataService_Init();
	Buttons_Init();
	InitKeyboard(&Keyboard);
	OWIThermo_Init(&ThermometerController);
	TDA8551_Init();
	Audio_Init(F_CPU);
	InitSoundLib(&SoundController);	
	ThermalCtrl_Init(&ThermalData);
}

/*----------------------------------------------------------------------------*/
uint8_t GetPSModulesNumber(void)
{
	uint8_t index;
	uint8_t result = 0;											
	
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
void SetRegulator(bool isEnabled, uint8_t moduleNumber)
{
	PSMData[moduleNumber].Set.Data.PowerState = isEnabled ? PSMS_ON : PSMS_OFF; 
}

/******************* (C) COPYRIGHT 2013 HENIUS *************** END OF FILE ****/