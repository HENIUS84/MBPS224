/**
 *******************************************************************************
 * @file     main.h                                                   
 * @author   HENIUS (Paweł Witak)                                      
 * @version  1.1.1                                                         
 * @date     04-04-2011                                                       
 * @brief    Program obsługi modułu zasilacza (plik nagłówkowy)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2011 HENIUS</center></h2>
 */

#ifndef MAIN_H_
#define MAIN_H_

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <stdint.h>

// --->Pliki użytkownika

#include "Peripherals.h"

/* Sekcja stałych, makr i definicji ------------------------------------------*/

// --->Stałe

// Obsługa prescalerów
/*! Prescaler dla okresu 1 s */
#define SYS_PRESC_1s		(1000 / SYS_TIME)	
/*! Prescaler dla okresu 10 ms */
#define SYS_PRESC_10ms		(10 / SYS_TIME)
/*! Prescaler dla multimetru */
#define MULTIMETER_PRESC	(5 / SYS_TIME)

#define START_DELAY			(1000)	/*!< Opóźnienie startu systemu (w ms) */

/* Sekcja deklaracji ---------------------------------------------------------*/

// Funkcja opóźniająca w ms
void Wait_ms(uint16_t delay);

#endif 										/* MAIN_H_ */

/******************* (C) COPYRIGHT 2011 HENIUS *************** KONIEC PLIKU ***/
