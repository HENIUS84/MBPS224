/**
  ******************************************************************************
  * @file     main.h
  * @author   HENIUS (Paweł Witak)
  * @version  1.1.2
  * @date     15/11/2013
  * @brief    Główny plik nagłówkowy
  ******************************************************************************
  * 
  * <h2><center>COPYRIGHT 2010 HENIUS</center></h2>
  */

#ifndef MAIN_H
#define MAIN_H

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe
#include <avr/io.h>

/* Sekcja stałych, makr i definicji ------------------------------------------*/

// --->Stałe

// Obsługa prescalerów
/*! Prescaler dla okresu 1 s */
#define SYS_PRESC_1s		(1000 / SYS_TIME)
/*! Prescaler dla okresu 10 ms */
#define SYS_PRESC_10ms		(10 / SYS_TIME)
/*! Prescaler dla okresu 5 ms */
#define SYS_PRESC_5ms		(5 / SYS_TIME)
/*! Prescaler dla okresu 100 ms */
#define SYS_PRESC_100ms		(100 / SYS_TIME)
/*! Prescaler dla timera komunikacji z modułami zasilacza */
#define PSM_PRESC			(20 / SYS_TIME)

/* Sekcja deklaracji ---------------------------------------------------------*/

// Funkcja opóźniająca w ms
void Wait_ms(uint16_t delay);

#endif								/* MAIN_H */

/******************* (C) COPYRIGHT 2010 HENIUS *************** KONIEC PLIKU ***/
