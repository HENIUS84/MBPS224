/**
 *******************************************************************************
 * @file     PSMMultimeter.c
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.1
 * @date     20-05-2011
 * @brief    Moduł pomiaru napięcia i natężenia prądu
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2011 HENIUS</center></h2>
 */

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <stdlib.h>

// --->Pliki użytkownika

#include "Multimeter.h"
#include "Hardware.h"
#include "ADC.h"
#include "AverageFilters.h"

/* Sekcja zmiennych ----------------------------------------------------------*/

Multimeter_t *MBData;				/*!< Struktura z wynikami pomiaru */
ADCChannel_t ADCchannelList[] =		/*!< Lista obsługiwanych kanałów */
{
	VOLTAGE_CHANNEL,				/*!< Kanał pomiaru napięcia */
	CURRENT_CHANNEL					/*!< Kanał pomiaru natężenia prądu */
};

/*! Filtr dolno-przepustowy napięcia */
AvgFilter1_t VoltageFilter[VOLTAGE_FILTER_ORDER];		
AvgFilter2_t VoltageAverageFilter;	/*!< Filtr uśredniający napięcie */
AvgFilter2_t VoltageAverageFilter2;
/*! Filtr dolno-przepustowy natężenia prądu */
AvgFilter1_t CurrentFilter[CURRENT_FILTER_ORDER];
AvgFilter2_t CurrentAverageFilter;	/*!< Filtr uśredniający natężenie prądu */
/*! Bufor danych przetwornika A/C */
uint16_t ADCbuffer[ADC_CHANNEL_AMOUNT];
/*! Bufor dla celów oversampling'u */
uint32_t ADCbufferOVS[ADC_CHANNEL_AMOUNT];
ADC_t ADCdata = 					/*!< Dane konfiguracyjne przetwornika A/C */
{
	.Mode          = ADCM_SINGLE,
	.SampleRate    = ADCSR_4800SPS,
	.Resolution    = ADCR_11BIT,
	.Vref          = ADCVR_AREF,
	.Buffer        = ADCbuffer,
	.OVSbuffer     = ADCbufferOVS,
	.ChannelAmount = ADC_CHANNEL_AMOUNT,
	.ChannelList   = ADCchannelList
};

/* Sekcja funkcji ------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
 * @brief    Funkcja obsługująca gotowość pomiaru ADC
 * @param    Brak
 * @retval   Brak
 */
void PSMmultimeter_ADCdataReady(void)
{	uint8_t idx;
	
	if (MBData)
	{
		// Konwersja danych ADC na napięcie i natężenie prądu (funkcja liniowa)
		// f(x) = (y1 - y2) / (x1 - x2) * (x - x1) + y1
		
		// Filtracja wartości ADC natężenia prądu
		MBData->Filtered.CurrentADC = !MBData->IsPowerOn ? 0 : ADCbuffer[1];
		for (idx = 0; idx < CURRENT_FILTER_ORDER; idx++)
		{
			CurrentFilter[idx].TimeConstant = 4;
			/*MBData->Filtered.CurrentADC =
				AverageFilter1(MBData->Filtered.CurrentADC, 
				              &CurrentFilter[idx]);*/
			MBData->Filtered.CurrentADC =
				AverageFilter2(MBData->Filtered.CurrentADC, 
							   &CurrentAverageFilter);
		}
		
		// Natężenie prądu - przeliczanie
		MBData->Unfiltered.Current =
			!MBData->IsPowerOn ? 0 : CALCULATE_CURRENT(ADCbuffer[1]);
		MBData->Filtered.Current = !MBData->IsPowerOn ?
			0 : CALCULATE_CURRENT(MBData->Filtered.CurrentADC);
								
		// Filtracja napięcia		
		MBData->Filtered.VoltageADC = !MBData->IsPowerOn ? 0 : ADCbuffer[0];
		for (idx = 0; idx < VOLTAGE_FILTER_ORDER; idx++)
		{
			VoltageFilter[idx].TimeConstant = 4;
			/*MBData->Filtered.VoltageADC =
				AverageFilter1(MBData->VoltageADC,
				               &VoltageFilter[idx]);*/	
			MBData->Filtered.VoltageADC =
				AverageFilter2(MBData->Filtered.VoltageADC,
				               &VoltageAverageFilter);
		}
			   
		// Napięcie (w mV) - przeliczanie
		MBData->Unfiltered.Voltage =
			!MBData->IsPowerOn ?
				0 : CALCULATE_VOLTAGE(ADCbuffer[0],
				                      MBData->Unfiltered.Current);
		MBData->Filtered.Voltage =
			!MBData->IsPowerOn ?
				0 : CALCULATE_VOLTAGE(MBData->Filtered.VoltageADC,
				                      MBData->Filtered.Current);
	}
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Żądanie kolejnego pomiaru
 * @param    Brak
 * @retval   Brak
 */
void Multimeter_ConvReq(void)
{
	ADC_StartConv();				// Rozpoczęcie kolejnego pomiaru ADC
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Inicjalizacja modułu pomiarowego
 * @param    *data : wskaźnik do struktury z wynikami multimetru
 * @retval   Brak
 */
void Multimeter_Init(Multimeter_t *data)
{
	MBData = data;					// Inicjalizacja
	// Inicjalizacja callback'a na zakończenie przetwarzania
	ADCdata.OnCompleted = PSMmultimeter_ADCdataReady;
	ADC_Init(&ADCdata);				// Inicjalizacja przetwornika A/C
}

/******************* (C) COPYRIGHT 2011 HENIUS *************** KONIEC PLIKU ***/