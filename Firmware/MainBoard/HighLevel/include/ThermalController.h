/**
 *******************************************************************************
 * @file     ThermalController.h
 * @author   HENIUS (Pawe³ Witak)
 * @version  1.1.1
 * @date     25-01-2013
 * @brief    Obs³uga zarz¹dzania temperatur¹ (plik nag³ówkowy)
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

/* Sekcja sta³ych, makr i definicji ------------------------------------------*/

// --->Typy

/**
 * @brief Typ danych obs³ugiwanych przez kontroler
 */
typedef struct  
{
	int16_t *BoardTemperature;		/*!< Aktualne temperatura p³yty g³ównej */
	/*! Temperatury modu³ów */
	bool IsOverheat[PS_MODULES_COUNT];
	int16_t *MaxTemperature;		/*!< Temperatura progowa */
	int16_t *TempHisteresis;		/*!< Histereza temperatura */
	bool *IsTempProtEnabled;		/*!< Flaga zebezpieczenia temperaturowego */
	/*! WskaŸnik do funkcji w³¹czaj¹cej/wy³¹czaj¹cej regulator */
	void (*EnableRegulator)(bool isEnabled, uint8_t moduleNumber);
	/*! WskaŸnik do funkcji zarz¹dzaj¹cej wiatrakiem */
	void (*SetCooler)(uint8_t power);
}ThermalData_t;

/* Sekcja deklaracji ---------------------------------------------------------*/

// --->Funkcje

// Inicjalizacja kontrolera
void ThermalCtrl_Init(ThermalData_t *data);
// Funkcja obs³ugi kontrolera
void ThermalCtrl_Handler(void);

#endif								/* THERMAL_CONTROLLER_H_ */

/******************* (C) COPYRIGHT 2013 HENIUS *************** KONIEC PLIKU ***/