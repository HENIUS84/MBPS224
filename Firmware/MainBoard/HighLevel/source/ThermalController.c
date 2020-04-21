/**
 *******************************************************************************
 * @file     ThermalController.c
 * @author   HENIUS (Pawe³ Witak)
 * @version  1.1.1
 * @date     25-01-2013
 * @brief    Obs³uga zarz¹dzania temperatur¹
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <stdint.h>
#include <avr/io.h>

// --->Pliki u¿ytkownika

#include "ThermalController.h"

/* Sekcja zmiennych ----------------------------------------------------------*/

ThermalData_t *MBData;					/*!< WskaŸnik do danych kontrolera */

/* Sekcja funkcji ------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
* @brief    Inicjalizacja kontrolera
* @param    *data : wskaŸnik do danych kontrolera
* @retval   Brak
*/
void ThermalCtrl_Init(ThermalData_t *data)
{
	MBData = data;
}

/*----------------------------------------------------------------------------*/
/**
* @brief    Funkcja obs³ugi kontrolera
* @param    Brak
* @retval   Brak
*/
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
		
		// Czy temperatura zosta³a przekroczona?
		if (*MBData->BoardTemperature >= *MBData->MaxTemperature ||
		    MBData->IsOverheat[0] || MBData->IsOverheat[1])
		{
			// Przekroczenie temperatury
			MBData->SetCooler(100);
		}
		else if (*MBData->BoardTemperature <= minTemp &&
		         !MBData->IsOverheat[0] && !MBData->IsOverheat[1])
			// Wy³¹czanie wiatraka
			MBData->SetCooler(0);
	}
}

/******************* (C) COPYRIGHT 2013 HENIUS *************** KONIEC PLIKU ***/