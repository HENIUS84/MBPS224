/**
********************************************************************************
* @file     main.c
* @author   HENIUS (Paweł Witak)
* @version  1.1.2
* @date     15/11/2013
* @brief    Program of supporting Main Board of power supply MBPS
* @mainpage
*           \section Intro Project description
*           This is program of supporting Main Board, which is part of project 
*           MBPS224.
*
*           Device consists of two main parts:
*           - Main Board,
*           - Power Supply Module.
*
*           The responsibilities of Main Board are:
*           - communication with power supply module over isolated I2C bus,
*           - measurements visualization,
*           - setting parameters of power supply modules,
*           - communication with PC.
*           \section DI Devices list
*    		This project was developed for ATmega128.
********************************************************************************
*
* <h2><center>COPYRIGHT 2010  HENIUS</center></h2>
*/

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <avr/wdt.h>
#include <util/delay_basic.h>

// --->User files

#include "main.h"
#include "Menu.h"
#include "Debug.h"
#include "Tasks.h"
#include "Hardware.h"
#include "SerialPort.h"
#include "OWIMaster.h"
#include "GraphLib.h"
#include "KeyboardLib.h"
#include "SoundLib.h"
#include "Settings.h"
#include "Peripherals.h"

/* Variable section ----------------------------------------------------------*/

/*! Prescaler for delay function */
uint16_t DelTimerPresc = SET_DEL_TIME();
volatile int16_t DelayCounter = 0;			/*! Variable for delay function */

/* Function section ----------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
* @brief    Main function
* @param    None
* @retval   None
*/
int main(void)
{	
	// --->System initialization
	
	InitHardware();
	KS0108LCD_Init();
	InitGraphLib(KS0108LCD_SetPixel);	
	LoadSettings();	
	sei();
	
	// DEBUG mode is enabled by DIPSWITCH1
	if (GET_DIPSW(DIPSW1))			
	{
		SetDebugMode(true);
	}
	
	// SPlash screen is enabled by DIPSWITCH2
	if (GET_DIPSW(DIPSW2))			
	{
		ShowSplashScreen();
	}
	
	InitPeripherals();
	
	
	// Advanced by pressing Left and Right key
	IsAdvancedMode = IsKeyPressed('L') && IsKeyPressed('R') ? true : false;
		
	// Main loop
	while (1)						
	{ 
		MenuHandler();
	}

	return 0;
}

/*----------------------------------------------------------------------------*/
/**
* @brief    Timer interrupt handler for delay function reason
* @param    None
* @retval   None
*/
ISR(TIMER0_OVF_vect)
{
	if (!--DelTimerPresc)
	{
		DelTimerPresc = SET_DEL_TIME();

		TemperatureTask();	
		SystemPowerHandler();
		DelayCounter--;
	}
}

/*----------------------------------------------------------------------------*/
/**
* @brief    Timer interrupt handler for system timer (1 ms)
* @param    None
* @retval   None
*/
ISR(TIMER2_COMP_vect)
{	
	sei();
	MainSystemTask();
	KeyboardTask();
	SoundTask();
	MenuKeysTask();
	PSMCtrlTask();
	PSMLcdTask();
	ThermalControlTask();
	PCCommunicationTask();
}

/*----------------------------------------------------------------------------*/
void Wait_ms(uint16_t delay)
{
	DelayCounter = delay;

	while (DelayCounter > 0);
}

/******************* (C) COPYRIGHT 2010 HENIUS *************** END OF FILE ****/
