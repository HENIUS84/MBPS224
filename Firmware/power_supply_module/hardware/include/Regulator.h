/**
 *******************************************************************************
 * @file     Regulator.h
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.2
 * @date     24-05-2014
 * @brief    Voltage and current regulator of PS module (header file)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2014 HENIUS</center></h2>
 */

#ifndef  REGULATOR_H_
#define  REGULATOR_H_

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdbool.h>
#include <stdint.h>

/* Macros, constants and definitions section ---------------------------------*/

// Regulator activation
#define SC_EN_PORT			(PORTB)	/*!< Output register of regulator */
#define SC_EN_DDR			(DDRB)  /*!< Direction register of regulator */
#define SC_EN_PIN			(PINB)	/*!< Input register of regulator */
#define SC_EN				(_BV(4))/*!< Bit mask of regulator */
/*! Macro to activate the regulator */
#define VREG_ON()			(PORTB &= ~SC_EN)
/*! Macro to deactivate regulator */
#define VREG_OFF()			(PORTB |= SC_EN)

// Voltage regulator - PWM channel
#define PS_PWM_PORT			(PORTD)	/*!< Output register of PWM pin */
#define PS_PWM_DDR			(DDRD)	/*!< Direction register of PWM pin */
#define PS_PWM_PIN			(PIND)	/*!< Output register of PWM pin */
#define PS_PWM				(_BV(5))/*!< Bit mask of PWM pin */
#define PS_PWM_REG			(OCR1A)	/*!< PWM register of voltage regulator */
#define PS_PWM_RES			(10)	/*!< PWM resolution */

// Calibration data of regulator
/*! Voltage in mV (calibration data - min.) */
#define VREG_CALIB_MIN		(600)
/*! Voltage in mV (calibration data - max.) */
#define VREG_CALIB_MAX		(24000)
/*! Voltage - PWM value (calibration data - max.) */
#define VREG_PWM_CALIB_MAX	(1023)
#define VOLTAGE_MULTIPLIER	(100)	/*! Voltage multiplier */

#define MAX_CURRENT_LIMIT	(100)	/*!< Limit of overcurrents */

/* Declaration section -------------------------------------------------------*/

// --->Types

/**
 * @brief Data for regulator support (pointers)
 */
typedef struct 
{
	uint16_t Unused;				/*!< Unused */
	uint16_t SetVoltage;			/*!< Set voltage value */
	uint16_t SetCurrent;			/*!< Set current value */
	uint16_t Current;				/*!< Measured current value */
	uint16_t Temperature;			/*!< Temperature of regulator */
	uint16_t MaxTemperature;		/*!< Max. temperature */
	uint16_t TempHisteresis;		/*!< Temperature hysteresis */
	bool ManualMode;				/*!< Manual mode flag */
	uint32_t SoftStartTime;			/*!< Soft-start time (in ms) */	
	bool IsPowerOn;					/*!< Activation flag of regulator */
	bool IsOvercurrent;				/*!< Overcurrent flag */
	bool IsOverheat;				/*!< Overheat flag */	
	bool IsTempProtectionEnabled;	/*!< Thermal protection flag */			
}PSMreg_t;

// --->Functions

/*----------------------------------------------------------------------------*/
/**
 * @brief    Initializes the voltage and current regulator of module
 * @param    *psmReg : pointer to the regulator
 * @retval   None
 */
void Regulator_Init(PSMreg_t *psmReg);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Voltage and current regulator handler
 * @param    None
 * @retval   None
 */
void Regulator_Handler(void);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Activation/deactivation of the regulator
 * @param    isEnabled : activation flag
 * @retval   None
 */
void Regulator_TurnOnOff(bool isEnabled);

#endif								/* REGULATOR_H_ */

/******************* (C) COPYRIGHT 2014 HENIUS ************** END OF FILE ****/
