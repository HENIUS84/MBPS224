/**
 ******************************************************************************
 * @file     main.c                                                   
 * @author   HENIUS (Paweł Witak)                                      
 * @version  1.1.1                                                         
 * @date     03-04-2011                                                       
 * @brief    Program obsługi modułu zasilacza
 * @mainpage
 *           \section Intro Opis projektu
 *           To jest projekt obsługi modułu zasilacza, który jest częścią
 *           projektu zasilacza sterowanego mikrokontrolerem MBPS224.
 *
 *           Urządzenie składa się z dwóch głównych elementów:
 *           - płyty głównej,
 *           - modułu zasilacza.
 *
 *           Zadaniem modułu zasilacza jest:
 *           - regulacja napięcia i natężenia prądu,
 *           - pomiar temperatury stabilizatora,
 *           - pomiar napięcia i natężenia prądu,
 *           - komunikacja z płytą główną za pomocą izolowanej magistrali I2C.
 *           \section DI Lista urządzeń
 *           Niniejszy projekt został napisany dla mikrokontrolera ATmega32.
 *
 ******************************************************************************
 *
 * <h2><center>COPYRIGHT 2011 HENIUS</center></h2>
 */

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <stdio.h>
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>

// --->Pliki użytkownika

#include "Tasks.h"
#include "main.h"
#include "SerialPort.h"
#include "I2CSlave.h"
#include "ADC.h"
#include "Debug.h"
#include "Hardware.h"

/* Sekcja zmiennych ----------------------------------------------------------*/

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
	// Inicjalizacja systemu
	InitPeripherals_();				// Inicjalizacja peryferiów
	sei();							// Aktywacja przerwań	
	InitTasks();					// Inicjalizacja zadań		
	ADC_StartConv();				// Inicjalizacja modułu pomiarowego

	// Aktywacja trybu DEBUG
	if (GET_DIPSW(DIPSW1))
	{
		SetDebugMode(true);
		BUZZER_ON();
	}

	// Główna pętla programu
	while (1);

	return 0;
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Obsługa przerwania timera opóźnienia (1 ms)
 * @param    Brak
 * @retval   Brak
 */
ISR(TIMER2_COMP_vect)
{
	DelayCounter--; 
	TemperatureTask();			// Zadanie pomiaru temperatury stabilizatora
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Obsługa przerwania timera systemowego (1 ms)
 * @param    Brak
 * @retval   Brak
 */
ISR(TIMER0_COMP_vect)
{
	sei();	
	MainSystemTask();				// Główne zadanie systemowe
	CtrlTask();						// Zadanie komunikacji z płytą główną	
	// Zadanie regulacji napięcia i natężenia prądu
	RegulatorTask();			
	MultimeterTask();				// Zadanie obsługi pomiarów
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Funkcja opóźniająca
 * @param  	 delay : opóźnienie w ms
 * @retval   Brak
 */
void Wait_ms(uint16_t delay)
{
	DelayCounter = delay;

	while (DelayCounter > 0);
}

/******************* (C) COPYRIGHT 2011 HENIUS *************** KONIEC PLIKU ***/
