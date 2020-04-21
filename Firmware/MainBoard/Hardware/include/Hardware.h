/**
 *******************************************************************************
 * @file     Hardware.h
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

// --->Pliki użytkownika

#include "Tasks.h"
#include "KS0108LCD.h"

/* Sekcja stałych, makr i definicji ------------------------------------------*/

// Dipswitch
#define DIPSW_PORT	   		(PORTD)		/*!< Rejestr wyjściowy dipswitch'a */
#define DIPSW_DDR       	(DDRD)		/*!< Rejestr kierunkowy dipswitch'a */
#define DIPSW_PIN       	(PIND)		/*!< Rejestr wejściowy dipswitch'a */
#define DIPSW1 				(_BV(5))	/*!< Maska DIPS1 */
#define DIPSW2 				(_BV(4))	/*!< Maska DIPS2 */
#define DIPSW3 				(_BV(3))	/*!< Maska DIPS3 */
/*! Makro pobierania stanu pinu dipswitch'a */
#define GET_DIPSW(number)	(!(DIPSW_PIN & number))

//Dioda statusowa LED
#define STAT_LED_PORT	 	(PORTA)		/*!< Rejestr wyjściowy diody */
#define STAT_LED_DDR       	(DDRA)		/*!< Rejestr kierunkowy diody */
#define STAT_LED_PIN       	(PINA)		/*!< Rejestr wejściowy diody */
#define STAT_LED 	       	(_BV(5))	/*!< Maska pinu diody */
/*! Makro zapalania diody */
#define STAT_LED_ON()		(STAT_LED_PORT &= ~STAT_LED)
/*! Makro gaszenia diody */
#define STAT_LED_OFF()		(STAT_LED_PORT |= STAT_LED)
/*! Makro zmiany świecenia diody */
#define STAT_LED_TOGGLE()	(STAT_LED_PORT ^= STAT_LED)
/*! Makro mrugania diodą */
#define STAT_LED_ON_TIME	(100)		/*!< Czas wł. diody statusowej w ms */
#define STAT_LED_OFF_TIME	(600)		/*!< Czas wył. diody statusowej w ms */

// Buzzer
#define BUZZER_PORT			(PORTE)		/*!< Rejestr wyjściowy buzzera */
#define BUZZER_DDR			(DDRE)		/*!< Rejestr kierunkowy buzzera */
#define BUZZER_PIN			(PINE)		/*!< Rejestr wejściowy buzzera */
#define BUZZER				(_BV(2))	/*!< Maska pinu buzzera */
/*! Makro włączania buzzera */
#define BUZZER_ON()			(BUZZER_PORT &= ~BUZZER)
/*! Wyłączanie buzzera */
#define BUZZER_OFF()		(BUZZER_PORT |= BUZZER)
/*! Zmiana stanu buzzera */
#define BUZZER_TOGGLE()		(BUZZER_PORT ^= BUZZER)

// Obsługa regulacji podświetlenia LCD
#define LCD_BACKL_PORT      (PORTB) /*!< Port pinu do ściemniania LCD */
#define LCD_BACKL_DDR       (DDRB)  /*!< Rejestr kierunkowy sygnału
                                         ściemniania LCD */
#define LCD_BACKL_PIN       (PINB)  /*!< Rejestr wejściowy sygnału
                                         ściemniania LCD */
#define LCD_BACKL           (_BV(4))/*!< Maska pinu ściemniania LCD */
#define LCD_BACKL_REG       (OCR0)  /*!< Rejestr PWM dla dimmera LCD */
#define LCD_BACKL_MAX       (255)   /*!< Maksymalna wartość w rejestrze PWM 
                                         wyświetlacza */

// Prescaler
#define LCD_PRESC_0			(0)		/*!< Brak sygnału dla timera */
#define LCD_PRESC_1			(1)     /*!< Prescaler /1 */
#define LCD_PRESC_8			(2)     /*!< Prescaler /8 */
#define LCD_PRESC_64		(3)     /*!< Prescaler /64 */
#define LCD_PRESC_256		(4)     /*!< Prescaler /256 */
#define LCD_PRESC_1024		(5)     /*!< Prescaler /1024 */
#define LCD_BACKL_PRESC		(1)		/*!< Prescaler timera PWM dla LCD */
/*! Wartość bitów CS (prescalera) timera PWM dla LCD */
#define LCD_BACKL_CS		(LCD_PRESC_1)

// Wentylator
#define COOLER_PORT			(PORTE)	/*!< Port pinu wentylatora */
#define COOLER_DDR			(DDRE)	/*!< Rejestr kierunkowy pinu wentylatora */
#define COOLER_PIN			(PINE)	/*!< Rejestr wejściowy pinu wentylatora */
#define COOLER				(_BV(3))/*!< Maska pinu wentylatora */
#define COOLER_REG			(OCR3A)	/*!< Rejestr PWM dla wentylatora */
/*! Maksymalna wartość w rejestrze PWM dla wentylatora */
#define COOLER_PWM_MAX		(1023)	

// Prescaler
#define COOLER_PRESC_0		(0)		/*!< Brak sygnału dla timera */
#define COOLER_PRESC_1		(1)     /*!< Prescaler /1 */
#define COOLER_PRESC_8		(2)     /*!< Prescaler /8 */
#define COOLER_PRESC_64		(3)     /*!< Prescaler /64 */
#define COOLER_PRESC_256	(4)     /*!< Prescaler /256 */
#define COOLER_PRESC_1024	(5)     /*!< Prescaler /1024 */
/*! Wartość bitów CS (prescalera) timera PWM dla wentylatora */
#define COOLER_CS			(COOLER_PRESC_64)

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
/*! Wartość bitów CS (prescalera) timera opóźnienia */
#define SYS_TIMER_CS	    (TIMS_PRESC_256)
/*! Obliczanie wartości rejestru OCR dla zapewnienia czasu */
#define SET_SYS_TIME()     	(((F_CPU / SYS_TIMER_PRESC) * SYS_TIME) / 1000 - 1)

// Timer dla realizacji funkcji opóźnienia
/*! Czas przerwania timera opóźnienia w ms */
#define DEL_TIME			(1)
/*! Rozdzielczość timera */
#define DEL_TIMER_RES		(8)
/*! Obliczanie wartości zmiennej prescalera dla zapewnienia czasu */
#define SET_DEL_TIME() \
	(F_CPU / LCD_BACKL_PRESC / (1 << DEL_TIMER_RES) * DEL_TIME / 1000 - 1)

// Obsługa podtrzymania zasilania
// Pin wyłączający zasilanie
#define POWER_OFF_PORT		(PORTA)
#define POWER_OFF_DDR		(DDR)
#define POWER_OFF_PIN		(PINA)
#define POWER_OFF			(_BV(2))

// Pin podtrzymujący
#define POWER_BTN_PORT     	(PORTA) /*!< Port pinu podtrzymującego */
#define POWER_BTN_DDR      	(DDRA)  /*!< Rejestr kierunkowy pinu
                                         podtrzymującego */
#define POWER_BTN_PIN      	(PINA)  /*!< Rejestr wejściowy pinu
                                         podtrzymującego*/
#define POWER_BTN          	(_BV(1))/*!< Maska pinu podtrzymującego */
#define POWER_BTN_TIME     	(1)     /*!< Czas sygnału podtrzymującego w ms */
/*! Makro ustawiania pinu podtrzymywania zasilania */
#define POWER_BTN_ON() 		(POWER_BTN_PORT |= POWER_BTN)
/*! Makro zerowania pinu podtrzymywania zasilania */
#define POWER_BTN_OFF() 	(POWER_BTN_PORT &= ~POWER_BTN)
/*! Makro zmiany stanu pinu podtrzymywania zasilania */
#define POWER_BTN_TOGGLE() 	(POWER_BTN_PORT ^= POWER_BTN)

// Pin przekaźnika trybu symetrycznego zasilania
#define SYM_MODE_PORT     	(PORTA) /*!< Port pinu trybu symetrycznego */
#define SYM_MODE_DDR      	(DDRA)  /*!< Rejestr kierunkowy pinu
                                         trybu symetrycznego */
#define SYM_MODE_PIN      	(PINA)  /*!< Rejestr wejściowy pinu
                                         trybu symetrycznego*/
#define SYM_MODE          	(_BV(0))/*!< Maska pinu trybu symetrycznego */
/*! Makro ustawiania pinu trybu symetrycznego zasilania */
#define SYM_MODE_ON() 		(SYM_MODE_PORT &= ~SYM_MODE)
/*! Makro zerowania pinu trybu symetrycznego zasilania */
#define SYM_MODE_OFF() 		(SYM_MODE_PORT |= SYM_MODE)
/*! Makro zmiany stanu pinu trybu symetrycznego zasilania */
#define SYM_MODE_TOGGLE() 	(SYM_MODE_PORT ^= SYM_MODE)

/* Sekcja deklaracji ---------------------------------------------------------*/

// Czas świecenia diody statusowej
extern uint16_t StatLedOnTime;
// Czas nieświecenia diody statusowej
extern uint16_t StatLedOffTime;
// Temperatura płytki
extern int16_t MainBoardTemp;
// Ustawianie podświetlenia na zadaną wartość
void SetLcdBacklight(uint8_t baclightValue);
// Ustawianie mocy wentylatora na zadaną wartość
void SetCoolerPower(uint8_t powerValue);
// Inicjalizacja podzespołów płyty głównej
void InitHardware(void);
// Funkcja obsługi migania diodą statusową
void StatLedHandler();
// Funkcja ustawiająca czasy migania diody statusowej
void SetStatLedBlinking(uint16_t onTime, uint16_t offTime);
// Funkcja zarządzania zasilaniem
void SystemPowerHandler();

#endif								/* HARDWARE_H */

/******************* (C) COPYRIGHT 2010 HENIUS *************** KONIEC PLIKU ***/
