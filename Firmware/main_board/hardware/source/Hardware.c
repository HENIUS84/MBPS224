/**
 *******************************************************************************
 * @file     Hardware.c
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.2
 * @date     16/04/2014
 * @brief    Files of main board hardware
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2014 HENIUS</center></h2>
 */

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdint.h>
#include <avr/io.h>
#include <avr/wdt.h>
#include <math.h>

// --->User files

#include "Hardware.h"
#include "Utils.h"

/* Variable section ----------------------------------------------------------*/

uint16_t StatLedOnTime;
uint16_t StatLedOffTime;

/* Function section ----------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
void SetLcdBacklight(uint8_t backlightVal)
{
	LIMIT_VALUE(backlightVal, 100, 0);
	LCD_BACKL_REG = backlightVal * LCD_BACKL_MAX / 100;  
}

/*----------------------------------------------------------------------------*/
void SetCoolerPower(uint8_t powerValue)
{	
	LIMIT_VALUE(powerValue, 100, 0);
	COOLER_REG = (uint32_t)powerValue * COOLER_PWM_MAX / 100;
}

/*----------------------------------------------------------------------------*/
void InitHardware(void)
{
	// Initialization
	
	// ---> Main system timer
	TCCR2 = _BV(WGM21);				// CTC mode
	TCCR2 |= SYS_TIMER_CS << CS20;	// Prescaler
	OCR2 = SET_SYS_TIME();			// Interrupt time
	TIMSK |= _BV(OCIE2);			// Interrupt mode

	// ---> Dipswitch
	DIPSW_DDR &= ~(DIPSW1 | DIPSW2 | DIPSW3);
	DIPSW_PORT |= DIPSW1 | DIPSW2 | DIPSW3;

	// --->Status LED
	STAT_LED_DDR |= STAT_LED;
	STAT_LED_OFF();
	SetStatLedBlinking(STAT_LED_ON_TIME, STAT_LED_OFF_TIME);

	// --->Buzzer
	BUZZER_DDR |= BUZZER;
	BUZZER_OFF();

	// --->Power backup
	POWER_BTN_DDR |= POWER_BTN;
	POWER_BTN_ON();
	
	// --->Zmiana trybu zasilaniaSymmetric mode
	SYM_MODE_DDR |= SYM_MODE;
	SYM_MODE_OFF();	

    // --->LCD support
    // LCD dimmer pin
    LCD_BACKL_DDR |= LCD_BACKL;
    TCCR0 |= _BV(WGM01) | _BV(WGM00) | 	// Fast PWM
			 _BV(COM01) | 				// Mode
			 (LCD_BACKL_CS << CS00);    // Timer start
    // This timer is also for delay function support
    TIMSK |= _BV(TOIE0);
		
	// --->FAN coontroller
	COOLER_DDR |= COOLER;
	TCCR3A |= _BV(WGM31) | _BV(WGM30) |	// Phase Correct - 10 bit
	          _BV(COM3A1);				// Mode
	TCCR3B |= (COOLER_CS << CS30);		// Timer start
	SetCoolerPower(0);
	
	// --->Watchdog
	wdt_enable(WDTO_2S);
}

/*----------------------------------------------------------------------------*/
void SystemPowerHandler()
{
	// Timer obsługi zasilania
	static uint16_t powerBtnTimer = 1;
	
	// --->Generowanie przebiegu podtrzymującego zasilanie
	if (!--powerBtnTimer)
	{
		POWER_BTN_TOGGLE();
		powerBtnTimer = POWER_BTN_TIME;
	}
}

/*----------------------------------------------------------------------------*/
void StatLedHandler()
{
	// LED timer (turning on)
	static uint16_t ledOnTimer = 1;
	// LED timer (turning of)       
	static uint16_t ledOffTimer = 1;
	
	// --->Status LED blinking
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
	// Temp LED on time
	double _onTime = round(onTime / SYS_TIME);
	// Temp LED of time
	double _offTime = round(offTime / SYS_TIME);
	
	StatLedOnTime = _onTime > 0  ? _onTime : onTime;
	StatLedOffTime = _offTime > 0  ? _offTime : offTime;
}

/******************* (C) COPYRIGHT 2014 HENIUS *************** END OF FILE ****/
