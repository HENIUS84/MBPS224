/**
 ******************************************************************************
 * @file     PSMHardware.c                                                  
 * @author   HENIUS (Paweł Witak)                                             
 * @version  1.1.1                                                         
 * @date     04/12/2010                                                       
 * @brief    Zestaw funkcji związanych z obsługą płyty głównej                
 ******************************************************************************
 *
 * <h2><center>COPYRIGHT 2010 HENIUS</center></h2>
 */

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <stdio.h>
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>

// --->Pliki użytkownika

#include "Hardware.h"
#include "SerialPort.h"
#include "I2CSlave.h"
#include "Multimeter.h"
#include "Regulator.h"
#include "OWIMaster.h"

/* Sekcja zmiennych ----------------------------------------------------------*/

uint16_t StatLedOnTime;             /*!< Czas świecenia diody statusowej */
uint16_t StatLedOffTime;            /*!< Czas nieświecenia diody statusowej */

/* Sekcja funkcji ------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
 * @brief    Inicjalizacja podzespołów płyty głównej
 * @param    Brak
 * @retval   Brak
 */
void InitHardware(void)
{
	// Inicjalizacja
	// 
	// ---> Główny timer systemowy
	TCCR0 = _BV(WGM01);				// Tryb CTC
	TCCR0 |= SYS_TIMER_CS << CS00;	// Ustalanie prescalera
	OCR0 = SET_SYS_TIME();			// Ustalanie czasu przerwania
	TIMSK = _BV(OCIE0);				// Przerwanie na odliczenie czasu

	// ---> Timer dla realizacji opóźnienia
	TCCR2 = _BV(WGM21);				// Tryb CTC
	TCCR2 |= DEL_TIMER_CS << CS20;	// Ustalanie prescalera
	OCR2 = SET_DEL_TIME();			// Ustalanie czasu przerwania
	TIMSK |= _BV(OCIE2);			// Przerwanie na odliczenie czasu

	// ---> Buzzer
	BUZZER_DDR |= BUZZER;
	BUZZER_PORT |= BUZZER;

	// ---> Dipswitch
	DIPSW_DDR &= ~(DIPSW1 | DIPSW2 | DIPSW3);
	DIPSW_PORT |= DIPSW1 | DIPSW2 | DIPSW3;

	// ---> Statusowa dioda led
	STAT_LED_DDR |= STAT_LED;
	STAT_LED_OFF();
	SetStatLedBlinking(STAT_LED_ON_TIME, STAT_LED_OFF_TIME);
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Funkcja obsługi migania diodą statusową
 * @param    Brak
 * @retval   Brak
 */
void StatLedHandler()
{
	// Timer diody (załączenie)
	static uint16_t ledOnTimer = 1;
	// Timer diody (wyłączenie)       
	static uint16_t ledOffTimer = 1;
	
	// --->Mruganie diodą statusową
	if (StatLedOffTime)
	{
		if (!--ledOnTimer)
		{
			STAT_LED_OFF();		// Dioda zgaszona
			ledOnTimer = 0;
		}
	}
	
	if (StatLedOnTime)
	{
		if (!--ledOffTimer)
		{
			STAT_LED_ON();		// Dioda zapalona
			ledOffTimer = StatLedOnTime + StatLedOffTime;
			ledOnTimer = StatLedOnTime;
		}
	}
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Funkcja ustawiająca czasy migania diody statusowej
 * @param    onTime: czas świecenia diody (w ms)
 * @param    offTime: czas nieświecenia (w ms)
 * @retval   Brak
 */
void SetStatLedBlinking(uint16_t onTime, uint16_t offTime)
{
	StatLedOnTime = onTime;
	StatLedOffTime = offTime;
}

/******************* (C) COPYRIGHT 2010 HENIUS *************** KONIEC PLIKU ***/
