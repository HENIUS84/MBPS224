/**
 *******************************************************************************
 * @file     Peripherals.h
 * @author   HENIUS (Pawe³ Witak)
 * @version  1.1.2
 * @date     09-01-2014
 * @brief    Peripherals driver (header file)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

#ifndef  PERIPHERALS_H_
#define  PERIPHERALS_H_

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdint.h>
#include <stdbool.h>

// --->User files

#include "PSMcontroller.h"
#include "OWIThermometer.h"
#include "ThermalController.h"
#include "Buttons.h"
#include "Audio.h"
#include "SerialPort.h"

/* Macros, constants and definitions section ---------------------------------*/

// --->Constants

// Modu³ zasilacza
#define PSM_BASE_ID			(0x10)	/*!< Adres bazowy modu³ów po I2C */
/*! Rozmiar tablicy danych modu³ów (liczba 2 x wiêksza ni¿ liczba modu³ów */
#define PSM_TABLE_SIZE		(PS_MODULES_COUNT * 1)
/*! Liczba termometrów */
#define AMOUNT_OF_THERMOMETERS	(1)
/*! Domyœlna wartoœæ zadanego natê¿enia pr¹du */
#define DEFAULT_SET_CURRENT	(1000)

/* Declaration section -------------------------------------------------------*/

// --->Zmienne

/*! Measurement data of modules */
extern PSMCData_t PSMData[PSM_TABLE_SIZE];
/*! Module communication speed */
extern CommSpeed_t CommunicationSpeed;
/*! Data of thermometer controller */
extern ThermalData_t ThermalData;
/*! Controller of 1-Wire thermometers */
extern OWIThermoCtrl_t ThermometerController;
/*! Serial port controller structure */
extern SPController_t SerialPortController;

// --->Functions

/*----------------------------------------------------------------------------*/
/**
* @brief    Peripherals initialization
* @param    *peripherals : pointer to the peripheral structure
* @retval   None
*/
void InitPeripherals(void);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Gets nu number of connected modules
 * @param    None
 * @retval   Number of connected modules
 */
uint8_t GetPSModulesNumber(void);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Activation/deactivation of power supply module
 * @param    isEnabled : activation flag
 * @param    moduleNumber : module index
 * @retval   None
 */
void SetRegulator(bool isEnabled, uint8_t moduleNumber);

#endif								/* PERIPHERALS_H_ */

/******************* (C) COPYRIGHT 2013 HENIUS *************** END OF FILE ****/
