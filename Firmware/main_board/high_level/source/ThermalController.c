/**
 *******************************************************************************
 * @file     ThermalController.c
 * @author   HENIUS (Pawe³ Witak)
 * @version  1.1.1
 * @date     25-01-2013
 * @brief    Service of temperature management
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdint.h>
#include <avr/io.h>

// --->User files

#include "ThermalController.h"

/* Variable section ----------------------------------------------------------*/

/*! Pointer to the controller data */
static ThermalData_t *MBData;

/* Function section ----------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
void ThermalCtrl_Init(ThermalData_t *data)
{
	MBData = data;
}

/*----------------------------------------------------------------------------*/
void ThermalCtrl_Handler(void)
{
	int16_t minTemp = 0;
	
	if (MBData &&
	    MBData->EnableRegulator &&
		MBData->SetCooler &&
		MBData->TempHisteresis &&
		MBData->MaxTemperature &&
		MBData->IsTempProtEnabled) 
	{
		minTemp = *MBData->MaxTemperature - *MBData->TempHisteresis;
		
		if (*MBData->BoardTemperature >= *MBData->MaxTemperature ||
		    MBData->IsOverheat[0] || MBData->IsOverheat[1])
		{
			MBData->SetCooler(100);
		}
		else if (*MBData->BoardTemperature <= minTemp &&
		         !MBData->IsOverheat[0] && !MBData->IsOverheat[1])
			MBData->SetCooler(0);
	}
}

/******************* (C) COPYRIGHT 2013 HENIUS *************** END OF FILE ****/
