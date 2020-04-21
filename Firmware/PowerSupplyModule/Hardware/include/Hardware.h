/**
 *******************************************************************************
 * @file     PSMHardware.h
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.1
 * @date     19/11/2010
 * @brief    Zestaw funkcji związanych z obsługą płyty głównej
 *           (plik nagłówkowy)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2010 HENIUS</center></h2>
 */

#ifndef  HARDWARE_H
#define  HARDWARE_H

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <stdint.h>
#include <stdio.h>

// --->Pliki użytkownika

#include "MBController.h"
#include "Multimeter.h"
#include "Regulator.h"
#include "OWIThermometer.h"

/* Sekcja stałych, makr i definicji ------------------------------------------*/

#define PSM_ID_BASE			(0x10)	/*!< Sprzętowy adres bazowy modułu */

// Dipswitch
#define DIPSW_PORT	   		(PORTB) /*!< Rejestr wyjściowy dipswitch'a */
#define DIPSW_DDR       	(DDRB)  /*!< Rejestr kierunkowy dipswitch'a */
#define DIPSW_PIN       	(PINB)  /*!< Rejestr wejściowy dipswitch'a */
#define DIPSW1 				(_BV(1))/*!< Maska DIPS1 */
#define DIPSW2 				(_BV(2))/*!< Maska DIPS2 */
#define DIPSW3 				(_BV(3))/*!< Maska DIPS3 */
/*! Makro pobierania stanu pinu dipswitch'a */
#define GET_DIPSW(number)	(!(DIPSW_PIN & number))
/*! Makro pobierania adresu modułu wybranego na dipswitch'u */
#define GET_MODULE_ADDR()	(GET_DIPSW(DIPSW2) ? 1 : 0)

// Dioda statusowa LED
#define STAT_LED_PORT	   	(PORTC) /*!< Rejestr wyjściowy diody */
#define STAT_LED_DDR       	(DDRC)  /*!< Rejestr kierunkowy diody */
#define STAT_LED_PIN       	(PINC)  /*!< Rejestr wejściowy diody */
#define STAT_LED 	        (_BV(6))/*!< Maska pinu diody */
/*! Makro zapalania diody */
#define STAT_LED_ON()		(STAT_LED_PORT &= ~STAT_LED)
/*! Makro gaszenia diody */
#define STAT_LED_OFF()		(STAT_LED_PORT |= STAT_LED)
/*! Makro zmiany świecenia diody */
#define STAT_LED_TOGGLE()	(STAT_LED_PORT ^= STAT_LED)
#define STAT_LED_ON_TIME	(100)	/*!< Czas wł. diody statusowej w ms */
#define STAT_LED_OFF_TIME	(600)	/*!< Czas wył. diody statusowej w ms */

// Buzzer
#define BUZZER_PORT			(PORTB)	/*!< Rejestr wyjściowy buzzera */
#define BUZZER_DDR			(DDRB)	/*!< Rejestr kierunkowy buzzera */
#define BUZZER_PIN			(PINB)	/*!< Rejestr wejściowy buzzera */
#define BUZZER				(_BV(0))/*!< Maska pinu buzzera */
/*! Makro włączania buzzera */
#define BUZZER_ON()			(BUZZER_PORT &= ~BUZZER)
/*! Wyłączanie buzzera */
#define BUZZER_OFF()		(BUZZER_PORT |= BUZZER)
/*! Zmiana stanu buzzera */
#define BUZZER_TOGGLE()		(BUZZER_PORT ^= BUZZER)

// Timer systemowy
// Prescaler
#define TIMS_PRESC_0		(0)		/*!< Brak sygnału dla timera */
#define TIMS_PRESC_1		(1)     /*!< Prescaler /1 */
#define TIMS_PRESC_8		(2)     /*!< Prescaler /8 */
#define TIMS_PRESC_64		(3)     /*!< Prescaler /64 */
#define TIMS_PRESC_256		(4)     /*!< Prescaler /256 */
#define TIMS_PRESC_1024		(5)     /*!< Prescaler /1024 */

/*! Prescaler timera systemowego */
#define SYS_TIMER_PRESC		(256)
/*! Wartość bitów CS (prescalera) timera systemowego */
#define SYS_TIMER_CS	    (TIMS_PRESC_256)
/*! Obliczanie wartości rejestru OCR dla zapewnienia czasu */
#define SET_SYS_TIME()     	(F_CPU / SYS_TIMER_PRESC * SYS_TIME / 1000 - 1)

// Timer realizujący funkcję opóźnienia
// Prescaler
#define TIMD_PRESC_0		(0)		/*!< Brak sygnału dla timera */
#define TIMD_PRESC_1		(1)     /*!< Prescaler /1 */
#define TIMD_PRESC_8		(2)     /*!< Prescaler /8 */
#define TIMD_PRESC_32		(3)     /*!< Prescaler /32 */
#define TIMD_PRESC_64		(4)     /*!< Prescaler /64 */
#define TIMD_PRESC_128		(5)     /*!< Prescaler /128 */
#define TIMD_PRESC_256		(6)     /*!< Prescaler /256*/
#define TIMD_PRESC_1024		(7)     /*!< Prescaler /1024 */

/*! Czas przerwania timera opóźnienia w ms */
#define DEL_TIME			(1)
/*! Prescaler timera opóźnienia */
#define DEL_TIMER_PRESC		(256)
/*! Wartość bitów CS (prescalera) timera opóźnienia */
#define DEL_TIMER_CS	    (TIMD_PRESC_256)
/*! Obliczanie wartości rejestru OCR dla zapewnienia czasu */
#define SET_DEL_TIME()     	(F_CPU / DEL_TIMER_PRESC * DEL_TIME / 1000 - 1)

// Multimetr
#define CURRENT_AMP_LOW		(1)		/*!< Niskie wzocnienie natężenia prądu */
#define CURRENT_AMP_HIGH	(2)		/*!< Wysokie wzmocnienie natężenia prądu */

/* Sekcja deklaracji ---------------------------------------------------------*/

// --->Funkcje

void InitHardware(void);			// Inicjalizacja podzespołów płyty głównej
// Funkcja obsługi migania diodą statusową
void StatLedHandler();
// Funkcja ustawiająca czasy migania diody statusowej
void SetStatLedBlinking(uint16_t onTime, uint16_t offTime);   

#endif								/* HARDWARE_H */

/******************* (C) COPYRIGHT 2010 HENIUS *************** KONIEC PLIKU ***/
