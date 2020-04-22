/**
 *******************************************************************************
 * @file     Tasks.c
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.1
 * @date     04-04-2011
 * @brief    List of tasks handled by PS module
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2011 HENIUS</center></h2>
 */

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdint.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <stdbool.h>

// --->User files

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

/* Function section ----------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
void MainSystemTask(void)
{
	StatLedHandler();
}

/*----------------------------------------------------------------------------*/
void MultimeterTask(void)
{
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
void TemperatureTask(void)
{
	static uint8_t timer = TEMP_TASK_TIME;
	
	if (!(--timer))
	{
		timer = TEMP_TASK_TIME;
		OWIThermo_Handler();
		MBCommController.MBData.Set.Data.Temperature = 
			ThermometerController.Temperatures[0] * 10 / 16;
	}	
}

/*----------------------------------------------------------------------------*/
void RegulatorTask(void)
{
	static uint8_t timer = REGULATOR_TASK_TIME;
	
	if (!(--timer))
	{
		timer = REGULATOR_TASK_TIME;
		
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

		// Regulator power state management
		if (MBCommController.MBData.Get.Data.PowerState != PSMS_IDLE)
		{
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
	
		// Voltage and current regulation
		Regulator_Handler();
		MBCommController.MBData.Set.Data.IsOvercurrent = PSMReg.IsOvercurrent;
		MBCommController.MBData.Set.Data.IsOverheat = PSMReg.IsOverheat;
	}	
}

/*----------------------------------------------------------------------------*/
void CtrlTask(void)
{
	static uint8_t timer = MB_TASK_TIME;
	
	if (!(--timer))
	{
		timer = MB_TASK_TIME;
	
		MBController_Handler();		
	}	
}

/*----------------------------------------------------------------------------*/
void InitTasks(void)
{
	Regulator_TurnOnOff(false);
}

/******************* (C) COPYRIGHT 2010 HENIUS *************** END OF FILE ****/
