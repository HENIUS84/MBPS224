/**
 *******************************************************************************
 * @file     Bitmaps.h                                                      
 * @author   HENIUS (Paweł Witak)                                              
 * @version  1.1.1                                                          
 * @date     28-04-2012                                                 
 * @brief    Deklaracje obrazków (plik nagłówkowy)                                 
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2012 HENIUS</center></h2>
 */

#ifndef  BITMAPS_H_
#define  BITMAPS_H_

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe
#include <stdint.h>
#include <stdbool.h>

/* Sekcja stałych, makr i definicji ------------------------------------------*/

/* Sekcja deklaracji ---------------------------------------------------------*/

extern uint8_t SplashScreen1[];				// Obraz Splash Screen'a #1				   
extern uint8_t SplashScreen2[];				// Obraz Splash Screen'a #2
extern uint8_t SettingsIcon[];				// Ikona ustawień 
extern uint8_t GeneralSettingsIcon[];		// Ikona ustawień ogólnych
extern uint8_t PSsettingsIcon[];			// Ikona ustawień zasilacza
extern uint8_t AboutIcon[];					// Ikona informacji o programie
extern uint8_t PCConnectionImage[];			// Obraz podczas połączenia z PC

#endif								/* BITMAPS_H_ */

/******************* (C) COPYRIGHT 2011 HENIUS *************** KONIEC PLIKU ***/
