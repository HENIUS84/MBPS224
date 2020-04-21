/**
 *******************************************************************************
 * @file     Menu.h
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.2
 * @date     03-05-2013
 * @brief    Obsługa menu (plik nagłówkowy)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

#ifndef MENU_H_
#define MENU_H_

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// --->Pliki użytkownika

#include "Hardware.h"

/* Sekcja stałych, makr i definicji ------------------------------------------*/

// --->Stałe

/*! Timeout po jakim zostanie wyłączony LCD */
#define LCD_OFF_TIMEOUT		(6000)
#define CURSOR_TIME			(50)	/*!< Czas migotania kursora edycji
                                         (uzależniony od czasu odpytywania
                                         funkcji obsługi przycisków menu) */
#define LOW_VOLTAGE			600		/*!< Dolna granica napięcia */
#define HIGH_VOLTAGE		24000	/*!< Górna granica napięcia */
#define LOW_VOLTAGE_PWM		0		/*!< Dolna granica PWM napięcia */
#define HIGH_VOLTAGE_PWM	1023	/*!< Górna granica PWM napięcia */
#define LOW_CURRENT			(1)		/*!< Dolna granica natężenia prądu */
#define HIGH_CURRENT		(1000)	/*!< Górna granica natężenia prądu */
#define DISP_BACKL_MIN		(10)	/*!< Minimalna wartość podświetlenia */
#define DISP_BACKL_MAX      (100)	/*!< Maksymalna wartość podświetlenia */
#define DISP_BACKL_STEPS	(11)    /*!< Liczba kroków ustawień podświetlenia */
/* Wielkość kroku w ustawianiu podświetlenia (maks. 10 poziomów) */
#define DISP_BACKL_STEP		((DISP_BACKL_MAX - DISP_BACKL_MIN) / \
                             (DISP_BACKL_STEPS - 1))
/*! Minimalny czas łagodnego startu (w sekundach) */ 							 
#define SOFT_START_TIME_MIN	(0)
/*! Maksymalny czas łagodnego startu (w sekundach) */
#define SOFT_START_TIME_MAX	(60)	
/*! Maksymalna wartość parametru maksymalnej temperatury */
#define MAX_TEMP_MAX		(800)
/*! Minimalna wartość parametru maksymalnej temperatury */
#define MAX_TEMP_MIN		(200)
/*! Maksymalna wartość parametru histerezy temperatury */
#define TEMP_HISTERESIS_MAX	(100)
/*! Minimalna wartość parametru histerezy temperatury */
#define TEMP_HISTERESIS_MIN	(10)

// --->Makra

// Dźwięki przycisków
/*! Domyślny dźwięk przycisku */
#define KEY_BEEP()			Beep(500, 100)
/*! Dźwięk niedozwolonej operacji */
#define WRONG_BEEP()		Beep(250, 100)
/*! Dźwięk wejścia w tryb edycji */
#define EDITION_BEEP()		Beep(650, 300)
/*! Dźwięk przeciążenia */
#define OVERLOAD_BEEP()		Beep(1000, -1)

/*! Pobieranie liczby ekranów */
#define AMOUNT_OF_SCREENS(x)	(sizeof(x) / sizeof(Screen_t))

// --->Typy

/**
 * @brief Indeksy napisów
 */
typedef enum
{
    CI_CHANNEL1_LABEL,				/*!< Etykieta kanału #1 */
    CI_CHANNEL2_LABEL,				/*!< Etykieta kanału #2 */
    CI_SET_VALUES,					/*!< Etykieta wartości zadanych */
    CI_LEFT_NAVIGATOR,				/*!< Lewy nawigator */
    CI_RIGHT_NAVIGATOR,				/*!< Prawy nawigator */
    CI_RIGHTS,						/*!< Informacja o prawach autorskich */
    CI_FW_VERSION,					/*!< Informacja o wersji oprogramowania */
    CI_FLOAT_VALUE_1,				/*!< Wartość zmienno-przecinkowa 1 */
    CI_VOLTAGE_UNIT,				/*!< Jednostka napięcia */
    CI_LOW_RESISTANCE_UNIT,			/*!< Jednostka niskiej rezystancji */
    CI_LOW_POWER_UNIT,				/*!< Jednostka niskiej mocy */
    CI_TEMPERATURE_UNIT,			/*!< Jednostka temperatury */
    CI_CURRENT_UNIT,				/*!< Jednostka natężenia prądu */
    CI_INT_VALUE,					/*!< Wartość całkowita */
    CI_TEMPERATURES,				/*!< Etykieta temperatur */
    CI_MEASURED_VALUES,				/*!< Etykieta wartości zmierzonych */
    CI_POWER_RESISTANCE,			/*!< Etykieta mocy/rezystancji */
    CI_HIGH_POWER_UNIT,				/*!< Jednostka dużej mocy */
    CI_MED_RESISTANCE_UNIT,			/*!< Jednostka średniej rezystancji */
    CI_HI_RESISTANCE_UNIT,			/*!< Jednostka dużej rezystancji */
    CI_MB_TEMP_LABEL,				/*!< Etykieta temperatury płyty głównej */
    CI_INFINITY_SYMBOL,				/*!< Symbol nieskończoności */
    CI_SETTINGS,                    /*!< Etykieta ustawień */
    CI_SOUND,						/*!< Etykieta ustawień dźwięku */
    CI_DISPLAY, 					/*!< Etykieta ustawień wyświetlacza */
    CI_LANGUAGE,					/*!< Etykieta ustawień języka */
    CI_MENU_LANGUAGE,				/*!< Etykieta ustawień języka */
    CI_SET_PWM,						/*!< Etykieta ustawień wartości PWM */
    CI_ADC_VALUES,					/*!< Etykieta wartości zmierzonych ADC */
    CI_VOLTAGE_PWM_UNIT,			/*!< JEdnostka PWM napięcia */
    CI_CURRENT_PWM_UNIT,			/*!< Jednostka PWM natężenia prądu */	
	CI_SOUND_OFF,					/*!< Informacja o wyłączonym dźwięku */
    CI_SOUND_ON,					/*!< Informacja o włączonym dźwięku */
    CI_FLOAT_VALUE_2,				/*!< Wartość zmienno-przecinkowa 2 */
    CI_FLOAT_VALUE_3,				/*!< Wartość zmienno-przecinkowa 3 */
    CI_OVERCURRENT,					/*!< Znak przekroczenia natężenia prądu */
    CI_GENERAL_SETTINGS,			/*!< Etykieta ustawień ogólnych */
    CI_PS_SETTINGS,					/*!< Etykieta ustawień zasilacza */
	/*! Etykieta ustawień ogólnych w górnej belce */
    CI_GENERAL_SETTINGS_LABEL,		
	/*! Etykieta ustawień łagodnego startu kanału #1 */
    CI_SOFT_START_1,	
	/*! Etykieta ustawień łagodnego startu kanału #2 */			
    CI_SOFT_START_2,			
	/*! Etykieta ustawień zasilacza w górnej belce */	
    CI_PS_SETTINGS_LABEL,	
	/*! Jednostka czasu łagodnego startu */		
    CI_SOFT_START_UNIT,			
    CI_ABOUT,						/*!< Informacje o programie */
    CI_COMMUNICATION,				/*!< Komunikacja */
    CI_DATA_RATE,					/*!< Prędkość transmisji */
    CI_MESSAGE_SIZE,				/*!< Rozmiar komunikatu */
    CI_RX_DATA,						/*!< Informacja o danych odbieranych */
    CI_TX_DATA,						/*!< Informacja o danych wysyłanych */
    CI_FIRMWARE, 	                /*!< Informacja o oprogramowaniu */
	/*! Informacja o oprogramowaniu modułu #1 */
	CI_FIRMWARE1, 	                 
	/*! Informacja o oprogramowaniu modułu #2 */
	CI_FIRMWARE2, 	       
	/*! Informacja o wersji  oprogramowania płyty głównej */        
    CI_MB_VERSION,		
	/*! Informacja o wersji  oprogramowania modułu */
	CI_PSM_VERSION,			
	/*! Data zbudowania oprogramowania (pełna wersja) */	
    CI_FULL_BUILD_DATE,	
	/*! Data zbudowania oprogramowania (skrócona wersja) */
	CI_SHORT_BUILD_DATE,			
	CI_MAX_TEMP,					/*!< Etykieta ustawień maksymalnej temp. */
	CI_TEMP_HYSTERESIS,				/*!< Etykieta ustawień histerezy temp. */
	CI_TEMP_PROTECTION,				/*!< Etykieta ustawień zabezp. temp. */
	/*! Informacja o włączonym zabezpieczeniu termicznym */
	CI_TEMP_PROTECTION_ON,			
	/*! Informacja o wyłączonym zabezpieczeniu termicznym */
	CI_TEMP_PROTECTION_OFF,			
}ECaptionIndex_t;

/**
 * @brief Ekrany menu
 */
typedef enum
{
    MS_START,						/*!< Stan początkowy */
    MS_SET_VALUES,					/*!< Widok zadanego napięcia i  prądu */
    MS_SCREEN_SET_VALUES,			/*!< Widok nazwy ekranu wartości zadanych */
    MS_TEMPERATURES,				/*!< Widok temperatur */
    MS_SCREEN_TEMPERATURES,			/*!< Widok nazwy ekranu temperatur */    
    MS_SCREEN_MEASURED_VALUES,		/*!< Widok nazwy ekranu zmierzonych war. */
    MS_SCREEN_POWER_RESISTANCE,		/*!< Widok nazwy ekranu mocy/rezystancji */
    MS_MEASURED_VALUES,				/*!< Widok zmierzonego napięcia i  prądu */
    MS_POWER_RESISTANCE,			/*!< Widok mocy rezystancji */
    MS_SCREEN_SETTINGS,				/*!< Widok nazwy ekranu ustawień */
    MS_SETTINGS,					/*!< Widok ustawień programu */
    MS_SCREEN_SOUND,				/*!< Widok nazwy ekranu ustawień dżwięku */
    MS_SOUND_SETTINGS,				/*!< Widok ustawień dźwięku */
    MS_SCREEN_DISPLAY,				/*!< Widok nazwy ekranu ustawień ekranu */
    MS_DISPLAY_SETTINGS,			/*!< Widok ustawień wyświetlacza */
    MS_SCREEN_LANGUAGE,				/*!< Widok nazwy ekranu zmiany języka */
    MS_LANGUAGE_SETTINGS,			/*!< Widok ustawień języka */
	/*! Widok nazwy ekranu wartości zadanych PWM */
    MS_SCREEN_SET_PWM,				
    MS_SET_PWM,						/*!< Widok wartości zadanych PWM napięcia */
    MS_SCREEN_ADC_VALUES,			/*!< Widok nazwy ekranu wartości ADC */
    MS_ADC_VALUES,					/*!< Widok wartości zmierzonych ADC */
    MS_SCREEN_GENERAL_SETTINGS,		/*!< Widok nazwy ekranu ustawień ogólnych */
    MS_GENERAL_SETTINGS,			/*!< Widok ustawień ogólnych */
    MS_SCREEN_PS_SETTINGS,			/*!< Widok nazwy ekranu ustawień modułu */
    MS_PS_SETTINGS,					/*!< Widok ustawień zasilacza */
	/*! Widok nazwy ekranu ustawień łagodnego startu kanału #1 */
    MS_SCREEN_SS1_SETTINGS,		
	/*! Widok ustawień łagodnego startu kanału #1 */	
    MS_SS1_SETTINGS,		
	/*! Widok nazwy ekranu ustawień łagodnego startu kanału #2 */		
    MS_SCREEN_SS2,	
	/*! Widok ustawień łagodnego startu kanału #2 */				
    MS_SS2_SETTINGS,	
	/*! Widok nazwy ekranu informacji o programie */			
    MS_SCREEN_ABOUT,				
    MS_ABOUT,						/*!< Widok informacji o programie */
	/*! Widok nazwy ekranu informacji o komunikacji */
    MS_SCREEN_COMMUNICATION,	
	/*! Widok ekranu informacji o komunikacji */	
    MS_COMMUNICATION,	
	/*! Widok nazwy ekranu informacji o oprogramowaniu */			
    MS_SCREEN_FIRMWARE,		
	/*! Widok ekranu informacji o oprogramowaniu */		
    MS_FIRMWARE,    
	/*! Widok nazwy ekranu ustawień maksymalnej temperatury */	                
	MS_SCREEN_MAX_TEMP,						
	MS_MAX_TEMP_SETTINGS,			/*!< Widok ustawień maks. temperatury */
	/*! Widok nazwy ekranu ustawień histerezy temperatury */	
	MS_SCREEN_TEMP_HYSTERESIS,				
	MS_TEMP_HYSTERESIS_SETTINGS,	/*!< Widok ustawień histerezy temperatury */
	/*! Widok nazwy ekranu ustawień zabezpieczenia temperaturowego */
	MS_SCREEN_TEMP_PROTECTION,		
	/*! Widok ustawień zabezpieczenia temperaturowego */
	MS_TEMP_PROTECTION_SETTINGS,
	/*! Widok nazwy ekranu informacji o oprogramowaniu modułu #1 */
	MS_SCREEN_FIRMWARE1,
	/*! Widok ekranu informacji o oprogramowaniu modułu #1 */
	MS_FIRMWARE1,	
	/*! Widok nazwy ekranu informacji o oprogramowaniu modułu #2 */
	MS_SCREEN_FIRMWARE2,
	/*! Widok ekranu informacji o oprogramowaniu modułu #2 */
	MS_FIRMWARE2
}EMenuScreen_t;

/**
 * @brief Obiekt kojarzący ekran i jego opis
 */
typedef struct
{
    EMenuScreen_t Type;				/*!< Typ ekranu */
    ECaptionIndex_t Name;			/*!< Indeks nazwy ekranu */
	/*! Flaga oznaczająca ekran dostępny w trybie zaawansowanym */
    bool AdvancedMode;				
} Screen_t;

/**
 * @brief Stany przycisków menu
 */
typedef enum
{
    MKS_SCREEN_NAME,				/*!< Zmiana nazwy ekranu */
    MKS_VALUE_EDITION,				/*!< Edycja wartości */
	/*! Naciśnięcie przycisku - wyjście z trybu przekroczenia natężenia prądu */
    MKS_OVERCURRENT					
} MenuKeyState_t;

/**
 * @brief Języki menu
 */
typedef enum
{
    L_ENGLISH,						/*!< Język angielski */
    L_POLISH,						/*!< Język polski */
    NUMBER_OF_LANGUAGES				/*!< Liczba języków menu */
} Language_t;

/* Sekcja deklaracji ---------------------------------------------------------*/

// --->Zmienne

bool IsAdvancedMode;				// Flaga oznaczająca tryb zaawansowany

// --->Funkcje

//Funkcja pokazywania ekranu początkowego
void ShowSplashScreen(void);
// Funkcja wyboru ekranu menu
void MenuHandler(void);
// Obsługa przycisków menu
void MenuKeysHandler(void);

#endif								/* MENU_H_ */

/******************* (C) COPYRIGHT 2013 HENIUS *************** KONIEC PLIKU ***/
