/**
 *******************************************************************************
 * @file     Buttons.c
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.1
 * @date     04-02-2012
 * @brief    Obsługa przycisków (plik nagłówkowy)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2012 HENIUS</center></h2>
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <avr/io.h>

/* Sekcja stałych, makr i definicji ------------------------------------------*/

// Piny przycisków
// Przycisk 1
#define KBD1_PORT	   		(PORTE) /*!< Rejestr wyjściowy KBD1 */
#define KBD1_DDR       		(DDRE)  /*!< Rejestr kierunkowy KBD1 */
#define KBD1_PIN       		(PINE)  /*!< Rejestr wejściowy KBD1 */
#define KBD1				(_BV(7))/*!< Maska pinu KBD1 */
// Przycisk 2
#define KBD2_PORT	   		(PORTE) /*!< Rejestr wyjściowy KBD2 */
#define KBD2_DDR       		(DDRE)  /*!< Rejestr kierunkowy KBD2 */
#define KBD2_PIN       		(PINE)  /*!< Rejestr wejściowy KBD2 */
#define KBD2				(_BV(6))/*!< Maska pinu KBD2 */
// Przycisk 3
#define KBD3_PORT	   		(PORTE) /*!< Rejestr wyjściowy KBD3 */
#define KBD3_DDR       		(DDRE)  /*!< Rejestr kierunkowy KBD3 */
#define KBD3_PIN       		(PINE)  /*!< Rejestr wejściowy KBD3 */
#define KBD3				(_BV(5))/*!< Maska pinu KBD3 */
// Przycisk 4
#define KBD4_PORT	   		(PORTE) /*!< Rejestr wyjściowy KBD4 */
#define KBD4_DDR       		(DDRE)  /*!< Rejestr kierunkowy KBD4 */
#define KBD4_PIN       		(PINE)  /*!< Rejestr wejściowy KBD4 */
#define KBD4				(_BV(4))/*!< Maska pinu KBD4 */

/* Sekcja deklaracji ---------------------------------------------------------*/		

// --->Funkcje
// 
// Inicjalizacja obsługi przycisków
void Buttons_Init(void);
// Funkcja obsługi przycisków
uint16_t Buttons_Handler(void);

#endif								/* BUTTONS_H_ */

/******************* (C) COPYRIGHT 2012 HENIUS ************** KONIEC PLIKU ****/
