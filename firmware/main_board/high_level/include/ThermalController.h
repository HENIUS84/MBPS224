/**
 *******************************************************************************
 * @file     ThermalController.h
 * @author   HENIUS (Pawe³ Witak)
 * @version  1.1.1
 * @date     25-01-2013
 * @brief    Service of temperature management (header file)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

#ifndef  THERMAL_CONTROLLER_H_
#define  THERMAL_CONTROLLER_H_

/* Include section -----------------------------------------------------------*/

// --->System files
#include <stdint.h>
#include <stdbool.h>

/* Macros, constants and definitions section ---------------------------------*/

// --->Types

/**
 * @brief Type of data supporting by controller
 */
typedef struct  
{
	int16_t *BoardTemperature;		/*!< Current main board temperature */
	/*! Module temperatures */
	bool IsOverheat[PS_MODULES_COUNT];
	int16_t *MaxTemperature;		/*!< Max. temperature */
	int16_t *TempHisteresis;		/*!< Temperature hysteresis */
	bool *IsTempProtEnabled;		/*!< Thermal protection flag */
	/*! Pointer to the function for regulator activation/deactivation */
	void (*EnableRegulator)(bool isEnabled, uint8_t moduleNumber);
	/*! Pointer tot he function managing of cooler */
	void (*SetCooler)(uint8_t power);
}ThermalData_t;

/* Declaration section -------------------------------------------------------*/

// --->Functions

/*----------------------------------------------------------------------------*/
/**
* @brief    Initializes the controller
* @param    *data : pointer to the controller data
* @retval   None
*/
void ThermalCtrl_Init(ThermalData_t *data);

/*----------------------------------------------------------------------------*/
/**
* @brief    Controller handler
* @param    None
* @retval   None
*/
void ThermalCtrl_Handler(void);

#endif								/* THERMAL_CONTROLLER_H_ */

/******************* (C) COPYRIGHT 2013 HENIUS *************** END OF FILE ****/
