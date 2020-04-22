/**
 ******************************************************************************
 * @file     Tasks.c
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.1
 * @date     19/11/2010
 * @brief    Task list supported by main board
 ******************************************************************************
 *
 * <h2><center>COPYRIGHT 2010 HENIUS</center></h2>
 */

/* Include section -----------------------------------------------------------*/

// --->System files

#include <avr/pgmspace.h>
#include <avr/wdt.h>

// --->User files

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

/* Function section ----------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
void MainSystemTask(void) 
{		
	StatLedHandler();
}

/*----------------------------------------------------------------------------*/
void SoundTask(void) 
{
	static uint16_t timer = SOUND_TASK_TIME;
	
	if (!(--timer)) 
	{
		timer = SOUND_TASK_TIME;
				
		SoundLibHandler();
	}	
}

/*----------------------------------------------------------------------------*/
void TemperatureTask(void) 
{
	static uint16_t timer = TEMP_TASK_TIME;
	
	if (!(--timer)) 
	{
		timer = TEMP_TASK_TIME;
		OWIThermo_Handler();
		MainBoardTemp = ThermometerController.Temperatures[0] * 10 / 16;
	}	
}

/*----------------------------------------------------------------------------*/
void PSMCtrlTask(void)
{
	static uint16_t timer = PSM_TASK_TIME;
	
	if (!(--timer)) 
	{
		timer = PSM_TASK_TIME;
		
		wdt_reset();
		PSMController_Handler();
	}	
}

/*----------------------------------------------------------------------------*/
void MenuKeysTask(void) 
{
	static uint16_t timer = MENU_TASK_TIME;
	
	if (!(--timer)) 
	{
		timer = MENU_TASK_TIME;		
		MenuKeysHandler();
	}	
}

/*----------------------------------------------------------------------------*/
void PSMLcdTask(void) 
{
	static uint16_t timer = LCD_TASK_TIME;
	
	if (!(--timer)) 
	{
		timer = LCD_TASK_TIME;		
		KS0108LCD_MemoryHandler();
	}	
}

/*----------------------------------------------------------------------------*/
void KeyboardTask(void) 
{
	static uint16_t timer = KBD_TASK_TIME;
	
	if (!(--timer)) 
	{
		timer = KBD_TASK_TIME;
		
		KeyboardHandler();
	}	
}

/*----------------------------------------------------------------------------*/
void ThermalControlTask(void)
{
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
void PCCommunicationTask()
{
	static uint16_t timer = PC_COMM_TASK_TIME;
	
	if (!(--timer))
	{
		timer = PC_COMM_TASK_TIME;
		
		PSDataService_Handler();
	}
}

/******************* (C) COPYRIGHT 2010 HENIUS *************** END OF FILE ****/
