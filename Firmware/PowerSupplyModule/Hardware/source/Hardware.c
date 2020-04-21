/**
 ******************************************************************************
 * @file     PSMHardware.c                                                  
 * @author   HENIUS (Paweł Witak)                                             
 * @version  1.1.1                                                         
 * @date     04/12/2010                                                       
 * @brief    Functions of PS module hardware                
 ******************************************************************************
 *
 * <h2><center>COPYRIGHT 2010 HENIUS</center></h2>
 */

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdio.h>
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>

// --->User files

#include "Hardware.h"
#include "SerialPort.h"
#include "I2CSlave.h"
#include "Multimeter.h"
#include "Regulator.h"
#include "OWIMaster.h"

/* Variable section ----------------------------------------------------------*/

static uint16_t StatLedOnTime;				/*!< On time of status LED */
static uint16_t StatLedOffTime;				/*!< Off time of status LED */

/* Function section ----------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
void InitHardware(void)
{
	// --->Main system timer
	TCCR0 = _BV(WGM01);				// CTC mode
	TCCR0 |= SYS_TIMER_CS << CS00;
	OCR0 = SET_SYS_TIME();
	TIMSK = _BV(OCIE0);

	// --->Delay timer
	TCCR2 = _BV(WGM21);				// Tryb CTC
	TCCR2 |= DEL_TIMER_CS << CS20;
	OCR2 = SET_DEL_TIME();
	TIMSK |= _BV(OCIE2);

	// --->Buzzer
	BUZZER_DDR |= BUZZER;
	BUZZER_PORT |= BUZZER;

	// --->Dipswitch
	DIPSW_DDR &= ~(DIPSW1 | DIPSW2 | DIPSW3);
	DIPSW_PORT |= DIPSW1 | DIPSW2 | DIPSW3;

	// --->Status LED
	STAT_LED_DDR |= STAT_LED;
	STAT_LED_OFF();
	SetStatLedBlinking(STAT_LED_ON_TIME, STAT_LED_OFF_TIME);
}

/*----------------------------------------------------------------------------*/
void StatLedHandler()
{
	static uint16_t ledOnTimer = 1;
	static uint16_t ledOffTimer = 1;
	
	if (StatLedOffTime)
	{
		if (!--ledOnTimer)
		{
			STAT_LED_OFF();
			ledOnTimer = 0;
		}
	}
	
	if (StatLedOnTime)
	{
		if (!--ledOffTimer)
		{
			STAT_LED_ON();
			ledOffTimer = StatLedOnTime + StatLedOffTime;
			ledOnTimer = StatLedOnTime;
		}
	}
}

/*----------------------------------------------------------------------------*/
void SetStatLedBlinking(uint16_t onTime, uint16_t offTime)
{
	StatLedOnTime = onTime;
	StatLedOffTime = offTime;
}

/******************* (C) COPYRIGHT 2010 HENIUS *************** END OF FILE ****/
