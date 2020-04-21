/**
 *******************************************************************************
 * @file     Hardware.c
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.2
 * @date     16/04/2014
 * @brief    Zestaw funkcji związanych z obsługą płyty głównej
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2014 HENIUS</center></h2>
 */

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <stdint.h>
#include <avr/io.h>
#include <avr/wdt.h>
#include <math.h>

// --->Pliki użytkownika

#include "Hardware.h"
#include "Utils.h"

/* Sekcja zmiennych ----------------------------------------------------------*/

uint16_t StatLedOnTime;             /*!< Czas świecenia diody statusowej */
uint16_t StatLedOffTime;            /*!< Czas nieświecenia diody statusowej */

/* Sekcja funkcji ------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
 * @brief    Ustawianie podświetlenia na zadaną wartość
 * @param    baclightValue: procentowa wartość podświetlenia
 * @retval   Brak
 */
void SetLcdBacklight(uint8_t backlightVal)
{
	// Ograniczenie
	LIMIT_VALUE(backlightVal, 100, 0);	
	
	// Ustawienie odpowiedniej wartości rejestru PWM
	LCD_BACKL_REG = backlightVal * LCD_BACKL_MAX / 100;  
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Ustawianie mocy wentylatora na zadaną wartość
 * @param    powerValue: procentowa wartość mocy
 * @retval   Brak
 */
void SetCoolerPower(uint8_t powerValue)
{	
	// Ograniczenie
	LIMIT_VALUE(powerValue, 100, 0);	
	
	// Ustawienie odpowiedniej wartości rejestru PWM
	COOLER_REG = (uint32_t)powerValue * COOLER_PWM_MAX / 100;
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Inicjalizacja podzespołów płyty głównej
 * @param    Brak
 * @retval   Brak
 */
void InitHardware(void)
{
	// Inicjalizacja
	
	// ---> Główny timer systemowy
	TCCR2 = _BV(WGM21);				// Tryb CTC
	TCCR2 |= SYS_TIMER_CS << CS20;	// Ustalanie prescalera
	OCR2 = SET_SYS_TIME();			// Ustalanie czasu przerwania
	TIMSK |= _BV(OCIE2);			// Przerwanie na odliczenie czasu

	// ---> Dipswitch
	DIPSW_DDR &= ~(DIPSW1 | DIPSW2 | DIPSW3);
	DIPSW_PORT |= DIPSW1 | DIPSW2 | DIPSW3;

	// --->Statusowa dioda led
	STAT_LED_DDR |= STAT_LED;
	STAT_LED_OFF();
	SetStatLedBlinking(STAT_LED_ON_TIME, STAT_LED_OFF_TIME);

	// --->Buzzer
	BUZZER_DDR |= BUZZER;
	BUZZER_OFF();

	// --->Podtrzymanie zasilania
	POWER_BTN_DDR |= POWER_BTN;
	POWER_BTN_ON();
	
	// --->Zmiana trybu zasilania
	SYM_MODE_DDR |= SYM_MODE;
	SYM_MODE_OFF();	

    // --->Wyświetlacz LCD i regulacja podświetlenia
    // Inicjalizacja pinu i PWM
    LCD_BACKL_DDR |= LCD_BACKL;
    TCCR0 |= _BV(WGM01) | _BV(WGM00) | 	// Fast PWM
			 _BV(COM01) | 				// Tryb nieodwracający
			 (LCD_BACKL_CS << CS00);    // Start timera
    // Ten timer będzie wykorzystany dla celów funkcji opóźniającej
    TIMSK |= _BV(TOIE0);
		
	// --->Regulacja obrotów wentylatora
	COOLER_DDR |= COOLER;
	TCCR3A |= _BV(WGM31) | _BV(WGM30) |	// Phase Correct - 10 bit
	          _BV(COM3A1);				// Tryb nieodwracający
	TCCR3B |= (COOLER_CS << CS30);		// Start timera
	SetCoolerPower(0);
	
	// --->Inicjalizacja watchdog'a
	wdt_enable(WDTO_2S);
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Funkcja zarządzania zasilaniem
 * @param    Brak
 * @retval   Brak
 */
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
	// Pośredni czas włączenia 
	double _onTime = round(onTime / SYS_TIME);
	// Pośredni czas wyłączenia
	double _offTime = round(offTime / SYS_TIME);
	
	StatLedOnTime = _onTime > 0  ? _onTime : onTime;
	StatLedOffTime = _offTime > 0  ? _offTime : offTime;
}

/******************* (C) COPYRIGHT 2014 HENIUS *************** KONIEC PLIKU ***/
