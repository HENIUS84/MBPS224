/**
 *******************************************************************************
 * @file     Multimeter.h
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.1
 * @date     20-05-2011
 * @brief    Module of voltage and current measurements (header file)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2011 HENIUS</center></h2>
 */

#ifndef  MULTIMETER_H_
#define  MULTIMETER_H_

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdio.h>
#include <stdbool.h>

/* Macros, constants and definitions section ---------------------------------*/

// --->Constants

// Measurement settings


#define VOLTAGE_CHANNEL		(ADCC_CH1)		/*!< Voltage ADC channel */
#define CURRENT_CHANNEL		(ADCC_CH0)		/*!< Current ADC channel */
#define VOLTAGE_SF			(100)			/*!< Voltage scaling factor */
/*! Calculation of the voltage drop in mV on the current measuring resistor */
#define CRES_OFFSET(c)		(c * 15 / 100)
#define VOLTAGE_FILTER_ORDER	(10)		/*!< Voltage filter order */
#define CURRENT_FILTER_ORDER	(15)		/*!< Current filter order */
/*! Count of channels supported by module */
#define ADC_CHANNEL_AMOUNT	(sizeof(ADCchannelList) / sizeof(ADCChannel_t))

// --->Types

/**
 * @brief Measurement data structure
 */
typedef struct
{
	struct
	{
		uint16_t Voltage;					/*!< Measured voltage in mV */
		uint16_t Current;					/*!< Measured current in mA */
		uint16_t VoltageADC;				/*!< ADC value of voltage */
		uint16_t CurrentADC;				/*!< ADC value of current */
	}Filtered;								/*!< Filtered values */
	
	struct
	{
		uint16_t Voltage;					/*!< Measured voltage in mV */
		uint16_t Current;					/*!< Measured current in mA */
	}Unfiltered;							/*!< Unfiltered values */
				
	bool IsPowerOn;							/*!< Module power state flag */				
}Multimeter_t;

// Measurement calibration
 
// Voltage

/*! Voltage in mV (calibration data  - min.) */
#define V_CALIB_MIN			(617UL)
/*! Voltage - ADC value (calibration data - min.) */
#define V_ADC_CALIB_MIN		(50)
/*! Voltage in mV (calibration data - max.) */
#define V_CALIB_MAX 		(24000UL)
/*! Voltage - ADC value (calibration data - max.) */
#define V_ADC_CALIB_MAX		(2038)
/*! Voltage value calculation */
#define CALCULATE_VOLTAGE(ADCValue, CurrentValue) \
	(((V_CALIB_MAX - V_CALIB_MIN) * (int32_t)ADCValue + \
	V_ADC_CALIB_MAX * V_CALIB_MIN - V_ADC_CALIB_MIN * V_CALIB_MAX) / \
	(V_ADC_CALIB_MAX - V_ADC_CALIB_MIN) - CRES_OFFSET(CurrentValue))

// Current

/*! Current in mA (calibration data - min.) */
#define C_CALIB_MIN 		(0UL)
/*! Current - ADC value (calibration data - max.) */
#define C_ADC_CALIB_MIN 	(0)
/*! Current in mA (calibration data - max.) */
#define C_CALIB_MAX 		(606UL)
/*! Current - ADC value (calibration data - max.) */
#define C_ADC_CALIB_MAX		(550)
/*! Current value calculation */
#define CALCULATE_CURRENT(ADCValue) \
	(((C_CALIB_MAX - C_CALIB_MIN) * (int32_t)ADCValue + \
	C_ADC_CALIB_MAX * C_CALIB_MIN - C_ADC_CALIB_MIN * C_CALIB_MAX) / \
	(C_ADC_CALIB_MAX - C_ADC_CALIB_MIN))

/* Declaration section -------------------------------------------------------*/

// --->Functions

/*----------------------------------------------------------------------------*/
/**
 * @brief    Initializes multimeter module
 * @param    *data : pointer to te measured data
 * @retval   None
 */
void Multimeter_Init(Multimeter_t *data);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Request of next measurement
 * @param    None
 * @retval   None
 */
void Multimeter_ConvReq(void);

#endif								/* MULTIMETER_H_ */

/******************* (C) COPYRIGHT 2011 HENIUS *************** END OF FILE ****/
