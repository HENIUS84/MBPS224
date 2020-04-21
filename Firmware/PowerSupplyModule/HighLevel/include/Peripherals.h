/**
 *******************************************************************************
 * @file     ThermalController.h
 * @author   HENIUS (Pawe� Witak)
 * @version  1.1.1
 * @date     25-01-2013
 * @brief    Obs�uga peryferi�w (plik nag��wkowy)
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

// --->Pliki u�ytkownika

#include "MBController.h"
#include "Multimeter.h"
#include "Regulator.h"
#include "OWIThermometer.h"

/* Sekcja sta�ych, makr i definicji ------------------------------------------*/

#define AMOUNT_OF_THERMOMETERS	(1)	/*!< Liczba termometr�w */

/* Sekcja deklaracji ---------------------------------------------------------*/

// --->Zmienne

// Kontroler komunikacji z p�yt� g��wn�
extern MBController_t MBCommController;
// Dane regulatora
extern PSMreg_t PSMReg;				
// Struktura ze wska�nikami dla multimetru
extern Multimeter_t Multimeter;
// Kontroler obs�ugi termometr�w */
extern OWIThermoCtrl_t ThermometerController;	

// --->Funkcje

// Inicjalizacja peryferi�w
void InitPeripherals_(void);

#endif								/* PERIPHERALS_H_ */

/******************* (C) COPYRIGHT 2013 HENIUS *************** KONIEC PLIKU ***/