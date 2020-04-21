/**
 *******************************************************************************
 * @file     ThermalController.h
 * @author   HENIUS (Pawe� Witak)
 * @version  1.1.1
 * @date     25-01-2013
 * @brief    Obs�uga zarz�dzania temperatur� (plik nag��wkowy)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

#ifndef  THERMAL_CONTROLLER_H_
#define  THERMAL_CONTROLLER_H_

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe
#include <stdint.h>
#include <stdbool.h>

/* Sekcja sta�ych, makr i definicji ------------------------------------------*/

// --->Typy

/**
 * @brief Typ danych obs�ugiwanych przez kontroler
 */
typedef struct  
{
	int16_t *BoardTemperature;		/*!< Aktualne temperatura p�yty g��wnej */
	/*! Temperatury modu��w */
	bool IsOverheat[PS_MODULES_COUNT];
	int16_t *MaxTemperature;		/*!< Temperatura progowa */
	int16_t *TempHisteresis;		/*!< Histereza temperatura */
	bool *IsTempProtEnabled;		/*!< Flaga zebezpieczenia temperaturowego */
	/*! Wska�nik do funkcji w��czaj�cej/wy��czaj�cej regulator */
	void (*EnableRegulator)(bool isEnabled, uint8_t moduleNumber);
	/*! Wska�nik do funkcji zarz�dzaj�cej wiatrakiem */
	void (*SetCooler)(uint8_t power);
}ThermalData_t;

/* Sekcja deklaracji ---------------------------------------------------------*/

// --->Funkcje

// Inicjalizacja kontrolera
void ThermalCtrl_Init(ThermalData_t *data);
// Funkcja obs�ugi kontrolera
void ThermalCtrl_Handler(void);

#endif								/* THERMAL_CONTROLLER_H_ */

/******************* (C) COPYRIGHT 2013 HENIUS *************** KONIEC PLIKU ***/