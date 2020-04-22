/**
 *******************************************************************************
 * @file     ThermalController.h
 * @author   HENIUS (Pawe³ Witak)
 * @version  1.1.1
 * @date     25-01-2013
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

#include "MBController.h"
#include "Multimeter.h"
#include "Regulator.h"
#include "OWIThermometer.h"

/* Macros, constants and definitions section ---------------------------------*/

#define AMOUNT_OF_THERMOMETERS	(1)					/*!< Count of thermometers */

/* Declaration section -------------------------------------------------------*/

// --->Vaiables

/*! Controller of communication with main board */
extern MBController_t MBCommController;
extern PSMreg_t PSMReg;						/*!< Regulator data */
extern Multimeter_t Multimeter;				/*!< Data structure for multimeter*/
/*! Thermometers controller */
extern OWIThermoCtrl_t ThermometerController;	

// --->Functions

//*----------------------------------------------------------------------------*/
/**
* @brief    Initializes peripherals
* @param    None
* @retval   None
*/
void InitPeripherals_(void);

#endif								/* PERIPHERALS_H_ */

/******************* (C) COPYRIGHT 2013 HENIUS *************** END OF FILE ****/
