/**
 *******************************************************************************
 * @file     Multimeter.h
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.1
 * @date     20-05-2011
 * @brief    Moduł pomiaru napięcia i natężenia prądu (plik nagłówkowy)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2011 HENIUS</center></h2>
 */

#ifndef  MULTIMETER_H_
#define  MULTIMETER_H_

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <stdio.h>
#include <stdbool.h>

/* Sekcja stałych, makr i definicji ------------------------------------------*/

// --->Stałe
// Ustawienia pomiaru
/*! Kanał pomiaru napięcia */
#define VOLTAGE_CHANNEL		(ADCC_CH1)
/*! Kanał pomiaru natężenia prądu */
#define CURRENT_CHANNEL		(ADCC_CH0)
/*! Współczynnik skalowania napięcia */
#define VOLTAGE_SF			(100)
/*! Obliczanie spadku napięcia w mV na rezystorze pomiarowym natężenia prądu */
#define CRES_OFFSET(c)		(c * 15 / 100)
/*! Stopień filtru napięcia */
#define VOLTAGE_FILTER_ORDER	(10)
/*! Stopień filtru natężenia prądu */
#define CURRENT_FILTER_ORDER	(15)
/*! Liczba obsługiwanych kanałów przez moduł */
#define ADC_CHANNEL_AMOUNT	(sizeof(ADCchannelList) / sizeof(ADCChannel_t))

// --->Typy
/**
 * @brief Indeksy napisów
 */
typedef struct
{
	struct
	{
		uint16_t Voltage;			/*!< Zmierzone napięcie w mV */
		uint16_t Current;			/*!< Zmierzone natężenie prądu w mA */
		uint16_t VoltageADC;		/*!< Wartość ADC napięcia */
		uint16_t CurrentADC;		/*!< Wartość ADC natężenia prądu */
	}Filtered;						/*!< Wartości uśrednione */
	
	struct
	{
		uint16_t Voltage;			/*!< Zmierzone napięcie w mV */
		uint16_t Current;			/*!< Zmierzone natężenie prądu w mA */
	}Unfiltered;					/*!< Wartości nieuśrednione */
				
	/*! Flaga oznaczająca przekroczenie natężenia prądu */
	bool IsPowerOn;					
}Multimeter_t;

// Kalibracja pomiaru
 
// Napięcie

/*! Napięcie w mV (dane kalibracyjne  - min.) */
#define V_CALIB_MIN			(617UL)
/*! Napięcie - wartość ADC (dane kalibracyjne - min.) */
#define V_ADC_CALIB_MIN		(50)
/*! Napięcie w mV (dane kalibracyjne - maks.) */
#define V_CALIB_MAX 		(24000UL)
/*! Napięcie - wartość ADC (dane kalibracyjne - maks.) */
#define V_ADC_CALIB_MAX		(2038)
/*! Obliczanie wartości napięcia */
#define CALCULATE_VOLTAGE(ADCValue, CurrentValue) \
	(((V_CALIB_MAX - V_CALIB_MIN) * (int32_t)ADCValue + \
	V_ADC_CALIB_MAX * V_CALIB_MIN - V_ADC_CALIB_MIN * V_CALIB_MAX) / \
	(V_ADC_CALIB_MAX - V_ADC_CALIB_MIN) - CRES_OFFSET(CurrentValue))

// Natężenie prądu

/*! Natężenie prądu w mA(dane kalibracyjne - min.) */
#define C_CALIB_MIN 		(0UL)
/*! Natężenie prądu - wartość ADC (dane kalibracyjne - maks.) */
#define C_ADC_CALIB_MIN 	(0)
/*! Natężenie prądu w mA (dane kalibracyjne - maks.) */
#define C_CALIB_MAX 		(606UL)
/*! Natężenie prądu - wartość ADC (dane kalibracyjne - maks.) */
#define C_ADC_CALIB_MAX		(550)
/*! Obliczanie wartości napięcia */
#define CALCULATE_CURRENT(ADCValue) \
	(((C_CALIB_MAX - C_CALIB_MIN) * (int32_t)ADCValue + \
	C_ADC_CALIB_MAX * C_CALIB_MIN - C_ADC_CALIB_MIN * C_CALIB_MAX) / \
	(C_ADC_CALIB_MAX - C_ADC_CALIB_MIN))

/* Sekcja deklaracji ---------------------------------------------------------*/

// --->Funkcje
// Inicjalizacja modułu pomiarowego
void Multimeter_Init(Multimeter_t *data);
// Żądanie kolejnego pomiaru
void Multimeter_ConvReq(void);

#endif								/* MULTIMETER_H_ */

/******************* (C) COPYRIGHT 2011 HENIUS ************** KONIEC PLIKU ****/
