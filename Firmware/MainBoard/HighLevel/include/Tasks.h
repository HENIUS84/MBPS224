/**
 *******************************************************************************
 * @file     Tasks.h
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.1
 * @date     19/11/2010
 * @brief    Zestaw zadań obsugiwanych przez płytę główną (plik nagłówkowy)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2010 HENIUS</center></h2>
 */

#ifndef  TASKS_H
#define  TASKS_H

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <stdint.h>
#include <stdio.h>

// --->Pliki użytkownika

#include "PSMcontroller.h"

/* Sekcja stałych, makr i definicji ------------------------------------------*/

// --->Makra

/*! Makro zwracające czas zadania */
#define GET_TIME(interval) \
	(!(interval / SYS_TIME) ? SYS_TIME : (interval / SYS_TIME))

// --->Stałe

// Czasy powtarzania zadań (w ms)

/*! Czas zadania obsługi wyświetlacza */
#define LCD_TASK_TIME	(GET_TIME(10))	
/*! Czas zadania komunikacji z modułami zasilacza */
#define PSM_TASK_TIME	(GET_TIME(5))
/*! Czas zadania obsługi przycisków menu */
#define MENU_TASK_TIME	(GET_TIME(10))
/*! Czas zadania obsługi dźwięku */
#define SOUND_TASK_TIME	(GET_TIME(1))
/*! Czas zadania obsługi klawiatury */
#define KBD_TASK_TIME	(GET_TIME(1))
/*! Czas zadania pomiaru temperatury */
#define TEMP_TASK_TIME	(GET_TIME(1))
/*! Czas zadania zarządzania temperaturą */
#define TEMP_CTRL_TASK_TIME	(GET_TIME(100))
/*! Czas zadania komunikacji z PC */
#define PC_COMM_TASK_TIME	(GET_TIME(10))

// --->Funkcje

void MainSystemTask(void);			// Główne zadanie systemowe
// Zadanie wymiany danych z modułami zasilacza
void PSMCtrlTask(void);
void PSMLcdTask(void);				// Zadanie obsługi wyświetlania
void KeyboardTask(void);			// Zadanie obsługi klawiatury
void TemperatureTask(void);			// Zadanie obsługi pomiaru temperatury	
void SoundTask(void);				// Zadanie obsługi generowania dźwięku	
void MenuKeysTask(void);			// Zadanie obsługi przycisków menu
void ThermalControlTask(void);		// Zadanie zarządzania temperaturą
void PCCommunicationTask();			// Zadanie komunikacji z PC

#endif								/* TASKS_H */

/******************* (C) COPYRIGHT 2010 HENIUS ************** KONIEC PLIKU ****/

