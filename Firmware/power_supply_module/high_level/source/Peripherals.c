/**
 *******************************************************************************
 * @file     Peripherals.c
 * @author   HENIUS (Pawe³ Witak)
 * @version  1.1.1
 * @date     25-01-2013
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
#include "Tasks.h"
#include "Peripherals.h"
#include "Hardware.h"
#include "SerialPort.h"
#include "Version.h"
#include "MBController.h"

/* Variable section ----------------------------------------------------------*/

/*! Serial port controller */
static SPController_t SerialPortController =
{
	.Delay           = Wait_ms,
	.CpuFrequency    = F_CPU,
	.IsPrintfEnabled = true,
	.PrintfPort      = SPN_USART0
};
/*! Serial port configuration */
static SPDescriptor_t SerialPortConfig = 
{
	.BaudRate   = SPBR_38400,
	.DataLength = 8,
	.StopBits   = 1,
	.Parity     = SPP_NO_PARITY,
	.Edge       = SPE_TRRF,
	.SyncMode   = SPSM_ASYNCHRONOUS,
	.SpeedMode  = SPSM_NORMAL
};
/*!< Controller of communication with main board */
MBController_t MBCommController =
{
	.MBData  =
	{
		.Get.Data.Current = 1000
	},
	.SysTime = SYS_TIME
};
PSMreg_t PSMReg;
/*! Temperature list of 1-Wire */
static int16_t Temperature[AMOUNT_OF_THERMOMETERS];
/*! 1-Wire sensor informations */
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
Multimeter_t Multimeter;

/* Function section ----------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
void InitPeripherals_(void)
{
	InitHardware();
	
	// --->Serial port
	SerialPort_Init(&SerialPortController);
	SerialPort_Open(SPN_USART0, &SerialPortConfig);

	// --->Main board communicaton
	MBCommController.MBData.DeviceId = PSM_ID_BASE + GET_MODULE_ADDR();
	GetFirmwareVersion(&MBCommController.MBData.Set.Firmware.Info, 
	                   FIRMWARE_VERSION);
	MBController_Init(&MBCommController);

	// --->Multimeter
	Multimeter_Init(&Multimeter);

	// --->Voltage and current regulator
	MBCommController.MBData.Set.Data.IsPowerOn = true;
	Regulator_Init(&PSMReg);
	
	// --->Regulator thermometer
	OWIThermo_Init(&ThermometerController);
}

/******************* (C) COPYRIGHT 2013 HENIUS *************** END OF FILE ****/
