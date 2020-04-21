/**
 *******************************************************************************
 * @file     ThermalController.h
 * @author   HENIUS (Pawe� Witak)
 * @version  1.1.2
 * @date     09-01-2014
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

#include "PSMcontroller.h"
#include "OWIThermometer.h"
#include "ThermalController.h"
#include "Buttons.h"
#include "Audio.h"
#include "SerialPort.h"

/* Sekcja sta�ych, makr i definicji ------------------------------------------*/

// --->Sta�e

// Modu� zasilacza
#define PSM_BASE_ID			(0x10)	/*!< Adres bazowy modu��w po I2C */
/*! Rozmiar tablicy danych modu��w (liczba 2 x wi�ksza ni� liczba modu��w */
#define PSM_TABLE_SIZE		(PS_MODULES_COUNT * 1)
/*! Liczba termometr�w */
#define AMOUNT_OF_THERMOMETERS	(1)
/*! Domy�lna warto�� zadanego nat�enia pr�du */
#define DEFAULT_SET_CURRENT	(1000)

/* Sekcja deklaracji ---------------------------------------------------------*/

// --->Zmienne

// Dane pomiarowe modu��w
extern PSMCData_t PSMData[PSM_TABLE_SIZE];
// Pr�dko�ci komunikacji z modu�ami
extern CommSpeed_t CommunicationSpeed;
// Dane kontrolera temperatury 
extern ThermalData_t ThermalData;
// Kontroler obs�ugi termometr�w na 1-Wire
extern OWIThermoCtrl_t ThermometerController;
// Kontroler portu szeregowego */
extern SPController_t SerialPortController;

// --->Funkcje

// Inicjalizacja peryferi�w
void InitPeripherals(void);
// Pobieranie liczby pod��czonych modu��w
uint8_t GetPSModulesNumber(void);
// Aktywacja/dezaktywacja modu�u zasilacza
void SetRegulator(bool isEnabled, uint8_t moduleNumber);

#endif								/* PERIPHERALS_H_ */

/******************* (C) COPYRIGHT 2013 HENIUS *************** KONIEC PLIKU ***/