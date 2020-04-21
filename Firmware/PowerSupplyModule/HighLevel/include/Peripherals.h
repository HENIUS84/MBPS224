/**
 *******************************************************************************
 * @file     ThermalController.h
 * @author   HENIUS (Pawe³ Witak)
 * @version  1.1.1
 * @date     25-01-2013
 * @brief    Obs³uga peryferiów (plik nag³ówkowy)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

#ifndef  PERIPHERALS_H_
#define  PERIPHERALS_H_

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <stdint.h>
#include <stdbool.h>

// --->Pliki u¿ytkownika

#include "MBController.h"
#include "Multimeter.h"
#include "Regulator.h"
#include "OWIThermometer.h"

/* Sekcja sta³ych, makr i definicji ------------------------------------------*/

#define AMOUNT_OF_THERMOMETERS	(1)	/*!< Liczba termometrów */

/* Sekcja deklaracji ---------------------------------------------------------*/

// --->Zmienne

// Kontroler komunikacji z p³yt¹ g³ówn¹
extern MBController_t MBCommController;
// Dane regulatora
extern PSMreg_t PSMReg;				
// Struktura ze wskaŸnikami dla multimetru
extern Multimeter_t Multimeter;
// Kontroler obs³ugi termometrów */
extern OWIThermoCtrl_t ThermometerController;	

// --->Funkcje

// Inicjalizacja peryferiów
void InitPeripherals_(void);

#endif								/* PERIPHERALS_H_ */

/******************* (C) COPYRIGHT 2013 HENIUS *************** KONIEC PLIKU ***/