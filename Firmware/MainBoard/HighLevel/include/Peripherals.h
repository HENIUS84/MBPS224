/**
 *******************************************************************************
 * @file     ThermalController.h
 * @author   HENIUS (Pawe³ Witak)
 * @version  1.1.2
 * @date     09-01-2014
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

#include "PSMcontroller.h"
#include "OWIThermometer.h"
#include "ThermalController.h"
#include "Buttons.h"
#include "Audio.h"
#include "SerialPort.h"

/* Sekcja sta³ych, makr i definicji ------------------------------------------*/

// --->Sta³e

// Modu³ zasilacza
#define PSM_BASE_ID			(0x10)	/*!< Adres bazowy modu³ów po I2C */
/*! Rozmiar tablicy danych modu³ów (liczba 2 x wiêksza ni¿ liczba modu³ów */
#define PSM_TABLE_SIZE		(PS_MODULES_COUNT * 1)
/*! Liczba termometrów */
#define AMOUNT_OF_THERMOMETERS	(1)
/*! Domyœlna wartoœæ zadanego natê¿enia pr¹du */
#define DEFAULT_SET_CURRENT	(1000)

/* Sekcja deklaracji ---------------------------------------------------------*/

// --->Zmienne

// Dane pomiarowe modu³ów
extern PSMCData_t PSMData[PSM_TABLE_SIZE];
// Prêdkoœci komunikacji z modu³ami
extern CommSpeed_t CommunicationSpeed;
// Dane kontrolera temperatury 
extern ThermalData_t ThermalData;
// Kontroler obs³ugi termometrów na 1-Wire
extern OWIThermoCtrl_t ThermometerController;
// Kontroler portu szeregowego */
extern SPController_t SerialPortController;

// --->Funkcje

// Inicjalizacja peryferiów
void InitPeripherals(void);
// Pobieranie liczby pod³¹czonych modu³ów
uint8_t GetPSModulesNumber(void);
// Aktywacja/dezaktywacja modu³u zasilacza
void SetRegulator(bool isEnabled, uint8_t moduleNumber);

#endif								/* PERIPHERALS_H_ */

/******************* (C) COPYRIGHT 2013 HENIUS *************** KONIEC PLIKU ***/