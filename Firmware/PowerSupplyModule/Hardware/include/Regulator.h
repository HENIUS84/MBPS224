/**
 *******************************************************************************
 * @file     Regulator.h
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.2
 * @date     24-05-2014
 * @brief    Regulator napięcia i prądu modułu zasilacza (plik nagłówkowy)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2014 HENIUS</center></h2>
 */

#ifndef  REGULATOR_H_
#define  REGULATOR_H_

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <stdbool.h>
#include <stdint.h>

/* Sekcja stałych, makr i definicji ------------------------------------------*/

// Aktywacja stabilizatora
#define SC_EN_PORT			(PORTB)	/*!< Rejestr wyjściowy stabilizatora */
#define SC_EN_DDR			(DDRB)  /*!< Rejestr kierunkowy stabilizatora */
#define SC_EN_PIN			(PINB)	/*!< Rejestr wejściowy stabilizatora */
#define SC_EN				(_BV(4))/*!< Maska pinu stabilizatora */
/*! Makro włączania stabilizatora */
#define VREG_ON()			(PORTB &= ~SC_EN)
/*! Makro wyłączania stabilizatora */
#define VREG_OFF()			(PORTB |= SC_EN)

// Regulacja napięcia - kanał PWM
#define PS_PWM_PORT			(PORTD)	/*!< Rejestr wyjściowy PWM zasilacza */
#define PS_PWM_DDR			(DDRD)	/*!< Rejestr kierunkowy PWM zasilacza */
#define PS_PWM_PIN			(PIND)	/*!< Rejestr wyjściowy PWM zasilacza */
#define PS_PWM				(_BV(5))/*!< Maska pinu PWM zasilacza */
#define PS_PWM_REG			(OCR1A)	/*!< Rejestr PWM dla regulacji napięcia */
#define PS_PWM_RES			(10)	/*!< Rozdzielczość bitowa PWM */

// Dane kalibracyjne regulatora
/*! Napięcie w mV (dane kalibracyjne - min.) */
#define VREG_CALIB_MIN		(600)
/*! Napięcie w mV (dane kalibracyjne - maks.) */
#define VREG_CALIB_MAX		(24000)
/*! Napięcie - wartość PWM (dane kalibracyjne - maks.) */
#define VREG_PWM_CALIB_MAX	(1023)
#define VOLTAGE_MULTIPLIER	(100)	/*! Mnożnik napięcia */

#define MAX_CURRENT_LIMIT	(100)	/*!< Limit przekroczeń natężenia prądu */

/* Sekcja deklaracji ---------------------------------------------------------*/

// --->Zmienne

// --->Typy

/**
 * @brief Dane potrzebne do działania regulatora (wskaźniki do zmiennych)
 */
typedef struct 
{
	uint16_t Unused;				/*!< Nieużywana zmienna */
	uint16_t SetVoltage;			/*!< Zadana wartość napięcia */
	uint16_t SetCurrent;			/*!< Zadane natężenie prądu */
	uint16_t Current;				/*!< Zmierzona wartość natężenia prądu */
	uint16_t Temperature;			/*!< Temperatra stabilizatora */
	uint16_t MaxTemperature;		/*!< Maksymalna temperatura */
	uint16_t TempHisteresis;		/*!< Histereza temperatury */
	bool ManualMode;				/*!< Flaga oznaczajaca tryb manualny */
	uint32_t SoftStartTime;			/*!< Czas łagodnego startu (w ms) */
	/*! Flaga oznaczajaca właczenie stabilizatora */
	bool IsPowerOn;		
	/*! Flaga oznaczajaca przekroczenie dopuszczalnej wartości nat. prądu */
	bool IsOvercurrent;		
	/*! Flaga oznaczajaca przekroczenie dopuszczalnej wartości temperatury */
	bool IsOverheat;		
	bool IsTempProtectionEnabled;	/*!< Flaga zabezpieczenia temperaturowego */			
}PSMreg_t;

// --->Funkcje
// Inicjalizacja regulatora napięcia i natężenia prądu modułu
void Regulator_Init(PSMreg_t *psmReg);
// Funkcja obsługi regulatora napięcia
void Regulator_Handler(void);
// Aktywacja/dezaktywacja stabilizatora napięcia
void Regulator_TurnOnOff(bool isEnabled);
extern uint16_t maxCurrent;
#endif								/* REGULATOR_H_ */

/******************* (C) COPYRIGHT 2014 HENIUS ************** KONIEC PLIKU ****/
