/**
 ******************************************************************************
 * @file     main.c                                                   
 * @author   HENIUS (Paweł Witak)                                      
 * @version  1.1.1                                                         
 * @date     03-04-2011                                                       
 * @brief    Program of supporting power supply module
 * @mainpage
 *           \section Intro Project description
 *           This project is for power supply module which is part of power
 *           supply project MBPS224.
 *
 *           Device consists of two main parts:
 *           - Main Board,
 *           - Power Supply Module.
 *
 *           The responsibilities of Power Supply Module are:
 *           - voltage and current regulation,
 *           - temperature measurement of voltage regulator,
 *           - voltage and current measurements,
 *           - communication with Main Board by isolated I2C bus.
 *           \section DI Devices list
 *    		This project was developed for ATmega32.
 *
 ******************************************************************************
 *
 * <h2><center>COPYRIGHT 2011 HENIUS</center></h2>
 */

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdio.h>
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>

// --->User files

#include "Tasks.h"
#include "main.h"
#include "SerialPort.h"
#include "I2CSlave.h"
#include "ADC.h"
#include "Debug.h"
#include "Hardware.h"

/* Variable section ----------------------------------------------------------*/

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
	
	InitPeripherals_();
	sei();	
	InitTasks();		
	ADC_StartConv();

	// DEBUG mode is enabled by DIPSWITCH1
	if (GET_DIPSW(DIPSW1))
	{
		SetDebugMode(true);
		BUZZER_ON();
	}

	// Main loop
	while (1);

	return 0;
}

/*----------------------------------------------------------------------------*/
/**
* @brief    Timer interrupt handler for delay function reason
* @param    None
* @retval   None
*/
ISR(TIMER2_COMP_vect)
{
	DelayCounter--; 
	TemperatureTask();
}

/*----------------------------------------------------------------------------*/
/**
* @brief    Timer interrupt handler for system timer (1 ms)
* @param    None
* @retval   None
*/
ISR(TIMER0_COMP_vect)
{
	sei();	
	MainSystemTask();
	CtrlTask();
	RegulatorTask();			
	MultimeterTask();
}

/*----------------------------------------------------------------------------*/
void Wait_ms(uint16_t delay)
{
	DelayCounter = delay;

	while (DelayCounter > 0);
}

/******************* (C) COPYRIGHT 2011 HENIUS *************** END OF FILE ****/
