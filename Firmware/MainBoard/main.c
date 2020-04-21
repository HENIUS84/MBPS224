/**
********************************************************************************
* @file     main.c
* @author   HENIUS (Paweł Witak)
* @version  1.1.2
* @date     15/11/2013
* @brief    Program obsługi płyty głównej zasilacza MBPS
* @mainpage
*           \section Intro Opis projektu
*           To jest projekt obsługi płyty głównej, który jest częścią
*           projektu zasilacza sterowanego mikrokontrolerem MBPS224.
*
*           Urządzenie składa się z dwóch głównych elementów:
*           - płyty głównej,
*           - modułu zasilacza.
*
*           Zadaniem głównej jest:
*           - komunikacja z modułami zasilacza za pomocą izolowanej magistrali
*             I2C,
*           - wizualiazacja pomiarów,
*           - wystawianiem nastaw dla modułów,
*           - komunikacja z komputerem PC.
*           \section DI Lista urządzeń
*           Niniejszy projekt został napisany dla mikrokontrolera ATmega32.
********************************************************************************
*
* <h2><center>COPYRIGHT 2010  HENIUS</center></h2>
*/

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <avr/wdt.h>
#include <util/delay_basic.h>

// --->Pliki użytkownika

#include "main.h"
#include "Menu.h"
#include "Debug.h"
#include "Tasks.h"
#include "Hardware.h"
#include "SerialPort.h"
#include "OWIMaster.h"
#include "GraphLib.h"
#include "KeyboardLib.h"
#include "SoundLib.h"
#include "Settings.h"
#include "Peripherals.h"

/* Sekcja zmiennych ----------------------------------------------------------*/

/*! Prescaler dla celów realizacji funkcji opóźniającej */
uint16_t DelTimerPresc = SET_DEL_TIME();
/*! Zmienna na potrzeby realizacji funkcji opóźniającej */
volatile int16_t DelayCounter = 0;	

/* Sekcja funkcji ------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
* @brief    Główna funkcja programu
* @param    Brak
* @retval   Brak
*/
int main(void)
{	
	// --->Inicjalizacja systemu
	
	InitHardware();					// Inicjalizacja głównych podzespołów
	KS0108LCD_Init();				// Inicjalizacja wyświetlacza
	// Inicjalizacja modułu graficznego
	InitGraphLib(KS0108LCD_SetPixel);	
	LoadSettings();					// Ładowanie ustawień
	sei();							// Aktywacja przerwań
	
	// Aktywacja trybu DEBUG
	if (GET_DIPSW(DIPSW1))			
	{
		SetDebugMode(true);
	}
	
	// Pokazanie ekranu początkowego
	if (GET_DIPSW(DIPSW2))			
	{
		ShowSplashScreen();
	}
	
	InitPeripherals();				// Inicjalizacja peryferiów
	
	
	// Aktywacja trybu zaawansowanego
	IsAdvancedMode = IsKeyPressed('L') && IsKeyPressed('R') ? true : false;
		
	// Główna pętla programu
	while (1)						
	{ 
		MenuHandler();
	}

	return 0;
}

/*----------------------------------------------------------------------------*/
/**
* @brief    Obsługa przerwania timera opóźnienia
* @param    Brak
* @retval   Brak
*/
ISR(TIMER0_OVF_vect)
{
	if (!--DelTimerPresc)
	{
		DelTimerPresc = SET_DEL_TIME();

		TemperatureTask();				// Zadanie obsługi temperatury		
		SystemPowerHandler();			// Obsługa podtrzymania zasilania
		DelayCounter--;
	}
}

/*----------------------------------------------------------------------------*/
/**
* @brief    Obsługa przerwania timera systemowego (1 ms)
* @param    Brak
* @retval   Brak
*/
ISR(TIMER2_COMP_vect)
{	
	sei();
	MainSystemTask();				// Główne zadanie systemowe
	KeyboardTask();					// Obsługa klawiatury
	SoundTask();					// Obsługa dźwięku	
	MenuKeysTask();					// Obsługa przycisków menu 
	PSMCtrlTask();					// Komunikacja z modułami zasilacza
	PSMLcdTask();					// Obsługa wyświetlacza
	ThermalControlTask();			// Kontrola temperatury
	PCCommunicationTask();			// Komunikacja z PC
}

/*----------------------------------------------------------------------------*/
/**
* @brief    Funkcja opóźniająca
* @param  	delay : opóźnienie w ms
* @retval   Brak
*/
void Wait_ms(uint16_t delay)
{
	DelayCounter = delay;

	while (DelayCounter > 0);
}

/******************* (C) COPYRIGHT 2010 HENIUS *************** KONIEC PLIKU ***/
