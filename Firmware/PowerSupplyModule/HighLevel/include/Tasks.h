/**
 *******************************************************************************
 * @file     Tasks.h
 * @author   HENIUS (Paweł Witak)                                      
 * @version  1.1.1                                                         
 * @date     04-04-2011                                                       
 * @brief    Zestaw zadań obsugiwanych przez moduł zasilacza (plik nagłówkowy)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2011 HENIUS</center></h2>
 */

#ifndef PSM_TASKS_H_
#define PSM_TASKS_H_

/* Sekcja include ------------------------------------------------------------*/

/* Sekcja stałych, makr i definicji ------------------------------------------*/

//--->Stałe

// Czasy powtarzania zadań (w ms)
#define MB_TASK_TIME	(1 / SYS_TIME)
/*! Czas zadania pomiaru temperatury */
#define TEMP_TASK_TIME	(1 / SYS_TIME)
/*! Czas zadania pomiarów parametrów zasilacza */
#define MULTIMETER_TASK_TIME	(5 / SYS_TIME)
/*! Czas zadania regulatora */
#define REGULATOR_TASK_TIME		(1 / SYS_TIME)

/* Sekcja deklaracji ---------------------------------------------------------*/

// Główne zadanie systemowe 1 ms
void MainSystemTask(void);
// Zadanie wymiany danych z płytą główną
void CtrlTask(void);
// Zadanie obsługi pomiarów
void MultimeterTask(void);
// Zadanie obsługi pomiaru temperatury stabilizatora
void TemperatureTask(void);
// Zadanie obsługi regulatora napięcia i natężenia prądu
void RegulatorTask(void);
// Inicjalizacja zadań
void InitTasks(void);

#endif 										/* PSM_TASKS_H_ */

/******************* (C) COPYRIGHT 2011 HENIUS *************** KONIEC PLIKU ***/
