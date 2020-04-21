/**
 *******************************************************************************
 * @file     PSMMultimeter.c
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.1
 * @date     20-05-2011
 * @brief    Module of voltage and current measurements
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2011 HENIUS</center></h2>
 */

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdlib.h>

// --->User files

#include "Multimeter.h"
#include "Hardware.h"
#include "ADC.h"
#include "AverageFilters.h"

/* Variable section ----------------------------------------------------------*/

static Multimeter_t *MBData;				/*!< Measured data structure */
static ADCChannel_t ADCchannelList[] =		/*!< List of supported ADC channels */
{
	VOLTAGE_CHANNEL,						/*!< Voltage channel */
	CURRENT_CHANNEL							/*!< Current channel */
};

/*! LPF for voltage */
static AvgFilter1_t VoltageFilter[VOLTAGE_FILTER_ORDER];		
static AvgFilter2_t VoltageAverageFilter;	/*!< Average filter of voltage #1 */
static AvgFilter2_t VoltageAverageFilter2;	/*!< Average filter of voltage #2 */
/*! LPF for current */
static AvgFilter1_t CurrentFilter[CURRENT_FILTER_ORDER];
static AvgFilter2_t CurrentAverageFilter;	/*!< Average filter of current */
/*! Data buffer of ADC */
static uint16_t ADCbuffer[ADC_CHANNEL_AMOUNT];
/*! Oversampling buffer */
static uint32_t ADCbufferOVS[ADC_CHANNEL_AMOUNT];
static ADC_t ADCdata = 						/*!< ADC configuration data */
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

/* Function section ----------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
 * @brief    ADC data ready handler
 * @param    None
 * @retval   None
 */
static void PSMmultimeter_ADCdataReady(void)
{	
	uint8_t idx;
	
	if (MBData)
	{
		// ADC value to voltage and current conversion (line function)
		// f(x) = (y1 - y2) / (x1 - x2) * (x - x1) + y1
		
		// Current ADC value filtration
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
		
		// Current calculation
		MBData->Unfiltered.Current =
			!MBData->IsPowerOn ? 0 : CALCULATE_CURRENT(ADCbuffer[1]);
		MBData->Filtered.Current = !MBData->IsPowerOn ?
			0 : CALCULATE_CURRENT(MBData->Filtered.CurrentADC);
								
		// Voltage filtration		
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
			   
		// Voltage (in mV) calculation
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
void Multimeter_ConvReq(void)
{
	ADC_StartConv();
}

/*----------------------------------------------------------------------------*/
void Multimeter_Init(Multimeter_t *data)
{
	MBData = data;
	ADCdata.OnCompleted = PSMmultimeter_ADCdataReady;
	ADC_Init(&ADCdata);
}

/******************* (C) COPYRIGHT 2011 HENIUS *************** END OF FILE ****/
